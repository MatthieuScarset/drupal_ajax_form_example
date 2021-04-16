<?php

namespace Drupal\oab_marketo\Access;


use Drupal\Core\Access\AccessResult;
use Drupal\Core\Access\AccessResultInterface;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Routing\Access\AccessInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use Symfony\Component\Routing\Route;

class AltaresSettingsFormAccess implements AccessInterface {


  private $config;


  public function __construct(ImmutableConfig $altares_config) {
    $this->config = $altares_config;
  }

  /**
   * A custom access check.
   *
   * @param AccountInterface $account
   *   Run access checks for this account.
   *
   * @return AccessResultInterface
   *   The access result.
   */
  public function access(AccountInterface $account) {

    if ($account->id() == 1 || $account->hasPermission('administer site configuration')) {
      return AccessResult::allowed();
    }

    $authorized_users = $this->config->get(OabAltaresSettingsForm::AUTHORIZED_USERS);

    return AccessResult::allowedIf(in_array($account->id(), $authorized_users));
  }
}
