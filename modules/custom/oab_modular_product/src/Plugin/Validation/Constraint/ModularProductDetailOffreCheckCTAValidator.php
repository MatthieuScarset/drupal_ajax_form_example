<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\paragraphs\Entity\Paragraph;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the UniqueInteger constraint.
 */
class ModularProductDetailOffreCheckCTAValidator extends ConstraintValidator {

  /**
   * {@inheritdoc}
   * @var \Drupal\entity_reference_revisions\EntityReferenceRevisionsFieldItemList $entity
   */
  public function validate($items, Constraint $constraint) {
    foreach ($items as $item) {
      if (isset($item->entity)) {
        /** @var \Drupal\paragraphs\Entity\Paragraph $entity */
        $entity = $item->entity;
        if($item->entity->hasField('field_call_to_action_buton')) {
          $value_cta_detail_offre_global = $item->entity->get('field_call_to_action_buton')->getValue();
          if (!empty($value_cta_detail_offre_global[0]["title"])) {
            //LE CTA globale est rempli au niveau du module détail Ofrre => on doit vérifier les enfants

            if (!empty($entity->field_items)) {
              $bool_error = FALSE;
              $i = 0;
              //tant qu'il y a des enfants et qu'il n'y a pas d'erreur
              foreach ($entity->field_items as $field_items) {
                if (!$bool_error) {
                  $offre_item =  $field_items->subform;

                  if ($offre_item['field_cta'] !== NULL && count($offre_item['field_cta']) > 1) {
                    // il y a un CTA sur l'item => on renvoie une erreur
                    $bool_error = TRUE;
                    $this->context->addViolation($constraint->error);
                  }
                  $i++;
                }
              }
            }
          }
        }

      }
    }
  }
}
