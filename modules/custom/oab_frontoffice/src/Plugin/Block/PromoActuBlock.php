<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;


/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "promo_actu_block",
 *   admin_label = @Translation("Promo Actu"),
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

class PromoActuBlock extends BlockBase {

    public function build() {
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



        if ($type == 'product') {
            if ($node->hasField('field_axiome_data')) {

                //on deserialise les données à passer au template
                $field_axiome_data = isset($node->field_axiome_data) && $node->field_axiome_data->value !== null ? unserialize($node->field_axiome_data->value) : array();
                if (is_countable($field_axiome_data) && count($field_axiome_data) > 0) {

                    if (isset($field_axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes'])) {
                      $zone_see_more_attr = $field_axiome_data['Children']['ruby_theme']['Children']['ruby_zone_seemore']['Attributes'];

                      if (isset($zone_see_more_attr['free_test_title']) && is_string($zone_see_more_attr['free_test_title'])
                        && isset($zone_see_more_attr['free_test_text']) && is_string($zone_see_more_attr['free_test_text'])
                        && isset($zone_see_more_attr['free_test_link_text']) && is_string($zone_see_more_attr['free_test_link_text'])
                        && isset($zone_see_more_attr['free_test_url']) && is_string($zone_see_more_attr['free_test_url'])
                      ) {
                          $block['titre_promoactu'] = $zone_see_more_attr['free_test_title'];
                          $block['texte_promoactu'] = $zone_see_more_attr['free_test_text'];
                          $block['textelien_promoactu'] = $zone_see_more_attr['free_test_link_text'];
                          $block['url_promoactu'] = $zone_see_more_attr['free_test_url'];
                      }

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
