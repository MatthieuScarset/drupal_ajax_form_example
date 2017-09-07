<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_en_block",
 *   admin_label = @Translation("Contact Bar EN Standard"),
 *   category = @Translation("Blocks"),
 *   context = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */

class ContactBarEnBlock extends BlockBase {

    public function build(){
        $block = array();

        //$block['#markup'] = $this->configuration['content'];
        //$block['#format'] = $this->configuration['content_format'];

        return $block;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);
        $form['link_offices'] = [
            '#title' => $this->t('Link to Our local offices'),
            '#type' => 'textfield',
            '#default_value' => 'http://www.orange-business.com/en/where-we-are',
            '#required' => false,
        ];
        $form['link_offices_text'] = [
            '#title' => $this->t('Link text to Our local offices'),
            '#type' => 'textfield',
            '#default_value' => 'Our local offices',
            '#required' => false,
        ];

        $form['link_help'] = [
            '#title' => $this->t('Link to Get help'),
            '#type' => 'textfield',
            '#default_value' => '',
            '#required' => false,
        ];
        $form['link_help_text'] = [
            '#title' => $this->t('Link text to Get Help'),
            '#type' => 'textfield',
            '#default_value' => 'Get help',
            '#required' => false,
        ];

        $form['link_contact'] = [
            '#title' => $this->t('Link to Contact sales'),
            '#type' => 'textfield',
            '#default_value' => '',
            '#required' => false,
        ];
        $form['link_contact_text'] = [
            '#title' => $this->t('Link text to Contact sales'),
            '#type' => 'textfield',
            '#default_value' => 'Contact sales',
            '#required' => false,
        ];

        /*$form['content'] = array(
            '#type' => 'text_format',
            '#title' => t('Contact Bar content'),
            '#default_value' => isset($this->configuration['content']) ? $this->configuration['content'] : '',
            '#format' => isset($this->configuration['content_format']) ? $this->configuration['content_format'] : 'full_html',
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
        $content = $form_state->getValue('content');
        //$this->configuration['content'] = $content['value'];
        //$this->configuration['content_format'] = $content['format'];

        $this->setConfigurationValue('link_offices', $form_state->getValue('link_offices'));
        $this->setConfigurationValue('link_offices_text', $form_state->getValue('link_offices_text'));
        $this->setConfigurationValue('link_help', $form_state->getValue('link_help'));
        $this->setConfigurationValue('link_help_text', $form_state->getValue('link_help_text'));
        $this->setConfigurationValue('link_contact', $form_state->getValue('link_contact'));
        $this->setConfigurationValue('link_contact_text', $form_state->getValue('link_contact_text'));
    }
}