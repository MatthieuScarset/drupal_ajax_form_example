<?php

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.dashboard_du_manager_editorial');
$config_group->setData(
    array (
        'label' => 'Dashboard',
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
                                        'field_rendering_model' =>
                                            array (
                                                'label' => 'Model',
                                            ),
                                        'field_start_date' =>
                                            array (
                                                'label' => 'Start date',
                                            ),
                                        'field_end_date' =>
                                            array (
                                                'label' => 'Expiration date',
                                            ),
                                        'uid' =>
                                            array (
                                                'label' => 'Author',
                                            ),
                                    ),
                                'title' => 'Dashboard',
                            ),
                    ),
                'page_1' =>
                    array (
                        'display_options' =>
                            array (
                                'menu' =>
                                    array (
                                        'description' => 'Editorial manager dashboard, to manage content validity',
                                    ),
                            ),
                    ),
            ),
    )
);

$config_group->save(TRUE);