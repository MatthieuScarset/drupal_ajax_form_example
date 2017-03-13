<?php
//suppression des champs concernant les taxonomies à supprimer :  blogs, areas, customer_stories, magazines, partners, topics
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('field.field.node.blog_post.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.blog_post.field_blog');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.blog_post.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.blog_post.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.customer_story.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.customer_story.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.customer_story.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.document.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.document.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.document.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.document.field_topic');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.magazine.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.magazine.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.partner.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_kit.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_kit.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_kit.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_release.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_release.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.press_release.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.simple_page.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.simple_page.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.field.node.simple_page.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.storage.node.field_area');
$config_group->delete();

$config_group = $config_factory->getEditable('field.storage.node.field_blog');
$config_group->delete();

$config_group = $config_factory->getEditable('field.storage.node.field_customer_story');
$config_group->delete();

$config_group = $config_factory->getEditable('field.storage.node.field_partner');
$config_group->delete();

$config_group = $config_factory->getEditable('field.storage.node.field_topic');
$config_group->delete();


// Suppression des vocabulaires inutiles : blogs, areas, customer_stories, magazines, partners, topics
$vids_to_delete = array('areas', 'blogs', 'customer_stories', 'magazines', 'partners', 'topics');
$vocabularies = \Drupal\taxonomy\Entity\Vocabulary::loadMultiple();

foreach ($vids_to_delete as $vid_to_delete)
	if (isset($vocabularies[$vid_to_delete])) {
		$vocabulary = \Drupal\taxonomy\Entity\Vocabulary::load($vid_to_delete)->delete();
	}