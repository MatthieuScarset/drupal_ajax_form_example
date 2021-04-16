<?php

\Drupal::configFactory()->getEditable('oab_backbones.settings')
    ->set('bbp_network_solution_nid', 0)
    ->set('bbp_simple_page_nid', 0)
    ->set('bbp_front_text', "State-of-the-art indicators to measure Wide-Area-Network performances are Round Trip Delay (RTD), Packet Loss Ratio (PLR) and Jitter. The table below shows the performance between the primary Orange Business Services points of presence worldwide.")
    ->save();
drupal_set_message("Création de la configuration terminée", 'status');
