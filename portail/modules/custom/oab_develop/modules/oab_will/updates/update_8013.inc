<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * RUBYPORTAILOBS-3310 [OC] champ HUB dans les types de contenu
 */


$field_storage = FieldStorageConfig::loadByName('node', 'field_hub');

if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_hub',
        'entity_type' => 'node',
        'type' => 'entity_reference',
    ))->save();
}
oabt_YmlImport('field.storage.node.field_hub.yml');

/*$connection = \Drupal::database();
$query_string = "CREATE TABLE IF NOT EXISTS `node__field_hub` (
`bundle` varchar(128) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `langcode` varchar(32) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The language code for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_hub_target_id` int(10) unsigned NOT NULL COMMENT 'The ID of the target entity.'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='Data storage for node field field_hub.';";
$query = $connection->query($query_string);
$result = $query->execute();


$connection = \Drupal::database();
$query_string = "CREATE TABLE IF NOT EXISTS `node_revision__field_hub` (
`bundle` varchar(128) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) unsigned NOT NULL COMMENT 'The entity revision id this data is attached to',
  `langcode` varchar(32) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The language code for this data item.',
  `delta` int(10) unsigned NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_hub_target_id` int(10) unsigned NOT NULL COMMENT 'The ID of the target entity.'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='Revision archive storage for node field field_hub.';";
$query = $connection->query($query_string);
$result = $query->execute();
*/


$bundles = [
    'blog_post',
    'custom_page',
    'customer_story',
    'document',
    'full_html',
    'homepage',
    'industry',
    'magazine',
    'product',
    'profile',
    'simple_page',
    'solution'
];

foreach ($bundles as $bundle) {
    $field = FieldConfig::loadByName('node', $bundle, 'field_hub');

    if (empty($field)) {
        $config_array = array(
            'field_name' => 'field_hub',
            'entity_type' => 'node',
            'bundle' => $bundle,
            'label' => 'hub',
            'required' => FALSE,
        );
        FieldConfig::create($config_array)->save();
    }
}


oabt_YmlImport('core.entity_form_display.node.blog_post.default.yml');
oabt_YmlImport('core.entity_form_display.node.custom_page.default.yml');
oabt_YmlImport('core.entity_form_display.node.customer_story.default.yml');
oabt_YmlImport('core.entity_form_display.node.document.default.yml');
oabt_YmlImport('core.entity_form_display.node.full_html.default.yml');
oabt_YmlImport('core.entity_form_display.node.homepage.default.yml');
oabt_YmlImport('core.entity_form_display.node.industry.default.yml');
oabt_YmlImport('core.entity_form_display.node.magazine.default.yml');
oabt_YmlImport('core.entity_form_display.node.product.default.yml');
oabt_YmlImport('core.entity_form_display.node.profile.default.yml');
oabt_YmlImport('core.entity_form_display.node.simple_page.default.yml');
oabt_YmlImport('core.entity_form_display.node.solution.default.yml');

oabt_YmlImport('core.entity_view_display.node.blog_post.default.yml');
oabt_YmlImport('core.entity_view_display.node.custom_page.default.yml');
oabt_YmlImport('core.entity_view_display.node.customer_story.default.yml');
oabt_YmlImport('core.entity_view_display.node.document.default.yml');
oabt_YmlImport('core.entity_view_display.node.full_html.default.yml');
oabt_YmlImport('core.entity_view_display.node.homepage.full.yml');
oabt_YmlImport('core.entity_view_display.node.industry.default.yml');
oabt_YmlImport('core.entity_view_display.node.magazine.default.yml');
oabt_YmlImport('core.entity_view_display.node.product.default.yml');
oabt_YmlImport('core.entity_view_display.node.profile.default.yml');
oabt_YmlImport('core.entity_view_display.node.simple_page.default.yml');
oabt_YmlImport('core.entity_view_display.node.solution.default.yml');

oabt_YmlImport('field.field.node.blog_post.field_hub.yml');
oabt_YmlImport('field.field.node.custom_page.field_hub.yml');
oabt_YmlImport('field.field.node.customer_story.field_hub.yml');
oabt_YmlImport('field.field.node.document.field_hub.yml');
oabt_YmlImport('field.field.node.full_html.field_hub.yml');
oabt_YmlImport('field.field.node.homepage.field_hub.yml');
oabt_YmlImport('field.field.node.industry.field_hub.yml');
oabt_YmlImport('field.field.node.magazine.field_hub.yml');
oabt_YmlImport('field.field.node.product.field_hub.yml');
oabt_YmlImport('field.field.node.profile.field_hub.yml');
oabt_YmlImport('field.field.node.simple_page.field_hub.yml');
oabt_YmlImport('field.field.node.solution.field_hub.yml');

