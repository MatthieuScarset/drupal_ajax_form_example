<?php
$role = \Drupal\user\Entity\Role::load('contributor');
if (!empty($role)) {
	//affectation de la permission
	$permissions = $role->getPermissions();
	if (!in_array('create url aliases', $permissions)) {
		$role->grantPermission('create url aliases');
		$role->save();
		drupal_set_message("Permission affectée (changement url alias) au role contributor", 'status');
	}
}