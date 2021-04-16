<?php

use Drupal\redirect\Entity\Redirect;

// desactivation vue frontpage
oabt_YmlImport('views.view.frontpage.yml');
// desactivation vue frontpage
oabt_YmlImport('views.view.taxonomy_term.yml');

// ajout d'une redirection /node vers la homepage en 301
Redirect::create([
  'redirect_source' => 'node',
  'redirect_redirect' => 'internal:/',
  'language' => 'und',
  'status_code' => '307',
])->save();
