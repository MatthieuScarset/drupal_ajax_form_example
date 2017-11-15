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
    $content = "";
    $block = array();
    // récupération du contexte
    $node_ctxt = $this->getContextValue('node');
    $nid_fld = $node_ctxt->nid->getValue();
    $nid = $nid_fld[0]['value'];

    // chargement du noeud et du field Wysiwyg
    $node = Node::load($nid);
    if ($node->hasField('field_wysiwyg_rebond')) {
      $related_content = $node->get('field_wysiwyg_rebond');
      #$related_content = $node->get('field_wysiwyg_rebond');
      #$content .= render($related_content);
     # kint(gettype($related_content));
      #kint($related_content[0]->getValue()); die();
      $b = $related_content[0]->getValue();
      $block["#markup"] = $b['value'];
    }

    #$block = $content;
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