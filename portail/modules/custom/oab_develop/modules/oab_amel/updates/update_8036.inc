<?php



// Remplacement du champs lien texte par un champ lien sur les paragraphes home thematic columns

oabt_YmlImport('field.field.paragraph.home_thematic_columns.field_link_title.yml');
oabt_YmlImport('core.entity_form_display.paragraph.home_thematic_columns.default.yml');
oabt_YmlImport('core.entity_view_display.paragraph.home_thematic_columns.default.yml');


// Remontées filtrées par langue sur les pages thématique eclairage
// Pas de remontée de page thématiques sur les pages thématique
oabt_YmlImport('views.view.page_thematique.yml');


oabt_YmlImport('core.entity_form_display.node.hp_eclairage_thematique.default.yml');
oabt_YmlImport('core.entity_form_display.node.homepage_eclairage.default.yml');
oabt_YmlImport('core.entity_view_display.node.hp_eclairage_thematique.default.yml');
oabt_YmlImport('core.entity_view_display.node.homepage_eclairage.default.yml');
