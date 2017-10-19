<?php


//suppression des contenus press release et press kit pour ne pas
// afficher la barre de contact standard russe, mais seulement la barre de contact des contenus presse

oabt_YmlImport('block.block.contactbarrustandard.yml');

//ajout du terme de taxonomie INSIGHT pour permettre de remonter les témoignages client sur la homepage eclairage

oabt_YmlImport('field.field.node.customer_story.field_insight.yml');
oabt_YmlImport('core.entity_view_display.node.customer_story.default.yml');
oabt_YmlImport('core.entity_form_display.node.customer_story.default.yml');

// display all items on Homepage Eclairage

oabt_YmlImport('block.block.contactbarrustandard.yml');

// Remplacement du champs lien texte par un champ lien sur les paragraphes home banner

oabt_YmlImport('field.field.paragraph.home_banner.field_link_title.yml');
oabt_YmlImport('core.entity_form_display.paragraph.home_banner.default.yml');
oabt_YmlImport('core.entity_view_display.paragraph.home_banner.default.yml');
