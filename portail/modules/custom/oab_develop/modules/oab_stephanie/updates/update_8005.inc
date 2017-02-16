<?php
/**
 * Suppression du title display
 */


//BLOG-POST DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//CUSTOMER STORY DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//PRESS KIT DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//PRESS RELEASE DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//DOCUMENT DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//MAGAZINE DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);

//PARTNER DEFAULT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);


//PAGE SIMPLE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.simple_page.default');
$config_group->clear('content.field_display_title');
$config_group->set('hidden.field_display_title', 'true');
$config_group->save(TRUE);
