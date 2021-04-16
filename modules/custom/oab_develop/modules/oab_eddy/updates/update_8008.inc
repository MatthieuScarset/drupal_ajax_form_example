<?php

$database = \Drupal::database();

$revisionQuery = $database->query('ALTER TABLE `paragraph_revision__field_title` CHANGE `field_title_value` `field_title_value` VARCHAR(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL;');
$fieldQuery = $database->query('ALTER TABLE `paragraph__field_title` CHANGE `field_title_value` `field_title_value` VARCHAR(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL;');
