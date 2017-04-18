<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.media.image.default');
$config_group->setData(
    array (
        'uuid' => '4398d76c-af4f-4fd6-a8ef-cd213bb0daf4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.media.image.field_image',
                        1 => 'field.field.media.image.field_tags',
                        2 => 'field.field.media.image.field_thematic',
                        3 => 'media_entity.bundle.image',
                    ),
                'module' =>
                    array (
                        0 => 'image',
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
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_link' => '',
                                'image_style' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
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
    )
);
$config_group->save(TRUE);