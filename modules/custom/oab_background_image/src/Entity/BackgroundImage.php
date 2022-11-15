<?php

namespace Drupal\oab_background_image\Entity;

use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityPublishedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Url;

/**
 * Defines the Background image entity.
 *
 * @ingroup oab_background_image
 *
 * @ContentEntityType(
 *   id = "background_image",
 *   label = @Translation("Background image"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_background_image\BackgroundImageListBuilder",
 *     "access" = "Drupal\oab_background_image\BackgroundImageAccessControlHandler",
 *   },
 *   base_table = "background_image",
 *   translatable = FALSE,
 *   admin_permission = "administer background image entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "url" = "url",
 *     "mid" = "mid",
 *     "uuid" = "uuid",
 *     "langcode" = "langcode",
 *     "published" = "status",
 *   },
 *   internal= TRUE,
 * )
 */
class BackgroundImage extends ContentEntityBase implements BackgroundImageInterface {

  use EntityChangedTrait;
  use EntityPublishedTrait;

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

  public static function getUrlMachineName(string|Url $url): string {
    if ($url instanceof Url) {
      $url = $url->setAbsolute(false)->toString();
    }

    $machine_readable = strtolower($url);
    $machine_readable = preg_replace('@[^a-z0-9_]+@', '-', $machine_readable);
    return str_replace('_', '-', $machine_readable);
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {


    $fields = parent::baseFieldDefinitions($entity_type);

    // Add the published field.
    $fields += static::publishedBaseFieldDefinitions($entity_type);

    $fields['url'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Url'))
      ->setDescription(t('Transformed URL where the BG should show'))
      ->setSettings([
        'max_length' => 256,
        'text_processing' => 0,
      ])
      ->setDefaultValue('')
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false)
      ->setRequired(TRUE);

    $fields['status']->setDescription(t('A boolean indicating whether the Background image is published.'))
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


    $fields['mid'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Media ID'))
      ->setDescription(t('The media ID of the bg.'))
      ->setSettings(array(
        'target_type' => 'media',
        'handler_settings' => [
          'target_bundles' => ['background' => 'background']
        ],
        'default_value' => 0,
      ))
      ->setRequired(TRUE);

    return $fields;
  }

}
