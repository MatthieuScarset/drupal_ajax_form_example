<?php

//REGIONS
$regions = get_correspondances_regionsD7_to_regionsD8();
\Drupal::state()->set('correspondence_taxo_region', $regions);