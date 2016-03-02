<?php

namespace Drupal\oab_cartography\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "agence_map_block",
 *   admin_label = @Translation("Agence Map Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class AgenceMapBlock extends BlockBase {

  public function build(){
    $config = $this->getConfiguration();
    $agence_map_custom_text = isset($config['agence_map_custom_text']) ? $config['agence_map_custom_text'] : '';
    return array(
        '#markup' => '<div id="map"></div>' . check_markup($agence_map_custom_text['value'], $agence_map_custom_text['format'])
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
    $form['agence_map_custom_text'] = array(
        '#type' => 'text_format',
        '#title' => t('Custom text'),
        '#default_value' => isset($config['agence_map_custom_text']['value']) ? $config['agence_map_custom_text']['value'] : '',
        '#format' => isset($config['agence_map_custom_text']['format']) ? $config['agence_map_custom_text']['format'] : 'full_html',
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
    $this->setConfigurationValue('agence_map_custom_text', $form_state->getValue('agence_map_custom_text'));
  }
}