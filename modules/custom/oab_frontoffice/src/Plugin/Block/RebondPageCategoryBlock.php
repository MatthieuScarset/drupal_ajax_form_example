<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;
use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;


/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "rebond_page_category_block",
 *   admin_label = @Translation("Rebond page category"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class RebondPageCategoryBlock extends BlockBase {

  public function build() {
    $block = array();
    $current_route = \Drupal::routeMatch()->getRouteName();
    if ($current_route == 'view.category_page.category_page') {
      if (\Drupal::routeMatch()->getParameters()->has('tid')) {
        $term_id = \Drupal::routeMatch()->getParameters()->get('tid');
        $term = Term::load($term_id);
        if ($term->hasField('field_block_rebond') && isset($term->get('field_block_rebond')->getValue()[0]['value'])) {
          $block['categ_rebond'] = check_markup($term->get('field_block_rebond')->getValue()[0]['value'], 'full_html', '', []);
        }
      }
    }
  //  kint($block);die();
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
