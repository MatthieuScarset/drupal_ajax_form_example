<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.action.user_add_role_action.blogger');
$config->setData(
    array (
    'uuid' => '07ad60b9-14d1-4eeb-829c-ac96f05bdbdb',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'user.role.blogger',
                ),
            'module' =>
                array (
                    0 => 'user',
                ),
        ),
    'id' => 'user_add_role_action.blogger',
    'label' => 'Ajouter le rôle Blogger aux utilisateurs sélectionnés',
    'type' => 'user',
    'plugin' => 'user_add_role_action',
    'configuration' =>
        array (
            'rid' => 'blogger',
        ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.action.user_remove_role_action.blogger');
$config->setData(
    array (
        'uuid' => 'e3ff0914-f636-4b54-bf68-cb56a8de0ff4',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'user.role.blogger',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'user_remove_role_action.blogger',
        'label' => 'Retirer le rôle Blogger aux utilisateurs sélectionnés',
        'type' => 'user',
        'plugin' => 'user_remove_role_action',
        'configuration' =>
            array (
                'rid' => 'blogger',
            ),
    ));
$config->save(TRUE);