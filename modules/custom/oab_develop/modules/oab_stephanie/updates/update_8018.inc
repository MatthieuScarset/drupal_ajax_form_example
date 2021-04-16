<?php

//On supprime d'abord les termes de taxonomies saisis manuellement
$vidsToClean = array('solutions',
  'industries',
  'partner_types',
  'regions',
  'jobs_profiles',
  'subhomes');

foreach ($vidsToClean as $vid) {
  $tids = \Drupal::entityQuery('taxonomy_term')
    ->condition('vid', $vid)
    ->execute();

  $controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
  $entities = $controller->loadMultiple($tids);
  $controller->delete($entities);
}

$terms = array(
  //Solutions FR
  array( 'vid' => 'solutions', 'name' => 'Espace collaboratifs', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Mobile Workspace', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Relation client enrichie', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Innovation au service du business', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Connectivité enrichie', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'IT Flexible', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Cyberdefense', 'language' => 'fr'),
  array( 'vid' => 'solutions', 'name' => 'Service', 'language' => 'fr'),

  //Solutions EN
  array( 'vid' => 'solutions', 'name' => 'Collaborative workspace', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Enriched customer relationships', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Business innovation', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Universal connectivity', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Flexible IT', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Cyber defense', 'language' => 'en'),
  array( 'vid' => 'solutions', 'name' => 'Services', 'language' => 'en'),

  //Industries FR
  array( 'vid' => 'industries', 'name' => 'Banque et Assurance', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Commerce', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Santé', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Industrie / Campus numérique', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Secteur public', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Smart Cities', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Transport logistique', 'language' => 'fr'),
  array( 'vid' => 'industries', 'name' => 'Collectivités locales', 'language' => 'fr'),

  //Industries EN
  array( 'vid' => 'industries', 'name' => 'Transport and Logistic', 'language' => 'en'),
  array( 'vid' => 'industries', 'name' => 'Financial Services', 'language' => 'en'),
  array( 'vid' => 'industries', 'name' => 'Healthcare', 'language' => 'en'),
  array( 'vid' => 'industries', 'name' => 'Oil, gaz, mines', 'language' => 'en'),
  array( 'vid' => 'industries', 'name' => "MOFA’s", 'language' => 'en'),

  //Industries RU
  array( 'vid' => 'industries', 'name' => 'решения для здравоохранения', 'language' => 'ru'),
  array( 'vid' => 'industries', 'name' => 'решения для нефтегазовых организаций', 'language' => 'ru'),
  array( 'vid' => 'industries', 'name' => 'решения для финансовых организаций', 'language' => 'ru'),

  //Industries RU-EN
  array( 'vid' => 'industries', 'name' => 'finance', 'language' => 'ru-en'),
  array( 'vid' => 'industries', 'name' => 'oil & gas', 'language' => 'ru-en'),

  //Type de partenaires FR
  array( 'vid' => 'partner_types', 'name' => 'Solutions', 'language' => 'fr'),
  array( 'vid' => 'partner_types', 'name' => 'Telco', 'language' => 'fr'),
  array( 'vid' => 'partner_types', 'name' => 'Inégrateurs de Systèmes', 'language' => 'fr'),
  array( 'vid' => 'partner_types', 'name' => 'Verticaux', 'language' => 'fr'),

  //Type de partenaires EN
  array( 'vid' => 'partner_types', 'name' => 'Solutions', 'language' => 'en'),
  array( 'vid' => 'partner_types', 'name' => 'Telco', 'language' => 'en'),
  array( 'vid' => 'partner_types', 'name' => 'System Integrators', 'language' => 'en'),
  array( 'vid' => 'partner_types', 'name' => 'Vertical', 'language' => 'en'),

  //Zone géographique FR
  array( 'vid' => 'regions', 'name' => 'Afrique', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Asie Pacifique', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Europe', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Amerique Latine', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Moyen Orient', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Amerique du Nord', 'language' => 'fr'),
  array( 'vid' => 'regions', 'name' => 'Russie', 'language' => 'fr'),

  //Zone géographique EN
  array( 'vid' => 'regions', 'name' => 'Africa', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'Asia Pacific', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'Europe', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'Latin America', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'Middle East', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'North America', 'language' => 'en'),
  array( 'vid' => 'regions', 'name' => 'Russia', 'language' => 'en'),

  //Profils métiers FR
  array( 'vid' => 'jobs_profiles', 'name' => 'Directeur Général (DG)', 'language' => 'fr'),
  array( 'vid' => 'jobs_profiles', 'name' => 'DSI', 'language' => 'fr'),
  array( 'vid' => 'jobs_profiles', 'name' => 'DRH', 'language' => 'fr'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Directeur Marketing', 'language' => 'fr'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Directeur Commercial ou des ventes', 'language' => 'fr'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Directeur de la Communication', 'language' => 'fr'),

  //Profils métiers EN
  array( 'vid' => 'jobs_profiles', 'name' => 'CEO', 'language' => 'en'),
  array( 'vid' => 'jobs_profiles', 'name' => 'CIO', 'language' => 'en'),
  array( 'vid' => 'jobs_profiles', 'name' => 'HR Director or VP', 'language' => 'en'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Chief Marketing Officer (CMO)', 'language' => 'en'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Sales Director', 'language' => 'en'),
  array( 'vid' => 'jobs_profiles', 'name' => 'Communications Director', 'language' => 'en'),

  //Subhomes FR
  array( 'vid' => 'subhomes', 'name' => 'Partenaires', 'language' => 'fr'),
  array( 'vid' => 'subhomes', 'name' => 'Cas clients', 'language' => 'fr'),
  array( 'vid' => 'subhomes', 'name' => 'Presse', 'language' => 'fr'),
  array( 'vid' => 'subhomes', 'name' => 'Médiathèque', 'language' => 'fr'),
  array( 'vid' => 'subhomes', 'name' => 'Catalogue', 'language' => 'fr'),
  array( 'vid' => 'subhomes', 'name' => 'Magazine', 'language' => 'fr'),

  //Subhomes EN
  array( 'vid' => 'subhomes', 'name' => 'Partners', 'language' => 'en'),
  array( 'vid' => 'subhomes', 'name' => 'Customer Stories', 'language' => 'en'),
  array( 'vid' => 'subhomes', 'name' => 'Press', 'language' => 'en'),
  array( 'vid' => 'subhomes', 'name' => 'Library', 'language' => 'en'),
  array( 'vid' => 'subhomes', 'name' => 'Portfolio', 'language' => 'en'),
  array( 'vid' => 'subhomes', 'name' => 'Magazine', 'language' => 'en'),
);

foreach ($terms as $term)
{
  //vérification de l'existance du terme pour ce vocabulaire
  $query = \Drupal::entityQuery('taxonomy_term');
  $query->condition('vid', $term['vid']);
  $query->condition('langcode', $term['language']);
  $query->condition('name', $term['name']);
  $entity = $query->execute();

  if (!isset($entity) || empty($entity))
  {
    //s'il n'existe pas on le crée
    $newTerm = \Drupal\taxonomy\Entity\Term::create([
      'vid' => $term['vid'],
      'name' => $term['name'],
      'langcode' => $term['language'],
    ]);
    $newTerm->save();
    drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
  }
}