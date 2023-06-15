<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_es_standard_block",
 *   admin_label = @Translation("Contact Bar ES Standard"),
 *   category = @Translation("Blocks"),
 *   context_definitions = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */

class ContactBarEsStandardBlock extends BlockBase {

    public function build() {
        //$block = array();
        //$block['#markup'] = $this->configuration['content'];
        //$block['#format'] = $this->configuration['content_format'];

        //return $block;

        $config = $this->getConfiguration();

        $link_offices = isset($config['link_offices']) ? $config['link_offices'] : '';
        $link_offices_text = isset($config['link_offices_text']) ? $config['link_offices_text'] : '';
        $link_help = isset($config['link_help']) ? $config['link_help'] : '';
        $link_help_text = isset($config['link_help_text']) ? $config['link_help_text'] : '';
        $link_contact = isset($config['link_contact']) ? $config['link_contact'] : '';
        $link_contact_text = isset($config['link_contact_text']) ? $config['link_contact_text'] : '';

        $build = array();
        $build['link_offices_text'] = $link_offices_text;
        $build['link_offices'] = $link_offices;
        $build['link_help'] = $link_help;
        $build['link_help_text'] = $link_help_text;
        $build['link_contact'] = $link_contact;
        $build['link_contact_text'] = $link_contact_text;

        return $build;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);
        $form['link_offices'] = [
            '#title' => $this->t('Link to Our local offices'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_offices'])
              ? $this->configuration['link_offices'] : 'http://www.orange-business.com/en/where-we-are',
            '#required' => false,
        ];
        $form['link_offices_text'] = [
            '#title' => $this->t('Link text to Our local offices'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_offices_text'])
              ? $this->configuration['link_offices_text'] : 'Our local offices',
            '#required' => false,
        ];

        $form['link_help'] = [
            '#title' => $this->t('Link to Get help'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_help']) ? $this->configuration['link_help'] : '',
            '#required' => false,
        ];
        $form['link_help_text'] = [
            '#title' => $this->t('Link text to Get Help'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_help_text']) ? $this->configuration['link_help_text'] : 'Get help',
            '#required' => false,
        ];

        $form['link_contact'] = [
            '#title' => $this->t('Link to Contact sales'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact']) ? $this->configuration['link_contact'] : '',
            '#required' => false,
        ];
        $form['link_contact_text'] = [
            '#title' => $this->t('Link text to Contact sales'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact_text'])
              ? $this->configuration['link_contact_text'] : 'Contact sales',
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
