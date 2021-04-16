<?php

$connection = \Drupal\Core\Database\Database::getConnection();

// suppression de l entrée block.block.topzoneblock dans la table config
$query_delete = $connection->delete('config')
    ->condition('name', 'block.block.topzoneblock')
    ->execute();

