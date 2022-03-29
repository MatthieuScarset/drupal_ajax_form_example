<?php

namespace Drupal\oab_modular_product\Services;

use Drupal\Core\Config\ImmutableConfig;

class OabModularProductService {

  public function __construct(
    private ImmutableConfig $config
  ) { }

  public function getTopZoneTitleMaxCharacter(): string {
    return $this->get("top_zone.title");
  }

  public function getTopZoneDescriptionMaxCharacter(): string {
    return $this->get("top_zone.description");
  }

  public function getModuleTitleMaxCharacter(): string {
    return $this->get("module.title");
  }

  public function getModuleDescriptionMaxCharacter(): string {
    return $this->get("module.description");
  }

  public function getModuleItemsTitleMaxCharacter(): string {
    return $this->get("module_items.title");
  }

  public function getModuleItemsDescriptionMaxCharacter(): string {
    return $this->get("module_items.description");
  }

  private function get(string $item): mixed {
    return $this->config->get("mp_title.$item") ?? [];
  }
}

