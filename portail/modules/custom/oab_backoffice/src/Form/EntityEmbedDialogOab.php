<?php

/**
 * @file
 * Contains \Drupal\entity_embed\Form\EntityEmbedDialog.
 */

namespace Drupal\oab_backoffice\Form;

use Drupal\Component\Utility\Html;
use Drupal\Component\Utility\Unicode;
use Drupal\Core\Ajax\AjaxResponse;
use Drupal\Core\Ajax\CloseModalDialogCommand;
use Drupal\Core\Ajax\HtmlCommand;
use Drupal\Core\Ajax\SetDialogTitleCommand;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\entity_embed\Form\EntityEmbedDialog;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\editor\Ajax\EditorDialogSave;
use Drupal\editor\EditorInterface;
use Drupal\embed\EmbedButtonInterface;
use Drupal\entity_browser\Events\Events;
use Drupal\entity_browser\Events\RegisterJSCallbacks;
use Drupal\entity_embed\EntityEmbedDisplay\EntityEmbedDisplayManager;
use Drupal\entity_embed\EntityHelperTrait;
use Drupal\Component\Serialization\Json;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\EventDispatcher\EventDispatcherInterface;


/**
 * Provides a form to embed entities by specifying data attributes.
 */
class EntityEmbedDialogOab extends EntityEmbedDialog {

  /**
   * Constructs a EntityEmbedDialog object.
   *
   * @param \Drupal\entity_embed\EntityEmbedDisplay\EntityEmbedDisplayManager $plugin_manager
   *   The Module Handler.
   * @param \Drupal\Core\Form\FormBuilderInterface $form_builder
   *   The Form Builder.
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager service.
   * @param \Symfony\Component\EventDispatcher\EventDispatcherInterface $event_dispatcher
   *   Event dispatcher service.
   */
  public function __construct(EntityEmbedDisplayManager $plugin_manager, FormBuilderInterface $form_builder, EntityTypeManagerInterface $entity_type_manager, EventDispatcherInterface $event_dispatcher) {
    $this->setDisplayPluginManager($plugin_manager);
    $this->formBuilder = $form_builder;
    $this->entityTypeManager = $entity_type_manager;
    $this->eventDispatcher = $event_dispatcher;
  }

  /**
   * {@inheritdoc}
   *
   * @param \Drupal\editor\EditorInterface $editor
   *   The editor to which this dialog corresponds.
   * @param \Drupal\embed\EmbedButtonInterface $embed_button
   *   The URL button to which this dialog corresponds.
   */
  public function buildForm(array $form, FormStateInterface $form_state, EditorInterface $editor = NULL, EmbedButtonInterface $embed_button = NULL) {
    $values = $form_state->getValues();
    $input = $form_state->getUserInput();
    // Set embed button element in form state, so that it can be used later in
    // validateForm() function.
    $form_state->set('embed_button', $embed_button);
    $form_state->set('editor', $editor);
    // Initialize entity element with form attributes, if present.
    $entity_element = empty($values['attributes']) ? array() : $values['attributes'];
    $entity_element += empty($input['attributes']) ? array() : $input['attributes'];
    // The default values are set directly from \Drupal::request()->request,
    // provided by the editor plugin opening the dialog.
    if (!$form_state->get('entity_element')) {
      $form_state->set('entity_element', isset($input['editor_object']) ? $input['editor_object'] : array());
    }
    $entity_element += $form_state->get('entity_element');
    $entity_element += array(
      'data-entity-type' => $embed_button->getTypeSetting('entity_type'),
      'data-entity-uuid' => '',
      'data-entity-embed-display' => 'entity_reference:entity_reference_entity_view',
      'data-entity-embed-settings' => array(),
    );
    $form_state->set('entity_element', $entity_element);
    $form_state->set('entity', $this->loadEntity($entity_element['data-entity-type'], $entity_element['data-entity-uuid']));

    if (!$form_state->get('step')) {
      // If an entity has been selected, then always skip to the embed options.
      if ($form_state->get('entity')) {
        $form_state->set('step', 'embed');
      }
      else {
        $form_state->set('step', 'select');
      }
    }

    $form['#tree'] = TRUE;
    $form['#attached']['library'][] = 'editor/drupal.editor.dialog';
    $form['#attached']['library'][] = 'entity_embed/drupal.entity_embed.dialog';
    $form['#prefix'] = '<div id="entity-embed-dialog-form">';
    $form['#suffix'] = '</div>';
    $form['#attributes']['class'][] = 'entity-embed-dialog-step--' . $form_state->get('step');

    $this->loadEntityBrowser($form_state);

    if ($form_state->get('step') == 'select') {
      $form = $this->buildSelectStep($form, $form_state);
    }
    elseif ($form_state->get('step') == 'review') {
      $form = $this->buildReviewStep($form, $form_state);
    }
    elseif ($form_state->get('step') == 'embed') {
      $form = $this->buildEmbedStep($form, $form_state);
    }

    return $form;
  }

