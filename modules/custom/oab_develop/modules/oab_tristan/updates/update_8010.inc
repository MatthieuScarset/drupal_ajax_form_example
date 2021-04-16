<?php
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\locale\SourceString;

$contentTypes = [
  'blog_post',
  'customer_story',
  'document',
  'full_html',
  'magazine',
  'partner',
  'press_release',
  'simple_page',
  'webform'
];

#field.field.node.blog_post.field_rebond_document

##Tous les fields d'origine
$fields = [
  "field_rebond_document" => array (
    'uuid' => '42106671-ed33-421b-ad44-2399e45d9172',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_rebond_document',
            1 => 'node.type.blog_post',
            2 => 'node.type.document',
          ),
      ),
    'id' => 'node.blog_post.field_rebond_document',
    'field_name' => 'field_rebond_document',
    'entity_type' => 'node',
    'bundle' => 'blog_post',
    'label' => 'Document',
    'description' => 'Related document',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:node',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'document' => 'document',
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
  ),
  "field_page_du_site_1" => array (
    'uuid' => 'acb6ac42-6537-4f1b-8062-8d90e78fd8df',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_page_du_site_1',
            1 => 'node.type.blog_post',
            2 => 'node.type.customer_story',
            3 => 'node.type.full_html',
            4 => 'node.type.industry',
            5 => 'node.type.magazine',
            6 => 'node.type.office',
            7 => 'node.type.press_kit',
            8 => 'node.type.press_release',
            9 => 'node.type.product',
            10 => 'node.type.simple_page',
            11 => 'node.type.solution',
          ),
      ),
    'id' => 'node.blog_post.field_page_du_site_1',
    'field_name' => 'field_page_du_site_1',
    'entity_type' => 'node',
    'bundle' => 'blog_post',
    'label' => 'Site page #1',
    'description' => 'Linked content #1',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:node',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'blog_post' => 'blog_post',
                'customer_story' => 'customer_story',
                'full_html' => 'full_html',
                'industry' => 'industry',
                'magazine' => 'magazine',
                'office' => 'office',
                'press_kit' => 'press_kit',
                'press_release' => 'press_release',
                'product' => 'product',
                'simple_page' => 'simple_page',
                'solution' => 'solution',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => false,
            'auto_create_bundle' => 'blog_post',
          ),
      ),
    'field_type' => 'entity_reference',
  ),
  "field_page_du_site_2" => array (
    'uuid' => '20000bcd-f4aa-4fcb-85a8-25ce85fd33a7',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_page_du_site_2',
            1 => 'node.type.blog_post',
            2 => 'node.type.customer_story',
            3 => 'node.type.full_html',
            4 => 'node.type.industry',
            5 => 'node.type.magazine',
            6 => 'node.type.office',
            7 => 'node.type.press_kit',
            8 => 'node.type.press_release',
            9 => 'node.type.product',
            10 => 'node.type.simple_page',
            11 => 'node.type.solution',
          ),
      ),
    'id' => 'node.blog_post.field_page_du_site_2',
    'field_name' => 'field_page_du_site_2',
    'entity_type' => 'node',
    'bundle' => 'blog_post',
    'label' => 'Site page #2',
    'description' => 'Linked content #1',
    'required' => false,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
        'handler' => 'default:node',
        'handler_settings' =>
          array (
            'target_bundles' =>
              array (
                'blog_post' => 'blog_post',
                'customer_story' => 'customer_story',
                'full_html' => 'full_html',
                'industry' => 'industry',
                'magazine' => 'magazine',
                'office' => 'office',
                'press_kit' => 'press_kit',
                'press_release' => 'press_release',
                'product' => 'product',
                'simple_page' => 'simple_page',
                'solution' => 'solution',
              ),
            'sort' =>
              array (
                'field' => '_none',
              ),
            'auto_create' => false,
            'auto_create_bundle' => 'blog_post',
          ),
      ),
    'field_type' => 'entity_reference',
  )
];

$field_page_du_site_1_settings = array (
  'weight' => 37,
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
);
$field_page_du_site_2_settings = array (
  'weight' => 38,
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
);
$field_rebond_document_settings = array (
  'weight' => 36,
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
);

$traductions = [
  'field_rebond_document' => array (
    'description' => 'Remontée d\'un contenu de type document.',
  ),
  'field_page_du_site_1' => array (
    'label' => 'Page du site #1',
    'description' => 'Remontée d\'une page dans la sidebar',
  ),
  'field_page_du_site_2' => array (
    'label' => 'Page du site #2',
    'description' => 'Remontée d\'une deuxième page dans la sidebar',
  )
];

