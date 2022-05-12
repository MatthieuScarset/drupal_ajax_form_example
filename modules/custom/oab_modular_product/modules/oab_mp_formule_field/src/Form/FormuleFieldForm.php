<?php

namespace Drupal\oab_mp_formule_field\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Class FormuleFieldForm.
 */
class FormuleFieldForm extends EntityForm {

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    $form['tabs'] = [
      '#type' => 'vertical_tabs',
      '#tree' => true
    ];


    $form['group_field_config'] = [
      '#type' => 'details',
      '#title' => t('Field configuration'),
      '#group' => "tabs"
    ];

    /** @var \Drupal\oab_mp_formule_field\Entity\FormuleField $formule_field */
    $formule_field = $this->entity;
    $form['group_field_config']['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Setting Label'),
      '#maxlength' => 255,
      '#default_value' => $formule_field->label(),
      '#description' => $this->t("Label for the Formule field. Display only in admin configs"),
      '#required' => TRUE,
    ];

    $form['group_field_config']['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $formule_field->id(),
      '#machine_name' => [
        'exists' => '\Drupal\oab_mp_formule_field\Entity\FormuleField::load',
      ],
      '#disabled' => !$formule_field->isNew(),
    ];
    $form['group_field_config']['display_label'] = [
      '#type' => 'textarea',
      '#title' => $this->t('Display Label'),
      '#default_value' => $formule_field->getDisplayLabel(),
      '#description' => $this->t("Label displayed in the configurateur"),
      '#required' => TRUE,
    ];

    $form['group_field_config']['description'] = [
      '#type' => 'textarea',
      '#default_value' => $formule_field->getDescription(),
      '#title' => $this->t('Description'),
      '#description' => $this->t('Displayed on a formule configurateur'),
      '#required' => true,
    ];

    $form['group_field_config']['display_mode'] = [
      '#type' => 'radios',
      '#default_value' => $formule_field->getDisplayMode(),
      '#title' => $this->t('Display mode'),
      '#options' => [
        'chips' => t("Chips"),
        'list' => t("List")
      ],
      '#required' => true
    ];

    $form['group_inputs'] = [
      '#type' => 'details',
      '#title' => t('Inputs'),
      '#group' => "tabs"
    ];

    $choices = "";
    foreach ($formule_field->getChoices() as $key => $value) {
      $choices .= "$key|$value\n";
    }

    $form['group_inputs']['choices'] = [
      '#type' => 'textarea',
      '#default_value' => $choices,
      '#title' => $this->t('Choices'),
      '#description' => $this->t('The possible values this field can contain. Enter one value per line, in the format key|label.'),
      '#required' => true,
    ];

    $form['group_inputs']['null_value'] = [
      '#type' => 'checkbox',
      '#default_value' => $formule_field->hasNullValue(),
      '#title' => $this->t('Has null value'),
      '#description' => $this->t('If you want to add a null value'),
    ];

    $form['group_inputs']['null_label'] = [
      '#type' => 'textfield',
      '#default_value' => $formule_field->getNullLabel(),
      '#title' => $this->t('Null value label'),
      '#description' => $this->t('The null value label'),
      '#states' => [
        'visible' => [
          ':input[name=null_value]' => ['checked' => true]
        ],
        'required' => [
          ':input[name=null_value]' => ['checked' => true]
        ]
      ],
      '#required' => $formule_field->hasNullValue()
    ];

    $form['group_result'] = [
      '#type' => 'details',
      '#title' => t('Result'),
      '#group' => "tabs"
    ];

    $form['group_result']['sentence'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Choice sentence'),
      '#maxlength' => 255,
      '#default_value' => $formule_field->getSentence(),
      '#description' => $this->t("The choice sentence display in the configurateur. Add %answer where you want to print the user answer in the sentence", [
        '%answer' => "{answer}"
      ]),
      '#required' => TRUE,
    ];

    $form['group_empty_config'] = [
      '#type' => 'details',
      '#title' => t('Empty configuration'),
      '#description' => t("Configuration if no package available"),
      '#tree' => true,
      '#group' => "tabs"
    ];

    $third_party_settings = $formule_field->getThirdPartySettings('oab_mp_formule_field');
    $empty_config = $third_party_settings['empty_config'] ?? [];


    $form['group_empty_config']['no_result_title'] = [
      '#type' => 'textarea',
      '#title' => $this->t("No result title"),
      '#description' => $this->t("Title of the no-result page. Use %answer to print the user answer. "
              . "Use [formule-field:color:orange] and [formule-field:color:normal] pour mettre le texte en orange",
        [
          '%answer' => "{answer}"
        ]),
      '#default_value' => $empty_config['no_result_title'] ?? ""
    ];

    $form['group_empty_config']['no_result_sentence'] = [
      '#type' => 'textarea',
      '#title' => $this->t("No result sentence"),
      '#description' => $this->t("Display just under the title on no-result page"),
      '#default_value' => $empty_config['no_result_sentence'] ?? ""
    ];

    $form['group_empty_config']['button_text'] = [
      '#type' => 'textfield',
      '#title' => $this->t("Button text"),
      '#default_value' => $empty_config['button_text'] ?? ""
    ];

    $form['group_empty_config']['button_link'] = [
      '#type' => 'url',
      '#title' => $this->t("Button link"),
      '#default_value' => $empty_config['button_link'] ?? ""
    ];


    return $form;
  }


  public function submitForm(array &$form, FormStateInterface $form_state) {
    $choices_value = $form_state->getValue('choices', "");

    if (is_string($choices_value)) {
      $form_state->setValue('choices', $this->getChoicesAsArray($choices_value));
    }

    parent::submitForm($form, $form_state); // TODO: Change the autogenerated stub
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {

    /** @var \Drupal\oab_mp_formule_field\Entity\FormuleField $formule_field */
    $formule_field = $this->entity;

    // La flemme de créer les fields dans la conf....
    $formule_field->setThirdPartySetting('oab_mp_formule_field', 'empty_config', $form_state->getValue('group_empty_config'));

    $status = $formule_field->save();

    switch ($status) {
      case SAVED_NEW:
        $this->messenger()->addMessage($this->t('Created the %label Formule field.', [
          '%label' => $formule_field->label(),
        ]));
        break;

      default:
        $this->messenger()->addMessage($this->t('Saved the %label Formule field.', [
          '%label' => $formule_field->label(),
        ]));
    }
    $form_state->setRedirectUrl($formule_field->toUrl('collection'));
  }

  function afterBuild(array $element, FormStateInterface $form_state) {
    $choices_value = $form_state->getValue('choices', "");
    $form_state->setValue('choices', $this->getChoicesAsArray($choices_value));

    return parent::afterBuild($element, $form_state); // TODO: Change the autogenerated stub
  }


  private function getChoicesAsArray(string $input): array {
    $choices = [];
    $choice_values = explode(PHP_EOL, $input);
    if ($choice_values != false) {
      foreach (explode("\r\n", $input) as $choice) {
        $choice_part = explode('|', $choice);
        if (strlen($choice) > 0 && $choice_part != false) {
          $choices[$choice_part[0]] = $choice_part[1] ?? $choice_part[0];
        }
      }
    }

    return $choices;
  }

}
