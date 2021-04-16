<?php

use Drupal\Core\Database\Database;

$config_factory = \Drupal::configFactory();
$config_old = $config_factory->getEditable('oab_subhomes.subhomes');

$config_new = array(
    'press_term_tid' => $config_old->get('press_term_tid'),
    'partner_term_tid' => $config_old->get('partner_term_tid'),
    'customer_term_tid' => $config_old->get('customer_term_tid'),
    'library_term_tid' => $config_old->get('library_term_tid'),
    'blog_term_tid' => $config_old->get('blog_term_tid'),
    'magazine_term_tid' => $config_old->get('magazine_term_tid'),
    'product_term_tid' => $config_old->get('product_term_tid'),
    'press_meta' => 'Press',
    'partner_meta' => 'Partners',
    'customer_meta' => 'Customer stories',
    'library_meta' => 'Documents',
    'blog_meta' => 'Blogs',
    'magazine_meta' => 'Magazine',
    'product_meta' => 'Products',
);

// Meta title EN
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_subhomes.subhomes');
$config_group->setData($config_new);
$config_group->save();

// Meta title FR
$connection = Database::getConnection();
$sth = $connection->select('config', 'c')
    ->fields('c', array('data'))
    ->condition('name', 'oab_subhomes.subhomes')
    ->condition('collection', 'language.fr');
$data = $sth->execute();
$results = $data->fetchAll(\PDO::FETCH_OBJ);
if (count($results) > 0) {
    $olddata = unserialize($results[0]->data);
    $collection = \Drupal::service('config.storage')->createCollection('language.fr');
    $collection->write('oab_subhomes.subhomes', array (
        'press_term_tid' => $olddata['press_term_tid'],
        'partner_term_tid' => $olddata['partner_term_tid'],
        'customer_term_tid' => $olddata['customer_term_tid'],
        'library_term_tid' => $olddata['library_term_tid'],
        'blog_term_tid' => $olddata['blog_term_tid'],
        'magazine_term_tid' => $olddata['magazine_term_tid'],
        'product_term_tid' => $olddata['product_term_tid'],
        'press_meta' => 'Presse',
        'partner_meta' => 'Partenaires',
        'customer_meta' => 'Témoignages clients',
        'library_meta' => 'Médiathèque',
        'blog_meta' => 'Blogs',
        'magazine_meta' => 'Magazine',
        'product_meta' => 'Produits',
    ));
}

// Meta title RU
$connection = Database::getConnection();
$sth = $connection->select('config', 'c')
    ->fields('c', array('data'))
    ->condition('name', 'oab_subhomes.subhomes')
    ->condition('collection', 'language.ru');
$data = $sth->execute();
$results = $data->fetchAll(\PDO::FETCH_OBJ);
if (count($results) > 0) {
    $olddata = unserialize($results[0]->data);
    $collection = \Drupal::service('config.storage')->createCollection('language.ru');
    $collection->write('oab_subhomes.subhomes', array (
        'press_term_tid' => $olddata['press_term_tid'],
        'partner_term_tid' => $olddata['partner_term_tid'],
        'customer_term_tid' => $olddata['customer_term_tid'],
        'library_term_tid' => $olddata['library_term_tid'],
        'blog_term_tid' => $olddata['blog_term_tid'],
        'magazine_term_tid' => $olddata['magazine_term_tid'],
        'product_term_tid' => $olddata['product_term_tid'],
        'press_meta' => 'Новости',
        'customer_meta' => 'Проекты',
        'product_meta' => 'Услуги',
    ));
}

// on met à jour la vue subhomes
oabt_YmlImport('views.view.subhomes.yml');