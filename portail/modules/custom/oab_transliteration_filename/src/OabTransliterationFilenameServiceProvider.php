<?php

namespace Drupal\oab_transliteration_filename;

use Drupal\Core\DependencyInjection\ContainerBuilder;
use Drupal\Core\DependencyInjection\ServiceProviderBase;

class OabTransliterationFilenameServiceProvider extends ServiceProviderBase {

    public function alter(ContainerBuilder $container) {
        $definition = $container->getDefinition('transliteration');
        $definition->setClass('Drupal\oab_transliteration_filename\Transliteration');
    }
}
