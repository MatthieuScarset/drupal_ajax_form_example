<?php

namespace Drupal\oab_modular_product\Breadcrumb;

use Drupal\Core\Breadcrumb\Breadcrumb;
use Drupal\Core\Breadcrumb\BreadcrumbBuilderInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Language\LanguageInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Link;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\node\NodeInterface;

/**
 * Provides a breadcrumb builder for node:svp.
 */
class SvpBreadcrumbBuilder implements BreadcrumbBuilderInterface {

  use StringTranslationTrait;

  /**
   * The entity type manager.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * The language manager service.
   *
   * @var \Drupal\Core\Language\LanguageManagerInterface|null
   */
  protected $languageManager;

  /**
   * Constructs the SVPBreadcrumbBuilder.
   *
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager service.
   * @param \Drupal\Core\Language\LanguageManagerInterface|null $language_manager
   *   The language manager service.
   */
  public function __construct(EntityTypeManagerInterface $entity_type_manager, LanguageManagerInterface $language_manager = NULL) {
    $this->entityTypeManager = $entity_type_manager;
    $this->languageManager = $language_manager;
  }

  /**
   * {@inheritdoc}
   */
  public function applies(RouteMatchInterface $route_match) {
    $node = $route_match->getParameter('node');
    return $node instanceof NodeInterface && in_array($node->bundle(), ['svp', 'domain']);
  }

  /**
   * {@inheritdoc}
   */
  public function build(RouteMatchInterface $route_match) {
    $node = $route_match->getParameter('node');
    $current_language = $this->languageManager->getCurrentLanguage(LanguageInterface::TYPE_CONTENT);

    $links = [];
    $links[] = Link::createFromRoute($this->t('Home'), '<front>', [], ['language' => $current_language]);
    $links[] = Link::createFromRoute($this->t('Business needs'), '<nolink>');

    // Get title from Top Zone paragraph otherwise use node title.
    $custom_title =  $node?->field_header?->entity?->field_title?->value ?? $node->label();
    $links[] = Link::createFromRoute($custom_title, 'entity.node.canonical', ['node' => $node->id()]);

    $breadcrumb = new Breadcrumb();
    $breadcrumb->setLinks($links);
    $breadcrumb->addCacheContexts(['languages:' . LanguageInterface::TYPE_CONTENT]);
    $breadcrumb->addCacheableDependency($node);
    return $breadcrumb;
  }

  /**
   * Get the node title or the top zone title.
   *
   * @param \Drupal\node\NodeInterface $node
   *   A give node.
   *
   * @return string
   *   The custom title.
   */
  public function getCustomTitle(NodeInterface $node) {
    $custom_title = $node->label();

    if ($node->hasField('field_header') && !$node->get('field_header')->isEmpty()) {
      $paragraph = $node->get('field_header')->referencedEntities()[0];
      if ($paragraph->hasField('field_title') && !$paragraph->get('field_title')->isEmpty()) {
        $custom_title = $paragraph->get('field_title')->getString();
      }
    }

    return $custom_title;
  }
}
