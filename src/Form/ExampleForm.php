<?php

namespace Drupal\mymodule\Form;

use Drupal\Component\Utility\Html;
use Drupal\Core\Ajax\AjaxResponse;
use Drupal\Core\Ajax\CloseDialogCommand;
use Drupal\Core\Ajax\MessageCommand;
use Drupal\Core\Ajax\ReplaceCommand;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * This is a demo form.
 */
class ExampleForm extends FormBase {

  public function getFormId() {
    return 'mymodule';
  }

  public function buildForm(array $form, FormStateInterface $form_state) {
    $wrapper_id = Html::getUniqueId('this is an example form');
    $form['#prefix'] = '<div id="' . $wrapper_id . '">';
    $form['#suffix'] = '</div>';

    $form['mail'] = [
      '#type' => 'email',
      '#title' => $this->t('Your mail number'),
      '#description' => $this->t('This field is required but can be empty. You can submit the form. Try it. You should see a validation error'),
    ];

    $form['random'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Random value'),
      '#value' => rand(666, 777),
      '#description' => $this->t('This field is random and refreshed at each form validate'),
    ];

    $form['save'] = [
      '#type' => 'submit',
      '#value' => $this->t('Save'),
      '#ajax' => [
        'wrapper' => $wrapper_id,
        'callback' => '::ajaxSubmit',
      ],
    ];

    return $form;
  }

  public function validateForm(array &$form, FormStateInterface $form_state) {
    // Step 0
    // Le formulaire est valide.

    $mail = $form_state->getValue('mail');
    if (empty($mail)) {
      $form_state->setErrorByName('mail', $this->t('Oups, your email is required.'));
    }
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Step 1
    // On fait de qu'on veut avec les donnees soumises.

    // Exemple: envoyer un email.
    $email = $form_state->getValue('mail');
    // ... do your business logic.
  }

  
  public function ajaxSubmit(array &$form, FormStateInterface $form_state) {
    // Pour rafraichir le formulaire, on peut s'arreter la et juste renvoyer le form:
    // return $form;

    // Exemple: afficher un message d'erreur.
    if ($form_state->hasAnyErrors()) {
      $form['status_messages'] = [
        '#type' => 'status_messages',
        '#weight' => -1000,
      ];
      $form['#sorted'] = FALSE;
      return $form;
    }

    // Sinon, on fait ce qu'on veut avec des Commands ajax.
    // Exemple:  Fermer la modal si tout va bien.
    $response = new AjaxResponse();
    $command = new CloseDialogCommand();
    $response->addCommand($command);

    return $response;
  }
}
