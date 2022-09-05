<?php

namespace Drupal\oab_custom_assets\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_custom_assets\Entity\CustomAssetInterface;

/**
 * Class CustomAssetForm.
 */
class CustomAssetForm extends EntityForm {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    /** @var CustomAssetInterface $custom_asset */
    $custom_asset = $this->entity;


    $form['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Label'),
      '#maxlength' => 255,
      '#default_value' => $custom_asset->label(),
      '#description' => $this->t("Label for the Custom asset."),
      '#required' => TRUE,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $custom_asset->id(),
      '#machine_name' => [
        'exists' => '\Drupal\oab_custom_assets\Entity\CustomAsset::load',
      ],
      '#disabled' => !$custom_asset->isNew(),
    ];

    $form['paths'] = [
      '#type' => 'textarea',
      '#default_value' => $custom_asset->getPaths(),
      '#title' => $this->t("Paths"),
      '#description' => $this->t("Enter one path per line. You can use wildcard")
    ];

    $form['assets'] = [
      '#type' => 'fieldset',
      '#title' => 'Assets'
    ];

    $form['assets']['css'] = [
      '#type' => 'textarea',
      '#default_value' => $custom_asset->getCSS(),
      '#title' => $this->t("CSS"),
      '#description' => $this->t("Paste here your custom CSS")
    ];

    $form['assets']['js'] = [
      '#type' => 'textarea',
      '#default_value' => $custom_asset->getJs(),
      '#title' => $this->t("JavaScript"),
      '#description' => $this->t("Paste here your custom JS")
    ];

    $form['assets']['bottom_js'] = [
      '#type' => 'textarea',
      '#default_value' => $custom_asset->getBottomJs(),
      '#title' => $this->t("Bottom JavaScript"),
      '#description' => $this->t("Paste here your custom JS that need to be at the bottom of the HTML")
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $custom_asset = $this->entity;
    $status = $custom_asset->save();

    switch ($status) {
      case SAVED_NEW:
        $this->messenger()->addMessage($this->t('Created the %label Custom asset.', [
          '%label' => $custom_asset->label(),
        ]));
        break;

      default:
        $this->messenger()->addMessage($this->t('Saved the %label Custom asset.', [
          '%label' => $custom_asset->label(),
        ]));
    }
    $form_state->setRedirectUrl($custom_asset->toUrl('collection'));
  }

}
