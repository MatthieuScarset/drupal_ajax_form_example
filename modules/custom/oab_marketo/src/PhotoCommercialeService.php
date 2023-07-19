<?php


namespace Drupal\oab_marketo;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityBase;
use Drupal\Core\Entity\EntityFieldManagerInterface;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\oab_marketo\Entity\PhotoCommercialeItem;
use Drupal\oab_marketo\Entity\PhotoCommercialeItemInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 *
 * Provide a service to manager Photo Commerciale Item
 *
 * Class PhotoCommercialeService
 * @package Drupal\oab_marketo
 */
class PhotoCommercialeService {

  const COL_RAISON_SOCIALE = 2;
  const COL_SIREN_HQ = 3;
  const COL_IDENT = 4;
  const COL_SIREN = 5;
  const COL_STATUT_INSEE = 6;
  const COL_DIVISION_COMPTE = 8;
  const COL_DIVISION_SIREN = 9;
  const COL_CANAL = 10;
  const COL_SEGMENTATION = 12;
  const COL_SEGMENT_MACRO = 13;
  const COL_AE_ENTREPRISE = 32;
  const COL_AE = 33;

  const IMPORT_DIRECTORY = 'private://photo_commerciale/';


  /**
   * @var EntityStorageInterface
   */
  private EntityStorageInterface $storage;

  /**
   * @var ImmutableConfig
   */
  private ImmutableConfig $photoCommercialeConfig;


  /**
   * @var EntityFieldManagerInterface
   */
  private EntityFieldManagerInterface $entityFieldManager;


  /**
   * @var array
   */
  private array $photoCommercialesFields = [];

  public function __construct(EntityTypeManagerInterface $entity_type_manager, EntityFieldManagerInterface $entity_field_manager,
                              ImmutableConfig $photo_commerciale_config) {
      $this->storage = $entity_type_manager->getStorage('photo_commerciale_item');
      $this->entityFieldManager = $entity_field_manager;
      $this->photoCommercialeConfig = $photo_commerciale_config;
      $this->photoCommercialesFields = $this->entityFieldManager->getFieldDefinitions('photo_commerciale_item', 'photo_commerciale_item');
  }

  /**
   * Create new Photo Commerciale Item
   *
   * @param array $photo_commerciale
   *
   * @return EntityBase|EntityInterface
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function createPhotoCommercialeItem(array $photo_commerciale): EntityInterface|EntityBase {
    $photo_commerciale_item = PhotoCommercialeItem::create($photo_commerciale);
    $photo_commerciale_item->save();

    return $photo_commerciale_item;
  }

  /**
   * @param string $ident
   * @return PhotoCommercialeItemInterface|null
   */
  public function getPhotoCommercialeItemByIdent(string $ident): ?PhotoCommercialeItemInterface {
    $photo_commerciale_item = $this->storage->loadByProperties(['ident' => $ident]);
    if (count($photo_commerciale_item) > 0) {
      return array_shift($photo_commerciale_item);
    }
    return null;
  }

  /**
   * @param string $reg_numb_type
   * @param string $reg_numb
   * @param string $raison_sociale
   *
   * @return PhotoCommercialeItem|null
   */
  public function getPhotoCommercialeItem(string $reg_numb_type,
                                          string $reg_numb,
                                          string $raison_sociale
  ): ?PhotoCommercialeItem {

    $siren = '';
    $photo_commerciale = [];

    if (!empty($reg_numb_type) && !empty($reg_numb)) {
      if (str_contains($reg_numb_type, 'SIREN')) {
        $siren = $reg_numb;
      } elseif (str_contains($reg_numb_type, "SIRET")) {
        $siren = substr($reg_numb, 0, 9);
      } elseif (str_contains($reg_numb_type, "Value Added Tax Number")) {
        $siren = substr($reg_numb, 6, 9);
      }
    }


    if (!empty($siren)) {
      $photo_commerciale = $this->getPhotoCommercialeBySiren($siren);
    } else {
      $photo_commerciale = $this->getPhotoCommercialeItemByRS($raison_sociale);
    }

    return $photo_commerciale;
  }

