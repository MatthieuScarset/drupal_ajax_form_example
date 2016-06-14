<?php
/**
 * Migrate post row save event subscriber and handler.
 */

namespace Drupal\oab_migrate_content\EventSubscriber;

// This is the interface we are going to implement.
use \Symfony\Component\EventDispatcher\EventSubscriberInterface;
use \Drupal\migrate\Event\MigrateEvents;
use \Drupal\migrate\Event\MigratePostRowSaveEvent;

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
    $events[MigrateEvents::POST_ROW_SAVE][] = array('updateTranslations');
    return $events;
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
    && $migrate_src_values['plugin'] == 'blogpost_profile'){
      $entity = \Drupal\node\Entity\Node::load($nid);

      $values = array(
        // Non multilingual.
        'created' => time(),
        'uid' => 1,
        'sticky' => 0,
        'status' => 1,

        // Multilingual.
        'title' => $migrate_src_values['title'],
        'body' => $migrate_src_values['field_txt_catcher'],
        'field_job' => $migrate_src_values['field_profil'],
        'field_location' => $migrate_src_values['field_location'],
        'field_image' => $migrate_dest_values['field_image'],
      );
      $translated_entity = $entity->addTranslation('en', $values);
      $translated_entity->save();

      $map = $migrate_row->getMigration()->getIdMap();

      $map->saveIdMapping($migrate_row->getRow(), array($nid));
    }
  }
}