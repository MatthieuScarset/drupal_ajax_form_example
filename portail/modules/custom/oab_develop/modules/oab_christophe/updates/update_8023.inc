<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('pathauto.settings');
$config->setData(array (
  'punctuation' =>
    array (
      'double_quotes' => 0,
      'quotes' => 0,
      'backtick' => 0,
      'comma' => 0,
      'period' => 0,
      'hyphen' => 1,
      'underscore' => 0,
      'colon' => 0,
      'semicolon' => 0,
      'pipe' => 0,
      'left_curly' => 0,
      'left_square' => 0,
      'right_curly' => 0,
      'right_square' => 0,
      'plus' => 0,
      'equal' => 0,
      'asterisk' => 0,
      'ampersand' => 0,
      'percent' => 0,
      'caret' => 0,
      'dollar' => 0,
      'hash' => 0,
      'at' => 0,
      'exclamation' => 0,
      'tilde' => 0,
      'left_parenthesis' => 0,
      'right_parenthesis' => 0,
      'question_mark' => 0,
      'less_than' => 0,
      'greater_than' => 0,
      'slash' => 0,
      'back_slash' => 0,
    ),
  'verbose' => false,
  'separator' => '-',
  'max_length' => 100,
  'max_component_length' => 100,
  'transliterate' => true,
  'reduce_ascii' => false,
  'case' => true,
  'ignore_words' => 'a, an, as, at, before, but, by, for, from, is, in, into, like, of, off, on, onto, per, since, than, the, this, that, to, up, via, with',
  'update_action' => 0,
  '_core' =>
    array (
      'default_config_hash' => 'YrQtUD-tjwXmWch1oNpPqr3qb5S17-dXdlKwqhiHjNI',
    ),
  'langcode' => 'fr',
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('pathauto.pattern.nodes');
$config->setData(array (
  'uuid' => '0543e2fd-4c48-4eb6-888b-f36346ad9eb2',
  'langcode' => 'fr',
  'status' => true,
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
      '6edb3d49-441f-4ba3-8a8e-d1af785173a9' =>
        array (
          'id' => 'node_type',
          'bundles' =>
            array (
              'container' => 'container',
              'profil_redacteur' => 'profil_redacteur',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => 'node',
            ),
          'uuid' => '6edb3d49-441f-4ba3-8a8e-d1af785173a9',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -5,
  'relationships' =>
    array (
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('pathauto.pattern.termes');
$config->setData(array (
  'uuid' => '271703a1-08c8-4b55-94bd-28bb252c9187',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'ctools',
          1 => 'taxonomy',
        ),
    ),
  'id' => 'termes',
  'label' => 'termes',
  'type' => 'canonical_entities:taxonomy_term',
  'pattern' => '[term:name]',
  'selection_criteria' =>
    array (
      'd6f88d06-189d-46e9-8006-debb9c859e45' =>
        array (
          'id' => 'entity_bundle:taxonomy_term',
          'bundles' =>
            array (
              'areas' => 'areas',
              'blog' => 'blog',
              'customer_stories' => 'customer_stories',
              'document_types' => 'document_types',
              'industries' => 'industries',
              'magazine' => 'magazine',
              'partners' => 'partners',
              'solutions' => 'solutions',
              'topic' => 'topic',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'taxonomy_term' => 'taxonomy_term',
            ),
          'uuid' => 'd6f88d06-189d-46e9-8006-debb9c859e45',
        ),
    ),
  'selection_logic' => 'and',
  'weight' => -5,
  'relationships' =>
    array (
    ),
));
$config->save(TRUE);