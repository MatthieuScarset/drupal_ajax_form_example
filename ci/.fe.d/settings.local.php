<?php

/**
 * Specifics settings for PRP and Prod
 */



$settings['config_sync_directory'] = '../config/sync';

$settings['update_free_access'] = FALSE;

$config['config_split.config_split.prp']['status'] = getenv('ENV') === "prp";
$config['config_split.config_split.prod']['status'] = getenv('ENV') === "prod";

