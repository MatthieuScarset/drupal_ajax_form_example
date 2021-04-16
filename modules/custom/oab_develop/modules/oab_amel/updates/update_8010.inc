<?php
// ajout du style d'image SUBHOME

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.subhome');
$config_group->setData(
    array (
        'uuid' => 'd8f41055-cce9-46ae-ab18-6e4407637b60',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'name' => 'subhome',
        'label' => 'Subhome',
        'effects' =>
            array (
                '4cb2e9ce-974c-45f1-b483-0a4c79ce49f9' =>
                    array (
                        'uuid' => '4cb2e9ce-974c-45f1-b483-0a4c79ce49f9',
                        'id' => 'image_scale',
                        'weight' => 1,
                        'data' =>
                            array (
                                'width' => 310,
                                'height' => 125,
                                'upscale' => true,
                            ),
                    ),
            ),
    )
);
$config_group->save(TRUE);



//Ajout du mode d'affichage Media : SUBHOME IMAGE
$config_group = $config_factory->getEditable('core.entity_view_mode.media.subhome_image');
$config_group->setData(
    array (
        'uuid' => 'e304983e-4c5e-4ed6-a81f-7b0fc1693b33',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'media_entity',
                    ),
            ),
        'id' => 'media.subhome_image',
        'label' => 'Subhome image',
        'targetEntityType' => 'media',
        'cache' => true,
    )
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_view_display.media.image.subhome_image');
$config_group->setData(
    array (
        'uuid' => '6a624993-d75c-43e4-a1be-9018451aa4c3',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.media.subhome_image',
                        1 => 'field.field.media.image.field_image',
                        2 => 'field.field.media.image.field_tags',
                        3 => 'field.field.media.image.field_thematic',
                        4 => 'image.style.subhome',
                        5 => 'media_entity.bundle.image',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                    ),
            ),
        'id' => 'media.image.subhome_image',
        'targetEntityType' => 'media',
        'bundle' => 'image',
        'mode' => 'subhome_image',
        'content' =>
            array (
                'field_image' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => 'subhome',
                                'image_link' => 'content',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_tags' => true,
                'field_thematic' => true,
                'langcode' => true,
                'name' => true,
                'thumbnail' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);





// ajout du style d'image Related Content

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('image.style.related_contents');
$config_group->setData(
    array (
        'uuid' => 'd008a6c5-67bb-4151-9428-aecd62ba49af',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
            ),
        'name' => 'related_contents',
        'label' => 'Related Contents',
        'effects' =>
            array (
                '64299098-90a4-4b7c-9a04-d6002a64f46b' =>
                    array (
                        'uuid' => '64299098-90a4-4b7c-9a04-d6002a64f46b',
                        'id' => 'image_scale',
                        'weight' => 1,
                        'data' =>
                            array (
                                'width' => 420,
                                'height' => 200,
                                'upscale' => true,
                            ),
                    ),
            ),
    )
);
$config_group->save(TRUE);



//Ajout du mode d'affichage Media : RELATED CONTENT IMAGE
$config_group = $config_factory->getEditable('core.entity_view_mode.media.related_content_image');
$config_group->setData(
    array (
        'uuid' => 'd7e714e2-575d-4961-a4ff-208f6fd293ca',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'media_entity',
                    ),
            ),
        'id' => 'media.related_content_image',
        'label' => 'Related Content Image',
        'targetEntityType' => 'media',
        'cache' => true,
    )
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('core.entity_view_display.media.image.related_content_image');
$config_group->setData(
    array (
        'uuid' => '54efbbf6-ee95-4dd6-94b4-6a40776e8874',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.media.related_content_image',
                        1 => 'field.field.media.image.field_image',
                        2 => 'field.field.media.image.field_tags',
                        3 => 'field.field.media.image.field_thematic',
                        4 => 'image.style.related_contents',
                        5 => 'media_entity.bundle.image',
                    ),
                'module' =>
                    array (
                        0 => 'image',
                    ),
            ),
        'id' => 'media.image.related_content_image',
        'targetEntityType' => 'media',
        'bundle' => 'image',
        'mode' => 'related_content_image',
        'content' =>
            array (
                'field_image' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'image_style' => 'related_contents',
                                'image_link' => 'content',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'image',
                    ),
            ),
        'hidden' =>
            array (
                'created' => true,
                'field_tags' => true,
                'field_thematic' => true,
                'langcode' => true,
                'name' => true,
                'thumbnail' => true,
                'uid' => true,
            ),
    )
);
$config_group->save(TRUE);






