<?php


namespace Drupal\oab_frontoffice\Element;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element;
use Drupal\Core\Render\Element\Checkbox;
use Drupal\Core\Render\Element\FormElement;
use Drupal\Core\Render\Element\FormElementInterface;


/**
 *
 * @FormElement("subhome_select")
 */
class SubhomeSelect extends Checkbox implements FormElementInterface {

  /**
   * Returns the element properties for this element.
   *
   * @return array
   *   An array of element properties. See
   *   \Drupal\Core\Render\ElementInfoManagerInterface::getInfo() for
   *   documentation of the standard properties of all elements, and the
   *   return value format.
   */
  public function getInfo() {
    // TODO: Implement getInfo() method.

    $class = get_class($this);
    return [
      '#input' => TRUE,
      '#return_value' => 1,
      '#process' => [
        [$class, 'processSubhomeSelect'],
        [$class, 'processAjaxForm'],
        [$class, 'processGroup'],
      ],
      '#pre_render' => [
        [$class, 'preRenderSubhomeSelect'],
        [$class, 'preRenderGroup'],
      ],
      '#theme' => 'subhome_select',
      '#theme_wrappers' => ['form_element'],
    ];
  }

  public static function preRenderSubhomeSelect($element) {
    $element['#attributes']['type'] = 'checkbox';
//    $element['#name'] = $element['#parents'][0] . '[]';
    Element::setAttributes($element, ['id', 'name', '#return_value' => 'value']);
    // Unchecked checkbox has #value of integer 0.
    if (!empty($element['#checked'])) {
      $element['#attributes']['checked'] = 'checked';
    }
    
    static::setAttributes($element, ['form-subhome-select']);

    return $element;
  }

  /**
   * Sets the #checked property of a checkbox element.
   */
  public static function processSubhomeSelect(&$element, FormStateInterface $form_state, &$complete_form) {
    return parent::processCheckbox($element, $form_state, $complete_form);
  }
}
