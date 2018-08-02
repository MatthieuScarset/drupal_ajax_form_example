<?php

/**
 * @file
 * Definition of Drupal\oab_backoffice\Plugin\views\filter\NodeMonth.
 */

namespace Drupal\oab_backoffice\Plugin\views\filter;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\display\DisplayPluginBase;
use Drupal\views\Plugin\views\filter\Date;
use Drupal\views\ViewExecutable;

/**
 * Filters by node month.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("node_month")
 */
class NodeMonth extends Date  {

    /**
     * {@inheritdoc}
     */
    public function init(ViewExecutable $view, DisplayPluginBase $display, array &$options = NULL) {
        parent::init($view, $display, $options);
        $this->valueTitle = t('Node month');
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
      /*$selected_date = mktime(0,0,0,$this->value['value'],1);
      if (!empty($selected_date ) ) {
          $this->query->addWhereExpression(0, "node_field_data.created > $selected_date");
      }*/
        if (!empty($this->value['value']) && $this->value['value'] != 'All') {
            $month = $this->value['value'];
            $this->query->addWhereExpression(0, "MONTH(FROM_UNIXTIME(node_field_data.created)) = $month");
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
            '01' => t('January'),
            '02' => t('February'),
            '03' => t('March'),
            '04' => t('April'),
            '05' => t('May'),
            '06' => t('June'),
            '07' => t('July'),
            '08' => t('August'),
            '09' => t('September'),
            '10' => t('October'),
            '11' => t('November'),
            '12' => t('December')
        );
    }


}
