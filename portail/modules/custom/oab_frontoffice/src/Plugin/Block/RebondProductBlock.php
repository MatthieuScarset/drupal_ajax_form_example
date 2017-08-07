<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;


/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "rebond_product_block",
 *   admin_label = @Translation("Rebond product"),
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

class RebondProductBlock extends BlockBase {

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

          #oabt($axiome_data, true);
          /*$block['titre_promoactu'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['free_test_title']['@attributes'][name];
          $block['texte_promoactu'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['free_test_text']['@attributes'][name];
          $block['textelien_promoactu'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['free_test_link_text']['@attributes'][name];
          $block['url_promoactu'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['free_test_url']['@attributes'][name];

          #$block['rebondProduct_']
           */
          /**
           * Ordre de priorité :
           *  1. Portail dédié
           *  2. Boutiques
           *  3. Espace client
          */
          /*if (isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']
            ['Attributes']['online_purchase_dedicated_portal'])) {

            $block['rebondProduct_type'] = 'portailDedie';
            $block['rebondProduct_link'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['online_purchase_dedicated_portal'];

          }  elseif (isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']
          ['Attributes']['online_purchase_shops'])) {

            $block['rebondProduct_type'] = 'boutique';
            $block['rebondProduct_link'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['online_purchase_shops'];

          } else*/if (isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']
          ['Attributes']['online_purchase_customer_area'])) {

            $block['rebondProduct']['type'] = 'espaceClient';
            $block['rebondProduct']['title'] = t('My Service Space');
            $block['rebondProduct']['text']  = t("Track your use, manage your bills, options and services 24/24");
            $block['rebondProduct']['link'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['online_purchase_customer_area'];
            $block['rebondProduct']['link_text'] = t("Sign in");
          }

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
      '#title' => t('Promo Actu content'),
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