  /**
   * Form constructor for the entity selection step.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   *
   * @return array
   *   The form structure.
   */
  public function buildSelectStep(array &$form, FormStateInterface $form_state) {
    // Entity element is calculated on every AJAX request/submit. See ::buildForm().
    $entity_element = $form_state->get('entity_element');
    /** @var \Drupal\embed\EmbedButtonInterface $embed_button */
    $embed_button = $form_state->get('embed_button');
    $entity = $form_state->get('entity');

    $form['attributes']['data-entity-type'] = array(
      '#type' => 'value',
      '#value' => $entity_element['data-entity-type'],
    );

    $label = $this->t('Label');
    // Attempt to display a better label if we can by getting it from
    // the label field definition.
    $entity_type = $this->entityTypeManager->getDefinition($entity_element['data-entity-type']);
    if ($entity_type->isSubclassOf('\Drupal\Core\Entity\FieldableEntityInterface') && $entity_type->hasKey('label')) {
      $field_definitions = $this->entityManager()->getBaseFieldDefinitions($entity_type->id());
      if (isset($field_definitions[$entity_type->getKey('label')])) {
        $label = $field_definitions[$entity_type->getKey('label')]->getLabel();
      }
    }

    $form['#title'] = $this->t('Select @type to embed', array('@type' => $entity_type->getLowercaseLabel()));

    if ($this->entityBrowser) {
      $this->eventDispatcher->addListener(Events::REGISTER_JS_CALLBACKS, [$this, 'registerJSCallback']);

      $form['entity_browser']['#theme_wrappers'] = ['container'];
      $form['entity_browser']['browser'] = $this->entityBrowser->getDisplay()->displayEntityBrowser($form_state);
      $form['entity_browser']['entity_id'] = [
        '#type' => 'hidden',
        '#default_value' => $entity ? $entity->id() : '',
        '#attributes' => ['class' => ['eb-target']]
      ];
      $form['#attached']['library'][] = 'entity_browser/common';
      $form['#attached']['drupalSettings']['entity_browser'] = [
        $this->entityBrowser->getDisplay()->getUuid() => [
          'cardinality' => 1
        ]
      ];
    }
    else {
      $form['entity_id'] = array(
        '#type' => 'entity_autocomplete',
        '#target_type' => $entity_element['data-entity-type'],
        '#title' => $label,
        '#default_value' => $entity,
        '#required' => TRUE,
        '#description' => $this->t('Type label and pick the right one from suggestions. Note that the unique ID will be saved.'),
      );
      if ($bundles = $embed_button->getTypeSetting('bundles')) {
        $form['entity_id']['#selection_settings']['target_bundles'] = $bundles;
      }
    }

    $form['attributes']['data-entity-uuid'] = array(
      '#type' => 'value',
      '#title' => $entity_element['data-entity-uuid'],
    );
    $form['actions'] = array(
      '#type' => 'actions',
    );

    $form['actions']['save_modal'] = array(
      '#type' => 'submit',
      '#value' => $this->t('Next'),
      '#button_type' => 'primary',
      // No regular submit-handler. This form only works via JavaScript.
      '#submit' => array(),
      '#ajax' => array(
        'callback' => '::submitSelectStepOab',
        'event' => 'click',
      ),
      '#attributes' => [
        'class' => [
          'js-button-next',
        ],
      ],
    );

    return $form;
  }


