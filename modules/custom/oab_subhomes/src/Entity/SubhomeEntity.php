<?php

namespace Drupal\oab_subhomes\Entity;
use Drupal\Core\Database\Database;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityChangedTrait;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\user\UserInterface;
use Drupal\taxonomy\Entity\Term;

/**
 * Defines the Subhome entity entity.
 *
 * @ingroup oab_subhomes
 *
 * @ContentEntityType(
 *   id = "subhome_entity",
 *   label = @Translation("Subhome entity"),
 *   bundle_label = @Translation("Subhome entity type"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_subhomes\SubhomeEntityListBuilder",
 *     "views_data" = "Drupal\oab_subhomes\Entity\SubhomeEntityViewsData",
 *
 *     "form" = {
 *       "default" = "Drupal\oab_subhomes\Form\SubhomeEntityForm",
 *       "add" = "Drupal\oab_subhomes\Form\SubhomeEntityForm",
 *       "edit" = "Drupal\oab_subhomes\Form\SubhomeEntityForm",
 *       "delete" = "Drupal\oab_subhomes\Form\SubhomeEntityDeleteForm",
 *     },
 *     "access" = "Drupal\oab_subhomes\SubhomeEntityAccessControlHandler",
 *     "route_provider" = {
 *       "html" = "Drupal\oab_subhomes\SubhomeEntityHtmlRouteProvider",
 *     },
 *   },
 *   base_table = "subhome_entity",
 *   translatable = false,
 *   admin_permission = "administer subhome entity entities",
 *   entity_keys = {
 *     "id" = "id",
 *     "bundle" = "type",
 *     "label" = "name",
 *     "uuid" = "uuid",
 *     "langcode" = "langcode"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/subhome_entity/{subhome_entity}",
 *     "add-page" = "/admin/structure/subhome_entity/add",
 *     "add-form" = "/admin/structure/subhome_entity/add/{subhome_entity_type}",
 *     "edit-form" = "/admin/structure/subhome_entity/{subhome_entity}/edit",
 *     "delete-form" = "/admin/structure/subhome_entity/{subhome_entity}/delete",
 *     "collection" = "/admin/structure/subhome_entity",
 *   },
 *   bundle_entity_type = "subhome_entity_type",
 *   field_ui_base_route = "entity.subhome_entity_type.edit_form"
 * )
 */
class SubhomeEntity extends ContentEntityBase implements SubhomeEntityInterface {

    use EntityChangedTrait;

    const TWIG_VAR_NAME = 'subhome_entity';

