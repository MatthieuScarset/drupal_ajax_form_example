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

    switch ($entity->getEntity()->bundle()) {
      case 'module_business_case':
        if ($entity->count() < 2) {
          $this->context->addViolation($constraint->minItems, [
            '%value' => $entity->getEntity()->bundle()
          ]);
        }
        break;

      case 'module_business_case_item':
        if ($entity->count() < 3) {
          $this->context->addViolation($constraint->keyPointValue, [
            '%value' => $entity->getEntity()->bundle()
          ]);
        }
        break;

      default:
        if ($entity->count() < 3) {
          $this->context->addViolation($constraint->minValue, [
            '%value' => $entity->getEntity()->bundle()
          ]);
        }
        break;
    }
  }

}
