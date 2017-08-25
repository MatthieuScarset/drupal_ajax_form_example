<?php


use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

use Drupal\paragraphs\Entity\ParagraphsType;


/******** Création du MENU menu-homepage-eclairage ***********/


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



/******** Création des PARAGRAPHES ***********
 *   banner
 *   columns
 *   column section
 *   playlist
 */

// création du bundle de paragraph paragraphs.paragraphs_type.home_banner
$paragraphStorage = ParagraphsType::load('home_banner');
if(empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_banner',
        'label' => 'Home Banner',
        'revision' => false
    ]);
    $paragraphType->save();
}

// création des champs pour le paragraph paragraphs.paragraphs_type.home_banner
/****** storage ******/
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_title');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'type' => 'string',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_big_image_desktop_');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_big_image_desktop_',
        'entity_type' => 'paragraph',
        'type' => 'image',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_date');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_date',
        'entity_type' => 'paragraph',
        'type' => 'datetime',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_function');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_function',
        'entity_type' => 'paragraph',
        'type' => 'string',
        'settings' => array (
            'max_length' => 156,
            'is_ascii' => false,
            'case_sensitive' => false,
        ),
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_image_mobile');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_image_mobile',
        'entity_type' => 'paragraph',
        'type' => 'image',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_link',
        'entity_type' => 'paragraph',
        'type' => 'string',
        'settings' =>
            array (
                'max_length' => 255,
                'is_ascii' => false,
                'case_sensitive' => false,
            ),
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_little_image_desktop');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_little_image_desktop',
        'entity_type' => 'paragraph',
        'type' => 'image',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_name');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_name',
        'entity_type' => 'paragraph',
        'type' => 'string',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}


$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_text_color');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_text_color',
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'options',
                        1 => 'paragraphs',
                    ),
            ),
        'entity_type' => 'paragraph',
        'type' => 'list_string',
        'settings' =>
            array (
                'allowed_values' =>
                    array (
                        0 =>
                            array (
                                'value' => 'white',
                                'label' => 'White',
                            ),
                        1 =>
                            array (
                                'value' => 'black',
                                'label' => 'Black',
                            ),
                    ),
                'allowed_values_function' => '',
            ),
        'module' => 'options',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}


/****** instances ******/
$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_title');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'title',
        'required' => TRUE,
        'translatable' => false,
        'language' => 'en',
        'field_type' => 'string',
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_text_color');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_text_color',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Text Color',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array(
                0 =>
                    array(
                        'value' => 'black',
                    ),
            ),
        'field_type' => 'list_string',
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_name');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_name',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'language' => 'en',
        'field_type' => 'string',
        'label' => 'Name',
        'description' => '',
        'required' => false,
        'translatable' => false,
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_little_image_desktop');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_little_image_desktop',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Little Image Desktop',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'file_directory' => '[date:custom:Y]-[date:custom:m]',
                'file_extensions' => 'png gif jpg jpeg',
                'max_filesize' => '',
                'max_resolution' => '',
                'min_resolution' => '',
                'alt_field' => true,
                'alt_field_required' => false,
                'title_field' => false,
                'title_field_required' => false,
                'default_image' =>
                    array (
                        'uuid' => '',
                        'alt' => '',
                        'title' => '',
                        'width' => NULL,
                        'height' => NULL,
                    ),
                'handler' => 'default:file',
            ),
        'field_type' => 'image',
    );
    FieldConfig::create($config_array)->save();
}


