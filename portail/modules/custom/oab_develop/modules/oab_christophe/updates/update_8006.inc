<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.default');
$config_group->set('content.field_file', array (
  'weight' => 106,
  'label' => 'hidden',
  'settings' =>
    array (
      'link' => true,
      'view_mode' => 'default',
    ),
  'third_party_settings' =>
    array (
    ),
  'type' => 'entity_reference_entity_view',
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.theme_boosted_breadcrumbs');
$config_group->set('region', "content");
$config_group->set('weight', "-15");
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.theme_boosted_page_title');
$config_group->set('region', "content");
$config_group->set('weight', "-15");
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.newsletterblock');
$config_group->setData(array(
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
      'label_display' => '1',
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