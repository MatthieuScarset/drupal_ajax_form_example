<?php
/**
 * Migrate post row save event subscriber and handler.
 */

namespace Drupal\oab_migrate_content\EventSubscriber;

// This is the interface we are going to implement.
use Drupal\Core\Database\Database;
use Drupal\Core\Session\UserSession;
use \Symfony\Component\EventDispatcher\EventSubscriberInterface;
use \Drupal\migrate\Event\MigrateEvents;
use \Drupal\migrate\Event\MigrateRollbackEvent;
use \Drupal\migrate\Event\MigrateRowDeleteEvent;
use \Drupal\migrate\Event\MigratePostRowSaveEvent;
use Drupal\migrate\Event\MigrateImportEvent;

/**
 * Subscribe to MigrateEvents::POST_ROW_SAVE events.
 */
class OabMigrateContentEvents implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents() {
        $events[MigrateEvents::PRE_IMPORT][] = array('swtchUserToAdmin');
        $events[MigrateEvents::PRE_IMPORT][] = array('fillTaxonomyTIDCorrespondence');
        $events[MigrateEvents::PRE_IMPORT][] = array('fillSubhomeIdInState');
        $events[MigrateEvents::PRE_IMPORT][] = array('fillPressFormatIdInState');
        $events[MigrateEvents::PRE_IMPORT][] = array('getAllOfficeCountries');
    $events[MigrateEvents::POST_ROW_SAVE][] = array('updateTranslations');
    $events[MigrateEvents::POST_ROW_DELETE][] = array('deleteUrlAlias');
        $events[MigrateEvents::POST_IMPORT][] = array('swtchUserToAnonymous');

