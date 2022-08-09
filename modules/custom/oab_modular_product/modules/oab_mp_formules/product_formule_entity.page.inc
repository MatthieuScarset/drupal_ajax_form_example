<?php

/**
 * @file
 * Contains product_formule_entity.page.inc.
 *
 * Page callback for Product formule entity entities.
 */

use Drupal\Core\Render\Element;

/**
 * Prepares variables for Product formule entity templates.
 *
 * Default template: product_formule_entity.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_product_formule_entity(array &$variables) {
  // Fetch ProductFormuleEntity Entity Object.
  $product_formule_entity = $variables['elements']['#product_formule_entity'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}
