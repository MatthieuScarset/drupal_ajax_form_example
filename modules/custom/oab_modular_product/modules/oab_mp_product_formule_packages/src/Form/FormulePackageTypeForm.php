<?php

namespace Drupal\oab_mp_product_formule_packages\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\language\Entity\ContentLanguageSettings;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackageType;

/**
 * Class FormulePackageTypeForm.
 */
class FormulePackageTypeForm extends EntityForm {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    /** @var FormulePackageType $formule_package_type */
    $formule_package_type = $this->entity;
    $form['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Label'),
      '#maxlength' => 255,
      '#default_value' => $formule_package_type->label(),
      '#description' => $this->t("Label for the Formule package type."),
      '#required' => TRUE,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $formule_package_type->id(),
      '#machine_name' => [
        'exists' => '\Drupal\oab_mp_product_formule_packages\Entity\FormulePackageType::load',
      ],
      '#disabled' => !$formule_package_type->isNew(),
    ];


    $form['formule'] = [
      '#type' => "entity_autocomplete",
      '#target_type' => 'product_formule_entity',
      '#autocreate' => false,
      '#title' => $this->t("Formule"),
      '#description' => $this->t("Choose the Formule entity with the correct field package"),
      '#required' => true,
      '#default_value' => $formule_package_type->getFormule(),
      '#attributes' => ['disabled' => !$formule_package_type->isNew()]
    ];


    $form['additional_settings'] = [
      '#type' => 'vertical_tabs',
      '#attached' => [
        'library' => ['node/drupal.content_types'],
      ],
    ];

    if ($this->moduleHandler->moduleExists('language')) {
      $form['language'] = [
        '#type' => 'details',
        '#title' => $this->t('Language settings'),
        '#group' => 'additional_settings',
      ];

      $language_configuration = ContentLanguageSettings::loadByEntityTypeBundle('formule_package_type', $formule_package_type->bundle());
      $form['language']['language_configuration'] = [
        '#type' => 'language_configuration',
        '#entity_information' => [
          'entity_type' => 'formule_package_type',
          'bundle' => $formule_package_type->bundle(),
        ],
        '#default_value' => $language_configuration,
      ];
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    /** @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageTypeInterface $formule_package_type */
    $formule_package_type = $this->entity;

    $status = $formule_package_type->save();

    switch ($status) {
      case SAVED_NEW:
        $this->messenger()->addMessage($this->t('Created the %label Formule package type.', [
          '%label' => $formule_package_type->label(),
        ]));
        break;

      default:
        $this->messenger()->addMessage($this->t('Saved the %label Formule package type.', [
          '%label' => $formule_package_type->label(),
        ]));
    }
    $form_state->setRedirectUrl($formule_package_type->toUrl('collection'));
  }

}
