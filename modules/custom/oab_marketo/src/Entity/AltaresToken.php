<?php

namespace Drupal\oab_marketo\Entity;

use DateInterval;
use Drupal\Core\Annotation\Translation;
use Drupal\Core\Entity\Annotation\ContentEntityType;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\webform\Plugin\WebformElement\DateTime;

/**
 * Defines the Playlist entity.
 *
 * @ingroup oab_marketo
 *
 * @ContentEntityType(
 *   id = "altares_token",
 *   label = @Translation("Altares Token"),
 *   base_table = "altares_token",
 *   data_table = "altares_token_field_data",
 *   entity_keys = {
 *     "id" = "id",
 *     "token" = "token",
 *     "created" = "created",
 *     "expires" = "expires",
 *     "valid" = "valid",
 *     "count" = "count"
 *   },
 * )
 */
class AltaresToken extends ContentEntityBase implements AltaresTokenInterface
{

  /**
   * {@inheritdoc}
   */
  public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
    $expires = new \DateTime();
    $expires->add(new \DateInterval('P1D'));

    parent::preCreate($storage_controller, $values);
    $values += [
      'token' => self::generateToken(),
      'expires' => $expires->format('U')
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

    // Standard field, unique outside of the scope of the current project.
    $fields['token'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Token'))
      ->setDescription(t('The token to access Altares data'))
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

    $fields['expires'] = BaseFieldDefinition::create('timestamp')
      ->setLabel(t('Expires'))
      ->setDescription(t('The time that the token will expire.'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['valid'] = BaseFieldDefinition::create('boolean')
      ->setLabel(t('Valid'))
      ->setDescription(t('Define if token is still valid'))
      ->setDefaultValue(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['count'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('Count'))
      ->setDescription(t('Count how many time the token has been used.'))
      ->setDefaultValue(0)
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

  /**
   * @return int
   */
  public function getExpires(): int {
    return $this->expires->value;
  }

  /**
   * @return boolean
   */
  public function isValid(): bool {
    return (date('U') < $this->expires->value) && (bool) $this->valid->value;
  }

  /**
   * @return int
   */
  public function getCount(): int {
    return $this->count->value;
  }

  /**
   * @return void
   * @throws \Drupal\Core\TypedData\Exception\ReadOnlyException
   */
  public function incrementCount(): int {
    $this->count->setValue($this->getCount() + 1);
    return $this->getCount();
  }
}
