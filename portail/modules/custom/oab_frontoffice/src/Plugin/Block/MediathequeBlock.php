<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;

/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "mediatheque_block",
 *   admin_label = @Translation("Mediathèque"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class MediathequeBlock extends BlockBase {

  public function build(){
    $block = array();
    // récupération du contexte
    /*$node_ctxt = $this->getContextValue('node');
    $nid_fld = $node_ctxt->nid->getValue();
    $nid = $nid_fld[0]['value'];
    // chargement du noeud et de la valeur top zone
    $node = Node::load($nid);
    if ($node->hasField('field_local_nav')) {
      $localnav = $node->get('field_local_nav')->getValue();
    }

    $block['type'] = 'processed_text';
    $block['#markup'] = '';
    $content = '';
    if(isset($localnav[0]['value'])){
      $content = check_markup($localnav[0]['value'], 'full_html', '', FALSE);
    }
    $block = $content;*/

    //return $block;

    return array(
      'text' => t('Vous êtes à la recherche d\'images ou de vidéos pour illustrer vos supports de communication ?'),
      'link'  => t('https://mediatheque.orange.com/en/mediacenter'),
      'link_text' => t("Lorem")
    );
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