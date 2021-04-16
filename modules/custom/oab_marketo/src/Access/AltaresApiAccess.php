<?php

namespace Drupal\oab_marketo\Access;


use Drupal\Core\Access\AccessResult;
use Drupal\Core\Access\AccessResultInterface;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Routing\Access\AccessInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\oab_marketo\AltaresTokenService;
use Drupal\oab_marketo\Form\OabAltaresSettingsForm;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RequestStack;
use Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException;
use Symfony\Component\Routing\Route;


class AltaresApiAccess implements AccessInterface {

  use StringTranslationTrait;

  /**
   * @var AltaresTokenService
   */
  private $altaresTokenService;

  /**
   * @var Request|null
   */
  private $request;

  public function __construct(AltaresTokenService $altares_token_service, RequestStack $request_stack) {
    $this->altaresTokenService = $altares_token_service;
    $this->request = $request_stack->getCurrentRequest();
  }

  /**
   * A custom access check.
   *
   * @param AccountInterface $account
   *   Run access checks for this account.
   *
   * @return AccessResultInterface
   *   The access result.
   * @throws \Drupal\Core\Entity\EntityStorageException
   */
  public function access(AccountInterface $account) {

    if ($account->id() == 1) {
      return AccessResult::allowed();
    }

    $auth = $this->request->headers->get('Authorization');
    if (preg_match('/Bearer\s(\S+)/', $auth, $matches)) {
      $token = $this->altaresTokenService->getToken($matches[1]);

      if ($token !== null && $this->altaresTokenService->isValid($token)
        && $token->getCount() < $this->altaresTokenService->getMaxRequest()) {
        $token->incrementCount();
        $token->save();
        return AccessResult::allowed();
      }
    }

    $msg = $this->t("Token not valid");
    if ($token !== null && $token->getCount() >= $this->altaresTokenService->getMaxRequest()) {
      $token->set("valid", false);
      $token->save();
      $msg = $this->t("Request limit reached");
    }

    return AccessResult::forbidden($msg);
  }
}
