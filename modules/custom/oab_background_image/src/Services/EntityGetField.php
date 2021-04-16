<?php

namespace Drupal\oab_background_image\Services;

use Drupal\Core\Entity\ContentEntityInterface;


class EntityGetField {
    /**
     * @param ContentEntityInterface $entity
     * @param $field_name
     * @return array|mixed
     */
    public function get(ContentEntityInterface $entity, $field_name) {
        $ret = [];

        if ($entity->hasField($field_name)) {
            /** @var  $field_value \Drupal\Core\Field\FieldItemListInterface */
            $field_value = $entity->get($field_name);

            if ($field_value !== null) {
                $ret = $field_value->getValue();
            }
        }

        return $ret;
    }


    /**
     * Utilisé pour recupérer le 1er élément : si c'est le seul ou si vous voulez spécifiquement le 1er element de la liste
     *
     * @param ContentEntityInterface $entity
     * @param $field_name
     * @return array
     * @throws \Drupal\Core\TypedData\Exception\MissingDataException
     */
    public function getFirst(ContentEntityInterface $entity, $field_name) {
        $ret = [];
        if ($entity->hasField($field_name)) {
            /** @var  $field_value \Drupal\Core\Field\FieldItemListInterface */
            $field_value = $entity->get($field_name);

            if ($field_value !== null && $field_value->count() > 0) {
                $ret = $field_value->first()->getValue();
            }
        }

        return $ret;
    }
}
