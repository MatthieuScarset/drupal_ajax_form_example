<?php


/*
 * changement sur la valeur par defaut dde la date de publication
 */

/*
 * RUBYPORTAILOBS-2739 insertion du champs contributeur externe au users
 */

oabt_YmlImport('core.entity_form_display.user.user.default.yml');
oabt_YmlImport('core.entity_view_display.user.user.default.yml');
oabt_YmlImport('field.field.user.user.field_contributeurs_externes.yml');
oabt_YmlImport('field.storage.user.field_contributeurs_externes.yml');

use Drupal\Core\Database\Database;

$query = "CREATE TABLE IF NOT EXISTS `user__field_contributeurs_externes` (
`bundle` varchar(128) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) UNSIGNED NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) UNSIGNED NOT NULL COMMENT 'The entity revision id this data is attached to, which for an unversioned entity type is the same as the entity id',
  `langcode` varchar(32) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The language code for this data item.',
  `delta` int(10) UNSIGNED NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_contributeurs_externes_value` varchar(20) NOT NULL COMMENT 'The date value.'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='Data storage for user field field_contributeurs_externes.';";

$schema = Database::getConnection()->query($query);