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

    public function build(){
        $config = $this->getConfiguration();
        $link_assistance = isset($config['link_assistance']) ? $config['link_assistance'] : '';
        $link_assistance_text = isset($config['link_assistance_text']) ? $config['link_assistance_text'] : '';

        return array(
            '#markup' => $this->t('Text link: @link_assistance_text', array('@linkassistance'=> $link_assistance,'@link_assistance_text'=> $link_assistance_text)),
        );
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
            '#default_value' => '',
            '#required' => false,
        ];
        $form['link_assistance_text'] = [
            '#title' => $this->t('Texte du lien vers l\'espace assistance'),
            '#type' => 'textfield',
            '#default_value' => 'Assistance',
            '#required' => false,
        ];

        $form['link_contacter'] = [
            '#title' => $this->t('Lien vers Nous contacter'),
            '#type' => 'textfield',
            '#default_value' => '',
            '#required' => false,
        ];
        $form['link_contacter_text'] = [
            '#title' => $this->t('Texte du lien vers Nous contacter'),
            '#type' => 'textfield',
            '#default_value' => 'Nous contacter',
            '#required' => false,
        ];

        $form['link_ecrire'] = [
            '#title' => $this->t('Lien vers Nous écrire'),
            '#type' => 'textfield',
            '#default_value' => 'www.orange-business.com/fr/contact-commercial',
            '#required' => false,
        ];
        $form['link_ecrire_text'] = [
            '#title' => $this->t('Texte du lien vers Nous écrire'),
            '#type' => 'textfield',
            '#default_value' => 'Nous écrire',
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
        $this->setConfigurationValue('link_contacter', $form_state->getValue('link_contacter'));
        $this->setConfigurationValue('link_contacter_text', $form_state->getValue('link_contacter_text'));
        $this->setConfigurationValue('link_ecrire', $form_state->getValue('link_ecrire'));
        $this->setConfigurationValue('link_ecrire_text', $form_state->getValue('link_ecrire_text'));
    }
}