$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_link');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_link',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'language' => 'en',
        'field_type' => 'string',
        'label' => 'Link',
        'description' => '',
        'required' => false,
        'translatable' => false,
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_image_mobile');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_image_mobile',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'language' => 'en',
        'label' => 'Image Mobile',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'file_directory' => '[date:custom:Y]-[date:custom:m]',
                'file_extensions' => 'png gif jpg jpeg',
                'max_filesize' => '',
                'max_resolution' => '',
                'min_resolution' => '',
                'alt_field' => true,
                'alt_field_required' => false,
                'title_field' => false,
                'title_field_required' => false,
                'default_image' =>
                    array (
                        'uuid' => '',
                        'alt' => '',
                        'title' => '',
                        'width' => NULL,
                        'height' => NULL,
                    ),
                'handler' => 'default:file',
                'handler_settings' =>
                    array (
                    ),
            ),
        'field_type' => 'image',
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_function');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_function',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'language' => 'en',
        'field_type' => 'string',
        'label' => 'Function',
        'required' => false,
        'translatable' => false,
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_date');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_date',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'language' => 'en',
        'field_type' => 'datetime',
        'label' => 'Date',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
                0 =>
                    array (
                        'default_date_type' => 'now',
                        'default_date' => 'now',
                    ),
            ),
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_big_image_desktop_');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_big_image_desktop_',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Big Image Desktop ',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'file_directory' => '[date:custom:Y]-[date:custom:m]',
                'file_extensions' => 'png gif jpg jpeg',
                'max_filesize' => '',
                'max_resolution' => '',
                'min_resolution' => '',
                'alt_field' => true,
                'alt_field_required' => false,
                'title_field' => false,
                'title_field_required' => false,
                'default_image' =>
                    array (
                        'uuid' => '',
                        'alt' => '',
                        'title' => '',
                        'width' => NULL,
                        'height' => NULL,
                    ),
                'handler' => 'default:file',
                'handler_settings' =>
                    array (
                    ),
            ),
        'field_type' => 'image',
    );
    FieldConfig::create($config_array)->save();
}


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.home_banner.default');
$config_group->setData(
    array (
        'uuid' => 'c2f94d7f-df9b-40b3-a3b8-25c1d4fc6fc4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_banner.field_big_image_desktop_',
                        1 => 'field.field.paragraph.home_banner.field_date',
                        2 => 'field.field.paragraph.home_banner.field_function',
                        3 => 'field.field.paragraph.home_banner.field_image_mobile',
                        4 => 'field.field.paragraph.home_banner.field_link',
                        5 => 'field.field.paragraph.home_banner.field_little_image_desktop',
                        6 => 'field.field.paragraph.home_banner.field_name',
                        7 => 'field.field.paragraph.home_banner.field_text_color',
                        8 => 'field.field.paragraph.home_banner.field_title',
                        9 => 'image.style.thumbnail',
                        10 => 'paragraphs.paragraphs_type.home_banner',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'image',
                        2 => 'workbench_moderation',
                    ),
            ),
        'id' => 'paragraph.home_banner.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_banner',
        'mode' => 'default',
        'content' =>
            array (
                'field_big_image_desktop_' =>
                    array (
                        'weight' => 11,
                        'settings' =>
                            array (
                                'progress_indicator' => 'throbber',
                                'preview_image_style' => 'thumbnail',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_date' =>
                    array (
                        'weight' => 6,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_function' =>
                    array (
                        'weight' => 9,
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
                'field_image_mobile' =>
                    array (
                        'weight' => 13,
                        'settings' =>
                            array (
                                'progress_indicator' => 'throbber',
                                'preview_image_style' => 'thumbnail',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_link' =>
                    array (
                        'weight' => 10,
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
                'field_little_image_desktop' =>
                    array (
                        'weight' => 12,
                        'settings' =>
                            array (
                                'progress_indicator' => 'throbber',
                                'preview_image_style' => 'thumbnail',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_name' =>
                    array (
                        'weight' => 8,
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
                'field_text_color' =>
                    array (
                        'weight' => 14,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_title' =>
                    array (
                        'weight' => 7,
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
            ),
        'hidden' =>
            array (
                'created' => true,
                'status' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.home_banner.default');
$config_group->setData(
    array (
        'uuid' => 'e403b136-e810-472b-8bae-e6cc4aef1e87',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_banner.field_big_image_desktop_',
                        1 => 'field.field.paragraph.home_banner.field_date',
                        2 => 'field.field.paragraph.home_banner.field_function',
                        3 => 'field.field.paragraph.home_banner.field_image_mobile',
                        4 => 'field.field.paragraph.home_banner.field_link',
                        5 => 'field.field.paragraph.home_banner.field_little_image_desktop',
                        6 => 'field.field.paragraph.home_banner.field_name',
                        7 => 'field.field.paragraph.home_banner.field_text_color',
                        8 => 'field.field.paragraph.home_banner.field_title',
                        9 => 'paragraphs.paragraphs_type.home_banner',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'image',
                        2 => 'options',
                    ),
            ),
        'id' => 'paragraph.home_banner.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_banner',
        'mode' => 'default',
        'content' =>
            array (
                'field_big_image_desktop_' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
                'field_date' =>
                    array (
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'format_type' => 'medium',
                                'timezone_override' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_function' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_image_mobile' =>
                    array (
                        'weight' => 7,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
                'field_link' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_little_image_desktop' =>
                    array (
                        'weight' => 6,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
                'field_name' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_text_color' =>
                    array (
                        'weight' => 8,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'list_default',
                        'region' => 'content',
                    ),
                'field_title' =>
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
            ),
    )
);
$config_group->save(true);


$field_storage = FieldStorageConfig::loadByName('node', 'field_home_banner');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_home_banner',
        'entity_type' => 'node',
        'type' => 'entity_reference_revisions',
        'cardinality' => 4,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'node',
                        2 => 'paragraphs',
                    ),
            ),
        'settings' =>
            array (
                'target_type' => 'paragraph',
            ),
        'module' => 'entity_reference_revisions',
        'locked' => false,
        'cardinality' => 4,
        'translatable' => true,
    ))->save();
}

$config_group->save(TRUE);
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_home_banner');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_home_banner',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Home Banner',
        'required' => FALSE,
        'settings' =>
            array (
                'handler' => 'default:paragraph',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'home_banner' => 'home_banner',
                            ),
                        'target_bundles_drag_drop' =>
                            array (
                                'home_banner' =>
                                    array (
                                        'enabled' => true,
                                        'weight' => 3,
                                    ),
                                'home_column' =>
                                    array (
                                        'weight' => 4,
                                        'enabled' => false,
                                    ),
                            ),
                    ),
            ),
        'field_type' => 'entity_reference_revisions',
    );
    FieldConfig::create($config_array)->save();
}








/********************************* PARAGRAPHE HOME COLUMN *********************************/

/********* Paragraphe storage **********/
// création du bundle de paragraph paragraphs.paragraphs_type.home_column
$paragraphStorage = ParagraphsType::load('home_banner');
if(empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_column',
        'label' => 'Home Column',
        'revision' => false
    ]);
    $paragraphType->save();
}


/********* Fields storage in paragraph **********/


//field_title

// création des champs pour le paragraph paragraphs.paragraphs_type.home_column
/****** storage ******/
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_solaris_icon');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_solaris_icon',
        'entity_type' => 'paragraph',
        'type' => 'image',
        'module' => 'image',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => false,
    ))->save();
}


