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
      '#description' => t("Configuration if no available package"),
      '#group' => "tabs",
      'empty_configs' => [
        '#type' => 'fieldgroup',
        '#tree' => true,
        '#prefix' => '<div id="group-empty-config">',
        '#suffix' => '</div>',
        'add_more_button' => [
          '#type' => 'submit',
          '#value' => $this->t('Add one more'),
          '#weight' => 100,
          '#submit' => [
            '::addEmptyConfig'
          ],
          '#ajax' => [
            'callback' => '::addEmptyConfigCallback',
            'wrapper' => 'group-empty-config'
          ]
        ]
      ],
    ];

    $third_party_settings = $formule_field->getThirdPartySettings('oab_mp_formule_field');

//    $empty_config_inputs =


    if (is_array($third_party_settings['empty_configs'])) {

      $empty_configs = array_merge(
        $form_state->getValue('empty_configs') ?? [],
        $third_party_settings['empty_configs']
      );
      if (isset($empty_configs['add_more_button'])) {
        unset($empty_configs['add_more_button']);
      }

      foreach ($empty_configs as $config_id => $empty_config) {

        $form['group_empty_config']['empty_configs'][$config_id] = $this->generateEmptyConfig(
          $empty_config + ['name' => $config_id === "default" ? "Default" : "Config $config_id"],
          $formule_field->getChoices()
        );

      }

      if ($form_state->has('need_empty_config')) {
        $index_new_item = count($empty_configs);

        // Pour être sur que l'index n'existe pas déjà
        while (isset($empty_configs["config_$index_new_item"])) {
          $index_new_item++;
        }

        $form['group_empty_config']['empty_configs']["config_$index_new_item"]
          = $this->generateEmptyConfig(
            ['name' => "Config $index_new_item"],
            $formule_field->getChoices()
        );
      }

    } else {
      $form['group_empty_config']['empty_configs']['default'] = $this->generateEmptyConfig(['name' => "Default"], $formule_field->getChoices());
    }


    return $form;
  }

  /**
   * Callback for both ajax-enabled buttons.
   *
   * Selects and returns the fieldset with the names in it.
   */
  public function addEmptyConfigCallback(array &$form, FormStateInterface $form_state) {
    return $form['group_empty_config']['empty_configs'];
  }

  public function addEmptyConfig(array &$form, FormStateInterface $form_state) {
    $form_state->set('need_empty_config', true);
    $form_state
      ->setRebuild();
  }


  private function generateEmptyConfig(array $values, array $choices): array {

    $detail = [
      '#type' => "details",
      "#title" => $values['name']
    ];

    $detail['name'] = [
      '#type' => 'hidden',
      '#value' => $values['name']
    ];

    $detail['no_result_title'] = [
      '#type' => 'textarea',
      '#title' => $this->t("No result title"),
      '#description' => $this->t("Title of the no-result page. Use %answer to print the user answer. "
        . "Use [formule-field:color:orange] and [formule-field:color:normal] pour mettre le texte en orange",
        [
          '%answer' => "{answer}"
        ]),
      '#default_value' => $values['no_result_title'] ?? ""
    ];

    $detail['no_result_sentence'] = [
      '#type' => 'textarea',
      '#title' => $this->t("No result sentence"),
      '#description' => $this->t("Display just under the title on no-result page"),
      '#default_value' => $values['no_result_sentence'] ?? ""
    ];

    $detail['button_text'] = [
      '#type' => 'textfield',
      '#title' => $this->t("Button text"),
      '#default_value' => $values['button_text'] ?? ""
    ];

    $detail['button_link'] = [
      '#type' => 'url',
      '#title' => $this->t("Button link"),
      '#default_value' => $values['button_link'] ?? ""
    ];

    if ($values['name'] !== 'Default') {
      $detail['inputs'] = [
        '#type' => 'checkboxes',
        '#title' => "Inputs",
        '#description' => "Select inputs that emtpy config applies to",
        '#options' => $choices,
        '#default_value' => $values['inputs']
      ];
    }


    return $detail;
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

    $empty_configs = $form_state->getValue('empty_configs');
    foreach ($empty_configs as $key => $empty_config) {
      if (empty($empty_config['no_result_title']) && empty($empty_config['no_result_sentence'])) {
        unset($empty_configs[$key]);
      } elseif (isset($empty_config['inputs'])) {

        $empty_configs[$key]['inputs'] = array_filter($empty_config['inputs']);
      }
    }

    // La flemme de créer les fields dans la conf....
    $formule_field->setThirdPartySetting('oab_mp_formule_field', 'empty_configs', $empty_configs);

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


  private function getChoicesAsArray(string|array $input): array {
    if (is_array($input)) {
      return $input;
    }

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
