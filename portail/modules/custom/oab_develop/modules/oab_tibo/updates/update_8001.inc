<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * Configuration du type de contenu Product
 */

// CREATION DU FIELD TOP ZONE
$field_storage = FieldStorageConfig::loadByName('node', 'field_top_zone');
if (empty($field_storage)) {
  FieldStorageConfig::create(array(
    'field_name' => 'field_top_zone',
    'entity_type' => 'node',
    'type' => 'text_long',
  ))->save();
}

$field = FieldConfig::loadByName('node', 'product', 'field_top_zone');
if (empty($field)) {
  $config_array = array(
    'field_name' =>  'field_top_zone',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Top zone',
    'required' => FALSE,
  );
  FieldConfig::create($config_array)->save();
}

// PRODUIT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.product');
$config_group->setData(
  array (
    'uuid' => 'd3612531-99c8-4f5b-b695-daaea240ffa9',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'menu_ui',
            1 => 'workbench_access',
            2 => 'workbench_moderation',
          ),
      ),
    'third_party_settings' =>
      array (
        'menu_ui' =>
          array (
            'available_menus' =>
              array (
              ),
            'parent' => '',
          ),
        'workbench_access' =>
          array (
            'workbench_access_status' => false,
          ),
        'workbench_moderation' =>
          array (
            'enabled' => true,
            'allowed_moderation_states' =>
              array (
                0 => 'published',
                1 => 'archived',
                2 => 'draft',
                3 => 'needs_review',
                4 => 'unpublished',
              ),
            'default_moderation_state' => 'draft',
          ),
      ),
    'name' => 'Produit',
    'type' => 'product',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.product', array (
  'name' => 'Produit',
));

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.node.product');
$config_group->setData(
  array (
    'uuid' => '80dd0d74-c18f-4ed6-b7c2-9c08e28f2dba',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'content_translation',
          ),
      ),
    'third_party_settings' =>
      array (
        'content_translation' =>
          array (
            'enabled' => false,
          ),
      ),
    'id' => 'node.product',
    'target_entity_type_id' => 'node',
    'target_bundle' => 'product',
    'default_langcode' => 'current_interface',
    'language_alterable' => true,
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('xmlsitemap.settings.node.product');
$config_group->setData(
  array (
    'status' => true,
    'priority' => 0.5,
    'changefreq' => 86400,
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_content');
$config_group->setData(
  array (
    'uuid' => '312543ba-92d4-4345-b1a2-b206a84251ae',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_content',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'node.product.field_content',
    'field_name' => 'field_content',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Content',
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_end_date');
$config_group->setData(
  array (
    'uuid' => 'd8aad55b-96e5-4eac-a82b-8db426319b7d',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_end_date',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'datetime',
          ),
      ),
    'id' => 'node.product.field_end_date',
    'field_name' => 'field_end_date',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'End date',
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
    'field_type' => 'datetime',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_metatags');
$config_group->setData(
  array (
    'uuid' => '5e0a19fd-febb-48a0-938f-1c46a79656d2',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_metatags',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'metatag',
          ),
      ),
    'id' => 'node.product.field_metatags',
    'field_name' => 'field_metatags',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Metatags',
    'description' => '',
    'required' => false,
    'translatable' => true,
    'default_value' =>
      array (
        0 =>
          array (
            'value' => 'a:0:{}',
          ),
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'metatag',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_meta_description');
$config_group->setData(
  array (
    'uuid' => '86731752-52e7-48fb-85cd-6e12e42a4ad1',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_meta_description',
            1 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.field_meta_description',
    'field_name' => 'field_meta_description',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Meta description',
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
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_meta_title');
$config_group->setData(
  array (
    'uuid' => '0995421a-5304-4fb4-8003-cbf5abc37e84',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_meta_title',
            1 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.field_meta_title',
    'field_name' => 'field_meta_title',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Meta title',
    'description' => 'This field is limited to 56 characters (used for SEO-optimization)',
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
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.product.field_start_date');
$config_group->setData(
  array (
    'uuid' => 'e29308bb-c2fc-46e2-95ad-d80306e7e14e',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_start_date',
            1 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'datetime',
          ),
      ),
    'id' => 'node.product.field_start_date',
    'field_name' => 'field_start_date',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Start date',
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
    'field_type' => 'datetime',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.changed');
$config_group->setData(
  array (
    'uuid' => '981c5a0c-4b8a-412a-bc66-6e03c721feba',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.changed',
    'field_name' => 'changed',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Changed',
    'description' => 'The time that the node was last edited.',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'changed',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.created');
$config_group->setData(
  array (
    'uuid' => 'faba280c-ce75-480c-adc5-e6a74cfcb633',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.created',
    'field_name' => 'created',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Authored on',
    'description' => 'The time that the node was created.',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'created',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.menu_link');
$config_group->setData(
  array (
    'uuid' => '56e723a9-89d0-4325-9665-c824f7ef55a6',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.menu_link',
    'field_name' => 'menu_link',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Menu link',
    'description' => 'Computed menu link for the node (only available during node saving).',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default',
        'handler_settings' =>
          array (
          ),
      ),
    'field_type' => 'entity_reference',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.moderation_state');
$config_group->setData(
  array (
    'uuid' => 'b7d3fa99-e241-4bf7-9b5c-460e0f8bba1b',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.moderation_state',
    'field_name' => 'moderation_state',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Moderation state',
    'description' => 'The moderation state of this piece of content.',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default',
        'handler_settings' =>
          array (
          ),
      ),
    'field_type' => 'entity_reference',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.path');
$config_group->setData(
  array (
    'uuid' => 'f8dee2b2-d86a-4f5b-85d0-4de22190a406',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'path',
          ),
      ),
    'id' => 'node.product.path',
    'field_name' => 'path',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'URL alias',
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
    'field_type' => 'path',
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.promote');
$config_group->setData(
  array (
    'uuid' => 'deaa7c2e-a486-4355-91cd-106ea25c8c11',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.promote',
    'field_name' => 'promote',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Promoted to front page',
    'description' => '',
    'required' => false,
    'translatable' => false,
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.status');
$config_group->setData(
  array (
    'uuid' => '8985d05e-0a55-4b76-8e73-797748357091',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.status',
    'field_name' => 'status',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Publishing status',
    'description' => 'A boolean indicating whether the node is published.',
    'required' => false,
    'translatable' => false,
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.sticky');
$config_group->setData(
  array (
    'uuid' => 'a9fed1e1-0ead-44b2-b639-b6b042680daf',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.sticky',
    'field_name' => 'sticky',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Sticky at top of lists',
    'description' => '',
    'required' => false,
    'translatable' => false,
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

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.title');
$config_group->setData(
  array (
    'uuid' => '257d8627-37f2-47ac-b593-bf8bc64a355f',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.title',
    'field_name' => 'title',
    'entity_type' => 'node',
    'bundle' => 'product',
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
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.base_field_override.node.product.uid');
$config_group->setData(
  array (
    'uuid' => 'c9024eec-9cdf-404c-966c-228f542a2a2d',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'node.type.product',
          ),
      ),
    'id' => 'node.product.uid',
    'field_name' => 'uid',
    'entity_type' => 'node',
    'bundle' => 'product',
    'label' => 'Authored by',
    'description' => 'The username of the content author.',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => 'Drupal\node\Entity\Node::getCurrentUserId',
    'settings' =>
      array (
        'handler' => 'default',
        'handler_settings' =>
          array (
          ),
      ),
    'field_type' => 'entity_reference',
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
            0 => 'field.field.node.product.field_content',
            1 => 'field.field.node.product.field_end_date',
            2 => 'field.field.node.product.field_meta_description',
            3 => 'field.field.node.product.field_meta_title',
            4 => 'field.field.node.product.field_metatags',
            5 => 'field.field.node.product.field_start_date',
            6 => 'field.field.node.product.field_top_zone',
            7 => 'node.type.product',
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
                    1 => 'group_publish',
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
                'label' => 'Onglets',
              ),
            'group_write' =>
              array (
                'children' =>
                  array (
                    0 => 'langcode',
                    1 => 'title',
                    2 => 'field_top_zone',
                    3 => 'field_content',
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
                'weight' => 7,
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
          ),
        'field_top_zone' =>
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
            'type' => 'text_textarea',
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
          ),
      ),
    'hidden' =>
      array (
        'created' => true,
        'promote' => true,
        'sticky' => true,
        'uid' => true,
      ),
  )
);
$config_group->save(TRUE);

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
            2 => 'field.field.node.product.field_meta_description',
            3 => 'field.field.node.product.field_meta_title',
            4 => 'field.field.node.product.field_metatags',
            5 => 'field.field.node.product.field_start_date',
            6 => 'field.field.node.product.field_top_zone',
            7 => 'node.type.product',
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
            'weight' => 3,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'text_default',
          ),
        'field_meta_description' =>
          array (
            'weight' => 5,
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
        'field_meta_title' =>
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
          ),
        'field_metatags' =>
          array (
            'weight' => 6,
            'label' => 'hidden',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'metatag_empty_formatter',
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
          ),
      ),
    'hidden' =>
      array (
        'field_end_date' => true,
        'field_start_date' => true,
        'field_top_zone' => true,
        'langcode' => true,
      ),
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.product.teaser');
$config_group->setData(
  array (
    'uuid' => '390f23f2-1d64-4936-b504-95095ad75b47',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'core.entity_view_mode.node.teaser',
            1 => 'field.field.node.product.field_content',
            2 => 'field.field.node.product.field_end_date',
            3 => 'field.field.node.product.field_meta_description',
            4 => 'field.field.node.product.field_meta_title',
            5 => 'field.field.node.product.field_metatags',
            6 => 'field.field.node.product.field_start_date',
            7 => 'field.field.node.product.field_top_zone',
            8 => 'node.type.product',
          ),
        'module' =>
          array (
            0 => 'text',
            1 => 'user',
          ),
      ),
    'id' => 'node.product.teaser',
    'targetEntityType' => 'node',
    'bundle' => 'product',
    'mode' => 'teaser',
    'content' =>
      array (
        'field_content' =>
          array (
            'type' => 'text_trimmed',
            'weight' => 1,
            'label' => 'hidden',
            'settings' =>
              array (
                'trim_length' => 100,
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'links' =>
          array (
            'weight' => 2,
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
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
          ),
      ),
    'hidden' =>
      array (
        'field_end_date' => true,
        'field_meta_description' => true,
        'field_meta_title' => true,
        'field_metatags' => true,
        'field_start_date' => true,
        'field_top_zone' => true,
        'langcode' => true,
      ),
  )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.newsletterblock');
$config_group->setData(array (
  'uuid' => '07fd0e88-fc31-44c5-93ee-5d6be88156a5',
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
  'id' => 'newsletterblock',
  'theme' => 'theme_boosted',
  'region' => 'sidebar',
  'weight' => 0,
  'provider' => NULL,
  'plugin' => 'newsletter_block',
  'settings' =>
    array (
      'id' => 'newsletter_block',
      'label' => 'Newsletter Block',
      'provider' => 'oab_frontoffice',
      'label_display' => '0',
    ),
  'visibility' =>
    array (
      'entity_bundle:node' =>
        array (
          'id' => 'entity_bundle:node',
          'bundles' =>
            array (
              'blog_post' => 'blog_post',
              'customer_story' => 'customer_story',
              'document' => 'document',
              'magazine' => 'magazine',
              'partner' => 'partner',
              'press_kit' => 'press_kit',
              'press_release' => 'press_release',
              'product' => 'product',
              'simple_page' => 'simple_page',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => '@node.node_route_context:node',
            ),
        ),
    ),
));
$config_group->save(TRUE);

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
    'region' => 'pre_content',
    'weight' => -17,
    'provider' => NULL,
    'plugin' => 'top_zone_block',
    'settings' =>
      array (
        'id' => 'top_zone_block',
        'label' => 'Top Zone',
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
