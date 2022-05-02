<?php

namespace Drupal\oab_modular_product\Plugin\Block;

use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Access\AccessResultForbidden;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\file\Entity\File;
use Drupal\media\Entity\Media;
use Drupal\node\Entity\Node;
use Drupal\paragraphs\Entity\Paragraph;
use Drupal\taxonomy\Entity\Term;

/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "page_menu_modular_product_block",
 *   admin_label = @Translation("Page Menu Modular Product"),
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
class PageMenuModularProductBlock extends BlockBase {

  /**
   * @throws \Drupal\Component\Plugin\Exception\ContextException
   */
  public function access(AccountInterface $account, $return_as_object = FALSE) {
    $node = $this->getContextValue('node');

    if ($node instanceof Node && $node->bundle() === "modular_product") {
      return parent::access($account, $return_as_object);
    }
    return $return_as_object ? AccessResultForbidden::forbidden() : false;
  }

  /**
   * @throws \Drupal\Component\Plugin\Exception\ContextException
   */
  public function build(): array {
    $block = [];
    $node = $this->getContextValue('node');
    if ($node instanceof Node && $node->bundle() === "modular_product") {
        if (!empty($node->field_presentation)) {
        $values_presentation = $node->field_presentation->getValue();
        foreach ( $values_presentation as $element ) {
          if (!empty($element['target_id'])) {
            $paragraphEntity = Paragraph::load($element['target_id']);
            if(!empty($paragraphEntity)) {
              if ($paragraphEntity->bundle() == 'module_presentation') {
                $block['children_items'][] = [
                  'id' => 'presentation',
                  'label' => t('Presentation')
                ];
              }
            }
          }
        }
      }

      if ($node->hasField('field_detail_offre') && !empty($node->field_detail_offre)) {
        $values_detail_offre = $node->field_detail_offre->getValue();
        foreach ( $values_detail_offre as $element ) {
          if(!empty($element['target_id'])) {
            $paragraphEntity = Paragraph::load($element['target_id']);
            if(!empty($paragraphEntity)) {
              if($paragraphEntity->bundle() == 'module_detail_offre') {
                $block['children_items'][] = [
                  'id' => 'detail-offre',
                  'label' => t('Offer Detail')
                ];
              }
              if($paragraphEntity->bundle() == 'module_detail_gamme') {
                $block['children_items'][] = [
                  'id' => 'detail-gamme',
                  'label' => t('Detail of the range')
                ];
              }
            }
          }
        }
      }
      if (!empty($node->field_modules)) {
        $values_modules = $node->field_modules->getValue();
        foreach ( $values_modules as $module ) {
          if(!empty($module['target_id'])) {
            $paragraphModuleEntity = Paragraph::load($module['target_id']);
            if(!empty($paragraphModuleEntity)) {
              if($paragraphModuleEntity->bundle() == 'module_services') {
                $block['children_items'][] = [
                  'id' => 'services',
                  'label' => t('Tailor-made services')
                ];
              }
              if($paragraphModuleEntity->bundle() == 'module_exemples') {
                $block['children_items'][] = [
                  'id' => 'exemple',
                  'label' => t('Example of realization')
                ];
              }
              if($paragraphModuleEntity->bundle() == 'module_testimonial') {
                $block['children_items'][] = [
                  'id' => 'temoignages',
                  'label' => t('Testimonials')
                ];
              }
            }
          }
        }
      }

      //parser les modules du field_modules
      // vérifier type du paragraph
      // pour ajouter lien si Services exclusifs / exemples / témoignages

      //regarder où on prend les libellés

    }
    return $block;
  }
}
