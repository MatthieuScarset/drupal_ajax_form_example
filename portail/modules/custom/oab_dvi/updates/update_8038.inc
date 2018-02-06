<?php

/**
 * Détaggage de tous les produits qui avaient été taggés avec des terms de DVI
 */
$default_labels = array(
    'plus-50-salaries',
    'plus-250-salaries',
    'more-50-employees',
    'more-250-employees',
    'moins-50-salaries',
    'less-50-employees',
    'secteur-public',
    'public-sector'
);
$tids = array();
foreach ($default_labels as $label)
{
        $query = \Drupal::entityQuery('taxonomy_term');
        $query->condition('vid', 'market_segments');
        $query->condition('name', $label);
        $entity = $query->execute();

        if (!empty($entity)) {
            $tids[] = strval(key($entity));
        }
}

#on recupère tous les nids des produits
$nids= \Drupal::entityQuery('node')
    ->condition('type', 'product')
    ->execute();

$nodesProducts = \Drupal\node\Entity\Node::loadMultiple($nids);
foreach ($nodesProducts as $product) {
    $segments = $product->get('field_market_segment')->getValue();

    foreach ($segments as $key => $segment) {
        if (in_array($segment['target_id'], $tids )) {
            unset($segments[$key]);
        }
    }

    $product->set('field_market_segment', array_values($segments));
    $product->save();

}

##Ensuite, suppression des termes
$terms = \Drupal\taxonomy\Entity\Term::loadMultiple($tids);
foreach ($terms as $term) {
    $term->delete();
}

