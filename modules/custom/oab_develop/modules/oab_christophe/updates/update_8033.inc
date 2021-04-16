<?php

// solutions
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.solutions_fr_en');
$config_group->delete();


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.solutions');
$config_group->setData(array(
  'uuid' => '666ec1ac-730e-4e61-aea0-1e665e8ff76a',
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
  'id' => 'solutions',
  'label' => 'solutions',
  'type' => 'canonical_entities:node',
  'pattern' => 'solutions/[node:title]',
  'selection_criteria' =>
    array (
      'da0e3701-0c0e-46df-9e26-fce0025039f9' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'solution' => 'solution',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => 'da0e3701-0c0e-46df-9e26-fce0025039f9',
        ),
      '38d370d8-50df-4312-ba24-7a2150dbc091' =>
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
          'uuid' => '38d370d8-50df-4312-ba24-7a2150dbc091',
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


// industries
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.industries_fr_en');
$config_group->delete();


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.industries');
$config_group->setData(array(
  'uuid' => '8d6932f0-baf4-40eb-b48f-bfc58dc5e22b',
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
  'id' => 'industries',
  'label' => 'industries',
  'type' => 'canonical_entities:node',
  'pattern' => 'industries/[node:title]',
  'selection_criteria' =>
    array (
      '7bb18959-0eba-4682-8cd9-922ebdf2e056' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'industry' => 'industry',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '7bb18959-0eba-4682-8cd9-922ebdf2e056',
        ),
      '7cfba12d-0e5e-4968-b3bd-b0022de127c2' =>
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
          'uuid' => '7cfba12d-0e5e-4968-b3bd-b0022de127c2',
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


// régions
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.regions_fr_en');
$config_group->delete();


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('pathauto.pattern.regions');
$config_group->setData(array(
  'uuid' => '7e8e275d-9880-486d-97b3-451c6e9ff7bb',
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
  'id' => 'regions',
  'label' => 'regions',
  'type' => 'canonical_entities:node',
  'pattern' => 'regions/[node:title]',
  'selection_criteria' =>
    array (
      '4da6f9b3-cd30-4d8f-bf85-66bba0f0a11e' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'region' => 'region',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '4da6f9b3-cd30-4d8f-bf85-66bba0f0a11e',
        ),
      'a3486acf-9c25-45fb-aec5-03d13251c59f' =>
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
          'uuid' => 'a3486acf-9c25-45fb-aec5-03d13251c59f',
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