$labels = [
  'field_rebond_document' => "Document",
  'field_page_du_site_1'  => "Page du site 1",
  'field_page_du_site_2'  => "Page du site 2",
];


foreach ( $labels as $fieldName => $label ) {
  $field_storage = FieldStorageConfig::loadByName('node', $fieldName);
  if (empty($field_storage)) {
    FieldStorageConfig::create(array(
      'field_name' => $fieldName,
      'entity_type' => 'node',
      'type' => 'entity_reference',
    ))->save();
  }
  foreach ($contentTypes as $contentType) {
    $field = FieldConfig::loadByName('node', $contentType, $fieldName);
    if (empty($field)) {
      $config_array = array(
        'field_name' =>  $fieldName,
        'entity_type' => 'node',
        'bundle' => $contentType,
        'label' => $label,
        'required' => false,
      );
      FieldConfig::create($config_array)->save();
    }
  }
}

$onglet = array (
  'children' =>
    array (
      0 => 'field_rebond_document',
      1 => 'field_page_du_site_1',
      2 => 'field_page_du_site_2',
    ),
  'parent_name' => 'group_onglets',
  'weight' => 60,
  'format_type' => 'tab',
  'format_settings' =>
    array (
      'label' => 'Rebond',
      'formatter' => 'closed',
      'description' => 'Contenus relatifs qui s\'afficheront dans la zone "Rebond" ou "1/3" de la page',
      'required_fields' => true,
      'id' => '',
      'classes' => '',
    ),
  'label' => 'Rebond',
);

##Librairie pour les UUID
$uuid_service = \Drupal::service('uuid');

##Je charge la librairie pour accéder aux config en BDD
$config_factory = \Drupal::configFactory();

#print("################<br />#Debut creation des fields  ". date('H:i:s') ."<br />");
##je loop sur tous mes type de contenu pour leur ajouter les 3 fields nécessaires
foreach ($contentTypes as $content) {
  #("### $content " . date('H:i:s') . "<br />");

  ##Nom du content type en BDD
  $contentNode = "node.type." . $content;

  ##je boucle sur mes 3 fields pour faire les modifs et les ajouter à chaque fois
  foreach ($fields as $field_name=>$field_data) {
    #print("###### $field_name <br />");
    ##je duplique mon array pour ne pas travailler sur celui de base
    $field_data_m = $field_data;

    ##Je regènère un nouvel UUID
    $field_data['uuid'] = $uuid_service->generate();

    ##Je reconstitue l'id du field et le set
    $field_id = "node." . $content . "." . $field_name;
    $field_data_m['id'] = $field_id;


    ##Je set le nom du bundle correspondant (ie. le content type)
    $field_data_m['bundle'] = $content;

    ##Si le content n'est pas dans les dependances, je l'ajoute
    if (false === array_search($contentNode, $field_data_m['dependencies']['config'])) {
      $taille = count($field_data_m['dependencies']['config']);
      $field_data_m['dependencies']['config'][$taille] = $contentNode;
    }


    ##Je reconstitue le nom BDD
    $field_bddName = "field.field.node." . $content . "." . $field_name;

      ##Ajout du field au content
    $config_group = $config_factory->getEditable($field_bddName);
    $config_group->setData($field_data_m);
    $config_group->save(TRUE);

    ##traduction des champs en Fr
    $collection = \Drupal::service('config.storage')->createCollection('language.fr');
    $collection->write($field_bddName, $traductions[$field_name]);

    ##Ajout du field au display form au bon endroit
    $display_form_config = "core.entity_form_display.node.$content.default";
    $config_group_display_form = $config_factory->getEditable($display_form_config);

    $display_form_array = $config_group_display_form->get();

    if (count($display_form_array)>0) {
      $display_form_array['content']['field_page_du_site_1'] = $field_page_du_site_1_settings;
      $display_form_array['content']['field_page_du_site_2'] = $field_page_du_site_2_settings;
      $display_form_array['content']['field_rebond_document'] = $field_rebond_document_settings;

      ##
      /*while (false !== (
          $key =
          array_search('group_rebond',$display_form_array['third_party_settings']['field_group']['group_onglets']['children'] ))
        ) {
          unset($display_form_array['third_party_settings']['field_group']['group_onglets']['children'][$key]);
      }*/


      $display_form_array['third_party_settings']['field_group']['group_rebond'] = $onglet;
      $nbChildren = count($display_form_array['third_party_settings']['field_group']['group_onglets']['children']);
      $display_form_array['third_party_settings']['field_group']['group_onglets']['children'][$nbChildren] = "group_rebond";

      $config_group_display_form->setData($display_form_array);
      $config_group_display_form->save(TRUE);

    }
  }
}

