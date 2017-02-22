<?php

use \Drupal\Core\Utility\UpdateException;

$config_factory = \Drupal::configFactory();
$config = $config_factory->getEditable('block.block.directaccessblock');
$config->setData(
    array (
        'uuid' => 'fdfa81cf-088e-4cfa-b36b-94badfdadb11',
        'langcode' =>  'fr',
        'status' =>  true,
        'dependencies' =>
            array (
                'module'  =>
                    array(
                        0 => 'oab_frontoffice'
                    ),
                'theme'  =>
                    array (
                        0  => 'theme_boosted',
                    ),
            ),
        'id'=> 'directaccessblock',
        'theme'=>'theme_boosted',
        'region'=> 'prefooter',
        'weight'=> 0,
        'provider'=> null,
        'plugin'=> 'direct_access_block',
        'settings' =>
            array(
                'id' => 'direct_access_block',
                'label' => 'Direct Access Block',
                'provider' => 'oab_frontoffice',
                'label_display' => '0',
                'direct_access_custom_text' =>
                    array(
                        'value' => '<div id="directaccessblock"><div class="col col-md-12 bg bg_blue nopadding"><div class="col col-md-2 nopadding">&nbsp;</div><div class="col col-md-2 nopadding text-align-center"><div class="div_direct_access border-right"><i class="glyphicon icon icon-wifi link_direct_access"><br /><a class="text_direct_access" href="" target="_blank"> Blogs</a></i></div></div><div class="col col-md-2 nopadding text-align-center"><div class="div_direct_access border-right"><i class="glyphicon icon icon-Collective_class_training link_direct_access"><br /><a class="text_direct_access" href="" target="_blank"> Newsroom</a></i></div></div><div class="col col-md-2 nopadding text-align-center"><div class="div_direct_access border-right"><i class="glyphicon icon icon-playmode_random link_direct_access"><br /><a class="text_direct_access" href="" target="_blank"> Document</a> </i></div></div><div class="col col-md-2 nopadding text-align-center"><div class="div_direct_access"><i class="glyphicon icon icon-hotel link_direct_access"><br /><a class="text_direct_access" href="" target="_blank"> News</a> </i></div></div></div></div>',
                        'format' => 'full_html',
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
                                        'magazine' => 'magazine',
                                        'partner' => 'partner',
                                        'press_kit' => 'press_kit',
                                        'press_release' => 'press_release',
                                        'simple_page' => 'simple_page',
                                    ),
                                'negate' => false,
                                'context_mapping' =>
                                    array (
                                        'node' => '@node.node_route_context:node',
                                    ),
                            ),
                    ),
            )
    )
);
$config->save(TRUE);


//throw new UpdateException();