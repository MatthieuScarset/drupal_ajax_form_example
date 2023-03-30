<?php

namespace Drupal\oab_frontoffice\Form;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Component\Utility\UrlHelper;

/**
 * Newsletter form.
 */
class NewsletterForm extends FormBase {
  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'newsletter_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $form['custom_text'] = array(
      "#prefix" => "<p>",
      "#suffix" => "</p>",
      '#markup' => t("Le rendez-vous bimensuel des acteurs des Technologies de l'Information et de " .
        "la Communication : actualités, analyse, tendances, décryptage, interviews d'experts, trucs et astuces, dossiers pratiques..."),
    );

    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Email'),
      '#required' => FALSE,
    );

    $form['firstname'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Firstname'),
      '#required' => FALSE,
    );

    $form['lastname'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Lastname'),
      '#required' => FALSE,
    );

    $form['company'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Comapny'),
      '#required' => FALSE,
    );

    $form['function'] = array(
      '#type' => 'textfield',
      '#title' => t('Your Function'),
      '#required' => FALSE,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
  }
}
