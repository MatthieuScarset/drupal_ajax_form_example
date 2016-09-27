<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('pathauto.pattern.nodes');
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