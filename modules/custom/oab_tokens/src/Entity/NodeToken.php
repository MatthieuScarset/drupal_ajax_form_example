<?php

namespace Drupal\oab_tokens\Entity;

use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;

/**
 * Defines the entity.
 *
 * @ingroup oab_tokens
 *
 * @ContentEntityType(
 *   id = "node_token",
 *   label = @Translation("Node Token"),
 *   base_table = "node_token",
 *   data_table = "node_token_field_data",
 *   entity_keys = {
 *     "id" = "id",
 *     "nid" = "nid",
 *     "vid" = "vid",
 *     "token" = "token",
 *     "created" = "created"
 *   },
 * )
 */
class NodeToken extends ContentEntityBase implements NodeTokenInterface {

  /**
   * {@inheritdoc}
   */
  public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
    parent::preCreate($storage_controller, $values);
    $values += [
      'token' => self::generateToken()
    ];
  }

  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {

    // Standard field, used as unique if primary index.
    $fields['id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('ID'))
      ->setDescription(t('The ID of the token'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    // Standard field.
    $fields['nid'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('NID'))
      ->setDescription(t('The NID of the Node'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    // Standard field.
    $fields['vid'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('VID'))
      ->setDescription(t('The VID of the revision'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    // Standard field, unique outside of the scope of the current project.
    $fields['token'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Token'))
      ->setDescription(t('The token to access node'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false)
      ->addConstraint('UniqueField', []); // Should be Unique

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);



    return $fields;
  }

  public static function generateToken(): string {
    return sha1(date('dmYhs') . bin2hex(random_bytes(30)));
  }

  public function getToken(): string {
    return $this->token->value;
  }
}
