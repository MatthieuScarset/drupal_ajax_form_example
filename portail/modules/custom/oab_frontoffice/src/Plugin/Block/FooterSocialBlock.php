<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "footer_social_block",
 *   admin_label = @Translation("Footer Social Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class FooterSocialBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();
        $footer_social_custom_text = isset($config['footer_social_custom_text']) ? $config['footer_social_custom_text'] : '';
        return array(
            '#markup' => check_markup($footer_social_custom_text['value'], $footer_social_custom_text['format']),
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
        $form['footer_social_custom_text'] = array(
            '#type' => 'text_format',
            '#title' => t('Custom text'),
            '#default_value' => isset($config['footer_social_custom_text']['value']) ? $config['footer_social_custom_text']['value'] : '',
            '#format' => isset($config['footer_social_custom_text']['format']) ? $config['footer_social_custom_text']['format'] : 'full_html',
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
        $this->setConfigurationValue('footer_social_custom_text', $form_state->getValue('footer_social_custom_text'));
    }
}
