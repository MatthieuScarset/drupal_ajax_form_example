<?php

namespace Drupal\oab_hub;

use Drupal\oab_hub\Controller\OabHubController;
use Drupal\path_alias\AliasRepository;
use Drupal\path_alias\AliasRepositoryInterface;

class AliasRepositoryDecorator extends AliasRepository implements AliasRepositoryInterface {


  /**
   * Returns a SELECT query for the path_alias base table.
   *
   * Alter parent getBaseQuery to add conditions about the hub.
   * Add a weight to every alias depending on whether it matches the current hub or not
   * to always get an alias if it exists.
   *
   * Add a custom expression and order the query with this expression.
   *
   * The expression should like like this :
   * @code
   *   CASE
   *      WHEN
   *        base_table.alias NOT LIKE "/consulting%"
   *        AND base_table.alias NOT LIKE "/digitalworkspace%"
   *        AND base_table.alias NOT LIKE "/mss-assistance%"
   *        THEN 0
   *      WHEN base_table.alias LIKE "/consulting%" THEN 2
   *      WHEN base_table.alias LIKE "/digitalworkspace%" THEN 3
   *      WHEN base_table.alias LIKE "/mss-assistance%" THEN 4
   *    END AS custom_hub_order_field
   * @endcode
   *
   * When I wrote it, only God and I knew what I did... Now only God knows
   *
   * @return \Drupal\Core\Database\Query\SelectInterface
   *   A Select query object.
   */
  protected function getBaseQuery() {
    $query = parent::getBaseQuery();

    $actif_hub = OabHubController::getHubPartOfUrl();

    $expressions = [];
    $placeholders = [];
    $all_hubs_prefixes = OabHubController::getAllHubPrefixes();

    /*
     * Only one foreach for 3 things :
     *  1. Create placeholder array
     *  3. Generate expression for hubs
     */
    foreach ($all_hubs_prefixes as $key => $hub_prefix) {
      $placeholder = str_replace(['-', '_', ' ', '/'], '', $hub_prefix);
      $placeholders[":$placeholder"] = "/$hub_prefix%";

      /*
       * if it's current hub, then 1, otherwise, bigger than 2.
       * See default expression weight which can be 0 or 1 depending on if there is an current hub or not.
       */
      $weight = $hub_prefix === $actif_hub ? 1 : $key + 3;
      $expressions[] = "WHEN base_table.alias LIKE :$placeholder THEN $weight";
    }


    // Juste rewrite the expression with every case part
    $complete_expression = "CASE ";
    foreach ($expressions as $expression) {
      $complete_expression .= " $expression";
    }
    // Default (obs.com aliases) => weight = 2,
    // so it's always the 1st alias if there is nos alias for current hub for that path (current alias is 0 or position+2)
    $complete_expression .= " ELSE 2";

    $complete_expression .= " END";

    // Add the expression
    $query->addExpression($complete_expression, 'custom_hub_order_field', $placeholders);

    // Order with this expression
    $query->orderBy('custom_hub_order_field', 'ASC');

    return $query;
  }

}
