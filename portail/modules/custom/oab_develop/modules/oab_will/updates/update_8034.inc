<?php

use Drupal\field\Entity\FieldConfig;

$connection = \Drupal\Core\Database\Database::getConnection();

$convertable = array(
'oab.akamai_settings'=> 'oab_akamai.akamai_settings',
'oab.axiome'=>'oab_axiome.axiome_settings',
'oab.cookie_compliance'=>'oab_cookie_compliance.cookie_compliance',
'oab.ece'=>'oab_backoffice.ece',
'oab.gdpr_settings'=>'oab_backoffice.gdpr_settings',
'oab.general_settings'=>'oab_backoffice.general_settings',
'oab.offices_map'=>'oab_offices_map.offices_map',
'oab.pardot'=>'oab_backoffice.pardot',
'oab.subhomes'=>'oab_subhomes.subhomes',
'oab.synomia.contentTypes'=>'oab_synomia_search.synomia.contentTypes',
'oab.synomia.searchSettings'=>'oab_synomia_search.synomia.searchSettings',
'oab.tealium'=>'oab_tealium.tealium'
);

foreach ($convertable as $key=>$value){
    $query = $connection->update('config');
    $query->fields([
        'name' => $value
    ]);
    $query->condition('name',$key);
    $query->execute();
}

$query_del = $connection->delete('config');
$query_del->condition('name','oab.settings_axiome');
$query_del->execute();

$query_del = $connection->delete('config');
$query_del->condition('name','oab.axiome_settings');
$query_del->execute();

$query_del = $connection->delete('webform_submission');
$query_del->execute();
$query_del = $connection->delete('webform_submission_data');
$query_del->execute();
$query_del = $connection->delete('webform_submission_log');
$query_del->execute();

/*$vocab = \Drupal\taxonomy\Entity\Vocabulary::load("hub");
if ($vocab) {
  $vocab->delete();
}*/



$query_del = $connection->delete('webform_submission_log');
$query_del->execute();

/*foreach ($tids as $tid) {
  $consulting = \Drupal\taxonomy\Entity\term::load($tid);
  if ($consulting) {
    $consulting->delete();
  }
}*/

$fields = [
  'field_hub_menus',
  'field_hub_blocs',
  'field_hub_subhomes',
  'field_hub_url',
  'field_hub_machine_name_suffixe'
];


foreach ($fields as $field) {

  if (Drupal::database()->schema()->tableExists('field_deleted_data_e3b0c44298')) {
    Drupal::database()->schema()->dropTable('field_deleted_data_e3b0c44298');
  }


  $field_config = FieldConfig::loadByName('taxonomy_term', 'hub', $field);
  if ($field_config !== null) {
    $field_config->delete();
  }

  // Deleting field storage.
  $field_storage = \Drupal\field\Entity\FieldStorageConfig::loadByName('taxonomy_term', $field);
  if ($field_storage !== null) {
    $field_storage->delete();
  }
}




/**
 * Consulting: {"tid":[{"value":"900"}],"uuid":[{"value":"48c5fa10-0343-4efa-88b7-c029d220164a"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"consulting"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1536677210"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1535460864"}],"field_hub_blocs":[{"value":"topnavbarconsultingfr"},{"value":"toprightnavbarconsultfr"},{"value":"mainmenuconsultingfr"},{"value":"directaccessconsultingfr"},{"value":"mainfooterconsultingfr"},{"value":"contactbarblockhubcofr"}],"field_hub_machine_name_suffixe":[{"value":"consulting"}],"field_hub_menus":[{"value":"top-navbar-consulting-fr"},{"value":"top-right-navbar-consult-fr"},{"value":"main-menu-consulting-fr"},{"value":"direct-access-consulting-fr"},{"value":"main-footer-consulting-fr"}],"field_hub_subhomes":[{"target_id":"211"},{"target_id":"210"},{"target_id":"213"},{"target_id":"214"},{"target_id":"209"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"consulting"}]}
 * Dig Workspace : {"tid":[{"value":"1048"}],"uuid":[{"value":"39007ad5-e699-4ea6-acfd-2fdca7241d0c"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"Digital Workspace"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1575455069"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1575455069"}],"field_hub_blocs":[{"value":"topnavbardigitalworksfr"},{"value":"toprightnavbardigitalfr"},{"value":"mainmenudigitalworkspfr"},{"value":"directaccessdigitalwofr"},{"value":"mainfooterdigitalworkfr"},{"value":"contactbarblockhubdifr"}],"field_hub_machine_name_suffixe":[{"value":"digital-workspace"}],"field_hub_menus":[{"value":"top-navbar-digital-works-fr"},{"value":"top-right-navbar-digital-fr"},{"value":"main-menu-digital-worksp-fr"},{"value":"direct-access-digital-wo-fr"},{"value":"main-footer-digital-work-fr"}],"field_hub_subhomes":[{"target_id":"210"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"digitalworkspace"}]}
 */

/**
 $fields = [];
$term = Drupal\taxonomy\Entity\Term::load(900);
foreach($term->getFields() as $name => $field) {

$fields[$name] = $term->get($name)->getValue();
}

echo json_encode($fields);*/