$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_column_section');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_column_section',
        'entity_type' => 'paragraph',
        'type' => 'entity_reference_revisions',
        'module' => 'entity_reference_revisions',
        'locked' => false,
        'cardinality' => 2,
        'translatable' => false,
    ))->save();
}


/********* Instances of fields **********/


$field = FieldConfig::loadByName('paragraph', 'home_column', 'field_title');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column',
        'label' => 'Column Title',
        'required' => true,
        'translatable' => false,
        'field_type' => 'string',
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_column', 'field_solaris_icon');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_solaris_icon',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column',
        'label' => 'Solaris icon',
        'required' => true,
        'translatable' => false,
        'settings' =>
            array (
                'file_directory' => '[date:custom:Y]-[date:custom:m]',
                'file_extensions' => 'png gif jpg jpeg',
                'max_filesize' => '',
                'max_resolution' => '',
                'min_resolution' => '',
                'alt_field' => true,
                'alt_field_required' => false,
                'title_field' => false,
                'title_field_required' => false,
                'default_image' =>
                    array (
                        'uuid' => '',
                        'alt' => '',
                        'title' => '',
                        'width' => NULL,
                        'height' => NULL,
                    ),
                'handler' => 'default:file',
                'handler_settings' =>
                    array (
                    ),
            ),
        'field_type' => 'image',
    );
    FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'home_column', 'field_column_section');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_column_section',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column',
        'label' => 'Column_section',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'handler' => 'default:paragraph',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'home_column_section' => 'home_column_section',
                            ),
                        'target_bundles_drag_drop' =>
                            array (
                                'home_banner' =>
                                    array (
                                        'weight' => 4,
                                        'enabled' => false,
                                    ),
                                'home_column' =>
                                    array (
                                        'weight' => 5,
                                        'enabled' => false,
                                    ),
                                'home_column_section' =>
                                    array (
                                        'enabled' => true,
                                        'weight' => 6,
                                    ),
                            ),
                    ),
            ),
        'field_type' => 'entity_reference_revisions',
    );
    FieldConfig::create($config_array)->save();
}

/********* Form display et View display of Paragraph **********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.home_column.default');
$config_group->setData(
    array (
        'uuid' => '0c095571-e0fd-4669-9716-e36135161d08',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_column.field_column_section',
                        1 => 'field.field.paragraph.home_column.field_solaris_icon',
                        2 => 'field.field.paragraph.home_column.field_title',
                        3 => 'image.style.thumbnail',
                        4 => 'paragraphs.paragraphs_type.home_column',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                        1 => 'paragraphs',
                        2 => 'workbench_moderation',
                    ),
            ),
        'id' => 'paragraph.home_column.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_column',
        'mode' => 'default',
        'content' =>
            array (
                'field_column_section' =>
                    array (
                        'type' => 'entity_reference_paragraphs',
                        'weight' => 3,
                        'settings' =>
                            array (
                                'title' => 'Paragraph',
                                'title_plural' => 'Paragraphs',
                                'edit_mode' => 'open',
                                'add_mode' => 'dropdown',
                                'form_display_mode' => 'default',
                                'default_paragraph_type' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_solaris_icon' =>
                    array (
                        'weight' => 0,
                        'settings' =>
                            array (
                                'progress_indicator' => 'throbber',
                                'preview_image_style' => 'thumbnail',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 1,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'status' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.home_column.default');
$config_group->setData(
    array (
        'uuid' => '1c32df67-479c-492a-9958-031725a96799',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_column.field_column_section',
                        1 => 'field.field.paragraph.home_column.field_solaris_icon',
                        2 => 'field.field.paragraph.home_column.field_title',
                        3 => 'paragraphs.paragraphs_type.home_column',
                    ),
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'image',
                    ),
            ),
        'id' => 'paragraph.home_column.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_column',
        'mode' => 'default',
        'content' =>
            array (
                'field_column_section' =>
                    array (
                        'type' => 'entity_reference_revisions_entity_view',
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_solaris_icon' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
                'field_title' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
            ),
    )
);
$config_group->save(true);




/********* Field storage in node **********/


