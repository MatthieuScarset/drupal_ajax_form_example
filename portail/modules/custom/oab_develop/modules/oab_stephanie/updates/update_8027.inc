<?php


/**
 * Ajout module Simplify et configuration de ce dernier
 */

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config_comment = $config_factory->getEditable('simplify.global');
$config_comment->setData(
  array (
    'simplify_admin' => false,
    'simplify_nodes_global' =>
      array (
        'author' => '0',
        'format' => '0',
        'options' => '0',
        'revision_information' => '0',
        'comment' => '0',
        'menu' => '0',
        'path_settings' => '0',
        'metatags' => '0',
        'redirect' => '0',
      ),
    'simplify_users_global' =>
      array (
        'format' => '0',
        'status' => '0',
        'timezone' => '0',
        'contact' => '0',
        'metatags' => '0',
        'redirect' => '0',
      ),
    'simplify_comments_global' =>
      array (
        'format' => 'format',
      ),
    'simplify_taxonomies_global' =>
      array (
        'format' => '0',
        'relations' => '0',
        'path' => '0',
        'metatags' => '0',
        'redirect' => '0',
      ),
    'simplify_blocks_global' =>
      array (
        'format' => '0',
        'revision_information' => '0',
      ),
    'simplify_profiles_global' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'omWr4s_-ZB9DeG-rP5oY4s3Pm2uiK-guRhGg0_DHHpM',
      ),
    'langcode' => 'fr',
  )
  );
$config_comment->save(TRUE);