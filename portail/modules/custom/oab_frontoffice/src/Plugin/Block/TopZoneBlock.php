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
 * @author DMPT2806
 * @Block(
 *   id = "top_zone_block",
 *   admin_label = @Translation("Top Zone"),
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

class TopZoneBlock extends BlockBase {

    public function build() {
        $block = array();
        // récupération du contexte
        $node_ctxt = $this->getContextValue('node');
        $nid_fld = $node_ctxt->nid->getValue();
        $nid = $nid_fld[0]['value'];
        // chargement du noeud et de la valeur top zone
        $node = Node::load($nid);
        if ($node->hasField('field_top_zone')) {
            $top_zone = $node->get('field_top_zone')->getValue();
        }
        if ($node->hasField('field_top_zone_background')) {
            $top_zone_background = $node->get('field_top_zone_background')->getValue();
        }
        if ($node->hasField('field_top_zone_bg_mobile')) {
            $top_zone_background_mobile = $node->get('field_top_zone_bg_mobile')->getValue();
        }
        $block['#type'] = 'markup';
        $block['#markup'] = '';
        $content = '';
        $content_top = '';
        $content_desktop = '';
        $content_mobile = '';

        if (isset($top_zone[0]['value'])) {
            $content_top = check_markup($top_zone[0]['value'], 'full_html', '', []);
        }
        if (isset($top_zone_background[0]['target_id'])) {
            $entity = \Drupal::entityTypeManager()->getStorage('media')->load((int) $top_zone_background[0]['target_id']);

            $url = '';
            if (!is_null($entity)) {
                $uri = $entity->getType()->thumbnail($entity);
                $type = $node->getType();
                if ($type == 'product') {
                    $img_style = 'top_zone';
                } else {
                    $img_style = 'top_zone_big';
                }
                $url = ImageStyle::load($img_style)->buildUrl($uri);
                $url = file_url_transform_relative($url);
            }
            $class_hidden_xs = "";
            if (isset($top_zone_background_mobile[0]['target_id'])) {
                $class_hidden_xs = 'class="hidden-xs"';
            }
            $content_desktop = check_markup('<div id="topzonebg"  '.$class_hidden_xs.' style="background:url('.$url.') top center no-repeat">'.$content_top.'</div>', 'full_html', '', []);
            $content = $content_desktop;
        }
        if (isset($top_zone_background_mobile[0]['target_id'])) {
            $entity = \Drupal::entityTypeManager()->getStorage('media')->load((int) $top_zone_background_mobile[0]['target_id']);
            $url = '';
            if (!is_null($entity)) {
                $uri = $entity->getType()->thumbnail($entity);
                $img_style = 'max_650';
                $url = ImageStyle::load($img_style)->buildUrl($uri);
                $url = file_url_transform_relative($url);
            }
            $content_mobile = check_markup('<div id="topzonebg-mobile"  class="visible-xs" style="background:url('.$url.') top center no-repeat">'.$content_top.'</div>', 'full_html', '', []);
            $content = check_markup($content_desktop . $content_mobile, 'full_html', '', []) ;
        }
        $block['#markup'] = $content;
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
