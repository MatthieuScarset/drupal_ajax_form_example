<?php

/** SET REQUIRED FIELD_BLOG field.field.node.container.field_blog **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.container.field_blog');
$config_group->setData(
    array (
        'uuid' => '89972bcf-7c4b-498b-b9e7-5458f05b6509',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_blog',
                        1 => 'node.type.container',
                        2 => 'taxonomy.vocabulary.blog',
                    ),
            ),
        'id' => 'node.container.field_blog',
        'field_name' => 'field_blog',
        'entity_type' => 'node',
        'bundle' => 'container',
        'label' => 'Blog',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'blog' => 'blog',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    ));
$config_group->save(TRUE);
drupal_set_message("Champ field_blog requis", "status");


/** SET REQUIRED FIELD_MAGAZINE field.field.node.container.field_magazine **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.container.field_magazine');
$config_group->setData(
    array (
        'uuid' => 'ce7e6fac-8e4e-4932-b8a5-755661282620',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_magazine',
                        1 => 'node.type.container',
                        2 => 'taxonomy.vocabulary.magazine',
                    ),
            ),
        'id' => 'node.container.field_magazine',
        'field_name' => 'field_magazine',
        'entity_type' => 'node',
        'bundle' => 'container',
        'label' => 'Magazine',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'magazine' => 'magazine',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    ));
$config_group->save(TRUE);
drupal_set_message("Champ field_magazine requis", "status");

/** SET REQUIRED FIELD_FILE field.field.node.container.field_file **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.container.field_file');
$config_group->setData(
    array (
        'uuid' => 'c961a2a8-23ab-4fd9-9765-a6a12882fc81',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_file',
                        1 => 'media_entity.bundle.file',
                        2 => 'node.type.container',
                    ),
            ),
        'id' => 'node.container.field_file',
        'field_name' => 'field_file',
        'entity_type' => 'node',
        'bundle' => 'container',
        'label' => 'Fichier',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:media',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'file' => 'file',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);
drupal_set_message("Champ field_file requis", "status");

/** SET REQUIRED FIELD_DOCUMENT_TYPE field.field.node.container.field_document_type **/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.container.field_document_type');
$config_group->setData(
    array (
        'uuid' => '409ed832-af0c-484d-8c34-d615faec9129',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_document_type',
                        1 => 'node.type.container',
                        2 => 'taxonomy.vocabulary.document_types',
                    ),
            ),
        'id' => 'node.container.field_document_type',
        'field_name' => 'field_document_type',
        'entity_type' => 'node',
        'bundle' => 'container',
        'label' => 'Document type',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'document_types' => 'document_types',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => '',
                    ),
            ),
        'field_type' => 'entity_reference',
    )
);
$config_group->save(TRUE);
drupal_set_message("Champ field_document_type requis", "status");

