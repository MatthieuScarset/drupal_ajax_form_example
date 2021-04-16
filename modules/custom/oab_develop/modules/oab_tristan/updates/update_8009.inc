<?php

/**
 * Je cache la petite loupe du right icon block pour les petits et moyens ecrans
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.righticonblock');
$config_group->setData(
  array (
    'uuid' => 'a21c0682-9a50-48ca-88bd-86abd4af85d7',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'oab_frontoffice',
          ),
        'theme' =>
          array (
            0 => 'theme_boosted',
          ),
      ),
    'id' => 'righticonblock',
    'theme' => 'theme_boosted',
    'region' => 'header',
    'weight' => -5,
    'provider' => NULL,
    'plugin' => 'right_icon_block',
    'settings' =>
      array (
        'id' => 'right_icon_block',
        'label' => 'Right icon Block',
        'provider' => 'oab_frontoffice',
        'label_display' => '0',
        'right_icon_custom_text' =>
          array (
            'value' => '<p><span aria-hidden="true" class="glyphicon glyphicon-search" data-target="#search-form" data-toggle="collapse" font-size="2em"></span><span aria-hidden="true" class="align-right icon icon-share hidden-xs hidden-sm" data-target="#social-share" data-toggle="collapse"></span></p>',
            'format' => 'full_html',
          ),
      ),
    'visibility' =>
      array (
      ),
  )
);
$config_group->save(TRUE);
