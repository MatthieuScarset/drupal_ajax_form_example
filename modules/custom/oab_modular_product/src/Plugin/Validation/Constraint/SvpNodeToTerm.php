<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;

/**
 * Checks that SVP Node to Term relationship.
 *
 * @Constraint(
 *   id = "SvpNodeToTerm",
 *   label = @Translation("SVP Node to Term relationship", context = "Validation"),
 *   type = "entity_reference"
 * )
 */
class SvpNodeToTerm extends Constraint {
  public $missingEntity = 'Cannot find the parent entity for %field';
  public $wrongBundle = '%field should not be used on this entity %bundle';
  public $alreadyUsedByOne = 'This SVP term is already used by another SVP (ID: %nid). Unpublish the other node and resave this form.';
  public $alreadyUsedByMany = 'This SVP term is already used by others SVP (ID: %nids). Unpublish these nodes and resave this form.';
}
