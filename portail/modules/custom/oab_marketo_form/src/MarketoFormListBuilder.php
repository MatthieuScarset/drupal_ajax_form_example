<?php

namespace Drupal\oab_marketo_form;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Language\LanguageInterface;
use Drupal\Core\Render\Renderer;
use Drupal\filter\FilterFormatListBuilder;
use Drupal\oab_marketo_form\Entity\MarketoForm;
use Drupal\oab_marketo_form\Entity\MarketoFormInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Provides a listing of Example.
 */
class MarketoFormListBuilder extends EntityListBuilder {


  /** @var Renderer */
  private $renderer;

  /**
   * {@inheritdoc}
   */
  public static function createInstance(ContainerInterface $container, EntityTypeInterface $entity_type) {
    return new static(
      $entity_type,
      $container->get('entity_type.manager')->getStorage($entity_type->id()),
      $container->get('renderer')
    );
  }

  /**
   * Constructs a new EntityListBuilder object.
   *
   * @param \Drupal\Core\Entity\EntityTypeInterface $entity_type
   *   The entity type definition.
   * @param \Drupal\Core\Entity\EntityStorageInterface $storage
   *   The entity storage class.
   */
  public function __construct(EntityTypeInterface $entity_type, EntityStorageInterface $storage, Renderer $renderer) {
    $this->renderer = $renderer;
    parent::__construct($entity_type, $storage);
  }



  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['form_id'] = $this->t('Form ID');
    $header['form_name'] = $this->t('Form name');
    $header['redirection_url'] = $this->t('Redirection URL');
    $header['message_of_thanks'] = $this->t('Message of thanks');
    $header['langcode'] = $this->t('Language');
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {

    /**
     * @var MarketoFormInterface $entity
     */

    $row['form_id'] = $entity->getFormId();
    $row['form_name'] = $entity->getFormName();
    $row['redirection_url'] = $this->renderer->renderRoot($entity->get('redirection_url')->view());
    $row['message_of_thanks'] = $this->renderer->renderRoot($entity->get('message_of_thanks')->view());
    $row['langcode'] = $entity->langcode(true)->getName();

    return $row + parent::buildRow($entity);
  }

}
