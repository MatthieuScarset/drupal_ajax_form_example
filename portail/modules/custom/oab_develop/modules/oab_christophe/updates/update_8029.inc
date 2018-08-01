<?php
use Drupal\paragraphs\Entity\ParagraphsType;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\Core\Entity\Entity\EntityFormDisplay;

// création du bundle de paragraph
$paragraphStorage = ParagraphsType::load('related_content');
if (empty($paragraphStorage)) {
  $paragraphType = ParagraphsType::create([
    'id' => 'related_content',
    'label' => 'related content',
    'revision' => false
  ]);
  $paragraphType->save();
}

// création des champs pour le paragraph
/****** storage ******/
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_title');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'type' => 'string',
    'cardinality' => 1,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_catcher');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_catcher',
    'entity_type' => 'paragraph',
    'type' => 'string_long',
    'cardinality' => 1,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_link');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'type' => 'link',
    'cardinality' => 1,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}
$field_storage = FieldStorageConfig::loadByName('paragraph', 'field_visual');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_visual',
    'entity_type' => 'paragraph',
    'type' => 'entity_reference',
    'settings' => array('target_type' => 'media'),
    'cardinality' => 1,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}
$field_storage = FieldStorageConfig::loadByName('node', 'field_related_content');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_related_content',
    'entity_type' => 'node',
    'type' => 'entity_reference_revisions',
    'settings' =>
      array (
        'target_type' => 'paragraph',
      ),
    'cardinality' => 3,
    'translatable' => false,
    'language' => 'en',
  ))->save();
}

/****** instances ******/
$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_title');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_title',
    'entity_type' => 'paragraph',
    'bundle' => 'related_content',
    'label' => 'title',
    'required' => FALSE,
    'translatable' => false,
    'language' => 'en',
    'field_type' => 'string',
  );
  FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_catcher');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_catcher',
    'entity_type' => 'paragraph',
    'bundle' => 'related_content',
    'label' => 'catcher',
    'required' => FALSE,
    'translatable' => false,
    'language' => 'en',
    'field_type' => 'string_long',
  );
  FieldConfig::create($config_array)->save();
}

