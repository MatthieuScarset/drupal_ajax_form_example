<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('editor.editor.full_html');
$config_group->set('settings.plugins.stylescombo', array (
  'styles' => "div.titre1|intertitre
                                div.titre2|chapô
                                div.titre3|sous titre
                                p.highlight1|paragraphe
                                ul.orange|liste orange
                                ul.black|liste noire
                                ul.white|liste blanche
                                ul.grey|liste grise
                                span.orange|texte orange
                                span.black|texte noir
                                span.white|texte blanc
                                span.blue|texte bleu"
));
$config_group->save(TRUE);
