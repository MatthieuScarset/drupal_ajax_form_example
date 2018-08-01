<?php
/**
 * Config des permissions
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.fh_backbones');
$config_group->setData(
    array(
        'uuid' => 'b6bdc89f-6b3a-4f9f-8245-f7e9a8a83f86',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array(),
        'id' => 'fh_backbones',
        'label' => 'FH Backbones',
        'weight' => 7,
        'is_admin' => NULL,
        'permissions' =>
            array(
                0 => 'access shortcuts',
                1 => 'access toolbar',
                2 => 'access user profiles',
                3 => 'obs_backbones_functional_access',
                4 => 'view the administration theme',
            ),
    )
);
$config_group->save(TRUE);