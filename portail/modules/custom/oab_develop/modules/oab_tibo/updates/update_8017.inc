<?php

use Drupal\Core\Database\Database;

function renameTaxo($old, $new, $vid, $lang){
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $vid);
	$query->condition('langcode', $lang);
	$query->condition('name', $old);
	$entity = $query->execute();
	if(isset($entity)) {
		foreach ($entity as $tid => $value){
			$tidRename = $tid;
		}
	}
	if(isset($tidRename)){
		$connection = Database::getConnection();
		$query = $connection->update('taxonomy_term_field_data');
		$query->fields([
			'name' => $new,
		]);
		$query->condition('tid',$tidRename);
		$query->execute();
	}
}

// mise à jour des taxonomies existantes

/**
 * Solutions
 */
renameTaxo('Cyber défense', 'Cyberdefense', 'solutions', 'fr');
renameTaxo('IT flexible', 'IT Flexible', 'solutions', 'fr');

renameTaxo('Business innovation', 'Business Innovation', 'solutions', 'en');
renameTaxo('Collaborative workspace', 'Collaborative Workspace', 'solutions', 'en');
renameTaxo('Cyber defense', 'Cyber Defense', 'solutions', 'en');
renameTaxo('Enriched customer relationships', 'Enriched Customer relationships', 'solutions', 'en');
drupal_set_message("-- Taxonomies Solutions mises à jour", "status");

/**
 * Industries
 */
renameTaxo('Banque et Assurance', 'Banque et assurance', 'industries', 'fr');


drupal_set_message("-- Taxonomies Industries mises à jour", "status");





//throw new \Drupal\Core\Utility\UpdateException();