<?php
/*Consulting: {"tid":[{"value":"900"}],"uuid":[{"value":"48c5fa10-0343-4efa-88b7-c029d220164a"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"consulting"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1536677210"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1535460864"}],"field_hub_blocs":[{"value":"topnavbarconsultingfr"},{"value":"toprightnavbarconsultfr"},{"value":"mainmenuconsultingfr"},{"value":"directaccessconsultingfr"},{"value":"mainfooterconsultingfr"},{"value":"contactbarblockhubcofr"}],"field_hub_machine_name_suffixe":[{"value":"consulting"}],"field_hub_menus":[{"value":"top-navbar-consulting-fr"},{"value":"top-right-navbar-consult-fr"},{"value":"main-menu-consulting-fr"},{"value":"direct-access-consulting-fr"},{"value":"main-footer-consulting-fr"}],"field_hub_subhomes":[{"target_id":"211"},{"target_id":"210"},{"target_id":"213"},{"target_id":"214"},{"target_id":"209"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"consulting"}]}
 * Dig Workspace : {"tid":[{"value":"1048"}],"uuid":[{"value":"39007ad5-e699-4ea6-acfd-2fdca7241d0c"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"Digital Workspace"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1575455069"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1575455069"}],"field_hub_blocs":[{"value":"topnavbardigitalworksfr"},{"value":"toprightnavbardigitalfr"},{"value":"mainmenudigitalworkspfr"},{"value":"directaccessdigitalwofr"},{"value":"mainfooterdigitalworkfr"},{"value":"contactbarblockhubdifr"}],"field_hub_machine_name_suffixe":[{"value":"digital-workspace"}],"field_hub_menus":[{"value":"top-navbar-digital-works-fr"},{"value":"top-right-navbar-digital-fr"},{"value":"main-menu-digital-worksp-fr"},{"value":"direct-access-digital-wo-fr"},{"value":"main-footer-digital-work-fr"}],"field_hub_subhomes":[{"target_id":"210"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"digitalworkspace"}]}
 */

use Drupal\taxonomy\Entity\Term;

/*
$connection = \Drupal\Core\Database\Database::getConnection();
$connection->schema()->dropTable('menu_link_content_field_revision');
$connection->schema()->dropTable('menu_link_content_revision');
$connection->schema()->dropTable('taxonomy_term_r__9e5738c328');

$connection->schema()->dropTable('taxonomy_term_revision__field_country_code');


$key_value = \Drupal::keyValue('post_update');
$update_list = $key_value->get('existing_updates');


$post_updates = [
  'menu_link_content_post_update_make_menu_link_content_revisionable',
  'system_post_update_add_expand_all_items_key_in_system_menu_block',
  'system_post_update_clear_menu_cache',
  'taxonomy_post_update_make_taxonomy_term_revisionable_patched'
];

foreach ($post_updates as $post_update) {
  $key = array_search($post_update, $update_list);
  if ($key !== false) {
    unset($update_list[$key]);
  }
}


$key_value->set('existing_updates', $update_list);
*/



$data = [
  900 => "{\"field_hub_blocs\":[{\"value\":\"topnavbarconsultingfr\"},{\"value\":\"toprightnavbarconsultfr\"},{\"value\":\"mainmenuconsultingfr\"},{\"value\":\"directaccessconsultingfr\"},{\"value\":\"mainfooterconsultingfr\"},{\"value\":\"contactbarblockhubcofr\"}],\"field_hub_machine_name_suffixe\":[{\"value\":\"consulting\"}],\"field_hub_menus\":[{\"value\":\"top-navbar-consulting-fr\"},{\"value\":\"top-right-navbar-consult-fr\"},{\"value\":\"main-menu-consulting-fr\"},{\"value\":\"direct-access-consulting-fr\"},{\"value\":\"main-footer-consulting-fr\"}],\"field_hub_subhomes\":[{\"target_id\":\"211\"},{\"target_id\":\"210\"},{\"target_id\":\"213\"},{\"target_id\":\"214\"},{\"target_id\":\"209\"},{\"target_id\":\"212\"},{\"target_id\":\"297\"}],\"field_hub_url\":[{\"value\":\"consulting\"}]}",
  1048 => "{\"field_hub_blocs\":[{\"value\":\"topnavbardigitalworksfr\"},{\"value\":\"toprightnavbardigitalfr\"},{\"value\":\"mainmenudigitalworkspfr\"},{\"value\":\"directaccessdigitalwofr\"},{\"value\":\"mainfooterdigitalworkfr\"},{\"value\":\"contactbarblockhubdifr\"}],\"field_hub_machine_name_suffixe\":[{\"value\":\"digital-workspace\"}],\"field_hub_menus\":[{\"value\":\"top-navbar-digital-works-fr\"},{\"value\":\"top-right-navbar-digital-fr\"},{\"value\":\"main-menu-digital-worksp-fr\"},{\"value\":\"direct-access-digital-wo-fr\"},{\"value\":\"main-footer-digital-work-fr\"}],\"field_hub_subhomes\":[{\"target_id\":\"210\"},{\"target_id\":\"212\"},{\"target_id\":\"297\"}],\"field_hub_url\":[{\"value\":\"digitalworkspace\"}]}"
];


foreach ($data as $tid => $row) {
  $fields = json_decode($row, true);
  if ($fields !== null && $fields !== false) {
    $term = Term::load($tid);
    if ($term !== null) {
      foreach ($fields as $name => $values) {
        $to_insert = [];
        foreach ($values as $value) {
          if (isset($value['value'])) {
            $to_insert[] = $value['value'];
          } elseif (isset($value['target_id'])) {
            $to_insert[] = Term::load($value['target_id']);
          }
        }

        if (count($to_insert)) {
          $term->set($name, $to_insert);
        }
      }
      $term->save();
      drupal_set_message("Hub " . $term->label() . " refill", 'notice');
    }
  }
}
