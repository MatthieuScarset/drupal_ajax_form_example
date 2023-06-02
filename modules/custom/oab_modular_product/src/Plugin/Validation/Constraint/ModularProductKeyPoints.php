<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;

/**
 * Checks that the submitted value is a unique integer.
 *
 * @Constraint(
 *   id = "ModularProductKeyPoints",
 *   label = @Translation("Modular Product key points", context = "Validation"),
 *   type = "string"
 * )
 */
class ModularProductKeyPoints extends Constraint {

  public string $message = 'At least one value is required for Category page -> key points.';

}
