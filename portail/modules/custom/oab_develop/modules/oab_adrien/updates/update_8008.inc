<?php

use \Drupal\block_content\Entity\BlockContent;

$new_blocks = [
  [
    'uuid' => 'ea50b916-a069-4fac-a324-bd82a04a5def',
    'language' => 'en',
    'name' => 'Contact CSP EN',
    'type' => 'basic',
  ],
  [
    'uuid' => 'c55c4f20-7284-46c6-9f27-9a5df2395e26',
    'language' => 'fr',
    'name' => 'Contact CSP FR',
    'type' => 'basic'
  ],
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
