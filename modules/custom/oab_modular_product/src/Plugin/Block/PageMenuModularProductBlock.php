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
use Symfony\Contracts\Translation\TranslatorTrait;
use Drupal\oab_modular_product\Services;

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
 *       label = @Translation("Current Node"),
 *       required = FALSE,
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
    /** @var OabModularProductService $conf_modular_product */
    $conf_modular_product = \Drupal::service('oab_modular_product.settings');

    // PRESENTATION
    $paragraphEntity = Paragraph::load($node->field_presentation->target_id ?? 0);
    if(!empty($paragraphEntity)) {
      if ($paragraphEntity->bundle() == 'module_presentation') {
        $block['children_items'][] = [
          'id' => 'presentation',
          'label' => $this->t($conf_modular_product->getPresentationModuleTitle()),
        ];
      }
    }


    //DETAIL OFFRE/GAMME
    $paragraphEntity = Paragraph::load($node->field_detail_offre->target_id ?? 0);
    if(!empty($paragraphEntity)) {
      if($paragraphEntity->bundle() == 'module_detail_offre') {
        $block['children_items'][] = [
          'id' => 'detail-offre',
          'label' => $this->t($conf_modular_product->getOfferDetailTitle()),
        ];
      }
      if($paragraphEntity->bundle() == 'module_detail_gamme') {
        $block['children_items'][] = [
          'id' => 'detail-gamme',
          'label' => $this->t($conf_modular_product->getDetailGammeModuleTitle()),
        ];
      }
    }

    $variables['module_title'] = $conf_modular_product->getCustomerSpaceModuleTitle();
    //MODULES
    /** @var \Drupal\Core\Field\FieldItemList $module */
    foreach ( $node->field_modules as $module ) {
      $paragraphModuleEntity = Paragraph::load($module->target_id ?? 0);
      if(!empty($paragraphModuleEntity)) {
        if($paragraphModuleEntity->bundle() == 'module_services') {
          $block['children_items'][] = [
            'id' => 'services',
            'label' => $this->t($conf_modular_product->getServicesModuleTitle()),
          ];
        }
        if($paragraphModuleEntity->bundle() == 'module_customer_space') {
          $block['children_items'][] = [
            'id' => 'customer-space',
            'label' => $this->t($conf_modular_product->getCustomerSpaceModuleTitle()),
          ];
        }
        if($paragraphModuleEntity->bundle() == 'module_exemples') {
          $block['children_items'][] = [
            'id' => 'exemple',
            'label' => $this->t($conf_modular_product->getExamplesModuleTitle()),
          ];
        }
        if($paragraphModuleEntity->bundle() == 'module_testimonial') {
          $block['children_items'][] = [
            'id' => 'temoignages',
            'label' => $this->t($conf_modular_product->getTestimonialModuleTitle()),
          ];
        }
      }
    }
    $block['children_items'][] = [
      'id' => 'to_go_further',
      'label' => $this->t($conf_modular_product->getToGoFurtherTitle()),
    ];
    return $block;
  }
}
