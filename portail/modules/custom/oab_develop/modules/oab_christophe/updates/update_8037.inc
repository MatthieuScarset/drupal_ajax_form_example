<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');
$config->setData(array (
  'uuid' => 'cf04fad0-354b-4937-8f05-5e173e8a060c',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'filter.format.full_html',
        ),
      'module' =>
        array (
          0 => 'ckeditor',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => '967ijj7p6i7rwrYl7r08WQFeCY_c23YAh0h8u-w_CXM',
    ),
  'format' => 'full_html',
  'editor' => 'ckeditor',
  'settings' =>
    array (
      'toolbar' =>
        array (
          'rows' =>
            array (
              0 =>
                array (
                  0 =>
                    array (
                      'name' => 'Plugins',
                      'items' =>
                        array (
                          0 => 'Styles',
                          1 => 'Templating',
                          2 => 'FontAwesome',
                          3 => 'Templates',
                        ),
                    ),
                  1 =>
                    array (
                      'name' => 'Formatting',
                      'items' =>
                        array (
                          0 => 'Bold',
                          1 => 'Italic',
                          2 => 'Underline',
                          3 => '-',
                          4 => 'RemoveFormat',
                          5 => 'Blockquote',
                          6 => '-',
                          7 => 'media_browser',
                          8 => 'Embed',
                          9 => 'Table',
                          10 => 'HorizontalRule',
                          11 => 'BulletedList',
                          12 => 'SpecialChar',
                          13 => '-',
                          14 => 'Indent',
                          15 => 'Outdent',
                          16 => '-',
                          17 => 'JustifyLeft',
                          18 => 'JustifyCenter',
                          19 => 'JustifyRight',
                          20 => 'JustifyBlock',
                          21 => '-',
                          22 => 'Undo',
                          23 => 'Redo',
                        ),
                    ),
                  2 =>
                    array (
                      'name' => 'Linking',
                      'items' =>
                        array (
                          0 => 'Linkit',
                          1 => 'DrupalUnlink',
                        ),
                    ),
                  3 =>
                    array (
                      'name' => 'Tools',
                      'items' =>
                        array (
                          0 => 'ShowBlocks',
                          1 => 'Source',
                          2 => 'PasteFromWord',
                          3 => 'Maximize',
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
div.textlimit|texte 850px
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
          'linkit' =>
            array (
              'linkit_profile' => 'link',
            ),
        ),
    ),
  'image_upload' =>
    array (
      'status' => true,
      'scheme' => 'public',
      'directory' => 'inline-images',
      'max_size' => '',
      'max_dimensions' =>
        array (
          'width' => NULL,
          'height' => NULL,
        ),
    ),
));
$config->save(TRUE);

