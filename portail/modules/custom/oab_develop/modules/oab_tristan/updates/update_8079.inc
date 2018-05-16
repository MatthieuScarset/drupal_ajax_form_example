<?php


## Webform Manager
$role = \Drupal\user\Entity\Role::load('webform_manager');
if ($role === null) {
    $role = \Drupal\user\Entity\Role::create(array('id' => 'webform_manager', 'label' => 'Webform Manager'));
    $role->save();
}
oabt_YmlImport('user.role.webform_manager.yml');


## Webform Business Owner
$role = \Drupal\user\Entity\Role::load('webform_business_owner');
if ($role === null) {
    $role = \Drupal\user\Entity\Role::create(array('id' => 'webform_business_owner', 'label' => 'Webform Business Owner'));
    $role->save();
}
oabt_YmlImport('user.role.webform_business_owner.yml');


## Webform Admin
$role = \Drupal\user\Entity\Role::load('webform_admin');
if ($role === null) {
    $role = \Drupal\user\Entity\Role::create(array('id' => 'webform_admin', 'label' => 'Webform Admin'));
    $role->save();
}
oabt_YmlImport('user.role.webform_admin.yml');


## Webform SPOC Security
$role = \Drupal\user\Entity\Role::load('webform_spoc_securite');
if ($role === null) {
    $role = \Drupal\user\Entity\Role::create(array('id' => 'webform_spoc_securite', 'label' => 'Webform SPOC Sécurité'));
    $role->save();
}
oabt_YmlImport('user.role.webform_spoc_securite.yml');