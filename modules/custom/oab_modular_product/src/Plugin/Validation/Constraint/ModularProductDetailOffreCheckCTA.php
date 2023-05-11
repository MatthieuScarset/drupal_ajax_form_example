<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;

/**
 * Checks that the submitted value is a unique integer.
 *
 * @Constraint(
 *   id = "ModularProductDetailOffreCheckCTA",
 *   label = @Translation("Modular Product Detail Offre Check CTA", context = "Validation"),
 *   type = "string"
 * )
 */
class ModularProductDetailOffreCheckCTA extends Constraint {

  public $error = 'A global call to action is defined on the Offer Details module. You cannot enter a Call To Action at the "offer detail" item level';

}
