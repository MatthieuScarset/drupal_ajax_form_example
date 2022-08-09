<?php

namespace Drupal\oab_mp_product_formule_packages\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;


/**
 * Checks that the submitted value is a unique integer.
 *
 * @Constraint(
 *   id = "FormuleFieldConstraint",
 *   label = @Translation("Verify that the formule field couple doesnt exists for the current entity type", context = "Validation"),
 *   type = "string"
 * )
 */
class FormuleField extends Constraint {

  public $alreadyExists = "This choice already exists for the %entity entity";

}
