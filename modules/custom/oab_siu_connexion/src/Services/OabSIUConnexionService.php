<?php

namespace Drupal\oab_siu_connexion\Services;

use Drupal\Core\Condition\ConditionManager;
use Drupal\Core\Config\ImmutableConfig;

class OabSIUConnexionService {

  public function __construct(
    private ImmutableConfig $config,
    private ConditionManager $conditionManager
  ) { }

  public function getIDPConnexion(): mixed {
    return $this->get("idp");
  }

  public function getSIURestrictedURL(): string {
    return $this->get("siu_restricted_urls");
  }

  public function isCurrentPageAllowed(string $path = null): bool {
    $plugin_conf = [
      'pages' => $this->getSIURestrictedURL() ?? ''
    ];

    if ($path) {
      $plugin_conf['current_path'] = $path;
    }

    /** @var \Drupal\system\Plugin\Condition\RequestPath $path_condition */
    $path_condition = $this->conditionManager->createInstance('request_path', $plugin_conf);

    return $path_condition->evaluate();
  }

  private function get(string $item): mixed {
    return $this->config->get($item) ?? [];
  }
}

