<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * RUBYPORTAILOBS-3309 [OC] gestion du partage portail / hub
 */


$field_storage = FieldStorageConfig::loadByName('node', 'field_hub_portal');

if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_hub_portal',
        'entity_type' => 'node',
        'type' => 'boolean'
    ))->save();
}

oabt_YmlImport('field.storage.node.field_hub_portal.yml');

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
    $field = FieldConfig::loadByName('node', $bundle, 'field_hub_portal');

    if (empty($field)) {
        $config_array = array(
            'field_name' => 'field_hub_portal',
            'entity_type' => 'node',
            'bundle' => $bundle,
            'label' => 'partagé sur le portail',
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

oabt_YmlImport('field.field.node.blog_post.field_hub_portal.yml');
oabt_YmlImport('field.field.node.custom_page.field_hub_portal.yml');
oabt_YmlImport('field.field.node.customer_story.field_hub_portal.yml');
oabt_YmlImport('field.field.node.document.field_hub_portal.yml');
oabt_YmlImport('field.field.node.full_html.field_hub_portal.yml');
oabt_YmlImport('field.field.node.homepage.field_hub_portal.yml');
oabt_YmlImport('field.field.node.industry.field_hub_portal.yml');
oabt_YmlImport('field.field.node.magazine.field_hub_portal.yml');
oabt_YmlImport('field.field.node.product.field_hub_portal.yml');
oabt_YmlImport('field.field.node.profile.field_hub_portal.yml');
oabt_YmlImport('field.field.node.simple_page.field_hub_portal.yml');
oabt_YmlImport('field.field.node.solution.field_hub_portal.yml');

oabt_YmlImport('user.role.chief_editor_hub.yml');
