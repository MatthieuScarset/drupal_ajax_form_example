<?php

$connection = \Drupal\Core\Database\Database::getConnection();
//vérification de l'existance du terme pour ce vocabulaire
$query = $connection->select('url_alias', 'u');
$query->fields('u');
$query->condition('source', "/contacts");
$query->condition('langcode', 'en');
$entity = $query->execute()->fetchObject();

if (!isset($entity) || empty($entity))
{
	\Drupal::service('path.alias_storage')->save("/contacts" , "/where-we-are" , "en");
}