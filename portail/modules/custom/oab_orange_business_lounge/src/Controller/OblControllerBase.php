<?php

namespace Drupal\oab_orange_business_lounge\Controller;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Session\AccountInterface;

abstract class OblControllerBase extends ControllerBase {


  private $session_var_name = 'obl_controller_token';

  protected function generateToken() {
    $session = \Drupal::request()->getSession();

    $token = uniqid("", true);
    $session->set($this->session_var_name, $token);

    return $token;
  }

  protected function isTokenValid($token) {
    $session = \Drupal::request()->getSession();
    if (!$session->has($this->session_var_name)) {
      return false;
    }

    return $token === $session->get($this->session_var_name);
  }

  public function access(AccountInterface $account) {
    $request = \Drupal::request();
    if ($request->query->has('t') && $this->isTokenValid($request->query->get('t'))) {
       return AccessResult::allowed();
    }

    return AccessResult::forbidden();
  }

}
