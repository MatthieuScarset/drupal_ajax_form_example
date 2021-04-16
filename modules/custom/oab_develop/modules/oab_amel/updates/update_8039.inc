<?php

// Pas de pager desktop sur la homepage eclairage + tri par dates du plus récent au moins récent
oabt_YmlImport('views.view.home_eclairage_playlist.yml');

//  tri par dates du plus récent au moins récent pour la vue thématique
oabt_YmlImport('views.view.page_thematique.yml');


// modification du lien vers les menus sur la page eclairage
oabt_YmlImport('field.field.node.homepage_eclairage.field_menu_title.yml');