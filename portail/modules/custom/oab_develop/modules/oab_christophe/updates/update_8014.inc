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
              'ru-en' => 'ru-en',
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
$config_group = $config_factory->getEditable('pathauto.pattern.case_study_en');
$config_group->setData(array(
  'uuid' => '1ad7782f-a921-4e6f-936b-015f6918c97c',
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
  'id' => 'case_study_en',
  'label' => 'case study EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'case-study/[node:title]',
  'selection_criteria' =>
    array (
      'e8fff86b-663c-4bb9-b917-a73cb86b69b4' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'customer_story' => 'customer_story',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'e8fff86b-663c-4bb9-b917-a73cb86b69b4',
        ),
      '8fd73fdd-b0a5-43ea-9004-6f2cf53cef77' =>
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
          'uuid' => '8fd73fdd-b0a5-43ea-9004-6f2cf53cef77',
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
$config_group = $config_factory->getEditable('pathauto.pattern.case_study_fr');
$config_group->setData(array(
  'uuid' => 'aff72791-b713-477c-a7e2-75acce810349',
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
  'id' => 'case_study_fr',
  'label' => 'case study FR',
  'type' => 'canonical_entities:node',
  'pattern' => 'temoignage-client/[node:title]',
  'selection_criteria' =>
    array (
      'e720b97a-7bfe-43fe-a95b-ffee97a9522e' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'customer_story' => 'customer_story',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'e720b97a-7bfe-43fe-a95b-ffee97a9522e',
        ),
      '1674f845-46b7-4edd-8f6a-9f58bd86af6a' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '1674f845-46b7-4edd-8f6a-9f58bd86af6a',
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
$config_group = $config_factory->getEditable('pathauto.pattern.case_study_ru');
$config_group->setData(array(
  'uuid' => 'e3b9da2a-480e-4f6e-b00e-ee9b4c1f672f',
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
  'id' => 'case_study_ru',
  'label' => 'case study RU',
  'type' => 'canonical_entities:node',
  'pattern' => 'projects/[node:title]',
  'selection_criteria' =>
    array (
      '6a7b64a9-a1d1-4ebe-bd28-746475695103' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'customer_story' => 'customer_story',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '6a7b64a9-a1d1-4ebe-bd28-746475695103',
        ),
      '7d67ea20-1bbb-4865-8e6b-408f5f53195a' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'ru' => 'ru',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '7d67ea20-1bbb-4865-8e6b-408f5f53195a',
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
$config_group = $config_factory->getEditable('pathauto.pattern.case_study_ru_en');
$config_group->setData(array(
  'uuid' => 'a28a9e10-234f-4801-a417-63ac228f1df9',
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
  'id' => 'case_study_ru_en',
  'label' => 'case study RU-EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'customer-stories/[node:title]',
  'selection_criteria' =>
    array (
      '82cece73-9447-42e2-b8bd-0bce67595d87' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'customer_story' => 'customer_story',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '82cece73-9447-42e2-b8bd-0bce67595d87',
        ),
      '991e5c3b-6871-4129-bcc2-3516f6b0dedf' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '991e5c3b-6871-4129-bcc2-3516f6b0dedf',
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
$config_group->setData(array(
  'uuid' => '2b8cecf2-9bd8-4444-951d-b09b920995c8',
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
  'id' => 'document_en_ru_ru_en',
  'label' => 'document EN RU RU-EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'library/[node:field_document_type:entity:name]/[node:title]',
  'selection_criteria' =>
    array (
      '1007ec6e-ea87-4744-a71e-80a2565dd466' =>
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
          'uuid' => '1007ec6e-ea87-4744-a71e-80a2565dd466',
        ),
      'a67623ef-0376-4a51-9456-a138303b29f7' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'ru' => 'ru',
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => 'a67623ef-0376-4a51-9456-a138303b29f7',
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
$config_group = $config_factory->getEditable('pathauto.pattern.document_fr');
$config_group->setData(array(
  'uuid' => 'f75ada61-579d-45bf-a080-e1dad2f56bd9',
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
  'id' => 'document_fr',
  'label' => 'document FR',
  'type' => 'canonical_entities:node',
  'pattern' => 'mediatheque/[node:field_document_type:entity:name]/[node:title]',
  'selection_criteria' =>
    array (
      '3ab8dbbc-8e34-4f90-b72c-11a52cd998ca' =>
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
          'uuid' => '3ab8dbbc-8e34-4f90-b72c-11a52cd998ca',
        ),
      '1cddaf73-ae8b-4f5e-b4af-1a15f3325615' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '1cddaf73-ae8b-4f5e-b4af-1a15f3325615',
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
              'ru' => 'ru',
              'ru-en' => 'ru-en',
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
$config_group = $config_factory->getEditable('pathauto.pattern.nodes');
$config_group->setData(array(
  'uuid' => '082bbd6d-9ed9-41f6-a65f-dd0ca83ac339',
  'langcode' => 'en',
  'status' => false,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
        ),
    ),
  'id' => 'nodes',
  'label' => 'nodes',
  'type' => 'canonical_entities:node',
  'pattern' => '[node:title]',
  'selection_criteria' =>
    array (
      '2b330202-9701-4f29-bc0d-7fbcf203bf39' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'blog_post' => 'blog_post',
              'country' => 'country',
              'customer_story' => 'customer_story',
              'document' => 'document',
              'industry' => 'industry',
              'magazine' => 'magazine',
              'partner' => 'partner',
              'press_kit' => 'press_kit',
              'press_release' => 'press_release',
              'product' => 'product',
              'profile' => 'profile',
              'region' => 'region',
              'simple_page' => 'simple_page',
              'solution' => 'solution',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '2b330202-9701-4f29-bc0d-7fbcf203bf39',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -5,
  'relationships' =>
    array (
    ),
));
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.partners_en_ru_ru_en');
$config_group->setData(array(
  'uuid' => '9f5a3b5a-6c29-46f0-95a2-2870bddfa1c2',
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
  'id' => 'partners_en_ru_ru_en',
  'label' => 'partners EN RU RU-EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'partners/[node:title]',
  'selection_criteria' =>
    array (
      '0ab49695-bd0e-429d-beea-5cfa3d45bc0d' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'partner' => 'partner',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '0ab49695-bd0e-429d-beea-5cfa3d45bc0d',
        ),
      '8070c60e-5bcb-40c7-9431-cfceff754152' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'ru' => 'ru',
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '8070c60e-5bcb-40c7-9431-cfceff754152',
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
$config_group = $config_factory->getEditable('pathauto.pattern.partners_fr');
$config_group->setData(array(
  'uuid' => '222faa5f-a06e-4789-ba86-ec72eeb94c64',
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
  'id' => 'partners_fr',
  'label' => 'partners FR',
  'type' => 'canonical_entities:node',
  'pattern' => 'partenaires/[node:title]',
  'selection_criteria' =>
    array (
      '7e6561d4-2cab-4850-9960-151334e73a9d' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'partner' => 'partner',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '7e6561d4-2cab-4850-9960-151334e73a9d',
        ),
      'd7c8703b-9447-4d04-a2df-8687bb2d9519' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => 'd7c8703b-9447-4d04-a2df-8687bb2d9519',
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
$config_group = $config_factory->getEditable('pathauto.pattern.press_en_ru_ru_en');
$config_group->setData(array(
  'uuid' => '80bfca6f-9b56-45d6-a8ae-bafcb9fa4a72',
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
  'id' => 'press_en_ru_ru_en',
  'label' => 'press EN RU RU-EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'press/[node:title]',
  'selection_criteria' =>
    array (
      'bacd1b9a-c00e-49a4-b4a4-95b2e01342c0' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'press_release' => 'press_release',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'bacd1b9a-c00e-49a4-b4a4-95b2e01342c0',
        ),
      'd8b76477-ffad-4875-bc56-f7645a895a3e' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'ru' => 'ru',
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => 'd8b76477-ffad-4875-bc56-f7645a895a3e',
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
$config_group = $config_factory->getEditable('pathauto.pattern.press_fr');
$config_group->setData(array(
  'uuid' => '87b25379-8c1f-4696-9c27-91f83d6e9c20',
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
  'id' => 'press_fr',
  'label' => 'press FR',
  'type' => 'canonical_entities:node',
  'pattern' => 'presse/[node:title]',
  'selection_criteria' =>
    array (
      '71c53c99-3d42-4197-841f-c81c52a85b3b' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'press_release' => 'press_release',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '71c53c99-3d42-4197-841f-c81c52a85b3b',
        ),
      '89868bbf-aeca-41d3-8705-035f8c85f70d' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '89868bbf-aeca-41d3-8705-035f8c85f70d',
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
$config_group = $config_factory->getEditable('pathauto.pattern.products_en_ru_ru_en');
$config_group->setData(array(
  'uuid' => '2ab0b5fa-0a2d-4209-8e24-afd7b92134ec',
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
  'id' => 'products_en_ru_ru_en',
  'label' => 'products EN RU RU-EN',
  'type' => 'canonical_entities:node',
  'pattern' => 'products/[node:title]',
  'selection_criteria' =>
    array (
      '15715f22-f634-4846-8b3f-83d3c73359b9' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'product' => 'product',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '15715f22-f634-4846-8b3f-83d3c73359b9',
        ),
      '232e1135-2851-43c6-aed7-bc512194b851' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'ru' => 'ru',
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '232e1135-2851-43c6-aed7-bc512194b851',
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
$config_group = $config_factory->getEditable('pathauto.pattern.products_fr');
$config_group->setData(array(
  'uuid' => '185b7770-7428-46a9-aacf-5f5415813573',
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
  'id' => 'products_fr',
  'label' => 'products FR',
  'type' => 'canonical_entities:node',
  'pattern' => 'produits/[node:title]',
  'selection_criteria' =>
    array (
      'f9eab3d6-5a46-427a-8050-8115a1794b02' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'product' => 'product',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'f9eab3d6-5a46-427a-8050-8115a1794b02',
        ),
      '610939f3-3ddd-4d48-bed6-934070e10999' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '610939f3-3ddd-4d48-bed6-934070e10999',
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
$config_group = $config_factory->getEditable('pathauto.pattern.simple_page');
$config_group->setData(array(
  'uuid' => 'a87b5bef-094c-4e63-bbe1-6ca5745db25f',
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
  'id' => 'simple_page',
  'label' => 'simple page',
  'type' => 'canonical_entities:node',
  'pattern' => '[node:title]',
  'selection_criteria' =>
    array (
      '78802233-4314-46e0-8d2b-ce5d630f2aa4' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'simple_page' => 'simple_page',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '78802233-4314-46e0-8d2b-ce5d630f2aa4',
        ),
      '6be09840-8d47-4cbb-8756-212fd5397b75' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'en' => 'en',
              'fr' => 'fr',
              'ru' => 'ru',
              'ru-en' => 'ru-en',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => 'node:langcode:language',
            ),
          'uuid' => '6be09840-8d47-4cbb-8756-212fd5397b75',
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