<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.promoactu');
$config_group->setData(
    array (
        'uuid' => '7ecf0d3b-7802-4b8a-bdb2-80c02f40ed3b',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'ctools',
                        1 => 'oab_frontoffice',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'promoactu',
        'theme' => 'theme_boosted',
        'region' => 'sidebar',
        'weight' => 0,
        'provider' => NULL,
        'plugin' => 'promo_actu_block',
        'settings' =>
            array (
                'id' => 'promo_actu_block',
                'label' => 'Promo Actu',
                'provider' => 'oab_frontoffice',
                'label_display' => '0',
                'content' => '',
                'content_format' => 'full_html',
                'context_mapping' =>
                    array (
                        'node' => '@node.node_route_context:node',
                    ),
            ),
        'visibility' =>
            array (
                'entity_bundle:node' =>
                    array (
                        'id' => 'entity_bundle:node',
                        'bundles' =>
                            array (
                                'product' => 'product',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'node' => '@node.node_route_context:node',
                            ),
                    ),
            ),
    )
    );
$config_group->save();