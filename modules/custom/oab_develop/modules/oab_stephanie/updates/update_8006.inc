<?php

/**
 * Champ Meta title obligatoire
 */
//BLOG-POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//CUSTOMER STORY
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//DOCUMENT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//MAGAZINE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PARTNER
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PRESS KIT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PRESS RELEASE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PAGE SIMPLE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_meta_description');
$config_group->set('required', 'true');
$config_group->save(TRUE);


/***
 * Champ Méta title obligatoire
 */
//BLOG-POST
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//CUSTOMER STORY
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.customer_story.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//DOCUMENT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.document.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//MAGAZINE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.magazine.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PARTNER
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.partner.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PRESS KIT
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_kit.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PRESS RELEASE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.press_release.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);
//PAGE SIMPLE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.simple_page.field_meta_title');
$config_group->set('required', 'true');
$config_group->save(TRUE);


