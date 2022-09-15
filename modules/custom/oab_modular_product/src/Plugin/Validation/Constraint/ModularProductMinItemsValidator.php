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
    if ($entity->count() < 3) {
      $this->context->addViolation($constraint->minValue, [
        '%value' => $entity->getEntity()->bundle()
      ]);
    }
  }


}