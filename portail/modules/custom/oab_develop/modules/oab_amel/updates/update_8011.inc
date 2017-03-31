<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.related_contents');
$config_group->setData(
    array (
        'uuid' => '4704129d-4be6-4a15-8e71-0636a1fa0bc1',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'node.type.blog_post',
                        2 => 'node.type.customer_story',
                        3 => 'node.type.document',
                        4 => 'node.type.industry',
                        5 => 'node.type.magazine',
                        6 => 'node.type.partner',
                        7 => 'node.type.press_kit',
                        8 => 'node.type.press_release',
                        9 => 'node.type.product',
                        10 => 'node.type.region',
                        11 => 'node.type.simple_page',
                        12 => 'node.type.solution',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'user',
                    ),
            ),
        'id' => 'related_contents',
        'label' => 'Related Contents',
        'module' => 'views',
        'description' => '',
        'tag' => '',
        'base_table' => 'node_field_data',
        'base_field' => 'nid',
        'core' => '8.x',
        'display' =>
            array (
                'default' =>
                    array (
                        'display_plugin' => 'default',
                        'id' => 'default',
                        'display_title' => 'Master',
                        'position' => 0,
                        'display_options' =>
                            array (
                                'access' =>
                                    array (
                                        'type' => 'perm',
                                        'options' =>
                                            array (
                                                'perm' => 'access content',
                                            ),
                                    ),
                                'cache' =>
                                    array (
                                        'type' => 'tag',
                                        'options' =>
                                            array (
                                            ),
                                    ),
                                'query' =>
                                    array (
                                        'type' => 'views_query',
                                        'options' =>
                                            array (
                                                'disable_sql_rewrite' => false,
                                                'distinct' => false,
                                                'replica' => false,
                                                'query_comment' => '',
                                                'query_tags' =>
                                                    array (
                                                    ),
                                            ),
                                    ),
                                'exposed_form' =>
                                    array (
                                        'type' => 'basic',
                                        'options' =>
                                            array (
                                                'submit_button' => 'Apply',
                                                'reset_button' => false,
                                                'reset_button_label' => 'Reset',
                                                'exposed_sorts_label' => 'Sort by',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array (
                                        'type' => 'some',
                                        'options' =>
                                            array (
                                                'items_per_page' => 3,
                                                'offset' => 0,
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'grid',
                                        'options' =>
                                            array (
                                                'uses_fields' => false,
                                                'columns' => 3,
                                                'automatic_width' => true,
                                                'alignment' => 'horizontal',
                                                'col_class_default' => true,
                                                'col_class_custom' => '',
                                                'row_class_default' => true,
                                                'row_class_custom' => '',
                                            ),
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'entity:node',
                                        'options' =>
                                            array (
                                                'relationship' => 'none',
                                                'view_mode' => 'related_content',
                                            ),
                                    ),
                                'fields' =>
                                    array (
                                        'title' =>
                                            array (
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                                'label' => '',
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'make_link' => false,
                                                        'absolute' => false,
                                                        'trim' => false,
                                                        'word_boundary' => false,
                                                        'ellipsis' => false,
                                                        'strip_tags' => false,
                                                        'html' => false,
                                                    ),
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => true,
                                                    ),
                                                'plugin_id' => 'field',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'exclude' => false,
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'string',
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array (
                                                    ),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                            ),
                                    ),
                                'filters' =>
                                    array (
                                        'status' =>
                                            array (
                                                'value' => '1',
                                                'table' => 'node_field_data',
                                                'field' => 'status',
                                                'plugin_id' => 'boolean',
                                                'entity_type' => 'node',
                                                'entity_field' => 'status',
                                                'id' => 'status',
                                                'expose' =>
                                                    array (
                                                        'operator' => '',
                                                    ),
                                                'group' => 1,
                                            ),
                                        'type' =>
                                            array (
                                                'id' => 'type',
                                                'table' => 'node_field_data',
                                                'field' => 'type',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'in',
                                                'value' =>
                                                    array (
                                                        'blog_post' => 'blog_post',
                                                        'customer_story' => 'customer_story',
                                                        'press_release' => 'press_release',
                                                        'document' => 'document',
                                                        'press_kit' => 'press_kit',
                                                        'industry' => 'industry',
                                                        'magazine' => 'magazine',
                                                        'simple_page' => 'simple_page',
                                                        'partner' => 'partner',
                                                        'product' => 'product',
                                                        'region' => 'region',
                                                        'solution' => 'solution',
                                                    ),
                                                'group' => 1,
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => '',
                                                        'label' => '',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => '',
                                                        'identifier' => '',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                            ),
                                                        'reduce' => false,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'entity_type' => 'node',
                                                'entity_field' => 'type',
                                                'plugin_id' => 'bundle',
                                            ),
                                    ),
                                'sorts' =>
                                    array (
                                        'changed' =>
                                            array (
                                                'id' => 'changed',
                                                'table' => 'node_field_data',
                                                'field' => 'changed',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'order' => 'DESC',
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'label' => '',
                                                    ),
                                                'granularity' => 'second',
                                                'entity_type' => 'node',
                                                'entity_field' => 'changed',
                                                'plugin_id' => 'date',
                                            ),
                                    ),
                                'title' => 'Related Contents',
                                'header' =>
                                    array (
                                    ),
                                'footer' =>
                                    array (
                                    ),
                                'empty' =>
                                    array (
                                    ),
                                'relationships' =>
                                    array (
                                    ),
                                'arguments' =>
                                    array (
                                        'nid' =>
                                            array (
                                                'id' => 'nid',
                                                'table' => 'node_field_data',
                                                'field' => 'nid',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'default_action' => 'default',
                                                'exception' =>
                                                    array (
                                                        'value' => 'all',
                                                        'title_enable' => false,
                                                        'title' => 'All',
                                                    ),
                                                'title_enable' => false,
                                                'title' => '',
                                                'default_argument_type' => 'node',
                                                'default_argument_options' =>
                                                    array (
                                                    ),
                                                'default_argument_skip_url' => false,
                                                'summary_options' =>
                                                    array (
                                                        'base_path' => '',
                                                        'count' => true,
                                                        'items_per_page' => 25,
                                                        'override' => false,
                                                    ),
                                                'summary' =>
                                                    array (
                                                        'sort_order' => 'asc',
                                                        'number_of_records' => 0,
                                                        'format' => 'default_summary',
                                                    ),
                                                'specify_validation' => false,
                                                'validate' =>
                                                    array (
                                                        'type' => 'none',
                                                        'fail' => 'not found',
                                                    ),
                                                'validate_options' =>
                                                    array (
                                                    ),
                                                'break_phrase' => false,
                                                'not' => true,
                                                'entity_type' => 'node',
                                                'entity_field' => 'nid',
                                                'plugin_id' => 'node_nid',
                                            ),
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                    ),
                            ),
                    ),
                'block_1' =>
                    array (
                        'display_plugin' => 'block',
                        'id' => 'block_1',
                        'display_title' => 'Block',
                        'position' => 1,
                        'display_options' =>
                            array (
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                    ),
                            ),
                    ),
            ),
    )
);
$config_group->save(TRUE);



