<?php
use Symfony\Component\Yaml\Yaml;


/*
 * RUBYPORTAILOBS-3177 mise a jour des images styles
 */


oabt_YmlImport('image.style.blogger_insert.yml');
oabt_YmlImport('image.style.document_visual_image.yml');
oabt_YmlImport('image.style.file_entity_browser_thumbnail.yml');
oabt_YmlImport('image.style.homepage_expertise.yml');
oabt_YmlImport('image.style.homepage_news.yml');
oabt_YmlImport('image.style.homepage_solution_banner.yml');
oabt_YmlImport('image.style.homepage_top_zone.yml');
oabt_YmlImport('image.style.large.yml');
oabt_YmlImport('image.style.linkit_result_thumbnail.yml');
oabt_YmlImport('image.style.logo_partner.yml');
oabt_YmlImport('image.style.max_325x325.yml');
oabt_YmlImport('image.style.max_650.yml');
oabt_YmlImport('image.style.max_1300x1300.yml');
oabt_YmlImport('image.style.max_2600x2600.yml');
oabt_YmlImport('image.style.medium.yml');
oabt_YmlImport('image.style.miniature_document.yml');
oabt_YmlImport('image.style.partner.yml');
oabt_YmlImport('image.style.playlist.yml');
oabt_YmlImport('image.style.related_contents.yml');
oabt_YmlImport('image.style.subhome.yml');
oabt_YmlImport('image.style.thumbnail.yml');
oabt_YmlImport('image.style.top_zone.yml');
oabt_YmlImport('image.style.top_zone_big.yml');
oabt_YmlImport('image.style.valorisation.yml');

$connection = \Drupal\Core\Database\Database::getConnection();
$query = $connection->update('config');
$query->fields([
    'data' => serialize(array (
        'label' => 'Encart bloggeur (170x170)',
    )),
]);
$query->condition('name',"image.style.blogger_insert");
$query->condition('collection','language.fr');
$query->execute();
