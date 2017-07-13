<?php
use \Drupal\Core\Utility\UpdateException;
use Drupal\Core\Database\Database;


/*$field = \Drupal::entityManager()->getStorage('field_config')->load('taxonomy_term.subhome.field_content_type');
$field->delete();
field_purge_field($field);
*/
/***********************
 * Desactivation du module easy-breadcrumb afin de gérer
 * les fils d'ariane par un module perso
 ***********************/
$config_factory = \Drupal::configFactory();

##Je recupère la config des modules
$config_group = $config_factory->getEditable('core.extension');

##Je recupère la liste des modules actifs dans la config
$modules = $config_group->get('module');

##Si je trouve le module easy_breadcrumbre
if (isset($modules['easy_breadcrumb'])) {

  ##Je supprime le module de la config
  unset($modules['easy_breadcrumb']);

  ##je resset le tableau des modules
  $config_group->set('module', $modules);

  ##Je save la config
  $config_group->save(TRUE);

  ##Je recupère la config du module et je la supprime
  $config_easybreadcrumb = $config_factory->getEditable('easy_breadcrumb.settings');
  $config_easybreadcrumb->delete();

}


#################
## Ajout de la config pour les taxonomies
$config_group = $config_factory->getEditable('field.field.taxonomy_term.subhomes.field_content_type');
$config_group->setData(
  array (
    'uuid' => '9799a3bc-107b-4965-80d2-c4df94c13edc',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.storage.taxonomy_term.field_field_content_type',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.field_field_content_type',
    'field_name' => 'field_field_content_type',
    'entity_type' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'label' => 'field_content_type',
    'description' => '',
    'required' => true,
    'translatable' => false,
    'default_value' =>
      array (
      ),
    'default_value_callback' => '',
    'settings' =>
      array (
      ),
    'field_type' => 'string',
  )
);

$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.storage.taxonomy_term.field_content_type');
$config_group->setData(
  array (
    'uuid' => 'b5299c17-d7c2-43b9-ac5a-d83cc6c5f345',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'taxonomy',
          ),
      ),
    'id' => 'taxonomy_term.field_field_content_type',
    'field_name' => 'field_field_content_type',
    'entity_type' => 'taxonomy_term',
    'type' => 'string',
    'settings' =>
      array (
        'max_length' => 50,
        'is_ascii' => false,
        'case_sensitive' => false,
      ),
    'module' => 'core',
    'locked' => false,
    'cardinality' => 1,
    'translatable' => true,
    'indexes' =>
      array (
      ),
    'persist_with_no_fields' => false,
    'custom_storage' => false,
  )

);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_form_display.taxonomy_term.subhomes.default');
$config_group->setData(
  array (
    'uuid' => 'dc3414b1-293e-4271-82c9-3a1cab2e793d',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.subhomes.field_field_content_type',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
        'module' =>
          array (
            0 => 'path',
            1 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
          array (
            'type' => 'text_textfield',
            'weight' => 0,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_field_content_type' =>
          array (
            'weight' => 31,
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'string_textfield',
            'region' => 'content',
          ),
        'langcode' =>
          array (
            'type' => 'language_select',
            'weight' => 2,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'name' =>
          array (
            'type' => 'string_textfield',
            'weight' => -5,
            'region' => 'content',
            'settings' =>
              array (
                'size' => 60,
                'placeholder' => '',
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'path' =>
          array (
            'type' => 'path',
            'weight' => 30,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
      ),
    'hidden' =>
      array (
      ),
  )
);
$config_group->save(TRUE);


$config_group = $config_factory->getEditable('core.entity_view_display.taxonomy_term.subhomes.default');
$config_group->setData(
  array (
    'uuid' => '89f78ff7-f890-42c0-bd2f-f42725d6c1bc',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'config' =>
          array (
            0 => 'field.field.taxonomy_term.subhomes.field_field_content_type',
            1 => 'taxonomy.vocabulary.subhomes',
          ),
        'module' =>
          array (
            0 => 'text',
          ),
      ),
    'id' => 'taxonomy_term.subhomes.default',
    'targetEntityType' => 'taxonomy_term',
    'bundle' => 'subhomes',
    'mode' => 'default',
    'content' =>
      array (
        'description' =>
          array (
            'label' => 'hidden',
            'type' => 'text_default',
            'weight' => 0,
            'region' => 'content',
            'settings' =>
              array (
              ),
            'third_party_settings' =>
              array (
              ),
          ),
        'field_field_content_type' =>
          array (
            'weight' => 1,
            'label' => 'above',
            'settings' =>
              array (
                'link_to_entity' => false,
              ),
            'third_party_settings' =>
              array (
              ),
            'type' => 'string',
            'region' => 'content',
          ),
      ),
    'hidden' =>
      array (
        'langcode' => true,
      ),
  )

);
$config_group->save(TRUE);

$schema = Database::getConnection()->query(
  "
CREATE TABLE `taxonomy_term__field_field_content_type` (
`bundle` varchar(128) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The field instance bundle to which this row belongs, used when deleting a field instance',
  `deleted` tinyint(4) NOT NULL DEFAULT '0' COMMENT 'A boolean indicating whether this data item has been deleted',
  `entity_id` int(10) UNSIGNED NOT NULL COMMENT 'The entity id this data is attached to',
  `revision_id` int(10) UNSIGNED NOT NULL COMMENT 'The entity revision id this data is attached to, which for an unversioned entity type is the same as the entity id',
  `langcode` varchar(32) CHARACTER SET ascii NOT NULL DEFAULT '' COMMENT 'The language code for this data item.',
  `delta` int(10) UNSIGNED NOT NULL COMMENT 'The sequence number for this data item, used for multi-value fields',
  `field_field_content_type_value` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='Data storage for taxonomy_term field field_field_content…'");

$schema = Database::getConnection()->query("
INSERT INTO `taxonomy_term__field_field_content_type` (`bundle`, `deleted`, `entity_id`, `revision_id`, `langcode`, `delta`, `field_field_content_type_value`) VALUES
('subhomes', 0, 364, 364, 'fr', 0, 'partner'),
('subhomes', 0, 365, 365, 'fr', 0, 'customer_story'),
('subhomes', 0, 366, 366, 'fr', 0, 'press_release'),
('subhomes', 0, 367, 367, 'fr', 0, 'document'),
('subhomes', 0, 368, 368, 'fr', 0, 'product'),
('subhomes', 0, 369, 369, 'fr', 0, 'magazine'),
('subhomes', 0, 370, 370, 'en', 0, 'partner'),
('subhomes', 0, 371, 371, 'en', 0, 'customer_story'),
('subhomes', 0, 372, 372, 'en', 0, 'press_release'),
('subhomes', 0, 373, 373, 'en', 0, 'document'),
('subhomes', 0, 374, 374, 'en', 0, 'product'),
('subhomes', 0, 375, 375, 'en', 0, 'magazine')");


$schema = Database::getConnection()->query("
ALTER TABLE `taxonomy_term__field_field_content_type`
  ADD PRIMARY KEY (`entity_id`,`deleted`,`delta`,`langcode`),
  ADD KEY `bundle` (`bundle`),
  ADD KEY `revision_id` (`revision_id`)
");

#A enlever à la fin des tests
throw new UpdateException();