// Mode de rendu subhome pour les Produits

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.product.subhome');
$config_group->setData(
    array (
        'uuid' => '5ccac2f5-5357-4d2f-b3ae-a04b42c1d9a3',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
                        1 => 'field.field.node.product.field_content',
                        2 => 'field.field.node.product.field_end_date',
                        3 => 'field.field.node.product.field_industry',
                        4 => 'field.field.node.product.field_job_profile',
                        5 => 'field.field.node.product.field_market_segment',
                        6 => 'field.field.node.product.field_meta_description',
                        7 => 'field.field.node.product.field_meta_title',
                        8 => 'field.field.node.product.field_metatags',
                        9 => 'field.field.node.product.field_region',
                        10 => 'field.field.node.product.field_solution',
                        11 => 'field.field.node.product.field_start_date',
                        12 => 'field.field.node.product.field_sub_family',
                        13 => 'field.field.node.product.field_subhome',
                        14 => 'field.field.node.product.field_top_zone',
                        15 => 'node.type.product',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.product.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'product',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_solution' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_end_date' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_start_date' => true,
                'field_sub_family' => true,
                'field_subhome' => true,
                'field_top_zone' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);


// Mode de rendu subhome pour les PROFILS

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.profile.subhome');
$config_group->setData(
    array (
        'uuid' => 'bab46afa-7fe1-4e6f-9f8e-56e56c33bad9',
        'langcode' => 'fr',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
                        1 => 'field.field.node.profile.body',
                        2 => 'field.field.node.profile.field_first_name',
                        3 => 'field.field.node.profile.field_job',
                        4 => 'field.field.node.profile.field_last_name',
                        5 => 'field.field.node.profile.field_link',
                        6 => 'field.field.node.profile.field_location',
                        7 => 'field.field.node.profile.field_metatags',
                        8 => 'field.field.node.profile.field_social_accounts',
                        9 => 'field.field.node.profile.field_visual',
                        10 => 'node.type.profile',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.profile.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'profile',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_first_name' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                    ),
                'field_last_name' =>
                    array (
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                    ),
            ),
        'hidden' =>
            array (
                'body' => true,
                'field_job' => true,
                'field_link' => true,
                'field_location' => true,
                'field_metatags' => true,
                'field_social_accounts' => true,
                'field_visual' => true,
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(TRUE);


// Mode de rendu subhome pour les Blog Post avec le rendered Subhom pour le profil Blogger

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.subhome');
$config_group->setData(
    array (
        'uuid' => '081a6208-fadb-4086-8ff2-d20d83fe8213',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
                        1 => 'field.field.node.blog_post.field_content',
                        2 => 'field.field.node.blog_post.field_content_owner',
                        3 => 'field.field.node.blog_post.field_display_title',
                        4 => 'field.field.node.blog_post.field_email_owner',
                        5 => 'field.field.node.blog_post.field_end_date',
                        6 => 'field.field.node.blog_post.field_highlight',
                        7 => 'field.field.node.blog_post.field_industry',
                        8 => 'field.field.node.blog_post.field_job_profile',
                        9 => 'field.field.node.blog_post.field_market_segment',
                        10 => 'field.field.node.blog_post.field_meta_description',
                        11 => 'field.field.node.blog_post.field_meta_title',
                        12 => 'field.field.node.blog_post.field_metatags',
                        13 => 'field.field.node.blog_post.field_profile',
                        14 => 'field.field.node.blog_post.field_region',
                        15 => 'field.field.node.blog_post.field_solution',
                        16 => 'field.field.node.blog_post.field_start_date',
                        17 => 'field.field.node.blog_post.field_subhome',
                        18 => 'field.field.node.blog_post.field_visual',
                        19 => 'field.field.node.blog_post.publish_date',
                        20 => 'field.field.node.blog_post.unpublish_date',
                        21 => 'node.type.blog_post',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.blog_post.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'blog_post',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_profile' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'publish_date' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'unpublish_date' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

