<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.logo_partner');
$config_group->setData(
  array (
    'uuid' => 'a4ead234-865d-44ae-aab3-b8a7defd380b',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'name' => 'logo_partner',
    'label' => 'logo partner',
    'effects' =>
      array (
        'ef2077bb-4168-4d8a-9786-b3e69fc7be3c' =>
          array (
            'uuid' => 'ef2077bb-4168-4d8a-9786-b3e69fc7be3c',
            'id' => 'image_scale',
            'weight' => 1,
            'data' =>
              array (
                'width' => 105,
                'height' => 105,
                'upscale' => false,
              ),
          ),
      ),
  )
);
$config_group->save(TRUE);