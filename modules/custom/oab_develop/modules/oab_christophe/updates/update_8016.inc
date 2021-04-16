<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.blogs');
$config_group->setData(array(
  'uuid' => '3936c940-add5-42aa-9920-a3df5dc78f48',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'language',
          1 => 'node',
        ),
    ),
  'id' => 'blogs',
  'label' => 'blogs',
  'type' => 'canonical_entities:node',
  'pattern' => 'blogs/[node:title]',
  'selection_criteria' =>
    array (
      '61b56fc3-eaae-487c-b218-4e08608af3af' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'blog_post' => 'blog_post',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '61b56fc3-eaae-487c-b218-4e08608af3af',
        ),
      '4a48dc7f-f53b-4595-bd9f-e4f555d2c6bb' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'fr' => 'fr',
              'ru' => 'ru',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '4a48dc7f-f53b-4595-bd9f-e4f555d2c6bb',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -10,
  'relationships' =>
    array (
      'node:langcode:language' =>
        array (
          'label' => 'Language',
        ),
    ),
));
$config_group->save(TRUE);


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.magazine');
$config_group->setData(array(
  'uuid' => '4fe3be65-d24c-4ea0-b009-a6889933ad06',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'language',
          1 => 'node',
        ),
    ),
  'id' => 'magazine',
  'label' => 'magazine',
  'type' => 'canonical_entities:node',
  'pattern' => 'magazine/[node:title]',
  'selection_criteria' =>
    array (
      'a061c975-76fb-4c44-928d-15369008db61' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'magazine' => 'magazine',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'a061c975-76fb-4c44-928d-15369008db61',
        ),
      '04e84c4d-b7cb-44f5-b1c3-a091ff795f85' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '04e84c4d-b7cb-44f5-b1c3-a091ff795f85',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -10,
  'relationships' =>
    array (
      'node:langcode:language' =>
        array (
          'label' => 'Language',
        ),
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.document_en_ru_ru_en');
$config_group->delete();

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.document_en');
$config_group->setData(array(
  'uuid' => '97d2a76d-ad3b-47c8-86a7-cf709a86809a',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'language',
          1 => 'node',
        ),
    ),
  'id' => 'document_en',
  'label' => 'document EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'library/[node:field_document_type:entity:name]/[node:title]',
  'selection_criteria' =>
    array (
      'e99882a4-f9a8-41d5-a14b-7b55e4b90de6' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'document' => 'document',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'e99882a4-f9a8-41d5-a14b-7b55e4b90de6',
        ),
      'be5887e1-fb29-4776-903a-713e7fbe6364' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => 'be5887e1-fb29-4776-903a-713e7fbe6364',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -10,
  'relationships' =>
    array (
      'node:langcode:language' =>
        array (
          'label' => 'Language',
        ),
    ),
));
$config_group->save(TRUE);