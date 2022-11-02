<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class ModularProductModuleRequiredValidator extends ConstraintValidator {

  /**
   * @param \Drupal\Core\Field\FieldItemList $items
   * @param \Symfony\Component\Validator\Constraint $constraint
   *
   * @return void
   */
  public function validate($items, Constraint $constraint) {
    //On récupère les modules ajoutés en BO
    $list_module = [];
    $module_required = "module_benefits";
    foreach ($items as $item) {
      if (isset($item->entity)) {
        $list_module[] = $item->entity->bundle();
      }
    }

    if (!in_array($module_required, $list_module)) {
      $this->context->addViolation($constraint->required, [
        "%value" => "benefite"
      ]);
    }
  }
}
