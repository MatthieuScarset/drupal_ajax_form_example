<?php

namespaceDrupaloab_transliteration_filename;
useDrupalCoreDependencyInjectionContainerBuilder;
useDrupalCoreDependencyInjectionServiceProviderBase;
class MyModuleServiceProvider extends ServiceProviderBase {

    public function alter(ContainerBuilder $container) {
        $definition = $container->getDefinition('transliteration');
        $definition->setClass(Drupaloab_transliteration_filenameTransliteration::class);

    }
}