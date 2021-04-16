<?php

use Drupal\Core\Database\Database;
use Drupal\file\Entity\File;

// ajout de l image, on récupère son uuid si existant
$fichierImg = 'mediaembed_update_8020.png';
$connection = Database::getConnection();
$sth = $connection->select('file_managed', 'f')
    ->fields('f', array('uuid'))
    ->condition('f.filename', $fichierImg, '=');
$data = $sth->execute();
$results = $data->fetchAll(\PDO::FETCH_OBJ);

if (count($results) == 0) {
    // on créé le fichier dans Drupal
    $filesystem = \Drupal::service('file_system');
    $pathImg = drupal_get_path('module', 'oab_tibo').'/images/'.$fichierImg;
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
    $file_usage->add($image, 'embed', 'media_button', 'node');
    $image->save();
    $sth = $connection->select('file_managed', 'f')
        ->fields('f', array('uuid'))
        ->condition('f.filename', $fichierImg, '=');

    $data = $sth->execute();
    $results = $data->fetchAll(\PDO::FETCH_OBJ);
}
// on récupère l uuid pour la suite
$uuid = $results[0]->uuid;

// configuration pour embed.button.media_browser
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.media_browser');
$config_group->set('dependencies', array(
    'config' =>
        array (
            0 => 'media_entity.bundle.image',
        ),
    'content' =>
        array (
            0 => 'file:file:'.$uuid,
        ),
    'module' =>
        array (
            0 => 'entity_embed',
            1 => 'media_entity',
        ),
));
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.media_browser');
$config_group->set('type_settings', array(
    'entity_type' => 'media',
    'bundles' =>
        array (
            0 => 'image',
        ),
    'display_plugins' =>
        array (
            0 => 'entity_reference:media_thumbnail',
        ),
    'entity_browser' => 'browse_medias_iframe',
    'entity_browser_settings' =>
        array (
            'display_review' => false,
        ),
));
$config_group->save();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.media_browser');
$config_group->set('icon_uuid', $uuid);
$config_group->save();

//throw new \Drupal\Core\Utility\UpdateException();