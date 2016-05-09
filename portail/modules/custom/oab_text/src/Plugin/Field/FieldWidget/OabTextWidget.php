<?php

namespace Drupal\oab_text\Plugin\Field\FieldWidget;

use Drupal\Core\Form\FormStateInterface;
use Drupal\text\Plugin\Field\FieldWidget\TextareaWidget;
use Symfony\Component\Validator\ConstraintViolationInterface;
use Drupal\Core\Field\FieldItemListInterface;

/**
 * Plugin implementation of the 'text_textfield' widget.
 *
 * @FieldWidget(
 *   id = "oab_text_textfield",
 *   label = @Translation("Oab Text field"),
 *   field_types = {
 *     "oab_text"
 *   },
 * )
 */
class OabTextWidget extends TextareaWidget {

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return array(
      'rows' => '9',
      'placeholder' => '',
    ) + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $element = parent::settingsForm($form, $form_state);

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    $element = parent::formElement($items, $delta, $element, $form, $form_state);

    $element['zone'] = array(
      '#type' => 'select',
      '#title' => t('Zone'),
      '#default_value' => $items[$delta]->zone,
      '#options' => ['top', 'left', 'right', 'bottom'],
      '#weight' => 10,
    );

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function errorElement(array $element, ConstraintViolationInterface $violation, array $form, FormStateInterface $form_state) {
    $element = parent::errorElement($element, $violation, $form, $form_state);
    if ($element === FALSE) {
      return FALSE;
    }
    elseif (isset($violation->arrayPropertyPath[0])) {
      return $element[$violation->arrayPropertyPath[0]];
    }
    else {
      return $element;
    }
  }

}
