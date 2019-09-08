<?php

$connection = \Drupal\Core\Database\Database::getConnection();

//mise a jour taxo pour update corps 8.7.0
//taxonomy_term_data
$query = $connection->update('taxonomy_term_data');
$query->fields(['langcode' => 'en']);
$query->condition('tid',900);
$query->execute();

//taxonomy_term_field_data
$query = $connection->update('taxonomy_term_field_data');
$query->fields(['langcode' => 'en']);
$query->condition('tid',900);
$query->execute();

//taxonomy_term__parent
$query = $connection->update('taxonomy_term__parent');
$query->fields(['langcode' => 'en']);
$query->condition('entity_id',900);
$query->execute();

//node__field_hub
$query = $connection->update('node__field_hub');
$query->fields(['langcode' => 'en']);
$query->condition('field_hub_target_id',900);
$query->execute();

//node_revision__field_hub
$query = $connection->update('node_revision__field_hub');
$query->fields(['langcode' => 'en']);
$query->condition('field_hub_target_id',900);
$query->execute();
