<?php

use \Drupal\block_content\Entity\BlockContent;

$new_blocks = [
  [
    'uuid' => '5fd49f9f-4404-453d-bf12-a09d01df0b98',
    'language' => 'en',
    'name' => 'IoT Sidebar EN',
    'type' => 'basic',
  ],
  [
    'uuid' => 'c9b875dc-4550-4fd1-abb0-a46a1ae75537',
    'language' => 'fr',
    'name' => 'IoT Sidebar FR',
    'type' => 'basic'
  ],
  [
    'uuid' => 'b3860fd5-d056-4941-8e51-cbdc1201c66e',
    'language' => 'en',
    'name' => 'IoT Banner EN',
    'type' => 'basic'
  ],
  [
    'uuid' => '6e7580fa-a5f6-436c-95e6-10145f5862d4',
    'language' => 'fr',
    'name' => 'IoT Banner FR',
    'type' => 'basic'
  ]
];

foreach ($new_blocks as &$block) {

  /** @var \Drupal\Core\Entity\EntityTypeManager $entity_type_manager */
  $entity_type_manager = \Drupal::entityTypeManager();

  $entity = $entity_type_manager->getStorage('block_content')->loadByProperties(
    [
      'uuid' => $block['uuid'],
      'langcode' => $block['language'],
    ]
  );

  if (!isset($entity) || empty($entity)) {
    $newBlock = BlockContent::create([
      'uuid' => $block['uuid'],
      'langcode' => $block['language'],
      'info' => $block['name'],
      'type' => $block['type']
    ]);
    $newBlock->save();
  }
}
