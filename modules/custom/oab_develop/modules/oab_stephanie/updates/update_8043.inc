<?php

/**
 * Suppression de la permission pour administrer les commentaires => pour le rapport de securité
 */
$role = \Drupal\user\Entity\Role::load('chief_editor');
if (!empty($role))
{
	//chargement des permissions
	$permissions = $role->getPermissions();
	if (in_array('administer comments', $permissions)) {
		$role->revokePermission('administer comments');
		$role->save();
		drupal_set_message("Permission supprimée", 'status');
	}
}