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
 *      "visibility",
 *      "assets"
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

  public function getAssets(): array {
    return $this->get('assets') ?? ["css" => "", "js" => "", "bottom_js" => ""];
  }

  public function getVisibility(): array {
    return $this->get('visibility') ?? ["paths" => "", "languages" => []];
  }

  public function getPaths(): ?string {
    return $this->visibility['paths'] ?? null;
  }

  public function getPathsAsArray(): array {
    return explode("\r\n", $this->getPaths()) ?? [];
  }

  public function getLanguages(): array {

    if (!empty($this->visibility['languages'])) {
      return array_filter($this->visibility['languages']);
    }

    return [];
  }

  public function getCSS(): ?string {
    return $this->assets['css'] ?? null;
  }

  public function getJs(): ?string {
    return $this->assets['js'] ?? null;
  }

  public function getBottomJs(): ?string {
    return $this->assets['bottom_js'] ?? null;
  }

}
