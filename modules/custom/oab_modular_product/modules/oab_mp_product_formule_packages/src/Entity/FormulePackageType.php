<?php

namespace Drupal\oab_mp_product_formule_packages\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBundleBase;
use Drupal\Core\Config\Entity\ThirdPartySettingsInterface;
use Drupal\oab_mp_formules\Entity\ProductFormuleEntity;

/**
 * Defines the Formule package type entity.
 *
 * @ConfigEntityType(
 *   id = "formule_package_type",
 *   label = @Translation("Formule package type"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_mp_product_formule_packages\FormulePackageTypeListBuilder",
 *     "form" = {
 *       "add" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageTypeForm",
 *       "edit" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageTypeForm",
 *       "delete" = "Drupal\oab_mp_product_formule_packages\Form\FormulePackageTypeDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_mp_product_formule_packages\FormulePackageTypeHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "formule_package_type",
 *   admin_permission = "administer site configuration",
 *   bundle_of = "formule_package",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid",
 *     "formule" = "formule"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/type/formule_package/{formule_package_type}",
 *     "add-form" = "/admin/structure/type/formule_package/add",
 *     "edit-form" = "/admin/structure/type/formule_package/{formule_package_type}/edit",
 *     "delete-form" = "/admin/structure/type/formule_package/{formule_package_type}/delete",
 *     "collection" = "/admin/structure/type/formule_package"
 *   },
 *    revision_metadata_keys = {
 *     "revision_user" = "revision_user",
 *     "revision_created" = "revision_created",
 *     "revision_log_message" = "revision_log",
 *   },
 *   config_export = {
 *     "id",
 *     "label",
 *     "uuid",
 *     "formule"
 *   },
 * )
 */
class FormulePackageType extends ConfigEntityBundleBase implements FormulePackageTypeInterface {

  /**
   * The Formule package type ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Formule package type label.
   *
   * @var string
   */
  protected $label;


  /**
   * @var int
   */
  protected $formule;


  public function getFormule(): ?ProductFormuleEntity {
    return ProductFormuleEntity::load($this->get('formule') ?? 0);
  }

}
