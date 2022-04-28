<?php

/**
 * @file
 * Contains formule_package.page.inc.
 *
 * Page callback for Formule package entities.
 */

use Drupal\Core\Render\Element;

/**
 * Prepares variables for Formule package templates.
 *
 * Default template: formule_package.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_formule_package(array &$variables) {
  // Fetch FormulePackage Entity Object.
  $formule_package = $variables['elements']['#formule_package'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}
