<?php

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');
$config->set('settings.toolbar.rows.0.1.items',
  array (
    0 => 'Bold',
    1 => 'Italic',
    2 => 'Underline',
    3 => 'TextColor',
    4 => '-',
    5 => 'RemoveFormat',
    6 => 'Blockquote',
    7 => '-',
    8 => 'media_browser',
    9 => 'Table',
    10 => 'HorizontalRule',
    11 => 'BulletedList',
    12 => 'SpecialChar',
    13 => '-',
    14 => 'Outdent',
    15 => 'Indent',
    16 => '-',
    17 => 'JustifyLeft',
    18 => 'JustifyCenter',
    19 => 'JustifyRight',
    20 => 'JustifyBlock',
    21 => '-',
    22 => 'Undo',
    23 => 'Redo',
  )
);

$config->set('settings.plugins.stylescombo.styles','h1.titre1|titre             
h2.titre2|intertitre
div.titre3|chapô
h3.titre4|sous titre
p.highlight1|paragraphe
p.date|date
p.insight_banniere|insight bannière                                                              
ul.orange|liste orange
ul.black|liste noire
ul.white|liste blanche
ul.grey|liste grise
span.downloadPDF|download PDF 
'
);

$config->set('settings.plugins.colorbutton',
  array (
    'colors' => 'FF7900,000,fff,4bb4e6',
  )
);

$config->save(TRUE);


// throw new UpdateException();