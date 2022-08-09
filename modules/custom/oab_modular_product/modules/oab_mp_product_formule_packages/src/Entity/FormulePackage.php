<?php

namespace Drupal\oab_mp_product_formule_packages\Entity;

use Drupal\Core\Config\Entity\ThirdPartySettingsInterface;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\EditorialContentEntityBase;
use Drupal\Core\Entity\RevisionableInterface;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityPublishedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\FieldStorageDefinitionInterface;

/**
 * Defines the Formule package entity.
 *
 * @ingroup oab_mp_product_formule_packages
 *
 * @ContentEntityType(
 *   id = "formule_package",
 *   label = @Translation("Formule package"),
 *   bundle_label = @Translation("Formule package type"),
 *   handlers = {
 *     "storage" = "Drupal\oab_mp_product_formule_packages\FormulePackageStorage",
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_mp_product_formule_packages\FormulePackageListBuilder",
 *     "views_data" = "Drupal\oab_mp_product_formule_packages\Entity\FormulePackageViewsData",
 *     "form" = {
 *       "default" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageForm",
 *       "add" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageForm",
 *       "edit" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageForm",
 *       "delete" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageDeleteForm",
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_mp_product_formule_packages\FormulePackageHtmlRouteProvider",
 *     },
 *     "access" = "Drupal\oab_mp_product_formule_packages\FormulePackageAccessControlHandler",
 *   },
 *   base_table = "formule_package",
 *   revision_table = "formule_package_revision",
 *   revision_data_table = "formule_package_field_revision",
 *   translatable = FALSE,
 *   admin_permission = "administer formule package entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "revision" = "vid",
 *     "bundle" = "type",
 *     "label" = "name",
 *     "uuid" = "uuid",
 *     "langcode" = "langcode",
 *     "published" = "status",
 *     "formule_values" = "formule_values"
 *   },
 *   constraints = {
 *     "FormuleFieldConstraint" = {}
 *   },
 *   links = {
 *     "canonical" = "/admin/product/formule_package/{formule_package}",
 *     "add-page" = "/admin/product/formule_package/add",
 *     "add-form" = "/admin/product/formule_package/add/{formule_package_type}",
 *     "edit-form" = "/admin/product/formule_package/{formule_package}/edit",
 *     "delete-form" = "/admin/product/formule_package/{formule_package}/delete",
 *     "version-history" = "/admin/product/formule_package/{formule_package}/revisions",
 *     "revision" = "/admin/product/formule_package/{formule_package}/revisions/{formule_package_revision}/view",
 *     "revision_revert" = "/admin/product/formule_package/{formule_package}/revisions/{formule_package_revision}/revert",
 *     "revision_delete" = "/admin/product/formule_package/{formule_package}/revisions/{formule_package_revision}/delete",
 *     "collection" = "/admin/product/formule_package",
 *   },
 *    revision_metadata_keys = {
 *     "revision_user" = "revision_user",
 *     "revision_created" = "revision_created",
 *     "revision_log_message" = "revision_log",
 *   },
 *   bundle_entity_type = "formule_package_type",
 *   field_ui_base_route = "entity.formule_package_type.edit_form"
 * )
 */
class FormulePackage extends EditorialContentEntityBase implements FormulePackageInterface {

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
    // make the formule_package owner the revision author.
    if (!$this->getRevisionUser()) {
      $this->setRevisionUserId(\Drupal::currentUser()->id());
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return $this->get('name')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setName($name) {
    $this->set('name', $name);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCreatedTime() {
    return $this->get('created')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setCreatedTime($timestamp) {
    $this->set('created', $timestamp);
    return $this;
  }

  public function getFormuleValues(): array {
    $ret = [];
    $formule_values = $this->get('formule_values');
    foreach ($formule_values as $formule_value) {
      $ret[$formule_value->formule_field_target] = $formule_value->value;
    }

    return $ret;
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
      ->setDescription(t('The name of the Formule package entity.'))
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

    $fields['status']->setDescription(t('A boolean indicating whether the Formule package is published.'))
      ->setDisplayOptions('form', [
        'type' => 'boolean_checkbox',
        'weight' => 100,
      ]);

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the entity was last edited.'));


    $fields['formule_values'] = BaseFieldDefinition::create('formule_field_type')
      ->setLabel(t('Formules field values'))
      ->setDescription('Choose the formule field value for that package')
      ->setCardinality(FieldStorageDefinitionInterface::CARDINALITY_UNLIMITED)
      ->setRequired(true)
      ->setDisplayOptions('form', [
        'type' => 'formule_field_widget_type',
        'weight' => -3,
      ]);

    return $fields;
  }

}
