<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "social_share_block",
 *   admin_label = @Translation("Social Share Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class SocialShareBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();
        $social_share_custom_text = isset($config['social_share_custom_text']) ? $config['social_share_custom_text'] : '';
        return array(
            '#markup' => check_markup($social_share_custom_text['value'], $social_share_custom_text['format']),
            '#attached' => array(
                'library' =>  array(
                    'theme_boosted/socialbar',
                ),
            ),
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
        $form['social_share_custom_text'] = array(
            '#type' => 'text_format',
            '#title' => t('Custom text'),
            '#default_value' => isset($config['social_share_custom_text']['value']) ? $config['social_share_custom_text']['value'] : '',
            '#format' => isset($config['social_share_custom_text']['format']) ? $config['social_share_custom_text']['format'] : 'full_html',
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
        $this->setConfigurationValue('social_share_custom_text', $form_state->getValue('social_share_custom_text'));
    }
}
