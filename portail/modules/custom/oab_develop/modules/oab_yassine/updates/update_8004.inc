<?php

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');

$config->set('settings.plugins.stylescombo.styles','h1.titre1|Title (H1)             
h2.titre2|Heading (H2)
div.titre3|Introduction
h3.titre4|Subtitle (H3)
p.highlight1|Paragraph
p.date|Date
p.insight_banniere|Banner insight                                                           
ul.orange|Orange list
ul.black|Black bulleted list
ul.white|White bulleted list
ul.grey|Grey bulleted list
span.downloadPDF|download PDF 
'
);

$config->set('settings.plugins.colorbutton',
  array (
    'colors' => 'FF7900,000,fff',
  )
);

$config->save(TRUE);


// throw new UpdateException();