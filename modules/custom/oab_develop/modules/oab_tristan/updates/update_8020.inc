<?php

/**
 * Mise à jour du display layout de la subhome Offres (Produits, Catalogue et les 2 autres termes)
 * pour ajouter l'ornemtal visuel et la solution en actif afin qu'ils puissent être visibles par le template
 */

$config_factory = \Drupal::configFactory();

############################
##Modification du formulaire
$config_group = $config_factory->getEditable('core.entity_view_display.node.product.subhome');

##On reset
$config_group->setData(array (
  'uuid' => '5ccac2f5-5357-4d2f-b3ae-a04b42c1d9a3',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'core.entity_view_mode.node.subhome',
          1 => 'field.field.node.product.field_axiome_data',
          2 => 'field.field.node.product.field_content',
          3 => 'field.field.node.product.field_content_owner',
          4 => 'field.field.node.product.field_email_owner',
          5 => 'field.field.node.product.field_end_date',
          6 => 'field.field.node.product.field_file',
          7 => 'field.field.node.product.field_highlight',
          8 => 'field.field.node.product.field_id_fiche',
          9 => 'field.field.node.product.field_id_offre',
          10 => 'field.field.node.product.field_industry',
          11 => 'field.field.node.product.field_job_profile',
          12 => 'field.field.node.product.field_market_segment',
          13 => 'field.field.node.product.field_meta_description',
          14 => 'field.field.node.product.field_meta_title',
          15 => 'field.field.node.product.field_metatags',
          16 => 'field.field.node.product.field_region',
          17 => 'field.field.node.product.field_solution',
          18 => 'field.field.node.product.field_start_date',
          19 => 'field.field.node.product.field_sub_family',
          20 => 'field.field.node.product.field_subhome',
          21 => 'field.field.node.product.field_top_zone',
          22 => 'field.field.node.product.field_top_zone_background',
          23 => 'field.field.node.product.field_visual',
          24 => 'node.type.product',
        ),
      'module' =>
        array (
          0 => 'user',
        ),
    ),
  'id' => 'node.product.subhome',
  'targetEntityType' => 'node',
  'bundle' => 'product',
  'mode' => 'subhome',
  'content' =>
    array (
      'field_solution' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 1,
          'region' => 'content',
          'label' => 'visually_hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
      'field_visual' =>
        array (
          'type' => 'entity_reference_entity_view',
          'weight' => 0,
          'region' => 'content',
          'label' => 'visually_hidden',
          'settings' =>
            array (
              'link' => true,
              'view_mode' => 'default',
            ),
          'third_party_settings' =>
            array (
            ),
        ),
    ),
  'hidden' =>
    array (
      'field_axiome_data' => true,
      'field_content' => true,
      'field_content_owner' => true,
      'field_email_owner' => true,
      'field_end_date' => true,
      'field_file' => true,
      'field_highlight' => true,
      'field_id_fiche' => true,
      'field_id_offre' => true,
      'field_industry' => true,
      'field_job_profile' => true,
      'field_market_segment' => true,
      'field_meta_description' => true,
      'field_meta_title' => true,
      'field_metatags' => true,
      'field_region' => true,
      'field_start_date' => true,
      'field_sub_family' => true,
      'field_subhome' => true,
      'field_top_zone' => true,
      'field_top_zone_background' => true,
      'langcode' => true,
      'links' => true,
      'workbench_moderation_control' => true,
    ),
));

##On save
$config_group->save(TRUE);
