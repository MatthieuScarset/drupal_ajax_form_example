<?php

namespace Drupal\oab_hub;

use Drupal\oab_hub\Controller\OabHubController;
use Drupal\path_alias\AliasRepository;
use Drupal\path_alias\AliasRepositoryInterface;

class AliasRepositoryDecorator extends AliasRepository implements AliasRepositoryInterface {


  /**
   * Returns a SELECT query for the path_alias base table.
   *
   * Alteration parent getBaseQuery to add conditions about the hub
   *
   * @return \Drupal\Core\Database\Query\SelectInterface
   *   A Select query object.
   */
  protected function getBaseQuery() {
    $query = parent::getBaseQuery();

    if (($actif_hub = OabHubController::getHubPartOfUrl()) !== false) {
      $query->condition('base_table.alias', "/$actif_hub%", "LIKE");
    } else {
      $all_hubs = OabHubController::getAllHubPrefixes();

      $and_condition = $query->andConditionGroup();
      foreach ($all_hubs as $hub_prefix) {
        $and_condition->condition('base_table.alias', "/$hub_prefix%", "NOT LIKE");
      }

      $query->condition($and_condition);
    }

    return $query;
  }

}
