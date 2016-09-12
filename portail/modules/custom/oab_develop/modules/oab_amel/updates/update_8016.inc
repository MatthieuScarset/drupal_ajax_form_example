<?php

use Drupal\Core\Database\Database;
use \Drupal\Core\Utility\UpdateException;

// Bloc sur-header "Service space" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('system.menu.service-space');
$config->setData(
    array (
        'uuid' => 'ada0a45e-ee5a-4e52-945d-44ef776557b6',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'service-space',
        'label' => 'Service space',
        'description' => 'Espace client pour le site EN',
        'locked' => false,
    ));
$config->save(TRUE);

// Bloc sur-header "Service space" EN
$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.servicespace');
$config->setData(
    array (
        'uuid' => NULL,
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'system.menu.service-space',
                    ),
                'module' =>
                    array (
                        0 => 'language',
                        1 => 'system',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'servicespace',
        'theme' => 'theme_boosted',
        'region' => 'header',
        'weight' => -13,
        'provider' => NULL,
        'plugin' => 'system_menu_block:service-space',
        'settings' =>
            array (
                'id' => 'system_menu_block:service-space',
                'label' => 'Service space',
                'provider' => 'system',
                'label_display' => '0',
                'level' => 1,
                'depth' => 0,
            ),
        'visibility' =>
            array (
                'language' =>
                    array (
                        'id' => 'language',
                        'langcodes' =>
                            array (
                                'en' => 'en',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'language' => '@language.current_language_context:language_interface',
                            ),
                    ),
            ),
    ));
$config->save(TRUE);
