<?php

/**
 * Création d'une vue contenant 2 display view de type "Entity Ref"
 * afin de modifier le retour des autocomplete de la zone rebond
 */

##Création de la vue et des deux displays views
oabt_YmlImport('views.view.rebond_entity_reference.yml');


##Modification des 3 fields concernés dans les différents types de contenu

$contentTypes = [
  "blog_post",
  "customer_story",
  "document",
  "full_html",
  "magazine",
  "partner",
  "press_release",
  "simple_page",
  "webform",
];

foreach ($contentTypes as $contentType) {
  oabt_YmlImport("field.field.node.$contentType.field_rebond_document.yml");
  oabt_YmlImport("field.field.node.$contentType.field_page_du_site_1.yml");
  oabt_YmlImport("field.field.node.$contentType.field_page_du_site_2.yml");
}