  /**
   * Form submission handler for the entity selection step.
   *
   * On success will send the user to the next step of the form to select the
   * embed display settings. On form errors, this will rebuild the form and
   * display the error messages.
   *
   * @param array $form
   *   The form array.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The form state.
   *
   * @return \Drupal\Core\Ajax\AjaxResponse
   *   The ajax response.
   */
  /*public function submitSelectStepOab(array &$form, FormStateInterface $form_state) {
    $response = new AjaxResponse();

    // Display errors in form, if any.
    if ($form_state->hasAnyErrors()) {
      unset($form['#prefix'], $form['#suffix']);
      $form['status_messages'] = array(
        '#type' => 'status_messages',
        '#weight' => -10,
      );
      $response->addCommand(new HtmlCommand('#entity-embed-dialog-form', $form));
    }
    else {
      $form_state->set('step', !empty($this->entityBrowserSettings['display_review']) ? 'review' : 'embed_oab');
      $form_state->setRebuild(TRUE);
      $rebuild_form = $this->formBuilder->rebuildForm('entity_embed_dialog', $form_state, $form);
      unset($rebuild_form['#prefix'], $rebuild_form['#suffix']);
      $response->addCommand(new HtmlCommand('#entity-embed-dialog-form', $rebuild_form));
      $response->addCommand(new SetDialogTitleCommand('', $rebuild_form['#title']));
    }

    return $response;
  }*/
  public function submitSelectStepOab(array &$form, FormStateInterface $form_state) {
    $response = new AjaxResponse();

    // default attributes
    $new_entity_element = $form_state->getValue('attributes');
    $new_entity_element['data-entity-embed-display'] = 'entity_reference:entity_reference_entity_view';
    $new_entity_element['data-entity-embed-settings'] =  array('view_mode' => 'default');
    $new_entity_element['data-embed-button'] = 'media_browser';
    $new_entity_element['data-align'] = '';
    $new_entity_element['data-caption'] = '';
    $form_state->setValue('attributes', $new_entity_element);


    // Submit configuration form the selected Entity Embed Display plugin.
    $entity_element = $form_state->getValue('attributes');
    $entity = $this->loadEntity($entity_element['data-entity-type'], $entity_element['data-entity-uuid']);
    $plugin_id = $entity_element['data-entity-embed-display'];
    $plugin_settings = $entity_element['data-entity-embed-settings'] ?: array();
    $display = $this->displayPluginManager()->createInstance($plugin_id, $plugin_settings);
    $display->setContextValue('entity', $entity);
    $display->setAttributes($entity_element);
    $display->submitConfigurationForm($form, $form_state);

    $values = $form_state->getValues();
    // Display errors in form, if any.
    if ($form_state->hasAnyErrors()) {
      unset($form['#prefix'], $form['#suffix']);
      $form['status_messages'] = array(
        '#type' => 'status_messages',
        '#weight' => -10,
      );
      $response->addCommand(new HtmlCommand('#entity-embed-dialog-form', $form));
    }
    else {
      // Serialize entity embed settings to JSON string.
      if (!empty($values['attributes']['data-entity-embed-settings'])) {
        $values['attributes']['data-entity-embed-settings'] = Json::encode($values['attributes']['data-entity-embed-settings']);
      }

      // Filter out empty attributes.
      $values['attributes'] = array_filter($values['attributes'], function($value) {
        return (bool) Unicode::strlen((string) $value);
      });

      // Allow other modules to alter the values before getting submitted to the WYSIWYG.
      $this->moduleHandler()->alter('entity_embed_values', $values, $entity, $display, $form_state);

      $response->addCommand(new EditorDialogSave($values));
      $response->addCommand(new CloseModalDialogCommand());
    }

    return $response;
  }