$field_storage = FieldStorageConfig::loadByName('node', 'field_home_columns');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'node',
                        2 => 'paragraphs',
                    ),
            ),
        'id' => 'node.field_home_columns',
        'field_name' => 'field_home_columns',
        'entity_type' => 'node',
        'type' => 'entity_reference_revisions',
        'settings' =>
            array (
                'target_type' => 'paragraph',
            ),
        'module' => 'entity_reference_revisions',
        'locked' => false,
        'cardinality' => 3,
        'translatable' => true,
    ))->save();
}

$config_group->save(TRUE);
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_home_banner');
if(empty($field)) {
    $config_array = array(
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_home_columns',
                        1 => 'node.type.homepage_eclairage',
                        2 => 'paragraphs.paragraphs_type.home_column',
                    ),
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                    ),
            ),
        'field_name' => 'field_home_columns',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Home Columns',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'handler' => 'default:paragraph',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'home_column' => 'home_column',
                            ),
                        'target_bundles_drag_drop' =>
                            array (
                                'home_banner' =>
                                    array (
                                        'weight' => 5,
                                        'enabled' => false,
                                    ),
                                'home_column' =>
                                    array (
                                        'enabled' => true,
                                        'weight' => 6,
                                    ),
                                'home_column_section' =>
                                    array (
                                        'weight' => 7,
                                        'enabled' => false,
                                    ),
                                'home_playlist' =>
                                    array (
                                        'weight' => 8,
                                        'enabled' => false,
                                    ),
                            ),
                    ),
            ),
        'field_type' => 'entity_reference_revisions',
    );
    FieldConfig::create($config_array)->save();
}





/********************************  PARAGRAPHE HOME COLUMN SECTION *********************************/

/********* Paragraph storage **********/
// création du bundle de paragraph paragraphs.paragraphs_type.home_column_section
$paragraphStorage = ParagraphsType::load('home_column_section');
if(empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_column_section',
        'label' => 'Home column section',
        'revision' => false
    ]);
    $paragraphType->save();
}


/********* Fields storage in paragraph **********/
//field_function done
//field_link done
//field_name done
//field_title done

//field_image
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_image');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_image',
        'entity_type' => 'paragraph',
        'type' => 'image',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}


//field_link_title
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link_title');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'id' => 'paragraph.field_link_title',
        'field_name' => 'field_link_title',
        'entity_type' => 'paragraph',
        'type' => 'link',
        'cardinality' => 1,
        'translatable' => false,
        'language' => 'en',
    ))->save();
}


/********* Instances of fields **********/

//field_image
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_image');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_image',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Image',
        'description' => '',
        'required' => true,
        'translatable' => false,
        'settings' =>
            array (
                'file_directory' => '[date:custom:Y]-[date:custom:m]',
                'file_extensions' => 'png gif jpg jpeg',
                'max_filesize' => '',
                'max_resolution' => '',
                'min_resolution' => '',
                'alt_field' => true,
                'alt_field_required' => false,
                'title_field' => false,
                'title_field_required' => false,
                'default_image' =>
                    array (
                        'uuid' => '',
                        'alt' => '',
                        'title' => '',
                        'width' => NULL,
                        'height' => NULL,
                    ),
                'handler' => 'default:file',
                'handler_settings' =>
                    array (
                    ),
            ),
        'field_type' => 'image',
    );
    FieldConfig::create($config_array)->save();
}
//field_link
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_link');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Link',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
//field_link_title
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_link_title');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_link_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Link Title',
        'required' => true,
        'translatable' => false,
        'settings' =>
            array (
                'link_type' => 17,
                'title' => 2,
            ),
        'field_type' => 'link',
    );
    FieldConfig::create($config_array)->save();
}

//field_name
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_name');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_name',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'language' => 'en',
        'field_type' => 'string',
        'label' => 'Name',
        'description' => '',
        'required' => false,
        'translatable' => false,
    );
    FieldConfig::create($config_array)->save();
}

//field_title
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_title');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Title',
        'required' => TRUE,
        'translatable' => false,
        'language' => 'en',
        'field_type' => 'string',
    );
    FieldConfig::create($config_array)->save();
}
//field_function
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_function');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_function',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Function',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

