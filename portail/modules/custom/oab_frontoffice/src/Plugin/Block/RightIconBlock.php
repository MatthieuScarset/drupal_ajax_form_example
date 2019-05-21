<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "right_icon_block",
 *   admin_label = @Translation("Right icon Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class RightIconBlock extends BlockBase {

    public function build() {
            $form = NULL;
            if (\Drupal::moduleHandler()->moduleExists('oab_synomia_search_engine')) {
                $render = \Drupal::formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchHeaderBlockForm');
                $form = render($render);
            }
            return array(
                '#theme' => 'custom-righticonblock',
                '#synomiaSearchForm' => $form,
            );

    }

}
