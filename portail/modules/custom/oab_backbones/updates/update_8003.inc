<?php

//1. création du rôle
$role = \Drupal\user\Entity\Role::load('fh_backbones');
if (empty($role)) {
    $role = \Drupal\user\Entity\Role::create(array('id' => 'fh_backbones', 'label' => 'FH Backbones'));
    $role->save();
    drupal_set_message("Rôle créé", 'status');
}

//affectation de la permission
$permissions = $role->getPermissions();
if (!in_array('obs_backbones_functional_access', $permissions)) {
    $role->grantPermission('obs_backbones_functional_access');
    $role->save();
    drupal_set_message("Permission affectée", 'status');
}

//2. Raccourci
$connection = \Drupal\Core\Database\Database::getConnection();
$query = $connection->select('shortcut_field_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.shortcut_set', 'default')
    ->condition('s.link__uri', 'internal:/admin/obs_backoffice/backbones');

$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

if (empty($results)) {
    $shortcut = \Drupal\shortcut\Entity\Shortcut::create(array(
        'shortcut_set' => 'default',
        'langcode' => 'en',
        'title' => 'Backbones',
        'weight' => '-1',
        'link' => 'internal:/admin/obs_backoffice/backbones',
        'options' => array(),
        'default_langcode' => 1
    ));
    $shortcut->save();
    drupal_set_message("Raccourci créé", 'status');
}
