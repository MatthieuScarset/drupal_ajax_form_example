<?php

use Drupal\file\Entity\File;
global $base_url;
global $base_path;

\Drupal::service('module_installer')->install(array('linkit'), true);

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('linkit.linkit_profile.link');
$config->setData(array (
  'uuid' => '39a33c38-efc9-458f-9d49-e7c79217bd24',
  'langcode' => 'en',
  'status' => true,
  'dependencies' =>
    array (
      'module' =>
        array (
          0 => 'node',
          1 => 'oab_ckeditor',
        ),
    ),
  'id' => 'link',
  'label' => 'link',
  'description' => '',
  'attributes' =>
    array (
      'title' =>
        array (
          'id' => 'title',
          'weight' => -10,
          'settings' =>
            array (
              'automatic_title' => true,
            ),
        ),
      'target' =>
        array (
          'id' => 'target',
          'weight' => -9,
          'settings' =>
            array (
              'widget_type' => 'simple_checkbox',
            ),
        ),
      'classes' =>
        array (
          'id' => 'classes',
          'weight' => 0,
          'settings' =>
            array (
            ),
        ),
      'id' =>
        array (
          'id' => 'id',
          'weight' => 0,
          'settings' =>
            array (
            ),
        ),
      'onmousedown' =>
        array (
          'id' => 'onmousedown',
          'weight' => 0,
          'settings' =>
            array (
            ),
        ),
      'styles' =>
        array (
          'id' => 'styles',
          'weight' => 0,
          'settings' =>
            array (
            ),
        ),
    ),
  'matchers' =>
    array (
      'e0f07df4-3d43-4e77-bd0b-d5160cd82af5' =>
        array (
          'uuid' => 'e0f07df4-3d43-4e77-bd0b-d5160cd82af5',
          'id' => 'entity:node',
          'weight' => 0,
          'settings' =>
            array (
              'result_description' => '',
              'bundles' =>
                array (
                  'container' => 'container',
                  'office' => 'office',
                  'profil_redacteur' => 'profil_redacteur',
                ),
              'group_by_bundle' => true,
              'include_unpublished' => false,
            ),
        ),
    ),
));
$config->save(TRUE);


$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');
$config->setData(array (
  'uuid' => 'cf04fad0-354b-4937-8f05-5e173e8a060c',
  'langcode' => 'fr',
  'status' => true,
  'dependencies' =>
    array (
      'config' =>
        array (
          0 => 'filter.format.full_html',
        ),
      'module' =>
        array (
          0 => 'ckeditor',
        ),
    ),
  '_core' =>
    array (
      'default_config_hash' => '967ijj7p6i7rwrYl7r08WQFeCY_c23YAh0h8u-w_CXM',
    ),
  'format' => 'full_html',
  'editor' => 'ckeditor',
  'settings' =>
    array (
      'toolbar' =>
        array (
          'rows' =>
            array (
              0 =>
                array (
                  0 =>
                    array (
                      'name' => 'Formatting',
                      'items' =>
                        array (
                          0 => 'Bold',
                          1 => 'Italic',
                          2 => 'Underline',
                          3 => '-',
                          4 => 'RemoveFormat',
                          5 => 'Styles',
                          6 => 'JustifyLeft',
                          7 => 'JustifyCenter',
                          8 => 'JustifyRight',
                          9 => 'JustifyBlock',
                          10 => 'Undo',
                          11 => 'Redo',
                        ),
                    ),
                  1 =>
                    array (
                      'name' => 'Linking',
                      'items' =>
                        array (
                          0 => 'Linkit',
                          1 => 'DrupalUnlink',
                        ),
                    ),
                  2 =>
                    array (
                      'name' => 'Lists',
                      'items' =>
                        array (
                          0 => 'BulletedList',
                        ),
                    ),
                  3 =>
                    array (
                      'name' => 'Media',
                      'items' =>
                        array (
                          0 => 'Blockquote',
                          1 => 'media_browser',
                          2 => 'Table',
                          3 => 'HorizontalRule',
                        ),
                    ),
                  4 =>
                    array (
                      'name' => 'Tools',
                      'items' =>
                        array (
                          0 => 'FontAwesome',
                          1 => 'Templates',
                          2 => 'ShowBlocks',
                          3 => 'Source',
                          4 => 'SpecialChar',
                          5 => 'Outdent',
                          6 => 'Cut',
                          7 => 'Copy',
                          8 => 'Indent',
                          9 => 'PasteFromWord',
                          10 => 'Maximize',
                        ),
                    ),
                ),
            ),
        ),
      'plugins' =>
        array (
          'language' =>
            array (
              'language_list' => 'un',
            ),
          'stylescombo' =>
            array (
              'styles' => 'div.titre1|titre 60pt
div.titre2|titre 50pt
div.titre3|titre 40pt
div.titre4|titre 34pt
div.titre5|titre 30pt
div.titre6|titre 24pt
div.titre7|titre 20pt
p.highlight1|paragraphe 18pt
p.highlight2|paragraphe 16pt
ul.orange|liste orange
ul.black|liste noire
ul.white|liste blanche
ul.grey|liste grise
span.orange|texte orange
span.black|texte noir
span.white|texte blanc
span.blue|texte bleu',
            ),
          'linkit' =>
            array (
              'linkit_profile' => 'link',
            ),
        ),
    ),
  'image_upload' =>
    array (
      'status' => true,
      'scheme' => 'public',
      'directory' => 'inline-images',
      'max_size' => '',
      'max_dimensions' =>
        array (
          'width' => NULL,
          'height' => NULL,
        ),
    ),
));
$config->save(TRUE);


// bouton media embed
$data = file_get_contents(file_create_url(drupal_get_path('module', 'ckeditor') . '/js/plugins/drupalimage/icons/drupalimage.png'));
$file = file_save_data($data, 'public://drupalimage.png', FILE_EXISTS_REPLACE);

if (is_object($file)){
  $config_factory = \Drupal::configFactory();
  $config = $config_factory->getEditable('embed.button.media_browser');
  $config->setData(array (
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
            0 => 'entity_reference:entity_reference_entity_view',
          ),
        'entity_browser' => 'browse_medias_iframe',
        'entity_browser_settings' =>
          array (
            'display_review' => false,
          ),
      ),
    'icon_uuid' => $file->uuid(),
  ));
  $config->save(TRUE);
}

//throw new \Drupal\Core\Utility\UpdateException();