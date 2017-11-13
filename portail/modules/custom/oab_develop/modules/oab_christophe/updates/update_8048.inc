<?php

oabt_YmlImport('system.action.oab_backoffice_node_workbench_publish.yml');
oabt_YmlImport('system.action.oab_backoffice_node_workbench_unpublish.yml');
oabt_YmlImport('views.view.content.yml');

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('system.action.node_delete_action', array (
  "label" => "Supprimer le contenu"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('system.action.pathauto_update_alias_node', array (
  "label" => "Mettre à jour l'url alias"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('system.action.oab_backoffice_node_workbench_publish', array (
  "label" => "Publier le contenu"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('system.action.oab_backoffice_node_workbench_unpublish', array (
  "label" => "Dépublier le contenu"
));