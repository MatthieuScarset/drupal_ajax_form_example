<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "zone_rebond_wysiwyg_block",
 *   admin_label = @Translation("Zone rebond: WYSIWYG"),
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

class ZoneRebondWysiwygBlock extends BlockBase {

  public function build(){
    $block = array();
    // récupération du contexte
    $node_ctxt = $this->getContextValue('node');
    $nid_fld = $node_ctxt->nid->getValue();
    $nid = $nid_fld[0]['value'];

    // chargement du noeud et du field Wysiwyg
    $node = Node::load($nid);
    if ($node->hasField('field_wysiwyg_rebond')) {
      $field_data = $node->get('field_wysiwyg_rebond');
      if (isset($field_data[0])) {
        $field_value= $field_data[0]->getValue();
        $block["#markup"] = $field_value['value'];
      }
    }

    return $block;
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);
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