/********* Form display et View display of Paragraph **********/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.home_column_section.default');
$config_group->setData(
    array (
        'uuid' => '0e26fabb-5e60-45bc-85c3-26958f44debf',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_column_section.field_function',
                        1 => 'field.field.paragraph.home_column_section.field_image',
                        2 => 'field.field.paragraph.home_column_section.field_link',
                        3 => 'field.field.paragraph.home_column_section.field_link_title',
                        4 => 'field.field.paragraph.home_column_section.field_name',
                        5 => 'field.field.paragraph.home_column_section.field_title',
                        6 => 'image.style.thumbnail',
                        7 => 'paragraphs.paragraphs_type.home_column_section',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                        1 => 'link',
                        2 => 'workbench_moderation',
                    ),
            ),
        'id' => 'paragraph.home_column_section.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_column_section',
        'mode' => 'default',
        'content' =>
            array (
                'field_function' =>
                    array (
                        'weight' => 2,
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
                'field_image' =>
                    array (
                        'weight' => 3,
                        'settings' =>
                            array (
                                'progress_indicator' => 'throbber',
                                'preview_image_style' => 'thumbnail',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_link_title' =>
                    array (
                        'weight' => 0,
                        'settings' =>
                            array (
                                'placeholder_url' => '',
                                'placeholder_title' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'link_default',
                        'region' => 'content',
                    ),
                'field_name' =>
                    array (
                        'weight' => 1,
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
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_link' => true,
                'field_title' => true,
                'status' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.home_column_section.default');
$config_group->setData(
    array (
        'uuid' => '2d959ee5-2062-4158-949e-d4acf56220a2',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_column_section.field_function',
                        1 => 'field.field.paragraph.home_column_section.field_image',
                        2 => 'field.field.paragraph.home_column_section.field_link',
                        3 => 'field.field.paragraph.home_column_section.field_link_title',
                        4 => 'field.field.paragraph.home_column_section.field_name',
                        5 => 'field.field.paragraph.home_column_section.field_title',
                        6 => 'paragraphs.paragraphs_type.home_column_section',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                        1 => 'link',
                    ),
            ),
        'id' => 'paragraph.home_column_section.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_column_section',
        'mode' => 'default',
        'content' =>
            array (
                'field_function' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_image' =>
                    array (
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                        'region' => 'content',
                    ),
                'field_link' =>
                    array (
                        'weight' => 4,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_link_title' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'trim_length' => 80,
                                'url_only' => false,
                                'url_plain' => false,
                                'rel' => '',
                                'target' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'link',
                        'region' => 'content',
                    ),
                'field_name' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_title' =>
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
            ),
    )
);
$config_group->save(true);


/********* Field storage in paragraph **********/
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_column_section');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'paragraphs',
                    ),
            ),
        'id' => 'paragraph.field_column_section',
        'field_name' => 'field_column_section',
        'entity_type' => 'paragraph',
        'type' => 'entity_reference_revisions',
        'settings' =>
            array (
                'target_type' => 'paragraph',
            ),
        'module' => 'entity_reference_revisions',
        'locked' => false,
        'cardinality' => 2,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    ))->save();
}

$config_group->save(TRUE);
$field = FieldConfig::loadByName('paragraph', 'home_column', 'field_column_section');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_column_section',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column',
        'label' => 'Column_section',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
                'handler' => 'default:paragraph',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'home_column_section' => 'home_column_section',
                            ),
                        'target_bundles_drag_drop' =>
                            array (
                                'home_banner' =>
                                    array (
                                        'weight' => 4,
                                        'enabled' => false,
                                    ),
                                'home_column' =>
                                    array (
                                        'weight' => 5,
                                        'enabled' => false,
                                    ),
                                'home_column_section' =>
                                    array (
                                        'enabled' => true,
                                        'weight' => 6,
                                    ),
                            ),
                    ),
            ),
        'field_type' => 'entity_reference_revisions',
    );
    FieldConfig::create($config_array)->save();
}




/********************************  PARAGRAPHE HOME PLAYLIST *********************************/


/********* Paragraph storage **********/
// création du bundle de paragraph paragraphs.paragraphs_type.home_column_section
$paragraphStorage = ParagraphsType::load('home_playlist');
if(empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_column_section',
        'label' => 'Home column section',
        'revision' => false
    ]);
    $paragraphType->save();
}

/********* Fields storage in paragraph **********/
//field_link_button
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link_button');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_link_button',
        'entity_type' => 'paragraph',
        'type' => 'link',
        'module' => 'link',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => false,
    ))->save();
}
//field_playlist_taxonomy_term
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_playlist_taxonomy_term');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_playlist_taxonomy_term',
        'entity_type' => 'paragraph',
        'type' => 'entity_reference',
        'settings' =>
            array (
                'target_type' => 'taxonomy_term',
            ),
        'cardinality' => 1,
        'translatable' => false,
    ))->save();
}
//field_title done

/********* Instances of fields **********/
//field_link_button
$field = FieldConfig::loadByName('paragraph', 'home_playlist', 'field_link_button');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link_button',
        'entity_type' => 'paragraph',
        'bundle' => 'home_playlist',
        'label' => 'Link Button',
        'required' => TRUE,
        'settings' =>
            array (
                'link_type' => 17,
                'title' => 2,
            ),
        'field_type' => 'link',
    );
    FieldConfig::create($config_array)->save();
}

