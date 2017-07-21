<?php
/**
 *  - field content_owner
 */
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.product.field_content_owner', array (
	'label' => 'Auteur',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('field.field.node.product.field_content_owner', array (
	'label' => 'Content owner',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru-en');
$collection->write('field.field.node.product.field_content_owner', array (
	'label' => 'Content owner',
));

/**
 *  - field email_owner
 */
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.product.field_email_owner', array (
	'label' => 'Email de l\'auteur',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('field.field.node.product.field_email_owner', array (
	'label' => 'Email of content owner',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru-en');
$collection->write('field.field.node.product.field_email_owner', array (
	'label' => 'Email of content owner',
));

