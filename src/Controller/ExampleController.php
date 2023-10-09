<?php

namespace Drupal\mymodule\Controller;

use Drupal\Component\Serialization\Json;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Url;

/**
 * Returns responses for mymodule module routes.
 */
class ExampleController extends ControllerBase {

  /**
   * Displays the demo page.
   *
   * @return string
   *   The rendered list of items for the feed.
   */
  public function page() {
    $build = [];

    $build['form_with_custom_ajax'] = [
      '#type' => 'link',
      '#url' => Url::fromRoute('mymodule.form'),
      '#title' => $this->t('Open form with custom ajax command'),
      '#weight' => 99,
      '#attributes' => [
        'class' => ['use-ajax'],
        'data-dialog-type' => 'modal', // 'dialog',
        'data-dialog-options' => Json::encode([
          'width' => 768,
          'dialogClass' => 'this-is-a-demo',
        ]),
      ],
    ];


    $build['form_with_helper'] = [
      '#type' => 'link',
      '#url' => Url::fromRoute('mymodule.form'),
      '#title' => $this->t('Open the form using AJaxFormHelperTrait'),
      '#weight' => 99,
      '#attributes' => [
        'class' => ['use-ajax'],
        'data-dialog-type' => 'modal', // 'dialog',
        'data-dialog-options' => Json::encode([
          'width' => 768,
          'dialogClass' => 'this-is-a-demo',
        ]),
      ],
      '#access' => FALSE,
    ];

    $build['#attached']['library'][] = 'core/drupal.ajax';
    $build['#attached']['library'][] = 'core/drupal.dialog.ajax';

    return $build;
  }
}
