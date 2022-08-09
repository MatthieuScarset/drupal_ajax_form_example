<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Render\RendererInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "newsletter_block",
 *   admin_label = @Translation("Newsletter Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class NewsletterBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * @var RendererInterface
   */
  private $renderService;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, RendererInterface $renderer_interface) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);

    $this->renderService = $renderer_interface;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new self(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('renderer')
    );
  }

  /**
   * @throws \Exception
   */
  public function build() {

    $form = \Drupal::formBuilder()->getForm('Drupal\oab_frontoffice\Form\NewsletterForm');

    return array(
      '#markup' => $this->renderService->render($form),
      '#attached' => array(
      ),
    );
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
