<?php

use Drupal\Core\Database\Database;

$admin_user = \Drupal\user\Entity\User::load(1);
$current_user = \Drupal::getContainer()->get('current_user');
\Drupal::getContainer()->set('current_user', $admin_user);

$connection = Database::getConnection();
$homepages = array(
  array(
    'title' => 'HOMEPAGE EN',
    'path' => '/homepage-en',
    'langcode' => 'en',
    'body' => '<p>content of the homepage</p>'
  ),
  array(
    'title' => 'HOMEPAGE RU',
    'path' => '/homepage-ru',
    'langcode' => 'ru',
    'body' => '<p>Содержание домашней страницы</p>'
  ),
  array(
    'title' => 'HOMEPAGE RU EN',
    'path' => '/homepage-ruen',
    'langcode' => 'ru-en',
    'body' => '<p>content of the homepage</p>'
  )
);
// Création des homepage
foreach ($homepages AS $homepage){
  $node = \Drupal\node\Entity\Node::create(array(
    'type' => 'container',
    'title' => $homepage['title'],
    'uid' => 1,
    'status' => 1,
    'promote' => 0,
    'langcode' => $homepage['langcode'],
    'path' => $homepage['path'],
  ));
  $node->set('field_rendering_model', 4177);
  $node->set('field_state', 'content_workflow_published');
  $node->set('field_content_field', array(
    'value' => $homepage['body'],
    'format' => 'full_html',
    'zone' => 'default'
  ));
  $node->save();

  $query_delete = $connection->delete('config')
    ->condition('collection', 'language.' . $homepage['langcode'])
    ->condition('name', 'system.site')
    ->execute();

  $query_create = $connection->insert('config')
    ->fields(array(
      'collection' => 'language.' . $homepage['langcode'],
      'name' => 'system.site',
      'data' => serialize(array(
        'page' => array(
          'front' => '/node/' . $node->id(),
        ),
      ))
    ))
    ->execute();
}
\Drupal::getContainer()->set('current_user', $current_user);

