<?php

namespace Drupal\oab_siu_connexion\Plugin\Block;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Session\AccountProxyInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use \Drupal\oab_siu_connexion\Entity\SIUProxyUser;

/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "siu_hello_user_block",
 *   admin_label = @Translation("SIU Hello User Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */
class SIUHelloUserBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * @var AccountProxyInterface
   */
  private $currentUser;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, AccountProxyInterface $currentUser) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->currentUser = $currentUser;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('current_user')
    );
  }

  protected function blockAccess(AccountInterface $account) {
      if (in_array('siu_user', $account->getRoles())) {
        return AccessResult::allowed();
      }
    return AccessResult::forbidden();
  }


  public function build() {
    return array(
      '#displayName' => $this->currentUser->getDisplayName(),
      '#theme' => 'siu_hello_user_block',
    );
  }


  public function getCacheContexts() {
    return parent::getCacheContexts() + [
      'user'
    ];
  }

}
