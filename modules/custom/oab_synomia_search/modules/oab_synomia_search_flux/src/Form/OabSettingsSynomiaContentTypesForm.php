<?php

namespace Drupal\oab_synomia_search_flux\Form;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsSynomiaContentTypesForm extends ConfigFormBase
{


  /**
   * @var EntityTypeManagerInterface
   */
  private EntityTypeManagerInterface $entityManager;

  public function __construct(ConfigFactoryInterface     $config_factory,
                              EntityTypeManagerInterface $entity_type_manager) {
    parent::__construct($config_factory);
    $this->entityManager = $entity_type_manager;
  }

  public static function create(ContainerInterface $container): OabSettingsSynomiaContentTypesForm {
    return new self(
      $container->get('config.factory'),
      $container->get('entity_type.manager')
    );
  }
  /**
   * {@inheritdoc}
   */
  public function getFormId(): string {
    return 'oab_admin_settings_synomia_contentTypes';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames(): array {
    return ['oab_synomia_search.synomia.contentTypes',];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state): array {

        $config = $this->config('oab_synomia_search.synomia.contentTypes');
        $content_types = $this->entityManager->getStorage('node_type')->loadMultiple();
        $form['label'] = array(
            '#type' => 'label',
            '#title' => 'Select the types of content you want to index by Synomia search',
        );
        foreach ($content_types as $contentType) {
            $form[$contentType->id()] = array(
                '#type' => 'checkbox',
                '#title' => $contentType->label(),
                '#default_value' => $config->get($contentType->id()),
            );
        }
        $form['creationDateLimit'] = array(
            '#type' => 'date',
            '#title' => "Creation date limit",
            '#default_value' => $config->get('creationDateLimit'),
        );
    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $config = $this->config('oab_synomia_search.synomia.contentTypes');
        $content_types = \Drupal::service('entity_type.manager')->getStorage('node_type')->loadMultiple();
        foreach ($content_types as $contentType) {
            $config->set($contentType->id(), $form_state->getValue($contentType->id()));
        }

        $config->set('creationDateLimit', $form_state->getValue('creationDateLimit'));
        $config->save();
    parent::submitForm($form, $form_state);
  }
}
