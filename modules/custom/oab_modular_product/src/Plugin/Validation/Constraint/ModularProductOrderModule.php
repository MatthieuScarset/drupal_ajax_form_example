<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\Annotation\Translation;
use Symfony\Component\Validator\Constraint;

/**
 * @Constraint(
 *   id = "ModularProductOrderModule",
 *   label = @Translation("Modular Product Order Module", context = "Validation"),
 *   type = "string"
 * )
 */
class ModularProductOrderModule extends Constraint {
  public string $badOrder = 'Modules are not well ordered. Here is the expected order : %value';
}
