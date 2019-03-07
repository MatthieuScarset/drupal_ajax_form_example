<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_dvi_block",
 *   admin_label = @Translation("Contact Bar DVI"),
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

class ContactBarDviBlock extends BlockBase {

    public function build() {
        $config = $this->getConfiguration();

        $need_help = isset($config['need_help']) ? $config['need_help'] : 'Besoin d\'aide';

        $link_ecrire = isset($config['link_partenaire']) ? $config['link_partenaire'] : '';
        $link_ecrire_text = isset($config['link_partenaire_text']) ? $config['link_partenaire_text'] : '';

        $link_contact = isset($config['link_contact']) ? $config['link_contact'] : '';
        $link_contact_text = isset($config['link_contact_text']) ? $config['link_contact_text'] : '';

        $build = array();

        $build['need_help'] = $need_help;

        $build['link_partenaire'] = $link_ecrire;
        $build['link_partenaire_text'] = $link_ecrire_text;

        $build['link_contact'] = $link_contact;
        $build['link_contact_text'] = $link_contact_text;

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


        $form['need_help'] = [
            '#title' => $this->t('Champ besoin d\'aide'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['need_help']) ? $this->configuration['need_help'] : '',
            '#required' => false,
        ];

        $form['link_partenaire'] = [
            '#title' => $this->t('Lien vers Devenir partenaire'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_partenaire']) ? $this->configuration['link_partenaire'] : '',
            '#required' => false,
        ];
        $form['link_partenaire_text'] = [
            '#title' => $this->t('Texte du lien vers le formulaire Devenir partenaire'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_partenaire_text']) ? $this->configuration['link_partenaire_text'] : 'Devenir partenaire',
            '#required' => false,
        ];

        $form['link_contact'] = [
            '#title' => $this->t('Lien vers Contact DVI'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact']) ? $this->configuration['link_contact'] : '',
            '#required' => false,
        ];
        $form['link_contact_text'] = [
            '#title' => $this->t('Texte du lien vers Contact DVI'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['link_contact_text']) ? $this->configuration['link_contact_text'] : 'Contact DVI',
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

        $this->setConfigurationValue('need_help', $form_state->getValue('need_help'));
        $this->setConfigurationValue('link_partenaire', $form_state->getValue('link_partenaire'));
        $this->setConfigurationValue('link_partenaire_text', $form_state->getValue('link_partenaire_text'));
        $this->setConfigurationValue('link_contact', $form_state->getValue('link_contact'));
        $this->setConfigurationValue('link_contact_text', $form_state->getValue('link_contact_text'));
    }
}
