<?php

use \Drupal\Core\Utility\UpdateException;

/***
 * Fichiers de configuration pour les communiques de presse (press_release)
 */

/*****************************
 * PRESS_RELEASE : MIGRATION GROUP
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration_group.press_release');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'press_release',
        'label' => 'Communiqué de presse Imports',
        'description' => NULL,
        'source_type' => 'Drupal 7',
        'module' => NULL,
        'shared_configuration' =>
            array (
                'source' =>
                    array (
                        'key' => 'drupal7',
                    ),
            ),
    ));
$config_group->save(TRUE);

/*****************************
 * PRESS_RELEASE : FILES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_press_release_file = $config_factory->getEditable('migrate_plus.migration.press_release_file');
$config_press_release_file->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'press_release_file',
        'migration_tags' => NULL,
        'migration_group' => 'press_release',
        'label' => 'Communique presse file',
        'source' =>
            array (
                'plugin' => 'press_release_file',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    )
);
$config_press_release_file->save(TRUE);

/*****************************
 * PRESS_RELEASE : MEDIA
 *****************************/
$config_factory = \Drupal::configFactory();
$config_press_release_media = $config_factory->getEditable('migrate_plus.migration.press_release_media');
$config_press_release_media->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'press_release_media',
        'migration_tags' => NULL,
        'migration_group' => 'press_release',
        'label' => 'Communique presse medias',
        'source' =>
            array (
                'plugin' => 'press_release_media',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'file',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_file',
                        'source' => 'file_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'press_release_file',
                    ),
            ),
    ));
$config_press_release_media->save(TRUE);


/*****************************
 * PRESS_RELEASE : NODES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_press_release_node = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config_press_release_node->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'press_release_node',
        'migration_tags' => NULL,
        'migration_group' => 'press_release',
        'label' => 'Communiqué de presse',
        'source' =>
            array (
                'plugin' => 'press_release_node',
            ),
        'process' =>
            array (
                'type' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'container',
                    ),
                'title' => 'title',
                'langcode' => 'language',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'field_rendering_model/target_id' => 'rendering_model_id',
                'field_content_field/value' => 'content_field',
                'field_content_field/format' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'full_html',
                    ),
                'field_industry' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'industries',
                    ),
                'field_solution' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'solutions',
                    ),
                'field_partner' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'partners',
                    ),
                'field_area' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'areas',
                    ),
                'field_customer_story' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'customer_stories',
                    ),
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_media',
                        'source' => 'files',
                    ),
                'field_short_description' => 'short_description',
                'path' => 'path',
                'field_country' => 'country',
                'field_city' => 'city',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:node',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'press_release_media',
                        1 => 'press_release_term',
                    ),
            ),
    ));
$config_press_release_node->save(TRUE);


/*****************************
 * PRESS_RELEASE : TERMES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_press_release_term = $config_factory->getEditable('migrate_plus.migration.press_release_term');
$config_press_release_term->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'press_release_term',
        'migration_tags' => NULL,
        'migration_group' => 'press_release',
        'label' => 'Communiqués de presse terms',
        'source' =>
            array (
                'plugin' => 'press_release_term',
            ),
        'process' =>
            array (
                'vid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'press_release',
                    ),
                'langcode' => 'language',
                'name' => 'name',
                'parent' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'press_release_term',
                        'source' => 'parent',
                    ),
                'weight' => 'weight',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:taxonomy_term',
            ),
        'migration_dependencies' =>
            array (
            ),
    ));
$config_press_release_term->save(TRUE);


/***
 * Fichiers de configuration pour dossier de presse
 */

/*****************************
 * DOSSIER_PRESSE MIGRATION GROUP
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration_group.dossier_presse');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'dossier_presse',
        'label' => 'Dossier de Presse Imports',
        'description' => NULL,
        'source_type' => 'Drupal 7',
        'module' => NULL,
        'shared_configuration' =>
            array (
                'source' =>
                    array (
                        'key' => 'drupal7',
                    ),
            ),
    ));
$config_group->save(TRUE);

/*****************************
 * DOSSIER PRESSE : FICHIERS
 *****************************/
