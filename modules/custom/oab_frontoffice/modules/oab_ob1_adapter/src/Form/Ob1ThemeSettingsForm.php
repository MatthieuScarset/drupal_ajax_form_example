<?php

namespace Drupal\oab_ob1_adapter\Form;

use Drupal\Core\Config\Config;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Entity\View;
use Symfony\Component\DependencyInjection\ContainerInterface;


class Ob1ThemeSettingsForm extends ConfigFormBase {

  /**
   * @var Config|ImmutableConfig
   */
  private $conf;


  /**
   * @var EntityTypeManager
   */
  private $entityTypeManager;

  /**
   * @var \Drupal\Core\Entity\EntityStorageInterface|mixed|object
   */
  private mixed $taxonomyTermStorage;

  /**
   * Constructs a \Drupal\system\ConfigFormBase object.
   *
   * @param ConfigFactoryInterface $config_factory
   *   The factory for configuration objects.
   */
  public function __construct(ConfigFactoryInterface $config_factory, EntityTypeManager $entity_type_manager) {
    parent::__construct($config_factory);
    $this->conf  = $this->config($this->getConfigName());
    $this->entityTypeManager = $entity_type_manager;
    $this->taxonomyTermStorage = $entity_type_manager->getStorage('taxonomy_term');
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('config.factory'),
      $container->get('entity_type.manager')
    );
  }

  public static function getConfigName() {
    return 'oab_ob1_adapter.theme_settings';
  }

  /**
   * Returns a unique string identifying the form.
   *
   * @return string
   *   The unique string identifying the form.
   */
  public function getFormId() {
    return 'oab_ob1_adapter_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
       self::getConfigName()
    ];
  }

  /**
   * Form constructor.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   *
   * @return array
   *   The form structure.
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form['tabs'] = [
      '#type' => 'vertical_tabs',
      '#title' => t('Configure ob1 theme')
    ];

    $form['fr'] = $this->generateTabForm('fr', 'français');
    $form['en'] = $this->generateTabForm('en', 'english');

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    $config = $this->config($this->getConfigName());

    foreach (['fr','en'] as $langcode) {
      $selected_urls = $form_state->getValue($langcode . '_url');
      $selected_routes = $form_state->getValue($langcode . '_routes');
      $selected_hubs = array_filter($form_state->getValue($langcode . '_selected_hubs'));

      $url_selected_to_save = [];
      $url_elems = array_filter(array_map('trim', explode("\n", $selected_urls)));
      foreach ($url_elems as $url) {
        $url_selected_to_save[] = $url;
      }

      $conf = [];
      $conf['url'] = $url_selected_to_save;
      $conf['routes'] = array_filter(array_map('trim', explode("\n", $selected_routes)));
      $conf['hubs'] = $selected_hubs;
      $config->set($langcode, $conf);
    }
    $config->save();

    parent::submitForm($form, $form_state);
  }

  private function generateTabForm($langcode, $langname) {

    $conf = $this->conf->get($langcode);
    /** @var View[] $view_types */
    $view_types = $this->viewsStorage->loadMultiple();
    $content_types = $this->contentTypeStorage->loadMultiple();
    $hubs = $this->taxonomyTermStorage->loadByProperties(['vid' => 'hub']);


    $tab = [
      '#type' => 'details',
      '#open' => true,
      '#title' => $this->t(ucfirst($langname)),
      '#description' => t('Ob1 config for @lang Content', ['@lang' => $langname]),
      '#group' => 'tabs'
    ];

    $tab['url'] = [
      '#type' => "details",
      '#open' => false,
      '#title' => t("Url conf")
    ];

    $tab['url'][$langcode . '_url'] = [
      '#type' => 'textarea',
      '#title' => t('List url One-i'),
      '#description' => t('Specify pages by using their paths. Enter one path per line without the langcode for ex: \'/en \'.'),
      '#default_value' => implode(PHP_EOL, $conf['url']) ?? ''
    ];

    $tab['routes'] = [
      '#type' => "details",
      '#open' => false,
      '#title' => t("Routes conf")
    ];

    $tab['routes'][$langcode . '_routes'] = [
      '#type' => 'textarea',
      '#title' => t('List routes One-i'),
      '#description' => t('Specify pages by using their routename. Enter one path per line without the langcode for ex: \'/en \'.'), '#default_value' => implode(PHP_EOL, $conf['routes']) ?? ''
    ];

    $tab['hubs'] = [
      '#type' => 'details',
      '#open' => false,
      '#title' => t('Hubs conf')
    ];

    $hub_options = [];
    foreach ($hubs as $hub) {
      $hub_options[$hub->id()] = $hub->label();
    }

    $tab['hubs'][$langcode . '_selected_hubs'] = [
      '#type' => 'checkboxes',
      '#options' => $hub_options,
      '#title' => t('select hubs'),
      '#default_value' => $conf['hubs'] ?? ''
    ];

    return $tab;
  }

}
