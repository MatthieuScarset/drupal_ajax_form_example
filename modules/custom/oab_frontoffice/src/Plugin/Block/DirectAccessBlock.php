<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "direct_access_block",
 *   admin_label = @Translation("Direct Access Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */



/******************* N'EST PLUS UTILISE ****************/
/** remplacé par les menus direct access bar
 * selon les langues et les blocs liés dans la config
 * A supprimer et voir les impacts **/
/*******************************************************/

class DirectAccessBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();
        $direct_access_custom_text = isset($config['direct_access_custom_text']) ? $config['direct_access_custom_text'] : '';
        return array(
            '#markup' => check_markup($direct_access_custom_text['value'], $direct_access_custom_text['format']),
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
        $form['direct_access_custom_text'] = array(
            '#type' => 'text_format',
            '#title' => t('Custom text'),
            '#default_value' => isset($config['direct_access_custom_text']['value']) ? $config['direct_access_custom_text']['value'] : '',
            '#format' => isset($config['direct_access_custom_text']['format'])
              ? $config['direct_access_custom_text']['format'] : 'full_html',
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
        $this->setConfigurationValue('direct_access_custom_text', $form_state->getValue('direct_access_custom_text'));
    }
}
