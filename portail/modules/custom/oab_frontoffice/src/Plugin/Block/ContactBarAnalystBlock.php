<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_analyst_block",
 *   admin_label = @Translation("Contact Bar Analyst"),
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

class ContactBarAnalystBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();

        $link_ecrire = isset($config['link_ecrire']) ? $config['link_ecrire'] : '';
        $link_ecrire_text = isset($config['link_ecrire_text']) ? $config['link_ecrire_text'] : '';

        $build = array();

        $build['link_ecrire'] = t($link_ecrire);
        $build['link_ecrire_text'] = t($link_ecrire_text);

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


        $this->setConfigurationValue('link_ecrire', $form_state->getValue('link_ecrire'));
        $this->setConfigurationValue('link_ecrire_text', $form_state->getValue('link_ecrire_text'));
    }
}
