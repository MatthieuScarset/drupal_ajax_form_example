<?php

use \Drupal\Core\Utility\UpdateException;

/***
 * Fichiers de configuration pour magazine interview
 */

/*****************************
 * MIGRATION GROUP
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('migrate_plus.migration_group.magazineinterview');
$config_group->setData(
              array (
                'langcode' => 'fr',
                'status' => true,
                'dependencies' =>
                  array (
                  ),
                'id' => 'magazineinterview',
                'label' => 'Magazine interviews Imports',
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
 * MAGAZINE INTERVIEW : IMAGES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_maginter_image = $config_factory->getEditable('migrate_plus.migration.magazineinterview_image');
$config_maginter_image->setData(
              array (
                'langcode' => 'fr',
                'status' => true,
                'dependencies' =>
                  array (
                  ),
                'id' => 'magazineinterview_image',
                'migration_tags' => NULL,
                'migration_group' => 'magazineinterview',
                'label' => 'Magazine interviews images',
                'source' =>
                  array (
                    'plugin' => 'magazineinterview_image',
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
$config_maginter_image->save(TRUE);

/*****************************
 * MAGAZINE INTERVIEW : MEDIA
 *****************************/
$config_factory = \Drupal::configFactory();
$config_maginter_media = $config_factory->getEditable('migrate_plus.migration.magazineinterview_media');
$config_maginter_media->setData(
              array (
                'langcode' => 'fr',
                'status' => true,
                'dependencies' =>
                  array (
                  ),
                'id' => 'magazineinterview_media',
                'migration_tags' => NULL,
                'migration_group' => 'magazineinterview',
                'label' => 'Magazine interviews medias',
                'source' =>
                  array (
                    'plugin' => 'magazineinterview_media',
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
                        'migration' => 'magazineinterview_image',
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
                        0 => 'magazineinterview_image',
                      ),
                  ),
              ));
$config_maginter_media->save(TRUE);


/*****************************
 * MAGAZINE INTERVIEW : NODES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_maginter_node = $config_factory->getEditable('migrate_plus.migration.magazineinterview_node');
$config_maginter_node->setData(
                    array (
                      'langcode' => 'fr',
                      'status' => true,
                      'dependencies' =>
                        array (
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
$config_maginter_node->save(TRUE);


/*****************************
 * MAGAZINE INTERVIEW : TERMES
 *****************************/
$config_factory = \Drupal::configFactory();
$config_maginter_termes = $config_factory->getEditable('migrate_plus.migration.magazineinterview_term');
$config_maginter_termes->setData(
                    array (
                      'langcode' => 'fr',
                      'status' => true,
                      'dependencies' =>
                        array (
                        ),
                      'id' => 'magazineinterview_term',
                      'migration_tags' => NULL,
                      'migration_group' => 'magazineinterview',
                      'label' => 'Magazine interview terms',
                      'source' =>
                        array (
                          'plugin' => 'magazineinterview_term',
                        ),
                      'process' =>
                        array (
                          'vid' => 'vid',
                          'langcode' => 'language',
                          'name' => 'name',
                          'parent' =>
                            array (
                              'plugin' => 'migration',
                              'migration' => 'magazineinterview_term',
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
$config_maginter_termes->save(TRUE);
return '';
//throw new UpdateException();