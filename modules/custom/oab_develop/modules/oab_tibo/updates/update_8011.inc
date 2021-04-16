<?php

// storage
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.directaccessblock');
$config_group->setData(
	array (
		'uuid' => 'fdfa81cf-088e-4cfa-b36b-94badfdadb11',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'oab_frontoffice',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'id' => 'directaccessblock',
		'theme' => 'theme_boosted',
		'region' => 'prefooter',
		'weight' => 0,
		'provider' => NULL,
		'plugin' => 'direct_access_block',
		'settings' =>
			array (
				'id' => 'direct_access_block',
				'label' => 'Direct Access Block',
				'provider' => 'oab_frontoffice',
				'label_display' => '0',
				'direct_access_custom_text' =>
					array (
						'value' => '
<div class="col-lg-12 col-md-12 col-sm-12 col-xs-12 bg bg_blue">
    <div id="slider_direct_access" class="container">
      <div class="item-direct-access nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-wifi link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Blogs</a> 
              </i>
          </div>
      </div>
      <div class="item-direct-access nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-Collective_class_training link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Newsroom</a> 
              </i>
          </div>
      </div>
      <div class="item-direct-access nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-playmode_random link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Document</a> 
              </i>
          </div>
      </div>
      <div class="item-direct-access nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-hotel link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> News</a> 
              </i>
          </div>
      </div>
    </div>
  </div>
</div>',
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
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);