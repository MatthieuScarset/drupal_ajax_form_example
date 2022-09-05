<?php

namespace Drupal\oab_custom_assets\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBase;

/**
 * Defines the Custom asset entity.
 *
 * @ConfigEntityType(
 *   id = "custom_asset",
 *   label = @Translation("Custom asset"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_custom_assets\CustomAssetListBuilder",
 *     "form" = {
 *       "add" = "Drupal\oab_custom_assets\Form\CustomAssetForm",
 *       "edit" = "Drupal\oab_custom_assets\Form\CustomAssetForm",
 *       "delete" = "Drupal\oab_custom_assets\Form\CustomAssetDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_custom_assets\CustomAssetHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "custom_asset",
 *   admin_permission = "administer site configuration",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   config_export = {
 *      "id",
 *      "label",
 *      "uuid",
 *      "paths",
 *      "css",
 *      "js",
 *      "bottom_js"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/oab/custom_asset/{custom_asset}",
 *     "add-form" = "/admin/structure/oab/custom_asset/add",
 *     "edit-form" = "/admin/structure/oab/custom_asset/{custom_asset}/edit",
 *     "delete-form" = "/admin/structure/oab/custom_asset/{custom_asset}/delete",
 *     "collection" = "/admin/structure/oab/custom_asset"
 *   }
 * )
 */
class CustomAsset extends ConfigEntityBase implements CustomAssetInterface {

  /**
   * The Custom asset ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Custom asset label.
   *
   * @var string
   */
  protected $label;

  public function getPaths(): ?string {
    return $this->get("paths");
  }

  public function getPathsAsArray(): array {
    return explode('\r\n', $this->getPaths()) ?? [];
  }

  public function getCSS(): ?string {
    return $this->get("css");
  }

  public function getJs(): ?string {
    return $this->get("js");
  }

  public function getBottomJs(): ?string {
    return $this->get("bottom_js");
  }

}
