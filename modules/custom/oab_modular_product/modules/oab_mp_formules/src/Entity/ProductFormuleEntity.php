<?php

namespace Drupal\oab_mp_formules\Entity;

use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\EditorialContentEntityBase;
use Drupal\Core\Entity\RevisionableInterface;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityPublishedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\oab_mp_formule_field\Entity\FormuleField;

/**
 * Defines the Product formule entity entity.
 *
 * @ingroup oab_mp_formules
 *
 * @ContentEntityType(
 *   id = "product_formule_entity",
 *   label = @Translation("Product formule"),
 *   handlers = {
 *     "storage" = "Drupal\oab_mp_formules\ProductFormuleEntityStorage",
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_mp_formules\ProductFormuleEntityListBuilder",
 *     "views_data" = "Drupal\oab_mp_formules\Entity\ProductFormuleEntityViewsData",
 *     "form" = {
 *       "default" = "Drupal\oab_mp_formules\Form\ProductFormuleEntityForm",
 *       "add" = "Drupal\oab_mp_formules\Form\ProductFormuleEntityForm",
 *       "edit" = "Drupal\oab_mp_formules\Form\ProductFormuleEntityForm",
 *       "delete" = "Drupal\oab_mp_formules\Form\ProductFormuleEntityDeleteForm",
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_mp_formules\ProductFormuleEntityHtmlRouteProvider",
 *     },
 *     "access" = "Drupal\oab_mp_formules\ProductFormuleEntityAccessControlHandler",
 *   },
 *   base_table = "product_formule_entity",
 *   revision_table = "product_formule_entity_revision",
 *   revision_data_table = "product_formule_entity_field_revision",
 *   translatable = FALSE,
 *   admin_permission = "administer product formule entity entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "revision" = "vid",
 *     "label" = "name",
 *     "uuid" = "uuid",
 *     "langcode" = "langcode",
 *     "published" = "status",
 *     "formule_fields" = "formule_fields"
 *   },
 *   revision_metadata_keys = {
 *     "revision_user" = "revision_user",
 *     "revision_created" = "revision_created",
 *     "revision_log_message" = "revision_log",
 *   },
 *   links = {
 *     "canonical" = "/admin/product/formules/{product_formule_entity}",
 *     "add-form" = "/admin/product/formules/add",
 *     "edit-form" = "/admin/product/formules/{product_formule_entity}/edit",
 *     "delete-form" = "/admin/product/formules/{product_formule_entity}/delete",
 *     "version-history" = "/admin/product/formules/{product_formule_entity}/revisions",
 *     "revision" = "/admin/product/formules/{product_formule_entity}/revisions/{product_formule_entity_revision}/view",
 *     "revision_revert" = "/admin/product/formules/{product_formule_entity}/revisions/{product_formule_entity_revision}/revert",
 *     "revision_delete" = "/admin/product/formules/{product_formule_entity}/revisions/{product_formule_entity_revision}/delete",
 *     "collection" = "/admin/product/formules",
 *   },
 *   field_ui_base_route = "product_formule_entity.settings"
 * )
 */
class ProductFormuleEntity extends EditorialContentEntityBase implements ProductFormuleEntityInterface {

  use EntityChangedTrait;
  use EntityPublishedTrait;


  /**
   * {@inheritdoc}
   */
  protected function urlRouteParameters($rel) {
    $uri_route_parameters = parent::urlRouteParameters($rel);

    if ($rel === 'revision_revert' && $this instanceof RevisionableInterface) {
      $uri_route_parameters[$this->getEntityTypeId() . '_revision'] = $this->getRevisionId();
    }
    elseif ($rel === 'revision_delete' && $this instanceof RevisionableInterface) {
      $uri_route_parameters[$this->getEntityTypeId() . '_revision'] = $this->getRevisionId();
    }

    return $uri_route_parameters;
  }

  /**
   * {@inheritdoc}
   */
  public function preSave(EntityStorageInterface $storage) {
    parent::preSave($storage);

    // If no revision author has been set explicitly,
    // make the product_formule_entity owner the revision author.
    if (!$this->getRevisionUser()) {
      $this->setRevisionUserId(\Drupal::currentUser()->id());
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getName(): string {
    return $this->get('name')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setName($name): ProductFormuleEntityInterface|static {
    $this->set('name', $name);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCreatedTime(): int {
    return $this->get('created')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setCreatedTime($timestamp): ProductFormuleEntityInterface|static {
    $this->set('created', $timestamp);
    return $this;
  }

  /**
   * @return FormuleField[]
   */
  public function getFormuleFields(): array {

    $field_ids = [];
    foreach ($this->get('formule_fields') as $field_item) {
      $field_ids[] = $field_item->target_id;
    }
    return FormuleField::loadMultiple($field_ids);
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields = parent::baseFieldDefinitions($entity_type);

    // Add the published field.
    $fields += static::publishedBaseFieldDefinitions($entity_type);

    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Name'))
      ->setDescription(t('The name of the Product formule entity entity.'))
      ->setRevisionable(TRUE)
      ->setSettings([
        'max_length' => 50,
        'text_processing' => 0,
      ])
      ->setDefaultValue('')
      ->setDisplayOptions('view', [
        'label' => 'above',
        'type' => 'string',
        'weight' => -4,
      ])
      ->setDisplayOptions('form', [
        'type' => 'string_textfield',
        'weight' => -4,
      ])
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE)
      ->setRequired(TRUE);

    $fields['status']->setDescription(t('A boolean indicating whether the Product formule entity is published.'))
      ->setDisplayOptions('form', [
        'type' => 'boolean_checkbox',
        'weight' => -3,
      ]);

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the entity was last edited.'));


    $fields['formule_fields'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Formule fields'))
      ->setDescription(t('Define Formule field'))
      ->setRevisionable(true)
      ->setRequired(true)
      ->setDisplayConfigurable("view", true)
      ->setDisplayOptions('view', [
        'label' => 'hidden',
        'type' => 'entity_reference_entity_view',
        'settings' => [
          'view_mode' => 'default'
        ],
        'weight' => -4,
      ])
      ->setDisplayConfigurable("form", true)
      ->setCardinality(FieldStorageDefinitionInterface::CARDINALITY_UNLIMITED)
      ->setSetting('target_type', 'formule_field')
      ->setDisplayOptions('form', [
        'type' => 'entity_reference_autocomplete',
        'target_type' => 'formule_field',
        'settings' => [
          'match_operator' => 'CONTAINS',
          'autocomplete_type' => 'tags',
          'placeholder' => '',
        ],
      ]);


    return $fields;
  }

}
