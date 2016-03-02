<?php

namespace Drupal\oab_cartography\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "contact_push_block",
 *   admin_label = @Translation("Contact Push Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class ContactPushBlock extends BlockBase {

  public function build(){
    $config = $this->getConfiguration();
    $contact_push_custom_text = isset($config['contact_push_custom_text']) ? $config['contact_push_custom_text'] : '';
    return array(
        '#markup' => check_markup($contact_push_custom_text['value'], $contact_push_custom_text['format'])
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
    $form['contact_push_custom_text'] = array(
        '#type' => 'text_format',
        '#title' => t('Custom text'),
        '#default_value' => isset($config['contact_push_custom_text']['value']) ? $config['contact_push_custom_text']['value'] : '',
        '#format' => isset($config['contact_push_custom_text']['format']) ? $config['contact_push_custom_text']['format'] : 'full_html',
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
    $this->setConfigurationValue('contact_push_custom_text', $form_state->getValue('contact_push_custom_text'));
  }
}