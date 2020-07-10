<?php

namespace Drupal\oab_marketo_form\Form;

use Drupal\Component\Datetime\TimeInterface;
use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Entity\EntityRepositoryInterface;
use Drupal\Core\Entity\EntityStorageException;
use Drupal\Core\Entity\EntityTypeBundleInfoInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Mail\MailManagerInterface;
use Drupal\Core\Messenger\MessengerInterface;

use Drupal\Core\Session\AccountProxyInterface;
use Drupal\Core\Url;
use Drupal\oab_marketo_form\Entity\MarketoForm;
use Drupal\taxonomy\Entity\Term;
use Drupal\user\Entity\User;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Form handler for the Example add and edit forms.
 */
class MarketoFormForm extends ContentEntityForm {


  /** @var LanguageManagerInterface */
  private $languageManager;

  public function __construct( LanguageManagerInterface $languageManager,
                               EntityRepositoryInterface $entity_repository,
                               EntityTypeBundleInfoInterface $entity_type_bundle_info = NULL,
                              TimeInterface $time = NULL) {
    $this->languageManager = $languageManager;
    parent::__construct($entity_repository, $entity_type_bundle_info, $time);
  }


  public static function create(ContainerInterface $container) {
    return new static(
      $container->get("language_manager"),
      $container->get('entity.repository'),
      $container->get('entity_type.bundle.info'),
      $container->get('datetime.time')
    );
  }

  /**
   * @var MarketoForm
   */
  protected $entity;


  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {

    $form['langcode'] = [
      "#type" => "hidden",
      '#value' => $this->languageManager->getId()
    ];


    return parent::form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function save(array $form, FormStateInterface $form_state) {

    $status = false;
    try {
      $status = $this->entity->save();
    } catch (EntityStorageException $e) {
      $status = false;
      $msg = $e->getMessage();
    }
    if (!$status) {
      $this->messenger()->addError($this->t('The marketo form has not been saved. Please try again'));
      if (isset($msg)) {
        $this->logger('oab_marketo_form')->error("The marketo form has not been saved with the error : @error", [
          '@error' => $msg
        ]);
      }
    }
  }

}

