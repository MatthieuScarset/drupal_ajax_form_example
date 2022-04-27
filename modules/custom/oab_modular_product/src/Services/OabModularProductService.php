<?php

namespace Drupal\oab_modular_product\Services;

use Drupal\Core\Config\ImmutableConfig;

class OabModularProductService {

  public function __construct(
    private ImmutableConfig $config
  ) { }

  public function getShortTitleMaxCharacter(): mixed {
    return $this->get("titles.title_short");
  }

  public function getLongTitleMaxCharacter(): mixed {
    return $this->get("titles.title_long");
  }

  public function getLongDescriptionMaxCharacter(): mixed {
    return $this->get("descriptions.description_long");
  }

  private function get(string $item): mixed {
    return $this->config->get("mp.$item") ?? [];
  }
}

