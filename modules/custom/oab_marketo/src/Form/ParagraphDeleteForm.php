<?php

namespace Drupal\oab_marketo\Form;

use Drupal\Core\Entity\ContentEntityDeleteForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

/**
 * Override paragraph delete form just to override getCancelUrl to avoid returning the canonical url of the paragraph which doesn't exist
 * Add the form to the entity in the "oab_marketo_entity_type_build" hook
 */
class ParagraphDeleteForm extends ContentEntityDeleteForm {

  public function getCancelUrl() {
    if (\Drupal::request()->headers->has('referer')) {
      $referer = \Drupal::request()->headers->get('referer');
      $base_url = \Drupal::request()->getSchemeAndHttpHost();
      return Url::fromUserInput(substr($referer, strlen($base_url)));
    } else {

      return Url::fromRoute('view.marketo_paragraph_entity_browser.page_list');
    }
  }

}
