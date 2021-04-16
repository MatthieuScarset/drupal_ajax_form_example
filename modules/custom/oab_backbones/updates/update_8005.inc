<?php

/**
 * UPDATE 8005 - Modification Table Shadow Sites
 */

$schema = \Drupal::database()->schema();

$table_name = 'oab_backbones_shadowsites';


if (!$schema->fieldExists($table_name, 'shadow_code')) {
// First table - Shadow Site
  $schema->addField(
    $table_name,
    'shadow_code',
    [
      'description' => 'Code of the site',
      'type' => 'varchar',
      'length' => 255,
      'not null' => FALSE,
      'default' => '',
    ]
  );
}

$schema->changeField(
  $table_name,
  'sid',
  'sid',
  [
    'description' => 'ID of the site',
    'type' => 'serial',
    'unsigned' => TRUE,
    'not null' => TRUE,
  ]
);


