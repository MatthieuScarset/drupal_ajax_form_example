<?php
/**
 * Migrate post row save event subscriber and handler.
 */

namespace Drupal\oab_migrate_content\EventSubscriber;

// This is the interface we are going to implement.
use Drupal\Core\Database\Database;
use \Symfony\Component\EventDispatcher\EventSubscriberInterface;
use \Drupal\migrate\Event\MigrateEvents;
use \Drupal\migrate\Event\MigrateRollbackEvent;
use \Drupal\migrate\Event\MigrateRowDeleteEvent;
use \Drupal\migrate\Event\MigratePostRowSaveEvent;
use Drupal\migrate\Event\MigrateImportEvent;

/**
 * Subscribe to MigrateEvents::POST_ROW_SAVE events.
 */
class OabMigrateContentBlogPostSave implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   *
   * Publish the Event.
   */
  public static function getSubscribedEvents() {
    //$events[MigrateEvents::POST_ROW_SAVE][] = array('updateDates');
    $events[MigrateEvents::POST_ROW_SAVE][] = array('updateTranslations');
    $events[MigrateEvents::POST_ROW_DELETE][] = array('deleteUrlAlias');

    return $events;
  }

  /**
   * MigrateEvents::POST_ROW_SAVE event handler.
   *
   * @param MigratePostRowSaveEvent $migrate_row
   *   Instance of Drupal\migrate\Event\MigratePostRowSaveEvent.
   */
  /*public function updateDates(MigratePostRowSaveEvent $migrate_row) {

    $row = $migrate_row->getRow();
    $destinationIdValues = $migrate_row->getDestinationIdValues();
    $nid = $destinationIdValues[0];
    $migrate_src_values = $row->getSource();

    $entity = \Drupal\node\Entity\Node::load($nid);
    $entityToSave = false;

    \Drupal::logger('migration date')->notice(serialize($migrate_src_values));

    if (isset($migrate_src_values['created'])){
      $entity->setCreatedTime($migrate_src_values['created']);
      $entityToSave = true;
    }
    if (isset($migrate_src_values['changed'])){
      $entity->setChangedTime($migrate_src_values['created']);
      $entityToSave = true;
    }

    if ($entityToSave){
      $entity->save();
      \Drupal::logger('migration date')->notice('date changed');
    }
  }*/

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
    && $migrate_src_values['plugin'] == 'blogpost_profile'){
      $entity = \Drupal\node\Entity\Node::load($nid);

      $values = array(
        // Non multilingual.
        'created' => $migrate_src_values['created'],
        'changed' => $migrate_src_values['created'],
        'uid' => 1,
        'sticky' => 0,
        'status' => 1,

        // Multilingual.
        'title' => $migrate_src_values['title'],
        'body' => array('value' => $migrate_src_values['field_txt_catcher'], 'format' => 'full_html'),
        'field_job' => $migrate_src_values['field_profil'],
        'field_location' => $migrate_src_values['field_location'],
        'field_image' => $migrate_dest_values['field_image'],
      );

      if ($entity->hasTranslation('en')){
        $entity->removeTranslation('en');
      }

      $translated_entity = $entity->addTranslation('en', $values);
      $translated_entity->save();

      $map = $migrate_row->getMigration()->getIdMap();

      $map->saveIdMapping($migrate_row->getRow(), array($nid));
    }

    // gestion des workflow schedule
    // ne fonctionne pas car une transition est déjà en cours d'enregistrement
    // provoque l'erreur : Transition is executed twice in a call. The second call for XXXX is not executed.
    
    /*if (isset($migrate_src_values['workflow_transition_state'])
    && isset($migrate_src_values['workflow_transition_time'])){
      $workflow_comment = isset($migrate_src_values['workflow_transition_comment']) ? $migrate_src_values['workflow_transition_comment'] : '';
      $entity = \Drupal\node\Entity\Node::load($nid);

      $workflowTransition = \Drupal\workflow\Entity\WorkflowTransition::create([$migrate_src_values['workflow']]);
      $workflowTransition->schedule(TRUE);
      $workflowTransition->setValues($migrate_src_values['workflow_transition_state'], NULL, $migrate_src_values['workflow_transition_time'], $workflow_comment);
      $workflowTransition->setTargetEntity($entity);
      $workflowTransition->set('field_name', 'field_state');
      $workflowTransition->execute();
    }*/

    // On remet l'utilisateur anonyme par défaut, au cas où
    $anonymous_user = \Drupal\user\Entity\User::load(0);
    \Drupal::getContainer()->set('current_user', $anonymous_user);
  }

  /** Suppression des Url alias
   * @param MigrateRowDeleteEvent $migrate_row
   */
  public function deleteUrlAlias(MigrateRowDeleteEvent $migrate_row)
  {
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
}