<?php

use Drupal\Core\Database\Database;

/** Création d'un nouveau Rôle : Blogger */

$data = array('id' => 'blogger', 'label' => 'Blogger');
//creating role
$role = \Drupal\user\Entity\Role::create($data);
//saving role
$role->save();


/** Attribution des permission au nouveau rôle Blogger */
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('user.role.blogger');
$config->setData(
array (
    'uuid' => '7a111929-80bb-4831-aef2-9335863adf91',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
        array (
        ),
    'id' => 'blogger',
    'label' => 'Blogger',
    'weight' => 7,
    'is_admin' => NULL,
    'permissions' =>
        array (
            0 => 'access browse_medias_iframe entity browser pages',
            1 => 'access browser_file_modal entity browser pages',
            2 => 'access browse_media_modal entity browser pages',
            3 => 'access files overview',
            4 => 'use text format basic_html',
            5 => 'use text format full_html',
            6 => 'create media',
            7 => 'delete media',
            8 => 'update media',
            9 => 'access content overview',
            10 => 'administer nodes',
            11 => 'view own unpublished content',
            12 => 'create office content',
            13 => 'edit own office content',
            14 => 'create container content',
            15 => 'edit own container content',
            16 => 'revert container revisions',
            17 => 'view container revisions',
            18 => 'create url aliases',
            19 => 'access in-place editing',
            20 => 'access administration pages',
            21 => 'view the administration theme',
            22 => 'create content_workflow workflow_transition',
        ),
));
$config->save(TRUE);

/** Attribution des permission au nouveau rôle Authenticated  */
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('user.role.blogger');
$config->setData(
array (
    'uuid' => '4774f7bb-1605-47fa-ab00-bd987c34ceeb',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
        array (
        ),
    '_core' =>
        array (
            'default_config_hash' => 'dJ0L2DNSj5q6XVZAGsuVDpJTh5UeYkIPwKrUOOpr8YI',
        ),
    'id' => 'authenticated',
    'label' => 'Authenticated user',
    'weight' => 1,
    'is_admin' => false,
    'permissions' =>
        array (
            0 => 'access content',
            2 => 'access comments',
            3 => 'post comments',
            5 => 'access site-wide contact form',
            6 => 'access shortcuts',
            7 => 'search content',
            8 => 'create processus_1 workflow_transition',
            9 => 'create publication_page_simple workflow_transition',
            10 => 'create workflow_page_simple workflow_transition',
            11 => 'use text format test',
            13 => 'view media',
            14 => 'use text format comments',
            15 => 'create comment_workflow workflow_transition',
        ),
));
$config->save(TRUE);