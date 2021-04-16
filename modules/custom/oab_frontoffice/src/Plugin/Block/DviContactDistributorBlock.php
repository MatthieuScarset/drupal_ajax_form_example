<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;


/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "dvi_contact_distributor_block",
 *   admin_label = @Translation("Dvi - Contact Distributor Block"),
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

class DviContactDistributorBlock extends BlockBase {

    public function build() {
        $block = array();



        // récupération du contexte
        $node_context = $this->getContextValue('node');
        $nid_field = $node_context->nid->getValue();
        $nid = $nid_field[0]['value'];

        // chargement du noeud et de la valeur axiome_data
        $node = Node::load($nid);
        $type = $node->getType();

        if ($type == 'distributor') {
            $form = \Drupal\webform\Entity\Webform::load('dvi_contact_distributor');
            $block["form"] = \Drupal::service('entity_type.manager')
                ->getViewBuilder('webform')
                ->view($form);

            $block["distributorName"] = $node->getTitle();
        }
        return $block;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
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

    }
}
