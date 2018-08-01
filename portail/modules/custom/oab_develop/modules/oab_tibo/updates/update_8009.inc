<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

$field_storage = FieldStorageConfig::loadByName('node', 'field_top_zone_background');
if (empty($field_storage)) {
	FieldStorageConfig::create(array(
		'field_name' => 'field_top_zone_background',
		'entity_type' => 'node',
		'type' => 'entity_reference',
	))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_top_zone_background');
if (empty($field)) {
	$config_array = array(
		'field_name' =>  'field_top_zone_background',
		'entity_type' => 'node',
		'bundle' => 'product',
		'label' => 'Top zone background',
		'required' => FALSE,
	);
	FieldConfig::create($config_array)->save();
}

// storage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_top_zone');
$config_group->setData(
  array (
    'uuid' => '49b405a0-d474-4065-a211-2ce9e4cca553',
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
    'id' => 'node.field_top_zone',
    'field_name' => 'field_top_zone',
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
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.storage.node.field_top_zone_background');
$config_group->setData(
  array (
    'uuid' => '40da4255-5a7e-4f1a-acd9-42606407d5da',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'media_entity',
            1 => 'node',
          ),
      ),
    'id' => 'node.field_top_zone_background',
    'field_name' => 'field_top_zone_background',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'media',
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

// fields
$config_group = $config_factory->getEditable('field.field.node.product.field_top_zone');
$config_group->setData(
  array (
    'uuid' => 'a5247275-b9fe-456b-b2ca-42ab75ad0806',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_top_zone',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'node.product.field_top_zone',
    'field_name' => 'field_top_zone',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Top zone',
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
    'field_type' => 'text_long',
  )
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.product.field_top_zone_background');
$config_group->setData(
  array (
    'uuid' => '27560084-d093-4b83-8e70-6a797b70e5c3',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_top_zone_background',
            1 => 'media_entity.bundle.image',
            2 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.field_top_zone_background',
    'field_name' => 'field_top_zone_background',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Top zone background',
    'description' => '',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
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
    'field_type' => 'entity_reference',
  )
);
$config_group->save(TRUE);

// content type product
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.product.default');
$config_group->setData(
array (
  'uuid' => '2836a2b4-4feb-423c-a23c-35e333688957',
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
          11 => 'field.field.node.product.field_region',
          12 => 'field.field.node.product.field_solution',
          13 => 'field.field.node.product.field_start_date',
          14 => 'field.field.node.product.field_sub_family',
          15 => 'field.field.node.product.field_subhome',
          16 => 'field.field.node.product.field_top_zone',
          17 => 'field.field.node.product.field_top_zone_background',
          18 => 'node.type.product',
        ),
      'module' =>
        array (
          0 => 'metatag',
          1 => 'text',
          2 => 'user',
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
          'weight' => 2,
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
      'field_meta_description' =>
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
      'field_meta_title' =>
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
      'field_metatags' =>
        array (
          'weight' => 5,
          'label' => 'hidden',
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'type' => 'metatag_empty_formatter',
          'region' => 'content',
        ),
      'field_top_zone_background' =>
        array (
          'weight' => 6,
          'label' => 'above',
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
      'links' =>
        array (
          'weight' => 1,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'region' => 'content',
        ),
      'workbench_moderation_control' =>
        array (
          'weight' => 0,
          'settings' =>
            array (
            ),
          'third_party_settings' =>
            array (
            ),
          'region' => 'content',
        ),
    ),
  'hidden' =>
    array (
      'field_end_date' => true,
      'field_highlight' => true,
      'field_id_fiche' => true,
      'field_id_offre' => true,
      'field_industry' => true,
      'field_job_profile' => true,
      'field_market_segment' => true,
      'field_region' => true,
      'field_solution' => true,
      'field_start_date' => true,
      'field_sub_family' => true,
      'field_subhome' => true,
      'field_top_zone' => true,
      'langcode' => true,
    ),
)
);
$config_group->save(TRUE);

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
            0 => 'entity_browser.browser.browse_media_modal',
            1 => 'field.field.node.product.field_content',
            2 => 'field.field.node.product.field_end_date',
            3 => 'field.field.node.product.field_highlight',
            4 => 'field.field.node.product.field_id_fiche',
            5 => 'field.field.node.product.field_id_offre',
            6 => 'field.field.node.product.field_industry',
            7 => 'field.field.node.product.field_job_profile',
            8 => 'field.field.node.product.field_market_segment',
            9 => 'field.field.node.product.field_meta_description',
            10 => 'field.field.node.product.field_meta_title',
            11 => 'field.field.node.product.field_metatags',
            12 => 'field.field.node.product.field_region',
            13 => 'field.field.node.product.field_solution',
            14 => 'field.field.node.product.field_start_date',
            15 => 'field.field.node.product.field_sub_family',
            16 => 'field.field.node.product.field_subhome',
            17 => 'field.field.node.product.field_top_zone',
            18 => 'field.field.node.product.field_top_zone_background',
            19 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'datetime',
            1 => 'entity_browser',
            2 => 'field_group',
            3 => 'metatag',
            4 => 'path',
            5 => 'text',
            6 => 'workbench_moderation',
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
                    3 => 'field_top_zone_background',
                    4 => 'field_top_zone',
                    5 => 'field_content',
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
            'weight' => 7,
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
        'field_top_zone_background' =>
          array (
            'weight' => 5,
            'settings' =>
              array (
                'entity_browser' => 'browse_media_modal',
                'field_widget_display' => 'rendered_entity',
                'field_widget_edit' => true,
                'field_widget_remove' => true,
                'selection_mode' => 'selection_append',
                'field_widget_display_settings' =>
                  array (
                    'view_mode' => 'default',
                  ),
                'open' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'entity_browser_entity_reference',
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

// bloc top zone
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.topzone');
$config_group->setData(
  array (
    'uuid' => '4f93e884-e26f-402b-a392-833e615de361',
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
    'id' => 'topzone',
    'theme' => 'theme_boosted',
    'region' => 'top_zone',
    'weight' => -17,
    'provider' => NULL,
    'plugin' => 'top_zone_block',
    'settings' =>
      array (
        'id' => 'top_zone_block',
        'label' => 'Top Zone',
        'provider' => 'oab_frontoffice',
        'label_display' => 'visible',
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
                'industry' => 'industry',
                'product' => 'product',
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
  )
);
$config_group->save(TRUE);

// image style
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.top_zone');
$config_group->setData(
  array (
    'uuid' => 'f7846ea5-7648-4499-9445-d87ea096630f',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
      ),
    'name' => 'top_zone',
    'label' => 'Top zone',
    'effects' =>
      array (
        '7c40d148-7df6-4a44-8c1e-4f4015fc79ec' =>
          array (
            'uuid' => '7c40d148-7df6-4a44-8c1e-4f4015fc79ec',
            'id' => 'image_scale_and_crop',
            'weight' => 1,
            'data' =>
              array (
                'width' => 3000,
                'height' => 180,
              ),
          ),
      ),
  )
);
$config_group->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();