<?php

use Drupal\Core\Database\Database;
use \Drupal\Core\Utility\UpdateException;

// création du menu du sur-header EN : regional presence

$connection = Database::getConnection();

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/a-propos');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'A propos',
        'menu_name' => 'main',
        'link' => 'internal:/a-propos',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/expertise');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Expertise',
        'menu_name' => 'main',
        'link' => 'internal:/expertise',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/produits-et-services');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Produits et services',
        'menu_name' => 'main',
        'link' => 'internal:/produits-et-services',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}


$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/eclairages');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_navprincipale = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'fr',
        'title' => 'Eclairages',
        'menu_name' => 'main',
        'link' => 'internal:/eclairages',
        'enabled' => '1',
        'parent' => ''
    ));
    $menu_navprincipale->save();
}

// création des liens du Footer EN

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/discover');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_footer_discover = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'en',
        'title' => 'Discover',
        'menu_name' => 'footer',
        'link' => 'internal:/discover',
        'enabled' => '1',
        'expanded' => '1',
        'parent' => ''
    ));
    $menu_footer_discover->save();
    $menuparent = $menu_footer_discover->uuid();

    // création des sous menus Discover : Home, Work et Fun
    $menu_footer_home = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Home',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/home',
        'weight' => '-50',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_home->save();

    $menu_footer_work = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Work',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/work',
        'weight' => '-49',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_work->save();

    $menu_footer_fun = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Home',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/fun',
        'weight' => '-48',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_fun->save();

    $menu_footer_connect = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Connect',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/connect',
        'weight' => '-47',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_connect->save();

    $menu_footer_family = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Family',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/family',
        'weight' => '-46',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_family->save();

    $menu_footer_wellbeing = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Wellbeing',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/wellbeing',
        'weight' => '-45',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_wellbeing->save();

    $menu_footer_money = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Money',
        'menu_name' => 'footer',
        'link' => 'internal:/discover/money',
        'weight' => '-44',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_money->save();
}

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/shop');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_footer_shop = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'en',
        'title' => 'Shop',
        'menu_name' => 'footer',
        'link' => 'internal:/shop',
        'enabled' => '1',
        'expanded' => '1',
        'parent' => ''
    ));
    $menu_footer_shop->save();
    $menuparent = $menu_footer_shop->uuid();

    // création des sous menus Shop : Phones, Tablets
    $menu_footer_phones = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Shop',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/phones',
        'weight' => '-50',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_phones->save();

    $menu_footer_tablets = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Tablets',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/tablets',
        'weight' => '-49',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_tablets->save();

    $menu_footer_paymonth = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Pay monthly phones',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/pay-monthly-phones',
        'weight' => '-48',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_paymonth->save();

    $menu_footer_paygo = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Pay mas you go',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/pay-as-you-go',
        'weight' => '-47',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_paygo->save();

    $menu_footer_homeb = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Home broadband',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/home-broadband',
        'weight' => '-46',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_homeb->save();

    $menu_footer_accessories = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Accessories',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/accessories',
        'weight' => '-45',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_accessories->save();

    $menu_footer_bshop = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Business shop',
        'menu_name' => 'footer',
        'link' => 'internal:/shop/business-shop',
        'weight' => '-44',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_bshop->save();
}

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/services');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_footer_services = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'en',
        'title' => 'Services',
        'menu_name' => 'footer',
        'link' => 'internal:/services',
        'enabled' => '1',
        'expanded' => '1',
        'parent' => ''
    ));
    $menu_footer_services->save();
    $menuparent = $menu_footer_services->uuid();

    // création des sous menus Services : Calling, messaging
    $menu_footer_calling = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Calling',
        'menu_name' => 'footer',
        'link' => 'internal:/services/calling',
        'weight' => '-50',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_calling->save();

    $menu_footer_messaging = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Messaging',
        'menu_name' => 'footer',
        'link' => 'internal:/services/messaging',
        'weight' => '-49',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_messaging->save();

    $menu_footer_mobile = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Mobile email',
        'menu_name' => 'footer',
        'link' => 'internal:/services/mobile-email',
        'weight' => '-48',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_mobile->save();

    $menu_footer_orange = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Orange TV',
        'menu_name' => 'footer',
        'link' => 'internal:/services/orange-tv',
        'weight' => '-47',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_orange->save();

    $menu_footer_contacts = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Contacts',
        'menu_name' => 'footer',
        'link' => 'internal:/services/contacts',
        'weight' => '-46',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_contacts->save();

    $menu_footer_data = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Mobile data services',
        'menu_name' => 'footer',
        'link' => 'internal:/services/mobile-data-services',
        'weight' => '-45',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_data->save();

    $menu_footer_roaming = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Roaming',
        'menu_name' => 'footer',
        'link' => 'internal:/services/roaming',
        'weight' => '-44',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_data->save();

    $menu_footer_money = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Orange money',
        'menu_name' => 'footer',
        'link' => 'internal:/services/orange-money',
        'weight' => '-43',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_money->save();

    $menu_footer_insurance = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Insurance',
        'menu_name' => 'footer',
        'link' => 'internal:/services/insurance',
        'weight' => '-42',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_insurance->save();
}

$query = $connection->select('menu_link_content_data', 'm')
    ->fields('m', array('link__uri'))
    ->condition('m.link__uri', 'internal:/support');
$results = $query->execute()->fetchAll(\PDO::FETCH_OBJ);
if (empty($results)) {
    $menu_footer_support = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'menu_link_content',
        'langcode' => 'en',
        'title' => 'Support',
        'menu_name' => 'footer',
        'link' => 'internal:/support',
        'enabled' => '1',
        'expanded' => '1',
        'parent' => ''
    ));
    $menu_footer_support->save();
    $menuparent = $menu_footer_support->uuid();

    // création des sous menus Services : Calling, messaging
    $menu_footer_broadband = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Broadband help',
        'menu_name' => 'footer',
        'link' => 'internal:/support/broadband-help',
        'weight' => '-48',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_broadband->save();

    $menu_footer_mobile = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Mobile help',
        'menu_name' => 'footer',
        'link' => 'internal:/support/mobile-help',
        'weight' => '-49',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_mobile->save();

    $menu_footer_data = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Mobile data help',
        'menu_name' => 'footer',
        'link' => 'internal:/support/mobile-data-help',
        'weight' => '-47',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_data->save();

    $menu_footer_business = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Business help',
        'menu_name' => 'footer',
        'link' => 'internal:/support/business-help',
        'weight' => '-46',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_business->save();

    $menu_footer_top = \Drupal\menu_link_content\Entity\MenuLinkContent::create(array(
        'bundle' => 'default',
        'langcode' => 'en',
        'title' => 'Top up your phone',
        'menu_name' => 'footer',
        'link' => 'internal:/support/top-up',
        'weight' => '-45',
        'enabled' => '1',
        'parent' => 'menu_link_content:' . $menuparent
    ));
    $menu_footer_top->save();
}

throw new \Drupal\Core\Utility\UpdateException();