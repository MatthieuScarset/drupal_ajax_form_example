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

    $default_order = [
      "module_services",
      "module_steps",
      "module_exemples",
      "module_benefits",
      "module_partner",
      "module_partner",
      "module_testimonial"
    ];

    $not_in_order = [
      "module_3_4_colonnes",
      "module_text_video_image",
      "paragraph_wysiwyg",
    ];

    $paragraph_order = [];

    foreach ($items as $item) {
      if (isset($item->target_id)) {
        $paragraph = Paragraph::load($item->target_id ?? 0);
        if ($paragraph) {
          if (!in_array($paragraph->bundle(), $not_in_order)) {
            $paragraph_order[] = $paragraph->bundle();
          }
        }
      }
    }

    $i_current = 0;

    while (count($default_order) && count($paragraph_order) && isset($paragraph_order[$i_current])) {
      $current_order = array_shift($default_order);
      if ($current_order === $paragraph_order[$i_current]) {
        $i_current++;
      }
    }
    $ordered = ($i_current === count($paragraph_order));

    if (!$ordered) {
      $this->context->addViolation($constraint->badOrder);
    }
  }
}
