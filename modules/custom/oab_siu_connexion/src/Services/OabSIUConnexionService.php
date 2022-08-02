<?php

namespace Drupal\oab_siu_connexion\Services;

use Drupal\Core\Config\ImmutableConfig;

class OabSIUConnexionService {

  public function __construct(
    private ImmutableConfig $config
  ) { }

  public function getIDPConnexion(): mixed {
    return $this->get("idp");
  }

  public function getSIURestrictedURL(): mixed {
    return $this->get("siu_restricted_urls");
  }

  private function get(string $item): mixed {
    return $this->config->get($item) ?? [];
  }
}

