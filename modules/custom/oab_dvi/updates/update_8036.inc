<?php

/**
 * Création de la nouvelle subhome spécifique aux produits DVI
 *
 * > Création d'un nouveau display Produits DVI (Ou catalgue DVI)
 * > Modification de la subhome produit pour ne plus prendre en compte les produits DVI
 * > Modification de la vue Product Autocomplete pour ne prendre en compte que les produits DVI
 */


oabt_YmlImport("views.view.product_autocomplete.yml");
oabt_YmlImport("views.view.subhomes.yml");


##Création du l'URL pour la page catalogue DVI
\Drupal::service('path.alias_storage')->save("/subhome_catalogue_dvi", "/ventes-indirectes/produits");
\Drupal::service('path.alias_storage')->save("/subhome_catalogue_dvi", "/ventes-indirectes/produits", "fr");