  /**
   * Form constructor for the entity embedding step.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   The current state of the form.
   *
   * @return array
   *   The form structure.
   */
  public function buildEmbedStep(array $form, FormStateInterface $form_state) {
    // Entity element is calculated on every AJAX request/submit. See ::buildForm().
    $entity_element = $form_state->get('entity_element');
    /** @var \Drupal\embed\EmbedButtonInterface $embed_button */
    $embed_button = $form_state->get('embed_button');
    /** @var \Drupal\editor\EditorInterface $editor */
    $editor = $form_state->get('editor');
    /** @var \Drupal\Core\Entity\EntityInterface $entity */
    $entity = $form_state->get('entity');
    $values = $form_state->getValues();

    $form['#title'] = $this->t('Embed @type', array('@type' => $entity->getEntityType()->getLowercaseLabel()));

    $entity_label = '';
    try {
      $entity_label = $entity->link();
    }
    catch (\Exception $e) {
      // Construct markup of the link to the entity manually if link() fails.
      // @see https://www.drupal.org/node/2402533
      $entity_label = '<a href="' . $entity->url() . '">' . $entity->label() . '</a>';
    }

    $form['entity'] = array(
      '#type' => 'item',
      '#title' => $this->t('Selected entity'),
      '#markup' => $entity_label,
    );
    $form['attributes']['data-entity-type'] = array(
      '#type' => 'hidden',
      '#value' => $entity_element['data-entity-type'],
    );
    $form['attributes']['data-entity-uuid'] = array(
      '#type' => 'hidden',
      '#value' => $entity_element['data-entity-uuid'],
    );

    // Build the list of allowed Entity Embed Display plugins.
    $display_plugin_options = $this->getDisplayPluginOptions($embed_button, $entity);

    // If the currently selected display is not in the available options,
    // use the first from the list instead. This can happen if an alter
    // hook customizes the list based on the entity.
    if (!isset($display_plugin_options[$entity_element['data-entity-embed-display']])) {
      $entity_element['data-entity-embed-display'] = key($display_plugin_options);
    }

    // The default Entity Embed Display plugin has been deprecated by the
    // rendered entity field formatter.
    if ($entity_element['data-entity-embed-display'] === 'default') {
      $entity_element['data-entity-embed-display'] = 'entity_reference:entity_reference_entity_view';
    }

    $form['attributes']['data-entity-embed-display'] = array(
      '#type' => 'select',
      '#title' => $this->t('Display as'),
      '#options' => $display_plugin_options,
      '#default_value' => $entity_element['data-entity-embed-display'],
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => '::updatePluginConfigurationForm',
        'wrapper' => 'data-entity-embed-settings-wrapper',
        'effect' => 'fade',
      ),
      // Hide the selection if only one option is available.
      '#access' => count($display_plugin_options) > 1,
    );
    $form['attributes']['data-entity-embed-settings'] = array(
      '#type' => 'container',
      '#prefix' => '<div id="data-entity-embed-settings-wrapper">',
      '#suffix' => '</div>',
    );
    $form['attributes']['data-embed-button'] = array(
      '#type' => 'value',
      '#value' => $embed_button->id(),
    );
    $plugin_id = !empty($values['attributes']['data-entity-embed-display']) ? $values['attributes']['data-entity-embed-display'] : $entity_element['data-entity-embed-display'];
    if (!empty($plugin_id)) {
      if (is_string($entity_element['data-entity-embed-settings'])) {
        $entity_element['data-entity-embed-settings'] = Json::decode($entity_element['data-entity-embed-settings']);
      }
      $display = $this->displayPluginManager()->createInstance($plugin_id, $entity_element['data-entity-embed-settings']);
      $display->setContextValue('entity', $entity);
      $display->setAttributes($entity_element);
      $form['attributes']['data-entity-embed-settings'] += $display->buildConfigurationForm($form, $form_state);
    }

    // When Drupal core's filter_align is being used, the text editor may
    // offer the ability to change the alignment.
    if ($editor->getFilterFormat()->filters('filter_align')->status) {
      $form['attributes']['data-align'] = array(
        '#title' => $this->t('Align'),
        '#type' => 'radios',
        '#options' => array(
          '' => $this->t('None'),
          'left' => $this->t('Left'),
          'center' => $this->t('Center'),
          'right' => $this->t('Right'),
        ),
        '#default_value' => isset($entity_element['data-align']) ? $entity_element['data-align'] : '',
        '#wrapper_attributes' => array('class' => array('container-inline')),
        '#attributes' => array('class' => array('container-inline')),
      );
    }

    // When Drupal core's filter_caption is being used, the text editor may
    // offer the ability to add a caption.
    if ($editor->getFilterFormat()->filters('filter_caption')->status) {
      $form['attributes']['data-caption'] = array(
        '#title' => $this->t('Caption'),
        '#type' => 'textfield',
        '#default_value' => isset($entity_element['data-caption']) ? Html::decodeEntities($entity_element['data-caption']) : '',
        '#element_validate' => array('::escapeValue'),
      );
    }

    $form['actions'] = array(
      '#type' => 'actions',
    );
    $form['actions']['back'] = array(
      '#type' => 'submit',
      '#value' => $this->t('Change'),
      // No regular submit-handler. This form only works via JavaScript.
      '#submit' => array(),
      '#ajax' => array(
        'callback' => !empty($this->entityBrowserSettings['display_review']) ? '::submitAndShowReview' : '::submitAndShowSelect',
        'event' => 'click',
      ),
    );
    $form['actions']['save_modal'] = array(
      '#type' => 'submit',
      '#value' => $this-> t('Embed', array(), array('context'=> 'media embed entity')),
      '#button_type' => 'primary',
      // No regular submit-handler. This form only works via JavaScript.
      '#submit' => array(),
      '#ajax' => array(
        'callback' => '::submitEmbedStep',
        'event' => 'click',
      ),
    );

    return $form;
  }

}
