<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author LZFD0165
 * @Block(
 *   id = "blogs_block",
 *   admin_label = @Translation("Blogs"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class BlogsBlock extends BlockBase {

  const TEXT = 'blogs_text';
  const LINK = 'blogs_link';
  const LINK_TEXT = 'blogs_link_text';

  public function build() {

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();
    /*
     * J'ai enlevé les trad car s'affiche seulement sur des contenus FR pour l'instant
     */
    return array(
      'text' => isset($config[self::TEXT]) ? $config[self::TEXT] : '',
      'link'  => isset($config[self::LINK]) ? $config[self::LINK] : '',
      'link_text' => isset($config[self::LINK_TEXT]) ? $config[self::LINK_TEXT] : ''
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
    $form[self::TEXT] = array(
      '#type' => 'textfield',
      '#title' => t('Text'),
      '#default_value' => isset($config[self::TEXT]) ? $config[self::TEXT] : ''
    );

    $form[self::LINK] = array(
      '#type' => 'textfield',
      '#title' => t('Link'),
      '#default_value' => isset($config[self::LINK]) ? $config[self::LINK] : ''
    );

    $form[self::LINK_TEXT] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#default_value' => isset($config[self::LINK_TEXT]) ? $config[self::LINK_TEXT] : ''
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
    $this->setConfigurationValue(self::TEXT, $form_state->getValue(self::TEXT));
    $this->setConfigurationValue(self::LINK, $form_state->getValue(self::LINK));
    $this->setConfigurationValue(self::LINK_TEXT, $form_state->getValue(self::LINK_TEXT));
  }
}
