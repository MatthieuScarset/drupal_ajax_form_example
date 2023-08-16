<?php

namespace Drupal\oab_modular_product\Plugin\Validation\Constraint;

use Drupal\paragraphs\Entity\Paragraph;
use Symfony\Component\Validator\Constraint;
use Symfony\Component\Validator\ConstraintValidator;

/**
 * Validates the UniqueInteger constraint.
 */
class ModularProductDetailOffreCheckCTAValidator extends ConstraintValidator
{

  /**
   * {@inheritdoc}
   * @var \Drupal\entity_reference_revisions\EntityReferenceRevisionsFieldItemList $entity
   */
  public function validate($items, Constraint $constraint)
  {
    foreach ($items as $item) {
      if (isset($item->entity)) {
        /** @var \Drupal\paragraphs\Entity\Paragraph $entity */
        $entity = $item->entity;
        if (!empty($entity->field_call_to_action_buton->title) && !empty($entity->field_items)) {
          //LE CTA globale est rempli au niveau du module détail Ofrre => on doit vérifier les enfants
          //tant qu'il y a des enfants et qu'il n'y a pas d'erreur
          foreach ($entity->field_items as $field_item) {
            $offre_item = $field_item->subform;
            //field_cta n'est jamais vide et contient par défaut (sans ajouter un CTA) une valeur d'ou le count > 1
            if ((isset($offre_item['field_cta']) && count($offre_item['field_cta']) > 1)
              || (!isset($offre_item['field_cta']) && $field_item->entity->field_cta->count() > 0)) {
              // il y a un CTA sur l'item => on renvoie une erreur
              $this->context->addViolation($constraint->error);
            }
          }
        }
      }
    }
  }
}
