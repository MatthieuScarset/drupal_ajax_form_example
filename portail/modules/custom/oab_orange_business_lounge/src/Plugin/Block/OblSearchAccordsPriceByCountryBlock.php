<?php

namespace Drupal\oab_orange_business_lounge\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\oab_orange_business_lounge\Form\SearchCountryForm;

/**
 *
 * @author LZFD0165
 * @Block(
 *   id = "search_accords_price_by_country_obl_block",
 *   admin_label = @Translation("Search Accords Price By Country OBL"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class OblSearchAccordsPriceByCountryBlock extends BlockBase {

    public function build() {

      $mon_form = \Drupal::formBuilder()->getForm(SearchCountryForm::class);

      $block = array();

      $block['#search_country_form'] = $mon_form;

      return $block;
    }

}
