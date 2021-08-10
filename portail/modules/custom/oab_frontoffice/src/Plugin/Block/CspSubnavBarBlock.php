<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;

/**
 *
 * @author FLBM7270
 * @Block(
 *   id = "csp_subnav_block",
 *   admin_label = @Translation("CSP Subnav"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class CspSubnavBarBlock extends BlockBase {

  const LIST_LINK = 'csp_list_link';
  const LIST_LINK_TEXT = 'csp_list_link_text';
  const MAP_LINK = 'csp_map_link';
  const MAP_LINK_TEXT = 'csp_map_link_text';


  public function build() {

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();

    return array(
      'list_link'  => isset($config[self::LIST_LINK]) ? $config[self::LIST_LINK] : '',
      'list_link_text' => isset($config[self::LIST_LINK_TEXT]) ? $config[self::LIST_LINK_TEXT] : '',
      'map_link'  => isset($config[self::MAP_LINK]) ? $config[self::MAP_LINK] : '',
      'map_link_text' => isset($config[self::MAP_LINK_TEXT]) ? $config[self::MAP_LINK_TEXT] : ''
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
    $form[self::LIST_LINK] = array(
      '#type' => 'textfield',
      '#title' => t('List link'),
      '#default_value' => isset($config[self::LIST_LINK]) ? $config[self::LIST_LINK] : ''
    );

    $form[self::LIST_LINK_TEXT] = array(
      '#type' => 'textfield',
      '#title' => t('Text list link'),
      '#default_value' => isset($config[self::LIST_LINK_TEXT]) ? $config[self::LIST_LINK_TEXT] : ''
    );

    $form[self::MAP_LINK] = array(
      '#type' => 'textfield',
      '#title' => t('Map link'),
      '#default_value' => isset($config[self::MAP_LINK]) ? $config[self::MAP_LINK] : ''
    );

    $form[self::MAP_LINK_TEXT] = array(
      '#type' => 'textfield',
      '#title' => t('Text map link'),
      '#default_value' => isset($config[self::MAP_LINK_TEXT]) ? $config[self::MAP_LINK_TEXT] : ''
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
    $this->setConfigurationValue(self::LIST_LINK, $form_state->getValue(self::LIST_LINK));
    $this->setConfigurationValue(self::LIST_LINK_TEXT, $form_state->getValue(self::LIST_LINK_TEXT));
    $this->setConfigurationValue(self::MAP_LINK, $form_state->getValue(self::MAP_LINK));
    $this->setConfigurationValue(self::MAP_LINK_TEXT, $form_state->getValue(self::MAP_LINK_TEXT));
  }
}
