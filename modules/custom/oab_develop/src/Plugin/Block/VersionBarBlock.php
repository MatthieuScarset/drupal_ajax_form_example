<?php

namespace Drupal\oab_develop\Plugin\Block;

use Composer\InstalledVersions;
use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

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

class VersionBarBlock extends BlockBase {

  /** @var string[]  */
  private array $envs = [
    'PRP' => 'PRE-PRODUCTION',
    'PROD' => 'PRODUCTION',
    'TEST' => 'TEST',
    'INT' => 'INTEGRATION'
  ];

  /**
   * {@inheritdoc}
   */
  public function build() {

    // partie : version
    $version = "Not Found";
    $composer = InstalledVersions::getRootPackage();
    $file = "modules/custom/oab_develop/.version";
    if (file_exists($file)) {
      $version = file_get_contents($file);
    }
    else if(isset($composer["pretty_version"])) {
      $version = $composer['pretty_version'];
    }
    else if (isset($composer["version"])) {
      $version = $composer["version"];
    }

    // partie : environment
    $env = $_ENV['ENV'] ?? "Local";
    $envLabel = $this->envs[$env] ?? "Local";

    // partie : theme
    $themeHandler = \Drupal::theme();
    $themeName = $themeHandler->getActiveTheme()->getName();

    // partie : message
    $config = $this->getConfiguration();
    $message = $config['message'] ?? '';

    return [
      "version" => $version,
      "env" => $env,
      "envLabel" => $envLabel,
      "theme" => $themeName,
      "message" => $message,
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
