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
 *   id = "styles",
 *   label = @Translation("Styles"),
 *   html_name = "style",
 *   description = @Translation("Add custom styles instructions"),
 * )
 */
class Styles extends AttributeBase {

  /**
   * {@inheritdoc}
   */
  public function buildFormElement($default_value) {
    return [
      '#type' => 'textfield',
      '#title' => t('Styles'),
      '#default_value' => $default_value,
    ];
  }
}