#print("################<br />#Fin de la creation des fields  ". date('H:i:s') ."<br />");

##Creation de la vue, des blocks et des displays views pour l'affichage
$configs = [
  'views.view.rebond_document' => array (
    'uuid' => '16e8cc16-a703-4a0c-ab38-5671ace35ed0',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.node.field_page_du_site_1',
            1 => 'field.storage.node.field_page_du_site_2',
            2 => 'field.storage.node.field_rebond_document',
          ),
        'module' =>
          array (
            0 => 'node',
            1 => 'user',
          ),
      ),
    'id' => 'rebond_document',
    'label' => 'Zone rebond',
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
                        'submit_button' => 'Appliquer',
                        'reset_button' => false,
                        'reset_button_label' => 'Réinitialiser',
                        'exposed_sorts_label' => 'Trier par',
                        'expose_sort_order' => true,
                        'sort_asc_label' => 'Asc',
                        'sort_desc_label' => 'Desc',
                      ),
                  ),
                'pager' =>
                  array (
                    'type' => 'none',
                    'options' =>
                      array (
                        'offset' => 0,
                      ),
                  ),
                'style' =>
                  array (
                    'type' => 'default',
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
                    'field_page_du_site_1' =>
                      array (
                        'id' => 'field_page_du_site_1',
                        'table' => 'node__field_page_du_site_1',
                        'field' => 'field_page_du_site_1',
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
                        'type' => 'entity_reference_entity_view',
                        'settings' =>
                          array (
                            'view_mode' => 'rebond_page_site',
                          ),
                        'group_column' => 'target_id',
                        'group_columns' =>
                          array (
                          ),
                        'group_rows' => true,
                        'delta_limit' => 2,
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
                'title' => 'rebond_document',
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
                    'field_page_du_site_1' =>
                      array (
                        'id' => 'field_page_du_site_1',
                        'table' => 'node__field_page_du_site_1',
                        'field' => 'field_page_du_site_1',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => 'field_page_du_site_1 : Contenu',
                        'required' => true,
                        'plugin_id' => 'standard',
                      ),
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
                        'not' => false,
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
                    0 => 'config:field.storage.node.field_page_du_site_1',
                  ),
              ),
          ),
        'block_document' =>
          array (
            'display_plugin' => 'block',
            'id' => 'block_document',
            'display_title' => 'Document',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'allow' =>
                  array (
                    'items_per_page' => true,
                  ),
                'display_description' => '',
                'pager' =>
                  array (
                    'type' => 'some',
                    'options' =>
                      array (
                        'items_per_page' => 1,
                        'offset' => 0,
                      ),
                  ),
                'defaults' =>
                  array (
                    'pager' => false,
                    'relationships' => false,
                    'fields' => false,
                  ),
                'relationships' =>
                  array (
                    'field_rebond_document' =>
                      array (
                        'id' => 'field_rebond_document',
                        'table' => 'node__field_rebond_document',
                        'field' => 'field_rebond_document',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => 'field_rebond_document : Contenu',
                        'required' => true,
                        'plugin_id' => 'standard',
                      ),
                  ),
                'fields' =>
                  array (
                    'field_rebond_document' =>
                      array (
                        'id' => 'field_rebond_document',
                        'table' => 'node__field_rebond_document',
                        'field' => 'field_rebond_document',
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
                        'type' => 'entity_reference_entity_view',
                        'settings' =>
                          array (
                            'view_mode' => 'rebond_document',
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
                    0 => 'config:field.storage.node.field_rebond_document',
                  ),
              ),
          ),
        'block_page_site_1' =>
          array (
            'display_plugin' => 'block',
            'id' => 'block_page_site_1',
            'display_title' => 'Page du site #1',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'allow' =>
                  array (
                    'items_per_page' => true,
                  ),
                'display_description' => '',
                'relationships' =>
                  array (
                    'field_page_du_site_1' =>
                      array (
                        'id' => 'field_page_du_site_1',
                        'table' => 'node__field_page_du_site_1',
                        'field' => 'field_page_du_site_1',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => 'field_page_du_site_1 : Contenu',
                        'required' => true,
                        'plugin_id' => 'standard',
                      ),
                  ),
                'defaults' =>
                  array (
                    'relationships' => false,
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
                    0 => 'config:field.storage.node.field_page_du_site_1',
                  ),
              ),
          ),
        'block_page_site_2' =>
          array (
            'display_plugin' => 'block',
            'id' => 'block_page_site_2',
            'display_title' => 'Page du site #2',
            'position' => 1,
            'display_options' =>
              array (
                'display_extenders' =>
                  array (
                  ),
                'allow' =>
                  array (
                    'items_per_page' => true,
                  ),
                'display_description' => '',
                'relationships' =>
                  array (
                    'field_page_du_site_2' =>
                      array (
                        'id' => 'field_page_du_site_2',
                        'table' => 'node__field_page_du_site_2',
                        'field' => 'field_page_du_site_2',
                        'relationship' => 'none',
                        'group_type' => 'group',
                        'admin_label' => 'field_page_du_site_2 : Contenu',
                        'required' => true,
                        'plugin_id' => 'standard',
                      ),
                  ),
                'defaults' =>
                  array (
                    'relationships' => false,
                    'fields' => false,
                  ),
                'fields' =>
                  array (
                    'field_page_du_site_2' =>
                      array (
                        'id' => 'field_page_du_site_2',
                        'table' => 'node__field_page_du_site_2',
                        'field' => 'field_page_du_site_2',
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
                        'type' => 'entity_reference_entity_view',
                        'settings' =>
                          array (
                            'view_mode' => 'rebond_page_site',
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
                    0 => 'config:field.storage.node.field_page_du_site_2',
                  ),
              ),
          ),
      ),
  ),
  'block.block.views_block__rebond_document_block_document' => array (
    'uuid' => '8ad63b1b-162e-4c1c-984c-063e9a53b939',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'views.view.rebond_document',
          ),
        'module' =>
          array (
            0 => 'ctools',
            1 => 'views',
          ),
        'theme' =>
          array (
            0 => 'theme_boosted',
          ),
      ),
    'id' => 'views_block__rebond_document_block_document',
    'theme' => 'theme_boosted',
    'region' => 'sidebar',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'views_block:rebond_document-block_document',
    'settings' =>
      array (
        'id' => 'views_block:rebond_document-block_document',
        'label' => '',
        'provider' => 'views',
        'label_display' => '0',
        'views_label' => '',
        'items_per_page' => 'none',
        'context_mapping' =>
          array (
          ),
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
                'full_html' => 'full_html',
                'magazine' => 'magazine',
                'partner' => 'partner',
                'press_release' => 'press_release',
                'simple_page' => 'simple_page',
                'webform' => 'webform',
              ),
            'negate' => false,
            'context_mapping' =>
              array (
                'node' => '@node.node_route_context:node',
              ),
          ),
      ),
  ),
  'block.block.views_block__rebond_document_block_page_site_1' => array (
    'uuid' => '6149aaff-4d21-4acc-88c5-401600ea036a',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'views.view.rebond_document',
          ),
        'module' =>
          array (
            0 => 'ctools',
            1 => 'views',
          ),
        'theme' =>
          array (
            0 => 'theme_boosted',
          ),
      ),
    'id' => 'views_block__rebond_document_block_page_site_1',
    'theme' => 'theme_boosted',
    'region' => 'sidebar',
    'weight' => 0,
    'provider' => NULL,
    'plugin' => 'views_block:rebond_document-block_page_site_1',
    'settings' =>
      array (
        'id' => 'views_block:rebond_document-block_page_site_1',
        'label' => '',
        'provider' => 'views',
        'label_display' => '0',
        'views_label' => '',
        'items_per_page' => 'none',
        'context_mapping' =>
          array (
          ),
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
                'full_html' => 'full_html',
                'magazine' => 'magazine',
                'partner' => 'partner',
                'press_release' => 'press_release',
                'simple_page' => 'simple_page',
                'webform' => 'webform',
              ),
            'negate' => false,
            'context_mapping' =>
              array (
                'node' => '@node.node_route_context:node',
              ),
          ),
      ),
  ),
  'block.block.views_block__rebond_document_block_page_site_2' => array (
      'uuid' => 'cd334b79-11a3-43b9-9b83-9dd49a6285ee',
      'langcode' => 'fr',
      'status' => true,
      'dependencies' =>
        array (
          'config' =>
            array (
              0 => 'views.view.rebond_document',
            ),
          'module' =>
            array (
              0 => 'ctools',
              1 => 'views',
            ),
          'theme' =>
            array (
              0 => 'theme_boosted',
            ),
        ),
      'id' => 'views_block__rebond_document_block_page_site_2',
      'theme' => 'theme_boosted',
      'region' => 'sidebar',
      'weight' => 0,
      'provider' => NULL,
      'plugin' => 'views_block:rebond_document-block_page_site_2',
      'settings' =>
        array (
          'id' => 'views_block:rebond_document-block_page_site_2',
          'label' => '',
          'provider' => 'views',
          'label_display' => '0',
          'views_label' => '',
          'items_per_page' => 'none',
          'context_mapping' =>
            array (
            ),
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
                  'full_html' => 'full_html',
                  'magazine' => 'magazine',
                  'partner' => 'partner',
                  'press_release' => 'press_release',
                  'simple_page' => 'simple_page',
                  'webform' => 'webform',
                ),
              'negate' => false,
              'context_mapping' =>
                array (
                  'node' => '@node.node_route_context:node',
                ),
            ),
        ),
    ),
  'core.entity_view_mode.node.rebond_document' => array (
    'uuid' => '2a7fd942-d107-485a-8872-8635eb1b4bc1',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
    array (
      'module' =>
      array (
        0 => 'node',
      ),
    ),
    'id' => 'node.rebond_document',
    'label' => 'rebond_document',
    'targetEntityType' => 'node',
    'cache' => true,
  ),
  'core.entity_view_mode.node.rebond_page_site' => array (
    'uuid' => 'faa4075a-3c39-46fd-8839-0f9a70a64a38',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
          ),
      ),
    'id' => 'node.rebond_page_site',
    'label' => 'rebond_page_site',
    'targetEntityType' => 'node',
    'cache' => true,
  ),
  'field.storage.node.field_rebond_document' => array (
    'uuid' => 'a3ef6b5b-4639-4e19-9b06-a7fbd87ed1a8',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
          ),
      ),
    'id' => 'node.field_rebond_document',
    'field_name' => 'field_rebond_document',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'node',
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
  ),
  'field.storage.node.field_page_du_site_1' => array (
    'uuid' => '0288d123-281e-4eb4-b05e-7930accb253f',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
          ),
      ),
    'id' => 'node.field_page_du_site_1',
    'field_name' => 'field_page_du_site_1',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'node',
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
  ),
  'field.storage.node.field_page_du_site_2' => array (
    'uuid' => '91eea279-7ea0-40dd-b381-fd3081d16e5d',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'node',
          ),
      ),
    'id' => 'node.field_page_du_site_2',
    'field_name' => 'field_page_du_site_2',
    'entity_type' => 'node',
    'type' => 'entity_reference',
    'settings' =>
      array (
        'target_type' => 'node',
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
];

