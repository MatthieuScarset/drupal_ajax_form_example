<?php

namespace Drupal\oab_develop\Plugin\Block;

use Composer\InstalledVersions;
use Drupal\Core\Access\AccessResult;
use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Composer\Composer;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Theme\ThemeManagerInterface;
use Symfony\Component\Config\Resource\ComposerResource;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 *
 * @author XBDG7979
 * @Block(
 *   id = "version_bar_block",
 *   admin_label = @Translation("Version Bar Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class VersionBarBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /** @var string[]  */
  private array $envs = [
    'DEV' => 'DEVELOPMENT',
    'PRP' => 'PRE-PRODUCTION',
    'PROD' => 'PRODUCTION',
    'TEST' => 'TEST',
    'INT' => 'INTEGRATION'
  ];

  /**
   * @var \Drupal\Core\Theme\ThemeManagerInterface
   */
  private ThemeManagerInterface $themeManager;

  /**
   * @var \Drupal\Core\Routing\RouteMatchInterface
   */
  private RouteMatchInterface $routeMatch;


  /**
   * Constructs a \Drupal\Component\Plugin\PluginBase object.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition,
                              ThemeManagerInterface $theme_manager, RouteMatchInterface $routeMatch) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->themeManager = $theme_manager;
    $this->routeMatch = $routeMatch;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new self(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('theme.manager'),
      $container->get('current_route_match')
    );
  }

  public function blockAccess(AccountInterface $account) {
    return AccessResult::allowedIf(!str_starts_with($this->routeMatch->getRouteName(), 'entity_browser.'));
  }

  /**
   * {@inheritdoc}
   */
  public function build() {

    $version = "";
    $composer = InstalledVersions::getRootPackage();
    $file = "modules/custom/oab_develop/.version";

    // get version by the file ".version" from CI/CD
    if (file_exists($file)) {
      // find the version written by the CI/CD -> remove the special chars
      $version = str_replace(["\r", "\n"], '', file_get_contents($file));
    }
    // if the file ".version" doesn't exist, the version is given by composer
    if (strlen($version) === 0 ) {
      $version = $composer['pretty_version'] ?? $composer["version"] ?? "Not Found";
    }

    // get the environment by the environment variables
    $env = getenv('ENV') ?? "Local";
    $env_label = $this->envs[$env] ?? $env;

    // get the current theme name
    $theme_name = $this->themeManager->getActiveTheme()->getName();

    // get the message from the block configuration
    $config = $this->getConfiguration();
    $message = $config['message'] ?? '';

    //Infos de la CI
    $file_ci_data = "ci-data";
    $ci_datas = [];
    if (file_exists($file_ci_data)) {
      // find the version written by the CI/CD -> remove the special chars
      $file_data = str_replace(["\r", "\n"], ';', file_get_contents($file_ci_data));
      $datas = explode(";", $file_data);
      foreach ($datas as $data) {
        $tmp = explode("=", $data);
        if(count($tmp) == 2) {
          if($tmp[0] == "CI_COMMIT_TIMESTAMP" && !empty($tmp[1])) {
            $ci_datas[$tmp[0]] = date_format(new \DateTime($tmp[1]), "d/m/Y H:i");
          }
          else {
            $ci_datas[$tmp[0]] = $tmp[1];
          }
        }
      }
    }

    return [
      "version" => $version,
      "env" => $env,
      "envLabel" => $env_label,
      "theme" => $theme_name,
      "message" => $message,
      "ci_datas" => $ci_datas
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

    // Retrieve existing configuration for this block.
    $config = $this->getConfiguration();

    // Add a form field to the existing block configuration form.
    $form['message'] = array(
      '#type' => 'textarea',
      '#title' => t('message'),
      '#rows' => 2,
      '#description' => t('Add a message in the bar'),
      '#default_value' =>  $config['message'] ?? '',
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {}

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    // Save our custom settings when the form is submitted.
    $this->setConfigurationValue('message', $form_state->getValue('message'));
  }
}
