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
 *   id = "classes",
 *   label = @Translation("Classes"),
 *   html_name = "class",
 *   description = @Translation("Add custom classes to your link"),
 * )
 */
class Classes extends AttributeBase {

  /**
   * {@inheritdoc}
   */
  public function buildFormElement($default_value) {
    return [
      '#type' => 'textfield',
      '#title' => t('Classes'),
      '#default_value' => $default_value,
    ];
  }
}
