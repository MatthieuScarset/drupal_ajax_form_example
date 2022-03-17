<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Render\RendererInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

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

class RightIconBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * @var RendererInterface
   */
  private $renderer;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, RendererInterface $renderer_interface) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->renderer = $renderer_interface;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new self(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('renderer')
    );
  }

  public function build() {
            $form = NULL;
            if (\Drupal::moduleHandler()->moduleExists('oab_synomia_search_engine')) {
                $render = \Drupal::formBuilder()->getForm('Drupal\oab_synomia_search_engine\Form\SynomiaSearchHeaderBlockForm');
                $form = $this->renderer->render($render);
            }
            return array(
                '#theme' => 'custom-righticonblock',
                '#synomiaSearchForm' => $form,
            );

    }

}
