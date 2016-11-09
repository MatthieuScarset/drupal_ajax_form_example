<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('password_policy.password_policy.oab_password_policy');
$config_group->setData(
    array (
        'id' => 'oab_password_policy',
        'label' => 'OAB Password Policy',
        'password_reset' => 180,
        'langcode' => 'fr',
        'policy_constraints' =>
            array (
                0 =>
                    array (
                        'id' => 'password_policy_character_constraint',
                        'character_count' => 1,
                        'character_type' => 'uppercase',
                    ),
                1 =>
                    array (
                        'id' => 'password_policy_character_constraint',
                        'character_count' => 1,
                        'character_type' => 'lowercase',
                    ),
                2 =>
                    array (
                        'id' => 'password_policy_character_constraint',
                        'character_count' => 1,
                        'character_type' => 'numeric',
                    ),
                3 =>
                    array (
                        'id' => 'password_policy_character_constraint',
                        'character_count' => 1,
                        'character_type' => 'special',
                    ),
                4 =>
                    array (
                        'id' => 'password_length',
                        'character_length' => 16,
                        'character_operation' => 'minimum',
                    ),
            ),
        'roles' =>
            array (
                'fh_admin' => 'fh_admin',
                'fh_content' => 'fh_content',
                'editor' => 'editor',
            ),
        ));
$config_group->save(TRUE);