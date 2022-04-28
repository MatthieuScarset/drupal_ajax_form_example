<?php

namespace Drupal\oab_mp_formule_field\Plugin\Validation\Constraint;

use Drupal\Core\Field\FieldFilteredMarkup;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class FormuleFieldValidator extends ConstraintValidator {

  /**
   * @param \Drupal\Core\Entity\EntityInterface $value
   * @param \Symfony\Component\Validator\Constraint $constraint
   */
  public function validate($value, Constraint $constraint) {

    $entity_type = $value->getEntityTypeId();
    $base_table = $value->getEntityType()->getDataTable() ?? $value->getEntityType()->getBaseTable();


    $query = \Drupal::database()->select($base_table, 'e')
        ->fields('e', ['id'])
        ->condition('e.id', $value->id(), '<>')
        ->condition('e.type',$value->bundle());

    foreach ($value->get('formule_values')->getValue() as $key => $formule_value) {
      $alias = "fv_$key";
      $query->leftJoin(
        $entity_type . "__formule_values",
        $alias,
        "$alias.entity_id = e.id"
      );

      $query->condition("$alias.formule_values_formule_field_target", $formule_value['formule_field_target']);
      $query->condition("$alias.formule_values_value", $formule_value['value']);
    }


    $ids = array_keys($query->execute()->fetchAllKeyed());
    if (count($ids)) {
      $this->context->addViolation($constraint->alreadyExists, ['%entity' => $value->bundle()]);
    }

  }

}
