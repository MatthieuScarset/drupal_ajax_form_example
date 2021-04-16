<?php

namespace Drupal\oab_subhomes\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBundleBase;

/**
 * Defines the Subhome entity type entity.
 *
 * @ConfigEntityType(
 *   id = "subhome_entity_type",
 *   label = @Translation("Subhome entity type"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_subhomes\SubhomeEntityTypeListBuilder",
 *     "form" = {
 *       "add" = "Drupal\oab_subhomes\Form\SubhomeEntityTypeForm",
 *       "edit" = "Drupal\oab_subhomes\Form\SubhomeEntityTypeForm",
 *       "delete" = "Drupal\oab_subhomes\Form\SubhomeEntityTypeDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_subhomes\SubhomeEntityTypeHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "subhome_entity_type",
 *   admin_permission = "administer site configuration",
 *   bundle_of = "subhome_entity",
 *   translatable = false,
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/subhome_entity_type/{subhome_entity_type}",
 *     "add-form" = "/admin/structure/subhome_entity_type/add",
 *     "edit-form" = "/admin/structure/subhome_entity_type/{subhome_entity_type}/edit",
 *     "delete-form" = "/admin/structure/subhome_entity_type/{subhome_entity_type}/delete",
 *     "collection" = "/admin/structure/subhome_entity_type"
 *   }
 * )
 */
class SubhomeEntityType extends ConfigEntityBundleBase implements SubhomeEntityTypeInterface {

  /**
   * The Subhome entity type ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Subhome entity type label.
   *
   * @var string
   */
  protected $label;

}