$config_factory = \Drupal::configFactory();
$config_dossierpresse_file = $config_factory->getEditable('migrate_plus.migration.dossier_presse_file');
$config_dossierpresse_file->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'dossier_presse_file',
        'migration_tags' => NULL,
        'migration_group' => 'dossier_presse',
        'label' => 'Dossier presse file',
        'source' =>
            array (
                'plugin' => 'dossier_presse_file',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    )
);
$config_dossierpresse_file->save(TRUE);

/*****************************
 * DOSSIER PRESSE : MEDIA
 *****************************/
$config_factory = \Drupal::configFactory();
$config_dossierpresse_media = $config_factory->getEditable('migrate_plus.migration.dossier_presse_media');
$config_dossierpresse_media->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'dossier_presse_media',
        'migration_tags' => NULL,
        'migration_group' => 'dossier_presse',
        'label' => 'Dossier presse medias',
        'source' =>
            array (
                'plugin' => 'dossier_presse_media',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'file',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_file',
                        'source' => 'file_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'dossier_presse_file',
                    ),
            ),
    ));
$config_dossierpresse_media->save(TRUE);


/*****************************
 * DOSSIER PRESSE : NODES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_dossierpresse_node = $config_factory->getEditable('migrate_plus.migration.dossier_presse_node');
$config_dossierpresse_node->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'dossier_presse_node',
        'migration_tags' => NULL,
        'migration_group' => 'dossier_presse',
        'label' => 'Dossier presse nodes',
        'source' =>
            array (
                'plugin' => 'dossier_presse_node',
            ),
        'process' =>
            array (
                'type' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'container',
                    ),
                'title' => 'title',
                'langcode' => 'language',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'field_rendering_model/target_id' => 'rendering_model_id',
                'field_content_field/value' => 'content_field',
                'field_content_field/format' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'full_html',
                    ),
                'field_content_field/zone' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'default',
                    ),
                'field_solution' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'solutions',
                    ),
                'field_industry' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'industries',
                    ),
                'field_partner' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'partners',
                    ),
                'field_area' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'areas',
                    ),
                'field_customer_story' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'customer_stories',
                    ),
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_media',
                        'source' => 'files',
                    ),
                'path' => 'path',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:node',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'dossier_presse_term',
                        1 => 'dossier_presse_media',
                    ),
            ),
    ));
$config_dossierpresse_node->save(TRUE);


/*****************************
 * DOSSIER PRESSE : TERMES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_dossierpresse_term = $config_factory->getEditable('migrate_plus.migration.dossier_presse_term');
$config_dossierpresse_term->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'dossier_presse_term',
        'migration_tags' => NULL,
        'migration_group' => 'dossier_presse',
        'label' => 'Dossiers presse terms',
        'source' =>
            array (
                'plugin' => 'dossier_presse_term',
            ),
        'process' =>
            array (
                'vid' => 'vid',
                'langcode' => 'language',
                'name' => 'name',
                'parent' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'dossier_presse_term',
                        'source' => 'parent',
                    ),
                'weight' => 'weight',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:taxonomy_term',
            ),
        'migration_dependencies' =>
            array (
            ),
    ));
$config_dossierpresse_term->save(TRUE);


/***
 * Fichiers de configuration pour document
 */