$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_link');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_link',
    'entity_type' => 'paragraph',
    'bundle' => 'related_content',
    'label' => 'link',
    'required' => FALSE,
    'translatable' => false,
    'language' => 'en',
    'field_type' => 'link',
    'settings' =>
      array (
        'link_type' => 17,
        'title' => 0,
      ),
  );
  FieldConfig::create($config_array)->save();
}
$field = FieldConfig::loadByName('paragraph', 'related_content', 'field_visual');
if (empty($field)) {
  $config_array = array(
    'field_name' => 'field_visual',
    'entity_type' => 'paragraph',
    'bundle' => 'related_content',
    'label' => 'Ornamental visual',
    'required' => FALSE,
    'translatable' => false,
    'language' => 'en',
    'field_type' => 'entity_reference',
    'settings' =>
      array (
        'handler' => 'default:media',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'image' => 'image',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => false,
            'auto_create_bundle' => '',
          ),
      ),
  );
  FieldConfig::create($config_array)->save();
}
foreach (array('solution', 'industry', 'region', 'country') AS $bundle) {
  $field = FieldConfig::loadByName('node', $bundle,'field_related_content');
  if (empty($field)) {
    $config_array = array(
      'field_name' => 'field_related_content',
      'entity_type' => 'node',
      'bundle' => $bundle,
      'label' => 'related content',
      'required' => false,
      'translatable' => false,
      'language' => 'en',
      'field_type' => 'entity_reference_revisions',
      'settings' =>
        array(
          'handler' => 'default:paragraph',
          'handler_settings' =>
            array(
              'target_bundles' =>
                array(
                  'related_content' => 'related_content',
                ),
              'target_bundles_drag_drop' =>
                array(
                  'related_content' =>
                    array(
                      'enabled' => true,
                      'weight' => 2,
                    ),
                ),
            ),
        ),
    );
    FieldConfig::create($config_array)->save();
  }
}


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.paragraph.related_content.default');
$config_group->setData(array(
  'uuid' => '635774a3-d4d2-44e6-8ed8-58271a67cedd',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'entity_browser.browser.browse_media_modal',
          1 => 'field.field.paragraph.related_content.field_catcher',
          2 => 'field.field.paragraph.related_content.field_link',
          3 => 'field.field.paragraph.related_content.field_title',
          4 => 'field.field.paragraph.related_content.field_visual',
          5 => 'paragraphs.paragraphs_type.related_content',
        ),
      'module' =>
        array (
          0 => 'entity_browser',
          1 => 'link',
          2 => 'workbench_moderation',
        ),
    ),
  'id' => 'paragraph.related_content.default',
  'targetEntityType' => 'paragraph',
  'bundle' => 'related_content',
  'mode' => 'default',
  'content' =>
    array (
      'field_catcher' =>
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
      'field_link' =>
        array (
          'weight' => 9,
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
      'field_visual' =>
        array (
          'weight' => 8,
          'settings' =>
            array (
              'entity_browser' => 'browse_media_modal',
              'field_widget_display' => 'rendered_entity',
              'field_widget_edit' => true,
              'field_widget_remove' => true,
              'selection_mode' => 'selection_append',
              'field_widget_display_settings' =>
                array (
                  'view_mode' => 'related_content_image',
                ),
              'open' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_browser_entity_reference',
          'region' => 'content',
        ),
    ),
  'hidden' =>
    array (
      'created' => true,
      'status' => true,
      'uid' => true,
    ),
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.paragraph.related_content.default');
$config_group->setData(array(
  'uuid' => '29d298f0-2a41-4cc0-8ea7-c3ec0023fb75',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'field.field.paragraph.related_content.field_catcher',
          1 => 'field.field.paragraph.related_content.field_link',
          2 => 'field.field.paragraph.related_content.field_title',
          3 => 'field.field.paragraph.related_content.field_visual',
          4 => 'paragraphs.paragraphs_type.related_content',
        ),
      'module' =>
        array (
          0 => 'link',
        ),
    ),
  'id' => 'paragraph.related_content.default',
  'targetEntityType' => 'paragraph',
  'bundle' => 'related_content',
  'mode' => 'default',
  'content' =>
    array (
      'field_catcher' =>
        array (
          'weight' => 2,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'basic_string',
          'region' => 'content',
        ),
      'field_link' =>
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
      'field_visual' =>
        array (
          'weight' => 1,
          'label' => 'hidden',
          'settings' =>
            array (
              'view_mode' => 'related_content_image',
              'link' => false,
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'entity_reference_entity_view',
          'region' => 'content',
        ),
    ),
  'hidden' =>
    array (
    ),
));
$config_group->save(true);

/****** form display powerpage ******/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.solution.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.solution.field_content',
  2 => 'field.field.node.solution.field_content_owner',
  3 => 'field.field.node.solution.field_display_title',
  4 => 'field.field.node.solution.field_email_owner',
  5 => 'field.field.node.solution.field_end_date',
  6 => 'field.field.node.solution.field_highlight',
  7 => 'field.field.node.solution.field_local_nav',
  8 => 'field.field.node.solution.field_meta_description',
  9 => 'field.field.node.solution.field_meta_title',
  10 => 'field.field.node.solution.field_related_content',
  11 => 'field.field.node.solution.field_start_date',
  12 => 'field.field.node.solution.field_top_zone',
  13 => 'field.field.node.solution.field_top_zone_background',
  14 => 'field.field.node.solution.field_visual',
  15 => 'node.type.solution',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_local_nav',
  8 => 'field_content',
  9 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'type' => 'entity_reference_paragraphs',
  'weight' => 11,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.industry.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.industry.field_content',
  2 => 'field.field.node.industry.field_content_owner',
  3 => 'field.field.node.industry.field_display_title',
  4 => 'field.field.node.industry.field_email_owner',
  5 => 'field.field.node.industry.field_end_date',
  6 => 'field.field.node.industry.field_highlight',
  7 => 'field.field.node.industry.field_local_nav',
  8 => 'field.field.node.industry.field_meta_description',
  9 => 'field.field.node.industry.field_meta_title',
  10 => 'field.field.node.industry.field_related_content',
  11 => 'field.field.node.industry.field_start_date',
  12 => 'field.field.node.industry.field_top_zone',
  13 => 'field.field.node.industry.field_top_zone_background',
  14 => 'field.field.node.industry.field_visual',
  15 => 'node.type.industry',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_local_nav',
  8 => 'field_content',
  9 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 44,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.region.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.region.field_content',
  2 => 'field.field.node.region.field_content_owner',
  3 => 'field.field.node.region.field_display_title',
  4 => 'field.field.node.region.field_email_owner',
  5 => 'field.field.node.region.field_end_date',
  6 => 'field.field.node.region.field_highlight',
  7 => 'field.field.node.region.field_meta_description',
  8 => 'field.field.node.region.field_meta_title',
  9 => 'field.field.node.region.field_related_content',
  10 => 'field.field.node.region.field_start_date',
  11 => 'field.field.node.region.field_top_zone',
  12 => 'field.field.node.region.field_top_zone_background',
  13 => 'field.field.node.region.field_visual',
  14 => 'node.type.region',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_top_zone',
  5 => 'field_top_zone_background',
  6 => 'field_visual',
  7 => 'field_content',
  8 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 10,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.country.default');
$config_group->set('dependencies.config', array(
  0 => 'entity_browser.browser.browse_media_modal',
  1 => 'field.field.node.country.field_content',
  2 => 'field.field.node.country.field_content_owner',
  3 => 'field.field.node.country.field_display_title',
  4 => 'field.field.node.country.field_email_owner',
  5 => 'field.field.node.country.field_end_date',
  6 => 'field.field.node.country.field_highlight',
  7 => 'field.field.node.country.field_meta_description',
  8 => 'field.field.node.country.field_meta_title',
  9 => 'field.field.node.country.field_region',
  10 => 'field.field.node.country.field_related_content',
  11 => 'field.field.node.country.field_start_date',
  12 => 'field.field.node.country.field_top_zone',
  13 => 'field.field.node.country.field_top_zone_background',
  14 => 'field.field.node.country.field_visual',
  15 => 'node.type.country',
));
$config_group->set('dependencies.module', array(
  0 => 'datetime',
  1 => 'entity_browser',
  2 => 'field_group',
  3 => 'paragraphs',
  4 => 'path',
  5 => 'text',
  6 => 'workbench_moderation',
));
$config_group->set('third_party_settings.field_group.group_write.children', array (
  0 => 'langcode',
  1 => 'title',
  2 => 'field_display_title',
  3 => 'field_highlight',
  4 => 'field_visual',
  5 => 'field_content',
  6 => 'field_related_content',
));
$config_group->set('content.field_related_content', array (
  'weight' => 8,
  'settings' =>
    array (
      'title' => 'Related content',
      'title_plural' => 'Related contents',
      'edit_mode' => 'open',
      'add_mode' => 'dropdown',
      'form_display_mode' => 'default',
      'default_paragraph_type' => 'related_content',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_paragraphs',
  'region' => 'content',
));
$config_group->clear('hidden.field_related_content');
$config_group->save(true);

/****** view display ******/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.solution.field_content',
  1 => 'field.field.node.solution.field_content_owner',
  2 => 'field.field.node.solution.field_display_title',
  3 => 'field.field.node.solution.field_email_owner',
  4 => 'field.field.node.solution.field_end_date',
  5 => 'field.field.node.solution.field_highlight',
  6 => 'field.field.node.solution.field_local_nav',
  7 => 'field.field.node.solution.field_meta_description',
  8 => 'field.field.node.solution.field_meta_title',
  9 => 'field.field.node.solution.field_related_content',
  10 => 'field.field.node.solution.field_start_date',
  11 => 'field.field.node.solution.field_top_zone',
  12 => 'field.field.node.solution.field_top_zone_background',
  13 => 'field.field.node.solution.field_visual',
  14 => 'node.type.solution',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'type' => 'entity_reference_revisions_entity_view',
  'weight' => 12,
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
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.industry.field_content',
  1 => 'field.field.node.industry.field_content_owner',
  2 => 'field.field.node.industry.field_display_title',
  3 => 'field.field.node.industry.field_email_owner',
  4 => 'field.field.node.industry.field_end_date',
  5 => 'field.field.node.industry.field_highlight',
  6 => 'field.field.node.industry.field_local_nav',
  7 => 'field.field.node.industry.field_meta_description',
  8 => 'field.field.node.industry.field_meta_title',
  9 => 'field.field.node.industry.field_related_content',
  10 => 'field.field.node.industry.field_start_date',
  11 => 'field.field.node.industry.field_top_zone',
  12 => 'field.field.node.industry.field_top_zone_background',
  13 => 'field.field.node.industry.field_visual',
  14 => 'node.type.industry',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 14,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.region.field_content',
  1 => 'field.field.node.region.field_content_owner',
  2 => 'field.field.node.region.field_display_title',
  3 => 'field.field.node.region.field_email_owner',
  4 => 'field.field.node.region.field_end_date',
  5 => 'field.field.node.region.field_highlight',
  6 => 'field.field.node.region.field_meta_description',
  7 => 'field.field.node.region.field_meta_title',
  8 => 'field.field.node.region.field_related_content',
  9 => 'field.field.node.region.field_start_date',
  10 => 'field.field.node.region.field_top_zone',
  11 => 'field.field.node.region.field_top_zone_background',
  12 => 'field.field.node.region.field_visual',
  13 => 'node.type.region',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 13,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.default');
$config_group->set('dependencies.config', array(
  0 => 'field.field.node.country.field_content',
  1 => 'field.field.node.country.field_content_owner',
  2 => 'field.field.node.country.field_display_title',
  3 => 'field.field.node.country.field_email_owner',
  4 => 'field.field.node.country.field_end_date',
  5 => 'field.field.node.country.field_highlight',
  6 => 'field.field.node.country.field_meta_description',
  7 => 'field.field.node.country.field_meta_title',
  8 => 'field.field.node.country.field_region',
  9 => 'field.field.node.country.field_related_content',
  10 => 'field.field.node.country.field_start_date',
  11 => 'field.field.node.country.field_top_zone',
  12 => 'field.field.node.country.field_top_zone_background',
  13 => 'field.field.node.country.field_visual',
  14 => 'node.type.country',
));
$config_group->set('dependencies.module', array(
  0 => 'entity_reference_revisions',
  1 => 'text',
  2 => 'user',
));
$config_group->set('content.field_related_content', array(
  'weight' => 15,
  'label' => 'above',
  'settings' =>
    array (
      'view_mode' => 'default',
      'link' => '',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_revisions_entity_view',
  'region' => 'content',
));
$config_group->save(true);


/****** blocks ******/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.relatedcontent');
$config_group->setData(array(
  'uuid' => '453a3215-10e6-4ac3-8cfc-761b2daf8441',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'ctools',
          1 => 'oab_frontoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'relatedcontent',
  'theme' => 'theme_boosted',
  'region' => 'prefooter',
  'weight' => -21,
  'provider' => NULL,
  'plugin' => 'related_content_block',
  'settings' =>
    array (
      'id' => 'related_content_block',
      'label' => 'Related content',
      'provider' => 'oab_frontoffice',
      'label_display' => '0',
      'context_mapping' =>
        array (
          'node' => '@node.node_route_context:node',
        ),
    ),
  'visibility' =>
    array (
      'entity_bundle:node' =>
        array (
          'id' => 'entity_bundle:node',
          'bundles' =>
            array (
              'country' => 'country',
              'industry' => 'industry',
              'region' => 'region',
              'solution' => 'solution',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => '@node.node_route_context:node',
            ),
        ),
    ),
));
$config_group->save(true);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.views_block__related_contents_block_1');
$config_group->delete();
$config_group->save(true);

/****** traduction des champs ******/
$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.paragraph.related_content.field_catcher', array (
  "label" => "résumé"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.paragraph.related_content.field_link', array (
  "label" => "lien"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.paragraph.related_content.field_title', array (
  "label" => "titre"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.paragraph.related_content.field_visual', array (
  "label" => "Visuel"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.country.field_related_content', array (
  "label" => "contenus relatifs"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.industry.field_related_content', array (
  "label" => "contenus relatifs"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.region.field_related_content', array (
  "label" => "contenus relatifs"
));

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('field.field.node.solution.field_related_content', array (
  "label" => "contenus relatifs"
));