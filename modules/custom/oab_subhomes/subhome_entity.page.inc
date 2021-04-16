<?php

/**
 * @file
 * Contains subhome_entity.page.inc.
 *
 * Page callback for Subhome entity entities.
 */

use Drupal\Core\Render\Element;

/**
 * Prepares variables for Subhome entity templates.
 *
 * Default template: subhome_entity.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_subhome_entity(array &$variables) {
  // Fetch SubhomeEntity Entity Object.
  $subhome_entity = $variables['elements']['#subhome_entity'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}
