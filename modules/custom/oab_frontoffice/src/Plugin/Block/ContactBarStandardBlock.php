<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_standard_block",
 *   admin_label = @Translation("Contact Bar Standard"),
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

class ContactBarStandardBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();

        $link_assistance = isset($config['link_assistance']) ? $config['link_assistance'] : '';
        $link_assistance_text = isset($config['link_assistance_text']) ? $config['link_assistance_text'] : '';
        $link_contact = isset($config['link_contact']) ? $config['link_contact'] : '';
        $link_contact_text = isset($config['link_contact_text']) ? $config['link_contact_text'] : '';
        $link_ecrire = isset($config['link_ecrire']) ? $config['link_ecrire'] : '';
        $link_ecrire_text = isset($config['link_ecrire_text']) ? $config['link_ecrire_text'] : '';

        $build = array();
        $build['link_assistance'] = $link_assistance;
        $build['link_assistance_text'] = $link_assistance_text;
        $build['link_contact'] = $link_contact;
        $build['link_contact_text'] = $link_contact_text;
        $build['link_ecrire'] = $link_ecrire;
        $build['link_ecrire_text'] = $link_ecrire_text;

        return $build;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

       /* $form['content'] = array(
            '#type' => 'text_format',
            '#title' => t('Contact Bar content'),
            '#default_value' => isset($this->configuration['content']) ? $this->configuration['content'] : '',
            '#format' => isset($this->configuration['content_format']) ? $this->configuration['content_format'] : 'full_html',
        );*/

        $form['link_assistance'] = [
            '#title' => $this->t('Lien vers l\'espace assistance'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_assistance']) ? $this->configuration['link_assistance'] : '',
            '#required' => false,
        ];
        $form['link_assistance_text'] = [
            '#title' => $this->t('Texte du lien vers l\'espace assistance'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_assistance_text']) ? $this->configuration['link_assistance_text'] : 'Assistance',
            '#required' => false,
        ];

        $form['link_contact'] = [
            '#title' => $this->t('Lien vers Nous contacter'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact']) ? $this->configuration['link_contact'] : '',
            '#required' => false,
        ];
        $form['link_contact_text'] = [
            '#title' => $this->t('Texte du lien vers Nous contacter'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact_text']) ? $this->configuration['link_contact_text'] : 'Nous contacter',
            '#required' => false,
        ];

        $form['link_ecrire'] = [
            '#title' => $this->t('Lien vers Nous écrire'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_ecrire']) ? $this->configuration['link_ecrire'] : 'http://www.orange-business.com/fr/contact-commercial',
            '#required' => false,
        ];
        $form['link_ecrire_text'] = [
            '#title' => $this->t('Texte du lien vers Nous écrire'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_ecrire_text']) ? $this->configuration['link_ecrire_text'] : 'Nous écrire',
            '#required' => false,
        ];

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
       // $content = $form_state->getValue('content');
        //$this->configuration['content'] = $content['value'];
       // $this->configuration['content_format'] = $content['format'];

        $this->setConfigurationValue('link_assistance', $form_state->getValue('link_assistance'));
        $this->setConfigurationValue('link_assistance_text', $form_state->getValue('link_assistance_text'));
        $this->setConfigurationValue('link_contact', $form_state->getValue('link_contact'));
        $this->setConfigurationValue('link_contact_text', $form_state->getValue('link_contact_text'));
        $this->setConfigurationValue('link_ecrire', $form_state->getValue('link_ecrire'));
        $this->setConfigurationValue('link_ecrire_text', $form_state->getValue('link_ecrire_text'));
    }
}