//field_playlist_taxonomy_term
$field = FieldConfig::loadByName('paragraph', 'home_playlist', 'field_playlist_taxonomy_term');
if(empty($field)) {
    $config_array = array(
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.paragraph.field_playlist_taxonomy_term',
                        1 => 'paragraphs.paragraphs_type.home_playlist',
                        2 => 'taxonomy.vocabulary.thematic',
                    ),
            ),
        'field_name' => 'field_playlist_taxonomy_term',
        'entity_type' => 'paragraph',
        'bundle' => 'home_playlist',
        'description' => 'Taxonomie Insight',
        'label' => 'Playlist Taxonomy Term',
        'required' => true,
        'translatable' => false,
        'settings' =>
            array (
                'handler' => 'default:taxonomy_term',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'thematic' => 'thematic',
                            ),
                        'sort' =>
                            array (
                                'field' => '_none',
                            ),
                        'auto_create' => false,
                        'auto_create_bundle' => 'insight',
                    ),
            ),
        'field_type' => 'entity_reference',
    );
    FieldConfig::create($config_array)->save();
}

//field_title
$field = FieldConfig::loadByName('paragraph', 'home_playlist', 'field_title');
if(empty($field)) {
    $config_array = array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_playlist',
        'label' => 'Playlist Title',
        'required' => true,
        'field_type' => 'string',
    );
    FieldConfig::create($config_array)->save();
}


/********* Form display et View display of Paragraph **********/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.home_playlist.default');
$config_group->setData(
    array (
        'uuid' => 'e0fa1dcd-c8ae-41c0-a93c-4b7b729ffded',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_playlist.field_link_button',
                        1 => 'field.field.paragraph.home_playlist.field_playlist_taxonomy_term',
                        2 => 'field.field.paragraph.home_playlist.field_title',
                        3 => 'paragraphs.paragraphs_type.home_playlist',
                    ),
                'module' =>
                    array (
                        0 => 'link',
                        1 => 'workbench_moderation',
                    ),
            ),
        'id' => 'paragraph.home_playlist.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_playlist',
        'mode' => 'default',
        'content' =>
            array (
                'field_link_button' =>
                    array (
                        'weight' => 11,
                        'settings' =>
                            array (
                                'placeholder_url' => '',
                                'placeholder_title' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'link_default',
                        'region' => 'content',
                    ),
                'field_playlist_taxonomy_term' =>
                    array (
                        'weight' => 9,
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
                'field_title' =>
                    array (
                        'weight' => 6,
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
            ),
        'hidden' =>
            array (
                'created' => true,
                'status' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.home_playlist.default');
$config_group->setData(
    array (
        'uuid' => '4d99058b-5414-4cf4-a568-5750d33231e2',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_playlist.field_link_button',
                        1 => 'field.field.paragraph.home_playlist.field_playlist_taxonomy_term',
                        2 => 'field.field.paragraph.home_playlist.field_title',
                        3 => 'paragraphs.paragraphs_type.home_playlist',
                    ),
                'module' =>
                    array (
                        0 => 'link',
                    ),
            ),
        'id' => 'paragraph.home_playlist.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_playlist',
        'mode' => 'default',
        'content' =>
            array (
                'field_link_button' =>
                    array (
                        'weight' => 5,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'trim_length' => 80,
                                'url_only' => false,
                                'url_plain' => false,
                                'rel' => '',
                                'target' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'link',
                        'region' => 'content',
                    ),
                'field_playlist_taxonomy_term' =>
                    array (
                        'weight' => 3,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                        'region' => 'content',
                    ),
                'field_title' =>
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
                        'region' => 'content',
                    ),
            ),
        'hidden' =>
            array (
            ),
    )
);
$config_group->save(true);


/********* Field storage in node **********/


$field_storage = FieldStorageConfig::loadByName('node', 'field_home_playlist');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'node',
                        2 => 'paragraphs',
                    ),
            ),
        'field_name' => 'field_home_playlists',
        'entity_type' => 'node',
        'type' => 'entity_reference_revisions',
        'settings' =>
            array (
                'target_type' => 'paragraph',
            ),
        'module' => 'entity_reference_revisions',
        'cardinality' => 8,
        'translatable' => true,
    ))->save();
}

$config_group->save(TRUE);
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_home_playlist');
if(empty($field)) {
    $config_array = array(
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_home_playlists',
                        1 => 'node.type.homepage_eclairage',
                        2 => 'paragraphs.paragraphs_type.home_playlist',
                    ),
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                    ),
            ),
        'field_name' => 'field_home_playlists',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Home Playlists',
        'description' => '',
        'required' => false,
        'translatable' => false,
        'settings' =>
            array (
                'handler' => 'default:paragraph',
                'handler_settings' =>
                    array (
                        'target_bundles' =>
                            array (
                                'home_playlist' => 'home_playlist',
                            ),
                        'target_bundles_drag_drop' =>
                            array (
                                'home_playlist' =>
                                    array (
                                        'enabled' => true,
                                        'weight' => 5,
                                    ),
                                'home_banner' =>
                                    array (
                                        'weight' => 6,
                                        'enabled' => false,
                                    ),
                                'home_column' =>
                                    array (
                                        'weight' => 7,
                                        'enabled' => false,
                                    ),
                                'home_column_section' =>
                                    array (
                                        'weight' => 8,
                                        'enabled' => false,
                                    ),
                            ),
                    ),
            ),
        'field_type' => 'entity_reference_revisions',
    );
    FieldConfig::create($config_array)->save();
}



