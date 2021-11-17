<?php


use Drupal\block_content\Entity\BlockContent;

$blocks_uuid = [
  'en' => [
    'b6ca0836-27bd-4382-a2ff-b3a6a5440cfa' => '[EN][Contact Button] Standard',
    'a3ad8ae0-2cae-4bd7-bc88-1ca7d7616242' => '[EN][Contact Button] Produits'
  ],
  'fr' => [
    '8483a68b-7342-4044-9099-7206b5910745' => '[FR][Contact Button] Standard',
    '9c1be4d3-c2d4-427d-ac6c-51cbf820dece' => '[FR][Contact Button] Produits'
  ]
];

$block_content_storage = \Drupal::entityTypeManager()->getStorage('block_content');

$created_blocks = 0;
foreach ($blocks_uuid as $lang => $blocks) {
  foreach ($blocks as $uuid => $title) {
    $stored_blocks = $block_content_storage->loadByProperties([
      'uuid' => $uuid
    ]);

    if (!$stored_blocks) {
      BlockContent::create([
        'uuid' => $uuid,
        'info' => $title,
        'type' => 'contact_button'
      ])->save();
      \Drupal::messenger()->addStatus(t("BlockContent %uuid | %title créé", ['%uuid' => $uuid, '%title' => $title]));
      $created_blocks++;
    }
  }
}

if ($created_blocks === 0) {
  \Drupal::messenger()->addStatus("Aucun BlockContent créé");
}


