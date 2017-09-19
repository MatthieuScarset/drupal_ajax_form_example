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
           #$block['rebondProduct_']

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

          }*/

          ##Changement pour la zone, on l'affiche toujours avec une URL par défaut si non dispo via Axiome
          $block['rebondProduct']['type'] = 'espaceClient';
          $block['rebondProduct']['title'] = t('My Service Space');
          $block['rebondProduct']['text']  = t("Track your use, manage your bills, options and services 24/24");
          $block['rebondProduct']['signin_text'] = t("Sign in");
          $block['rebondProduct']['create_text'] = t("Create an account");
          $block['rebondProduct']['create_link'] = t("http://www.orange-business.com/en/my-service-space-account-request");

          if (isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']
          ['Attributes']['online_purchase_customer_area']) && is_string($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']
            ['Attributes']['online_purchase_customer_area'])) {
            $block['rebondProduct']['signin_link'] = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes']['online_purchase_customer_area'];
          } else {
            $block['rebondProduct']['signin_link'] = t("https://dro.orange-business.com/authentification?TYPE=33554433&REALMOID=06-0000e733-54df-1266-8576-5e0e0a63d064&GUID=&SMAUTHREASON=0&METHOD=GET&SMAGENTNAME=-SM-TPZ0eHv9wdQAe0KqXWVXK5B%2b8mUfc6au28lAfEL%2bvsCray2ghF0v8nhYk9lzcjpc&TARGET=-SM-https%3a%2f%2fmy--service--space.orange--business.com%2f&codeContexte=MSS");
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