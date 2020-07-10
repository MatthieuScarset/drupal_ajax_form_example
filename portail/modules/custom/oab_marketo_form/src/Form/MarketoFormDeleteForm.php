<?php

namespace Drupal\oab_marketo_form\Form;

use Drupal\Component\Datetime\TimeInterface;
use Drupal\Core\Entity\ContentEntityDeleteForm;
use Drupal\Core\Entity\EntityConfirmFormBase;
use Drupal\Core\Entity\EntityRepositoryInterface;
use Drupal\Core\Entity\EntityTypeBundleInfoInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Url;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Builds the form to delete an Example.
 */

class MarketoFormDeleteForm extends ContentEntityDeleteForm {

  /** @var LanguageManagerInterface  */
  private $languageManager;

  public function __construct(LanguageManagerInterface $languageManager,
                              EntityRepositoryInterface $entity_repository,
                              EntityTypeBundleInfoInterface $entity_type_bundle_info = NULL,
                              TimeInterface $time = NULL) {
    $this->languageManager = $languageManager;
    parent::__construct($entity_repository, $entity_type_bundle_info, $time);
  }

  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('language_manager'),
      $container->get('entity.repository'),
      $container->get('entity_type.bundle.info'),
      $container->get('datetime.time'));
  }

  /**
   * {@inheritdoc}
   */
  public function getQuestion() {
    return $this->t('Are you sure you want to remove @email from @lang diffusion list?', array('@email' => $this->entity->email(), '@lang' => $this->entity->language()->getName()));
  }

  /**
   * {@inheritdoc}
   */
  public function getCancelUrl() {
    return new Url('entity.mailing_list_item.collection');
  }

  /**
   * {@inheritdoc}
   */
  public function getConfirmText() {
    return $this->t('Delete');
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $email = $this->entity->email();
    $this->entity->delete();
    $this->messenger()->addMessage($this->t('Email @email has been deleted from mailing list.', array('@email' => $email)));

    $form_state->setRedirectUrl($this->getCancelUrl());
  }
}

