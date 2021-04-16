<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_meta_title');
$config_group->setData(
    array (
        'uuid' => '0f9d4b34-d3d9-40b2-89b5-43116c785951',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.solution',
                    ),
            ),
        'id' => 'node.solution.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'solution',
        'label' => 'Meta title',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
    );
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_meta_title');
$config_group->setData(
    array (
        'uuid' => 'a9f7ebe2-4f04-4eb5-949d-b93e560f1a6d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.industry',
                    ),
            ),
        'id' => 'node.industry.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'industry',
        'label' => 'Meta title',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_meta_title');
$config_group->setData(
    array (
        'uuid' => '3c980f7a-645a-4890-b582-7779bf140bb4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.region',
                    ),
            ),
        'id' => 'node.region.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'region',
        'label' => 'Meta title',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_meta_title');
$config_group->setData(
    array (
        'uuid' => '8a2c1e6f-b3a9-4f9a-813a-40a86fa7b8fd',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_title',
                        1 => 'node.type.country',
                    ),
            ),
        'id' => 'node.country.field_meta_title',
        'field_name' => 'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'country',
        'label' => 'Meta title',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.solution.field_meta_description');
$config_group->setData(
    array (
        'uuid' => 'da2e7c01-47ee-4c4e-ad2c-3d8fce3d94a3',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.solution',
                    ),
            ),
        'id' => 'node.solution.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'solution',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.industry.field_meta_description');
$config_group->setData(
    array (
        'uuid' => '1aa759f6-5ece-4074-9268-33caf0689f3a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.industry',
                    ),
            ),
        'id' => 'node.industry.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'industry',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.region.field_meta_description');
$config_group->setData(
    array (
        'uuid' => 'd2b4e6ab-307a-40be-8dc6-8384717066b7',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.region',
                    ),
            ),
        'id' => 'node.region.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'region',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

$config_group->save(TRUE);
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.country.field_meta_description');
$config_group->setData(
    array (
        'uuid' => 'f6cfbbbe-86d9-4ab1-8139-23a15b94dc67',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_meta_description',
                        1 => 'node.type.country',
                    ),
            ),
        'id' => 'node.country.field_meta_description',
        'field_name' => 'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'country',
        'label' => 'Meta description',
        'description' => '',
        'required' => true,
        'translatable' => true,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);