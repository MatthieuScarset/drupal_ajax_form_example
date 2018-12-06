<?php
use Symfony\Component\Yaml\Yaml;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;

/**
 *         RUBYPORTAILOBS-3441 [SUB-PRESS] modification des views en figeant les type de contenu
 */

oabt_YmlImport('views.view.subhome_archive.yml');
oabt_YmlImport('views.view.subhomes.yml');
