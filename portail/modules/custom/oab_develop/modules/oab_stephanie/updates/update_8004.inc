<?php

use \Drupal\Core\Utility\UpdateException;

/**
 * Reconfiguration de la médiathèque suite aux update
 */

/*****************************
 * ACTIVATION CHAOS TOOLS
 *****************************/
if (! \Drupal::moduleHandler()->moduleExists('ctools')) {
  \Drupal::service('module_installer')->install(['ctools']);
}


/*****************************
 * filter.format.full_html
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('filter.format.full_html');
$config_group->setData(
              array (
                'uuid' => '8706a018-48c8-4f0b-a400-b316f7fec293',
                'langcode' => 'fr',
                'status' => true,
                'dependencies' =>
                  array (
                    'module' =>
                      array (
                        0 => 'editor',
                        1 => 'entity_embed',
                      ),
                  ),
                '_core' =>
                  array (
                    'default_config_hash' => 'hewPmBgni9jlDK_IjLxUx1HsTbinK-hdl0lOwjbteIY',
                  ),
                'name' => 'HTML complet',
                'format' => 'full_html',
                'weight' => -10,
                'filters' =>
                  array (
                    'filter_align' =>
                      array (
                        'id' => 'filter_align',
                        'provider' => 'filter',
                        'status' => true,
                        'weight' => 8,
                        'settings' =>
                          array (
                          ),
                      ),
                    'filter_caption' =>
                      array (
                        'id' => 'filter_caption',
                        'provider' => 'filter',
                        'status' => true,
                        'weight' => 9,
                        'settings' =>
                          array (
                          ),
                      ),
                    'editor_file_reference' =>
                      array (
                        'id' => 'editor_file_reference',
                        'provider' => 'editor',
                        'status' => true,
                        'weight' => 11,
                        'settings' =>
                          array (
                          ),
                      ),
                    'filter_html' =>
                      array (
                        'id' => 'filter_html',
                        'provider' => 'filter',
                        'status' => false,
                        'weight' => -10,
                        'settings' =>
                          array (
                            'allowed_html' => '<a hreflang href style class> <em> <strong> <cite> <blockquote cite> <code> <ul type> <ol type start> <li> <dl> <dt> <dd> <h2 id> <h3 id> <h4 id> <h5 id> <h6 id> <s> <sup> <sub> <img src alt data-entity-type data-entity-uuid data-align data-caption> <table> <caption> <tbody> <thead> <tfoot> <th> <td> <tr> <hr> <p class style> <h1> <pre> <div class style> <drupal-entity data-align data-embed-button data-entity-embed-display data-entity-embed-settings data-entity-id data-entity-label data-entity-type data-entity-uuid> <span class style> <i class style> <iframe width height frameborder src allowfullscreen> <article style class>',
                            'filter_html_help' => true,
                            'filter_html_nofollow' => false,
                          ),
                      ),
                    'filter_autop' =>
                      array (
                        'id' => 'filter_autop',
                        'provider' => 'filter',
                        'status' => true,
                        'weight' => 0,
                        'settings' =>
                          array (
                          ),
                      ),
                    'filter_url' =>
                      array (
                        'id' => 'filter_url',
                        'provider' => 'filter',
                        'status' => true,
                        'weight' => 0,
                        'settings' =>
                          array (
                            'filter_url_length' => 72,
                          ),
                      ),
                    'entity_embed' =>
                      array (
                        'id' => 'entity_embed',
                        'provider' => 'entity_embed',
                        'status' => true,
                        'weight' => 0,
                        'settings' =>
                          array (
                          ),
                      ),
                  ),
              ));
$config_group->save(TRUE);

/*****************************
 * media_entity.bundle.image
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('media_entity.bundle.image');
$config_group->setData(
                array (
                  'uuid' => 'd03cfdab-83fb-4592-9200-fb46bac9bbb3',
                  'langcode' => 'fr',
                  'status' => true,
                  'dependencies' =>
                    array (
                      'module' =>
                        array (
                          0 => 'media_entity_image',
                        ),
                    ),
                  'id' => 'image',
                  'label' => 'image',
                  'description' => '',
                  'type' => 'image',
                  'queue_thumbnail_downloads' => false,
                  'new_revision' => false,
                  'type_configuration' =>
                    array (
                      'source_field' => 'field_image',
                      'gather_exif' => false,
                    ),
                  'field_map' =>
                    array (
                    ),
                ));
$config_group->save(TRUE);


/*****************************
 * entity_browser.browser.browse_media_modal
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('entity_browser.browser.browse_media_modal');
$config_group->setData(
              array (
                'uuid' => 'b6c4c146-7bfc-4352-9208-8d0f91e00aae',
                'langcode' => 'und',
                'status' => true,
                'dependencies' =>
                  array (
                    'enforced' =>
                      array (
                        'module' =>
                          array (
                            0 => 'oab_media_browser',
                          ),
                      ),
                    'module' =>
                      array (
                        0 => 'entity_browser_entity_form',
                        1 => 'views',
                      ),
                  ),
                '_core' =>
                  array (
                    'default_config_hash' => 'mdUNatZ7S-c7XVDJ-ZivN7sKeRi7A4l9iN263Psv7GU',
                  ),
                'name' => 'browse_media_modal',
                'label' => 'Browser modal for medias',
                'display' => 'modal',
                'display_configuration' =>
                  array (
                    'widget_ids' =>
                      array (
                        '735d146c-a4b2-4327-a057-d109e0905e06' => 'Upload media',
                        'a4ad947c-9669-497c-9988-24351955a02f' => 'Medias listing',
                      ),
                    'width' => '',
                    'height' => '500',
                    'link_text' => 'Select medias',
                    'auto_open' => true,
                  ),
                'selection_display' => 'no_display',
                'selection_display_configuration' =>
                  array (
                    'view' => 'medias_entity_browser',
                    'view_display' => 'entity_browser_1',
                  ),
                'widget_selector' => 'tabs',
                'widget_selector_configuration' =>
                  array (
                  ),
                'widgets' =>
                  array (
                    'a4ad947c-9669-497c-9988-24351955a02f' =>
                      array (
                        'settings' =>
                          array (
                            'view' => 'medias_entity_browser',
                            'view_display' => 'entity_browser_1',
                          ),
                        'uuid' => 'a4ad947c-9669-497c-9988-24351955a02f',
                        'weight' => 1,
                        'label' => 'Medias listing',
                        'id' => 'view',
                      ),
                    '735d146c-a4b2-4327-a057-d109e0905e06' =>
                      array (
                        'settings' =>
                          array (
                            'entity_type' => 'media',
                            'bundle' => 'image',
                          ),
                        'uuid' => '735d146c-a4b2-4327-a057-d109e0905e06',
                        'weight' => 0,
                        'label' => 'Upload medias',
                        'id' => 'entity_form',
                      ),
                  ),
                'submit_text' => 'Select',
              )
);
$config_group->save(TRUE);


/*****************************
 * entity_browser.browser.browse_medias_iframe
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('entity_browser.browser.browse_medias_iframe');
$config_group->setData(
              array (
                'uuid' => 'e6d05d29-5b9e-4fa6-ba00-a815684d9bdb',
                'langcode' => 'und',
                'status' => true,
                'dependencies' =>
                  array (
                    'enforced' =>
                      array (
                        'module' =>
                          array (
                            0 => 'oab_media_browser',
                          ),
                      ),
                    'module' =>
                      array (
                        0 => 'entity_browser_entity_form',
                        1 => 'views',
                      ),
                  ),
                '_core' =>
                  array (
                    'default_config_hash' => 'Ue8A-OJls6HvSBav2bfwtUwPJLkMT8WjeLrW6DgU-9U',
                  ),
                'name' => 'browse_medias_iframe',
                'label' => 'Browser iframe for medias',
                'display' => 'iframe',
                'display_configuration' =>
                  array (
                    'widget_ids' =>
                      array (
                        '735d146c-a4b2-4327-a057-d109e0905e06' => 'Upload media',
                        'a4ad947c-9669-497c-9988-24351955a02f' => 'Medias listing',
                      ),
                    'width' => '1150',
                    'height' => '500',
                    'link_text' => 'Select medias',
                    'auto_open' => true,
                    'path' => '',
                  ),
                'selection_display' => 'no_display',
                'selection_display_configuration' =>
                  array (
                    'view' => 'medias_entity_browser',
                    'view_display' => 'entity_browser_1',
                  ),
                'widget_selector' => 'tabs',
                'widget_selector_configuration' =>
                  array (
                  ),
                'widgets' =>
                  array (
                    'a4ad947c-9669-497c-9988-24351955a02f' =>
                      array (
                        'settings' =>
                          array (
                            'view' => 'medias_entity_browser',
                            'view_display' => 'entity_browser_1',
                          ),
                        'uuid' => 'a4ad947c-9669-497c-9988-24351955a02f',
                        'weight' => 1,
                        'label' => 'Medias listing',
                        'id' => 'view',
                      ),
                    '735d146c-a4b2-4327-a057-d109e0905e06' =>
                      array (
                        'settings' =>
                          array (
                            'entity_type' => 'media',
                            'bundle' => 'image',
                          ),
                        'uuid' => '735d146c-a4b2-4327-a057-d109e0905e06',
                        'weight' => 0,
                        'label' => 'Upload media',
                        'id' => 'entity_form',
                      ),
                  ),
                'submit_text' => 'Select',
              )
);
$config_group->save(TRUE);


/*****************************
 * embed.button.media_browser
 *****************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('embed.button.media_browser');
$config_group->setData(
              array (
                'uuid' => 'b63f8494-e724-4200-9a14-203f7bb9420b',
                'langcode' => 'fr',
                'status' => true,
                'dependencies' =>
                  array (
                    'config' =>
                      array (
                        0 => 'media_entity.bundle.image',
                      ),
                    'module' =>
                      array (
                        0 => 'entity_embed',
                        1 => 'media_entity',
                        2 => 'oab_media_browser',
                      ),
                  ),
                '_core' =>
                  array (
                    'default_config_hash' => '2LD3MU__1jH7WAgvnKLeujY_JFBy5gUEGKkDy_FRSCk',
                  ),
                'label' => 'Media Browser',
                'id' => 'media_browser',
                'type_id' => 'entity',
                'type_settings' =>
                  array (
                    'entity_type' => 'media',
                    'bundles' =>
                      array (
                        0 => 'image',
                      ),
                    'display_plugins' =>
                      array (
                        0 => 'entity_reference:entity_reference_image',
                      ),
                    'entity_browser' => 'browse_medias_iframe',
                    'entity_browser_settings' =>
                      array (
                        'display_review' => 'd6282434-0513-4c98-bc46-709db58e9813',
                      ),
                  ),
                'icon_uuid' => NULL,
              )
);
$config_group->save(TRUE);

return '';
//throw new UpdateException();