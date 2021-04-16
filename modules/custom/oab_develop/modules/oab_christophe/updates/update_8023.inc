<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('editor.editor.full_html');
$config_group->set('settings.toolbar.rows.0.0.items', array(
  0 => 'Styles',
  1 => 'FontSize',
  2 => 'lineheight',
  3 => 'Templating',
  4 => 'Solaris',
  5 => 'Templates',
));
$config_group->set('settings.toolbar.rows.0.1.items', array(
  0 => 'Bold',
  1 => 'Italic',
  2 => 'Underline',
  3 => 'TextColor',
  4 => '-',
  5 => 'RemoveFormat',
  6 => 'Blockquote',
  7 => '-',
  8 => 'media_browser',
  9 => 'Table',
  10 => 'VideoEmbed',
  11 => 'HorizontalRule',
  12 => 'BulletedList',
  13 => 'SpecialChar',
  14 => '-',
  15 => 'Outdent',
  16 => 'Indent',
  17 => '-',
  18 => 'JustifyLeft',
  19 => 'JustifyCenter',
  20 => 'JustifyRight',
  21 => 'JustifyBlock',
  22 => '-',
  23 => 'Undo',
  24 => 'Redo',
));
$config_group->save();