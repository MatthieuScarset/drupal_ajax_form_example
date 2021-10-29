<?php

namespace Drupal\oab_backoffice\Plugin\Action;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Action\ActionBase;
use Drupal\Core\Session\AccountInterface;

/**
 * Node workbench unpublish.
 *
 * @Action(
 *   id = "oab_backoffice_node_workbench_unpublish",
 *   label = @Translation("Workbench unpublish content"),
 *   type = "node"
 * )
 */
class NodeWorkbenchUnpublish extends ActionBase {

  /**
   * {@inheritdoc}
   */
  public function execute($entity = NULL) {

    $moderation_enabled = false;
    $config_factory = \Drupal::configFactory();
    $config = $config_factory->get($entity->getEntityTypeId().'.type.'.$entity->bundle());

    if (!empty($config) && !empty($config->get('third_party_settings'))) {
      $moderation_enabled = $config->get('third_party_settings.workbench_moderation.enabled');
    }
    if($moderation_enabled){
      $entity->set('moderation_state', array('target_id' => 'unpublished'));
    }
    else{
      $entity->setPublished(false);
    }
    $entity->save();
  }

  /**
   * {@inheritdoc}
   */
  public function access($object, AccountInterface $account = NULL, $return_as_object = FALSE) {
    $result = $object->access('update', $account, TRUE)
      ->andif(AccessResult::allowedIfHasPermission($account, 'use draft_draft transition'))
      ->andif(AccessResult::allowedIfHasPermission($account, 'use published_draft transition'))
      ->andif(AccessResult::allowedIfHasPermission($account, 'use needs_review_draft transition'));

    return $return_as_object ? $result : $result->isAllowed();
  }

}
