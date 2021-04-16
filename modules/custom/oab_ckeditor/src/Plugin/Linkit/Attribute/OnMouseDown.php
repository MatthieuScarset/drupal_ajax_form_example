<?php

/**
 * @file
 * Contains \Drupal\linkit\Plugin\Linkit\Attribute\Target.
 */

namespace Drupal\oab_ckeditor\Plugin\Linkit\Attribute;

use Drupal\linkit\AttributeBase;

/**
 * Target attribute.
 *
 * @Attribute(
 *   id = "onmousedown",
 *   label = @Translation("On mouse down"),
 *   html_name = "onmousedown",
 *   description = @Translation("Add onmousedown instructions"),
 * )
 */
class OnMouseDown extends AttributeBase {

  /**
   * {@inheritdoc}
   */
  public function buildFormElement($default_value) {
    return [
      '#type' => 'textfield',
      '#title' => t('OnMouseDown'),
      '#default_value' => $default_value,
    ];
  }
}
