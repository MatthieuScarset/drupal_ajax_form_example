<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\oab_modular_product\Services\OabModularProductService;
use Drupal\paragraphs\Entity\Paragraph;
use Drupal\paragraphs\Entity\ParagraphsType;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class ModularProductOrderModuleValidator extends ConstraintValidator implements ContainerInjectionInterface {

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

    //liste de modules optionnels de la page produit dans le bon ordre
    $default_order_modules = $this->modularProductService->getModulesOrder();
    //liste de modules marqués seconde position possible
    $modules_second_position = $this->modularProductService->getModulesOptionalSecondaryPosition();
    //liste de modules obligatoires
    $modules_required = $this->modularProductService->getModulesRequired();

    //On récupère les modules du contenu en excluant les modules supplémentaires
    $paragraphs = [];
    foreach ($items as $item) {
      if (isset($item->entity)) {
        if (!in_array($item->entity->bundle(), OabModularProductService::MODULES_OPTIONNELS)) {
          $paragraphs[] = $item->entity->bundle();
        }
      }
    }

    //on va regarder, pour chaque module permettant une seconde position, combien il y a d'occurences sur ce contenu
    $seconde_position_restantes = [];
    $occurences_modules = array_count_values(array_values($paragraphs));
    foreach ($modules_second_position as $module) {
      $seconde_position_restantes[$module] = ($occurences_modules[$module]) ?? 0;
    }

    // on prend le 1er module attendu selon la conf
    $current_waited_module = array_shift($default_order_modules);
    // init
    $everything_is_ok = TRUE;
    $i = 0;

    // on parcourt les modules du contenu, tant que tout va bien
    while (isset($paragraphs[$i]) && $everything_is_ok) {
      // est-ce qu'on attendait un module ?
      if (!empty($current_waited_module) && $current_waited_module !== FALSE) {
        // Oui, on va regarder son cas :
        if ($current_waited_module === $paragraphs[$i]) {
          // c'est bien le module attendu, donc on avance au module d'après et l'attendu suivant
          $i++;
          $current_waited_module = array_shift($default_order_modules);
        }
        elseif (in_array($paragraphs[$i], $modules_second_position)) {
          // c'est pas le module qu'on attendait, mais c'est un module qui peut avoir une seconde position
          if (!empty($seconde_position_restantes[$paragraphs[$i]])
            && $seconde_position_restantes[$paragraphs[$i]] > 1) {
            // il lui reste + d'1 occurence donc il a le droit d'être où il veut, on passe au paragraphe de contenu suivant
            // et on décrémente le nombre d'occurences restantes vu qu'on vient de le passer
            $i++;
            $seconde_position_restantes[$paragraphs[$i]]--;
          }
          else {
            // il ne lui reste qu'une seule occurence donc il devrait être au bon endroit => soucis
            $everything_is_ok = FALSE;
          }
        }
        else {
          // c'est pas le module qu'on attendait ET ce n'est PAS un module qui peut avoir une seconde position
          // on passe à l'attendu suivant et on garde notre position dans le contenu pour voir si c'est la suite
            $current_waited_module = array_shift($default_order_modules);
        }
      } else {
        // on n'attendait pas de modules donc ça ne peut être que des modules 2nd position
        if (in_array($paragraphs[$i], $modules_second_position)
        && !empty($seconde_position_restantes[$paragraphs[$i]])
          && $seconde_position_restantes[$paragraphs[$i]] > 1) {
          // mais c'est un module en position secondaire auquel il reste des occurences donc c'est ok
          $i++;
          $seconde_position_restantes[$paragraphs[$i]]--;
        }
        else {
          // ce n'est pas un module en position secondaire et on n'attendait plus de module => il n'a rien à faire là, c'est une erreur
          $everything_is_ok = FALSE;
        }
      }
    }

    // on n'a pas passé tous les élément ou il y a un soucis => erreur
    if ($i !== count($paragraphs) || !$everything_is_ok) {
      $error_message = "";
      foreach ($this->modularProductService->getModulesOrder() as $module_id) {
        $paragraph_type = ParagraphsType::load($module_id);
        $error_message .= $paragraph_type->label . " //  ";
      }
      $this->context->addViolation($constraint->badOrder, [
        "%value" => substr($error_message, 0, -5)
      ]);
    }
  }
}
