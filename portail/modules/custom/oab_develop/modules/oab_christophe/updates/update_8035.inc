<?php

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.jirareportblock');
$config->setData(array (
  'uuid' => '7bdc04a7-6c42-445d-9325-5ee9a30a84df',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'oab_backoffice',
          1 => 'user',
        ),
      'theme' =>
        array (
          0 => 'theme_boosted',
        ),
    ),
  'id' => 'jirareportblock',
  'theme' => 'theme_boosted',
  'region' => 'content',
  'weight' => -19,
  'provider' => NULL,
  'plugin' => 'jira_report_block',
  'settings' =>
    array (
      'id' => 'jira_report_block',
      'label' => 'JIRA report block',
      'provider' => 'oab_backoffice',
      'label_display' => '0',
      'jira_report_code' => 'https://jira-build.orangeapplicationsforbusiness.com/s/96d7e41df7891a94f4e7689e8e66cf85-T/en_US-sccndq/64027/51/1.4.27/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector.js?locale=en-US&collectorId=891ebd03',
    ),
  'visibility' =>
    array (
      'user_role' =>
        array (
          'id' => 'user_role',
          'roles' =>
            array (
              'administrator' => 'administrator',
              'fh_admin' => 'fh_admin',
              'fh_content' => 'fh_content',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'user' => '@user.current_user_context:current_user',
            ),
        ),
    ),
));
$config->save(TRUE);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.jirareportblock_2');
$config->setData(array (
  'uuid' => '700d5177-3d4f-4090-9c86-8d0ad1a3f947',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'oab_backoffice',
          1 => 'user',
        ),
      'theme' =>
        array (
          0 => 'theme_obs_backoffice',
        ),
    ),
  'id' => 'jirareportblock_2',
  'theme' => 'theme_obs_backoffice',
  'region' => 'content',
  'weight' => 0,
  'provider' => NULL,
  'plugin' => 'jira_report_block',
  'settings' =>
    array (
      'id' => 'jira_report_block',
      'label' => 'JIRA report block',
      'provider' => 'oab_backoffice',
      'label_display' => '0',
      'jira_report_code' => 'https://jira-build.orangeapplicationsforbusiness.com/s/96d7e41df7891a94f4e7689e8e66cf85-T/en_US-sccndq/64027/51/1.4.27/_/download/batch/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector/com.atlassian.jira.collector.plugin.jira-issue-collector-plugin:issuecollector.js?locale=en-US&collectorId=891ebd03',
    ),
  'visibility' =>
    array (
      'user_role' =>
        array (
          'id' => 'user_role',
          'roles' =>
            array (
              'administrator' => 'administrator',
              'fh_admin' => 'fh_admin',
              'fh_content' => 'fh_content',
            ),
          'negate' => false,
          'context_mapping' =>
            array (
              'user' => '@user.current_user_context:current_user',
            ),
        ),
    ),
));
$config->save(TRUE);
