<?php

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

$vocab = \Drupal\taxonomy\Entity\Vocabulary::load("hub");
if ($vocab) {
  $vocab->delete();
}
