<?php

namespace Drupal\oab_subhomes\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Messenger\MessengerInterface;

/**
 * Class SubhomeEntityTypeForm.
 */
class SubhomeEntityTypeForm extends EntityForm {


  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    $subhome_entity_type = $this->entity;
    $form['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Label'),
      '#maxlength' => 255,
      '#default_value' => $subhome_entity_type->label(),
      '#description' => $this->t("Label for the Subhome entity type."),
      '#required' => TRUE,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $subhome_entity_type->id(),
      '#machine_name' => [
        'exists' => '\Drupal\oab_subhomes\Entity\SubhomeEntityType::load',
      ],
      '#disabled' => !$subhome_entity_type->isNew(),
    ];

    /* You will need additional form elements for your custom properties. */

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $subhome_entity_type = $this->entity;
    $status = $subhome_entity_type->save();

    switch ($status) {
      case SAVED_NEW:
        $this->messenger->addMessage($this->t('Created the %label Subhome entity type.', [
          '%label' => $subhome_entity_type->label(),
        ]));
        break;

      default:
        $this->messenger->addMessage($this->t('Saved the %label Subhome entity type.', [
          '%label' => $subhome_entity_type->label(),
        ]));
    }
    $form_state->setRedirectUrl($subhome_entity_type->toUrl('collection'));
  }

}
