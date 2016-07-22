<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');
$config->set('settings', array (
  'toolbar' =>
    array (
      'rows' =>
        array (
          0 =>
            array (
              0 =>
                array (
                  'name' => 'Formatting',
                  'items' =>
                    array (
                      0 => 'Bold',
                      1 => 'Italic',
                      2 => 'Underline',
                      3 => '-',
                      4 => 'RemoveFormat',
                      5 => 'Styles',
                      6 => 'JustifyLeft',
                      7 => 'JustifyCenter',
                      8 => 'JustifyRight',
                      9 => 'JustifyBlock',
                      10 => 'Undo',
                      11 => 'Redo',
                    ),
                ),
              1 =>
                array (
                  'name' => 'Linking',
                  'items' =>
                    array (
                      0 => 'DrupalLink',
                      1 => 'DrupalUnlink',
                    ),
                ),
              2 =>
                array (
                  'name' => 'Lists',
                  'items' =>
                    array (
                      0 => 'BulletedList',
                    ),
                ),
              3 =>
                array (
                  'name' => 'Media',
                  'items' =>
                    array (
                      0 => 'Blockquote',
                      1 => 'media_browser',
                      2 => 'Table',
                      3 => 'HorizontalRule',
                    ),
                ),
              4 =>
                array (
                  'name' => 'Tools',
                  'items' =>
                    array (
                      0 => 'FontAwesome',
                      1 => 'Templates',
                      2 => 'ShowBlocks',
                      3 => 'Source',
                      4 => 'SpecialChar',
                      5 => 'Outdent',
                      6 => 'Cut',
                      7 => 'Copy',
                      8 => 'Indent',
                      9 => 'PasteFromWord',
                      10 => 'Maximize',
                    ),
                ),
            ),
        ),
    ),
  'plugins' =>
    array (
      'language' =>
        array (
          'language_list' => 'un',
        ),
      'stylescombo' =>
        array (
          'styles' => 'div.titre1|titre 60pt
div.titre2|titre 50pt
div.titre3|titre 40pt
div.titre4|titre 34pt
div.titre5|titre 30pt
div.titre6|titre 24pt
div.titre7|titre 20pt
p.highlight1|paragraphe 18pt
p.highlight2|paragraphe 16pt
ul.orange|liste orange
ul.black|liste noire
ul.white|liste blanche
ul.grey|liste grise
span.orange|texte orange
span.black|texte noir
span.white|texte blanc
span.blue|texte bleu',
        ),
    ),
));
$config->save(TRUE);

//throw new \Drupal\Core\Utility\UpdateException();