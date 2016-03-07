<?php

namespace Drupal\oab_cartography\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "sticky_home_block",
 *   admin_label = @Translation("Sticky Home Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class StickyHomeBlock extends BlockBase {

  public function build(){
    $config = $this->getConfiguration();
    $sticky_home_custom_text = isset($config['sticky_home_custom_text']) ? $config['sticky_home_custom_text'] : '';
    return array(
        '#markup' => check_markup($sticky_home_custom_text['value'], $sticky_home_custom_text['format'])
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
    $form['sticky_home_custom_text'] = array(
        '#type' => 'text_format',
        '#title' => t('Custom text'),
        '#default_value' => isset($config['sticky_home_custom_text']['value']) ? $config['sticky_home_custom_text']['value'] : '',
        '#format' => isset($config['sticky_home_custom_text']['format']) ? $config['sticky_home_custom_text']['format'] : 'full_html',
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
    $this->setConfigurationValue('sticky_home_custom_text', $form_state->getValue('sticky_home_custom_text'));
  }
}