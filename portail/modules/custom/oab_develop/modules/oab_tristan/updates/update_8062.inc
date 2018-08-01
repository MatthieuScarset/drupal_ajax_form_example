<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\paragraphs\Entity\ParagraphsType;

##Création du paragraph type
$paragraphType = ParagraphsType::load('rebond_wysiwyg');
if (empty($paragraphType)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'rebond_wysiwyg',
        'label' => 'Rebond wysiwyg',
        'revision' => false
    ]);
    $paragraphType->save();
}
oabt_YmlImport("paragraphs.paragraphs_type.rebond_wysiwyg.yml");


$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_p_wysiwyg_rebond_color');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_p_wysiwyg_rebond_color',
        'entity_type' => 'paragraph',
        'type' => 'list_string',
    ))->save();
}
oabt_YmlImport("field.storage.paragraph.field_p_wysiwyg_rebond_color.yml");
oabt_YmlImport("field.field.paragraph.rebond_wysiwyg.field_p_wysiwyg_rebond_color.yml");

oabt_YmlImport("core.entity_view_display.paragraph.rebond_wysiwyg.default.yml");
oabt_YmlImport("core.entity_form_display.paragraph.rebond_wysiwyg.default.yml");


###Création du field storage du field pour les node content
$field_storage = FieldStorageConfig::loadByName('node', 'field_p_wysiwyg_rebond');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'node',
                        2 => 'paragraphs',
                    ),
            ),
        'id' => 'node.field_p_wysiwyg_rebond',
        'field_name' => 'field_p_wysiwyg_rebond',
        'entity_type' => 'node',
        'type' => 'entity_reference_revisions',
        'settings' =>
            array (
                'target_type' => 'paragraph',
            ),
        'module' => 'entity_reference_revisions',
        'locked' => false,
        'cardinality' => -1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    ))->save();
}

##########################################################
##########################################################
##Rechargement des configs pour tous les types de contenus


##Fields
oabt_YmlImport("field.field.node.blog_post.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.customer_story.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.document.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.magazine.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.partner.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.press_release.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.simple_page.field_p_wysiwyg_rebond.yml");
oabt_YmlImport("field.field.node.webform.field_p_wysiwyg_rebond.yml");

##Display views
oabt_YmlImport("core.entity_view_display.node.blog_post.default.yml");
oabt_YmlImport("core.entity_view_display.node.customer_story.default.yml");
oabt_YmlImport("core.entity_view_display.node.document.default.yml");
oabt_YmlImport("core.entity_view_display.node.magazine.default.yml");
oabt_YmlImport("core.entity_view_display.node.partner.default.yml");
oabt_YmlImport("core.entity_view_display.node.press_release.default.yml");
oabt_YmlImport("core.entity_view_display.node.simple_page.default.yml");
oabt_YmlImport("core.entity_view_display.node.webform.default.yml");

##Form Display
oabt_YmlImport("core.entity_form_display.node.blog_post.default.yml");
oabt_YmlImport("core.entity_form_display.node.customer_story.default.yml");
oabt_YmlImport("core.entity_form_display.node.document.default.yml");
oabt_YmlImport("core.entity_form_display.node.magazine.default.yml");
oabt_YmlImport("core.entity_form_display.node.partner.default.yml");
oabt_YmlImport("core.entity_form_display.node.press_release.default.yml");
oabt_YmlImport("core.entity_form_display.node.simple_page.default.yml");
oabt_YmlImport("core.entity_form_display.node.webform.default.yml");



$contentTypes = [
    'blog_post',
    'customer_story',
    'document',
    'magazine',
    'partner',
    'press_release',
    'simple_page',
    'webform'
];


$oldFieldName = "field_wysiwyg_rebond";
foreach ($contentTypes as $contentType) {
    #j'en profite pour supprimer l'ancien field basique s'il avait été créé
    $field_toDel = FieldConfig::loadByName('node', $contentType, $oldFieldName);
    if ($field_toDel !== null) {
        $field_toDel->delete();
    }
}

##Et je supprime le field storage à la fin
$field_storage = FieldStorageConfig::loadByName('node', 'field_wysiwyg_rebond');
if ($field_storage!== null) {
    $field_storage->delete();
}