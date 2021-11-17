<?php

namespace Drupal\oab_marketo\Form;


use Drupal\Core\Access\AccessResult;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Session\AccountProxyInterface;
use Drupal\oab_marketo\PhotoCommercialeService;
use Drupal\user\Entity\User;
use Symfony\Component\DependencyInjection\ContainerInterface;

class OabAltaresSettingsForm extends ConfigFormBase {

  const AUTHORIZED_USERS = 'authorized_users';
  const CONSUMER_KEY = 'consumer_key';
  const CONSUMER_SECRET = 'consumer_secret';
  const ALTARES_API_URL = 'api_url';
  const NB_MAX_REQUEST = 'nb_max_request';
  const CACHE_RETENTION_TIME = 'cache_retention_time';

  /**
   * @var FileSystemInterface
   */
  private $fileSystem;


  /**
   * Constructs a \Drupal\system\ConfigFormBase object.
   *
   * @param \Drupal\Core\Config\ConfigFactoryInterface $config_factory
   *   The factory for configuration objects.
   */
  public function __construct(ConfigFactoryInterface $config_factory, FileSystemInterface $file_system) {
    $this->setConfigFactory($config_factory);
    $this->fileSystem = $file_system;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('config.factory'),
      $container->get('file_system')
    );
  }

  public static function getConfigName() {
    return 'oab_marketo.altares_settings';
  }

  /**
   * Gets the configuration names that will be editable.
   *
   * @return array
   *   An array of configuration object names that are editable if called in
   *   conjunction with the trait's config() method.
   */
  protected function getEditableConfigNames() {
    return [
      $this->getConfigName()
    ];
  }

  /**
   * Returns a unique string identifying the form.
   *
   * The returned ID should be a unique string that can be a valid PHP function
   * name, since it's used in hook implementation names such as
   * hook_form_FORM_ID_alter().
   *
   * @return string
   *   The unique string identifying the form.
   */
  public function getFormId() {
    return 'oab_marketo_altares_settings';
  }

  public function buildForm(array $form, FormStateInterface $form_state) {


    $config = $this->config(self::getConfigName());

    $form['tabs'] = [
      '#type' => 'vertical_tabs',
      '#title' => t('Configure Altares'),
    ];

    if ($this->currentUser()->hasPermission('administer site configuration')) {
      $form['altares'] = [
        '#type' => 'details',
        '#open' => true,
        '#title' => t('Config Altares API'),
        '#description'    => t("Altares API auth config"),
        '#group' => 'tabs'
      ];

      $form['altares'][self::ALTARES_API_URL] = [
        '#type' => 'url',
        '#title' => $this->t('Altares API URL'),
        '#default_value' => $config->get(self::ALTARES_API_URL),
        '#required' => true
      ];

      $form['altares'][self::CONSUMER_KEY] = [
        '#type' => 'textfield',
        '#title' => $this->t('Consumer key'),
        '#default_value' => $config->get(self::CONSUMER_KEY),
        '#required' => true
      ];

      $form['altares'][self::CONSUMER_SECRET] = [
        '#type' => 'textfield',
        '#title' => $this->t('Consumer secret'),
        '#default_value' => $config->get(self::CONSUMER_SECRET),
        '#required' => true
      ];

      $form['altares'][self::NB_MAX_REQUEST] = [
        '#type' => 'number',
        '#title' => $this->t('Max client request allowed'),
        '#description' => $this->t("Number of request allowed for a token/client"),
        '#default_value' => $config->get(self::NB_MAX_REQUEST) ?: 50,
        '#required' => true
      ];

      $form['altares'][self::CACHE_RETENTION_TIME] = [
        '#type' => 'number',
        '#title' => $this->t('Cache retention time'),
        '#description' => $this->t("How many hours altares data will be saved in cache."),
        '#default_value' => $config->get(self::CACHE_RETENTION_TIME) ?: 24,
        '#required' => true
      ];
    }

    $form['photo_commerciale'] = [
      '#type' => 'details',
      '#open' => true,
      '#title' => t('Photo commerciale'),
      '#group' => 'tabs'
    ];

    $form['photo_commerciale']['upload_file'] = [
      '#type' => 'file',
      '#title' => $this->t("Upload file"),
      '#upload_location' => PhotoCommercialeService::IMPORT_DIRECTORY,
      '#upload_validators' => array(
        'file_validate_extensions' => array('csv zip'),
        'file_validate_size' => array(256 * 1024 * 1024),
      )
    ];

    $form['photo_commerciale']['import'] = [
      '#type' => 'submit',
      '#value' => $this->t('Import'),
      '#submit' => array('::executeImportHandler'),
      '#validate' => array('::validateImportHandler')
    ];


    if ($this->currentUser()->hasPermission('administer site configuration')) {
      $form['authorized_users_details'] = [
        '#type' => 'details',
        '#title' => t('Authorized users'),
        '#description'    => t("Authorized users to access this conf"),
        '#group' => 'tabs'
      ];

      $authorized_users = $config->get(self::AUTHORIZED_USERS);
      if (!is_array($authorized_users)) {
        $authorized_users = [$authorized_users];
      }

      $form['authorized_users_details'][self::AUTHORIZED_USERS] = [
        '#title' => ('Select User'),
        '#type' => 'entity_autocomplete',
        '#target_type' => 'user',
        '#required' => TRUE,
        '#tags' => TRUE,
        '#selection_settings' => [
          'include_anonymous' => FALSE,
        ],
        '#default_value' => User::loadMultiple($authorized_users),
      ];
    }

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {

    if ($this->currentUser()->hasPermission('administer site configuration')) {
      $config = $this->config($this->getConfigName());
      $config
        ->set(self::CONSUMER_KEY, $form_state->getValue(self::CONSUMER_KEY))
        ->set(self::CONSUMER_SECRET, $form_state->getValue(self::CONSUMER_SECRET))
        ->set(self::ALTARES_API_URL, $form_state->getValue(self::ALTARES_API_URL))
        ->set(self::NB_MAX_REQUEST, $form_state->getValue(self::NB_MAX_REQUEST))
        ->set(self::CACHE_RETENTION_TIME, $form_state->getValue(self::CACHE_RETENTION_TIME));

      if ($form_state->hasValue(self::AUTHORIZED_USERS)) {
        $users_value = $form_state->getValue(self::AUTHORIZED_USERS);
        $users_id = [];
        foreach ($users_value as $value) {
          $users_id[] = $value['target_id'];
        }

        $config->set(self::AUTHORIZED_USERS, $users_id);
      }
      $config->save();
    }

    parent::submitForm($form, $form_state); // TODO: Change the autogenerated stub
  }

  public function validateImportHandler(array &$form, FormStateInterface  $form_state) {
    $file = file_save_upload('upload_file', array('file_validate_extensions' => ''),
      PhotoCommercialeService::IMPORT_DIRECTORY, null, FileSystemInterface::EXISTS_REPLACE);

    if (!$file[0]) {
        $form_state->setErrorByName('upload_file', t('No file was uploaded.'));
    } else {
      $filename = $file[0]->getFilename();
      $input = &$form_state->getUserInput();
      $input["filename"] = $filename;
      $form_state->setUserInput($input);
    }

  }

  public function executeImportHandler(array &$form, FormStateInterface $form_state) {


    $input = $form_state->getUserInput();
    $mon_fichier = $this->fileSystem->realpath(PhotoCommercialeService::IMPORT_DIRECTORY . $input['filename']);

    if (!file_exists($mon_fichier)) {
      return;
    }

    //opération pour vider la table
    $operations = [
      ['oab_marketo_clearPhotoCommercialeTable', array()],
      ['oab_marketo_importPhotoCommerciale', array($mon_fichier)],
      ['oab_marketo_deleteFile', array($mon_fichier)]
    ];

    ##Setting up du batch
    $batch = array(
      'title' => t("Import Photo commerciale"),
      'operations'  => $operations,
      'progress_message' => t('Processed @current out of @total.'),
      'finished' => 'oab_marketo_endingBatch',
      'file' => drupal_get_path('module', 'oab_marketo') . '/oab_marketo.photo_commerciale.batch.inc'
    );

    batch_set($batch);
  }


}