/*****************************
 * DOCUMENT MIGRATION GROUP
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration_group.document');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document',
        'label' => 'Document Imports',
        'description' => NULL,
        'source_type' => 'Drupal 7',
        'module' => NULL,
        'shared_configuration' =>
            array (
                'source' =>
                    array (
                        'key' => 'drupal7',
                    ),
            ),
    ));
$config_group->save(TRUE);

/*****************************
 * DOCUMENT : IMAGES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_image = $config_factory->getEditable('migrate_plus.migration.document_image');
$config_document_image->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_image',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document images',
        'source' =>
            array (
                'plugin' => 'document_image',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    )
);
$config_document_image->save(TRUE);

/*****************************
 * DOCUMENT : FILES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_file = $config_factory->getEditable('migrate_plus.migration.document_file');
$config_document_file->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_file',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document files',
        'source' =>
            array (
                'plugin' => 'document_file',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    )
);
$config_document_file->save(TRUE);

/*****************************
 * DOCUMENT : MEDIA IMAGE
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_media_image = $config_factory->getEditable('migrate_plus.migration.document_media_image');
$config_document_media_image->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_media_image',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document image medias',
        'source' =>
            array (
                'plugin' => 'document_media_image',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'image',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_image',
                        'source' => 'image_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'document_image',
                    ),
            ),
    ));
$config_document_media_image->save(TRUE);

/*****************************
 * DOCUMENT : MEDIA FILE
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_media_file = $config_factory->getEditable('migrate_plus.migration.document_media_file');
$config_document_media_file->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_media_file',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document files medias',
        'source' =>
            array (
                'plugin' => 'document_media_file',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'file',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_file',
                        'source' => 'file_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'document_file',
                    ),
            ),
    ));
$config_document_media_file->save(TRUE);

/*****************************
 * DOCUMENT : NODES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_node = $config_factory->getEditable('migrate_plus.migration.document_node');
$config_document_node->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_node',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document',
        'source' =>
            array (
                'plugin' => 'document_node',
            ),
        'process' =>
            array (
                'type' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'container',
                    ),
                'title' => 'title',
                'langcode' => 'language',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'field_rendering_model/target_id' => 'rendering_model_id',
                'field_content_field/value' => 'content_field',
                'field_content_field/format' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'full_html',
                    ),
                'field_content_field/zone' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'default',
                    ),
                'field_document_type' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'document_types',
                    ),
                'field_topic' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'topics',
                    ),
                'field_solution' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'solutions',
                    ),
                'field_industry' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'industries',
                    ),
                'field_partner' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'partners',
                    ),
                'field_area' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'areas',
                    ),
                'field_customer_story' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'customer_stories',
                    ),
                'field_file' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_media_file',
                        'source' => 'files',
                    ),
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_media_image',
                        'source' => 'images',
                    ),
                'path' => 'path',
                'field_subtitle' => 'subtitle',
                'field_short_description' => 'short_description',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:node',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'document_media_file',
                        1 => 'document_media_image',
                        2 => 'document_term',
                    ),
            ),
    ));
$config_document_node->save(TRUE);


/*****************************
 * DOCUMENT : TERMES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_document_term = $config_factory->getEditable('migrate_plus.migration.document_term');
$config_document_term->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'document_term',
        'migration_tags' => NULL,
        'migration_group' => 'document',
        'label' => 'Document terms',
        'source' =>
            array (
                'plugin' => 'document_term',
            ),
        'process' =>
            array (
                'vid' => 'vid',
                'langcode' => 'language',
                'name' => 'name',
                'parent' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'document_term',
                        'source' => 'parent',
                    ),
                'weight' => 'weight',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:taxonomy_term',
            ),
        'migration_dependencies' =>
            array (
            ),
    ));
$config_document_term->save(TRUE);


/***
 * Fichiers de configuration pour les blog posts
 */

