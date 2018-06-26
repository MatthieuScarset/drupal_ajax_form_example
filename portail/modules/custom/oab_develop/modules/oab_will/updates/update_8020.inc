<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * RUBYPORTAILOBS-3349 correctif hub partagé sur le portail pour les contenu suhome en single checkbox
 */

oabt_YmlImport('core.entity_form_display.node.homepage.default.yml');
