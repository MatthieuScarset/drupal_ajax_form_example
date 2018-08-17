<?php

namespace Drupal\oab_subhomes;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityListBuilder;
use Drupal\Core\Link;

/**
 * Defines a class to build a listing of Subhome entity entities.
 *
 * @ingroup oab_subhomes
 */
class SubhomeEntityListBuilder extends EntityListBuilder {


  /**
   * {@inheritdoc}
   */
    public function buildHeader() {
        $header['id'] = $this->t('Subhome entity ID');
        $header['name'] = $this->t('Name');
        $header['entity_type'] = $this->t('Entity type');
        $header['subhome'] = $this->t('Subhome');
        $header['created'] = $this->t('Created');
        $header['modified'] = $this->t('Modified');
        return $header + parent::buildHeader();
    }

  /**
   * {@inheritdoc}
   */
    public function buildRow(EntityInterface $entity) {
        /* @var $entity \Drupal\oab_subhomes\Entity\SubhomeEntity */
        $row['id'] = $entity->id();
        $row['name'] = Link::createFromRoute(
          $entity->label(),
          'entity.subhome_entity.edit_form',
          ['subhome_entity' => $entity->id()]
        );
        $row['entity_type'] = $entity->bundle();
        $row['subhome'] = $entity->getSubhome()->getName();

        $row['created'] = Date('d/m/Y H:i:s', $entity->getCreatedTime());
        $row['modified'] = Date('d/m/Y H:i:s', $entity->getChangedTime());

        return $row + parent::buildRow($entity);
    }

}
