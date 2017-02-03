<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "right_icon_block",
 *   admin_label = @Translation("Right icon Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class RightIconBlock extends BlockBase {

    public function build(){
        $config = $this->getConfiguration();
        $right_icon_custom_text = isset($config['right_icon_custom_text']) ? $config['right_icon_custom_text'] : '';
        return array(
            'type' => 'markup',
            '#markup' => check_markup($right_icon_custom_text['value'], $right_icon_custom_text['format']),
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
        $form['right_icon_custom_text'] = array(
            '#type' => 'text_format',
            '#title' => t('Custom text'),
            '#default_value' => isset($config['right_icon_custom_text']['value']) ? $config['right_icon_custom_text']['value'] : '',
            '#format' => isset($config['right_icon_custom_text']['format']) ? $config['right_icon_custom_text']['format'] : 'full_html',
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
        $this->setConfigurationValue('right_icon_custom_text', $form_state->getValue('right_icon_custom_text'));
    }
}