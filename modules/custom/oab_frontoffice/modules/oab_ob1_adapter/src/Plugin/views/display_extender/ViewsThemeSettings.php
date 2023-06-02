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
    $options['ob1_settings'] = [
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
    $theme_settings = $this->hasThemeSettings() ? $this->getOb1SettingsValues() : FALSE;
    $options['ob1_settings'] = [
      'category' => 'theme_settings',
      'title' => t('Ob1 Theme Settings'),
      'value' => $theme_settings ? t('use ob1') : t('no settings'),
    ];
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {

    if ($form_state->get('section') == 'ob1_settings') {
      $form['#title'] .= t('The Ob1 theme settings for this display');
      $theme_settings = $this->getOb1SettingsValues();

      $form['ob1_settings'] = [
        '#type' => 'container',
        '#tree' => True,
      ];
      $form['ob1_settings']['ob1'] = [
        '#type' => 'checkbox',
        '#title' => t('ob1'),
        '#description' => t('this content type use ob1 theme'),
        '#default_value' => $theme_settings['ob1'],
      ];
    }
  }

  /**
   * Handle any special handling on the validate form.
   */
  public function submitOptionsForm(&$form, FormStateInterface $form_state) {
    if ($form_state->get('section') == 'ob1_settings') {
      $theme_settings = $form_state->getValue('ob1_settings');

      $this->options['ob1_settings'] = $theme_settings;
    }
  }

  /**
   * Identify whether or not the current display has custom theme settings defined.
   */
  public function hasThemeSettings(): bool {
    $theme_settings = $this->getOb1SettingsValues();
    return !empty($theme_settings['ob1']);
  }

  /**
   * Get the Theme Settings configuration for this display.
   *
   * @return array
   *   The Theme Settings values.
   */
  public function getOb1SettingsValues() {
    return $this->options['ob1_settings'];
  }
}
