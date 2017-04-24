<?php

/**
 * @file
 * Definition of Drupal\oab_backoffice\Plugin\views\filter\NodeYear.
 */

namespace Drupal\oab_backoffice\Plugin\views\filter;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\display\DisplayPluginBase;
use Drupal\views\Plugin\views\filter\Date;
use Drupal\views\ViewExecutable;

/**
 * Filters by node year.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("oab_backoffice_node_year")
 */
class NodeYear extends Date {

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
        // parent::valueForm($form, $form_state);
        $form['value'] = array(
            '#type' => 'select',
            '#options' => $this->generateOptions()
        );

    }

    /**
     * Override the query so that no filtering takes place if the user doesn't
     * select any options.
     */
    public function query() {
        $selected_date = mktime(0,0,0,1,1, $this->value['value']);
        if(!empty($selected_date)) {
            $this->query->addWhereExpression(0, "node_field_data.created > $selected_date");
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
            '01' => '2017',
            '02' => '2016',
            '03' => '2015',
            '04' => '2014',
            '05' => '2013',
            '06' => '2012'
        );
    }


}