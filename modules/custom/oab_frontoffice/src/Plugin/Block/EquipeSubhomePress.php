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
 *   id = "equipe_subhome_press_block",
 *   admin_label = @Translation("Equipe Subhome Press"),
 *   category = @Translation("Blocks"),
 * )
 *
 */
class EquipeSubhomePress extends BlockBase {

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
            $block['subhome_display_team_bloc'] = $subhome_entity->field_afficher_bloc_notre_equipe->value;
            $block['subhome_team_title'] = $subhome_entity->field_team_title->value;
            $block['subhome_team_visual'] = $subhome_entity->field_team_visual->view('default');
            $block['subhome_team_button'] = $subhome_entity->field_team_button->view('default');
          }
        }
      }
    }
    return $block;
  }
}
