<?php

// ajout d'un relation ship pour field_insight
oabt_YmlImport('views.view.page_thematique.yml');


// ajout de deux champs dans type de contenus homepage eclairage thematique
oabt_YmlImport('field.field.node.hp_eclairage_thematique.field_header_title.yml');
oabt_YmlImport('field.field.node.hp_eclairage_thematique.field_insight.yml');

//ajout de taxonomie insight dans type de contenus page simple
oabt_YmlImport('field.field.node.simple_page.field_insight.yml');



// MAJ des view diaplay et form display des types de contenus hp_eclairage_thematique et simple page
oabt_YmlImport('core.entity_form_display.node.simple_page.default.yml');
oabt_YmlImport('core.entity_view_display.node.simple_page.default.yml');
oabt_YmlImport('core.entity_form_display.node.hp_eclairage_thematique.default.yml');
oabt_YmlImport('core.entity_view_display.node.hp_eclairage_thematique.default.yml');


// MAJ du style d'image valorisation et des modes de rendu Teaser -> application du style d'image valorisation
oabt_YmlImport('core.entity_view_display.media.image.teaser.yml');
oabt_YmlImport('image.style.valorisation.yml');