/********************************  PARAGRAPHE Page THEMATIQUE COLUMNS *********************************/


/********* Paragraph storage **********/

/********* Fields storage in paragraph **********/

/********* Instances of fields **********/

/********* Form display et View display of Paragraph **********/

/********* Field storage in node **********/










/********************************  FIELDS DU NODE HOMEPAGE_ECLAIRAGE *********************************/
/********* Field storage in node **********/
//field_display_title
//field_home_banner done
//field_home_columns done
//field_home_playlists
//field_menu_title NEW
//field_meta_description
//field_meta_title

$field_storage = FieldStorageConfig::loadByName('node', 'field_menu_title');
if(empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_menu_title',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_menu_title');
$config_group->setData(
    array (
        'uuid' => 'c90bbfec-5abc-4390-ba3a-57cf2daf75a1',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                    ),
            ),
        'id' => 'node.field_menu_title',
        'field_name' => 'field_menu_title',
        'entity_type' => 'node',
        'type' => 'string',
        'settings' =>
            array (
                'max_length' => 56,
                'is_ascii' => false,
                'case_sensitive' => false,
            ),
        'module' => 'core',
        'locked' => false,
        'cardinality' => 1,
        'translatable' => true,
        'indexes' =>
            array (
            ),
        'persist_with_no_fields' => false,
        'custom_storage' => false,
    )
);
$config_group->save(TRUE);


/********* Instances of fields **********/

//field_menu_title
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_menu_title');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_menu_title',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Menu title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.homepage_eclairage.field_menu_title');
$config_group->setData(
    array (
        'uuid' => '795d84da-194a-4fdc-a8ce-85c279deb9bd',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_menu_title',
                        1 => 'node.type.homepage_eclairage',
                    ),
            ),
        'id' => 'node.homepage_eclairage.field_menu_title',
        'field_name' => 'field_menu_title',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Menu title',
        'description' => 'Create your items here : <a href=\'/admin/structure/menu/manage/menu-homepage-eclairage\' target=\'_blank\'> Menu homepage Eclairages </a>',
        'required' => true,
        'translatable' => false,
        'default_value' =>
            array (
            ),
        'default_value_callback' => '',
        'settings' =>
            array (
            ),
        'field_type' => 'string',
    )
);
$config_group->save(TRUE);

//field_display_title
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_display_title');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_display_title',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Display title',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}

