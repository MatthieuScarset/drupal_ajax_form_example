<?php

namespace Drupal\oab_ob1_adapter\Form;

use Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException;
use Drupal\Component\Plugin\Exception\PluginNotFoundException;
use Drupal\Core\Config\Config;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityStorageInterface;
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
   * @var EntityStorageInterface|mixed|object
   */
  private $viewsStorage;

  /**
   * @var EntityTypeManager
   */
  private $entityTypeManager;

  /**
   * @var EntityStorageInterface|mixed|object
   */
  private $contentTypeStorage;

  /**
   * Constructs a \Drupal\system\ConfigFormBase object.
   *
   * @param ConfigFactoryInterface $config_factory
   *   The factory for configuration objects.
   * @param EntityTypeManager $entity_type_manager
   * @throws InvalidPluginDefinitionException
   * @throws PluginNotFoundException
   */
  public function __construct(ConfigFactoryInterface $config_factory, EntityTypeManager $entity_type_manager) {
    parent::__construct($config_factory);
    $this->conf  = $this->config($this->getConfigName());
    $this->entityTypeManager = $entity_type_manager;
    $this->viewsStorage = $entity_type_manager->getStorage('view');
    $this->contentTypeStorage = $entity_type_manager->getStorage('node_type');
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
      $selected_displays = array_filter($form_state->getValue($langcode . '_selected_displays'));
      $selected_contents = array_filter($form_state->getValue($langcode . '_selected_contents'));
      $selected_urls = $form_state->getValue($langcode . '_url');

      $url_selected_to_save = [];
      $url_elems = array_filter(array_map('trim', explode("\n", $selected_urls)));
      foreach ($url_elems as $url) {
        $url_selected_to_save[] = $url;
      }

      $selected_to_save = [];
      foreach ($selected_displays as $display) {
        $elems = explode('.', $display);
        $selected_to_save[$elems[0]][] = $elems[1];
      }

      $content_selected_to_save = [];
      foreach ($selected_contents as $content) {
        $content_selected_to_save[] = $content;
      }

      $conf = [];
      $conf['url'] = $url_selected_to_save;
      $conf['views'] = $selected_to_save;
      $conf['contents'] = $content_selected_to_save;
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

    $tab['views'] = [
      '#type' => "details",
      "#open" => false,
      '#title' => t("Views conf")
    ];

    $options = [];
    foreach ($view_types as $view) {
      if ($view->get('status')) {
        foreach ($view->get('display') as $display) {
          if ($display['display_plugin'] == 'page') {
            $options[$view->id().'.'.$display['id']] = $view->label().' - '.$display['display_title'];
          }
        }
      }
    }

    $default = [];
    foreach ($conf['views'] as $view => $displays) {
      foreach ($displays as $display) {
        $default[] = $view.'.'.$display;
      }
    }

    $tab['views'][$langcode . '_selected_displays'] = [
      '#type' => 'checkboxes',
      '#options' => $options,
      '#title' => t('select views displays'),
      '#default_value' => $default
    ];

    $tab['contents'] = [
      '#type' => 'details',
      '#open' => false,
      '#title' => t('Content Type conf')
    ];

    $content_options = [];
    foreach ($content_types as $content) {
      if ($content->get('status')) {
        $content_options[$content->get('type')] = $content->label();
      }
    }

    $tab['contents'][$langcode . '_selected_contents'] = [
      '#type' => 'checkboxes',
      '#options' => $content_options,
      '#title' => t('select content types'),
      '#default_value' => $conf['contents'] ?? ''
    ];

    return $tab;
  }

}