    return $events;
  }

    public function swtchUserToAdmin(MigrateImportEvent $migrate_row) {
        // On change le current user car l'utilisateur anonyme (0) pose des problèmes avec le workflow
        $accountSwitcher = \Drupal::service('account_switcher');
        // switch to the admin user
        $accountSwitcher->switchTo(new UserSession(['uid' => 1]));
    }

    public function swtchUserToAnonymous(MigrateImportEvent $migrate_row) {
        // On change le current user car l'utilisateur anonyme (0) pose des problèmes avec le workflow
        $accountSwitcher = \Drupal::service('account_switcher');
        // switch to the admin user
        $accountSwitcher->switchTo(new UserSession(['uid' => 0]));
    }

  /**
   * MigrateEvents::POST_ROW_SAVE event handler.
   *
   * @param MigratePostRowSaveEvent $migrate_row
   *   Instance of Drupal\migrate\Event\MigratePostRowSaveEvent.
   */
  public function updateTranslations(MigratePostRowSaveEvent $migrate_row) {
    $row = $migrate_row->getRow();
    $destinationIdValues = $migrate_row->getDestinationIdValues();
    $nid = $destinationIdValues[0];

    $migrate_src_values = $row->getSource();
    $migrate_dest_values = $row->getDestination();

    if (isset($migrate_src_values['plugin'])
    && $migrate_src_values['plugin'] == 'blogpost_profile') {
      $entity = \Drupal\node\Entity\Node::load($nid);

      $body = $migrate_src_values['field_txt_biography_fr'];
      if (empty($body)) {
          $body = $migrate_src_values['field_txt_catcher'];
            }
      $values = array(
        // Non multilingual.
        'created' => $migrate_src_values['created'],
        'changed' => $migrate_src_values['created'],
        'uid' => 1,
        'sticky' => 0,
        'status' => 1,

        // Multilingual.
        'title' => $migrate_src_values['title'],
        'body' => array('value' => $body, 'format' => 'full_html'),
        'field_image' => $migrate_dest_values['field_image'],
      );

      if ($entity->hasTranslation('fr')) {
        $entity->removeTranslation('fr');
      }

      $translated_entity = $entity->addTranslation('fr', $values);
      $translated_entity->save();

      $map = $migrate_row->getMigration()->getIdMap();

      $map->saveIdMapping($migrate_row->getRow(), array($nid));
    }

  }

  /** Suppression des Url alias
   * @param MigrateRowDeleteEvent $migrate_row
   */
  public function deleteUrlAlias(MigrateRowDeleteEvent $migrate_row) {
    $migration = $migrate_row->getMigration();
    $destinationIdValues = $migrate_row->getDestinationIdValues();
    if (isset($destinationIdValues['nid']))
    {
      $nid = $destinationIdValues['nid'];
      //\Drupal::logger('oab_migrate_content')->notice('deleteUrlAlias - id:' . $nid);
      $query_aliases = Database::getConnection('default')->delete('url_alias')
            ->condition('source', '/node/'.$nid.'%', 'LIKE')
        ->execute();
    }
  }

    /** Permet de remplir les TID des taxonomyes dans les tableaux de correspondance D7-D8
     * @param \Drupal\migrate\Event\MigrateImportEvent $migrate_row
     */
    public function fillTaxonomyTIDCorrespondence(MigrateImportEvent $migrate_row) {
        ///SOLUTIONS
        $correspondance_taxo_solution = $this->genericFillCorrespondance('correspondence_taxo_solution' , 'solutions');
        \Drupal::state()->set('correspondence_taxo_solution', $correspondance_taxo_solution);

        ///INDUSTRIES
        $correspondence_taxo_industry = $this->genericFillCorrespondance('correspondence_taxo_industry' , 'industries');
        \Drupal::state()->set('correspondence_taxo_industry', $correspondence_taxo_industry);

        //REGIONS
        $correspondence_taxo_region = $this->genericFillCorrespondance('correspondence_taxo_region' , 'regions');
        \Drupal::state()->set('correspondence_taxo_region', $correspondence_taxo_region);

        //SOLUTION -> THEMATIC
        $correspondence_taxo_solution_to_thematic = $this->genericFillCorrespondance('correspondence_taxo_solution_to_thematic' , 'thematic');
        \Drupal::state()->set('correspondence_taxo_solution_to_thematic', $correspondence_taxo_solution_to_thematic);

        //CAT BLOG -> THEMATIC BLOG
        $correspondence_cat_blog_to_thematic_blog= $this->genericFillCorrespondance('correspondence_cat_blog_to_thematic_blog' , 'blog_thematics');
        \Drupal::state()->set('correspondence_cat_blog_to_thematic_blog', $correspondence_cat_blog_to_thematic_blog);

        //CAT BLOG -> FORMAT/TYPE BLOG
        $correspondence_cat_blog_to_type_blog = $this->genericFillCorrespondance('correspondence_cat_blog_to_type_blog' , 'blog_formats');
        \Drupal::state()->set('correspondence_cat_blog_to_type_blog', $correspondence_cat_blog_to_type_blog);


        //MAG CATEG TO MAG FORMAT
        $correspondence_cat_mag_to_format_mag = $this->genericFillCorrespondance('correspondence_cat_mag_to_format_mag' , 'magazine_types');
        \Drupal::state()->set('correspondence_cat_mag_to_format_mag', $correspondence_cat_mag_to_format_mag);

        //Solution to mag theme
        $correspondence_solution_to_theme_mag = $this->genericFillCorrespondance('correspondence_solution_to_theme_mag' , 'magazine_thematics');
        \Drupal::state()->set('correspondence_solution_to_theme_mag', $correspondence_solution_to_theme_mag);

        //solution to doc theme
        $correspondence_solution_to_theme_doc = $this->genericFillCorrespondance('correspondence_solution_to_theme_doc' , 'document_thematics');
        \Drupal::state()->set('correspondence_solution_to_theme_doc', $correspondence_solution_to_theme_doc);

        //format doc to doc format
        $correspondence_format_document = $this->genericFillCorrespondance('correspondence_format_document' , 'document_types');
        \Drupal::state()->set('correspondence_format_document', $correspondence_format_document);

    }



    /** Permet de remplir les TID des taxonomyes dans les tableaux de correspondance D7-D8
     * @param \Drupal\migrate\Event\MigrateImportEvent $migrate_row
     */
    public function fillSubhomeIdInState(MigrateImportEvent $migrate_row) {

        $subhomes = \Drupal::state()->get('subhomes_ids_for_migration');
        foreach ($subhomes as $code_subhome => $tableau_langues) {
            foreach ($tableau_langues as $langCode => $element) {
                if ($element['label'] != "") {
                    $query = \Drupal::entityQuery('taxonomy_term');
                    $query->condition('vid', 'subhomes');
                    $query->condition('langcode', $langCode);
                    $query->condition('name', $element['label']);
                    $entity = $query->execute();

                    if (isset($entity) && !empty($entity) && count($entity) > 0) {
                        $subhomes[$code_subhome][$langCode]['tid_D8'] = array_pop(array_values($entity));
                    }
                }
            }
        }
        \Drupal::state()->set('subhomes_ids_for_migration', $subhomes);
    }

    public function fillPressFormatIdInState(MigrateImportEvent $migrate_row) {

        $formats = \Drupal::state()->get('press_format_for_migration');
        foreach ($formats as $code_format => $tableau_langues) {
            foreach ($tableau_langues as $langCode => $element) {
                if ($element['label'] != "") {
                    $query = \Drupal::entityQuery('taxonomy_term');
                    $query->condition('vid', 'press_formats');
                    $query->condition('langcode', $langCode);
                    $query->condition('name', $element['label']);
                    $entity = $query->execute();

                    if (isset($entity) && !empty($entity) && count($entity) > 0) {
                        $formats[$code_format][$langCode]['tid_D8'] = array_pop(array_values($entity));
                    }
                }
            }
        }
        \Drupal::state()->set('press_format_for_migration', $formats);
    }


    private function genericFillCorrespondance($state_key, $vidD8) {
        $correspondance_state = \Drupal::state()->get($state_key);
        foreach ($correspondance_state as $key => $correspondance) {
            if ($correspondance['label_d8'] != "") {
                //vérification de l'existance du terme pour ce vocabulaire
                $query = \Drupal::entityQuery('taxonomy_term');
                $query->condition('vid', $vidD8);
                $query->condition('langcode', $correspondance['langcode']);
                $query->condition('name', $correspondance['label_d8']);
                $entity = $query->execute();

                if (isset($entity) && !empty($entity) && count($entity) > 0) {
                    $correspondance_state[$key]['tid_D8'] = array_pop(array_values($entity));
                }
                else {
                    // on n'a pas de terme D8 correspondant
                    \Drupal::logger('oab_migrate_content')
                        ->notice('Attention : pas de terme D8 correspondant à "' . $correspondance['label_d8'] . '" (' . $correspondance['langcode'] . ') ---- pour la taxonomie '.$vidD8.' - terme D7 = "' . $correspondance['label_d7'] . '" - TID D7 :' . $correspondance['tid_d7']);
                }
            }
            else {
                // on n'a pas de correspondance pour cette Taxonomie
                \Drupal::logger('oab_migrate_content')
                    ->notice('Attention : pas de correspondance D8 pour la taxonomie '.$vidD8.' - term = "' . $correspondance['label_d7'] . '" - TID D7 :' . $correspondance['tid_d7']);
            }
        }
        return $correspondance_state;
    }


    /** Recupération de tous les pays des offices
     * @param \Drupal\migrate\Event\MigrateImportEvent $migrate_row
     */
    public function getAllOfficeCountries(MigrateImportEvent $migrate_row) {
        $migration = $migrate_row->getMigration();
        //seulement pour les migrations d'offices
        if ($migration->getPluginId() == "office_node") {

            //on remet la connexion D7
            \Drupal\Core\Database\Database::setActiveConnection('drupal7');
            $dbD7 = \Drupal\Core\Database\Database::getConnection();

            $query = $dbD7->select('location_country', 'c')
                ->fields('c', ['code', 'name']);
            $countries_results = $query->execute()->fetchAll();

            //on remet la connexion D8
            \Drupal\Core\Database\Database::setActiveConnection();
            $dbD8 = \Drupal\Core\Database\Database::getConnection();

            if (is_array($countries_results)) {
                foreach ($countries_results AS $country) {
                    $name = "";
                    $code = "";
                    // On vérifie si on a affaire à un objet ou à un tableau
                    if (is_object($country) && isset($country->code)) {
                        $code = $country->code;
                        $name = $country->name;
                    }
                    elseif (is_array($country) && isset($country['code'])) {
                        $code = $country['code'];
                        $name = $country['name'];
                    }

                    //vérification de l'existance du terme et création
                    $query = $dbD8->select('taxonomy_term_field_data', 't');
                    $query->leftJoin('taxonomy_term__field_country_code', 'c', 'c.entity_id = t.tid');
                    $query->condition('t.vid', 'office_countries');
                    $query->condition('t.name', $name);
                    $query->condition('c.field_country_code_value', $code);
                    $query->fields('t', array('tid'));
                    $entity = $query->execute()->fetchObject();

                    if (!isset($entity) || empty($entity)) {
                        //s'il n'existe pas on le crée
                        $newTerm = \Drupal\taxonomy\Entity\Term::create([
                            'vid' => 'office_countries',
                            'langcode' => 'und',
                            'name' => $name,
                            'field_country_code' => $code,
                        ]);
                        $newTerm->save();
                    }
                }
            }
            \Drupal\Core\Database\Database::setActiveConnection('drupal7');
        }
    }
}