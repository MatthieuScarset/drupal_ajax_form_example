<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_backoffice.ece');
$config_group->setData(array (
    'title' => 'My Service Space',
    'intro' => 'Track your use, manage your bills, options and services 24/24',
    'connect_txt' => 'Sign in',
    'connect_link' => 'https://dro.orange-business.com/authentification?TYPE=33554433&REALMOID=06-0000e733-54df-1266-8576-5e0e0a63d064&GUID=&SMAUTHREASON=0&METHOD=GET&SMAGENTNAME=-SM-TPZ0eHv9wdQAe0KqXWVXK5B%2b8mUfc6au28lAfEL%2bvsCray2ghF0v8nhYk9lzcjpc&TARGET=-SM-https%3a%2f%2fmy--service--space.orange--business.com%2f&codeContexte=MSS',
    'discover_txt' => 'Discover',
    'discover_link' => 'https://www.orange-business.com/en/products/my-service-space',
    'create_txt' => 'Create an account',
    'create_link' => 'http://www.orange-business.com/en/my-service-space-account-request',
));
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('oab_backoffice.ece', array (
    'title' => 'Espace Client Entreprise',
    'intro' => 'Gérer vos solutions, consulter vos factures et retrouver les informations clés pour votre activité…',
    'connect_txt' => 'Se connecter',
    'connect_link' => 'https://espaceclient.orange-business.com/web/ece2/home',
    'discover_txt' => 'Découvrir',
    'discover_link' => 'https://www.orange-business.com/fr/produits/espace-client-entreprise',
    'create_txt' => 'Créer un compte',
    'create_link' => 'https://espaceclient.orange-business.com/web/ece2/creation',
));
