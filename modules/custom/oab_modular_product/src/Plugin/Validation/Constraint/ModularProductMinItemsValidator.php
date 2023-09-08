<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\paragraphs\Entity\Paragraph;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the UniqueInteger constraint.
 */
class ModularProductMinItemsValidator extends ConstraintValidator {

  /**
   * {@inheritdoc}
   * @var \Drupal\entity_reference_revisions\EntityReferenceRevisionsFieldItemList $entity
   */
  public function validate($entity, Constraint $constraint) {

    $max_items = $entity->getEntity()->bundle() === "module_business_case"
      ? 2
      : 3;  // Default value

    if ($entity->count() < $max_items) {
      $this->context->addViolation($constraint->minValue, [
        '%max_items' => $max_items,
        '%value' => $entity->getEntity()->bundle()
      ]);
    }
  }

}