    /**
    * {@inheritdoc}
    */
    public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
        parent::preCreate($storage_controller, $values);
    }

    /**
    * {@inheritdoc}
    */
    public function getName() {
        return $this->get('name')->value;
    }

    /**
    * {@inheritdoc}
    */
    public function setName($name) {
        $this->set('name', $name);
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getTitle() {
        return $this->get('title')->value;
    }

    /**
     * {@inheritdoc}
     */
    public function setTitle($title) {
        $this->set('title', $title);
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public function getDescription() {
        return $this->get('description')->value;
    }

    /**
     * {@inheritdoc}
     */
    public function setDescription($description) {
        $this->set('description', $description);
        return $this;
    }

    /**
    * {@inheritdoc}
    */
    public function getCreatedTime() {
        return $this->get('created')->value;
    }

    /**
    * {@inheritdoc}
    */
    public function setCreatedTime($timestamp) {
        $this->set('created', $timestamp);
        return $this;
    }

    /**
    * {@inheritdoc}
    */
    public function getSubhome() {
        return $this->get('subhome_id')->entity;
    }

    /**
    * {@inheritdoc}
    */
    public function getSubhomeId() {
        return $this->get('subhome_id')->target_id;
    }

    /**
    * {@inheritdoc}
    */
    public function setSubhomeId($tid) {
        $this->set('subhome_id', $tid);
        return $this;
    }

    /**
     * {@inheritdoc}
     */
    public static function loadBySubhomeId($sid) {
        $connection = Database::getConnection();

        $sth = $connection->select('subhome_entity', 's')
            ->fields('s', array('id'))
            ->condition('s.subhome_id', $sid);
        $data = $sth->execute();
        $results = $data->fetchAll(\PDO::FETCH_OBJ);

        $ret = null;

        // Je ne charge que le 1er, de toute facon, il n'y a normalement qu'une seule subhome avec ce tid dans le tableau
        if (isset($results[0])) {
            $ret = self::load($results[0]->id);
        }

        return $ret;
    }

    /**
     * Check if the selected subhome is already selected by another Subhome Entity
     * @param $sid int the id of the subhome to check
     * @return bool
     */
    public static function isUnique($sid) {
        $connection = Database::getConnection();
        $sth = $connection->select('subhome_entity', 's')
            ->fields('s', array('id'))
            ->condition('s.subhome_id', $sid, '=');
        $data = $sth->execute();
        $results = $data->fetchAll(\PDO::FETCH_OBJ);

        return (count($results) < 1) ? TRUE : FALSE;
    }

    /**
   * {@inheritdoc}
   */
    public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
        $fields = parent::baseFieldDefinitions($entity_type);


       /* $fields['langcode'] = BaseFieldDefinition::create('language')
            ->setLabel(t('Language'))
            ->setDescription(t('The subhome entity language'))
            ->setDisplayOptions('view', array(
                'type' => 'hidden',
            ))
            ->setDisplayOptions('form', [
                'type' => 'language_select',
                'weight' => 2,
            ])
            ->setDisplayConfigurable('form', TRUE)
        ->setDisplayConfigurable('view', TRUE);*/

        $fields['name'] = BaseFieldDefinition::create('string')
            ->setLabel(t('Name'))
            ->setDescription(t('The name of the Subhome entity entity. Not displayed, for backoffice only'))
            ->setSettings([
                'max_length' => 50,
                'text_processing' => 0,
            ])
            ->setDefaultValue('')
            ->setDisplayOptions('form', [
                'type' => 'string_textfield',
                'weight' => -6,
            ])
            ->setDisplayConfigurable('view', FALSE)
            ->setDisplayConfigurable('form', TRUE)
            ->setRequired(TRUE);

        $fields['title'] = BaseFieldDefinition::create('string')
            ->setLabel(t('Title'))
            ->setDescription(t('Title of the subhome, displayed in front.'))
            ->setSettings([
              'max_length' => 50,
              'text_processing' => 0,
            ])
            ->setDefaultValue('')
            ->setDisplayOptions('form', [
              'type' => 'string_textfield',
              'weight' => -5,
            ])
            ->setDisplayConfigurable('view', TRUE)
            ->setDisplayConfigurable('form', TRUE)
            ->setRequired(TRUE);

        $fields['subhome_id'] = BaseFieldDefinition::create('entity_reference')
            ->setLabel(t('Subhome'))
            ->setDescription(t('The subhome the entity is designed for'))
            ->setRevisionable(TRUE)
            ->addConstraint('UniqueField')
            ->setSetting('target_type', 'taxonomy_term')
            ->setSetting('handler', 'default')
            ->setSetting('handler_settings',
                array(
                    'target_bundles' => array(
                        'subhomes' => 'subhomes'
                    )))
            ->setTranslatable(FALSE)
            ->setDisplayOptions('form', [
                'type' => 'options_select',
                'weight' => -4
            ])
            ->setDisplayConfigurable('view', FALSE)
            ->setDisplayConfigurable('form', TRUE)
            ->setRequired(TRUE);

        $fields['description'] = BaseFieldDefinition::create('string_long')
            ->setLabel(t('Description'))
            ->setDescription(t('Description of the subhome, displayed in front.'))
            ->setSettings([
                'text_processing' => 0,
            ])
            ->setDefaultValue('')
            ->setDisplayOptions('form', [
                'type' => 'string_textarea',
                'weight' => -3,
            ])
            ->setDisplayConfigurable('form', TRUE)
            ->setDisplayConfigurable('view', TRUE)
            ->setRequired(TRUE);

        $fields['created'] = BaseFieldDefinition::create('created')
            ->setLabel(t('Created'))
            ->setDescription(t('The time that the entity was created.'));

        $fields['changed'] = BaseFieldDefinition::create('changed')
            ->setLabel(t('Changed'))
            ->setDescription(t('The time that the entity was last edited.'));

        return $fields;
  }

}
