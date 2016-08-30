<?php


function oab_backoffice_form_entity_embed_dialog_alter(&$form, \Drupal\Core\Form\FormState $form_state)
{
  \Drupal::logger('oab_backoffice')->notice('****************************************************************************************** ALTER oab_backoffice_form_entity_embed_dialog_alter');
  $connection = \Drupal\Core\Database\Database::getConnection();
  $query_create = $connection->insert('tmp_sjo_message')
    ->fields(array(
      'date' => date("Y-m-d H:i:s"),
      'module' => 'oab_backoffice_form_entity_embed_dialog_alter',
      'message' => serialize((array)$form)))->execute();
  /*
    $form['actions']['save_modal']['#ajax'] = array(
        'callback' => '::submitSelectStep',
        'event' => 'load',
    );*/

  //print_r(json_encode($form_state));
  //\Drupal::logger('oab_backoffice')->notice(serialize((array)$form_state));
}
