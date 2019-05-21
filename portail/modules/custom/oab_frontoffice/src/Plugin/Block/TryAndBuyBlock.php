<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 05/12/2017
 * Time: 10:28
 */

namespace Drupal\oab_frontoffice\Plugin\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\node\Entity\Node;

/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "try_and_buy_block",
 *   admin_label = @Translation("Try and Buy Block"),
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

class TryAndBuyBlock  extends BlockBase {

    public function build() {
        $block = array();
        $block_empty = true;
        // récupération du contexte
        $node_context = $this->getContextValue('node');
        $nid_field = $node_context->nid->getValue();
        $nid = $nid_field[0]['value'];
        // chargement du noeud et de la valeur axiome_data
        $node = Node::load($nid);
        $type = $node->getType();

        if ($type == 'product') {
            /**
             * Préparation du code à venir pour Axiome : par la suite les information pourront venir d'Axiome, il faudra alors modifier ce block pour afficher les infos d'Axiome
             */
            /*
            if ($node->hasField('field_axiome_data')) {
                $field_axiome_data = isset($node->field_axiome_data) ? unserialize($node->field_axiome_data->value) : array();
                if (is_array($field_axiome_data) && count($field_axiome_data) > 0) {
                    $axiome_data = $field_axiome_data;
                    $blockEmpty = FALSE;
                }
            }
            * FIN traitement des données Axiome
            */
            //var_dump($blockEmpty) ; die();
            if ($block_empty) {
                if ($node->hasField('field_try_and_buy')) {
                    $field_data = $node->get('field_try_and_buy');
                    foreach ($field_data as $data) {
                        $block[] = $data->view();
                        $block_empty = FALSE;
                    }
                }
            }
        }
        if (!$block_empty) {
            return $block;
        } else {
            return NULL;
        }
    }
}
