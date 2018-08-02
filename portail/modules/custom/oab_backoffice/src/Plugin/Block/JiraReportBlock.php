<?php

namespace Drupal\oab_backoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "jira_report_block",
 *   admin_label = @Translation("JIRA report block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class JiraReportBlock extends BlockBase {

  public function build() {
    $config = $this->getConfiguration();
    $jira_report_code = isset($config['jira_report_code']) ? $config['jira_report_code'] : '';

    return array(
      '#markup' => '',
      '#attached' => array(
        'library' => array('oab_backoffice/jira'),
      )
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();

    // Add a form field to the existing block configuration form.
    $form['jira_report_code'] = array(
      '#type' => 'textarea',
      '#title' => t('Code'),
      '#rows' => 2,
      '#description' => t('Paste the entire JIRA javascript url, without the HTML script tag'),
      '#default_value' => isset($config['jira_report_code']) ? $config['jira_report_code'] : '',
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    // Save our custom settings when the form is submitted.
    $this->setConfigurationValue('jira_report_code', $form_state->getValue('jira_report_code'));
  }
}
