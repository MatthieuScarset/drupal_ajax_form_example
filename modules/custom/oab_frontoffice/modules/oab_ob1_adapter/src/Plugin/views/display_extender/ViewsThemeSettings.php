<?php

namespace Drupal\oab_ob1_adapter\Plugin\views\display_extender;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\display_extender\DisplayExtenderPluginBase;

/**
 * views theme selection
 *
 * @ingroup views_display_extender_plugins
 *
 * @ViewsDisplayExtender(
 *   id = "theme_settings",
 *   title = @Translation("Theme settings for Views"),
 *   help = @Translation("Use the ob1 configuration"),
 *   no_ui = FALSE
 * )
 */
class ViewsThemeSettings extends DisplayExtenderPluginBase {

  /**
   * Provide the key options for this plugin.
   */
  public function defineOptionsAlter(&$options) {
    $options['theme'] = [
      'contains' => [
        'ob1' => ['default' => 0],
      ]
    ];
  }

  /**
   * Provide the default summary for options and category in the views UI.
   */
  public function optionsSummary(&$categories, &$options) {
    $categories['theme_settings'] = [
      'title' => t('Theme Settings'),
      'column' => 'second',
    ];
    $theme_applied = $this->hasThemeSettings() ? $this->getThemeValues() : FALSE;
    $options['theme'] = [
      'category' => 'theme_settings',
      'title' => t('Theme'),
      'value' => $theme_applied ? t('Ob1') : t('Boosted is by default'),
    ];
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {

    if ($form_state->get('section') == 'theme') {
      $form['#title'] .= t('Change theme for this display');
      $theme_applied = $this->getThemeValues();

      $form['theme'] = [
        '#type' => 'container',
        '#tree' => True,
      ];

      $form['theme']['ob1'] = [
        '#type' => 'checkbox',
        '#title' => t('ob1'),
        '#description' => t('Use ob1 theme for this display'),
        '#default_value' => $theme_applied['ob1'],
      ];
    }
  }

  /**
   * Handle any special handling on the validate form.
   */
  public function submitOptionsForm(&$form, FormStateInterface $form_state) {
    if ($form_state->get('section') == 'theme') {
      $theme_applied = $form_state->getValue('theme');

      $this->options['theme'] = $theme_applied;
    }
  }

  /**
   * Identify whether or not the current display has custom theme settings defined.
   */
  public function hasThemeSettings(): bool {
    $theme_settings = $this->getThemeValues();
    return !empty($theme_settings['ob1']);
  }

  /**
   * Get the Theme Settings configuration for this display.
   *
   * @return array
   *   The Theme Settings values.
   */
  public function getThemeValues() {
    return $this->options['theme'];
  }
}
