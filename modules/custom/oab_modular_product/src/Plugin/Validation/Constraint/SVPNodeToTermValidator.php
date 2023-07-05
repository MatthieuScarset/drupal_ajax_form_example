<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\node\NodeInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the field_svp constraint.
 */
class SVPNodeToTermValidator extends ConstraintValidator {

  /**
   * {@inheritdoc}
   */
  public function validate($items, Constraint $constraint) {
    $entity = $items->getEntity();
    if (!$entity instanceof ContentEntityInterface) {
      $this->context->addViolation($constraint->missingEntity, [
        '%field' => $items->getName(),
      ]);
    }

    $bundle = $entity->bundle();
    $allowed_bundles = ['svp'];
    if (!in_array($bundle, $allowed_bundles)) {
      $this->context->addViolation($constraint->wrongBundle, [
        '%field' => $items->getName(),
        '%bundle' => $bundle,
      ]);
    }

    // Check SVP term is not used in another published SVP node.
    if ($entity->bundle() == 'svp') {
      $tids = explode(', ', $items->getString());
      $nids = \Drupal::entityTypeManager()->getStorage('node')->getQuery()
        ->condition('field_svp', $tids, 'IN')
        ->condition('status', NodeInterface::PUBLISHED)
        ->accessCheck(FALSE)
        ->execute();

      // Remove current node from results.
      if (!$entity->isNew()) {
        $current_nid = $entity->id();
        $nids = array_filter($nids, function ($nid) use ($current_nid) {
          return $nid != $current_nid;
        });
      }

      if (!empty($nids)) {
        if (count($nids) > 1) {
          $this->context->addViolation($constraint->alreadyUsedByMany, [
            '%nids' => implode(', ', $nids),
          ]);
        } else {
          $this->context->addViolation($constraint->alreadyUsedByOne, [
            '%nid' => implode(', ', $nids),
          ]);
        }
      }
    }
  }
}
