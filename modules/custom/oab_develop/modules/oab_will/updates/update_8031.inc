<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *             RUBYPORTAILOBS-3450 creation taxonomy insight_type
 */

#lien du vocab inside type
$contentTypes = [
    "blog_post",
    "custom_page",
    "customer_story",
    "document",
    "full_html",
    "industry",
    "magazine",
    "press_kit",
    "press_release",
    "product",
    "simple_page",
    "solution"
];


foreach ($contentTypes as $contentType) {
    oabt_YmlImport('core.entity_view_display.node.'.$contentType.'.tile.yml');
}