//field_meta_description
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_meta_description');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Meta description',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
//field_meta_title
$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_meta_title');
if(empty($field)) {
    $config_array = array(
        'field_name' =>  'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'homepage_eclairage',
        'label' => 'Meta title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}


//field_home_banner done
//field_home_columns done
//field_home_playlists

/********* Form display et View display of NODE **********/


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.homepage_eclairage.default');
$config_group->setData(
    array (
        'uuid' => '3a82f231-a0a7-43cb-91e1-d10a801e6aad',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.homepage_eclairage.body',
                        1 => 'field.field.node.homepage_eclairage.field_display_title',
                        2 => 'field.field.node.homepage_eclairage.field_home_banner',
                        3 => 'field.field.node.homepage_eclairage.field_home_columns',
                        4 => 'field.field.node.homepage_eclairage.field_home_playlists',
                        5 => 'field.field.node.homepage_eclairage.field_menu_title',
                        6 => 'field.field.node.homepage_eclairage.field_meta_description',
                        7 => 'field.field.node.homepage_eclairage.field_meta_title',
                        8 => 'node.type.homepage_eclairage',
                    ),
                'module' =>
                    array (
                        0 => 'field_group',
                        1 => 'paragraphs',
                        2 => 'workbench_moderation',
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
                                        0 => 'group_homepage_menu',
                                        1 => 'group_banner',
                                        2 => 'group_home_section',
                                        3 => 'group_home_playlist',
                                        4 => 'group_seo',
                                    ),
                                'parent_name' => '',
                                'weight' => 2,
                                'format_type' => 'tabs',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'direction' => 'vertical',
                                    ),
                                'label' => 'Onglets',
                            ),
                        'group_banner' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_home_banner',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 21,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Banner',
                            ),
                        'group_home_section' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_home_columns',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 22,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Home section',
                            ),
                        'group_home_playlist' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_home_playlists',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 23,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Home Playlist',
                            ),
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 24,
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
                        'group_homepage_menu' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'title',
                                        1 => 'field_display_title',
                                        2 => 'field_menu_title',
                                    ),
                                'parent_name' => 'group_onglets',
                                'weight' => 20,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'open',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Homepage Menu',
                            ),
                    ),
            ),
        'id' => 'node.homepage_eclairage.default',
        'targetEntityType' => 'node',
        'bundle' => 'homepage_eclairage',
        'mode' => 'default',
        'content' =>
            array (
                'field_display_title' =>
                    array (
                        'weight' => 1,
                        'settings' =>
                            array (
                                'display_label' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean_checkbox',
                        'region' => 'content',
                    ),
                'field_home_banner' =>
                    array (
                        'type' => 'entity_reference_paragraphs',
                        'weight' => 31,
                        'settings' =>
                            array (
                                'title' => 'Paragraph',
                                'title_plural' => 'Paragraphs',
                                'edit_mode' => 'open',
                                'add_mode' => 'dropdown',
                                'form_display_mode' => 'default',
                                'default_paragraph_type' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_home_columns' =>
                    array (
                        'type' => 'entity_reference_paragraphs',
                        'weight' => 27,
                        'settings' =>
                            array (
                                'title' => 'Paragraph',
                                'title_plural' => 'Paragraphs',
                                'edit_mode' => 'open',
                                'add_mode' => 'dropdown',
                                'form_display_mode' => 'default',
                                'default_paragraph_type' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_home_playlists' =>
                    array (
                        'type' => 'entity_reference_paragraphs',
                        'weight' => 32,
                        'settings' =>
                            array (
                                'title' => 'Paragraph',
                                'title_plural' => 'Paragraphs',
                                'edit_mode' => 'open',
                                'add_mode' => 'dropdown',
                                'form_display_mode' => 'default',
                                'default_paragraph_type' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_menu_title' =>
                    array (
                        'weight' => 2,
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
                'field_meta_description' =>
                    array (
                        'weight' => 34,
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
                'field_meta_title' =>
                    array (
                        'weight' => 33,
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
                'title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 0,
                        'region' => 'content',
                        'settings' =>
                            array (
                                'size' => 60,
                                'placeholder' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'body' => true,
                'created' => true,
                'langcode' => true,
                'path' => true,
                'promote' => true,
                'sticky' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.homepage_eclairage.default');
$config_group->setData(
    array (
        'uuid' => 'c6afc24d-c561-471e-84a0-a0ce01f66970',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.homepage_eclairage.body',
                        1 => 'field.field.node.homepage_eclairage.field_display_title',
                        2 => 'field.field.node.homepage_eclairage.field_home_banner',
                        3 => 'field.field.node.homepage_eclairage.field_home_columns',
                        4 => 'field.field.node.homepage_eclairage.field_home_playlists',
                        5 => 'field.field.node.homepage_eclairage.field_menu_title',
                        6 => 'field.field.node.homepage_eclairage.field_meta_description',
                        7 => 'field.field.node.homepage_eclairage.field_meta_title',
                        8 => 'node.type.homepage_eclairage',
                    ),
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                        1 => 'text',
                        2 => 'user',
                    ),
            ),
        'id' => 'node.homepage_eclairage.default',
        'targetEntityType' => 'node',
        'bundle' => 'homepage_eclairage',
        'mode' => 'default',
        'content' =>
            array (
                'body' =>
                    array (
                        'label' => 'hidden',
                        'type' => 'text_default',
                        'weight' => 101,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_display_title' =>
                    array (
                        'weight' => 126,
                        'label' => 'above',
                        'settings' =>
                            array (
                                'format' => 'default',
                                'format_custom_false' => '',
                                'format_custom_true' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'boolean',
                        'region' => 'content',
                    ),
                'field_home_banner' =>
                    array (
                        'type' => 'entity_reference_revisions_entity_view',
                        'weight' => 120,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_home_columns' =>
                    array (
                        'type' => 'entity_reference_revisions_entity_view',
                        'weight' => 121,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_home_playlists' =>
                    array (
                        'type' => 'entity_reference_revisions_entity_view',
                        'weight' => 122,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_menu_title' =>
                    array (
                        'weight' => 123,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_meta_description' =>
                    array (
                        'weight' => 125,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'field_meta_title' =>
                    array (
                        'weight' => 124,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link_to_entity' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'string',
                        'region' => 'content',
                    ),
                'links' =>
                    array (
                        'weight' => 100,
                        'region' => 'content',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'langcode' => true,
            ),
    )
);
$config_group->save(true);









/********************************  FIELDS DU NODE PAGE THEMATIQUE *********************************/
/********* Field storage in node **********/
/********* Instances of fields **********/
/********* Form display et View display of NODE **********/





/********************************  VIEW HOMEPAGE_ECLAIRAGE PLAYLIST *********************************/

/********************************  VIEW PAGE_THEMATIQUE ZONE DE VALORISATION*********************************/

/********************************  MODE DE RENDU IMAGE HOME PLAYLIST *********************************/
