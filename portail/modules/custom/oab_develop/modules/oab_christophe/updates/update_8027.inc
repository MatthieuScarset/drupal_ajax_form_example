<?php

use Drupal\Core\Database\Database;

$shortcuts = array(
  array('title' => 'Dashboard', 'weight' => '-6', 'link' => 'internal:/admin/content/dashboard'),
  array('title' => 'People', 'weight' => '-5', 'link' => 'internal:/admin/people'),
  array('title' => 'Translations', 'weight' => '-4', 'link' => 'internal:/admin/config/regional/translate'),
  //array('title' => 'variables', 'weight' => '-3', 'link' => 'internal:/admin/content/dashboard'),
  array('title' => 'Taxonomy', 'weight' => '-2', 'link' => 'internal:/admin/structure/taxonomy'),
  array('title' => 'Comments', 'weight' => '-1', 'link' => 'internal:/admin/content/comment')
);

foreach ($shortcuts AS $shortcut){
  $connection = Database::getConnection();
  $query = $connection->select('shortcut_field_data', 's')
    ->fields('s', array('link__uri'))
    ->condition('s.shortcut_set', 'default')
    ->condition('s.link__uri', $shortcut['link']);

  $results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);

  if (empty($results)){
    $shortcut = \Drupal\shortcut\Entity\Shortcut::create(array(
      'shortcut_set' => 'default',
      'langcode' => 'en',
      'title' => $shortcut['title'],
      'weight' => $shortcut['weight'],
      'link' => $shortcut['link'],
      'options' => array(),
      'default_langcode' => 1
    ));
    $shortcut->save();
  }
}
