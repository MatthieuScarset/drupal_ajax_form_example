<?php

use Drupal\Core\Database\Database;
// Gestion de la traduction du dashboard

$connection = Database::getConnection();
$query_delete = $connection->delete('config')
    ->condition('collection', 'language.en')
    ->condition('name', 'views.view.dashboard')
    ->execute();

$query_create = $connection->insert('config')
    ->fields(array(
        'collection' => 'language.en',
        'name' => 'views.view.dashboard',
        'data' => serialize(
        array (
            'display' =>
                array (
                    'default' =>
                        array (
                            'display_options' =>
                                array (
                                    'fields' =>
                                        array (
                                            'title' =>
                                                array (
                                                    'label' => 'Title',
                                                ),
                                            'uid' =>
                                                array (
                                                    'label' => 'Author',
                                                ),
                                            'field_rendering_model' =>
                                                array (
                                                    'label' => 'Model',
                                                ),
                                            'langcode' =>
                                                array (
                                                    'label' => 'Language',
                                                ),
                                            'field_state' =>
                                                array (
                                                    'label' => 'Workflow status',
                                                ),
                                            'field_start_date' =>
                                                array (
                                                    'label' => 'Creation date',
                                                ),
                                            'field_end_date' =>
                                                array (
                                                    'label' => 'Expires on',
                                                ),
                                            'operations' =>
                                                array (
                                                    'label' => 'Actions',
                                                ),
                                        ),
                                    'filters' =>
                                        array (
                                            'field_state_value' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'description' => '',
                                                        ),
                                                    'group_info' =>
                                                        array (
                                                            'label' => 'Workflow Status',
                                                        ),
                                                ),
                                            'field_end_date_value' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'description' => '',
                                                        ),
                                                ),
                                            'title' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'label' => 'Title',
                                                        ),
                                                ),
                                            'uid' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'label' => 'Author',
                                                        ),
                                                ),
                                            'langcode' =>
                                                array (
                                                    'expose' =>
                                                        array (
                                                            'label' => 'Language',
                                                        ),
                                                ),
                                        ),
                                ),
                        ),
                ),
        ))
    ))
    ->execute();