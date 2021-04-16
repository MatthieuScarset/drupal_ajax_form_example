<?php

//ajout de l'indexation des Distributors
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('oab_synomia_search.synomia.contentTypes');
$config_group->set('distributor', 1);
$config_group->save(TRUE);

//ajout des metatags
oabt_YmlImport('metatag.metatag_defaults.node__distributor.yml');