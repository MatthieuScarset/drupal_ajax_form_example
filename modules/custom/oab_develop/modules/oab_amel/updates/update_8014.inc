<?php
use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('editor.editor.full_html');
$config->set('settings', array (
    'toolbar' =>
        array (
            'rows' =>
                array (
                    0 =>
                        array (
                            0 =>
                                array (
                                    'name' => 'Plugins',
                                    'items' =>
                                        array (
                                            0 => 'Styles',
                                            1 => 'Templating',
                                            2 => 'Solaris',
                                            3 => 'Templates',
                                        ),
                                ),
                            1 =>
                                array (
                                    'name' => 'Formatting',
                                    'items' =>
                                        array (
                                            0 => 'Bold',
                                            1 => 'Italic',
                                            2 => 'Underline',
                                            3 => '-',
                                            4 => 'RemoveFormat',
                                            5 => 'Blockquote',
                                            6 => '-',
                                            7 => 'media_browser',
                                            8 => 'Table',
                                            9 => 'HorizontalRule',
                                            10 => 'BulletedList',
                                            11 => 'SpecialChar',
                                            12 => '-',
                                            13 => 'Indent',
                                            14 => 'Outdent',
                                            15 => '-',
                                            16 => 'JustifyLeft',
                                            17 => 'JustifyCenter',
                                            18 => 'JustifyRight',
                                            19 => 'JustifyBlock',
                                            20 => '-',
                                            21 => 'Undo',
                                            22 => 'Redo',
                                        ),
                                ),
                            2 =>
                                array (
                                    'name' => 'Linking',
                                    'items' =>
                                        array (
                                            0 => 'Linkit',
                                            1 => 'DrupalUnlink',
                                        ),
                                ),
                            3 =>
                                array (
                                    'name' => 'Tools',
                                    'items' =>
                                        array (
                                            0 => 'ShowBlocks',
                                            1 => 'Source',
                                            2 => 'PasteFromWord',
                                            3 => 'Maximize',
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
                    'styles' => "  h1.titre1|titre             
                                h2.titre2|intertitre
                                div.titre3|chapô
                                h3.titre4|sous titre
                                p.highlight1|paragraphe
                                p.date|date
                                p.insight_banniere|insight bannière                                                              
                                ul.orange|liste orange
                                ul.black|liste noire
                                ul.white|liste blanche
                                ul.grey|liste grise
                                span.downloadPDF|download PDF  
                                span.orange|texte orange
                                span.black|texte noir
                                span.white|texte blanc
                                span.blue|texte bleu"
                ),
            'linkit' =>
                array (
                    'linkit_profile' => 'link',
                ),
        ),
/*
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
        ),*/
));
$config->save(TRUE);


