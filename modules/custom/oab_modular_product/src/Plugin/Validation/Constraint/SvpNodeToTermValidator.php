<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\node\NodeInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the field_svp constraint.
 */
class SvpNodeToTermValidator extends ConstraintValidator implements ContainerInjectionInterface {

  /**
   * Entity type manager service.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  public function __construct(EntityTypeManagerInterface $entity_type_manager) {
    $this->entityTypeManager = $entity_type_manager;
  }

  /**
   * @inheritDoc
   */
  public static function create(ContainerInterface $container) {
    return new self(
      $container->get('entity_type.manager')
    );
  }

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
    $allowed_bundles = ['svp', 'domain'];
    if (!in_array($bundle, $allowed_bundles)) {
      $this->context->addViolation($constraint->wrongBundle, [
        '%field' => $items->getName(),
        '%bundle' => $bundle,
      ]);
    }

    // Check SVP term is not used in another published SVP node.
    if ($entity->bundle() == 'svp' && !$items->isEmpty()) {
      $tid = $items[0]->target_id;

      $nids = $this->entityTypeManager->getStorage('node')->getQuery()
        ->condition('field_svp', $tid)
        ->condition('status', NodeInterface::PUBLISHED)
        ->condition('type', 'svp')
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
