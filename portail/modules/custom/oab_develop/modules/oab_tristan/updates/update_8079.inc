<?php


## Webform Manager
$role_webform_manager = \Drupal\user\Entity\Role::load('webform_manager');
if ($role_webform_manager === null) {
    $role_webform_manager = \Drupal\user\Entity\Role::create(array('id' => 'webform_manager', 'label' => 'Webform Manager'));
    $role_webform_manager->save();
}
oabt_YmlImport('user.role.webform_manager.yml');


## Webform Business Owner
$role_bo = \Drupal\user\Entity\Role::load('webform_business_owner');
if ($role_bo === null) {
    $role_bo = \Drupal\user\Entity\Role::create(array('id' => 'webform_business_owner', 'label' => 'Webform Business Owner'));
    $role_bo->save();
}
oabt_YmlImport('user.role.webform_business_owner.yml');


## Webform Admin
$role_webform_admin = \Drupal\user\Entity\Role::load('webform_admin');
if ($role_webform_admin === null) {
    $role_webform_admin = \Drupal\user\Entity\Role::create(array('id' => 'webform_admin', 'label' => 'Webform Admin'));
    $role_webform_admin->save();
}
oabt_YmlImport('user.role.webform_admin.yml');


## Webform SPOC Security
$role_spoc = \Drupal\user\Entity\Role::load('webform_spoc_securite');
if ($role_spoc === null) {
    $role_spoc = \Drupal\user\Entity\Role::create(array('id' => 'webform_spoc_securite', 'label' => 'Webform SPOC Sécurité'));
    $role_spoc->save();
}
oabt_YmlImport('user.role.webform_spoc_securite.yml');