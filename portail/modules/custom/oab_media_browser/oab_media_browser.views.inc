<?php

/**
 * @file
 * Provide custom views data for rendering file previews.
 */

/**
 * Implements hook_views_data_alter().
 */
function oab_media_browser_views_data_alter(&$data) {
  $data['file_managed']['oab_media_browser_preview'] = array(
    'title' => t('File Browser Preview'),
    'help' => t('Displays a preview of a file.'),
    'field' => array(
      'id' => 'oab_media_browser_preview',
    ),
  );
}
