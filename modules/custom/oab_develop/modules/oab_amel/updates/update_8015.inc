<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * Configuration du type de contenu Product
 */

// CREATION DU FIELD ID FICHE
$field_storage = FieldStorageConfig::loadByName('node', 'field_id_fiche');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_id_fiche',
        'entity_type' => 'node',
        'type' => 'integer',
    ))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_id_fiche');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_id_fiche',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Id Fiche',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

// CREATION DU FIELD ID OFFRE
$field_storage = FieldStorageConfig::loadByName('node', 'field_id_offre');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_id_offre',
        'entity_type' => 'node',
        'type' => 'integer',
    ))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_id_offre');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_id_offre',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Id Offre',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}


// CREATION DU FIELD HIGHLIGHT

$field = FieldConfig::loadByName('node', 'product', 'field_highlight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_highlight',
        'entity_type' => 'node',
        'bundle' => 'product',
        'label' => 'Highlight',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}




$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.product.default');
$config_group->setData(
    array (
        'uuid' => '25a16d28-a765-4ea1-bcc0-dcbd469c1613',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.product.field_content',
                        1 => 'field.field.node.product.field_end_date',
                        2 => 'field.field.node.product.field_highlight',
                        3 => 'field.field.node.product.field_id_fiche',
                        4 => 'field.field.node.product.field_id_offre',
                        5 => 'field.field.node.product.field_industry',
                        6 => 'field.field.node.product.field_job_profile',
                        7 => 'field.field.node.product.field_market_segment',
                        8 => 'field.field.node.product.field_meta_description',
                        9 => 'field.field.node.product.field_meta_title',
                        10 => 'field.field.node.product.field_metatags',
                        11 => 'field.field.node.product.field_product',
                        12 => 'field.field.node.product.field_region',
                        13 => 'field.field.node.product.field_solution',
                        14 => 'field.field.node.product.field_start_date',
                        15 => 'field.field.node.product.field_sub_family',
                        16 => 'field.field.node.product.field_subhome',
                        17 => 'field.field.node.product.field_top_zone',
                        18 => 'node.type.product',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'field_group',
                        2 => 'metatag',
                        3 => 'path',
                        4 => 'text',
                        5 => 'workbench_moderation',
                    ),
            ),
        'third_party_settings' =>
            array (
                'field_group' =>
                    array (
                        'group_onglets' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'group_write',
                                        1 => 'group_classify',
                                        2 => 'group_publish',
                                        3 => 'group_seo',
                                    ),
                                'parent_name' => '',
                                'weight' => 0,
                                'format_type' => 'tabs',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'direction' => 'vertical',
                                    ),
                                'label' => 'Onglets',
                            ),
                        'group_write' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'langcode',
                                        1 => 'title',
                                        2 => 'field_highlight',
                                        3 => 'field_top_zone',
                                        4 => 'field_content',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 5,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Write',
                            ),
                        'group_publish' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'group_content_worthy_period',
                                        1 => 'path',
                                        2 => 'field_metatags',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 8,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Publish',
                            ),
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 9,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'SEO',
                            ),
                        'group_content_worthy_period' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_start_date',
                                        1 => 'field_end_date',
                                    ),
                                'parent_name' => 'group_publish',
                                'weight' => 20,
                                'format_type' => 'fieldset',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Content worthy period',
                            ),
                        'group_classify' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_solution',
                                        1 => 'field_industry',
                                        2 => 'field_region',
                                        3 => 'field_job_profile',
                                        4 => 'field_market_segment',
                                        5 => 'field_sub_family',
                                        6 => 'field_subhome',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 6,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Classify',
                            ),
                    ),
            ),
        'id' => 'node.product.default',
        'targetEntityType' => 'node',
        'bundle' => 'product',
        'mode' => 'default',
        'content' =>
            array (
                'field_content' =>
                    array (
                        'weight' => 6,
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'field_end_date' =>
                    array (
                        'weight' => 27,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_highlight' =>
                    array (
                        'weight' => 4,
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textarea',
                        'region' => 'content',
                    ),
                'field_industry' =>
                    array (
                        'weight' => 29,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_job_profile' =>
                    array (
                        'weight' => 31,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_market_segment' =>
                    array (
                        'weight' => 32,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_meta_description' =>
                    array (
                        'weight' => 14,
                        'settings' =>
                            array (
                                'size' => 156,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_meta_title' =>
                    array (
                        'weight' => 13,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string_textfield',
                        'region' => 'content',
                    ),
                'field_metatags' =>
                    array (
                        'weight' => 22,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'metatag_firehose',
                        'region' => 'content',
                    ),
                'field_product' =>
                    array (
                        'weight' => 1,
                        'settings' =>
                            array (
                                'match_operator' => 'CONTAINS',
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_autocomplete',
                        'region' => 'content',
                    ),
                'field_region' =>
                    array (
                        'weight' => 30,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_solution' =>
                    array (
                        'weight' => 28,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_start_date' =>
                    array (
                        'weight' => 26,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_sub_family' =>
                    array (
                        'weight' => 33,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_subhome' =>
                    array (
                        'weight' => 34,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_top_zone' =>
                    array (
                        'weight' => 5,
                        'settings' =>
                            array (
                                'rows' => 5,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_textarea',
                        'region' => 'content',
                    ),
                'langcode' =>
                    array (
                        'type' => 'language_select',
                        'weight' => 2,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'path' =>
                    array (
                        'type' => 'path',
                        'weight' => 21,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 3,
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_id_fiche' => true,
                'field_id_offre' => true,
                'promote' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);