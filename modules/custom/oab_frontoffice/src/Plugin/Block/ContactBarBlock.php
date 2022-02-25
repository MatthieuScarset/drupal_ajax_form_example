<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "contact_bar_block",
 *   admin_label = @Translation("Contact Bar"),
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

class ContactBarBlock extends BlockBase {

  public function build() {

      $config = $this->getConfiguration();

      $link_assistance = isset($config['link_assistance']) ? $config['link_assistance'] : '';
      $link_assistance_text = isset($config['link_assistance_text']) ? $config['link_assistance_text'] : '';

      $link_ecrire = isset($config['link_ecrire']) ? $config['link_ecrire'] : '';
      $link_ecrire_text = isset($config['link_ecrire_text']) ? $config['link_ecrire_text'] : '';

      $block = array();
      $block['link_assistance'] = $link_assistance;
      $block['link_assistance_text'] = $link_assistance_text;

      $block['link_ecrire'] = $link_ecrire;
      $block['link_ecrire_text'] = $link_ecrire_text;


/* CODE A RE-UTILISER LORSQU'ON VOUDRA RECUPERER LE NUMERO DEPUIS LE FLUX AXIOME  - JIRA 2974
      // récupération du contexte
      $node_context = $this->getContextValue('node');
      $nid_field = $node_context->nid->getValue();
      $nid = $nid_field[0]['value'];

      // chargement du noeud et de la valeur axiome_data
      $node = Node::load($nid);
      $type = $node->getType();

      if ($type == 'product') {
        if ($node->hasField('field_axiome_data')) {

            //on deserialise les données à passer au template
            $field_axiome_data = isset($node->field_axiome_data) ? unserialize($node->field_axiome_data->value) : array();
            if (count($field_axiome_data) > 0)
            {
                $axiome_data = $field_axiome_data;
               // oabt($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']);

                $block['numero'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['contact_us'];


                $block['detail_numero'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['contact_form'];
            }
        }
      }*/
    return $block;
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    /*$form['content'] = array(
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

      $form['link_ecrire'] = [
          '#title' => $this->t('Lien vers Nous écrire'),
          '#type' => 'textfield',
          '#default_value' => isset($this->configuration['link_ecrire']) ? $this->configuration['link_ecrire'] : '',
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
    //$content = $form_state->getValue('content');
    //$this->configuration['content'] = $content['value'];
    //  $this->configuration['content_format'] = $content['format'];

      $this->setConfigurationValue('link_assistance', $form_state->getValue('link_assistance'));
      $this->setConfigurationValue('link_assistance_text', $form_state->getValue('link_assistance_text'));

      $this->setConfigurationValue('link_ecrire', $form_state->getValue('link_ecrire'));
      $this->setConfigurationValue('link_ecrire_text', $form_state->getValue('link_ecrire_text'));
  }
}
