<?php
/*
 * Ajout du bloc Mediatheque
 */

$config_factory = \Drupal::configFactory();

############################
##Modification du formulaire
$config_group = $config_factory->getEditable('block.block.mediatheque');

##On reset
$config_group->setData(array (
  'uuid' => 'c29ffabd-bae1-421d-989a-500dff464917',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'ctools',
          1 => 'language',
          2 => 'oab_frontoffice',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'mediatheque',
  'theme' => 'theme_boosted',
  'region' => 'sidebar',
  'weight' => 0,
  'provider' => NULL,
  'plugin' => 'mediatheque_block',
  'settings' =>
    array (
      'id' => 'mediatheque_block',
      'label' => 'Mediatheque',
      'provider' => 'oab_frontoffice',
      'label_display' => 'visible',
    ),
  'visibility' =>
    array (
      'entity_bundle:node' =>
        array (
          'id' => 'entity_bundle:node',
          'bundles' =>
            array (
              'press_release' => 'press_release',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'node' => '@node.node_route_context:node',
            ),
        ),
      'language' =>
        array (
          'id' => 'language',
          'langcodes' =>
            array (
              'fr' => 'fr',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'language' => '@language.current_language_context:language_interface',
            ),
        ),
    ),
));

##On save
$config_group->save(TRUE);
