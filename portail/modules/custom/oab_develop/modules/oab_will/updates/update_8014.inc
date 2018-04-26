<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 * RUBYPORTAILOBS-3310 [OC] champ HUB tac lite
 * role hub editor
 * setting tac lite
 */

oabt_YmlImport('user.role.hub_editor.yml');
oabt_YmlImport('tac_lite.settings.yml');