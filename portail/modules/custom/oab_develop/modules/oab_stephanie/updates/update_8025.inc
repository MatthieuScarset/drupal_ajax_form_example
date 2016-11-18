<?php

use \Drupal\Core\Utility\UpdateException;

/**
 * Ajout format texte Comments
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('filter.format.comments');
$config_group->setData(
  array (
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'editor',
            1 => 'entity_embed',
          ),
      ),
    'name' => 'Comments',
    'format' => 'comments',
    'weight' => 0,
    'filters' =>
      array (
        'editor_file_reference' =>
          array (
            'id' => 'editor_file_reference',
            'provider' => 'editor',
            'status' => false,
            'weight' => -46,
            'settings' =>
              array (
              ),
          ),
        'entity_embed' =>
          array (
            'id' => 'entity_embed',
            'provider' => 'entity_embed',
            'status' => false,
            'weight' => -45,
            'settings' =>
              array (
              ),
          ),
        'filter_align' =>
          array (
            'id' => 'filter_align',
            'provider' => 'filter',
            'status' => false,
            'weight' => -44,
            'settings' =>
              array (
              ),
          ),
        'filter_autop' =>
          array (
            'id' => 'filter_autop',
            'provider' => 'filter',
            'status' => true,
            'weight' => -49,
            'settings' =>
              array (
              ),
          ),
        'filter_caption' =>
          array (
            'id' => 'filter_caption',
            'provider' => 'filter',
            'status' => false,
            'weight' => -43,
            'settings' =>
              array (
              ),
          ),
        'filter_html' =>
          array (
            'id' => 'filter_html',
            'provider' => 'filter',
            'status' => true,
            'weight' => -48,
            'settings' =>
              array (
                'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <br>',
                'filter_html_help' => true,
                'filter_html_nofollow' => false,
              ),
          ),
        'filter_htmlcorrector' =>
          array (
            'id' => 'filter_htmlcorrector',
            'provider' => 'filter',
            'status' => false,
            'weight' => -41,
            'settings' =>
              array (
              ),
          ),
        'filter_html_escape' =>
          array (
            'id' => 'filter_html_escape',
            'provider' => 'filter',
            'status' => false,
            'weight' => -47,
            'settings' =>
              array (
              ),
          ),
        'filter_html_image_secure' =>
          array (
            'id' => 'filter_html_image_secure',
            'provider' => 'filter',
            'status' => false,
            'weight' => -42,
            'settings' =>
              array (
              ),
          ),
        'filter_url' =>
          array (
            'id' => 'filter_url',
            'provider' => 'filter',
            'status' => true,
            'weight' => -50,
            'settings' =>
              array (
                'filter_url_length' => 72,
              ),
          ),
      ),
  ));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.anonymous');
$config_group->setData(
  array (
    'uuid' => NULL,
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'j5zLMOdJBqC0bMvSdth5UebkprJB8g_2FXHqhfpJzow',
      ),
    'id' => 'anonymous',
    'label' => 'Anonymous user',
    'weight' => 0,
    'is_admin' => false,
    'permissions' =>
      array (
        0 => 'access content',
        1 => 'use text format restricted_html',
        2 => 'access comments',
        3 => 'access site-wide contact form',
        4 => 'search content',
        5 => 'create processus_1 workflow_transition',
        6 => 'create publication_page_simple workflow_transition',
        7 => 'create workflow_page_simple workflow_transition',
        8 => 'view media',
        10 => 'post comments',
        11 => 'use text format comments',
      ),
  ));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.authenticated');
$config_group->setData(
  array (
    'uuid' => '4774f7bb-1605-47fa-ab00-bd987c34ceeb',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    '_core' =>
      array (
        'default_config_hash' => 'dJ0L2DNSj5q6XVZAGsuVDpJTh5UeYkIPwKrUOOpr8YI',
      ),
    'id' => 'authenticated',
    'label' => 'Authenticated user',
    'weight' => 1,
    'is_admin' => false,
    'permissions' =>
      array (
        0 => 'access content',
        2 => 'access comments',
        3 => 'post comments',
        4 => 'skip comment approval',
        5 => 'access site-wide contact form',
        6 => 'access shortcuts',
        7 => 'search content',
        8 => 'create processus_1 workflow_transition',
        9 => 'create publication_page_simple workflow_transition',
        10 => 'create workflow_page_simple workflow_transition',
        11 => 'use text format test',
        13 => 'view media',
        14 => 'use text format comments',
      ),
  ));
$config_group->save(TRUE);