  /**
   * @param string $raison_sociale
   * @return PhotoCommercialeItem|null
   */
  public function getPhotoCommercialeItemByRS(string $raison_sociale): ?PhotoCommercialeItem {
    $photo_commerciale_item = $this->storage->loadByProperties(['raison_sociale' => $raison_sociale]);
    if (count($photo_commerciale_item) > 0) {
      return array_shift($photo_commerciale_item);
    }
    return null;
  }

  /**
   * @param string $siren
   * @return PhotoCommercialeItem|null
   */
  public function getPhotoCommercialeBySiren(string $siren): ?PhotoCommercialeItem {
    $photo_commerciale_item = $this->storage->loadByProperties(['siren' => $siren]);
    if (count($photo_commerciale_item) > 0) {
      return array_shift($photo_commerciale_item);
    }
    return null;
  }

  /**
   * @return PhotoCommercialeItemInterface[]
   */
  public function getAllPhotoCommercialeItem(): array {
    $ret = [];

    $photo_commerciale_item = $this->storage->loadByProperties();
    if (count($photo_commerciale_item) > 0) {
      $ret = $photo_commerciale_item;
    }

    return $ret;
  }

  public function import($row): bool {

//    $constants = (new \ReflectionClass(self::class))->getConstants();
//    $values = [];
//    foreach ($constants as $constant => $value) {
//      if (substr($constant, 0, 3) === 'COL') {
//        $field_name = strtolower(substr($constant, 4, strlen($constant)));
//        $values[$constant] = $this->getValueFromRow($row, $value, $field_name);
//      }
//    }
//    PhotoCommercialeItem::create($values)->save();

    if (strlen($row[self::COL_IDENT]) > 0) {
      PhotoCommercialeItem::create([
        'ident' => $this->getValueFromRow($row, self::COL_IDENT, 'ident'),
        'raison_sociale' => $this->getValueFromRow($row, self::COL_RAISON_SOCIALE, 'raison_sociale'),
        'siren_hq' => $this->getValueFromRow($row, self::COL_SIREN_HQ, 'siren_hq'),
        'siren' => $this->getValueFromRow($row, self::COL_SIREN, 'siren'),
        'status_insee' => $this->getValueFromRow($row, self::COL_STATUT_INSEE, 'status_insee'),
        'division_compte' => $this->getValueFromRow($row, self::COL_DIVISION_COMPTE, 'division_compte'),
        'division_siren' => $this->getValueFromRow($row, self::COL_DIVISION_SIREN, 'division_siren'),
        'canal' => $this->getValueFromRow($row, self::COL_CANAL, 'canal'),
        'segmentation' => $this->getValueFromRow($row, self::COL_SEGMENTATION, 'segmentation'),
        'segment_macro' => $this->getValueFromRow($row, self::COL_SEGMENT_MACRO, 'segment_macro'),
        'ae_entreprise' => $this->getValueFromRow($row, self::COL_AE_ENTREPRISE, 'ae_entreprise'),
        'ae' => $this->getValueFromRow($row, self::COL_AE, 'ae')
      ])->save();
      return true;
    }
    return false;
  }


  /**
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function clearPhotoCommercialeItem() {
    $photo_commerciale_item = $this->getAllPhotoCommercialeItem();

    $this->storage->delete($photo_commerciale_item);
  }


  private function getValueFromRow($row, $col, $field_name): bool|int|string {
    if (isset($row[$col])) {
      return utf8_encode($row[$col]);
    }

    $default_value = 'vide';

    if (isset($this->photoCommercialesFields[$field_name])) {
      switch ($this->photoCommercialesFields[$field_name]->getType()) {
        case 'boolean': $default_value = false; break;
        case 'integer': $default_value = 0; break;
        case 'string':
        default: $default_value = 'vide';
      }
    }

    return $default_value;
  }

}
