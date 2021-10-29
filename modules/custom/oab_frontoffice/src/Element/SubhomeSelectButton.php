<?php


namespace Drupal\oab_frontoffice\Element;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element\Checkboxes;
use Drupal\Core\Render\Element\FormElement;
use Drupal\Core\Render\Element\FormElementInterface;


/**
 *
 * @FormElement("subhome_select_button")
 */
class SubhomeSelectButton extends Checkboxes implements FormElementInterface {

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
      '#process' => [
        [$class, 'processSubhomeSelectButton'],
      ],
      '#pre_render' => [
        [$class, 'preRenderCompositeFormElement'],
      ],
      '#theme_wrappers' => ['subhome_select_button'],
    ];
  }

  /**
   * Processes a checkboxes form element.
   */
  public static function processSubhomeSelectButton(&$element, FormStateInterface $form_state, &$complete_form) {
    $value = is_array($element['#value']) ? $element['#value'] : [];
    $element['#tree'] = TRUE;
    if (count($element['#options']) > 0) {
      if (!isset($element['#default_value']) || $element['#default_value'] == 0) {
        $element['#default_value'] = [];
      }
      $weight = 0;
      foreach ($element['#options'] as $key => $choice) {
        // Integer 0 is not a valid #return_value, so use '0' instead.
        // @see \Drupal\Core\Render\Element\Checkbox::valueCallback().
        // @todo For Drupal 8, cast all integer keys to strings for consistency
        //   with \Drupal\Core\Render\Element\Radios::processRadios().
        if ($key === 0) {
          $key = '0';
        }
        // Maintain order of options as defined in #options, in case the element
        // defines custom option sub-elements, but does not define all option
        // sub-elements.
        $weight += 0.001;

        $element += [$key => []];
        $element[$key] += [
          '#type' => 'subhome_select',
          '#title' => $choice,
          '#return_value' => $key,
          '#default_value' => isset($value[$key]) ? $key : NULL,
          '#attributes' => $element['#attributes'],
          '#ajax' => isset($element['#ajax']) ? $element['#ajax'] : NULL,
          // Errors should only be shown on the parent checkboxes element.
          '#error_no_message' => TRUE,
          '#weight' => $weight,
        ];
      }
    }
    return $element;
  }
}
