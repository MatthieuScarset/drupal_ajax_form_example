<?php
/* mise a niveau des fichiers de config pour la recette finale */
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('autologout.settings');
$config_group->setData(
	array (
		'timeout' => 1200,
		'max_timeout' => 172800,
		'padding' => 10,
		'role_logout' => true,
		'redirect_url' => '/user/login',
		'no_dialog' => false,
		'message' => 'Your session is about to expire. Do you want to reset it?',
		'inactivity_message' => 'You have been logged out due to inactivity.',
		'enforce_admin' => true,
		'jstimer_format' => '%hours%:%mins%:%secs%',
		'jstimer_js_load_option' => false,
		'use_alt_logout_method' => true,
		'use_watchdog' => true,
		'_core' =>
			array (
				'default_config_hash' => 'zJS1GknUylh656CJSNXOupqKSqm6Xw200h1cq1eI970',
			),
	)
);
$config_group->save(TRUE);

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
    <div class="col-lg-2 col-md-2 col-sm-1 col-xs-1"></div>
    <div id="slider_direct_access" class="col-lg-8 col-md-8 col-sm-12 col-xs-12">
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-wifi link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Blogs</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-Collective_class_training link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Newsroom</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-playmode_random link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> Document</a> 
              </i>
          </div>
      </div>
      <div class="col-lg-3 col-md-3 col-sm-3 col-xs-3 nopadding text-align-center">
          <div class="div_direct_access border-right">
              <i class="glyphicon icon icon-hotel link_direct_access">
                  <a class="text_direct_access " href="" target="_blank"> News</a> 
              </i>
          </div>
      </div>
    </div>
    <div class="col-lg-2 col-md-2 col-sm-1 col-xs-1"></div>
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

