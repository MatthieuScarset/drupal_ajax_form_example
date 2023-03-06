<?php

namespace Drupal\oab_pdf\Access;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Access\AccessResultForbidden;
use Drupal\Core\Access\AccessResultInterface;
use Drupal\Core\Routing\Access\AccessInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\node\NodeInterface;

class PdfAccess implements AccessInterface {

  public function __construct(private RouteMatchInterface $routeMatch) {}

  public function access(AccountInterface $account): bool|AccessResultForbidden|AccessResultInterface {
    /** @var $node NodeInterface */
    if (($node = $this->routeMatch->getParameter('node')) instanceof NodeInterface) {
      return $node->access('view', $account, true);
    }
    return AccessResult::forbidden();
  }
}
