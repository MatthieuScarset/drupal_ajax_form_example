<?php

/**
 * @file
 * Contains \Drupal\replicate\Replicator.
 */

namespace Drupal\replicate;

use Drupal\Core\Entity\EntityInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Entity\FieldableEntityInterface;
use Drupal\replicate\Events\AfterSaveEvent;
use Drupal\replicate\Events\ReplicateAlterEvent;
use Drupal\replicate\Events\ReplicateEntityEvent;
use Drupal\replicate\Events\ReplicateEntityFieldEvent;
use Drupal\replicate\Events\ReplicatorEvents;
use Symfony\Component\EventDispatcher\EventDispatcherInterface;

/**
 * Class Replicator. Manages the replication of an entity.
 *
 * @package Drupal\replicate
 */
class Replicator {

  /**
   * The entity type manager.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * The event dispatcher.
   *
   * @var \Symfony\Component\EventDispatcher\EventDispatcherInterface
   */
  protected $eventDispatcher;

  /**
   * Creates a new Replicator instance.
   *
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager.
   * @param \Symfony\Component\EventDispatcher\EventDispatcherInterface $event_dispatcher
   *   The event dispatcher.
   */
  public function __construct(EntityTypeManagerInterface $entity_type_manager, EventDispatcherInterface $event_dispatcher) {
    $this->entityTypeManager = $entity_type_manager;
    $this->eventDispatcher = $event_dispatcher;
  }


  /**
   * Replicate a entity by entity type ID and entity ID and save it.
   *
   * @param string $entity_type_id
   *   The entity type ID.
   * @param int $entity_id
   *   The entity ID.
   *
   * @return \Drupal\Core\Entity\EntityInterface|null
   *   The cloned entity.
   */
  public function replicateByEntityId($entity_type_id, $entity_id) {
    if ($entity = $this->entityTypeManager->getStorage($entity_type_id)->load($entity_id)) {
      return $this->replicateEntity($entity);
    }
  }

  /**
   * Replicate a entity and save it.
   *
   * @param \Drupal\Core\Entity\EntityInterface $entity
   *   The entity.
   *
   * @return \Drupal\Core\Entity\EntityInterface|null
   *   The cloned entity.
   */
  public function replicateEntity(EntityInterface $entity) {
    if ($clone = $this->cloneEntity($entity)) {
      $this->entityTypeManager->getStorage($entity->getEntityTypeId())->save($clone);
      $event = new AfterSaveEvent($clone);
      $this->eventDispatcher->dispatch(ReplicatorEvents::AFTER_SAVE, $event);
      return $clone;
    }
  }

  /**
   * Clone a entity by entity type ID and entity ID without saving.
   *
   * @param string $entity_type_id
   *   The entity type ID.
   * @param int $entity_id
   *   The entity ID.
   *
   * @return \Drupal\Core\Entity\EntityInterface|null
   *   The cloned entity.
   */
  public function cloneByEntityId($entity_type_id, $entity_id) {
    if ($entity = $this->entityTypeManager->getStorage($entity_type_id)->load($entity_id)) {
      return $this->cloneEntity($entity);
    }
  }

  /**
   * Clone a entity without saving.
   *
   * @param \Drupal\Core\Entity\EntityInterface $entity
   *   The entity.
   *
   * @return \Drupal\Core\Entity\EntityInterface|null
   *   The cloned entity.
   */
  public function cloneEntity(EntityInterface $entity) {
    if ($clone = $entity->createDuplicate()) {
      $event = new ReplicateEntityEvent($entity);
      $this->eventDispatcher->dispatch(ReplicatorEvents::replicateEntityEvent($entity->getEntityTypeId()), $event);

      if ($clone instanceof FieldableEntityInterface) {
        $this->cloneEntityFields($clone);
      }

      $event = new ReplicateAlterEvent($clone, $entity);
      $this->eventDispatcher->dispatch(ReplicatorEvents::REPLICATE_ALTER, $event);
      return $clone;
    }
  }

  /**
   * Fires events for each field of a fieldable entity.
   *
   * @param \Drupal\Core\Entity\FieldableEntityInterface $clone
   *   The cloned fieldable entity.
   */
  protected function cloneEntityFields(FieldableEntityInterface $clone) {
    foreach ($clone->getFieldDefinitions() as $field_name => $field_definition) {
      $event = new ReplicateEntityFieldEvent($clone->get($field_name), $clone);
      $this->eventDispatcher->dispatch(ReplicatorEvents::replicateEntityField($field_definition->getType()), $event);
    }
  }

}
