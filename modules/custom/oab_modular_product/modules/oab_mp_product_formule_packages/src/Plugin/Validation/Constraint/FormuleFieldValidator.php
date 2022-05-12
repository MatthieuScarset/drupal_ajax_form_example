<?php

namespace Drupal\oab_mp_product_formule_packages\Plugin\Validation\Constraint;


use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\entity_browser\Plugin\EntityBrowser\WidgetValidation\EntityType;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class FormuleFieldValidator extends ConstraintValidator implements ContainerInjectionInterface {




  /** @var \Drupal\oab_mp_product_formule_packages\FormulePackageStorage  */
  private $formulePackageStorage;

  public function __construct(EntityTypeManagerInterface $entity_type_manager) {
    $this->formulePackageStorage = $entity_type_manager->getStorage('formule_package');
  }

  public static function create(ContainerInterface $container) {

    return new self(
      $container->get('entity_type.manager')
    );
  }


  /**
   * @param \Drupal\Core\Entity\EntityInterface $value
   * @param \Symfony\Component\Validator\Constraint $constraint
   */
  public function validate($value, Constraint $constraint) {

    $values = [];
    foreach ($value->get('formule_values')->getValue() as $formule_value) {
      $values[$formule_value['formule_field_target']] = $formule_value['value'];
    }

    $query = $this->formulePackageStorage->getBaseQuery($values, $value->bundle());
    $query->condition('e.id', $value->id(), '<>');

    $ids = array_keys($query->execute()->fetchAllKeyed());
    if (count($ids)) {
      $this->context->addViolation($constraint->alreadyExists, ['%entity' => $value->bundle()]);
    }

  }

}
