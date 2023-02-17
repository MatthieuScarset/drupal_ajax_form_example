<?php

namespace Drupal\oab_hub;

use Drupal\Core\DependencyInjection\ContainerBuilder;
use Drupal\Core\DependencyInjection\ServiceProviderBase;

class OabHubServiceProvider extends ServiceProviderBase {

  /**
   * {@inheritDoc}
   */
  public function alter(ContainerBuilder $container) {

    // Replace the path_alias repository by our decorator
    if ($container->hasDefinition('path_alias.repository')) {
      $definition = $container->getDefinition('path_alias.repository');
      $definition->setClass(AliasRepositoryDecorator::class);
    }
  }

}
