<?php

/**
 * Ajout du block pour le message des cookies
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.cookiecomplianceblock');
$config_group->setData(
    array (
        'uuid' => 'cdf36242-92dd-43d4-8766-514000b1e912',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'oab_cookie_compliance',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'cookiecomplianceblock',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -42,
        'provider' => NULL,
        'plugin' => 'cookie_compliance_block',
        'settings' =>
            array (
                'id' => 'cookie_compliance_block',
                'label' => 'Cookie compliance Block',
                'provider' => 'oab_cookie_compliance',
                'label_display' => '0',
            ),
        'visibility' =>
            array (
            ),
    )
);
$config_group->save(TRUE);
