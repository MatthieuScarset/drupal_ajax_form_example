<?php


$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_form_display.node.webform.default');

##Recuperation de l'array complet de la config
$data = $config_group->get();

$conf = array (
  'parent_name' => '',
  'weight' => 0,
  'format_type' => 'tabs',
  'format_settings' =>
    array (
      'id' => '',
      'classes' => '',
      'direction' => 'vertical',
    ),
  'label' => 'Onglets',);

##On rajoute les elements nécessaires
if (isset($data['third_party_settings']['field_group']['group_onglets'])) {
  if (count(isset($data['third_party_settings']['field_group']['group_onglets']))<2) {
    $data['third_party_settings']['field_group']['group_onglets'] += $conf;
  }
}

##On reset
$config_group->setData($data);

##On save
$config_group->save(TRUE);
