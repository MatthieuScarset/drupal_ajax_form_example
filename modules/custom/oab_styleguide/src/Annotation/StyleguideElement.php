<?php

namespace Drupal\oab_styleguide\Annotation;

use Drupal\Component\Annotation\Plugin;

/**
 * Defines styleguide_element annotation object.
 *
 * @Annotation
 */
class StyleguideElement extends Plugin {

  /**
   * The plugin ID.
   *
   * @var string
   */
  public $id;

  /**
   * The human-readable name of the plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $title;

  /**
   * The description of the plugin.
   *
   * @var \Drupal\Core\Annotation\Translation
   *
   * @ingroup plugin_translatable
   */
  public $description;

}
