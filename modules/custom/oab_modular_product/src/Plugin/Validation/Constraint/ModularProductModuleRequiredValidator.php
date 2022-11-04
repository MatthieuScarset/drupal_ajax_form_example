<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\oab_modular_product\Services\OabModularProductService;
use Drupal\paragraphs\Entity\ParagraphsType;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class ModularProductModuleRequiredValidator extends ConstraintValidator implements ContainerInjectionInterface {

  public function __construct(
    private OabModularProductService $modularProductService
  ) {
  }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('oab_modular_product.settings')
    );
  }

  /**
   * @param \Drupal\Core\Field\FieldItemList $items
   * @param \Symfony\Component\Validator\Constraint $constraint
   *
   * @return void
   */
  public function validate($items, Constraint $constraint) {
    //On récupère les modules ajoutés en BO
    $list_module = [];
    foreach ($items as $item) {
      if (isset($item->entity)) {
        $list_module[] = $item->entity->bundle();
      }
    }

    $count_errors = 0;
    $error_message = "";

    foreach ($this->modularProductService->getModulesRequired() as $module_required) {
      if (!in_array($module_required, $list_module)) {
        $count_errors++;
        $paragraph_type = ParagraphsType::load($module_required);
        $error_message .= $paragraph_type->label . ", ";
      }
    }
    if ($count_errors > 1) {
      $this->context->addViolation($constraint->required_multi, [
        "%value" => substr($error_message, 0, -2)
      ]);
    }
    elseif ( $count_errors > 0) {
      $this->context->addViolation($constraint->required, [
        "%value" => substr($error_message, 0, -2)
      ]);
    }
  }
}
