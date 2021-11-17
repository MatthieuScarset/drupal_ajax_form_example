<?php

namespace Drupal\oab_marketo\Entity;

use Drupal\Core\Annotation\Translation;
use Drupal\Core\Entity\Annotation\ContentEntityType;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use Drupal\oab_marketo\PhotoCommercialeService;
use Drupal\webform\Plugin\WebformElement\DateTime;

/**
 * Defines the Playlist entity.
 *
 * @ingroup oab_marketo
 *
 * @ContentEntityType(
 *   id = "photo_commerciale_item",
 *   label = @Translation("Photo Commerciale Item"),
 *   base_table = "photo_commerciale_item",
 *   data_table = "photo_commerciale_item_field_data",
 *   entity_keys = {
 *     "id" = "id",
 *     "ident" = "ident",
 *     "created" = "created",
 *   },
 * )
 */
class PhotoCommercialeItem extends ContentEntityBase implements PhotoCommercialeItemInterface {

  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {

    // Standard field, used as unique if primary index.
    $fields['id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('ID'))
      ->setDescription(t('The ID of the commercial photo item'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    // Standard field, unique outside of the scope of the current project.
    $fields['ident'] = BaseFieldDefinition::create('string')
      ->setLabel(t('ident'))
      ->setDescription(t('The identifier given by orange to the company'))
      ->setSetting('max_length', 12)
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false)
      ->addConstraint('UniqueField', []); // Should be Unique

    $fields['raison_sociale'] = BaseFieldDefinition::create('string')
      ->setLabel(t('raison_sociale'))
      ->setDescription(t('the name of the company'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['siren_hq'] = BaseFieldDefinition::create('string')
      ->setLabel(t('siren_hq'))
      ->setDescription(t('The HeadQuarter SIREN'))
      ->setSetting('max_length', 11)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['siren'] = BaseFieldDefinition::create('string')
      ->setLabel(t('siren'))
      ->setDescription(t('The company Siren'))
      ->setSetting('max_length', 11)
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['status_insee'] = BaseFieldDefinition::create('boolean')
      ->setLabel(t('status_insee'))
      ->setDescription(t('The company INSEE status (actif or inactif'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['division_compte'] = BaseFieldDefinition::create('string')
      ->setLabel(t('division_compte'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['division_siren'] = BaseFieldDefinition::create('string')
      ->setLabel(t('division_siren'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['canal'] = BaseFieldDefinition::create('string')
      ->setLabel(t('canal'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['segmentation'] = BaseFieldDefinition::create('string')
      ->setLabel(t('segmentation'))
      ->setDescription(t(''))
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['segment_macro'] = BaseFieldDefinition::create('string')
      ->setLabel(t('segment_macro'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['ae_entreprise'] = BaseFieldDefinition::create('string')
      ->setLabel(t('ae_entreprise'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['ae'] = BaseFieldDefinition::create('string')
      ->setLabel(t('ae'))
      ->setDescription(t(''))
      ->setSetting('max_length', 40)
      ->setReadOnly(true)
      ->setRequired(false)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'))
      ->setReadOnly(true)
      ->setRequired(true)
      ->setDisplayConfigurable('form', false)
      ->setDisplayConfigurable('view', false);

    return $fields;
  }

  public function getFieldsAsArray(): array {
    $values = [];
    foreach ($this->getFields() as $name => $property) {
      $values[$name] = $property->value;
    }
    return $values;
  }

  /**
   * @return string
   */
  public function getRaisonSociale(): string {
    return $this->raisonSociale->value;
  }

  /**
   * @return string
   */
  public function getSirenHq(): string {
    return $this->sirenHq->value;
  }

  /**
   * @return int
   */
  public function getIdent(): string {
    return $this->ident->value;
  }

  /**
   * @return string
   */
  public function getSiren(): string {
    return $this->siren->value;
  }

  /**
   * @return string
   */
  public function getStatutInsee(): bool {
    return $this->statutInsee->value;
  }

  /**
   * @return string
   */
  public function getDivisionCompte(): string {
    return $this->divisionCompte->value;
  }

  /**
   * @return string
   */
  public function getDivisionSiren(): string {
    return $this->divisionSiren->value;
  }

  /**
   * @return string
   */
  public function getCanal(): string {
    return $this->canal->value;
  }

  /**
   * @return string
   */
  public function getSegmentation(): string {
    return $this->segmentation->value;
  }

  /**
   * @return string
   */
  public function getSegmentMacro(): string {
    return $this->segmentMacro->value;
  }

  /**
   * @return string
   */
  public function getAeEntreprise(): string {
    return $this->aeEntrprise->value;
  }

  /**
   * @return string
   */
  public function getAe(): string {
    return $this->ae->value;
  }
}
