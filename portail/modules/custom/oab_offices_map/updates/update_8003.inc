<?php

$role = \Drupal\user\Entity\Role::load('digital_admin');
if(!empty($role)) {
	//affectation de la permission
	$permissions = $role->getPermissions();
	if (!in_array('oab_offices_map_administer', $permissions)) {
		$role->grantPermission('oab_offices_map_administer');
		$role->save();
	}
}