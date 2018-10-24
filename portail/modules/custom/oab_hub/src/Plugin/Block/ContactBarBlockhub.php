<?php

namespace Drupal\oab_hub\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @Block(
 *   id = "contact_bar_block_hub",
 *   admin_label = @Translation("Contact Bar Hub"),
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

class ContactBarBlockHub extends BlockBase {

  public function build() {

      $config = $this->getConfiguration();

      $block = array();
      $block['link_assistance'] = isset($config['link_assistance']) ? $config['link_assistance'] : '';
      $block['link_assistance_text'] = isset($config['link_assistance_text']) ? $config['link_assistance_text'] : '';
      $block['assistance_icon'] = isset($config['assistance_icon']) ? $config['assistance_icon'] : '';

      $block['tel_number'] = isset($config['tel_number']) ? $config['tel_number'] : '';
      $block['tel_number_affichage'] = isset($config['tel_number_affichage']) ? $config['tel_number_affichage'] : '';

      $block['link_ecrire'] = isset($config['link_ecrire']) ? $config['link_ecrire'] : '';
      $block['link_ecrire_text'] = isset($config['link_ecrire_text']) ? $config['link_ecrire_text'] : '';
      $block['ecrire_icon'] = isset($config['ecrire_icon']) ? $config['ecrire_icon'] : '';

    return $block;
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

      $form['assistance'] = array(
          '#type' => 'fieldset',
          '#title' => t('Assistance'),
          '#description'    => t("Laisser vide pour ne pas l'afficher"),
      );

      $form['assistance']['link_assistance'] = [
          '#title' => $this->t('Lien vers l\'espace assistance'),
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['link_assistance']) ? $this->configuration['link_assistance'] : '',
          '#required' => false,
      ];

      $form['assistance']['link_assistance_text'] = [
          '#title' => $this->t('Texte du lien vers l\'espace assistance'),
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['link_assistance_text'])
              ? $this->configuration['link_assistance_text']
              : 'Assistance',
          '#required' => false,
      ];

      $form['assistance']['assistance_icon'] = [
          '#title' => $this->t('Icone'),
          '#type' => 'textfield',
          '#description'    => "Mettre la classe de l'icone (ex: 'glyphicon glyphicon-question-sign')."
                                ." Voir sur http://boosted.orange.com/docs/3.3/components/#glyphicons",
          '#default_value' => isset($this->configuration['assistance_icon'])
              ? $this->configuration['assistance_icon']
              : '',
          '#required' => false,
      ];

      $form['tel'] = array(
          '#type' => 'fieldset',
          '#title' => t('Téléphone'),
          '#description'    => t("Laisser vide pour ne pas l'afficher"),
      );

      $form['tel']['tel_number'] = [
          '#title' => $this->t('Numéro de téléphone'),
          '#type' => 'tel',
          '#description' => "Numéro à composer (sans les espaces, avec le +33)",
          '#default_value' => isset($this->configuration['tel_number']) ? $this->configuration['tel_number'] : '',
          '#required' => false,
      ];

      $form['tel']['tel_number_affichage'] = [
          '#title' => $this->t('Numéro de téléphone affiché'),
          '#description'    => "Numéro affiché (avec les espaces)",
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['tel_number_affichage']) ? $this->configuration['tel_number_affichage'] : '',
          '#required' => false,
      ];

      $form['ecrire'] = [
          '#type' => 'fieldset',
          '#title' => t('Nous ecrire'),
          '#description'    => t("Laisser vide pour ne pas l'afficher"),
      ];

      $form['ecrire']['link_ecrire'] = [
          '#title' => $this->t('Lien vers Nous écrire'),
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['link_ecrire']) ? $this->configuration['link_ecrire'] : '',
          '#required' => false,
      ];
      $form['ecrire']['link_ecrire_text'] = [
          '#title' => $this->t('Texte du lien vers Nous écrire'),
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['link_ecrire_text']) ? $this->configuration['link_ecrire_text'] : 'Nous écrire',
          '#required' => false,
      ];
      $form['ecrire']['ecrire_icon'] = [
          '#title' => $this->t('Icone'),
          '#type' => 'textfield',
          '#description'    => "Mettre la classe de l'icone (ex: 'glyphicon glyphicon-question-sign')."
                                . " Voir sur http://boosted.orange.com/docs/3.3/components/#glyphicons",
          '#default_value' => isset($this->configuration['ecrire_icon']) ? $this->configuration['ecrire_icon'] : '',
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
      $this->setConfigurationValue('link_assistance',
          $form_state->getValue(array('assistance', 'link_assistance')));
      $this->setConfigurationValue('link_assistance_text',
          $form_state->getValue(array('assistance','link_assistance_text')));
      $this->setConfigurationValue('assistance_icon',
          $form_state->getValue(array('assistance','assistance_icon')));

      $this->setConfigurationValue('tel_number',
          $form_state->getValue(array('tel', 'tel_number')));
      $this->setConfigurationValue('tel_number_affichage',
          $form_state->getValue(array('tel','tel_number_affichage')));

      $this->setConfigurationValue('link_ecrire',
          $form_state->getValue(array('ecrire','link_ecrire')));
      $this->setConfigurationValue('link_ecrire_text',
          $form_state->getValue(array('ecrire','link_ecrire_text')));
      $this->setConfigurationValue('ecrire_icon',
          $form_state->getValue(array('ecrire','ecrire_icon')));
  }
}
