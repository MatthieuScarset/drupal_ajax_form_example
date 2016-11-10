<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('replicate_ui.settings');
$config_group->setData(
    array (
        'entity_types' =>
            array (
                0 => 'node',
            ),
        '_core' =>
            array (
                'default_config_hash' => '4HHP96M4EvFXLlTv2x7sF5zHnLIi_Hw_ckmE76MB6r4',
            ),
        'langcode' => 'fr',
    ));
$config_group->save(TRUE);