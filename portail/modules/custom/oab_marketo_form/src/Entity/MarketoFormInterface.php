<?php

namespace Drupal\oab_marketo_form\Entity;


use Drupal\Core\Entity\ContentEntityInterface;

interface MarketoFormInterface extends ContentEntityInterface {
  public function getFormName();
  public function getFormId();
  public function langcode($as_object = false);
}
