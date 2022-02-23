<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Render\RendererInterface;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 *
 * @author DMPT2806
 * @Block(
 *   id = "related_content_block",
 *   admin_label = @Translation("Related content"),
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

class RelatedContentBlock extends BlockBase implements ContainerFactoryPluginInterface {

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
    $content = "";
    $block = array();
    // récupération du contexte
    $node_ctxt = $this->getContextValue('node');
    $nid_fld = $node_ctxt->nid->getValue();
    $nid = $nid_fld[0]['value'];
    // chargement du noeud et de la valeur top zone
    $node = Node::load($nid);
    if ($node->hasField('field_related_content')) {
      $related_content = $node->get('field_related_content')->view('full');
      $content .= $this->renderer->render($related_content);
      //kint($related_content);
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
