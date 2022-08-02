<?php

$role = \Drupal\user\Entity\Role::load('siu_user');
if (empty($role)) {
  $role = \Drupal\user\Entity\Role::create(array('id' => 'siu_user', 'label' => 'SIU User'));
  $role->grantPermission('access-mss-assistance');
  $role->save();
  \Drupal::messenger()->addMessage("Rôle 'SIU User' créé", 'status');
}
