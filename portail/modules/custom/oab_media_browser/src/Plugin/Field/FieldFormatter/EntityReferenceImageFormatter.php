<?php

/**
 * @file
 * Contains \Drupal\oab_media_browser\Plugin\Field\FieldFormatter\EntityReferenceImageFormatter.
 */

namespace Drupal\oab_media_browser\Plugin\Field\FieldFormatter;

use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\Plugin\Field\FieldFormatter\EntityReferenceEntityFormatter;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element;
use Drupal\Core\Url;
use Drupal\file\Entity\File;
use Drupal\image\Entity\ImageStyle;

/**
 * Renders any entity reference field as rendered images.
 *
 * Most of this code is copied from the original ImageFormatter class.
 *
 * @FieldFormatter(
 *   id = "entity_reference_image",
 *   label = @Translation("Rendered file entity as Image"),
 *   description = @Translation("Display the referenced file entities as images."),
 *   field_types = {
 *     "entity_reference"
 *   }
 * )
 */
class EntityReferenceImageFormatter extends EntityReferenceEntityFormatter {

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return array(
      'image_style' => '',
    ) + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $image_styles = image_style_options(FALSE);

    \Drupal::configFactory()->getEditable('entity_browser.browser.browse_media_iframe')->getRawData();

    $link_generator = \Drupal::service('link_generator');
    $user = \Drupal::currentUser();

    $element['image_style'] = array(
      '#title' => t('Image style'),
      '#type' => 'select',
      '#default_value' => $this->getSetting('image_style'),
      '#empty_option' => t('None (original image)'),
      '#options' => $image_styles,
      '#description' => array(
        '#markup' => $link_generator->generate($this->t('Configure Image Styles'), new Url('entity.image_style.collection')),
        '#access' => $user->hasPermission('administer image styles'),
      ),
    );

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = array();

    $image_styles = image_style_options(FALSE);

    // Unset possible 'No defined styles' option.
    unset($image_styles['']);
    // Styles could be lost because of enabled/disabled modules that defines
    // their styles in code.
    $image_style_setting = $this->getSetting('image_style');
    if (isset($image_styles[$image_style_setting])) {
      $summary[] = t('Image style: @style', array('@style' => $image_styles[$image_style_setting]));
    }
    else {
      $summary[] = t('Original image');
    }

    return $summary;
  }

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $view_mode = $this->getSetting('view_mode');

    $elements = array();

    foreach ($this->getEntitiesToView($items, $langcode) as $delta => $entity) {
      if ($entity->getEntityType()->id() == 'media'){
        // Protect ourselves from recursive rendering.
        static $depth = 0;
        $depth++;
        if ($depth > 20) {
          $this->loggerFactory->get('entity')->error('Recursive rendering detected when rendering entity @entity_type @entity_id. Aborting rendering.', array('@entity_type' => $entity->getEntityTypeId(), '@entity_id' => $entity->id()));
          return $elements;
        }


        $image_style = $this->getSetting('image_style');
        $field_image = $entity->field_image->getValue();

        if (isset($field_image[0]['target_id'])){
          $file = File::load($field_image[0]['target_id']);

          if (!$image_style) {
            $elements[$delta] = [
              '#theme' => 'image',
              '#width' => $field_image[0]['width'],
              '#height' => $field_image[0]['height'],
              '#style_name' => 'original',
              '#uri' => $file->getFileUri(),
            ];
          }
          else{
            $elements[$delta] = [
              '#theme' => 'image_style',
              '#width' => '',
              '#height' => '',
              '#style_name' => $image_style,
              '#uri' => $file->getFileUri(),
            ];
          }
        }
        $depth = 0;
      }
    }
    return $elements;
  }
}
