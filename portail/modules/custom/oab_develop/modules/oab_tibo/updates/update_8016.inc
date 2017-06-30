<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('editor.editor.full_html');
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
	11 => 'node',
	12 => 'HorizontalRule',
	13 => 'BulletedList',
	14 => 'SpecialChar',
	15 => '-',
	16 => 'Outdent',
	17 => 'Indent',
	18 => '-',
	19 => 'JustifyLeft',
	20 => 'JustifyCenter',
	21 => 'JustifyRight',
	22 => 'JustifyBlock',
	23 => '-',
	24 => 'Undo',
	25 => 'Redo',
));
$config_group->save();

//throw new \Drupal\Core\Utility\UpdateException();