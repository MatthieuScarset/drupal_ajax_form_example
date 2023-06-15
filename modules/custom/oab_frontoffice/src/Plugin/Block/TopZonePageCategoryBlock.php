<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Access\AccessResultForbidden;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\file\Entity\File;
use Drupal\image\Entity\ImageStyle;
use Drupal\media\Entity\Media;
use Drupal\taxonomy\Entity\Term;
use Drupal\taxonomy\TermStorage;
use Drupal\views\Views;

/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "top_zone_page_category_block",
 *   admin_label = @Translation("Top Zone Page Category"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class TopZonePageCategoryBlock extends BlockBase {

  public function access(AccountInterface $account, $return_as_object = FALSE) {
    $current_route = \Drupal::routeMatch()->getRouteName();
    if ($current_route == 'view.category_page.category_page') {
      if (\Drupal::routeMatch()->getParameters()->has('tid')) {
    return parent::access($account, $return_as_object); // TODO: Change the autogenerated stub
      }
    }
    return $return_as_object ? AccessResultForbidden::forbidden() : false;
  }

  public function build() {

      $block = array();
      $current_route = \Drupal::routeMatch()->getRouteName();
      if ($current_route == 'view.category_page.category_page') {
        if (\Drupal::routeMatch()->getParameters()->has('tid')) {

          $term_id = \Drupal::routeMatch()->getParameters()->get('tid');

          $term = Term::load($term_id);
          $block['categ_title'] = $term->getName();
          $block['categ_description'] = check_markup($term->getDescription(), 'full_html', '', []);

          //gestion de l'image
          if ($term->hasField('field_image')) {
            $top_zone_image = $term->get('field_image')->getValue();
            if (isset($top_zone_image[0]['target_id'])) {
              $file = File::load($top_zone_image[0]['target_id']);
              if (isset($file)) {
                $block['categ_image_uri'] = $file->getFileUri();
                $block['categ_image_alt'] = "test";
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

  public function getCacheContexts() {
    return parent::getCacheContexts()
      + ['url']; // TODO: Change the autogenerated stub
  }
}
