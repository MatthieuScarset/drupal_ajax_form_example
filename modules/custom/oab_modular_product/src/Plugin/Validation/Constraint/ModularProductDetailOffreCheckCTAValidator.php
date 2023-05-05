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
        $value_cta_detail_offre_global = $item->entity->get('field_call_to_action_buton')->getValue();
        if (!empty($value_cta_detail_offre_global[0]["title"])) {
          //LE CTA globale est rempli au niveau du module détail Ofrre => on doit vérifier les enfants
          if (!empty($entity->get('field_items'))) {
            $offre_items = $entity->get('field_items')->getValue();
            $bool_error = false;
            $i = 0;
            //tant qu'il y a des enfants et qu'il n'y a pas d'erreur
            while (!$bool_error && $i < count($offre_items)) {
              $offre_item = $offre_items[$i]['entity'];
              if($offre_item->get('field_cta') !== NULL) {
                $cta_offre = $offre_item->get('field_cta')->getValue(); // on récupère la liste des CTA de l'item de l'offre
                if(count($cta_offre) > 0) {
                  // il y a un CTA sur l'item => on renvoie une erreur
                  $bool_error = true;
                  $this->context->addViolation($constraint->error);
                }
              }
              $i++;
            }
          }
        }
      }
    }
  }
}
