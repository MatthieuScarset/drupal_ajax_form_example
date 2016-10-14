<?php

/**
 * Edition de la configuration des migrations
 */
 /******** BLOGPOST ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.blogpost_node');
$config_group->setData(
  array (
    'uuid' => '72c85afd-7085-4a43-be72-4122ea43b951',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'NZtLnyP5CBHu09pjvkrX87MVAOuIpSm9sHIi1fH7D7Q',
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
        'created' => 'created',
        'changed' => 'changed',
        'field_profile' => 'profile_blogger_id',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
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
        'field_state/value' => 'workflow',
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
            1 => 'blogpost_image',
            2 => 'blogpost_media',
            3 => 'blogpost_profile',
          ),
      ),
  ));
$config_group->save(TRUE);
drupal_set_message("Migration Blogpost node changée pour les taxo section", "status");


 /******** MAGAZINE_ARTICLE ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazinearticle_node');
$config_group->setData(
  array (
    'uuid' => '6dcd29ca-ba35-46c3-83a4-986add373913',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'ltuk9LBKw2f1ZWnE17NsWN2c8rpatmD8-HagwPmgN_E',
      ),
    'id' => 'magazinearticle_node',
    'migration_tags' => NULL,
    'migration_group' => 'magazinearticle',
    'label' => 'Magazine articles nodes',
    'source' =>
      array (
        'plugin' => 'magazinearticle_node',
      ),
    'process' =>
      array (
        'created' => 'created',
        'changed' => 'changed',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
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
        'field_magazine' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'categories',
          ),
        'field_industry' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'industries',
          ),
        'field_solution' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'solutions',
          ),
        'field_partner' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'partners',
          ),
        'field_area' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'areas',
          ),
        'field_customer_story' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_term',
            'source' => 'customer_stories',
          ),
        'field_image' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazinearticle_media',
            'source' => 'images',
          ),
        'field_state/value' => 'workflow',
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
            0 => 'magazinearticle_term',
            1 => 'magazinearticle_media',
          ),
      ),
  ));
$config_group->save(TRUE);
drupal_set_message("Migration Magazine Article node changée pour les taxo section", "status");


 /******** MAGAZINE_INTERVIEW ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.magazineinterview_node');
$config_group->setData(
  array (
    'uuid' => 'a17d8b8a-8268-48f3-b823-a48af6c5258c',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'JmlWGPUxkzuLCLU8J1iOZEgnTXO7jPYwr_zpPTpD6ik',
      ),
    'id' => 'magazineinterview_node',
    'migration_tags' => NULL,
    'migration_group' => 'magazineinterview',
    'label' => 'Magazine interviews nodes',
    'source' =>
      array (
        'plugin' => 'magazineinterview_node',
      ),
    'process' =>
      array (
        'created' => 'created',
        'changed' => 'changed',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
        'field_content_field' => 'content_field',
        'field_magazine' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'categories',
          ),
        'field_industry' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'industries',
          ),
        'field_solution' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'solutions',
          ),
        'field_partner' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'partners',
          ),
        'field_area' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'areas',
          ),
        'field_customer_story' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_term',
            'source' => 'customer_stories',
          ),
        'field_image' =>
          array (
            'plugin' => 'migration',
            'migration' => 'magazineinterview_media',
            'source' => 'images',
          ),
        'field_state/value' => 'workflow',
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
            0 => 'magazineinterview_term',
            1 => 'magazineinterview_media',
          ),
      ),
  ));
$config_group->save(TRUE);
drupal_set_message("Migration Magazine Interview node changée pour les taxo section", "status");


 /******** DOCUMENTS ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.document_node');
$config_group->setData(
  array (
    'uuid' => 'f2b6e347-4b89-4174-b231-e5eb2de49e0e',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => '6tDfnQTJsM7nt25u31RmcUndHJ5gDIORIxOoe3XB8Nk',
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
        'created' => 'created',
        'changed' => 'created',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
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
        'field_state/value' => 'workflow',
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
$config_group->save(TRUE);
drupal_set_message("Migration Documents node changée pour les taxo section", "status");


 /******** DOSSIER_PRESSE ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.dossier_presse_node');
$config_group->setData(
  array (
    'uuid' => '124a3f38-033a-4b51-9153-5bdf80f58dc0',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => '_8iXumCVZCQAX6qQtqSWoK2waT8IYGrSCzVdOZyAJoQ',
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
        'created' => 'created',
        'changed' => 'changed',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
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
        'field_state/value' => 'workflow',
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
$config_group->save(TRUE);
drupal_set_message("Migration Dossier de presse node changée pour les taxo section", "status");


 /******** PRESS_RELEASE ********/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration.press_release_node');
$config_group->setData(
  array (
    'uuid' => '3b51d4c0-ef84-40ee-b8a0-392590c4be22',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => '-SKR_KEYig7VRtevywG_zuJO-IhcW1_GwJQwuqt82LY',
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
        'created' => 'created',
        'changed' => 'changed',
        'status' =>
          array (
            'plugin' => 'default_value',
            'default_value' => 1,
          ),
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
        'field_section' => array (
          'plugin' => 'get',
          'source' => 'sections',
        ),
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
        'field_state/value' => 'workflow',
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
$config_group->save(TRUE);
drupal_set_message("Migration Presse release node changée pour les taxo section", "status");

