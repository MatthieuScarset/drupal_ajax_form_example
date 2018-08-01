<?php


//1. création du rôle DVI
$role = \Drupal\user\Entity\Role::load('dvi');
if (empty($role))
{
	$role = \Drupal\user\Entity\Role::create(array('id' => 'dvi', 'label' => 'DVI', 'langcode' => 'en'));
	$role->save();
	drupal_set_message("Rôle DVI créé", 'status');
}

//affectation des  permissions
$permissionsToAdd = array('access administration pages',
	'access browse_media_modal entity browser pages',
	'access browse_medias_iframe entity browser pages',
	'access browser_file_modal entity browser pages',
	'access content overview',
	'access files overview',
	'access in-place editing',
	'access media overview',
	'access shortcuts',
	'access toolbar',
	'access tour',
	'access user profiles',
	'access workbench',
	'administer media',
	'administer scheduled updates',
	'administer scheduled_update display',
	'administer scheduled_update fields',
	'administer scheduled_update form display',
	'administer url aliases',
	'assign roles',
	'create distributor content',
	'create media',
	'create product content',
	'create url aliases',
	'delete all revisions',
	'delete any distributor content',
	'delete any media',
	'delete any product content',
	'delete distributor revisions',
	'delete media',
	'delete own distributor content',
	'delete own product content',
	'delete product revisions',
	'edit any distributor content',
	'edit any product content',
	'edit own distributor content',
	'edit own product content',
	'replicate entities',
	'revert all revisions',
	'revert distributor revisions',
	'revert product revisions',
	'update any media',
	'update media',
	'use archived_published transition',
	'use draft_draft transition',
	'use draft_needs_review transition',
	'use draft_published transition',
	'use needs_review_draft transition',
	'use needs_review_needs_review transition',
	'use needs_review_published transition',
	'use published_archived transition',
	'use published_draft transition',
	'use published_published transition',
	'use text format full_html',
	'view all revisions',
	'view any unpublished content',
	'view distributor revisions',
	'view latest version',
	'view moderation states',
	'view own unpublished content',
	'view product revisions',
	'view scheduled update entities',
	'view the administration theme');
$permissions = $role->getPermissions();
foreach ($permissionsToAdd as $permToAdd) {
	if (!in_array($permToAdd, $permissions))
	{
		$role->grantPermission($permToAdd);
	}
}
drupal_set_message("Permissions affectées", 'status');
$role->save();