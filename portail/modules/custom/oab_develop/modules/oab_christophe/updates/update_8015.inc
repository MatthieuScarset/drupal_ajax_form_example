<?php

\Drupal::service('module_installer')->install(array('responsive_image'), true);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('embed.button.media_browser');
$config->set('type_settings', array (
  'entity_type' => 'media',
  'bundles' =>
    array (
      0 => 'image',
    ),
  'display_plugins' =>
    array (
      0 => 'entity_reference:entity_reference_entity_view',
    ),
  'entity_browser' => 'browse_medias_iframe',
  'entity_browser_settings' =>
    array (
      'display_review' => false,
    ),
));


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.media.image.default');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.media.image.field_image',
          1 => 'field.field.media.image.field_tags',
          2 => 'field.field.media.image.field_thematic',
          3 => 'media_entity.bundle.image',
          4 => 'responsive_image.styles.wide',
        ),
      'module' =>
        array (
          0 => 'responsive_image',
        ),
    ),
  'id' => 'media.image.default',
  'targetEntityType' => 'media',
  'bundle' => 'image',
  'mode' => 'default',
  'content' =>
    array (
      'field_image' =>
        array (
          'weight' => 2,
          'label' => 'above',
          'settings' =>
            array (
              'responsive_image_style' => 'wide',
              'image_link' => '',
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'responsive_image',
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'field_tags' => true,
      'field_thematic' => true,
      'langcode' => true,
      'name' => true,
      'thumbnail' => true,
      'uid' => true,
    ),
));


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('core.entity_view_display.media.image.teaser');
$config->setData(array (
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.media.teaser',
          1 => 'field.field.media.image.field_image',
          2 => 'field.field.media.image.field_tags',
          3 => 'field.field.media.image.field_thematic',
          4 => 'media_entity.bundle.image',
          5 => 'responsive_image.styles.narrow',
        ),
      'module' =>
        array (
          0 => 'responsive_image',
        ),
    ),
  'id' => 'media.image.teaser',
  'targetEntityType' => 'media',
  'bundle' => 'image',
  'mode' => 'teaser',
  'content' =>
    array (
      'thumbnail' =>
        array (
          'type' => 'responsive_image',
          'weight' => 1,
          'label' => 'visually_hidden',
          'settings' =>
            array (
              'responsive_image_style' => 'narrow',
              'image_link' => '',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'field_image' => true,
      'field_tags' => true,
      'field_thematic' => true,
      'langcode' => true,
      'name' => true,
      'uid' => true,
    ),
));

//throw new \Drupal\Core\Utility\UpdateException();