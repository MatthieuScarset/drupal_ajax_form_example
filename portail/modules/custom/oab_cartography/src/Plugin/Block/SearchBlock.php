<?php

namespace Drupal\oab_cartography\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Block\BlockPluginInterface;


/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "search_block",
 *   admin_label = @Translation("Search Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class SearchBlock extends BlockBase implements BlockPluginInterface{

    public function build(){
        $config = $this->getConfiguration();
        $search_custom_text = isset($config['search_custom_text']) ? $config['search_custom_text'] : '';
        return array(
            'type' => 'markup',
            '#markup' => check_markup($search_custom_text['value'], $search_custom_text['format']),
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
        $form['search_custom_text'] = array(
            '#type' => 'text_format',
            '#title' => t('Custom text'),
            '#default_value' => isset($config['search_custom_text']['value']) ? $config['search_custom_text']['value'] : '',
            '#format' => isset($config['search_custom_text']['format']) ? $config['search_custom_text']['format'] : 'full_html',
        );

       /* $form['hello_block_name'] = array (
            '#type' => 'textfield',
            '#title' => $this->t('Who'),
            '#description' => $this->t('Who do you want to say hello to?'),
            '#default_value' => isset($config['name']) ? $config['name'] : '',
        );*/

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
        $this->setConfigurationValue('search_custom_text', $form_state->getValue('search_custom_text'));
    }
}