<?php

use \Drupal\Core\Utility\UpdateException;


/***
 * Création des noeuds pour les pages 404 et 403
 */

$admin_user = \Drupal\user\Entity\User::load(1);
$current_user = \Drupal::getContainer()->get('current_user');
\Drupal::getContainer()->set('current_user', $admin_user);

$pages = array(
  array(
    'type' => '404',
    'title' => '404 FR',
    'path' => '/404-fr',
    'langcode' => 'fr',
    'body' => '<p>Contenu de la page 404</p>'
  ),
  array(
    'type' => '404',
    'title' => '404 EN',
    'path' => '/404-en',
    'langcode' => 'en',
    'body' => '<p>content of the 404 page</p>'
  ),
  array(
    'type' => '404',
    'title' => '404 RU',
    'path' => '/404-ru',
    'langcode' => 'ru',
    'body' => '<p>Содержание страницы 404</p>'
  ),
  array(
    'type' => '404',
    'title' => '404 RU EN',
    'path' => '/404-ruen',
    'langcode' => 'ru-en',
    'body' => '<p>content of the 404 page</p>'
  ),
  array(
    'type' => '403',
    'title' => '403 FR',
    'path' => '/403-fr',
    'langcode' => 'fr',
    'body' => '<p>Contenu de la page 403</p>'
  ),
  array(
    'type' => '403',
    'title' => '403 EN',
    'path' => '/403-en',
    'langcode' => 'en',
    'body' => '<p>content of the 403 page</p>'
  ),
  array(
    'type' => '403',
    'title' => '403 RU',
    'path' => '/403-ru',
    'langcode' => 'ru',
    'body' => '<p>Содержание страницы 403</p>'
  ),
  array(
    'type' => '403',
    'title' => '403 RU EN',
    'path' => '/403-ruen',
    'langcode' => 'ru-en',
    'body' => '<p>content of the 403 page</p>'
  )
);
// Création des pages
foreach ($pages AS $page){
  $node = \Drupal\node\Entity\Node::create(array(
    'type' => 'container',
    'title' => $page['title'],
    'uid' => 1,
    'status' => 1,
    'promote' => 0,
    'langcode' => $page['langcode'],
    'path' => $page['path'],
  ));
  $node->set('field_rendering_model', 4177);
  $node->set('field_state', 'content_workflow_published');
  $node->set('field_content_field', array(
    'value' => $page['body'],
    'format' => 'full_html',
    'zone' => 'default'
  ));
  $node->set('field_metatags', array("value" => serialize(array(
    'robots' => 'noindex'
  ))));
  $node->save();

  $querySelect = \Drupal\Core\Database\Database::getConnection()->select('config', 'c')
    ->fields('c')
    ->condition('name', 'system.site');
  if($page['langcode'] != 'fr'){
    $querySelect = $querySelect->condition('collection', 'language.' . $page['langcode']);
  } else  {
    $querySelect = $querySelect->condition('collection', '');
  }
  $configResult = $querySelect->execute()->fetchAll();

  if(!empty($configResult) && is_array($configResult) && count($configResult) > 0)
  {
    $config = $configResult[0];
    $value = unserialize($config->data);
    $value['page'][$page['type']] = '/node/'.$node->id();

    $queryUpdate = \Drupal\Core\Database\Database::getConnection()->update('config')
      ->fields(['data' => serialize($value)])
      ->condition('name', 'system.site');
    if($page['langcode'] != 'fr'){
      $queryUpdate = $queryUpdate->condition('collection', 'language.' . $page['langcode']);
    } else  {
      $queryUpdate = $queryUpdate->condition('collection', '');
    }
    $queryUpdate->execute();
  }
}
\Drupal::getContainer()->set('current_user', $current_user);