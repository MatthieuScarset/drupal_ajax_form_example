<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;
use Drupal\Core\Annotation\Translation;

/**
 * Checks that the submitted value is a unique integer.
 *
 * @Constraint(
 *   id = "ModularProductModuleRequired",
 *   label = @Translation("Modular Product Module Required", context = "Validation"),
 *   type = "string"
 * )
 */
class ModularProductModuleRequired extends Constraint{

  // The message that will be shown if the value is not an integer.
  public string $required = 'The module %value is required';
  public string $required_multi = 'Modules %value are required';
}
