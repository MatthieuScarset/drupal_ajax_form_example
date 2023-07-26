<?php

use Drupal\Core\Database\Database;
use Drupal\file\Entity\File;

// ajout de l image, on récupère son uuid si existant
$fichierImg = 'nodeembed_update_8016.png';
$connection = Database::getConnection();
$sth = $connection->select('file_managed', 'f')
                  ->fields('f', array('uuid'))
                  ->condition('f.filename', $fichierImg, '=');
$data = $sth->execute();
$results = $data->fetchAll(\PDO::FETCH_OBJ);

if (count($results) == 0) {
	// on créé le fichier dans Drupal
	$filesystem = \Drupal::service('file_system');
//	$pathImg = drupal_get_path('module', 'oab_tibo').'/images/'.$fichierImg;
// Correction depréciation juste pour exemple
  $pathImg = \Drupal::service('extension.path.resolver')
    ->getPath('module', 'oab_tibo').'/images/'.$fichierImg;
	// Create file entity.
	$image = File::create();
	$image->setFileUri($pathImg);
	$image->setOwnerId(\Drupal::currentUser()->id());
	$image->setMimeType('image/' . pathinfo($pathImg, PATHINFO_EXTENSION));
	$image->setFileName($filesystem->basename($pathImg));
	$image->setSize(filesize($pathImg));
	$image->setPermanent();
	$image->save();
	// enregistrement dans file_usage
	$file_usage = \Drupal::service('file.usage');
	$file_usage->add($image, 'embed', 'embed_button', 'node');
	$image->save();
	$sth = $connection->select('file_managed', 'f')
	                  ->fields('f', array('uuid'))
	                  ->condition('f.filename', $fichierImg, '=');

	$data = $sth->execute();
	$results = $data->fetchAll(\PDO::FETCH_OBJ);
}
// on récupère l uuid pour la suite
$uuid = $results[0]->uuid;

// display special pour le node embed
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.node.wysiwyg_node_embed');
$config_group->setData(
	array (
		'uuid' => 'fe78fd7e-cdc3-4998-ad3d-73b0555197fc',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'node',
					),
			),
		'id' => 'node.wysiwyg_node_embed',
		'label' => 'Wysiwyg node embed',
		'targetEntityType' => 'node',
		'cache' => true,
	)
);
$config_group->save(TRUE);

\Drupal::keyValue('config.entity.key_store.entity_view_mode')->set('uuid:fe78fd7e-cdc3-4998-ad3d-73b0555197fc', array (
	0 => 'core.entity_view_mode.node.wysiwyg_node_embed',
));

// configuration pour embed.button.node
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.node');
$config_group->set('dependencies', array(
	'config' =>
		array (
			0 => 'node.type.country',
			1 => 'node.type.industry',
			2 => 'node.type.region',
			3 => 'node.type.solution',
		),
	'content' =>
		array (
			0 => 'file:file:'.$uuid,
		),
	'module' =>
		array (
			0 => 'entity_embed',
			1 => 'node',
		),
));
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.node');
$config_group->set('type_settings', array(
	'entity_type' => 'node',
	'bundles' =>
		array (
			0 => 'industry',
			1 => 'country',
			2 => 'region',
			3 => 'solution',
		),
	'display_plugins' =>
		array (
			0 => 'view_mode:node.wysiwyg_node_embed',
		),
	'entity_browser' => '',
	'entity_browser_settings' =>
		array (
			'display_review' => false,
		),
));
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.node');
$config_group->set('icon_uuid', $uuid);
$config_group->save();

// ajout du node embed dans le full html editor
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
