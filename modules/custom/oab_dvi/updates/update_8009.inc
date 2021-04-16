<?php

$default_labels = array(
	"fr" => array('+ 50 salariés', '+ 250 salariés'),
	"en" => array('+ 50 employees', '+ 250 employees')
);
$default_values = array();
foreach ($default_labels as $lang => $labels)
{
	$default_values[$lang] = array();
	foreach ($labels as $label) {
		$query = \Drupal::entityQuery('taxonomy_term');
		$query->condition('vid', 'market_segments');
		$query->condition('name', $label);
		$query->condition('langcode', $lang);
		$entity = $query->execute();

		if (!empty($entity)) {
			$default_values[$lang][] = array_pop($entity);
		}
	}
}

//on passe tous les nodes Office en EN
$nids= \Drupal::entityQuery('node')
	->condition('type', 'product')
	->execute();

$nodesProducts = \Drupal\node\Entity\Node::loadMultiple($nids);
foreach ($nodesProducts as $product) {
			if (!empty($default_values[$product->language()->getId()]) ) {
				$segments = $product->get('field_market_segment')->getValue();
				foreach ($default_values[$product->language()->getId()] as $newValue) {
					if (!in_array(array( "target_id" => $newValue), $segments)) {
						array_push($segments, $newValue);
					}
				}
				$product->set('field_market_segment', $segments);
				$product->save();
			}
}

