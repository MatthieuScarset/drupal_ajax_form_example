<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\oab_subhomes\Entity\SubhomeEntity;
use Drupal\views\Entity\View;

/**
 *
 * @author LRJV7114
 * @Block(
 *   id = "top_zone_subhome_press_block",
 *   admin_label = @Translation("Top Zone Subhome Press"),
 *   category = @Translation("Blocks"),
 * )
 *
 */
class TopZoneSubhomePress extends BlockBase {

  /**
   * @throws \Drupal\Component\Plugin\Exception\ContextException
   */
  public function build(): array {
    $block = [];
    $current_route = \Drupal::routeMatch()->getRouteName();

    if ($current_route === 'view.subhomes.page_press') {
      if (\Drupal::routeMatch()->getParameters()->has('view_id')) {
        $route_parts = explode('.', $current_route);
        $display_id = $route_parts[2];

        $view = View::load(\Drupal::routeMatch()->getParameters()->get('view_id'));

        if ($view !== null) {
          /** @var \Drupal\views\ViewExecutable $view_executable */
          $view_executable = $view->getExecutable();
          $view_executable->setDisplay($display_id);
          $view_executable->preview();

          if (isset($view_executable->argument['field_subhome_target_id'])) {
            $sid = $view_executable->argument['field_subhome_target_id']->value;
            $subhome_entity = SubhomeEntity::loadBySubhomeId($sid);
            $block['subhome_title'] = $subhome_entity->getTitle();
            $block['subhome_description'] = $subhome_entity->getDescription();

           if ($subhome_entity->hasField('field_carrousel')) {
             $block['subhome_carousel'] = $subhome_entity->field_carrousel->view('default');
           }
          }
        }
      }
    }
    return $block;
  }
}
