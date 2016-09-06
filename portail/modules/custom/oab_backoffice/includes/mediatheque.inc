<?php


function oab_backoffice_form_entity_embed_dialog_alter(&$form, \Drupal\Core\Form\FormState $form_state)
{
  /*
    $form['actions']['save_modal']['#ajax'] = array(
        'callback' => '::submitSelectStep',
        'event' => 'load',
    );*/

  //print_r(json_encode($form_state));
  //\Drupal::logger('oab_backoffice')->notice(serialize((array)$form_state));
}
