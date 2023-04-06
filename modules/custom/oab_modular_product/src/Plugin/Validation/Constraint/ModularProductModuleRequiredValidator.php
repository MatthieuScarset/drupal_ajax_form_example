<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\oab_modular_product\Services\OabModularProductService;
use Drupal\paragraphs\Entity\ParagraphsType;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class ModularProductModuleRequiredValidator extends ConstraintValidator implements ContainerInjectionInterface {

  use StringTranslationTrait;

  public function __construct(
    private OabModularProductService $oabModularProductService,
    private MessengerInterface $messenger
  ) {
  }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('oab_modular_product.settings'),
      $container->get('messenger')
    );
  }

  /**
   * @param \Drupal\Core\Field\FieldItemList $items
   * @param \Symfony\Component\Validator\Constraint $constraint
   *
   * @return void
   */
  public function validate($items, Constraint $constraint) {
    $entity = $items->getEntity();
    if (!isset($entity)) {
      return;
    }
    $is_published = $entity->isPublished();

    //On récupère les modules ajoutés en BO
    $list_module = [];
    foreach ($items as $item) {
      if (isset($item->entity)) {
        $list_module[] = $item->entity->bundle();
      }
    }

    $count_errors = 0;
    $error_message = "";

    foreach ($this->oabModularProductService->getModulesRequired() as $module_required) {
      if (!in_array($module_required, $list_module)) {
        $count_errors++;
        $paragraph_type = ParagraphsType::load($module_required);
        $error_message .= $paragraph_type->label . ", ";
      }
    }

    if ($count_errors > 0) {
      $constraint_message = ($count_errors > 1) ? $constraint->requiredMulti : $constraint->required;
      $message = $this->t($constraint_message, ['%value' => substr($error_message, 0, -2)]);
      if ($is_published) {
        $this->context->addViolation($message);
      }
      else {
        $this->messenger->addWarning($message);
      }
    }
  }
}
