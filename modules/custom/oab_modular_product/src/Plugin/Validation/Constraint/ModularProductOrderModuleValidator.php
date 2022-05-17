<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\paragraphs\Entity\Paragraph;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

class ModularProductOrderModuleValidator extends ConstraintValidator {

  /**
   * @param \Drupal\Core\Field\FieldItemList $items
   * @param \Symfony\Component\Validator\Constraint $constraint
   *
   * @return void
   */
  public function validate($items, Constraint $constraint) {

//liste de modules optionnels de la page produit dans le bon ordre
    $default_order = [
      "module_services",
      "module_customer_space",
      "module_steps",
      "module_exemples",
      "module_benefits",
      "module_partner",
      "module_partner",
      "module_testimonial"
    ];

//Liste des modules supplémentaires optionnels dont on ne tiendra pas compte
    $not_in_order = [
      "module_3_4_colonnes",
      "module_text_video_image",
      "paragraph_wysiwyg",
    ];


//On récupère les modules ajoutés en BO en excluant les modules supplémentaires
    $paragraph_order = [];
    foreach ($items as $item) {
      if (isset($item->entity)) {
        if (!in_array($item->entity->bundle(), $not_in_order)) {
          $paragraph_order[] = $item->entity->bundle();
        }
      }
    }

//On boucle sur nos tableaux pour les comparés
    $i_current = 0;
    while (count($default_order) && count($paragraph_order)
            && isset($paragraph_order[$i_current])) {
//On dépile le tableau de départ
      $current_order = array_shift($default_order);

//On passe à un autre élément que s'il y a égalité entre les premiers éléments
  //en incrémentant notre compteur
      if ($current_order === $paragraph_order[$i_current]) {
        $i_current++;
      }
    }

//Nos deux tableaux sont égaux que s'il y a égalité entre le compteur et le
  //nombre d'éléments dans le tableau récupérer en BO
    if ($i_current !== count($paragraph_order)) {
      $this->context->addViolation($constraint->badOrder);
    }
  }
}
