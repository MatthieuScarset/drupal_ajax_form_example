<?php

namespace Drupal\oab_ob1_adapter\Plugin\views\display_extender;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\views\Annotation\ViewsDisplayExtender;
use Drupal\views\Plugin\views\display_extender\DisplayExtenderPluginBase;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * views theme selection
 *
 * @ingroup views_display_extender_plugins
 *
 * @ViewsDisplayExtender(
 *   id = "oab_theme_settings",
 *   title = @Translation("Theme settings for Views"),
 *   help = @Translation("Use the ob1 configuration"),
 *   no_ui = FALSE
 * )
 */
class ViewsThemeSettings extends DisplayExtenderPluginBase {

  /**
   * @var \Drupal\Core\Language\LanguageManagerInterface
   */
  private LanguageManagerInterface $languageManager;


  /**
   * Constructs a PluginBase object.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, LanguageManagerInterface $language_manager) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);

    $this->definition = $plugin_definition + $configuration;
    $this->languageManager = $language_manager;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static($configuration, $plugin_id, $plugin_definition, $container->get('language_manager'));
  }

  /**
   * Provide the default summary for options and category in the views UI.
   */
  public function optionsSummary(&$categories, &$options) {

// On applique le choix du theme que sur les views de type page
    if ($this->displayHandler->pluginId === 'page') {
      $categories['oab_theme_settings'] = [
        'title' => t('Theme Settings'),
        'column' => 'second',
      ];

      $languages_with_ob1 = array_filter($this->options['theme'] ?? [], function($value) {
        return $value === 'ob1';
      });

      $options['theme'] = [
        'category' => 'oab_theme_settings',
        'title' => $this->t("Select theme by language"),
        'value' => count($languages_with_ob1)
          ? $this->t('Languages with Ob1: %langs', ['%langs' => implode(', ', array_keys($languages_with_ob1))])
          : $this->t("No language with Ob1")
      ];
    }
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {

    if ($form_state->get('section') === 'theme') {
      $form['#title'] .= $this->t('Select theme by language for this display');

      $form['theme'] = [
        '#type' => 'container',
        '#tree' => true
      ];

      foreach ($this->languageManager->getLanguages() as $language) {
        $form['theme'][$language->getId()] = [
          '#type' => 'radios',
          '#title' => $language->getName(),
          '#default_value' => $this->options['theme'][$language->getId()] ?? "default",
          '#options' => [
            'default' => $this->t('Default'),
            'ob1' => $this->t('Ob1'),
          ],
        ];
      }
    }
  }

  /**
   * Handle any special handling on the validate form.
   */
  public function submitOptionsForm(&$form, FormStateInterface $form_state) {
    if ($form_state->get('section') == 'theme') {
      $this->options['theme'] = $form_state->getValue('theme') ?? [];
    }
  }

}
