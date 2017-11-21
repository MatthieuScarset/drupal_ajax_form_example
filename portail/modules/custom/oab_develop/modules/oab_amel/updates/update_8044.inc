<?php

//  rétablissement du format HTML Date sur la view
oabt_YmlImport('views.view.page_thematique.yml');

oabt_YmlImport('field.field.node.blog_post.field_visual.yml');
oabt_YmlImport('field.field.node.customer_story.field_visual.yml');
oabt_YmlImport('field.field.node.document.field_visual.yml');
oabt_YmlImport('field.field.node.industry.field_visual.yml');
oabt_YmlImport('field.field.node.magazine.field_visual.yml');
oabt_YmlImport('field.field.node.partner.field_visual.yml');
oabt_YmlImport('field.field.node.press_release.field_visual.yml');
oabt_YmlImport('field.field.node.press_kit.field_visual.yml');
oabt_YmlImport('field.field.node.product.field_visual.yml');
oabt_YmlImport('field.field.node.profile.field_visual.yml');
oabt_YmlImport('field.field.node.region.field_visual.yml');
oabt_YmlImport('field.field.node.simple_page.field_visual.yml');
oabt_YmlImport('field.field.node.solution.field_visual.yml');
oabt_YmlImport('field.field.node.solution.field_top_zone_background.yml');

oabt_YmlImport('field.field.node.homepage.field_solution_banner_image.yml');
oabt_YmlImport('field.field.node.homepage.field_banner_expertise.yml');
oabt_YmlImport('field.field.node.homepage.field_top_zone_image.yml');
oabt_YmlImport('field.field.node.homepage_eclairage.field_home_banner.yml');
oabt_YmlImport('field.field.node.hp_eclairage_thematique.field_desktop_image.yml');
oabt_YmlImport('field.field.node.hp_eclairage_thematique.field_mobile_image.yml');

oabt_YmlImport('field.field.paragraph.home_banner.field_big_image_desktop_.yml');
oabt_YmlImport('field.field.paragraph.home_banner.field_little_image_desktop.yml');
oabt_YmlImport('field.field.paragraph.home_banner.field_image_mobile.yml');
oabt_YmlImport('field.field.paragraph.home_column_section.field_image.yml');
oabt_YmlImport('field.field.paragraph.home_thematic_columns.field_image.yml');
oabt_YmlImport('field.field.paragraph.homepage_news.field_image.yml');
oabt_YmlImport('field.field.paragraph.related_content.field_visual.yml');

oabt_YmlImport('field.field.node.homepage.field_infography.yml');
oabt_YmlImport('field.field.node.homepage.field_corporate_image.yml');
oabt_YmlImport('field.field.node.region.field_top_zone_background.yml');
oabt_YmlImport('field.field.paragraph.home_column.field_solaris_icon.yml');
oabt_YmlImport('field.field.node.industry.field_top_zone_background.yml');


$contentTypes = [
    'customer_story',
    'partner',
    'blog_post',
    'magazine',
    'press_release',
    'press_kit',
    'document',
    'simple_page',
    'product'
];

foreach ($contentTypes as $contentType) {
    $field_bddName = "field.field.node." . $contentType . ".field_visual";

    $collection = \Drupal::service('config.storage')->createCollection('language.fr');
    $collection->write($field_bddName, array (
        "label" => "Visuel pour la subHome",
        "description" => "Taille de l'image (largeur x hauteur) : 310x125px"
    ));
}
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.profile.field_visual", array (
    "label" => "Image blogger",
    "description" => "Taille de l'image : 170x170px"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.homepage.field_solution_banner_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 1400x500px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.homepage.field_top_zone_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 1400x500px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.homepage.field_banner_expertise", array (
    "description" => "Taille de l'image (largeur x hauteur) : 345x270px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.homepage_eclairage.field_home_banner", array (
    "description" => "Taille de l'image (largeur x hauteur) : 1000x465px"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.hp_eclairage_thematique.field_desktop_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 950x610px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.node.hp_eclairage_thematique.field_mobile_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 420x370px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.home_banner.field_big_image_desktop_", array (
    "description" => "Taille de l'image (largeur x hauteur) : 770x465px"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.home_banner.field_little_image_desktop", array (
    "description" => "Taille de l'image (largeur x hauteur) : 335x155px"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.home_banner.field_image_mobile", array (
    "description" => "Taille de l'image (largeur x hauteur) : 525x350px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.home_thematic_columns.field_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 420x200px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.homepage_news.field_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 380x180px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.home_column_section.field_image", array (
    "description" => "Taille de l'image (largeur x hauteur) : 90x55px"
));
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write("field.field.paragraph.related_content.field_visual", array (
    "description" => "Taille de l'image (largeur x hauteur) : 400x200px"
));



//JIRA_3185 : attribution des droits au Chief Editor pour accéder aux champs Scheduled Updates
oabt_YmlImport('user.role.chief_editor.yml');