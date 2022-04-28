<?php

namespace Drupal\oab_mp_formule_field\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBase;

/**
 * Defines the Formule field entity.
 *
 * @ConfigEntityType(
 *   id = "formule_field",
 *   label = @Translation("Formule field"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\oab_mp_formule_field\FormuleFieldListBuilder",
 *     "form" = {
 *       "add" = "Drupal\oab_mp_formule_field\Form\FormuleFieldForm",
 *       "edit" = "Drupal\oab_mp_formule_field\Form\FormuleFieldForm",
 *       "delete" = "Drupal\oab_mp_formule_field\Form\FormuleFieldDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\oab_mp_formule_field\FormuleFieldHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "formule_field",
 *   admin_permission = "administer site configuration",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid",
 *     "display_label",
 *     "description",
 *     "choices",
 *     "null_value",
 *     "null_label",
 *     "display_mode",
 *     "sentence"
 *   },
 *   links = {
 *     "canonical" = "/admin/product/formule_field/formule_field/{formule_field}",
 *     "add-form" = "/admin/product/formule_field/formule_field/add",
 *     "edit-form" = "/admin/product/formule_field/formule_field/{formule_field}/edit",
 *     "delete-form" = "/admin/product/formule_field/formule_field/{formule_field}/delete",
 *     "collection" = "/admin/product/formule_field/formule_field"
 *   },
 *   config_export = {
 *     "id",
 *     "label",
 *     "uuid",
 *     "display_label",
 *     "description",
 *     "choices",
 *     "null_value",
 *     "null_label",
 *     "display_mode",
 *     "sentence"
 *   },
 * )
 */
class FormuleField extends ConfigEntityBase implements FormuleFieldInterface {

  /**
   *     "display_label",
   *     "description",
   *     "choices",
   *     "null_value",
   *     "null_label"
   *     "display_mode",
   *     "sentence" */

  /**
   *  *     "display_label" = "display label",
   *     "description" = "description",
   *     "choices" = "choices",
   *     "null_value" = "has null value,
   *     "null_label" = "null label",
   *     "display_mode" = "display mode",
   *     "sentence" = "sentence
   */


  /**
   * The Formule field ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The Formule field label.
   *
   * @var string
   */
  protected string $label;

  /**
   * The Formule field label displayed.
   *
   * @var string
   */
  protected string $display_label;

  /**
   * The field descriptionl.
   *
   * @var string
   */
  protected string $description = "";

  /**
   * The field choices.
   *
   * @var array
   */
  protected array $choices = [];

  /**
   * If user can choose a none of the choices
   * @var bool
   */
  protected bool $null_value;

  /**
   * If user can choose a none of the choices
   * @var string
   */
  protected string $null_label;

  /**
   * The Formule field label.
   *
   * @var string
   */
  protected string $display_mode = "";

  /**
   * The Formule field label.
   *
   * @var string
   */
  protected string $sentence = "";

  /**
   * Hack for entityViewBuilder that need a "isDefaultRevision" even if the entity is not revisionable
   * @return bool
   */
  public function isDefaultRevision() {
    return true;
  }


  /**
   * @return ?string
   */
  public function getDescription(): ?string {
    return $this->get('description');
  }

  /**
   * @param string $description
   */
  public function setDescription(string $description): void {
    $this->description = $description;
  }

  /**
   * @return array
   */
  public function getChoices(): array {
    return $this->get('choices') ?? [];
  }

  /**
   * @param array|string $choices
   */
  public function setChoices(array|string $choices): void {

    if (is_string($choices)) {
      dd($choices, PHP_EOL);
    }

    $this->choices = $choices;
  }


  /**
   * @return ?string
   */
  public function getSentence(): ?string {
    return $this->get('sentence');
  }

  /**
   * @param string $sentence
   */
  public function setSentence(string $sentence): void {
    $this->sentence = $sentence;
  }

  /**
   * @return ?string
   */
  public function getDisplayLabel(): ?string {
    return $this->get('display_label');
  }

  /**
   * @param string $display_label
   */
  public function setDisplayLabel(string $display_label): void {
    $this->display_label = $display_label;
  }

  /**
   * @return ?string
   */
  public function getDisplayMode(): ?string {
    return $this->get('display_mode');
  }

  /**
   * @param string $display_mode
   */
  public function setDisplayMode(string $display_mode): void {
    $this->display_mode = $display_mode;
  }

  /**
   * @return bool
   */
  public function hasNullValue(): bool {
    return (bool) $this->get('null_value') ?? false;
  }

  /**
   * @param bool $null_value
   */
  public function setNullValue(bool $null_value): void {
    $this->null_value = $null_value;
  }

  /**
   * @return ?string
   */
  public function getNullLabel(): ?string {
    return $this->get('null_label');
  }

  /**
   * @param string $null_label
   */
  public function setNullLabel(string $null_label): void {
    $this->null_label = $null_label;
  }

}
