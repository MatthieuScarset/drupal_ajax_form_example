<?php

/**
 * @file
 * Definition of Drupal\oab_backoffice\Plugin\views\filter\NodeYear.
 */

namespace Drupal\oab_backoffice\Plugin\views\filter;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\display\DisplayPluginBase;
use Drupal\views\Plugin\views\filter\NumericFilter;
use Drupal\views\ViewExecutable;

/**
 * Filters by node year.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("oab_backoffice_node_year")
 */
class NodeYear extends NumericFilter {

  /**
   * {@inheritdoc}
   */
  public function init(ViewExecutable $view, DisplayPluginBase $display, array &$options = NULL) {
    parent::init($view, $display, $options);
    $this->valueTitle = t('Node year');
    $this->definition['options callback'] = array($this, 'generateOptions');
  }

  /**
   * Add a type selector to the value form
   */
  protected function valueForm(&$form, FormStateInterface $form_state) {
    parent::valueForm($form, $form_state);
  }

  /**
   * Override the query so that no filtering takes place if the user doesn't
   * select any options.
   */
  public function query() {
    if (!empty($this->value)) {
      parent::query();
    }
  }

  /**
   * Skip validation if no options have been chosen so we can use it as a
   * non-filter.
   */
  public function validate() {
    if (!empty($this->value)) {
      parent::validate();
    }
  }

  /**
   * Helper function that generates the options.
   * @return array
   */
  public function generateOptions() {
    // Array keys are used to compare with the table field values.
    return array(
      '2017' => '2017',
      '2016' => '2016',
      '2015' => '2015',
    );
  }

}