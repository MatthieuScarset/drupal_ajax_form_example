<?php

// Pas de pager desktop sur la homepage eclairage + tri par dates du plus récent au moins récent
oabt_YmlImport('views.view.home_eclairage_playlist.yml');

//  tri par dates du plus récent au moins récent pour la vue thématique
oabt_YmlImport('views.view.page_thematique.yml');

// Création des menus FR, RU et RU-EN, et renommage pour le EN
oabt_YmlImport('system.menu.menu-homepage-eclairage.yml');
oabt_YmlImport('system.menu.menu-homepage-eclairage-fr.yml');
oabt_YmlImport('system.menu.menu-homepage-eclairage-ru.yml');
oabt_YmlImport('system.menu.menu-homepage-eclairage-ru-.yml');


