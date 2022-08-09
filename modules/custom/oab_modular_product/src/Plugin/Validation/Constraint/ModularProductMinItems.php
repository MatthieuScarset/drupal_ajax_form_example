<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;

/**
 * Checks that the submitted value is a unique integer.
 *
 * @Constraint(
 *   id = "ModularProductMinItems",
 *   label = @Translation("Modular Product Min teps", context = "Validation"),
 *   type = "string"
 * )
 */
class ModularProductMinItems extends Constraint {

  // The message that will be shown if the value is not an integer.
  public $minValue = 'You should have at least 3 items in %value.';

}
