<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 *
 * @author WLCQ9089
 * @Block(
 *   id = "newsletter_block",
 *   admin_label = @Translation("Newsletter Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class NewsletterBlock extends BlockBase {

  public function build() {

    $form = \Drupal::formBuilder()->getForm('Drupal\oab_frontoffice\Form\NewsletterForm');

    return array(
      '#markup' => render($form),
      '#attached' => array(
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
  }
}
