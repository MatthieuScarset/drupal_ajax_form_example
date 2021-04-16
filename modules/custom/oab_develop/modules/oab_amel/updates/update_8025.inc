<?php
use Drupal\node\Entity\NodeType;

/******** Création du MENU menu-homepage-eclairage ***********/

echo('Création du MENU menu-homepage-eclairage \n');
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('system.menu.menu-homepage-eclairage');
$config_group->setData(
    array (
        'uuid' => 'b4277bd1-faea-4028-8c3e-2d7ce2821bb3',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'id' => 'menu-homepage-eclairage',
        'label' => 'Menu Homepage Eclairage',
        'description' => '',
        'locked' => false,
    )
);
$config_group->save(true);


/******** Création des NODE homepage_eclairage et hp_eclairage_thematique ***********/

echo('Création  des NODE homepage_eclairage et hp_eclairage_thematique \n');
$nodeStorage = NodeType::load('homepage_eclairage');
if (empty($nodeStorage)) {
    $nodeType = NodeType::create([
        'name' => 'Homepage Eclairage',
        'type' => 'homepage_eclairage',
    ]);
    $nodeType->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.homepage_eclairage');
$config_group->setData(
    array (
        'uuid' => '422a35b8-a953-459d-ae6d-1c25acba0b6a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'menu_ui',
                        1 => 'workbench_access',
                    ),
            ),
        'third_party_settings' =>
            array (
                'menu_ui' =>
                    array (
                        'available_menus' =>
                            array (
                                0 => 'main',
                            ),
                        'parent' => 'main:',
                    ),
                'workbench_access' =>
                    array (
                        'workbench_access_status' => false,
                    ),
            ),
        'name' => 'Homepage Eclairage',
        'type' => 'homepage_eclairage',
        'description' => '',
        'help' => '',
        'new_revision' => true,
        'preview_mode' => 1,
        'display_submitted' => true,
    )
);
$config_group->save(true);

$nodeStorage = NodeType::load('hp_eclairage_thematique');
if (empty($nodeStorage)) {
    $nodeType = NodeType::create([
        'name' => 'Homepage Eclairage Thématique',
        'type' => 'hp_eclairage_thematique',
    ]);
    $nodeType->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.hp_eclairage_thematique');
$config_group->setData(
    array (
        'uuid' => '8388d844-b6eb-4c75-80f1-7e9a9ccdf29f',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'menu_ui',
                        1 => 'workbench_access',
                    ),
            ),
        'third_party_settings' =>
            array (
                'menu_ui' =>
                    array (
                        'available_menus' =>
                            array (
                                0 => 'main',
                            ),
                        'parent' => 'main:',
                    ),
                'workbench_access' =>
                    array (
                        'workbench_access_status' => false,
                    ),
            ),
        'name' => 'Homepage Eclairage Thématique',
        'type' => 'hp_eclairage_thematique',
        'description' => '',
        'help' => '',
        'new_revision' => true,
        'preview_mode' => 1,
        'display_submitted' => true,
    )
);
$config_group->save(true);


