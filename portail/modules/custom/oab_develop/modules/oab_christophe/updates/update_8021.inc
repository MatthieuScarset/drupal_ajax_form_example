<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('editor.editor.full_html');
$config_group->set('settings.toolbar.rows.0.0.items', array(
  0 => 'Styles',
  1 => 'FontSize',
  2 => 'Templating',
  3 => 'Solaris',
  4 => 'Templates',
));
$config_group->save();