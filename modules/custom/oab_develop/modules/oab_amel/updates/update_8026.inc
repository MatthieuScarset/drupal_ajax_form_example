
<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\paragraphs\Entity\ParagraphsType;

//Applique les modifications en bdd pour la traduction : ajout des colonnes necessaires
\Drupal::entityDefinitionUpdateManager()->applyUpdates();
/******** Création des PARAGRAPHES ***********
 *   banner
 *   columns
 *   column section
 *   playlist
 */
echo('Création  des paragraphes');
// création du bundle de paragraph paragraphs.paragraphs_type.home_banner
$paragraphStorage = ParagraphsType::load('home_banner');
if (empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_banner',
        'label' => 'Home Banner',
        'revision' => false
    ]);
    $paragraphType->save();
}

// création des champs pour le paragraph paragraphs.paragraphs_type.home_banner
/****** storage ******/
//field_title
//field_big_image_desktop_
//field_date
//field_function
//field_image_mobile
//field_link
//field_little_image_desktop
//field_name
//field_text_color

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_title');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_title',
        'entity_type' => 'paragraph',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_title');
$config_group->setData(array (
    'uuid' => '5e80915b-7198-4f74-a610-53e7e66a4dea',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_title',
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_big_image_desktop_');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_big_image_desktop_',
        'entity_type' => 'paragraph',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_big_image_desktop_');
$config_group->setData(array (
    'uuid' => '9189fd12-3cad-4168-a3b7-f49a5817fe43',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_big_image_desktop_',
    'field_name' => 'field_big_image_desktop_',
    'entity_type' => 'paragraph',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_date');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_date',
        'entity_type' => 'paragraph',
        'type' => 'datetime',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_date');
$config_group->setData(array (
    'uuid' => '364232e2-65a6-442d-9424-bb0c3006c489',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'datetime',
                    1 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_date',
    'field_name' => 'field_date',
    'entity_type' => 'paragraph',
    'type' => 'datetime',
    'settings' =>
        array (
            'datetime_type' => 'date',
        ),
    'module' => 'datetime',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_function');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_function',
        'entity_type' => 'paragraph',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_function');
$config_group->setData(array (
    'uuid' => '81a3256d-7a08-4397-a323-30c6fce23a29',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_function',
    'field_name' => 'field_function',
    'entity_type' => 'paragraph',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 156,
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
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_image_mobile');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_image_mobile',
        'entity_type' => 'paragraph',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_image_mobile');
$config_group->setData(array (
    'uuid' => 'adeb566a-2020-423b-b092-69117cd5c22f',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_image_mobile',
    'field_name' => 'field_image_mobile',
    'entity_type' => 'paragraph',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_link',
        'entity_type' => 'paragraph',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_link');
$config_group->setData(array (
    'uuid' => 'e7fc427f-5845-43ee-8c2a-1dfc2a6151c2',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_link',
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_little_image_desktop');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_little_image_desktop',
        'entity_type' => 'paragraph',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_little_image_desktop');
$config_group->setData(array (
    'uuid' => '75f0a353-f370-4923-909e-51f6af045d7e',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_little_image_desktop',
    'field_name' => 'field_little_image_desktop',
    'entity_type' => 'paragraph',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_name');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_name',
        'entity_type' => 'paragraph',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_name');
$config_group->setData(array (
    'uuid' => '8762e1d3-9a05-40d3-a41d-8f93a77491b2',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'paragraph',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 156,
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
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_text_color');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_text_color',
        'entity_type' => 'paragraph',
        'type' => 'list_string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_text_color');
$config_group->setData(array (
    'uuid' => 'b19842ed-7313-45b6-8908-9134df685924',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'options',
                    1 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_text_color',
    'field_name' => 'field_text_color',
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
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

/*** instances*****/

//field_title
//field_big_image_desktop_
//field_date
//field_function
//field_image_mobile
//field_link
//field_little_image_desktop
//field_name
//field_text_color

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_title');
$config_group->setData(array (
    'uuid' => 'b4215cbf-c6cd-4b70-a804-c47429e43665',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_title',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
        ),
    'id' => 'paragraph.home_banner.field_title',
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Title',
    'description' => '',
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
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_big_image_desktop_');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_big_image_desktop_',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Big Image Desktop ',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_big_image_desktop_');
$config_group->setData(array (
    'uuid' => '4f510076-06fc-4a92-bc86-4b6a5d6a3feb',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_big_image_desktop_',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'paragraph.home_banner.field_big_image_desktop_',
    'field_name' => 'field_big_image_desktop_',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Big Image Desktop ',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_date');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_date',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Date',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_date');
$config_group->setData(array (
    'uuid' => '24aa37c0-121b-461c-8753-933cb3a8c5a2',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_date',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
            'module' =>
                array (
                    0 => 'datetime',
                ),
        ),
    'id' => 'paragraph.home_banner.field_date',
    'field_name' => 'field_date',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Date',
    'description' => '',
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
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'datetime',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_function');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_function',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Function',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_function');
$config_group->setData(array (
    'uuid' => '3be68e42-6af5-4d32-a9ce-480307389dde',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_function',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
        ),
    'id' => 'paragraph.home_banner.field_function',
    'field_name' => 'field_function',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Function',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_image_mobile');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_image_mobile',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Image Mobile',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_image_mobile');
$config_group->setData(array (
    'uuid' => '72afd42a-7b0d-4353-9947-3e66be0e3d6d',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_image_mobile',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'paragraph.home_banner.field_image_mobile',
    'field_name' => 'field_image_mobile',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Image Mobile',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Link',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_link');
$config_group->setData(array (
    'uuid' => '4d67a023-e20a-42b9-ab29-16f1be58e796',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_link',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
        ),
    'id' => 'paragraph.home_banner.field_link',
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Link',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_little_image_desktop');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_little_image_desktop',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Little Image Desktop',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_little_image_desktop');
$config_group->setData(array (
    'uuid' => '90b71327-3914-4d54-a1b3-3504d1314e82',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_little_image_desktop',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'paragraph.home_banner.field_little_image_desktop',
    'field_name' => 'field_little_image_desktop',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Little Image Desktop',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_name');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_name',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Name',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_name');
$config_group->setData(array (
    'uuid' => '8db168ce-164d-4551-acd1-661fa1e0f1d1',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_name',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
        ),
    'id' => 'paragraph.home_banner.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Name',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('paragraph', 'home_banner', 'field_text_color');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_text_color',
        'entity_type' => 'paragraph',
        'bundle' => 'home_banner',
        'label' => 'Text Color',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_banner.field_text_color');
$config_group->setData(array (
    'uuid' => '48375b0c-d447-4f9e-ba5c-772b993347da',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_text_color',
                    1 => 'paragraphs.paragraphs_type.home_banner',
                ),
            'module' =>
                array (
                    0 => 'options',
                ),
        ),
    'id' => 'paragraph.home_banner.field_text_color',
    'field_name' => 'field_text_color',
    'entity_type' => 'paragraph',
    'bundle' => 'home_banner',
    'label' => 'Text Color',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
            0 =>
                array (
                    'value' => 'black',
                ),
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'list_string',
));
$config_group->save(TRUE);




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
if (empty($field_storage)) {
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

$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_home_banner');
if (empty($field)) {
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



/********************************  PARAGRAPHE HOME COLUMN SECTION *********************************/

/********* Paragraph storage **********/
// création du bundle de paragraph paragraphs.paragraphs_type.home_column_section
$paragraphStorage = ParagraphsType::load('home_column_section');
if (empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_column_section',
        'label' => 'Home column section',
        'revision' => false
    ]);
    $paragraphType->save();
}

/********* Field storage in paragraph **********/
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_column_section');
if (empty($field_storage)) {
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_column_section');
$config_group->setData(array (
    'uuid' => 'e28c5cb1-7df0-4db6-8013-69301ffc5b4a',
    'langcode' => 'en',
    'status' => true,
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
));
$config_group->save(TRUE);



/********* Fields storage in paragraph **********/
//field_function done
//field_link done
//field_name done
//field_title done

//field_image
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_image');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_image',
        'entity_type' => 'paragraph',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_image');
$config_group->setData(array (
    'uuid' => '729cd632-8931-4376-94d1-db810f17b875',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_image',
    'field_name' => 'field_image',
    'entity_type' => 'paragraph',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


//field_link_title
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link_title');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_link_title',
        'entity_type' => 'paragraph',
        'type' => 'link',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_link_title');
$config_group->setData(array (
    'uuid' => '3cc2e153-0fd5-45fe-bcac-11a68be32e20',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'link',
                    1 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_link_title',
    'field_name' => 'field_link_title',
    'entity_type' => 'paragraph',
    'type' => 'link',
    'settings' =>
        array (
        ),
    'module' => 'link',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

/********* Instances of fields **********/

//field_image
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_image');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_image',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Image',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_image');
$config_group->setData(array (
    'uuid' => 'e6a65c3c-2247-4b37-acab-90360f990194',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_image',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_image',
    'field_name' => 'field_image',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Image',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);
//field_link

$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Link',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_link');
$config_group->setData(array (
    'uuid' => '8c128036-78c1-437d-98c0-dffb5f2be822',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_link',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_link',
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Link',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);



//field_link_title

$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_link_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Link Title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_link_title');
$config_group->setData(array (
    'uuid' => '60a65b4a-a081-40b4-92f3-a82733654b10',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_link_title',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
            'module' =>
                array (
                    0 => 'link',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_link_title',
    'field_name' => 'field_link_title',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Link Title',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
            'link_type' => 17,
            'title' => 2,
        ),
    'field_type' => 'link',
));
$config_group->save(TRUE);

//field_name
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_name');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_name',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Name',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_name');
$config_group->setData(
    array (
    'uuid' => '46bcd3c4-493e-4630-a33e-4a068dca5a30',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_name',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Name',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);


//field_title
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_title');
$config_group->setData(array (
    'uuid' => 'a93c5c8a-6061-47cb-a5a1-4e7d99e70e48',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_title',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_title',
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Title',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);


//field_function
$field = FieldConfig::loadByName('paragraph', 'home_column_section', 'field_function');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_function',
        'entity_type' => 'paragraph',
        'bundle' => 'home_column_section',
        'label' => 'Function',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column_section.field_function');
$config_group->setData(array (
    'uuid' => '158d0ea7-345d-42e0-9121-7e7498115c18',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_function',
                    1 => 'paragraphs.paragraphs_type.home_column_section',
                ),
        ),
    'id' => 'paragraph.home_column_section.field_function',
    'field_name' => 'field_function',
    'entity_type' => 'paragraph',
    'bundle' => 'home_column_section',
    'label' => 'Function',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);



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







/********************************* PARAGRAPHE HOME COLUMN *********************************/

/********* Paragraphe storage **********/
// création du bundle de paragraph paragraphs.paragraphs_type.home_column
$paragraphStorage = ParagraphsType::load('home_column');
if (empty($paragraphStorage)) {
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
if (empty($field_storage)) {
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
if (empty($field_storage)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
if (empty($field)) {
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_column.field_column_section');
$config_group->setData(
    array (
        'uuid' => 'b3f6fa6e-dfe7-4082-b3de-f560d1d8ebb5',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.paragraph.field_column_section',
                        1 => 'paragraphs.paragraphs_type.home_column',
                        2 => 'paragraphs.paragraphs_type.home_column_section',
                    ),
                'module' =>
                    array (
                        0 => 'entity_reference_revisions',
                    ),
            ),
        'id' => 'paragraph.home_column.field_column_section',
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
    )

);
$config_group->save(true);


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
if (empty($field_storage)) {
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

$field = FieldConfig::loadByName('node', 'homepage_eclairage', 'field_home_columns');
if (empty($field)) {
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




/********************************  PARAGRAPHE HOME PLAYLIST *********************************/


/********* Paragraph storage **********/
// création du bundle de paragraph playlist
$paragraphStorage = ParagraphsType::load('home_playlist');
if (empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_playlist',
        'label' => 'Home Playlist',
        'revision' => false
    ]);
    $paragraphType->save();
}

/********* Fields storage in paragraph **********/
//field_link_button
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link_button');
if (empty($field_storage)) {
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
if (empty($field_storage)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
if (empty($field_storage)) {
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
if (empty($field)) {
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

$paragraphStorage = ParagraphsType::load('home_thematic_columns');
if (empty($paragraphStorage)) {
    $paragraphType = ParagraphsType::create([
        'id' => 'home_thematic_columns',
        'label' => 'Home Thematic Columns',
    ]);
    $paragraphType->save();
}


/********* Fields storage in paragraph **********/
//field_date
//field_function
//field_highlight
//field_image
//field_link
//field_name
//field_title

$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_highlight');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_highlight',
        'entity_type' => 'paragraph',
        'type' => 'string_long',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.paragraph.field_highlight');
$config_group->setData(array (
    'uuid' => '57038c33-2839-4604-b339-5e38bfde6f92',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'paragraphs',
                ),
        ),
    'id' => 'paragraph.field_highlight',
    'field_name' => 'field_highlight',
    'entity_type' => 'paragraph',
    'type' => 'string_long',
    'settings' =>
        array (
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
));
$config_group->save(TRUE);


/********* Instances of fields **********/

//field_highlight
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_highlight');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_highlight',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Highlight',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_highlight');
$config_group->setData(array (
    'uuid' => '0353d071-1c6f-42a1-8596-bc6858a5f960',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_highlight',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_highlight',
    'field_name' => 'field_highlight',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Highlight',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string_long',
));
$config_group->save(TRUE);


//field_date
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_date');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_date',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Date',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_date');
$config_group->setData(array (
    'uuid' => '6f7b5e0a-063e-4b5b-8edf-afe07685f44a',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_date',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
            'module' =>
                array (
                    0 => 'datetime',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_date',
    'field_name' => 'field_date',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Date',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
            0 =>
                array (
                    'default_date_type' => 'now',
                    'default_date' => 'now',
                ),
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'datetime',
));
$config_group->save(TRUE);

//field_function
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_function');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_function',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Function',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_function');
$config_group->setData(array (
    'uuid' => '2e36a030-1401-4638-b0da-384cdf2aa635',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_function',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_function',
    'field_name' => 'field_function',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Function',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

//field_image
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_image');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_image',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Image',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_image');
$config_group->setData(array (
    'uuid' => '85dd6f94-3de8-40a3-a5a4-8ae5347b8106',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_image',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
            'module' =>
                array (
                    0 => 'content_translation',
                    1 => 'image',
                ),
        ),
    'third_party_settings' =>
        array (
            'content_translation' =>
                array (
                    'translation_sync' =>
                        array (
                            'alt' => 'alt',
                            'title' => 'title',
                            'file' => '0',
                        ),
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_image',
    'field_name' => 'field_image',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Image',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);

//field_link
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_link',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Link',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_link');
$config_group->setData(array (
    'uuid' => 'f5ca33b6-d7a5-4a16-b86d-7ef263cc4dda',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_link',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_link',
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Link',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

//field_name
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_name');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_name',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Name',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_name');
$config_group->setData(array (
    'uuid' => '4e1e88c8-4af7-48ad-a361-e710d1a19004',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_name',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Name',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);



//field_title
$field = FieldConfig::loadByName('paragraph', 'home_thematic_columns', 'field_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_title',
        'entity_type' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'label' => 'Title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.paragraph.home_thematic_columns.field_title');
$config_group->setData(array (
    'uuid' => 'aa52eae4-9a3c-44fe-876a-fc9affa4303f',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.paragraph.field_title',
                    1 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
        ),
    'id' => 'paragraph.home_thematic_columns.field_title',
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'bundle' => 'home_thematic_columns',
    'label' => 'Title',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

/********* Form display et View display of Paragraph **********/

//core.entity_form_display.paragraph.home_thematic_columns.default

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.home_thematic_columns.default');
$config_group->setData(
    array (
        'uuid' => 'd058f1a2-9ef4-4140-90e9-a62808b60b65',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_thematic_columns.field_date',
                        1 => 'field.field.paragraph.home_thematic_columns.field_function',
                        2 => 'field.field.paragraph.home_thematic_columns.field_highlight',
                        3 => 'field.field.paragraph.home_thematic_columns.field_image',
                        4 => 'field.field.paragraph.home_thematic_columns.field_link',
                        5 => 'field.field.paragraph.home_thematic_columns.field_name',
                        6 => 'field.field.paragraph.home_thematic_columns.field_title',
                        7 => 'image.style.thumbnail',
                        8 => 'paragraphs.paragraphs_type.home_thematic_columns',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'image',
                        2 => 'workbench_moderation',
                    ),
            ),
        'id' => 'paragraph.home_thematic_columns.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'mode' => 'default',
        'content' =>
            array (
                'field_date' =>
                    array (
                        'weight' => 2,
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
                        'weight' => 5,
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
                'field_highlight' =>
                    array (
                        'weight' => 7,
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
                'field_image' =>
                    array (
                        'weight' => 1,
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
                'field_name' =>
                    array (
                        'weight' => 4,
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
                'field_title' =>
                    array (
                        'weight' => 0,
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

//core.entity_view_display.paragraph.home_thematic_columns.default

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.home_thematic_columns.default');
$config_group->setData(
    array (
        'uuid' => '24909112-b009-4030-834d-fa8bfafe7a45',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.paragraph.home_thematic_columns.field_date',
                        1 => 'field.field.paragraph.home_thematic_columns.field_function',
                        2 => 'field.field.paragraph.home_thematic_columns.field_highlight',
                        3 => 'field.field.paragraph.home_thematic_columns.field_image',
                        4 => 'field.field.paragraph.home_thematic_columns.field_link',
                        5 => 'field.field.paragraph.home_thematic_columns.field_name',
                        6 => 'field.field.paragraph.home_thematic_columns.field_title',
                        7 => 'paragraphs.paragraphs_type.home_thematic_columns',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'image',
                    ),
            ),
        'id' => 'paragraph.home_thematic_columns.default',
        'targetEntityType' => 'paragraph',
        'bundle' => 'home_thematic_columns',
        'mode' => 'default',
        'content' =>
            array (
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
                'field_highlight' =>
                    array (
                        'weight' => 6,
                        'label' => 'above',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                        'region' => 'content',
                    ),
                'field_image' =>
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
                'field_link' =>
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
                'field_name' =>
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
                'field_title' =>
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
            ),
        'hidden' =>
            array (
            ),
    )
);
$config_group->save(true);

/********* Field storage in node **********/


$field_storage = FieldStorageConfig::loadByName('node', 'field_home_thematic_columns');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_home_thematic_columns',
        'entity_type' => 'node',
        'type' => 'entity_reference_revisions',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_home_thematic_columns');
$config_group->setData(array (
    'uuid' => 'e1d4a43b-62e3-40d7-befb-aa53cc4dbfd3',
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
    'id' => 'node.field_home_thematic_columns',
    'field_name' => 'field_home_thematic_columns',
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
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_home_thematic_columns');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_home_thematic_columns',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Home Thematic columns',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_home_thematic_columns');
$config_group->setData(array (
    'uuid' => 'f8489f87-d0d1-4cc4-9344-74f7e0543e0f',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_home_thematic_columns',
                    1 => 'node.type.hp_eclairage_thematique',
                    2 => 'paragraphs.paragraphs_type.home_thematic_columns',
                ),
            'module' =>
                array (
                    0 => 'entity_reference_revisions',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_home_thematic_columns',
    'field_name' => 'field_home_thematic_columns',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Home Thematic columns',
    'description' => '',
    'required' => true,
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
                            'home_thematic_columns' => 'home_thematic_columns',
                        ),
                    'target_bundles_drag_drop' =>
                        array (
                            'home_thematic_columns' =>
                                array (
                                    'enabled' => true,
                                    'weight' => 6,
                                ),
                            'home_banner' =>
                                array (
                                    'weight' => 7,
                                    'enabled' => false,
                                ),
                            'home_column' =>
                                array (
                                    'weight' => 8,
                                    'enabled' => false,
                                ),
                            'home_column_section' =>
                                array (
                                    'weight' => 9,
                                    'enabled' => false,
                                ),
                            'home_playlist' =>
                                array (
                                    'weight' => 10,
                                    'enabled' => false,
                                ),
                        ),
                ),
        ),
    'field_type' => 'entity_reference_revisions',
));
$config_group->save(TRUE);




/********************************  MODE DE RENDU IMAGE HOME PLAYLIST *********************************/
echo('Création  du mode de rendu playlist image');
//core.entity_view_mode.media.home_playlist
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.home_playlist');
$config_group->setData(
    array (
        'uuid' => 'bdf7e15a-cbeb-41f0-a739-33c86cbf11b1',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'media_entity',
                    ),
            ),
        'id' => 'media.home_playlist',
        'label' => 'Home Playlist image',
        'targetEntityType' => 'media',
        'cache' => true,
    )
);
$config_group->save(true);

//core.entity_view_display.media.image.home_playlist
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.media.home_playlist');
$config_group->setData(
    array (
        'uuid' => '5e8bc5ee-c939-4b0b-8f36-de77977c86bc',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.media.home_playlist',
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
        'id' => 'media.image.home_playlist',
        'targetEntityType' => 'media',
        'bundle' => 'image',
        'mode' => 'home_playlist',
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


/********************************  FIELDS DU NODE HOMEPAGE_ECLAIRAGE *********************************/
/********* Field storage in node **********/

//field_home_banner done
//field_home_columns done
//field_home_playlists done
//field_display_title done
//field_meta_description done
//field_meta_title done

//field_menu_title NEW
$field_storage = FieldStorageConfig::loadByName('node', 'field_menu_title');
if (empty($field_storage)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
if (empty($field)) {
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
//field_home_playlist done

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
                        'label' => 'hidden',
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
//field_banner_image_title
//field_banner_link
//field_grouping_title
//field_date
//field_desktop_image
//field_display_title
//field_funct
//field_meta_description
//field_meta_title
//field_mobile_image
//field_name
//field_navigation_link
//field_text_color
//field_text_zone
//field_text_zone_link

$field_storage = FieldStorageConfig::loadByName('node', 'field_date');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_date',
        'entity_type' => 'node',
        'type' => 'datetime',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_date');
$config_group->setData(array (
    'uuid' => '4fb58fa5-af89-4435-9c6f-4e88abdf1186',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'datetime',
                    1 => 'node',
                ),
        ),
    'id' => 'node.field_date',
    'field_name' => 'field_date',
    'entity_type' => 'node',
    'type' => 'datetime',
    'settings' =>
        array (
            'datetime_type' => 'date',
        ),
    'module' => 'datetime',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_name');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_name',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_name');
$config_group->setData(array (
    'uuid' => '1bfe515f-9b9e-40bd-997e-f5790726b861',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                ),
        ),
    'id' => 'node.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'node',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_text_color');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_text_color',
        'entity_type' => 'node',
        'type' => 'list_string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_text_color');
$config_group->setData(array (
    'uuid' => '1c1337b9-a40c-42d3-8901-5faa39747ed8',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                    1 => 'options',
                ),
        ),
    'id' => 'node.field_text_color',
    'field_name' => 'field_text_color',
    'entity_type' => 'node',
    'type' => 'list_string',
    'settings' =>
        array (
            'allowed_values' =>
                array (
                    0 =>
                        array (
                            'value' => 'black',
                            'label' => 'Black',
                        ),
                    1 =>
                        array (
                            'value' => 'white',
                            'label' => 'White',
                        ),
                ),
            'allowed_values_function' => '',
        ),
    'module' => 'options',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_banner_image_title');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_banner_image_title',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_banner_image_title');
$config_group->setData(array (
    'uuid' => '10655999-f646-49e1-97b2-3375da7f1b96',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                ),
        ),
    'id' => 'node.field_banner_image_title',
    'field_name' => 'field_banner_image_title',
    'entity_type' => 'node',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_banner_link');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_banner_link',
        'entity_type' => 'node',
        'type' => 'link',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_banner_link');
$config_group->setData(array (
    'uuid' => 'ad354521-50bf-4f16-a96b-818da593cfd8',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'link',
                    1 => 'node',
                ),
        ),
    'id' => 'node.field_banner_link',
    'field_name' => 'field_banner_link',
    'entity_type' => 'node',
    'type' => 'link',
    'settings' =>
        array (
        ),
    'module' => 'link',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_grouping_title');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_grouping_title',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_grouping_title');
$config_group->setData(array (
    'uuid' => '751cc829-043e-49ae-b12c-a8bb03567bca',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                ),
        ),
    'id' => 'node.field_grouping_title',
    'field_name' => 'field_grouping_title',
    'entity_type' => 'node',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_mobile_image');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_mobile_image',
        'entity_type' => 'node',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_mobile_image');
$config_group->setData(array (
    'uuid' => 'cea7a8c9-0a36-477d-91dc-a743576d7510',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'node',
                ),
        ),
    'id' => 'node.field_mobile_image',
    'field_name' => 'field_mobile_image',
    'entity_type' => 'node',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('node', 'field_desktop_image');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_desktop_image',
        'entity_type' => 'node',
        'type' => 'image',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_desktop_image');
$config_group->setData(array (
    'uuid' => '260ef82e-e011-46f6-b2c1-05e60ce183b9',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'file',
                    1 => 'image',
                    2 => 'node',
                ),
        ),
    'id' => 'node.field_desktop_image',
    'field_name' => 'field_desktop_image',
    'entity_type' => 'node',
    'type' => 'image',
    'settings' =>
        array (
            'uri_scheme' => 'public',
            'default_image' =>
                array (
                    'uuid' => '',
                    'alt' => '',
                    'title' => '',
                    'width' => NULL,
                    'height' => NULL,
                ),
            'target_type' => 'file',
            'display_field' => false,
            'display_default' => false,
        ),
    'module' => 'image',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('node', 'field_navigation_link');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_navigation_link',
        'entity_type' => 'node',
        'type' => 'link',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_navigation_link');
$config_group->setData(array (
    'uuid' => 'adc2091a-2cf0-457f-9aeb-6db3bffb06ff',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'link',
                    1 => 'node',
                ),
        ),
    'id' => 'node.field_navigation_link',
    'field_name' => 'field_navigation_link',
    'entity_type' => 'node',
    'type' => 'link',
    'settings' =>
        array (
        ),
    'module' => 'link',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('node', 'field_funct');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_funct',
        'entity_type' => 'node',
        'type' => 'string',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_funct');
$config_group->setData(array (
    'uuid' => 'a6fe2ff1-d4db-4fc2-8fdc-45b0d7061685',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                ),
        ),
    'id' => 'node.field_funct',
    'field_name' => 'field_funct',
    'entity_type' => 'node',
    'type' => 'string',
    'settings' =>
        array (
            'max_length' => 255,
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
));
$config_group->save(TRUE);

$field_storage = FieldStorageConfig::loadByName('node', 'field_text_zone');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_text_zone',
        'entity_type' => 'node',
        'type' => 'text_long',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_text_zone');
$config_group->setData(array (
    'uuid' => 'efe59f6f-0abf-49a5-8b0f-c9339316f80e',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'node',
                    1 => 'text',
                ),
        ),
    'id' => 'node.field_text_zone',
    'field_name' => 'field_text_zone',
    'entity_type' => 'node',
    'type' => 'text_long',
    'settings' =>
        array (
        ),
    'module' => 'text',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


$field_storage = FieldStorageConfig::loadByName('node', 'field_text_zone_link');
if (empty($field_storage)) {
    FieldStorageConfig::create(array(
        'field_name' => 'field_text_zone_link',
        'entity_type' => 'node',
        'type' => 'link',
    ))->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_text_zone_link');
$config_group->setData(array (
    'uuid' => '8898dd55-e7a7-4687-bc7a-97c4d2a04e72',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'module' =>
                array (
                    0 => 'link',
                    1 => 'node',
                ),
        ),
    'id' => 'node.field_text_zone_link',
    'field_name' => 'field_text_zone_link',
    'entity_type' => 'node',
    'type' => 'link',
    'settings' =>
        array (
        ),
    'module' => 'link',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
        array (
        ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
));
$config_group->save(TRUE);


/********* Instances of fields **********/
//field_banner_image_title
//field_banner_link
//field_grouping_title
//field_date
//field_desktop_image
//field_display_title
//field_funct
//field_meta_description
//field_meta_title
//field_mobile_image
//field_name
//field_navigation_link
//field_text_color
//field_text_zone
//field_text_zone_link

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_banner_image_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_banner_image_title',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Banner Image Title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_banner_image_title');
$config_group->setData(array (
    'uuid' => 'dcfc0afc-1add-485a-ac17-415465ec9b88',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_banner_image_title',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_banner_image_title',
    'field_name' => 'field_banner_image_title',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Banner Image Title',
    'description' => '',
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
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_text_zone');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_text_zone',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Text Zone',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_text_zone');
$config_group->setData(array (
    'uuid' => '686bb7b9-a957-4b32-a661-71530ce10489',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_text_zone',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'text',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_text_zone',
    'field_name' => 'field_text_zone',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Text Zone',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'text_long',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_text_color');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_text_color',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Text Color',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_text_color');
$config_group->setData(array (
    'uuid' => 'b1d5c1e8-5fa9-4d91-96d8-81381860d0a2',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_text_color',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'options',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_text_color',
    'field_name' => 'field_text_color',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Text Color',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
            0 =>
                array (
                    'value' => 'black',
                ),
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'list_string',
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_navigation_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_navigation_link',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Navigation link',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_navigation_link');
$config_group->setData(array (
    'uuid' => '2337f8bb-5c47-4efd-b3d9-d9e2b253dc4a',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_navigation_link',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'link',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_navigation_link',
    'field_name' => 'field_navigation_link',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Navigation link',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
            'link_type' => 17,
            'title' => 1,
        ),
    'field_type' => 'link',
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_name');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_name',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Name',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_name');
$config_group->setData(array (
    'uuid' => 'd1b20428-0d49-4f16-8cc1-65dc59d44d0a',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_name',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_name',
    'field_name' => 'field_name',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Name',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_mobile_image');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_mobile_image',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Mobile Image',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_mobile_image');
$config_group->setData(array (
    'uuid' => 'c647ce3b-9799-4128-9c79-e1fa550f05ad',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_mobile_image',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_mobile_image',
    'field_name' => 'field_mobile_image',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Mobile Image',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_meta_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_meta_title',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Meta title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_meta_title');
$config_group->setData(array (
    'uuid' => '000ba44d-399f-4def-814b-4025d18fb050',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_meta_title',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_meta_title',
    'field_name' => 'field_meta_title',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Meta title',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_meta_description');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_meta_description',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Meta description',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_meta_description');
$config_group->setData(array (
    'uuid' => '545bbd35-654c-4ca1-a842-55678d16f6f6',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_meta_description',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_meta_description',
    'field_name' => 'field_meta_description',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Meta description',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_grouping_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_grouping_title',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Columns title',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_grouping_title');
$config_group->setData(array (
    'uuid' => '1569ecca-5730-48be-a737-e2011c3899f3',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_grouping_title',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_grouping_title',
    'field_name' => 'field_grouping_title',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Columns title',
    'description' => '',
    'required' => true,
    'translatable' => true,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);


$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_funct');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_funct',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Function',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_funct');
$config_group->setData(array (
    'uuid' => 'f88fc8fd-5f03-4fe7-840d-14a34af85d29',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_funct',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_funct',
    'field_name' => 'field_funct',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Function',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'string',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_desktop_image');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_desktop_image',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Desktop image',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_desktop_image');
$config_group->setData(array (
    'uuid' => '6c2517dc-ddae-4cfd-b91c-fc46a9e54ed7',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_desktop_image',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'image',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_desktop_image',
    'field_name' => 'field_desktop_image',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Desktop image',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
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
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_date');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_date',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Date',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_date');
$config_group->setData(array (
    'uuid' => '13111c15-5ec8-4f8e-b9f3-483204950b64',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_date',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'datetime',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_date',
    'field_name' => 'field_date',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Date',
    'description' => '',
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
    'default_value_callback' => '',
    'settings' =>
        array (
        ),
    'field_type' => 'datetime',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_banner_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_banner_link',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Banner Link',
        'required' => TRUE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_banner_link');
$config_group->setData(array (
    'uuid' => '1a46eaff-cd36-41c3-8a84-c4c416d0c9d8',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_banner_link',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'link',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_banner_link',
    'field_name' => 'field_banner_link',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Banner Link',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
            'link_type' => 17,
            'title' => 1,
        ),
    'field_type' => 'link',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_text_zone_link');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_text_zone_link',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Text zone Link',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_text_zone_link');
$config_group->setData(array (
    'uuid' => '5de2ea1e-79b2-41ae-9a4b-502c06981e68',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_text_zone_link',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
            'module' =>
                array (
                    0 => 'link',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_text_zone_link',
    'field_name' => 'field_text_zone_link',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Text zone Link',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
        array (
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
            'link_type' => 17,
            'title' => 1,
        ),
    'field_type' => 'link',
));
$config_group->save(TRUE);

$field = FieldConfig::loadByName('node', 'hp_eclairage_thematique', 'field_display_title');
if (empty($field)) {
    $config_array = array(
        'field_name' =>  'field_display_title',
        'entity_type' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'label' => 'Display title',
        'required' => FALSE,
    );
    FieldConfig::create($config_array)->save();
}
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.hp_eclairage_thematique.field_display_title');
$config_group->setData(
    array (
    'uuid' => '913530fc-9b8e-4a7c-bea0-345e44295f4d',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
        array (
            'config' =>
                array (
                    0 => 'field.storage.node.field_display_title',
                    1 => 'node.type.hp_eclairage_thematique',
                ),
        ),
    'id' => 'node.hp_eclairage_thematique.field_display_title',
    'field_name' => 'field_display_title',
    'entity_type' => 'node',
    'bundle' => 'hp_eclairage_thematique',
    'label' => 'Display title',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
        array (
            0 =>
                array (
                    'value' => 0,
                ),
        ),
    'default_value_callback' => '',
    'settings' =>
        array (
            'on_label' => 'On',
            'off_label' => 'Off',
        ),
    'field_type' => 'boolean',
)
);
$config_group->save(TRUE);






/********* Form display et View display of NODE **********/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.hp_eclairage_thematique.default');
$config_group->setData(
    array (
        'uuid' => '2ae6e06e-ee41-49d5-9e49-2b3c458a0fc2',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.hp_eclairage_thematique.body',
                        1 => 'field.field.node.hp_eclairage_thematique.field_banner_image_title',
                        2 => 'field.field.node.hp_eclairage_thematique.field_banner_link',
                        3 => 'field.field.node.hp_eclairage_thematique.field_date',
                        4 => 'field.field.node.hp_eclairage_thematique.field_desktop_image',
                        5 => 'field.field.node.hp_eclairage_thematique.field_display_title',
                        6 => 'field.field.node.hp_eclairage_thematique.field_funct',
                        7 => 'field.field.node.hp_eclairage_thematique.field_grouping_title',
                        8 => 'field.field.node.hp_eclairage_thematique.field_home_thematic_columns',
                        9 => 'field.field.node.hp_eclairage_thematique.field_meta_description',
                        10 => 'field.field.node.hp_eclairage_thematique.field_meta_title',
                        11 => 'field.field.node.hp_eclairage_thematique.field_mobile_image',
                        12 => 'field.field.node.hp_eclairage_thematique.field_name',
                        13 => 'field.field.node.hp_eclairage_thematique.field_navigation_link',
                        14 => 'field.field.node.hp_eclairage_thematique.field_text_color',
                        15 => 'field.field.node.hp_eclairage_thematique.field_text_zone',
                        16 => 'field.field.node.hp_eclairage_thematique.field_text_zone_link',
                        17 => 'image.style.max_325x325',
                        18 => 'node.type.hp_eclairage_thematique',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'field_group',
                        2 => 'image',
                        3 => 'link',
                        4 => 'paragraphs',
                        5 => 'text',
                        6 => 'workbench_moderation',
                    ),
            ),
        'third_party_settings' =>
            array (
                'field_group' =>
                    array (
                        'group_content' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'group_banner',
                                        1 => 'group_columns',
                                        2 => 'group_seo',
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
                                'label' => 'Content',
                            ),
                        'group_banner' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_display_title',
                                        1 => 'group_navigation_zone',
                                        2 => 'group_text_zone',
                                        3 => 'group_image_zone',
                                    ),
                                'parent_name' => 'group_content',
                                'weight' => 33,
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
                        'group_columns' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_grouping_title',
                                        1 => 'field_home_thematic_columns',
                                    ),
                                'parent_name' => 'group_content',
                                'weight' => 34,
                                'format_type' => 'tab',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'formatter' => 'closed',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Columns',
                            ),
                        'group_seo' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_meta_title',
                                        1 => 'field_meta_description',
                                    ),
                                'parent_name' => 'group_content',
                                'weight' => 35,
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
                        'group_navigation_zone' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_navigation_link',
                                    ),
                                'parent_name' => 'group_banner',
                                'weight' => 33,
                                'format_type' => 'fieldset',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Navigation Zone',
                            ),
                        'group_text_zone' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'title',
                                        1 => 'field_text_zone',
                                        2 => 'field_text_zone_link',
                                    ),
                                'parent_name' => 'group_banner',
                                'weight' => 34,
                                'format_type' => 'fieldset',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Text Zone',
                            ),
                        'group_image_zone' =>
                            array (
                                'children' =>
                                    array (
                                        0 => 'field_date',
                                        1 => 'field_banner_image_title',
                                        2 => 'field_name',
                                        3 => 'field_funct',
                                        4 => 'field_banner_link',
                                        5 => 'field_text_color',
                                        6 => 'field_desktop_image',
                                        7 => 'field_mobile_image',
                                    ),
                                'parent_name' => 'group_banner',
                                'weight' => 35,
                                'format_type' => 'fieldset',
                                'format_settings' =>
                                    array (
                                        'id' => '',
                                        'classes' => '',
                                        'description' => '',
                                        'required_fields' => true,
                                    ),
                                'label' => 'Image Zone',
                            ),
                    ),
            ),
        'id' => 'node.hp_eclairage_thematique.default',
        'targetEntityType' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'mode' => 'default',
        'content' =>
            array (
                'field_banner_image_title' =>
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
                'field_banner_link' =>
                    array (
                        'weight' => 16,
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
                'field_date' =>
                    array (
                        'weight' => 12,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                        'region' => 'content',
                    ),
                'field_desktop_image' =>
                    array (
                        'weight' => 18,
                        'settings' =>
                            array (
                                'preview_image_style' => 'max_650',
                                'progress_indicator' => 'throbber',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_display_title' =>
                    array (
                        'weight' => 32,
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
                'field_funct' =>
                    array (
                        'weight' => 15,
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
                'field_grouping_title' =>
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
                'field_home_thematic_columns' =>
                    array (
                        'type' => 'entity_reference_paragraphs',
                        'weight' => 9,
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
                'field_meta_description' =>
                    array (
                        'weight' => 5,
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
                        'weight' => 4,
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
                'field_mobile_image' =>
                    array (
                        'weight' => 19,
                        'settings' =>
                            array (
                                'preview_image_style' => 'max_325x325',
                                'progress_indicator' => 'throbber',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image_image',
                        'region' => 'content',
                    ),
                'field_name' =>
                    array (
                        'weight' => 14,
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
                'field_navigation_link' =>
                    array (
                        'weight' => 27,
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
                'field_text_color' =>
                    array (
                        'weight' => 17,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'options_select',
                        'region' => 'content',
                    ),
                'field_text_zone' =>
                    array (
                        'weight' => 30,
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
                'field_text_zone_link' =>
                    array (
                        'weight' => 31,
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
                'title' =>
                    array (
                        'type' => 'string_textfield',
                        'weight' => 29,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.hp_eclairage_thematique.default');
$config_group->setData(
    array (
        'uuid' => 'ed9331d5-8bff-47c1-949b-08a13eda9699',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.field.node.hp_eclairage_thematique.body',
                        1 => 'field.field.node.hp_eclairage_thematique.field_banner_image_title',
                        2 => 'field.field.node.hp_eclairage_thematique.field_banner_link',
                        3 => 'field.field.node.hp_eclairage_thematique.field_date',
                        4 => 'field.field.node.hp_eclairage_thematique.field_desktop_image',
                        5 => 'field.field.node.hp_eclairage_thematique.field_display_title',
                        6 => 'field.field.node.hp_eclairage_thematique.field_funct',
                        7 => 'field.field.node.hp_eclairage_thematique.field_grouping_title',
                        8 => 'field.field.node.hp_eclairage_thematique.field_home_thematic_columns',
                        9 => 'field.field.node.hp_eclairage_thematique.field_meta_description',
                        10 => 'field.field.node.hp_eclairage_thematique.field_meta_title',
                        11 => 'field.field.node.hp_eclairage_thematique.field_mobile_image',
                        12 => 'field.field.node.hp_eclairage_thematique.field_name',
                        13 => 'field.field.node.hp_eclairage_thematique.field_navigation_link',
                        14 => 'field.field.node.hp_eclairage_thematique.field_text_color',
                        15 => 'field.field.node.hp_eclairage_thematique.field_text_zone',
                        16 => 'field.field.node.hp_eclairage_thematique.field_text_zone_link',
                        17 => 'node.type.hp_eclairage_thematique',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'entity_reference_revisions',
                        2 => 'image',
                        3 => 'link',
                        4 => 'options',
                        5 => 'text',
                        6 => 'user',
                    ),
            ),
        'id' => 'node.hp_eclairage_thematique.default',
        'targetEntityType' => 'node',
        'bundle' => 'hp_eclairage_thematique',
        'mode' => 'default',
        'content' =>
            array (
                'body' =>
                    array (
                        'label' => 'hidden',
                        'type' => 'text_default',
                        'weight' => 0,
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'region' => 'content',
                    ),
                'field_banner_image_title' =>
                    array (
                        'weight' => 21,
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
                'field_banner_link' =>
                    array (
                        'weight' => 3,
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
                'field_date' =>
                    array (
                        'weight' => 7,
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
                'field_desktop_image' =>
                    array (
                        'weight' => 19,
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
                'field_display_title' =>
                    array (
                        'weight' => 22,
                        'label' => 'hidden',
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
                'field_funct' =>
                    array (
                        'weight' => 9,
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
                'field_grouping_title' =>
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
                'field_home_thematic_columns' =>
                    array (
                        'type' => 'entity_reference_revisions_entity_view',
                        'weight' => 5,
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
                'field_meta_description' =>
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
                'field_meta_title' =>
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
                'field_mobile_image' =>
                    array (
                        'weight' => 20,
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
                        'weight' => 10,
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
                'field_navigation_link' =>
                    array (
                        'weight' => 11,
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
                'field_text_color' =>
                    array (
                        'weight' => 17,
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
                'field_text_zone' =>
                    array (
                        'weight' => 18,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'text_default',
                        'region' => 'content',
                    ),
                'field_text_zone_link' =>
                    array (
                        'weight' => 14,
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
            ),
        'hidden' =>
            array (
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(true);


/********************************  VIEW HOMEPAGE_ECLAIRAGE PLAYLIST *********************************/
echo('Création  de la vue homepage_eclairage');
//views.view.home_eclairage_playlist
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.home_eclairage_playlist');
$config_group->setData(
    array (
        'uuid' => 'c4a5dab4-b7c2-43eb-b3db-f54b9c4df6ab',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_content_owner',
                        1 => 'field.storage.node.field_visual',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'taxonomy',
                        2 => 'user',
                    ),
            ),
        'id' => 'home_eclairage_playlist',
        'label' => 'Home Eclairage Playlist',
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
                                                'items_per_page' => 10,
                                                'offset' => 0,
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'html_list',
                                        'options' =>
                                            array (
                                                'grouping' =>
                                                    array (
                                                    ),
                                                'row_class' => '',
                                                'default_row_class' => false,
                                                'type' => 'ul',
                                                'wrapper_class' => '',
                                                'class' => '',
                                            ),
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'fields',
                                        'options' =>
                                            array (
                                                'default_field_elements' => true,
                                                'inline' =>
                                                    array (
                                                    ),
                                                'separator' => '',
                                                'hide_empty' => false,
                                            ),
                                    ),
                                'fields' =>
                                    array (
                                        'field_visual' =>
                                            array (
                                                'id' => 'field_visual',
                                                'table' => 'node__field_visual',
                                                'field' => 'field_visual',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => 0,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => 0,
                                                        'text' => '',
                                                        'make_link' => 0,
                                                        'path' => '',
                                                        'absolute' => 0,
                                                        'external' => 0,
                                                        'replace_spaces' => 0,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => 0,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => 0,
                                                        'max_length' => '0',
                                                        'word_boundary' => 1,
                                                        'ellipsis' => 1,
                                                        'more_link' => 0,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => 0,
                                                        'trim' => 0,
                                                        'preserve_tags' => '',
                                                        'html' => 0,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => 1,
                                                'empty' => '',
                                                'hide_empty' => 0,
                                                'empty_zero' => 0,
                                                'hide_alter_empty' => 1,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_entity_view',
                                                'settings' =>
                                                    array (
                                                        'view_mode' => 'home_playlist_image',
                                                    ),
                                                'group_column' => 'target_id',
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
                                                'field_api_classes' => 0,
                                                'plugin_id' => 'field',
                                            ),
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
                                        'field_content_owner' =>
                                            array (
                                                'id' => 'field_content_owner',
                                                'table' => 'node__field_content_owner',
                                                'field' => 'field_content_owner',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'string',
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => false,
                                                    ),
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
                                                'plugin_id' => 'field',
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
                                'title' => 'Home Eclairage Playlist',
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
                                        'field_insight' =>
                                            array (
                                                'id' => 'field_insight',
                                                'table' => 'node__field_insight',
                                                'field' => 'field_insight',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => 'field_insight: Taxonomy term',
                                                'required' => true,
                                                'plugin_id' => 'standard',
                                            ),
                                    ),
                                'arguments' =>
                                    array (
                                        'tid' =>
                                            array (
                                                'id' => 'tid',
                                                'table' => 'taxonomy_index',
                                                'field' => 'tid',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'default_action' => 'not found',
                                                'exception' =>
                                                    array (
                                                        'value' => 'all',
                                                        'title_enable' => false,
                                                        'title' => 'All',
                                                    ),
                                                'title_enable' => false,
                                                'title' => '',
                                                'default_argument_type' => 'fixed',
                                                'default_argument_options' =>
                                                    array (
                                                        'argument' => '',
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
                                                'add_table' => false,
                                                'require_value' => false,
                                                'reduce_duplicates' => false,
                                                'plugin_id' => 'taxonomy_index_tid',
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
                                        0 => 'config:field.storage.node.field_content_owner',
                                        1 => 'config:field.storage.node.field_visual',
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
                                        0 => 'config:field.storage.node.field_content_owner',
                                        1 => 'config:field.storage.node.field_visual',
                                    ),
                            ),
                    ),
            ),
    )
);
$config_group->save(true);

/********************************  VIEW PAGE_THEMATIQUE ZONE DE VALORISATION*********************************/
echo('Création  de la vue page thematique');
//views.view.page_thematique
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.page_thematique');
$config_group->setData(
    array (
        'uuid' => '3e9574db-bfcd-4e75-b881-0879be5dab1a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'field.storage.node.field_highlight',
                        1 => 'field.storage.node.field_job_profile',
                        2 => 'field.storage.node.field_profile',
                        3 => 'field.storage.node.field_start_date',
                        4 => 'field.storage.node.field_visual',
                        5 => 'image.style.valorisation',
                        6 => 'taxonomy.vocabulary.industries',
                        7 => 'taxonomy.vocabulary.insight_types',
                        8 => 'taxonomy.vocabulary.jobs_profiles',
                        9 => 'taxonomy.vocabulary.regions',
                    ),
                'module' =>
                    array (
                        0 => 'datetime',
                        1 => 'media_entity',
                        2 => 'node',
                        3 => 'taxonomy',
                        4 => 'user',
                        5 => 'views_infinite_scroll',
                    ),
            ),
        'id' => 'page_thematique',
        'label' => 'Page thématique',
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
                                                'reset_button' => true,
                                                'reset_button_label' => 'Reset',
                                                'exposed_sorts_label' => 'Sort by',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array (
                                        'type' => 'infinite_scroll',
                                        'options' =>
                                            array (
                                                'items_per_page' => 8,
                                                'offset' => 0,
                                                'id' => 0,
                                                'total_pages' => NULL,
                                                'tags' =>
                                                    array (
                                                        'previous' => '‹ Previous',
                                                        'next' => 'Next ›',
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
                                                'views_infinite_scroll' =>
                                                    array (
                                                        'button_text' => 'Load More',
                                                        'automatically_load_content' => false,
                                                    ),
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'grid',
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'fields',
                                        'options' =>
                                            array (
                                                'default_field_elements' => true,
                                                'inline' =>
                                                    array (
                                                    ),
                                                'separator' => '',
                                                'hide_empty' => true,
                                            ),
                                    ),
                                'fields' =>
                                    array (
                                        'field_start_date' =>
                                            array (
                                                'id' => 'field_start_date',
                                                'table' => 'node__field_start_date',
                                                'field' => 'field_start_date',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => true,
                                                        'text' => '<div class="valorisation-element-date">
                                                        {{ field_start_date[0][\'#attributes\'][\'datetime\'] | date(\'d\') }} <br>
                                                        {{ field_start_date[0][\'#attributes\'][\'datetime\'] | date(\'m\') }} <br>
                                                        {{ field_start_date[0][\'#attributes\'][\'datetime\'] | date(\'y\') }}
                                                        </div>',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => 'div',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => 'div',
                                                'element_wrapper_class' => 'valorisation-element-date-wrapper',
                                                'element_default_classes' => false,
                                                'empty' => '',
                                                'hide_empty' => true,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'datetime_default',
                                                'settings' =>
                                                    array (
                                                        'timezone_override' => '',
                                                        'format_type' => 'html_date',
                                                    ),
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
                                                'plugin_id' => 'field',
                                            ),
                                        'field_visual' =>
                                            array (
                                                'id' => 'field_visual',
                                                'table' => 'node__field_visual',
                                                'field' => 'field_visual',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'media_thumbnail',
                                                'settings' =>
                                                    array (
                                                        'image_style' => 'valorisation',
                                                        'image_link' => '',
                                                    ),
                                                'group_column' => 'target_id',
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
                                                'plugin_id' => 'field',
                                            ),
                                        'title' =>
                                            array (
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 56,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => true,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'string',
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => true,
                                                    ),
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
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                                'plugin_id' => 'field',
                                            ),
                                        'field_highlight' =>
                                            array (
                                                'id' => 'field_highlight',
                                                'table' => 'node__field_highlight',
                                                'field' => 'field_highlight',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 150,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => true,
                                                        'preserve_tags' => '',
                                                        'html' => true,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'basic_string',
                                                'settings' =>
                                                    array (
                                                    ),
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
                                                'plugin_id' => 'field',
                                            ),
                                        'field_job_profile' =>
                                            array (
                                                'id' => 'field_job_profile',
                                                'table' => 'node__field_job_profile',
                                                'field' => 'field_job_profile',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => true,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'text' => '',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array (
                                                        'link' => false,
                                                    ),
                                                'group_column' => 'target_id',
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
                                                'plugin_id' => 'field',
                                            ),
                                        'field_profile' =>
                                            array (
                                                'id' => 'field_profile',
                                                'table' => 'node__field_profile',
                                                'field' => 'field_profile',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'label' => '',
                                                'exclude' => false,
                                                'alter' =>
                                                    array (
                                                        'alter_text' => true,
                                                        'text' => '{% if field_job_profile is not empty %}
                        {{ field_profile }} | {{ field_job_profile }} 
                        {% else %}
                        {{ field_profile }}
                        {% endif %}
                        ',
                                                        'make_link' => false,
                                                        'path' => '',
                                                        'absolute' => false,
                                                        'external' => false,
                                                        'replace_spaces' => false,
                                                        'path_case' => 'none',
                                                        'trim_whitespace' => false,
                                                        'alt' => '',
                                                        'rel' => '',
                                                        'link_class' => '',
                                                        'prefix' => '',
                                                        'suffix' => '',
                                                        'target' => '',
                                                        'nl2br' => false,
                                                        'max_length' => 0,
                                                        'word_boundary' => true,
                                                        'ellipsis' => true,
                                                        'more_link' => false,
                                                        'more_link_text' => '',
                                                        'more_link_path' => '',
                                                        'strip_tags' => false,
                                                        'trim' => false,
                                                        'preserve_tags' => '',
                                                        'html' => false,
                                                    ),
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => false,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_empty' => true,
                                                'empty_zero' => false,
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'target_id',
                                                'type' => 'entity_reference_label',
                                                'settings' =>
                                                    array (
                                                        'link' => false,
                                                    ),
                                                'group_column' => 'target_id',
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
                                                'plugin_id' => 'field',
                                            ),
                                    ),
                                'filters' =>
                                    array (
                                        'field_insight_target_id' =>
                                            array (
                                                'id' => 'field_insight_target_id',
                                                'table' => 'node__field_insight',
                                                'field' => 'field_insight_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_insight_target_id_op',
                                                        'label' => 'Insight',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_insight_target_id_op',
                                                        'identifier' => 'field_insight_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'chief_editor' => '0',
                                                                'digital_admin' => '0',
                                                                'webform_manager' => '0',
                                                                'contributor' => '0',
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
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'insight_types',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
                                            ),
                                        'field_job_profile_target_id' =>
                                            array (
                                                'id' => 'field_job_profile_target_id',
                                                'table' => 'node__field_job_profile',
                                                'field' => 'field_job_profile_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_job_profile_target_id_op',
                                                        'label' => 'Profession (field_job_profile)',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_job_profile_target_id_op',
                                                        'identifier' => 'field_job_profile_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'chief_editor' => '0',
                                                                'digital_admin' => '0',
                                                                'webform_manager' => '0',
                                                                'contributor' => '0',
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
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'jobs_profiles',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
                                            ),
                                        'field_industry_target_id' =>
                                            array (
                                                'id' => 'field_industry_target_id',
                                                'table' => 'node__field_industry',
                                                'field' => 'field_industry_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_industry_target_id_op',
                                                        'label' => 'Industry (field_industry)',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_industry_target_id_op',
                                                        'identifier' => 'field_industry_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'chief_editor' => '0',
                                                                'digital_admin' => '0',
                                                                'webform_manager' => '0',
                                                                'contributor' => '0',
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
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'industries',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
                                            ),
                                        'field_region_target_id' =>
                                            array (
                                                'id' => 'field_region_target_id',
                                                'table' => 'node__field_region',
                                                'field' => 'field_region_target_id',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'or',
                                                'value' =>
                                                    array (
                                                    ),
                                                'group' => 1,
                                                'exposed' => true,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => 'field_region_target_id_op',
                                                        'label' => 'Region (field_region)',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => 'field_region_target_id_op',
                                                        'identifier' => 'field_region_target_id',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                                'anonymous' => '0',
                                                                'administrator' => '0',
                                                                'chief_editor' => '0',
                                                                'digital_admin' => '0',
                                                                'webform_manager' => '0',
                                                                'contributor' => '0',
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
                                                'reduce_duplicates' => false,
                                                'type' => 'select',
                                                'limit' => true,
                                                'vid' => 'regions',
                                                'hierarchy' => false,
                                                'error_message' => true,
                                                'plugin_id' => 'taxonomy_index_tid',
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
                                'title' => 'Page thématique',
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
                                'filter_groups' =>
                                    array (
                                        'operator' => 'AND',
                                        'groups' =>
                                            array (
                                                1 => 'AND',
                                            ),
                                    ),
                                'use_ajax' => true,
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'url',
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_highlight',
                                        1 => 'config:field.storage.node.field_job_profile',
                                        2 => 'config:field.storage.node.field_profile',
                                        3 => 'config:field.storage.node.field_start_date',
                                        4 => 'config:field.storage.node.field_visual',
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
                                        3 => 'url.query_args',
                                        4 => 'user',
                                        5 => 'user.node_grants:view',
                                        6 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                        0 => 'config:field.storage.node.field_highlight',
                                        1 => 'config:field.storage.node.field_job_profile',
                                        2 => 'config:field.storage.node.field_profile',
                                        3 => 'config:field.storage.node.field_start_date',
                                        4 => 'config:field.storage.node.field_visual',
                                    ),
                            ),
                    ),
            ),
    )
);
$config_group->save(true);


//language.content_settings.node.homepage_eclairage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.node.homepage_eclairage');
$config_group->setData(
    array (
        'uuid' => 'a7620d16-7985-4746-9d06-af5eebb8f01a',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'node.type.homepage_eclairage',
                    ),
            ),
        'id' => 'node.homepage_eclairage',
        'target_entity_type_id' => 'node',
        'target_bundle' => 'homepage_eclairage',
        'default_langcode' => 'site_default',
        'language_alterable' => false,
    )
);
$config_group->save(true);


