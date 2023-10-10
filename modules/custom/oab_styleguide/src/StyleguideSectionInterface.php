<?php

namespace Drupal\oab_styleguide;

use Drupal\Core\Plugin\ContainerFactoryPluginInterface;

/**
 * Interface for styleguide_section plugins.
 */
interface StyleguideSectionInterface extends ContainerFactoryPluginInterface {

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
   * Returns the list of styleguide_element plugins for this section.
   *
   * @return \Drupal\oab_styleguide\StyleguideElementInterface[]
   *   The list of plugins already instanciated.
   */
  public function elements();

  /**
   * Returns the state by default.
   *
   * @return bool
   *   The open or close value.
   */
  public function isOpen();

}
