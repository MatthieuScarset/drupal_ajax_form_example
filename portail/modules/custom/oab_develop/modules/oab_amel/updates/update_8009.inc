<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('editor.editor.full_html');
$config_group->set('settings.plugins.stylescombo', array (
    'styles' => "  div.titre1|titre             
                                div.titre2|intertitre
                                div.titre3|chapô
                                div.titre4|sous titre
                                p.highlight1|paragraphe
                                p.date|date
                                p.insight_banniere|insight bannière                                                              
                                ul.orange|liste orange
                                ul.black|liste noire
                                ul.white|liste blanche
                                ul.grey|liste grise
                                span.downloadPDF|download PDF  
                                span.orange|texte orange
                                span.black|texte noir
                                span.white|texte blanc
                                span.blue|texte bleu"
));
$config_group->save(TRUE);
