<?php

//1. création du rôle
$role = \Drupal\user\Entity\Role::load('fh_backbones');
if(empty($role))
{
  $role = \Drupal\user\Entity\Role::create(array('id' => 'fh_backbones', 'label' => 'FH Backbones'));
  $role->save();
}

//affectation de la permission
$permissions = $role->getPermissions();
if(!in_array('obs_backbones_functional_access',$permissions))
{
  $role->grantPermission('obs_backbones_functional_access');
  $role->save();
}
