<?php
use \Drupal\Core\Utility\UpdateException;

/***********************
 * Desactivation du module easy-breadcrumb afin de gérer
 * les fils d'ariane par un module perso
 ***********************/
$config_factory = \Drupal::configFactory();

##Je recupère la config des modules
$config_group = $config_factory->getEditable('core.extension');

##Je recupère la liste des modules actifs dans la config
$modules = $config_group->get('module');

##Si je trouve le module easy_breadcrumbre
if (isset($modules['easy_breadcrumb'])) {

  ##Je supprime le module de la config
  unset($modules['easy_breadcrumb']);

  ##je resset le tableau des modules
  $config_group->set('module', $modules);

  ##Je save la config
  $config_group->save(TRUE);

  ##Je recupère la config du module et je la supprime
  $config_easybreadcrumb = $config_factory->getEditable('easy_breadcrumb.settings');
  $config_easybreadcrumb->delete();

}



#A enlever à la fin des tests
throw new UpdateException();