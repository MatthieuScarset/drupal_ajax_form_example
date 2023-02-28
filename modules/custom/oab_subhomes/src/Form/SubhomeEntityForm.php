<?php

namespace Drupal\oab_subhomes\Form;

use Drupal\Component\Datetime\TimeInterface;
use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Entity\EntityRepositoryInterface;
use Drupal\Core\Entity\EntityTypeBundleInfoInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_subhomes\Entity\SubhomeEntity;
use Drupal\taxonomy\Entity\Term;

/**
 * Form controller for Subhome entity edit forms.
 *
 * @ingroup oab_subhomes
 */
class SubhomeEntityForm extends ContentEntityForm {


  /**
    * {@inheritdoc}
    */
    public function buildForm(array $form, FormStateInterface $form_state) {
        /* @var $entity \Drupal\oab_subhomes\Entity\SubhomeEntity */
        $form = parent::buildForm($form, $form_state);

        $entity = $this->entity;

        return $form;
    }


    public function validateForm(array &$form, FormStateInterface $form_state) {

        // A la création d'une entité, je vérifie que la subhome selectionnée n'est pas
        // déjà selectionnée par une autre entité
        // Je vérifie aussi que la langue selectionnée est la même que celle de la subhome selectionnée
        if ($this->entity->isNew()) {
            $sid_value = $form_state->getValue('subhome_id');
            $sid = $sid_value[0]['target_id'];
            if (!SubhomeEntity::isUnique($sid)) {
                $form_state->setErrorByName('subhome_id', $this->t("This subhome term is already defined in another Subhome Entity"));
            }

            $term = Term::load($sid);
            $langcode = $form_state->getValue('langcode');
            if ($term !== null && $term->language()->getId() !== $langcode[0]['value']) {
                $form_state->setErrorByName('langcode', $this->t("The selected language must be the same than the selected subhome"));
            }

        }

        parent::validateForm($form, $form_state);
    }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $entity = $this->entity;

    $status = parent::save($form, $form_state);

    switch ($status) {
      case SAVED_NEW:
          $this->messenger->addMessage(t('Created the %label Subhome entity.', [
              '%label' => $entity->label(),
          ]));
        break;

      default:
        $this->messenger?->addMessage(t('Saved the %label Subhome entity.', [
          '%label' => $entity->label(),
        ]));
    }
    $form_state->setRedirect('entity.subhome_entity.canonical', ['subhome_entity' => $entity->id()]);
  }

}
