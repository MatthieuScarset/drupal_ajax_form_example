<?php

/**
 * Création de la subhome Analysts
 */



## First, création des termes de taxonomie
$terms = array(
    //en
    array(
        "language" => "en",
        "name" => "Analysts",
        "variable" => "analysts_term_tid",
        'description' => "<p>Find out what analysts are saying about Orange Business Services, from our regional and global capabilities to how we fare in independent customer service evaluations.</p>"
    ),
    array(
        "language" => "fr",
        "name" => "Analystes",
        "variable" => "analysts_term_tid",
        "description" => "<p>Retrouvez ici ce que les analystes disent d'Orange Business Services, depuis nos potentiels régional et global jusqu'à notre positionnement dans les évaluations de services consommateurs indépendants.</p>"
    )
);
$tids = array();

foreach ($terms as &$term) {
# Création de la taxo en EN et en FR
    $term_id = "";

    //vérification de l'existance du terme pour ce vocabulaire
    $query = \Drupal::entityQuery('taxonomy_term');
    $query->condition('vid', "subhomes");
    $query->condition('langcode', $term['language']);
    $query->condition('name', $term['name']);
    $entity = $query->execute();

    if (!isset($entity) || empty($entity)) {
        //s'il n'existe pas on le crée
        $entity = \Drupal\taxonomy\Entity\Term::create([
            'vid' => "subhomes",
            'name' => $term['name'],
            'langcode' => $term['language'],
            'description'   => $term['description']
        ]);
        $entity->set('field_related_display_view', 'page_analysts');
        $entity->save();
        //drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
        $term_id = $entity->id();
    } else {
        $term_id = key($entity);
    }

    ## Recuperation des tids des taxos créées pour save en conf
    $tids[$term['language']] = $term_id;
}

###########################################################
## Sauvegarde des tids en conf pour la gestion des subhomes

##Conf original en En
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->set('analysts_term_tid', $tids['en']);
$config_group->set('analysts_meta', "Analysts");
$config_group->save();

## Config fr => Je charge la collection déjà existante, je rajoute nos champs, puis je la save
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$config_fr = $collection->read('oab_subhomes.subhomes');
$config_fr['analysts_term_tid'] = $tids['fr'];
$config_fr['analysts_meta'] = "Analystes";
$collection->write('oab_subhomes.subhomes', $config_fr);


###########################################################
## Rechargement de la conf des subhomes pour ajouter la nouvelle subhome
oabt_YmlImport('views.view.subhomes.yml');

###########################################################
## Ajout des trads de la vue
$trad_fr = array (
    'display' =>
        array (
            'page_press' =>
                array (
                    'display_title' => 'Presse',
                ),
            'page_catalogue' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Produits',
                        ),
                    'display_title' => 'Produits',
                ),
            'page_customer' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Témoignage client',
                        ),
                    'display_title' => 'Témoignage client',
                ),
            'page_document' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Médiathèque',
                        ),
                    'display_title' => 'Médiathèque',
                ),
            'page_partners' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Partenaires',
                        ),
                    'display_title' => 'Partenaires',
                ),
            'default' =>
                array (
                    'display_options' =>
                        array (
                            'title' => 'Analystes',
                            'exposed_form' =>
                                array (
                                    'options' =>
                                        array (
                                            'submit_button' => 'Filtrer',
                                        ),
                                ),
                        ),
                ),
            'page_catalogue_dvi' =>
                array (
                    'display_title' => 'Produits DVI',
                    'display_options' =>
                        array (
                            'title' => 'Produits DVI',
                        ),
                ),
            'page_distributor' =>
                array (
                    'display_title' => 'Distributeurs',
                    'display_options' =>
                        array (
                            'title' => 'Distributeurs',
                        ),
                ),
            'page_analysts' =>
                array (
                    'display_title' => 'analystes',
                ),
        ),
);
$collection->write('views.view.subhomes', $trad_fr);

###########################################################
## Ajout des URL
\Drupal::service('path.alias_storage')->save("/subhome_analysts", "/analysts", "en");
\Drupal::service('path.alias_storage')->save("/subhome_analysts", "/analystes", "fr");
