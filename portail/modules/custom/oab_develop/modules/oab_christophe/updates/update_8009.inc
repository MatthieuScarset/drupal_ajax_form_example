<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('user.role.contributor');
$config_group->setData(array(
  'uuid' => '9d0a2637-b58f-4e23-952a-609c8c9dc59f',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
    ),
  'id' => 'contributor',
  'label' => 'contributor',
  'weight' => 6,
  'is_admin' => NULL,
  'permissions' =>
    array (
      0 => 'access browse_medias_iframe entity browser pages',
      1 => 'access browser_file_modal entity browser pages',
      2 => 'access browse_media_modal entity browser pages',
      3 => 'access files overview',
      4 => 'use text format full_html',
      5 => 'access media overview',
      6 => 'administer media',
      7 => 'access content overview',
      8 => 'edit any full_html content',
      9 => 'edit own full_html content',
      10 => 'view full_html revisions',
      11 => 'access in-place editing',
      12 => 'access shortcuts',
      13 => 'access administration pages',
      14 => 'view the administration theme',
      15 => 'access toolbar',
      16 => 'access tour',
      17 => 'access user profiles',
      18 => 'access workbench',
      19 => 'use draft_draft transition',
      20 => 'use published_draft transition',
      21 => 'use draft_needs_review transition',
    ),
));
$config_group->save(TRUE);
