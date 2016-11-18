<?php

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('migrate_plus.migration.blogpost_comment');
$config_comment->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'id' => 'blogpost_comment',
    'migration_group' => 'blogpost',
    'label' => 'Blog posts comments',
    'source' =>
      array (
        'plugin' => 'blogpost_comment',
      ),
    'destination' =>
      array (
        'plugin' => 'entity:comment',
      ),
    'process' =>
      array (
        'comment_type' => array (
          'plugin' => 'default_value',
          'default_value' => 'comment'
        ),
        'pid' => 'pid_parent',
        'entity_id' => array (
          'plugin' => 'migration',
          'migration' => 'blogpost_node',
          'source' => 'nid'
        ),
        'entity_type' => array (
          'plugin' => 'default_value',
          'default_value' => 'node'
        ),
        'field_name' => array (
          'plugin' => 'default_value',
          'default_value' => 'field_commentaire'
        ),
        'uid' => 'uid',
        'subject' => 'subject',
        'hostname' => 'hostname',
        'created' => 'created',
        'changed' => 'changed',
        'status' => 'status',
        'thread' => 'thread',
        'name' => 'name',
        'mail' => 'mail',
        'homepage' => 'homepage',
        'langcode' => 'language',
        'default_langcode' => 'default_langcode',
        'comment_body/value' => 'comment_body_value',
        'comment_body/format' => 'comment_body_format'
      ),

    'migration_dependencies' =>
      array (
        'required' =>
          array (
            0 => 'blogpost_node'
          ),
      ),
  ));
$config_comment->save(TRUE);