/*****************************
 *  BLOGPOST MIGRATION GROUP
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration_group.blogpost');
$config_group->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost',
        'label' => 'Blog post Imports',
        'description' => NULL,
        'source_type' => 'Drupal 7',
        'module' => NULL,
        'shared_configuration' =>
            array (
                'source' =>
                    array (
                        'key' => 'drupal7',
                    ),
            ),
    ));
$config_group->save(TRUE);

/*****************************
 * BLOGPOST : IMAGES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_image = $config_factory->getEditable('migrate_plus.migration.blogpost_image');
$config_blogpost_image->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_image',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts images',
        'source' =>
            array (
                'plugin' => 'blogpost_image',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    )
);
$config_blogpost_image->save(TRUE);

/*****************************
 * BLOGPOST : MEDIA
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_media = $config_factory->getEditable('migrate_plus.migration.blogpost_media');
$config_blogpost_media->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_media',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts medias',
        'source' =>
            array (
                'plugin' => 'blogpost_media',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'image',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_image',
                        'source' => 'image_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'blogpost_image',
                    ),
            ),
    ));
$config_blogpost_media->save(TRUE);


/*****************************
 * BLOGPOST : NODES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_node = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config_blogpost_node->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_node',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts nodes',
        'source' =>
            array (
                'plugin' => 'blogpost_node',
            ),
        'process' =>
            array (
                'type' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'container',
                    ),
                'title' => 'title',
                'langcode' => 'language',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'field_type/target_id' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 7,
                    ),
                'field_rendering_model/target_id' => 'rendering_model_id',
                'field_content_field/value' => 'content_field',
                'field_content_field/format' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'full_html',
                    ),
                'field_content_field/zone' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'default',
                    ),
                'field_blog' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'categories',
                    ),
                'field_solution' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'solutions',
                    ),
                'field_industry' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'industries',
                    ),
                'field_partner' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'partners',
                    ),
                'field_area' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'areas',
                    ),
                'field_customer_story' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'customer_stories',
                    ),
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_media',
                        'source' => 'images',
                    ),
                'path' => 'path',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:node',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'blogpost_term',
                        1 => 'blogpost_media',
                        2 => 'blogpost_profile',
                    ),
            ),
    ));
$config_blogpost_node->save(TRUE);


/*****************************
 * BLOGPOST : TERMES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_term = $config_factory->getEditable('migrate_plus.migration.blogpost_term');
$config_blogpost_term->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_term',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog post terms',
        'source' =>
            array (
                'plugin' => 'blogpost_term',
            ),
        'process' =>
            array (
                'vid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'blogpost',
                    ),
                'langcode' => 'language',
                'name' => 'name',
                'parent' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_term',
                        'source' => 'parent',
                    ),
                'weight' => 'weight',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:taxonomy_term',
            ),
        'migration_dependencies' =>
            array (
            ),
    ));
$config_blogpost_term->save(TRUE);


/*****************************
 * BLOGPOST : PROFILES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_profile = $config_factory->getEditable('migrate_plus.migration.blogpost_profile');
$config_blogpost_profile->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_profile',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts profiles',
        'source' =>
            array (
                'plugin' => 'blogpost_profile',
            ),
        'process' =>
            array (
                'type' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'profil_redacteur',
                    ),
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'langcode' => 'langcode',
                'title' => 'title',
                'body/value' => 'field_txt_catcher',
                'field_first_name/value' => 'field_first_name',
                'field_last_name/value' => 'field_last_name',
                'field_job/value' => 'field_profil',
                'field_social_accounts' => 'field_social_accounts',
                'field_location/value' => 'field_location',
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_profile_media',
                        'source' => 'images',
                    ),
                'path' => 'path',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:node',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'blogpost_profile_media',
                    ),
            ),
    ));
$config_blogpost_profile->save(TRUE);

/*****************************
 * BLOGPOST : PROFILES IMAGE
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_profile_image = $config_factory->getEditable('migrate_plus.migration.blogpost_profile_image');
$config_blogpost_profile_image->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_profile_image',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts profile images',
        'source' =>
            array (
                'plugin' => 'blogpost_profile_image',
            ),
        'process' =>
            array (
                'langcode' => 'langcode',
                'uid' => 'uid',
                'filename' => 'filename',
                'uri' => 'uri',
                'filemime' => 'filemime',
                'filesize' => 'filesize',
                'status' => 'status',
                'created' => 'timestamp',
                'changed' => 'timestamp',
            ),
        'destination' =>
            array (
                'plugin' => 'entity:file',
            ),
        'migration_dependencies' =>
            array (
            ),
    ));
$config_blogpost_profile_image->save(TRUE);

/*****************************
 * BLOGPOST : PROFILES MEDIAS
 *****************************/
$config_factory = \Drupal::configFactory();
$config_blogpost_profile_media = $config_factory->getEditable('migrate_plus.migration.blogpost_profile_media');
$config_blogpost_profile_media->setData(
    array (
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'blogpost_profile_media',
        'migration_tags' => NULL,
        'migration_group' => 'blogpost',
        'label' => 'Blog posts profile medias',
        'source' =>
            array (
                'plugin' => 'blogpost_profile_media',
            ),
        'process' =>
            array (
                'bundle' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'image',
                    ),
                'langcode' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 'und',
                    ),
                'name' => 'filename',
                'uid' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'status' =>
                    array (
                        'plugin' => 'default_value',
                        'default_value' => 1,
                    ),
                'created' => 'timestamp',
                'changed' => 'timestamp',
                'field_image' =>
                    array (
                        'plugin' => 'migration',
                        'migration' => 'blogpost_profile_image',
                        'source' => 'image_info',
                    ),
            ),
        'destination' =>
            array (
                'plugin' => 'entity:media',
            ),
        'migration_dependencies' =>
            array (
                'required' =>
                    array (
                        0 => 'blogpost_profile_image',
                    ),
            ),
    ));
$config_blogpost_profile_media->save(TRUE);

return '';
//throw new UpdateException();