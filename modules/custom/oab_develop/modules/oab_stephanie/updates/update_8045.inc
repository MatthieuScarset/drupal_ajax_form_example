<?php
//affectation des contenus region aux termes région
$termes = array(
	"Asia Pacific" => "Asia Pacific",
	"Middle East & Africa" => "Middle East and Africa",
	"Europe" => "Europe",
	"Latin America" => "Latin America",
	"North America" => "North America",
	"Russia" => "Russia"
);

foreach ($termes as $term => $contentTitle) {
//	$termsArray = taxonomy_term_load_multiple_by_name($term, 'regions');
  $termsArray = \Drupal::entityTypeManager()
    ->getStorage("taxonomy_term")
    ->loadByProperties(["name" => $term, "vid" => "regions"]);

	foreach ($termsArray as $foundterm) {
		if (!empty($foundterm)) {

			$query = \Drupal\Core\Database\Database::getConnection()->select('node_field_data', 'n');
			$query->condition('n.type', 'region', '=');
			$query->condition('n.status', 1, '=');
			$query->condition('n.title', $contentTitle, '=');
			$query->addField('n', 'nid', 'nid');
			$results =	$query->execute()->fetchAll();

			foreach ($results as $row) {
				if (!empty($row)) {
					$foundterm->field_linked_content = $row->nid;
					$foundterm->save();
				}
			}
		}
	}
}
