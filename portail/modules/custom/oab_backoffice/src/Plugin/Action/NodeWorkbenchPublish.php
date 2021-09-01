<?php

namespace Drupal\oab_backoffice\Plugin\Action;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Action\ActionBase;
use Drupal\Core\Session\AccountInterface;
use Drupal\oab_synomia_search_engine\Form\OabSynomiaSearchSettingsForm;

/**
 * Node workbench publish.
 *
 * @Action(
 *   id = "oab_backoffice_node_workbench_publish",
 *   label = @Translation("Workbench publish content"),
 *   type = "node"
 * )
 */
class NodeWorkbenchPublish extends ActionBase {

  /**
   * {@inheritdoc}
   */
  public function execute($entity = NULL) {
   /* $moderation_state = $entity->get('moderation_state')->getString();
    \Drupal::logger("oab_backoffice")->info(" status de moderation state : ".$moderation_state);
   */
    //
    $moderation_enabled = false;
    $config_factory = \Drupal::configFactory();
    $config = $config_factory->get($entity->getEntityTypeId().'.type.'.$entity->bundle());

    if (!empty($config) && !empty($config->get('third_party_settings'))) {
      $moderation_enabled = $config->get('third_party_settings.workbench_moderation.enabled');
    }
    if($moderation_enabled){
      $entity->set('moderation_state', array('target_id' => 'published'));
    }
    else{
      $entity->setPublished(true);
    }

    $entity->save();
  }

  /**
   * {@inheritdoc}
   */
  public function access($object, AccountInterface $account = NULL, $return_as_object = FALSE) {
    $result = $object->access('update', $account, TRUE)
        ->andif(AccessResult::allowedIfHasPermission($account, 'use archived_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use draft_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use needs_review_published transition'))
        ->andif(AccessResult::allowedIfHasPermission($account, 'use published_published transition'));

    return $return_as_object ? $result : $result->isAllowed();
  }

}