/********************************  VIEW HOMEPAGE *********************************/
echo('Création  de la vue homepage');
//views.view.homepage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.homepage');
$config_group->setData(
    array (
        'uuid' => '8ff240b2-286c-49cd-b234-a7d5da4df360',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'node.type.homepage_eclairage',
                        1 => 'node.type.hp_eclairage_thematique',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'user',
                    ),
            ),
        'id' => 'homepage',
        'label' => 'Homepage',
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
                                                'perm' => 'access content overview',
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
                                        'type' => 'full',
                                        'options' =>
                                            array (
                                                'items_per_page' => 25,
                                                'offset' => 0,
                                                'id' => 0,
                                                'total_pages' => NULL,
                                                'tags' =>
                                                    array (
                                                        'previous' => '‹‹',
                                                        'next' => '››',
                                                        'first' => '« First',
                                                        'last' => 'Last »',
                                                    ),
                                                'expose' =>
                                                    array (
                                                        'items_per_page' => false,
                                                        'items_per_page_label' => 'Items per page',
                                                        'items_per_page_options' => '5, 10, 25, 50',
                                                        'items_per_page_options_all' => false,
                                                        'items_per_page_options_all_label' => '- All -',
                                                        'offset' => false,
                                                        'offset_label' => 'Offset',
                                                    ),
                                                'quantity' => 9,
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'table',
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'fields',
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
                                                'label' => 'Title',
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
                                                        'homepage_eclairage' => 'homepage_eclairage',
                                                        'hp_eclairage_thematique' => 'hp_eclairage_thematique',
                                                    ),
                                                'group' => '1',
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => false,
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
                                                        'remember' => 0,
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
                                        'created' =>
                                            array (
                                                'id' => 'created',
                                                'table' => 'node_field_data',
                                                'field' => 'created',
                                                'order' => 'DESC',
                                                'entity_type' => 'node',
                                                'entity_field' => 'created',
                                                'plugin_id' => 'date',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'label' => '',
                                                    ),
                                                'granularity' => 'second',
                                            ),
                                    ),
                                'title' => 'Homepage',
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
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => 0,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url.query_args',
                                        3 => 'user.node_grants:view',
                                        4 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                    ),
                            ),
                    ),
                'page_1' =>
                    array (
                        'display_plugin' => 'page',
                        'id' => 'page_1',
                        'display_title' => 'Page',
                        'position' => 1,
                        'display_options' =>
                            array (
                                'display_extenders' =>
                                    array (
                                    ),
                                'path' => 'admin/content/homepage',
                                'menu' =>
                                    array (
                                        'type' => 'tab',
                                        'title' => 'Homepage',
                                        'description' => '',
                                        'expanded' => false,
                                        'parent' => '',
                                        'weight' => 0,
                                        'context' => '0',
                                        'menu_name' => 'main',
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => 0,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url.query_args',
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
$config_group->save(true);


/*********************** IMAGE STYLES ****************************/
//valorisation (dans page thematique, zone de remontée automatique)
echo('Création  des style d\'images');
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.valorisation');
$config_group->setData(
    array (
        'uuid' => 'd5be9ce9-215f-4ebe-8761-0c99b4b48df3',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'name' => 'valorisation',
        'label' => 'Valorisation',
        'effects' =>
            array (
                '7e53e874-735a-4bb0-9ae3-a17934774c13' =>
                    array (
                        'uuid' => '7e53e874-735a-4bb0-9ae3-a17934774c13',
                        'id' => 'image_scale',
                        'weight' => 1,
                        'data' =>
                            array (
                                'width' => 310,
                                'height' => 150,
                                'upscale' => true,
                            ),
                    ),
                '089110c3-8826-4208-9ffd-592fd60beb19' =>
                    array (
                        'uuid' => '089110c3-8826-4208-9ffd-592fd60beb19',
                        'id' => 'image_resize',
                        'weight' => 2,
                        'data' =>
                            array (
                                'width' => 310,
                                'height' => 150,
                            ),
                    ),
            ),
    )
);
$config_group->save(true);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.playlist');
$config_group->setData(
    array (
        'uuid' => '3f7f8fb7-2c9a-445b-9085-4e436199fba8',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'name' => 'playlist',
        'label' => 'Playlist',
        'effects' =>
            array (
                'e00cc62f-9846-4053-b20d-c3c0e9c6b323' =>
                    array (
                        'uuid' => 'e00cc62f-9846-4053-b20d-c3c0e9c6b323',
                        'id' => 'image_scale',
                        'weight' => 3,
                        'data' =>
                            array (
                                'width' => 310,
                                'height' => 165,
                                'upscale' => true,
                            ),
                    ),
                '2b031ea3-03ad-4564-8612-782932962b33' =>
                    array (
                        'uuid' => '2b031ea3-03ad-4564-8612-782932962b33',
                        'id' => 'image_resize',
                        'weight' => 2,
                        'data' =>
                            array (
                                'width' => 310,
                                'height' => 165,
                            ),
                    ),
            ),
    )
);
$config_group->save(true);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.home_playlist_image');
$config_group->setData(
    array (
        'uuid' => '073b9878-ea2c-4f5a-a517-a36a1035cc29',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'media_entity',
                    ),
            ),
        'id' => 'media.home_playlist_image',
        'label' => 'Home Playlist image',
        'targetEntityType' => 'media',
        'cache' => true,
    )
);
$config_group->save(true);

//core.entity_view_display.media.image.home_playlist_image
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.media.image.home_playlist_image');
$config_group->setData(
    array (
        'uuid' => '2e278d9e-684d-453e-a3de-fb68a20c3671',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.media.home_playlist_image',
                        1 => 'field.field.media.image.field_image',
                        2 => 'field.field.media.image.field_tags',
                        3 => 'field.field.media.image.field_thematic',
                        4 => 'image.style.playlist',
                        5 => 'media_entity.bundle.image',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                    ),
            ),
        'id' => 'media.image.home_playlist_image',
        'targetEntityType' => 'media',
        'bundle' => 'image',
        'mode' => 'home_playlist_image',
        'content' =>
            array (
                'field_image' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => 'playlist',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_tags' => true,
                'field_thematic' => true,
                'langcode' => true,
                'name' => true,
                'thumbnail' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);









