<?php

use \Drupal\Core\Utility\UpdateException;

$connection = \Drupal\Core\Database\Database::getConnection();

//Document type
$doc_query = $connection->select('taxonomy_term_field_data', 'ttd');
$doc_query->fields('ttd', ['tid'])
  ->condition('ttd.vid', 'document_types', '=');
$doc_results = $doc_query->execute()->fetchAll();
foreach ($doc_results AS $doc_result){

  // On vérifie si on a affaire à un objet ou à un tableau
  if (isset($doc_result->tid)){
    $doc_hierarchy = $connection->select('taxonomy_term_hierarchy', 'tth');
    $doc_hierarchy->fields('tth', ['tid']);
    $doc_hierarchy->condition('tth.tid', $doc_result->tid, '=');
    $doc_hierarchy_results = $doc_hierarchy->execute()->fetchAll();
    if(count($doc_hierarchy_results) == 0)
    {
      $connection->insert('taxonomy_term_hierarchy')
        ->fields(array(
          'tid' => $doc_result->tid,
          'parent' => 0))->execute();
    }
  }
}


//Topics
$topic_query = $connection->select('taxonomy_term_field_data', 'ttd');
$topic_query->fields('ttd', ['tid'])
  ->condition('ttd.vid', 'topic', '=');
$topic_results = $topic_query->execute()->fetchAll();
foreach ($topic_results AS $topic_result){

  // On vérifie si on a affaire à un objet ou à un tableau
  if (isset($topic_result->tid)){
    $topic_hierarchy = $connection->select('taxonomy_term_hierarchy', 'tth');
    $topic_hierarchy->fields('tth', ['tid']);
    $topic_hierarchy->condition('tth.tid', $topic_result->tid, '=');
    $topic_hierarchy_results = $topic_hierarchy->execute()->fetchAll();
    if(count($topic_hierarchy_results) == 0)
    {
      $connection->insert('taxonomy_term_hierarchy')
        ->fields(array(
          'tid' => $topic_result->tid,
          'parent' => 0))->execute();
    }
  }
}