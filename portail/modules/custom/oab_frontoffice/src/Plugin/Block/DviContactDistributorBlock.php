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

    public function build(){
        $block = array();



        // récupération du contexte
        $node_context = $this->getContextValue('node');
        $nid_field = $node_context->nid->getValue();
        $nid = $nid_field[0]['value'];

        // chargement du noeud et de la valeur axiome_data
        $node = Node::load($nid);
        $type = $node->getType();

        if($type == 'distributor'){
            $form = \Drupal\webform\Entity\Webform::load('dvi_contact_distributor');
            $form_output = \Drupal::entityManager()
                ->getViewBuilder('webform')
                ->view($form);
            /*$webform = \Drupal::entityTypeManager()->getStorage('webform')->load('dvi_contact_distributor');
            $block["form"] = $webform->getSubmissionForm();*/

            #$block["form"] = \Drupal::service('renderer')->renderRoot($form_output);
            /*$block["form"] = $form_output;
            $block["form"]["#webform"] = 'dvi_contact_distributor';

            $block["distributorName"] = $node->getTitle();*/
            #kint($block); die();


            /*$b = \Drupal\block\Entity\Block::load('dvi_contact_distributor');
            $block_content = \Drupal::entityManager()
                ->getViewBuilder('block')
                ->view($b);*/


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