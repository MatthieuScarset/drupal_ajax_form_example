<?php

namespace Drupal\oab_styleguide;

use Drupal\Core\Plugin\ContainerFactoryPluginInterface;

/**
 * Interface for styleguide_element plugins.
 */
interface StyleguideElementInterface extends ContainerFactoryPluginInterface {

  /**
   * Returns the translated plugin label.
   *
   * @return string
   *   The translated title.
   */
  public function label();

  /**
   * Returns the translated plugin description.
   *
   * @return string
   *   The translated description.
   */
  public function description();

  /**
   * Returns the content of this element.
   *
   * @return array
   *   A renderable array.
   */
  public function render();

}
