<?php
/**
 * Nouveau mode d'affichage : related_content + config pour les type de contenu
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.node.related_content');
$config_group->setData(
    array (
        'uuid' => '5d06c143-1001-40b9-8668-23177b40252c',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                    ),
            ),
        'id' => 'node.related_content',
        'label' => 'Related Content',
        'targetEntityType' => 'node',
        'cache' => true,
    )
);
$config_group->save(TRUE);




//Config de ce mode pour les types de contenus :

//MAGAZINES
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.related_content');
$config_group->setData(
        array (
            'uuid' => 'c73271d5-589f-4105-91cc-d62ae85e15bc',
            'langcode' => 'en',
            'status' => true,
            'dependencies' =>
                array (
                    'config' =>
                        array (
                            0 => 'core.entity_view_mode.node.related_content',
                            1 => 'field.field.node.magazine.field_content',
                            2 => 'field.field.node.magazine.field_content_owner',
                            3 => 'field.field.node.magazine.field_customer_story',
                            4 => 'field.field.node.magazine.field_display_title',
                            5 => 'field.field.node.magazine.field_email_owner',
                            6 => 'field.field.node.magazine.field_end_date',
                            7 => 'field.field.node.magazine.field_highlight',
                            8 => 'field.field.node.magazine.field_industry',
                            9 => 'field.field.node.magazine.field_meta_description',
                            10 => 'field.field.node.magazine.field_meta_title',
                            11 => 'field.field.node.magazine.field_metatags',
                            12 => 'field.field.node.magazine.field_partner',
                            13 => 'field.field.node.magazine.field_solution',
                            14 => 'field.field.node.magazine.field_start_date',
                            15 => 'field.field.node.magazine.field_subhome',
                            16 => 'field.field.node.magazine.field_visual',
                            17 => 'node.type.magazine',
                        ),
                    'module' =>
                        array (
                            0 => 'user',
                        ),
                ),
            'id' => 'node.magazine.related_content',
            'targetEntityType' => 'node',
            'bundle' => 'magazine',
            'mode' => 'related_content',
            'content' =>
                array (
                    'field_highlight' =>
                        array (
                            'weight' => 1,
                            'label' => 'hidden',
                            'settings' =>
                                array (
                                ),
                            'third_party_settings' =>
                                array (
                                ),
                            'type' => 'basic_string',
                        ),
                    'field_visual' =>
                        array (
                            'type' => 'entity_reference_entity_view',
                            'weight' => 0,
                            'label' => 'hidden',
                            'settings' =>
                                array (
                                    'view_mode' => 'default',
                                    'link' => false,
                                ),
                            'third_party_settings' =>
                                array (
                                ),
                        ),
                ),
            'hidden' =>
                array (
                    'field_content' => true,
                    'field_content_owner' => true,
                    'field_customer_story' => true,
                    'field_display_title' => true,
                    'field_email_owner' => true,
                    'field_end_date' => true,
                    'field_industry' => true,
                    'field_meta_description' => true,
                    'field_meta_title' => true,
                    'field_metatags' => true,
                    'field_partner' => true,
                    'field_solution' => true,
                    'field_start_date' => true,
                    'field_subhome' => true,
                    'langcode' => true,
                    'links' => true,
                    'workbench_moderation_control' => true,
                ),
        )
);
$config_group->save(TRUE);

//PARTENAIRE
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.related_content');
$config_group->setData(
    array (
        'uuid' => 'acdb4902-d589-4502-8748-755cb513cbbd',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.partner.field_content',
                        2 => 'field.field.node.partner.field_content_owner',
                        3 => 'field.field.node.partner.field_display_title',
                        4 => 'field.field.node.partner.field_email_owner',
                        5 => 'field.field.node.partner.field_end_date',
                        6 => 'field.field.node.partner.field_file',
                        7 => 'field.field.node.partner.field_highlight',
                        8 => 'field.field.node.partner.field_industry',
                        9 => 'field.field.node.partner.field_meta_description',
                        10 => 'field.field.node.partner.field_meta_title',
                        11 => 'field.field.node.partner.field_metatags',
                        12 => 'field.field.node.partner.field_partner_type',
                        13 => 'field.field.node.partner.field_region',
                        14 => 'field.field.node.partner.field_solution',
                        15 => 'field.field.node.partner.field_start_date',
                        16 => 'field.field.node.partner.field_subhome',
                        17 => 'field.field.node.partner.field_visual',
                        18 => 'node.type.partner',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.partner.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'partner',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_partner' =>
                    array (
                        'weight' => 10,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_label',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_file' => true,
                'field_industry' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_partner_type' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

//INDUSTRIE

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.related_content');
$config_group->setData(
    array (
        'uuid' => '1c5ad6a4-3f5f-4fb1-952c-2e85a0ccce0b',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.industry.field_content_owner',
                        2 => 'field.field.node.industry.field_email_owner',
                        3 => 'field.field.node.industry.field_end_date',
                        4 => 'field.field.node.industry.field_highlight',
                        5 => 'field.field.node.industry.field_industry',
                        6 => 'field.field.node.industry.field_start_date',
                        7 => 'field.field.node.industry.field_visual',
                        8 => 'node.type.industry',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.industry.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'industry',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content_owner' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_industry' => true,
                'field_start_date' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

//DOCUMENT

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.related_content');
$config_group->setData(
    array (
        'uuid' => 'fce1ee2d-391f-4a6c-9054-87ee68ef0eff',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.document.field_content',
                        2 => 'field.field.node.document.field_content_owner',
                        3 => 'field.field.node.document.field_display_title',
                        4 => 'field.field.node.document.field_document_type',
                        5 => 'field.field.node.document.field_email_owner',
                        6 => 'field.field.node.document.field_end_date',
                        7 => 'field.field.node.document.field_file',
                        8 => 'field.field.node.document.field_highlight',
                        9 => 'field.field.node.document.field_industry',
                        10 => 'field.field.node.document.field_job_profile',
                        11 => 'field.field.node.document.field_market_segment',
                        12 => 'field.field.node.document.field_meta_description',
                        13 => 'field.field.node.document.field_meta_title',
                        14 => 'field.field.node.document.field_metatags',
                        15 => 'field.field.node.document.field_region',
                        16 => 'field.field.node.document.field_solution',
                        17 => 'field.field.node.document.field_start_date',
                        18 => 'field.field.node.document.field_subhome',
                        19 => 'field.field.node.document.field_visual',
                        20 => 'node.type.document',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.document.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'document',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_document_type' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_file' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);


//CUSTOMER STORY

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.related_content');
$config_group->setData(
    array (
        'uuid' => '680967c5-30cc-4478-984e-a1e27ff778ac',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.customer_story.field_content',
                        2 => 'field.field.node.customer_story.field_content_owner',
                        3 => 'field.field.node.customer_story.field_display_title',
                        4 => 'field.field.node.customer_story.field_email_owner',
                        5 => 'field.field.node.customer_story.field_end_date',
                        6 => 'field.field.node.customer_story.field_file',
                        7 => 'field.field.node.customer_story.field_highlight',
                        8 => 'field.field.node.customer_story.field_industry',
                        9 => 'field.field.node.customer_story.field_job_profile',
                        10 => 'field.field.node.customer_story.field_market_segment',
                        11 => 'field.field.node.customer_story.field_meta_description',
                        12 => 'field.field.node.customer_story.field_meta_title',
                        13 => 'field.field.node.customer_story.field_metatags',
                        14 => 'field.field.node.customer_story.field_region',
                        15 => 'field.field.node.customer_story.field_solution',
                        16 => 'field.field.node.customer_story.field_start_date',
                        17 => 'field.field.node.customer_story.field_subhome',
                        18 => 'field.field.node.customer_story.field_visual',
                        19 => 'node.type.customer_story',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.customer_story.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'customer_story',
        'mode' => 'related_content',
        'content' =>
            array (

                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),

                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_file' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);


//COUNTRY

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.related_content');
$config_group->setData(
    array (
        'uuid' => '4cca6493-59ca-4387-aa18-d68e182f50da',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.country.field_content_owner',
                        2 => 'field.field.node.country.field_email_owner',
                        3 => 'field.field.node.country.field_end_date',
                        4 => 'field.field.node.country.field_highlight',
                        5 => 'field.field.node.country.field_start_date',
                        6 => 'field.field.node.country.field_visual',
                        7 => 'node.type.country',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.country.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'country',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content_owner' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_start_date' => true,
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(TRUE);


//SOLUTION

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.related_content');
$config_group->setData(
    array (
        'uuid' => '338aec56-fb47-4e6a-88dd-58e8ba5fafe8',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.solution.field_content_owner',
                        2 => 'field.field.node.solution.field_email_owner',
                        3 => 'field.field.node.solution.field_end_date',
                        4 => 'field.field.node.solution.field_highlight',
                        5 => 'field.field.node.solution.field_solution',
                        6 => 'field.field.node.solution.field_start_date',
                        7 => 'field.field.node.solution.field_visual',
                        8 => 'node.type.solution',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.solution.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'solution',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content_owner' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);


//REGION

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.related_content');
$config_group->setData(
    array (
        'uuid' => '23d6003f-8afc-4f8a-87f0-43f505b02028',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.region.field_content_owner',
                        2 => 'field.field.node.region.field_email_owner',
                        3 => 'field.field.node.region.field_end_date',
                        4 => 'field.field.node.region.field_highlight',
                        5 => 'field.field.node.region.field_region',
                        6 => 'field.field.node.region.field_start_date',
                        7 => 'field.field.node.region.field_visual',
                        8 => 'node.type.region',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.region.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'region',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content_owner' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_region' => true,
                'field_start_date' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

//COMMUNIQUE DE PRESSE

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.related_content');
$config_group->setData(
    array (
        'uuid' => 'e5d97805-ebc0-49e5-86b4-94928f9c119d',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.press_release.field_city',
                        2 => 'field.field.node.press_release.field_content',
                        3 => 'field.field.node.press_release.field_content_owner',
                        4 => 'field.field.node.press_release.field_country',
                        5 => 'field.field.node.press_release.field_display_title',
                        6 => 'field.field.node.press_release.field_email_owner',
                        7 => 'field.field.node.press_release.field_end_date',
                        8 => 'field.field.node.press_release.field_file',
                        9 => 'field.field.node.press_release.field_highlight',
                        10 => 'field.field.node.press_release.field_industry',
                        11 => 'field.field.node.press_release.field_job_profile',
                        12 => 'field.field.node.press_release.field_market_segment',
                        13 => 'field.field.node.press_release.field_meta_description',
                        14 => 'field.field.node.press_release.field_meta_title',
                        15 => 'field.field.node.press_release.field_metatags',
                        16 => 'field.field.node.press_release.field_region',
                        17 => 'field.field.node.press_release.field_solution',
                        18 => 'field.field.node.press_release.field_start_date',
                        19 => 'field.field.node.press_release.field_subhome',
                        20 => 'field.field.node.press_release.field_visual',
                        21 => 'node.type.press_release',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.press_release.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'press_release',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),

                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_city' => true,
                'field_content' => true,
                'field_content_owner' => true,
                'field_country' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_file' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(TRUE);


//DOSSIER PRESSE (PRESS KIT)

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.related_content');
$config_group->setData(
    array (
        'uuid' => 'daebe028-50a0-4aab-8c91-4df2766af0f5',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.press_kit.field_content',
                        2 => 'field.field.node.press_kit.field_content_owner',
                        3 => 'field.field.node.press_kit.field_display_title',
                        4 => 'field.field.node.press_kit.field_email_owner',
                        5 => 'field.field.node.press_kit.field_end_date',
                        6 => 'field.field.node.press_kit.field_file',
                        7 => 'field.field.node.press_kit.field_highlight',
                        8 => 'field.field.node.press_kit.field_industry',
                        9 => 'field.field.node.press_kit.field_job_profile',
                        10 => 'field.field.node.press_kit.field_market_segment',
                        11 => 'field.field.node.press_kit.field_meta_description',
                        12 => 'field.field.node.press_kit.field_meta_title',
                        13 => 'field.field.node.press_kit.field_metatags',
                        14 => 'field.field.node.press_kit.field_region',
                        15 => 'field.field.node.press_kit.field_solution',
                        16 => 'field.field.node.press_kit.field_start_date',
                        17 => 'field.field.node.press_kit.field_subhome',
                        18 => 'field.field.node.press_kit.field_visual',
                        19 => 'node.type.press_kit',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.press_kit.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'press_kit',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'default',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_content' => true,
                'field_content_owner' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_file' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.related_content');
$config_group->setData(
    array (
        'uuid' => 'b4cce3c8-9044-4f87-8bcf-8472f9dd91cb',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'field.field.node.blog_post.field_area',
                        2 => 'field.field.node.blog_post.field_blog',
                        3 => 'field.field.node.blog_post.field_content',
                        4 => 'field.field.node.blog_post.field_content_owner',
                        5 => 'field.field.node.blog_post.field_customer_story',
                        6 => 'field.field.node.blog_post.field_display_title',
                        7 => 'field.field.node.blog_post.field_email_owner',
                        8 => 'field.field.node.blog_post.field_end_date',
                        9 => 'field.field.node.blog_post.field_highlight',
                        10 => 'field.field.node.blog_post.field_industry',
                        11 => 'field.field.node.blog_post.field_meta_description',
                        12 => 'field.field.node.blog_post.field_meta_title',
                        13 => 'field.field.node.blog_post.field_metatags',
                        14 => 'field.field.node.blog_post.field_partner',
                        15 => 'field.field.node.blog_post.field_profile',
                        16 => 'field.field.node.blog_post.field_solution',
                        17 => 'field.field.node.blog_post.field_start_date',
                        18 => 'field.field.node.blog_post.field_subhome',
                        19 => 'field.field.node.blog_post.field_visual',
                        20 => 'field.field.node.blog_post.publish_date',
                        21 => 'field.field.node.blog_post.unpublish_date',
                        22 => 'node.type.blog_post',
                    ),
                'module' =>
                    array (
                        0 => 'media_entity',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.blog_post.related_content',
        'targetEntityType' => 'node',
        'bundle' => 'blog_post',
        'mode' => 'related_content',
        'content' =>
            array (
                'field_highlight' =>
                    array (
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'basic_string',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'media_thumbnail',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => '',
                                'image_link' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
            ),
        'hidden' =>
            array (
                'field_area' => true,
                'field_blog' => true,
                'field_content' => true,
                'field_content_owner' => true,
                'field_customer_story' => true,
                'field_display_title' => true,
                'field_email_owner' => true,
                'field_end_date' => true,
                'field_industry' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_partner' => true,
                'field_profile' => true,
                'field_solution' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'publish_date' => true,
                'unpublish_date' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);



/**
 * Ajout nouvelle vue Right Linked Content + placement du bloc
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('views.view.related_contents');
$config_group->setData(
    array (
        'uuid' => '4704129d-4be6-4a15-8e71-0636a1fa0bc1',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.related_content',
                        1 => 'node.type.blog_post',
                        2 => 'node.type.customer_story',
                        3 => 'node.type.document',
                        4 => 'node.type.industry',
                        5 => 'node.type.magazine',
                        6 => 'node.type.partner',
                        7 => 'node.type.press_kit',
                        8 => 'node.type.press_release',
                        9 => 'node.type.product',
                        10 => 'node.type.region',
                        11 => 'node.type.simple_page',
                        12 => 'node.type.solution',
                    ),
                'module' =>
                    array (
                        0 => 'node',
                        1 => 'user',
                    ),
            ),
        'id' => 'related_contents',
        'label' => 'Related Contents',
        'module' => 'views',
        'description' => '',
        'tag' => '',
        'base_table' => 'node_field_data',
        'base_field' => 'nid',
        'core' => '8.x',
        'display' =>
            array (
                'default' =>
                    array (
                        'display_plugin' => 'default',
                        'id' => 'default',
                        'display_title' => 'Master',
                        'position' => 0,
                        'display_options' =>
                            array (
                                'access' =>
                                    array (
                                        'type' => 'perm',
                                        'options' =>
                                            array (
                                                'perm' => 'access content',
                                            ),
                                    ),
                                'cache' =>
                                    array (
                                        'type' => 'tag',
                                        'options' =>
                                            array (
                                            ),
                                    ),
                                'query' =>
                                    array (
                                        'type' => 'views_query',
                                        'options' =>
                                            array (
                                                'disable_sql_rewrite' => false,
                                                'distinct' => false,
                                                'replica' => false,
                                                'query_comment' => '',
                                                'query_tags' =>
                                                    array (
                                                    ),
                                            ),
                                    ),
                                'exposed_form' =>
                                    array (
                                        'type' => 'basic',
                                        'options' =>
                                            array (
                                                'submit_button' => 'Apply',
                                                'reset_button' => false,
                                                'reset_button_label' => 'Reset',
                                                'exposed_sorts_label' => 'Sort by',
                                                'expose_sort_order' => true,
                                                'sort_asc_label' => 'Asc',
                                                'sort_desc_label' => 'Desc',
                                            ),
                                    ),
                                'pager' =>
                                    array (
                                        'type' => 'some',
                                        'options' =>
                                            array (
                                                'items_per_page' => 3,
                                                'offset' => 0,
                                            ),
                                    ),
                                'style' =>
                                    array (
                                        'type' => 'grid',
                                        'options' =>
                                            array (
                                                'uses_fields' => false,
                                                'columns' => 3,
                                                'automatic_width' => true,
                                                'alignment' => 'horizontal',
                                                'col_class_default' => true,
                                                'col_class_custom' => '',
                                                'row_class_default' => true,
                                                'row_class_custom' => '',
                                            ),
                                    ),
                                'row' =>
                                    array (
                                        'type' => 'entity:node',
                                        'options' =>
                                            array (
                                                'relationship' => 'none',
                                                'view_mode' => 'related_content',
                                            ),
                                    ),
                                'fields' =>
                                    array (
                                        'title' =>
                                            array (
                                                'id' => 'title',
                                                'table' => 'node_field_data',
                                                'field' => 'title',
                                                'entity_type' => 'node',
                                                'entity_field' => 'title',
                                                'label' => '',
                                                'alter' =>
                                                    array (
                                                        'alter_text' => false,
                                                        'make_link' => false,
                                                        'absolute' => false,
                                                        'trim' => false,
                                                        'word_boundary' => false,
                                                        'ellipsis' => false,
                                                        'strip_tags' => false,
                                                        'html' => false,
                                                    ),
                                                'hide_empty' => false,
                                                'empty_zero' => false,
                                                'settings' =>
                                                    array (
                                                        'link_to_entity' => true,
                                                    ),
                                                'plugin_id' => 'field',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'exclude' => false,
                                                'element_type' => '',
                                                'element_class' => '',
                                                'element_label_type' => '',
                                                'element_label_class' => '',
                                                'element_label_colon' => true,
                                                'element_wrapper_type' => '',
                                                'element_wrapper_class' => '',
                                                'element_default_classes' => true,
                                                'empty' => '',
                                                'hide_alter_empty' => true,
                                                'click_sort_column' => 'value',
                                                'type' => 'string',
                                                'group_column' => 'value',
                                                'group_columns' =>
                                                    array (
                                                    ),
                                                'group_rows' => true,
                                                'delta_limit' => 0,
                                                'delta_offset' => 0,
                                                'delta_reversed' => false,
                                                'delta_first_last' => false,
                                                'multi_type' => 'separator',
                                                'separator' => ', ',
                                                'field_api_classes' => false,
                                            ),
                                    ),
                                'filters' =>
                                    array (
                                        'status' =>
                                            array (
                                                'value' => '1',
                                                'table' => 'node_field_data',
                                                'field' => 'status',
                                                'plugin_id' => 'boolean',
                                                'entity_type' => 'node',
                                                'entity_field' => 'status',
                                                'id' => 'status',
                                                'expose' =>
                                                    array (
                                                        'operator' => '',
                                                    ),
                                                'group' => 1,
                                            ),
                                        'type' =>
                                            array (
                                                'id' => 'type',
                                                'table' => 'node_field_data',
                                                'field' => 'type',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'operator' => 'in',
                                                'value' =>
                                                    array (
                                                        'blog_post' => 'blog_post',
                                                        'customer_story' => 'customer_story',
                                                        'press_release' => 'press_release',
                                                        'document' => 'document',
                                                        'press_kit' => 'press_kit',
                                                        'industry' => 'industry',
                                                        'magazine' => 'magazine',
                                                        'simple_page' => 'simple_page',
                                                        'partner' => 'partner',
                                                        'product' => 'product',
                                                        'region' => 'region',
                                                        'solution' => 'solution',
                                                    ),
                                                'group' => 1,
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'operator_id' => '',
                                                        'label' => '',
                                                        'description' => '',
                                                        'use_operator' => false,
                                                        'operator' => '',
                                                        'identifier' => '',
                                                        'required' => false,
                                                        'remember' => false,
                                                        'multiple' => false,
                                                        'remember_roles' =>
                                                            array (
                                                                'authenticated' => 'authenticated',
                                                            ),
                                                        'reduce' => false,
                                                    ),
                                                'is_grouped' => false,
                                                'group_info' =>
                                                    array (
                                                        'label' => '',
                                                        'description' => '',
                                                        'identifier' => '',
                                                        'optional' => true,
                                                        'widget' => 'select',
                                                        'multiple' => false,
                                                        'remember' => false,
                                                        'default_group' => 'All',
                                                        'default_group_multiple' =>
                                                            array (
                                                            ),
                                                        'group_items' =>
                                                            array (
                                                            ),
                                                    ),
                                                'entity_type' => 'node',
                                                'entity_field' => 'type',
                                                'plugin_id' => 'bundle',
                                            ),
                                    ),
                                'sorts' =>
                                    array (
                                        'changed' =>
                                            array (
                                                'id' => 'changed',
                                                'table' => 'node_field_data',
                                                'field' => 'changed',
                                                'relationship' => 'none',
                                                'group_type' => 'group',
                                                'admin_label' => '',
                                                'order' => 'DESC',
                                                'exposed' => false,
                                                'expose' =>
                                                    array (
                                                        'label' => '',
                                                    ),
                                                'granularity' => 'second',
                                                'entity_type' => 'node',
                                                'entity_field' => 'changed',
                                                'plugin_id' => 'date',
                                            ),
                                    ),
                                'title' => 'Related Contents',
                                'header' =>
                                    array (
                                    ),
                                'footer' =>
                                    array (
                                    ),
                                'empty' =>
                                    array (
                                    ),
                                'relationships' =>
                                    array (
                                    ),
                                'arguments' =>
                                    array (
                                    ),
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'user.node_grants:view',
                                        3 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                    ),
                            ),
                    ),
                'block_1' =>
                    array (
                        'display_plugin' => 'block',
                        'id' => 'block_1',
                        'display_title' => 'Block',
                        'position' => 1,
                        'display_options' =>
                            array (
                                'display_extenders' =>
                                    array (
                                    ),
                            ),
                        'cache_metadata' =>
                            array (
                                'max-age' => -1,
                                'contexts' =>
                                    array (
                                        0 => 'languages:language_content',
                                        1 => 'languages:language_interface',
                                        2 => 'user.node_grants:view',
                                        3 => 'user.permissions',
                                    ),
                                'tags' =>
                                    array (
                                    ),
                            ),
                    ),
            ),
    )
);
$config_group->save(TRUE);

/**
 * config du block
 */

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.views_block__related_contents_block_1');
$config_group->setData(
    array (
        'uuid' => '2ec9a66b-2f76-4c6d-aec2-4a10bc1f57f0',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'views.view.related_contents',
                    ),
                'module' =>
                    array (
                        0 => 'ctools',
                        1 => 'views',
                    ),
                'theme' =>
                    array (
                        0 => 'theme_boosted',
                    ),
            ),
        'id' => 'views_block__related_contents_block_1',
        'theme' => 'theme_boosted',
        'region' => 'prefooter',
        'weight' => -18,
        'provider' => NULL,
        'plugin' => 'views_block:related_contents-block_1',
        'settings' =>
            array (
                'id' => 'views_block:related_contents-block_1',
                'label' => '',
                'provider' => 'views',
                'label_display' => '0',
                'views_label' => '',
                'items_per_page' => 'none',
            ),
        'visibility' =>
            array (
                'entity_bundle:node' =>
                    array (
                        'id' => 'entity_bundle:node',
                        'bundles' =>
                            array (
                                'blog_post' => 'blog_post',
                                'customer_story' => 'customer_story',
                                'document' => 'document',
                                'full_html' => 'full_html',
                                'industry' => 'industry',
                                'magazine' => 'magazine',
                                'partner' => 'partner',
                                'press_kit' => 'press_kit',
                                'press_release' => 'press_release',
                                'product' => 'product',
                                'region' => 'region',
                                'simple_page' => 'simple_page',
                                'solution' => 'solution',
                            ),
                        'negate' => false,
                        'context_mapping' =>
                            array (
                                'node' => '@node.node_route_context:node',
                            ),
                    ),
            ),
    )
);
$config_group->save(TRUE);

