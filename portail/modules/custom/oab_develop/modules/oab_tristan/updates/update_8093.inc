<?php
/*Consulting: {"tid":[{"value":"900"}],"uuid":[{"value":"48c5fa10-0343-4efa-88b7-c029d220164a"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"consulting"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1536677210"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1535460864"}],"field_hub_blocs":[{"value":"topnavbarconsultingfr"},{"value":"toprightnavbarconsultfr"},{"value":"mainmenuconsultingfr"},{"value":"directaccessconsultingfr"},{"value":"mainfooterconsultingfr"},{"value":"contactbarblockhubcofr"}],"field_hub_machine_name_suffixe":[{"value":"consulting"}],"field_hub_menus":[{"value":"top-navbar-consulting-fr"},{"value":"top-right-navbar-consult-fr"},{"value":"main-menu-consulting-fr"},{"value":"direct-access-consulting-fr"},{"value":"main-footer-consulting-fr"}],"field_hub_subhomes":[{"target_id":"211"},{"target_id":"210"},{"target_id":"213"},{"target_id":"214"},{"target_id":"209"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"consulting"}]}
 * Dig Workspace : {"tid":[{"value":"1048"}],"uuid":[{"value":"39007ad5-e699-4ea6-acfd-2fdca7241d0c"}],"revision_id":[],"langcode":[{"value":"fr"}],"vid":[{"target_id":"hub"}],"revision_created":[],"revision_user":[],"revision_log_message":[],"status":[{"value":"1"}],"name":[{"value":"Digital Workspace"}],"description":[{"value":null,"format":null}],"weight":[{"value":"0"}],"parent":[{"target_id":"0"}],"changed":[{"value":"1575455069"}],"default_langcode":[{"value":"1"}],"revision_default":[],"revision_translation_affected":[],"metatag":[],"path":[{"langcode":"fr"}],"moderation_state":[],"content_translation_source":[{"value":"und"}],"content_translation_outdated":[{"value":"0"}],"content_translation_uid":[{"target_id":"567"}],"content_translation_created":[{"value":"1575455069"}],"field_hub_blocs":[{"value":"topnavbardigitalworksfr"},{"value":"toprightnavbardigitalfr"},{"value":"mainmenudigitalworkspfr"},{"value":"directaccessdigitalwofr"},{"value":"mainfooterdigitalworkfr"},{"value":"contactbarblockhubdifr"}],"field_hub_machine_name_suffixe":[{"value":"digital-workspace"}],"field_hub_menus":[{"value":"top-navbar-digital-works-fr"},{"value":"top-right-navbar-digital-fr"},{"value":"main-menu-digital-worksp-fr"},{"value":"direct-access-digital-wo-fr"},{"value":"main-footer-digital-work-fr"}],"field_hub_subhomes":[{"target_id":"210"},{"target_id":"212"},{"target_id":"297"}],"field_hub_url":[{"value":"digitalworkspace"}]}
 */

use Drupal\taxonomy\Entity\Term;

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
