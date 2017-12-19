<?php

oabt_YmlImport("pathauto.pattern.distributor_fr.yml");
oabt_YmlImport("pathauto.pattern.distributor_en_ru.yml");

\Drupal::service('path.alias_storage')->delete(array('source' => "/subhome_distributors"));
\Drupal::service('path.alias_storage')->delete(array('source' => "/subhome_products_dvi"));
\Drupal::service('path.alias_storage')->save("/subhome_distributors", "/ventes-indirectes/revendeurs", "fr");
\Drupal::service('path.alias_storage')->save("/subhome_products_dvi", "/ventes-indirectes/produits", "fr");