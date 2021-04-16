<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *     RUBYPORTAILOBS-3420 [Taxo] Classement des contenus industrie
 */

oabt_YmlImport('core.entity_form_display.node.industry.default.yml');
oabt_YmlImport('core.entity_form_display.node.solution.default.yml');
oabt_YmlImport('core.entity_view_display.node.industry.default.yml');
oabt_YmlImport('core.entity_view_display.node.solution.default.yml');
oabt_YmlImport('field.field.node.industry.field_insight.yml');
oabt_YmlImport('field.field.node.solution.field_insight.yml');