$config_group = $config_factory->getEditable('block.block.newsletterblock');
$config_group->setData(
	array (
		'uuid' => 'cd113950-e39d-4adc-9394-2f0bcabf9729',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'ctools',
						1 => 'oab_frontoffice',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'id' => 'topzone',
		'theme' => 'theme_boosted',
		'region' => 'pre_content',
		'weight' => -17,
		'provider' => NULL,
		'plugin' => 'top_zone_block',
		'settings' =>
			array (
				'id' => 'top_zone_block',
				'label' => 'Top Zone',
				'provider' => 'oab_frontoffice',
				'label_display' => 'visible',
				'context_mapping' =>
					array (
						'node' => '@node.node_route_context:node',
					),
			),
		'visibility' =>
			array (
				'entity_bundle:node' =>
					array (
						'id' => 'entity_bundle:node',
						'bundles' =>
							array (
								'industry' => 'industry',
								'product' => 'product',
								'region' => 'region',
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

$config_group = $config_factory->getEditable('block.block.theme_boosted_admin');
$config_group->setData(
	array (
		'uuid' => '007fba68-0096-4d58-8c2f-604662de708a',
		'langcode' => 'en',
		'status' => false,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'system.menu.admin',
					),
				'module' =>
					array (
						0 => 'system',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => 'DWAB7HaAfAJerAmyT8B2K-6qxicu9n0PcKVpDr--N4c',
			),
		'id' => 'theme_boosted_admin',
		'theme' => 'theme_boosted',
		'region' => 'header',
		'weight' => -17,
		'provider' => NULL,
		'plugin' => 'system_menu_block:admin',
		'settings' =>
			array (
				'id' => 'system_menu_block:admin',
				'label' => 'Administration',
				'provider' => 'system',
				'label_display' => 'visible',
				'level' => 1,
				'depth' => 0,
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.theme_boosted_local_actions');
$config_group->setData(
	array (
		'uuid' => '3eba31d6-77c5-4086-9883-7ecddce114af',
		'langcode' => 'en',
		'status' => false,
		'dependencies' =>
			array (
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => 'PffmQ-ABSz5tFjWmVsR7NesunDnEivvopnJnBjl8KNE',
			),
		'id' => 'theme_boosted_local_actions',
		'theme' => 'theme_boosted',
		'region' => 'header',
		'weight' => -16,
		'provider' => NULL,
		'plugin' => 'local_actions_block',
		'settings' =>
			array (
				'id' => 'local_actions_block',
				'label' => 'Primary admin actions',
				'provider' => 'core',
				'label_display' => '0',
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.theme_boosted_login');
$config_group->setData(
	array (
		'uuid' => 'c56c80a7-1116-4a34-8fde-3011cfdcb3ef',
		'langcode' => 'en',
		'status' => false,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'user',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => '4QlSnWBcxxKMIFRM8sbu_MjSkcp3NjGgnVrc-lynQHI',
			),
		'id' => 'theme_boosted_login',
		'theme' => 'theme_boosted',
		'region' => 'header',
		'weight' => -13,
		'provider' => NULL,
		'plugin' => 'user_login_block',
		'settings' =>
			array (
				'id' => 'user_login_block',
				'label' => 'User login',
				'provider' => 'user',
				'label_display' => 'visible',
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.theme_boosted_messages');
$config_group->setData(
	array (
		'uuid' => '861916f1-f22e-4c06-b09a-b6afea16fed7',
		'langcode' => 'en',
		'status' => false,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'system',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => '5MNdk3fpMKx_xxBTcz2T11DL4XEU1H5SgHl8BsYdFsA',
			),
		'id' => 'theme_boosted_messages',
		'theme' => 'theme_boosted',
		'region' => 'header',
		'weight' => -15,
		'provider' => NULL,
		'plugin' => 'system_messages_block',
		'settings' =>
			array (
				'id' => 'system_messages_block',
				'label' => 'Status messages',
				'provider' => 'system',
				'label_display' => '0',
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.theme_boosted_tools');
$config_group->setData(
	array (
		'uuid' => 'd1a5e3e9-638f-4a06-9d63-3d63666a7d12',
		'langcode' => 'en',
		'status' => false,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'system.menu.tools',
					),
				'module' =>
					array (
						0 => 'system',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => 'xCOijLdB1-UgXxQ9a0D1_pd8vxNEhfMnxXZc8jYhHjs',
			),
		'id' => 'theme_boosted_tools',
		'theme' => 'theme_boosted',
		'region' => 'header',
		'weight' => -14,
		'provider' => NULL,
		'plugin' => 'system_menu_block:tools',
		'settings' =>
			array (
				'id' => 'system_menu_block:tools',
				'label' => 'Tools',
				'provider' => 'system',
				'label_display' => 'visible',
				'level' => 1,
				'depth' => 0,
			),
		'visibility' =>
			array (
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.views_block__linked_content_linked_content');
$config_group->setData(
	array (
		'uuid' => 'f3129188-2eb7-454f-a5fe-4fe95812ad37',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'views.view.linked_content',
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
		'id' => 'views_block__linked_content_linked_content',
		'theme' => 'theme_boosted',
		'region' => 'sidebar',
		'weight' => 0,
		'provider' => NULL,
		'plugin' => 'views_block:linked_content-linked_content',
		'settings' =>
			array (
				'id' => 'views_block:linked_content-linked_content',
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
								'magazine' => 'magazine',
								'partner' => 'partner',
								'press_kit' => 'press_kit',
								'press_release' => 'press_release',
								'product' => 'product',
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
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('field.field.node.webform.webform');
$config_group->setData(
	array (
		'uuid' => '7d68c380-d752-46a0-ba92-b9c3b85ae0f2',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'field.storage.node.webform',
						1 => 'node.type.webform',
					),
				'module' =>
					array (
						0 => 'webform',
					),
			),
		'_core' =>
			array (
				'default_config_hash' => '8lAeR9K2aPJaEzc_sjShqayrWxWOp2WCcW4xEp6_OUY',
			),
		'id' => 'node.webform.webform',
		'field_name' => 'webform',
		'entity_type' => 'node',
		'bundle' => 'webform',
		'label' => 'Form',
		'description' => '',
		'required' => false,
		'translatable' => false,
		'default_value' =>
			array (
			),
		'default_value_callback' => '',
		'settings' =>
			array (
				'default_data' => '',
				'status' => true,
				'handler' => 'default:webform',
				'handler_settings' =>
					array (
					),
				'open' => '',
				'close' => '',
			),
		'field_type' => 'webform',
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('locale.settings');
$config_group->setData(
	array (
		'cache_strings' => true,
		'translate_english' => false,
		'javascript' =>
			array (
				'directory' => 'languages',
			),
		'translation' =>
			array (
				'use_source' => 'remote_and_local',
				'default_filename' => '%project-%version.%language.po',
				'default_server_pattern' => 'http://ftp.drupal.org/files/translations/%core/%project/%project-%version.%language.po',
				'overwrite_customized' => false,
				'overwrite_not_customized' => false,
				'update_interval_days' => 0,
				'path' => 'sites/default/files/translations',
				'import_enabled' => true,
			),
		'_core' =>
			array (
				'default_config_hash' => 'Lqw8pAQIfr4sRSts2RRWG97eNG6vRT7FhqF_b5COPGk',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('node.type.blog_post');
$config_group->setData(
	array (
		'uuid' => '19514e03-fd62-4f5d-8e84-7db58bada375',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'menu_ui',
						1 => 'workbench_access',
						2 => 'workbench_moderation',
					),
			),
		'third_party_settings' =>
			array (
				'menu_ui' =>
					array (
						'available_menus' =>
							array (
							),
						'parent' => '',
					),
				'workbench_access' =>
					array (
						'workbench_access_status' => false,
					),
				'workbench_moderation' =>
					array (
						'enabled' => true,
						'allowed_moderation_states' =>
							array (
								0 => 'published',
								1 => 'archived',
								2 => 'draft',
								3 => 'needs_review',
								4 => 'unpublished',
							),
						'default_moderation_state' => 'draft',
					),
			),
		'name' => 'Blog post',
		'type' => 'blog_post',
		'description' => '',
		'help' => '',
		'new_revision' => false,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('robotstxt.settings');
$config_group->setData(
	array (
		'content' => 'User-agent: *
# CSS, JS, Images
Allow: /core/*.css$
Allow: /core/*.css?
Allow: /core/*.js$
Allow: /core/*.js?
Allow: /core/*.gif
Allow: /core/*.jpg
Allow: /core/*.jpeg
Allow: /core/*.png
Allow: /core/*.svg
Allow: /profiles/*.css$
Allow: /profiles/*.css?
Allow: /profiles/*.js$
Allow: /profiles/*.js?
Allow: /profiles/*.gif
Allow: /profiles/*.jpg
Allow: /profiles/*.jpeg
Allow: /profiles/*.png
Allow: /profiles/*.svg
# Directories
Disallow: /core/
Disallow: /profiles/
# Files
Disallow: /README.txt
Disallow: /web.config
# Paths (clean URLs)
Disallow: /admin/
Disallow: /comment/reply/
Disallow: /filter/tips/
Disallow: /node/add/
Disallow: /search/
Disallow: /user/register/
Disallow: /user/password/
Disallow: /user/login/
Disallow: /user/logout/
# Paths (no clean URLs)
Disallow: /index.php/admin/
Disallow: /index.php/comment/reply/
Disallow: /index.php/filter/tips/
Disallow: /index.php/node/add/
Disallow: /index.php/search/
Disallow: /index.php/user/password/
Disallow: /index.php/user/register/
Disallow: /index.php/user/login/
Disallow: /index.php/user/logout/

Sitemap: http://www.orange-business.com/fr/sitemap.xml
Sitemap: http://www.orange-business.com/en/sitemap.xml
Sitemap: http://www.orange-business.com/ru/sitemap.xml
Sitemap: http://www.orange-business.com/ru-en/sitemap.xml
',
		'_core' =>
			array (
				'default_config_hash' => 'ceCx5XZ_ay1Mxcv-sB95U_fBKoVkpvo8RaQiwutSZLI',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('taxonomy.vocabulary.jobs_profiles');
$config_group->setData(
	array (
		'uuid' => 'b559c4e9-4642-4b12-8b21-2158c3dd82ed',
		'langcode' => 'und',
		'status' => true,
		'dependencies' =>
			array (
			),
		'name' => 'Jobs profiles',
		'vid' => 'jobs_profiles',
		'description' => '',
		'hierarchy' => 0,
		'weight' => 0,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('user.role.anonymous');
$config_group->setData(
	array (
		'uuid' => '2628e3ff-ff07-4879-970f-291a77a417b5',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'j5zLMOdJBqC0bMvSdth5UebkprJB8g_2FXHqhfpJzow',
			),
		'id' => 'anonymous',
		'label' => 'Utilisateur non connecté',
		'weight' => 0,
		'is_admin' => false,
		'permissions' =>
			array (
				0 => 'access content',
				1 => 'use text format comments',
				2 => 'view media',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('user.role.authenticated');
$config_group->setData(
	array (
		'uuid' => '9002921e-7529-4be2-ae8e-864c75f26109',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'_core' =>
			array (
				'default_config_hash' => 'dJ0L2DNSj5q6XVZAGsuVDpJTh5UeYkIPwKrUOOpr8YI',
			),
		'id' => 'authenticated',
		'label' => 'Utilisateur connecté',
		'weight' => 1,
		'is_admin' => false,
		'permissions' =>
			array (
				0 => 'access content',
				1 => 'use text format comments',
				2 => 'view media',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('user.role.contributor');
$config_group->setData(
	array (
		'uuid' => '9d0a2637-b58f-4e23-952a-609c8c9dc59f',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'contributor',
		'label' => 'contributeur',
		'weight' => 6,
		'is_admin' => NULL,
		'permissions' =>
			array (
				0 => 'access administration pages',
				1 => 'access browse_media_modal entity browser pages',
				2 => 'access browse_medias_iframe entity browser pages',
				3 => 'access browser_file_modal entity browser pages',
				4 => 'access content overview',
				5 => 'access files overview',
				6 => 'access in-place editing',
				7 => 'access media overview',
				8 => 'access shortcuts',
				9 => 'access toolbar',
				10 => 'access tour',
				11 => 'access user profiles',
				12 => 'access workbench',
				13 => 'administer media',
				14 => 'administer nodes',
				15 => 'edit any full_html content',
				16 => 'edit own full_html content',
				17 => 'use draft_draft transition',
				18 => 'use draft_needs_review transition',
				19 => 'use published_draft transition',
				20 => 'use text format full_html',
				21 => 'view full_html revisions',
				22 => 'view the administration theme',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('user.role.digital_admin');
$config_group->setData(
	array (
		'uuid' => '85401b23-d860-4858-ba0e-3bb1b833eebd',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'digital_admin',
		'label' => 'Digital Admin',
		'weight' => 4,
		'is_admin' => NULL,
		'permissions' =>
			array (
				0 => 'access administration pages',
				1 => 'access browse_medias_iframe entity browser pages',
				2 => 'access browser_modal_for_medias entity browser pages',
				3 => 'access contextual links',
				4 => 'access files overview',
				5 => 'access in-place editing',
				6 => 'access shortcuts',
				7 => 'access site in maintenance mode',
				8 => 'access toolbar',
				9 => 'access tour',
				10 => 'access user profiles',
				11 => 'access workbench',
				12 => 'administer blocks',
				13 => 'administer meta tags',
				14 => 'administer nodes',
				15 => 'administer redirect settings',
				16 => 'administer redirects',
				17 => 'administer robots.txt',
				18 => 'administer scheduled updates',
				19 => 'administer taxonomy',
				20 => 'administer url aliases',
				21 => 'administer users',
				22 => 'administer xmlsitemap',
				23 => 'assign chief_editor role',
				24 => 'assign digital_admin role',
				25 => 'assign roles',
				26 => 'assign webform_manager role',
				27 => 'assign workbench access',
				28 => 'create content translations',
				29 => 'create url aliases',
				30 => 'delete all revisions',
				31 => 'delete content translations',
				32 => 'delete terms in areas',
				33 => 'delete terms in blogs',
				34 => 'delete terms in customer_stories',
				35 => 'delete terms in document_types',
				36 => 'delete terms in industries',
				37 => 'delete terms in magazines',
				38 => 'delete terms in media_tags',
				39 => 'delete terms in media_thematics',
				40 => 'delete terms in partners',
				41 => 'delete terms in solutions',
				42 => 'delete terms in subhomes',
				43 => 'delete terms in topics',
				44 => 'edit terms in areas',
				45 => 'edit terms in blogs',
				46 => 'edit terms in customer_stories',
				47 => 'edit terms in document_types',
				48 => 'edit terms in industries',
				49 => 'edit terms in magazines',
				50 => 'edit terms in media_tags',
				51 => 'edit terms in media_thematics',
				52 => 'edit terms in partners',
				53 => 'edit terms in solutions',
				54 => 'edit terms in subhomes',
				55 => 'edit terms in topics',
				56 => 'replicate entities',
				57 => 'revert all revisions',
				58 => 'translate any entity',
				59 => 'translate interface',
				60 => 'translate profile node',
				61 => 'translate shortcut',
				62 => 'update content translations',
				63 => 'use archived_published transition',
				64 => 'use draft_draft transition',
				65 => 'use draft_needs_review transition',
				66 => 'use draft_published transition',
				67 => 'use needs_review_draft transition',
				68 => 'use needs_review_needs_review transition',
				69 => 'use needs_review_published transition',
				70 => 'use published_archived transition',
				71 => 'use published_draft transition',
				72 => 'use published_published transition',
				73 => 'use text format full_html',
				74 => 'use workbench access',
				75 => 'view all revisions',
				76 => 'view any unpublished content',
				77 => 'view latest version',
				78 => 'view moderation states',
				79 => 'view own unpublished content',
				80 => 'view scheduled update entities',
				81 => 'view the administration theme',
				82 => 'view workbench access information',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('user.role.webform_manager');
$config_group->setData(
	array (
		'uuid' => '80fa78fe-de08-4872-a225-a48888fbebf0',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'webform_manager',
		'label' => 'Webform Manager',
		'weight' => 5,
		'is_admin' => NULL,
		'permissions' =>
			array (
				0 => 'access webform overview',
				1 => 'administer nodes',
				2 => 'administer webform element access',
				3 => 'administer webform submission',
				4 => 'create webform',
				5 => 'create webform content',
				6 => 'delete all revisions',
				7 => 'delete any webform',
				8 => 'delete any webform content',
				9 => 'delete own webform',
				10 => 'delete own webform content',
				11 => 'delete webform revisions',
				12 => 'delete webform submissions any node',
				13 => 'delete webform submissions own node',
				14 => 'edit any webform',
				15 => 'edit any webform content',
				16 => 'edit own webform',
				17 => 'edit own webform content',
				18 => 'edit webform submissions any node',
				19 => 'edit webform submissions own node',
				20 => 'revert all revisions',
				21 => 'revert webform revisions',
				22 => 'use text format full_html',
				23 => 'view all revisions',
				24 => 'view any webform submission',
				25 => 'view webform revisions',
				26 => 'view webform submissions any node',
				27 => 'view webform submissions own node',
			),
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('webform.webform.contact');
$config_group->setData(
	array (
		'uuid' => 'a64a8483-aa44-46a2-90fc-0f8dbc89e3cc',
		'langcode' => 'en',
		'status' => 'open',
		'dependencies' =>
			array (
				'enforced' =>
					array (
						'module' =>
							array (
								0 => 'webform',
							),
					),
			),
		'_core' =>
			array (
				'default_config_hash' => '9-0qAAB04ZXB-lll5r1fNyVVnMWW4GvIaAtU-FimtTk',
			),
		'open' => NULL,
		'close' => NULL,
		'uid' => NULL,
		'template' => false,
		'id' => 'contact',
		'title' => 'Contact',
		'description' => 'Basic email contact webform.',
		'category' => '',
		'elements' => "name:
  '#title': 'Your Name'
  '#type': textfield
  '#required': true
  '#default_value': '[webform-authenticated-user:display-name]'
email:
  '#title': 'Your Email'
  '#type': email
  '#required': true
  '#default_value': '[webform-authenticated-user:mail]'
subject:
  '#title': Subject
  '#type': textfield
  '#required': true
  '#test': 'Testing contact webform from [site:name]'
message:
  '#title': Message
  '#type': textarea
  '#required': true
  '#test': 'Please ignore this email.'
",
  'css' => '',
  'javascript' => '',
  'settings' => 
  array (
    'page' => true,
    'page_submit_path' => '',
    'page_confirm_path' => '',
    'form_submit_label' => 'Send message',
    'form_submit_once' => false,
    'form_submit_attributes' => 
    array (
    ),
    'form_exception_message' => '',
    'form_open_message' => '',
    'form_close_message' => '',
    'form_previous_submissions' => true,
    'form_confidential' => false,
    'form_confidential_message' => '',
    'form_convert_anonymous' => false,
    'form_prepopulate' => false,
    'form_prepopulate_source_entity' => false,
    'form_disable_autocomplete' => false,
    'form_novalidate' => false,
    'form_unsaved' => false,
    'form_disable_back' => false,
    'form_autofocus' => false,
    'form_details_toggle' => false,
    'submission_log' => false,
    'wizard_progress_bar' => true,
    'wizard_progress_pages' => false,
    'wizard_progress_percentage' => false,
    'wizard_next_button_label' => '',
    'wizard_next_button_attributes' => 
    array (
    ),
    'wizard_prev_button_label' => '',
    'wizard_prev_button_attributes' => 
    array (
    ),
    'wizard_start_label' => '',
    'wizard_complete' => true,
    'wizard_complete_label' => '',
    'preview' => 0,
    'preview_next_button_label' => '',
    'preview_next_button_attributes' => 
    array (
    ),
    'preview_prev_button_label' => '',
    'preview_prev_button_attributes' => 
    array (
    ),
    'preview_message' => '',
    'draft' => true,
    'draft_auto_save' => false,
    'draft_button_label' => '',
    'draft_button_attributes' => 
    array (
    ),
    'draft_saved_message' => '',
    'draft_loaded_message' => '',
    'confirmation_type' => 'url_message',
    'confirmation_title' => '',
    'confirmation_message' => 'Your message has been sent.',
    'confirmation_url' => '<front>',
    'confirmation_attributes' => 
    array (
    ),
    'confirmation_back' => true,
    'confirmation_back_label' => '',
    'confirmation_back_attributes' => 
    array (
    ),
    'limit_total' => NULL,
    'limit_total_message' => '',
    'limit_user' => NULL,
    'limit_user_message' => '',
    'purge' => 'none',
    'purge_days' => NULL,
    'entity_limit_total' => NULL,
    'entity_limit_user' => NULL,
    'results_disabled' => false,
    'results_disabled_ignore' => false,
    'token_update' => false,
  ),
  'access' => 
  array (
    'create' => 
    array (
      'roles' => 
      array (
        0 => 'anonymous',
        1 => 'authenticated',
      ),
      'users' => 
      array (
      ),
    ),
    'view_any' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'update_any' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'delete_any' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'purge_any' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'view_own' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'update_own' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
    'delete_own' => 
    array (
      'roles' => 
      array (
      ),
      'users' => 
      array (
      ),
    ),
  ),
  'handlers' => 
  array (
    'email_confirmation' => 
    array (
      'id' => 'email',
      'label' => 'Email confirmation',
      'handler_id' => 'email_confirmation',
      'status' => true,
      'weight' => 1,
      'settings' => 
      array (
        'states' => 
        array (
          0 => 'completed',
        ),
        'to_mail' => '[webform_submission:values:email:raw]',
        'to_options' => 
        array (
        ),
        'cc_mail' => '',
        'cc_options' => 
        array (
        ),
        'bcc_mail' => '',
        'bcc_options' => 
        array (
        ),
        'from_mail' => 'default',
        'from_options' => 
        array (
        ),
        'from_name' => 'default',
        'subject' => '[webform_submission:values:subject:value]',
        'body' => '[webform_submission:values:message:value]',
        'excluded_elements' => 
        array (
        ),
        'html' => true,
        'attachments' => false,
        'debug' => false,
        'reply_to' => '',
        'return_path' => '',
      ),
    ),
    'email_notification' => 
    array (
      'id' => 'email',
      'label' => 'Email notification',
      'handler_id' => 'email_notification',
      'status' => true,
      'weight' => 1,
      'settings' => 
      array (
        'states' => 
        array (
          0 => 'completed',
        ),
        'to_mail' => 'default',
        'to_options' => 
        array (
        ),
        'cc_mail' => '',
        'cc_options' => 
        array (
        ),
        'bcc_mail' => '',
        'bcc_options' => 
        array (
        ),
        'from_mail' => '[webform_submission:values:email:raw]',
        'from_options' => 
        array (
        ),
        'from_name' => '[webform_submission:values:name:value]',
        'subject' => '[webform_submission:values:subject:value]',
        'body' => '[webform_submission:values:message:value]',
        'excluded_elements' => 
        array (
        ),
        'html' => true,
        'attachments' => false,
        'debug' => false,
        'reply_to' => '',
        'return_path' => '',
      ),
    ),
  ),
)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('workbench_moderation.moderation_state.unpublished');
$config_group->setData(
	array (
		'uuid' => 'cbbc1b8d-79e2-4c50-a7a0-822fd9a526e7',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
			),
		'id' => 'unpublished',
		'label' => 'Dépublié',
		'published' => false,
		'default_revision' => false,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('workbench_moderation.moderation_state_transition.unpublish');
$config_group->setData(
	array (
		'uuid' => '26dd5f31-9b0f-4b7f-b731-b122f95c06a3',
		'langcode' => 'fr',
		'status' => true,
		'dependencies' =>
			array (
				'config' =>
					array (
						0 => 'workbench_moderation.moderation_state.published',
						1 => 'workbench_moderation.moderation_state.unpublished',
					),
			),
		'id' => 'unpublish',
		'label' => 'dépublier',
		'stateFrom' => 'published',
		'stateTo' => 'unpublished',
		'weight' => -10,
	)
);
$config_group->save(TRUE);


$config_group = $config_factory->getEditable('autologout.role.chief_editor');
$config_group->setData(
	array (
		'enabled' => false,
		'timeout' => NULL,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('autologout.role.digital_admin');
$config_group->setData(
	array (
		'enabled' => false,
		'timeout' => NULL,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('autologout.role.webform_manager');
$config_group->setData(
	array (
		'enabled' => false,
		'timeout' => NULL,
	)
);
$config_group->save(TRUE);

$config_group = $config_factory->getEditable('block.block.topzone');
$config_group->setData(
	array (
		'uuid' => 'cd113950-e39d-4adc-9394-2f0bcabf9729',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'ctools',
						1 => 'oab_frontoffice',
					),
				'theme' =>
					array (
						0 => 'theme_boosted',
					),
			),
		'id' => 'topzone',
		'theme' => 'theme_boosted',
		'region' => 'pre_content',
		'weight' => -17,
		'provider' => NULL,
		'plugin' => 'top_zone_block',
		'settings' =>
			array (
				'id' => 'top_zone_block',
				'label' => 'Top Zone',
				'provider' => 'oab_frontoffice',
				'label_display' => 'visible',
				'context_mapping' =>
					array (
						'node' => '@node.node_route_context:node',
					),
			),
		'visibility' =>
			array (
				'entity_bundle:node' =>
					array (
						'id' => 'entity_bundle:node',
						'bundles' =>
							array (
								'industry' => 'industry',
								'product' => 'product',
								'region' => 'region',
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