//Modification du rendu Related Content pour tous les type de contenu : utilisation du rendu Related Content pour l'image
//blog post
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);


//magazine
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);


//partenaire
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);

//cas client
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);

//communiqué de presse
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);


//dossier de presse
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);

//document
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);



//solution
$config_group = $config_factory->getEditable('core.entity_view_display.node.solution.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);



//industrie
$config_group = $config_factory->getEditable('core.entity_view_display.node.industry.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);


//region
$config_group = $config_factory->getEditable('core.entity_view_display.node.region.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);

//pays
$config_group = $config_factory->getEditable('core.entity_view_display.node.country.related_content');
$config_group->set('content.field_visual', array (
    'type' => 'entity_reference_entity_view',
    'weight' => 0,
    'label' => 'hidden',
    'settings' =>
        array (
            'view_mode' => 'related_content_image',
            'link' => false,
        ),
    'third_party_settings' =>
        array (
        ),
));
$config_group->save(TRUE);



/**
 * Nouveau mode d'affichage : SUBHOME + config pour les type de contenu
 */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_mode.node.subhome');
$config_group->setData(
    array (
        'uuid' => 'b8502f72-a1eb-40f1-a4bf-6929929e4bb4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'module' =>
                    array (
                        0 => 'node',
                    ),
            ),
        'id' => 'node.subhome',
        'label' => 'Subhome',
        'targetEntityType' => 'node',
        'cache' => true,
    )
);
$config_group->save(TRUE);

//Config de ce mode pour les types de contenus :

//MAGAZINES
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.magazine.subhome');
$config_group->setData(
    array (
        'uuid' => 'e820fc95-8456-426e-b3ae-59aba636352e',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
                        1 => 'field.field.node.magazine.field_content',
                        2 => 'field.field.node.magazine.field_content_owner',
                        3 => 'field.field.node.magazine.field_display_title',
                        4 => 'field.field.node.magazine.field_email_owner',
                        5 => 'field.field.node.magazine.field_end_date',
                        6 => 'field.field.node.magazine.field_highlight',
                        7 => 'field.field.node.magazine.field_industry',
                        8 => 'field.field.node.magazine.field_job_profile',
                        9 => 'field.field.node.magazine.field_market_segment',
                        10 => 'field.field.node.magazine.field_meta_description',
                        11 => 'field.field.node.magazine.field_meta_title',
                        12 => 'field.field.node.magazine.field_metatags',
                        13 => 'field.field.node.magazine.field_region',
                        14 => 'field.field.node.magazine.field_solution',
                        15 => 'field.field.node.magazine.field_start_date',
                        16 => 'field.field.node.magazine.field_subhome',
                        17 => 'field.field.node.magazine.field_visual',
                        18 => 'node.type.magazine',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.magazine.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'magazine',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_partner' =>
                    array (
                        'weight' => 8,
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
                'field_solution' =>
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
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.partner.subhome');
$config_group->setData(
    array (
        'uuid' => 'b4567a9d-c87f-4f95-851d-198c393408ab',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
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
        'id' => 'node.partner.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'partner',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_solution' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
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
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_partner_type' => true,
                'field_region' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);



//DOCUMENT

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.document.subhome');
$config_group->setData(
    array (
        'uuid' => '1c9fb3d3-3e32-4522-95aa-99e73cc671dc',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
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
                        0 => 'datetime',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.document.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'document',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_file' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 3,
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
                'field_solution' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 2,
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
                'field_start_date' =>
                    array (
                        'type' => 'datetime_default',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'format_type' => 'medium',
                                'timezone_override' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
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
$config_group = $config_factory->getEditable('core.entity_view_display.node.customer_story.subhome');
$config_group->setData(
    array (
        'uuid' => 'b5275f70-76f5-40fa-a3ce-9b76cd9c30dc',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
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
        'id' => 'node.customer_story.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'customer_story',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_solution' =>
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
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_start_date' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);

//COMMUNIQUE DE PRESSE

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_release.subhome');
$config_group->setData(
    array (
        'uuid' => '875dca0c-ffff-4ebe-a7d2-1ce9057338a4',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
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
                        0 => 'datetime',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.press_release.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'press_release',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_file' =>
                    array (
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'link' => true,
                                'view_mode' => 'default',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'entity_reference_entity_view',
                    ),
                'field_start_date' =>
                    array (
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'format_type' => 'medium',
                                'timezone_override' => '',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                        'type' => 'datetime_default',
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
            ),
    )
);
$config_group->save(TRUE);


//DOSSIER DE PRESSE

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.press_kit.subhome');
$config_group->setData(
    array (
        'uuid' => '7be68e52-1263-4623-adfb-16fe4e7efd0e',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
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
                        0 => 'datetime',
                        1 => 'user',
                    ),
            ),
        'id' => 'node.press_kit.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'press_kit',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_file' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
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
                'field_start_date' =>
                    array (
                        'type' => 'datetime_default',
                        'weight' => 2,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'timezone_override' => '',
                                'format_type' => 'medium',
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
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
                'field_highlight' => true,
                'field_industry' => true,
                'field_job_profile' => true,
                'field_market_segment' => true,
                'field_meta_description' => true,
                'field_meta_title' => true,
                'field_metatags' => true,
                'field_region' => true,
                'field_solution' => true,
                'field_subhome' => true,
                'langcode' => true,
                'links' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);



//BLOG POST

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('core.entity_view_display.node.blog_post.subhome');
$config_group->setData(
    array (
        'uuid' => '081a6208-fadb-4086-8ff2-d20d83fe8213',
        'langcode' => 'en',
        'status' => true,
        'dependencies' =>
            array (
                'config' =>
                    array (
                        0 => 'core.entity_view_mode.node.subhome',
                        1 => 'field.field.node.blog_post.field_content',
                        2 => 'field.field.node.blog_post.field_content_owner',
                        3 => 'field.field.node.blog_post.field_display_title',
                        4 => 'field.field.node.blog_post.field_email_owner',
                        5 => 'field.field.node.blog_post.field_end_date',
                        6 => 'field.field.node.blog_post.field_highlight',
                        7 => 'field.field.node.blog_post.field_industry',
                        8 => 'field.field.node.blog_post.field_job_profile',
                        9 => 'field.field.node.blog_post.field_market_segment',
                        10 => 'field.field.node.blog_post.field_meta_description',
                        11 => 'field.field.node.blog_post.field_meta_title',
                        12 => 'field.field.node.blog_post.field_metatags',
                        13 => 'field.field.node.blog_post.field_profile',
                        14 => 'field.field.node.blog_post.field_region',
                        15 => 'field.field.node.blog_post.field_solution',
                        16 => 'field.field.node.blog_post.field_start_date',
                        17 => 'field.field.node.blog_post.field_subhome',
                        18 => 'field.field.node.blog_post.field_visual',
                        19 => 'field.field.node.blog_post.publish_date',
                        20 => 'field.field.node.blog_post.unpublish_date',
                        21 => 'node.type.blog_post',
                    ),
                'module' =>
                    array (
                        0 => 'user',
                    ),
            ),
        'id' => 'node.blog_post.subhome',
        'targetEntityType' => 'node',
        'bundle' => 'blog_post',
        'mode' => 'subhome',
        'content' =>
            array (
                'field_profile' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 2,
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
                'field_visual' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 0,
                        'label' => 'hidden',
                        'settings' =>
                            array (
                                'view_mode' => 'subhome_image',
                                'link' => false,
                            ),
                        'third_party_settings' =>
                            array (
                            ),
                    ),
                'publish_date' =>
                    array (
                        'type' => 'entity_reference_entity_view',
                        'weight' => 1,
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
                'field_highlight' => true,
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
                'unpublish_date' => true,
                'workbench_moderation_control' => true,
            ),
    )
);
$config_group->save(TRUE);




