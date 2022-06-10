<?php

namespace Drupal\oab_mp_formule_field\Entity;

use Drupal\Core\Config\Entity\ConfigEntityInterface;

/**
 * Provides an interface for defining Formule field entities.
 */
interface FormuleFieldInterface extends ConfigEntityInterface {


  const NULL_ID = 'nil';

  /**
   * @return ?string
   */
  public function getDescription(): ?string;

  /**
   * @param string $description
   */
  public function setDescription(string $description): void;

  /**
   * @return array
   */
  public function getChoices(): array;

  /**
   * @param array|string $choices
   */
  public function setChoices(array|string $choices): void;


  /**
   * @return ?string
   */
  public function getSentence(): ?string;

  /**
   * @param string $sentence
   */
  public function setSentence(string $sentence): void;

  /**
   * @return ?string
   */
  public function getDisplayLabel(): ?string;

  /**
   * @param string $display_label
   */
  public function setDisplayLabel(string $display_label): void;

  /**
   * @return ?string
   */
  public function getDisplayMode(): ?string;

  /**
   * @param string $display_mode
   */
  public function setDisplayMode(string $display_mode): void;

  /**
   * @return bool
   */
  public function hasNullValue(): bool;

  /**
   * @param bool $null_value
   */
  public function setNullValue(bool $null_value): void;

  /**
   * @return ?string
   */
  public function getNullLabel(): ?string;

  /**
   * @param string $null_label
   */
  public function setNullLabel(string $null_label): void;
}
