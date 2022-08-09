<?php

namespace Drupal\oab_mp_product_formule_packages\Form;

use Drupal\Core\Form\ConfirmFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Provides a form for deleting a Formule package revision.
 *
 * @ingroup oab_mp_product_formule_packages
 */
class FormulePackageRevisionDeleteForm extends ConfirmFormBase {

  /**
   * The Formule package revision.
   *
   * @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface
   */
  protected $revision;

  /**
   * The Formule package storage.
   *
   * @var \Drupal\Core\Entity\EntityStorageInterface
   */
  protected $formulePackageStorage;

  /**
   * The database connection.
   *
   * @var \Drupal\Core\Database\Connection
   */
  protected $connection;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    $instance = parent::create($container);
    $instance->formulePackageStorage = $container->get('entity_type.manager')->getStorage('formule_package');
    $instance->connection = $container->get('database');
    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'formule_package_revision_delete_confirm';
  }

  /**
   * {@inheritdoc}
   */
  public function getQuestion() {
    return $this->t('Are you sure you want to delete the revision from %revision-date?', [
      '%revision-date' => \Drupal::service('date.formatter')->format($this->revision->getRevisionCreationTime()),
    ]);
  }

  /**
   * {@inheritdoc}
   */
  public function getCancelUrl() {
    return new Url('entity.formule_package.version_history', ['formule_package' => $this->revision->id()]);
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
  public function buildForm(array $form, FormStateInterface $form_state, $formule_package_revision = NULL) {
    $this->revision = $this->FormulePackageStorage->loadRevision($formule_package_revision);
    $form = parent::buildForm($form, $form_state);

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $this->FormulePackageStorage->deleteRevision($this->revision->getRevisionId());

    $this->logger('content')->notice('Formule package: deleted %title revision %revision.', ['%title' => $this->revision->label(), '%revision' => $this->revision->getRevisionId()]);
    $this->messenger()->addMessage(t('Revision from %revision-date of Formule package %title has been deleted.', ['%revision-date' => \Drupal::service('date.formatter')->format($this->revision->getRevisionCreationTime()), '%title' => $this->revision->label()]));
    $form_state->setRedirect(
      'entity.formule_package.canonical',
       ['formule_package' => $this->revision->id()]
    );
    if ($this->connection->query('SELECT COUNT(DISTINCT vid) FROM {formule_package_field_revision} WHERE id = :id', [':id' => $this->revision->id()])->fetchField() > 1) {
      $form_state->setRedirect(
        'entity.formule_package.version_history',
         ['formule_package' => $this->revision->id()]
      );
    }
  }

}
