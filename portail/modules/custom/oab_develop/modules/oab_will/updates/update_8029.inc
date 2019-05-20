<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *             RUBYPORTAILOBS-3433 [B-Insight] Création des templates des contenus
 */

oabt_YmlImport('core.entity_view_mode.node.tile.yml');
oabt_YmlImport('views.view.business_insight.yml');

oabt_YmlImport('core.entity_view_display.node.blog_post.tile.yml');
oabt_YmlImport('core.entity_view_display.node.custom_page.tile.yml');
oabt_YmlImport('core.entity_view_display.node.customer_story.tile.yml');
oabt_YmlImport('core.entity_view_display.node.document.tile.yml');
oabt_YmlImport('core.entity_view_display.node.full_html.tile.yml');
oabt_YmlImport('core.entity_view_display.node.industry.tile.yml');
oabt_YmlImport('core.entity_view_display.node.magazine.tile.yml');
oabt_YmlImport('core.entity_view_display.node.press_kit.tile.yml');
oabt_YmlImport('core.entity_view_display.node.press_release.tile.yml');
oabt_YmlImport('core.entity_view_display.node.product.tile.yml');
oabt_YmlImport('core.entity_view_display.node.simple_page.tile.yml');
oabt_YmlImport('core.entity_view_display.node.solution.tile.yml');
