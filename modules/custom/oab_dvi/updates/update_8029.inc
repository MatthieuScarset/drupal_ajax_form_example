<?php

\Drupal::service('path.alias_storage')->delete(array('source' => "/subhome_distributors"));
\Drupal::service('path.alias_storage')->save("/subhome_distributors", "/ventes-indirectes/distributeurs", "fr");