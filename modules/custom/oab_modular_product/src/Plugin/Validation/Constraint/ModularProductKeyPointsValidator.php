<?php


namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\Entity\Plugin\DataType\EntityAdapter;
use Drupal\node\Entity\Node;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the UniqueInteger constraint.
 */
class ModularProductKeyPointsValidator extends ConstraintValidator
{
  /**
   * @param \Drupal\Core\Field\FieldItemList $items
   * @param \Symfony\Component\Validator\Constraint $constraint
   *
   * @return void
   */
  public function validate($items, Constraint $constraint) {

    /** @var EntityAdapter $parent */
    $parent = $items->getParent();

    //Ne pas appliquer la contrainte dans la page de l'édition du field_key_points
    if ($parent->getEntity()->id()!= null && count($items->getValue()) < 3) {
      $this->context->addViolation($constraint->message);
    }
  }

}
