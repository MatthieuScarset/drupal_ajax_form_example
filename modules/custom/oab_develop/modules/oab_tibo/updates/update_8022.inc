<?php

$permissionsToAdd = array(
    'create product content',
    'delete any product content',
    'delete own product content',
    'delete product revisions',
    'edit any product content',
    'edit own product content',
    'revert product revisions',
    'view product revisions'
);

$role = \Drupal\user\Entity\Role::load('chief_editor');
if (!empty($role)) {
    $permissions = $role->getPermissions();
    foreach ($permissionsToAdd as $p) {
        if (!in_array($p, $permissions)) {
            $role->grantPermission($p);
            $role->save();
            drupal_set_message("Permission affectée ".$p." au role chief editor", 'status');
        }
    }
}

$role = \Drupal\user\Entity\Role::load('digital_admin');
if (!empty($role)) {
    $permissions = $role->getPermissions();
    foreach ($permissionsToAdd as $p) {
        if (!in_array($p, $permissions)) {
            $role->grantPermission($p);
            $role->save();
            drupal_set_message("Permission affectée ".$p." au role digital admin", 'status');
        }
    }
}