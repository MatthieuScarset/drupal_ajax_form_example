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
   * @var \Drupal\Core\Language\LanguageManagerInterface
   */
  protected $languageManager;

  /**
   * Constructs the SVPBreadcrumbBuilder.
   *
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager service.
   * @param \Drupal\Core\Language\LanguageManagerInterface $language_manager
   *   The language manager service.
   */
  public function __construct(EntityTypeManagerInterface $entity_type_manager, LanguageManagerInterface $language_manager) {
    $this->entityTypeManager = $entity_type_manager;
    $this->languageManager = $language_manager;
  }

  /**
   * {@inheritdoc}
   */
  public function applies(RouteMatchInterface $route_match) {
    $node = $route_match->getParameter('node');
    return $node instanceof NodeInterface && $node->bundle() == 'svp';
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
}
