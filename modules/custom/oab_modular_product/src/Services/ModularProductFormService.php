<?php

namespace Drupal\oab_modular_product\Services;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Session\AccountProxy;
use Drupal\paragraphs\Entity\Paragraph;

class ModularProductFormService {

  /**
   * @var \Drupal\Core\Entity\EntityStorageInterface|mixed|object
   */
  private EntityStorageInterface $formDisplayStorage;

  /**
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public function __construct(private AccountProxy $currentUser,
                              private EntityTypeManager $entityTypeManager) {
    $this->formDisplayStorage = $entityTypeManager->getStorage('entity_form_display');
  }

  public function disableFieldWithDefaultValue(&$form, FormStateInterface $form_state, EntityInterface $entity = null) {

    if (in_array('administrator', $this->currentUser->getRoles())) {
      return;
    }

    /** @var \Drupal\Core\Entity\EntityStorageInterface $storage */
    $storage = $form_state->getStorage();

    /** @var \Drupal\Core\Entity\Entity\EntityFormDisplay $form_display */
    $form_display = $storage['form_display'];
    $form_display_content = $form_display->get('content');

    /** @var \Drupal\Core\Entity\EntityInterface $entity */
    $entity = $entity ?? $form_state->getFormObject()->getEntity();

    //Paragraphs
    if (is_a($entity, Paragraph::class)) {
      $parent_field_name = $form['#parents'][0];

      if (isset($form_display_content[$parent_field_name])) {
        $form_displays = $this->formDisplayStorage->loadByProperties([
          'targetEntityType' => $entity->getEntityTypeId(),
          'bundle' => $entity->bundle(),
          'mode' => $form_displaycontent[$parent_field_name]['settings']['form_mode'] ?? "default"
        ]);

        if (!empty($form_displays)) {
          $form_display = reset($form_displays);
          $form_display_content = $form_display->get('content');
        }
      }
    }

    /** @var \Drupal\Core\Field\BaseFieldDefinition[] $field_definitions */
    $field_definitions = $entity->getFieldDefinitions();

    $avoided_field_type = ['boolean', 'entity_reference', 'entity_reference_revisions'];

    foreach ($form_display_content as $field_name => $field) {
      if (isset($form[$field_name]) && isset($field_definitions[$field_name])
        && !in_array($field_definitions[$field_name]->getType(), $avoided_field_type)
        && $this->isDefaultValueEmpty($field_definitions[$field_name]->getDefaultValue($entity))
      ) {
        $form[$field_name]['#disabled'] = 'disabled';
      }
    }
  }

  private function isDefaultValueEmpty(mixed $default_value): bool {
    return isset($default_value[0]["value"]) && strlen($default_value[0]["value"]);
  }
}