foreach ($configs as $configName => $config) {
  $config_group = $config_factory->getEditable($configName);
  $config_group->setData($config);
  $config_group->save(TRUE);
}
#print("################<br />#Fin de l'update ". date('H:i:s') ."<br />");

##Ajout des traductions nécessaires
$translations = array(
  array("source" => "Read more", "translation" => array("fr" => "En savoir plus")),
  array("source" => "My Service Space", "translation" => array("fr"=>"Mon Espace Client Entreprise")),
  array("source" => "Track your use, manage your bills, options and services 24/24",
    "translation" => array("fr"=>"Suivez vos consommations, gérez vos factures, vos options et services 24h/24")),
  array("source" => "Sign in", "translation" => array("fr" => "Se connecter")),
);

$storage = \Drupal::service('locale.storage');

foreach ($translations AS $translation) {
  $string = $storage->findString(array('source' => $translation['source']));
  if (is_null($string)) {
    $string = new SourceString();
    $string->setString($translation['source']);
    $string->setStorage($storage);
    $string->save();
  }

  foreach ($translation['translation'] as $language => $translated_string) {
    // Create translation. If one already exists, it will be replaced.
    $translation = $storage->createTranslation(array(
      'lid' => $string->lid,
      'language' => $language,
      'translation' => $translated_string,
    ))->save();
  }
}


#A enlever à la fin des tests
//throw new UpdateException();