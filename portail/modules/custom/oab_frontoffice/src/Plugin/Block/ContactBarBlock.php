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
 *   context = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */

class ContactBarBlock extends BlockBase {

  public function build(){
    $block = array();

    $block['#markup'] = $this->configuration['content'];
    $block['#format'] = $this->configuration['content_format'];

      // récupération du contexte
      $node_context = $this->getContextValue('node');
      $nid_field = $node_context->nid->getValue();
      $nid = $nid_field[0]['value'];

      // chargement du noeud et de la valeur axiome_data
      $node = Node::load($nid);
      $type = $node->getType();

      if($type == 'product'){
        if ($node->hasField('field_axiome_data')) {

            //on deserialise les données à passer au template
            $field_axiome_data = isset($node->field_axiome_data) ? unserialize($node->field_axiome_data->value) : array();
            if(count($field_axiome_data) > 0)
            {
                $axiome_data = $field_axiome_data;
               // oabt($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']);

                $block['numero'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['contact_us'];


                $block['detail_numero'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['contact_form'];
            }
        }
      }
    return $block;
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    $form['content'] = array(
      '#type' => 'text_format',
      '#title' => t('Contact Bar content'),
      '#default_value' => isset($this->configuration['content']) ? $this->configuration['content'] : '',
      '#format' => isset($this->configuration['content_format']) ? $this->configuration['content_format'] : 'full_html',
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
    $content = $form_state->getValue('content');
    $this->configuration['content'] = $content['value'];
    $this->configuration['content_format'] = $content['format'];
  }
}