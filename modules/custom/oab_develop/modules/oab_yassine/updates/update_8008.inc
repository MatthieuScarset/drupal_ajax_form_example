<?php
/***********************
 * Article de blog OK
 ***********************/
$config_factory = \Drupal::configFactory();
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

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.blog_post', array (
'name' => 'Article de blog',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.blog_post', array (
'name' => 'Blog post',
));


/***********************
 * Pays OK
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.country');
$config_group->setData(
	array (
		'uuid' => 'd41b95f2-6aa0-464e-92f0-339b8c74143a',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'menu_ui',
						1 => 'workbench_access',
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
			),
		'name' => 'Country',
		'type' => 'country',
		'description' => '',
		'help' => '',
		'new_revision' => false,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.country', array (
  'name' => 'Pays',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.country', array (
  'name' => 'Country',
));

/***********************
 * Témoignage client OK
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.customer_story');
$config_group->setData(
	array (
		'uuid' => '69b3500d-d0b5-4abb-b29a-3cdf820ccc95',
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
		'name' => 'Case study',
		'type' => 'customer_story',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.customer_story', array (
  'name' => 'Témoignage client',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.customer_story', array (
  'name' => 'Case study',
));

/***********************
 * Document OK
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.document', array (
  'name' => 'Document',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.document', array (
  'name' => 'Document',
));

/***********************
 * Page full html OK
 ***********************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.full_html');
$config_group->setData(
	array (
		'uuid' => 'd725e214-2c7a-4ea2-81c7-26a6b2e23fc9',
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
		'name' => 'Full html page',
		'type' => 'full_html',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.full_html', array (
  'name' => 'Page full html',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.full_html', array (
  'name' => 'Full html page',
));

/***********************
 * Industrie OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.industry');
$config_group->setData(
	array (
		'uuid' => '1316492b-212a-4d06-b57f-f6e6dbf0ee29',
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
		'name' => 'Industry',
		'type' => 'industry',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.industry', array (
  'name' => 'Industrie',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.industry', array (
  'name' => 'Industry',
));

/***********************
 * Article de magazine OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.magazine');
$config_group->setData(
	array (
		'uuid' => '0f7e9606-7f88-4c00-884e-3e302f386f63',
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
		'name' => 'Magazine article',
		'type' => 'magazine',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.magazine', array (
  'name' => 'Article de magazine',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.magazine', array (
  'name' => 'Magazine article',
));

/***********************
 * Bureau OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.office');
$config_group->setData(
	array (
		'uuid' => '6b1801ef-2ee2-4683-9bb2-0a8cafea144e',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'menu_ui',
						1 => 'workbench_access',
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
			),
		'name' => 'Office',
		'type' => 'office',
		'description' => '',
		'help' => '',
		'new_revision' => false,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.office', array (
  'name' => 'Bureau',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.office', array (
  'name' => 'Office',
));

/***********************
 * Partenaire OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.partner');
$config_group->setData(
  array (
    'uuid' => 'c4999339-25cc-4420-b197-1f8b6fba43cb',
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
    'name' => 'Partner',
    'type' => 'partner',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.partner', array (
  'name' => 'Partenaire',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.partner', array (
  'name' => 'Partner',
));

/***********************
 * Dossier de presse
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.press_kit');
$config_group->setData(
  array (
    'uuid' => '90100e2c-c5ad-48eb-b9fb-a496ffcca55c',
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
    'name' => 'Press folder',
    'type' => 'press_kit',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.press_kit', array (
  'name' => 'Dossier de presse',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.press_kit', array (
  'name' => 'Press folder',
));

/***********************
 * Communiqué de presse
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.press_release');
$config_group->setData(
  array (
    'uuid' => '5af5eb9b-5a2f-499a-9137-d078fa1e969f',
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
    'name' => 'Press release',
    'type' => 'press_release',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.press_release', array (
  'name' => 'Communiqué de presse',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.press_release', array (
  'name' => 'Press release',
));

/***********************
 * Produit
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.product');
$config_group->setData(
  array (
    'uuid' => 'd3612531-99c8-4f5b-b695-daaea240ffa9',
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
    'name' => 'Product',
    'type' => 'product',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.product', array (
  'name' => 'Produit',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.product', array (
  'name' => 'Product',
));

/***********************
 * Bloggeur OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.profile');
$config_group->setData(
  array (
    'uuid' => 'b16df3cb-c4f0-41b6-a377-0c3df3645f7c',
    'langcode' => 'fr',
    'status' => true,
    'dependencies' =>
      array (
        'module' =>
          array (
            0 => 'menu_ui',
            1 => 'workbench_access',
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
      ),
    'name' => 'Blogger',
    'type' => 'profile',
    'description' => '',
    'help' => '',
    'new_revision' => false,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.profile', array (
  'name' => 'Bloggeur',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.profile', array (
  'name' => 'Blogger',
));

/***********************
 * Région OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.region');
$config_group->setData(
  array (
    'uuid' => '7a610f59-7320-4363-85cd-5b323ccac714',
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
    'name' => 'Region',
    'type' => 'region',
    'description' => '',
    'help' => '',
    'new_revision' => true,
    'preview_mode' => 1,
    'display_submitted' => false,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.region', array (
  'name' => 'Région',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.region', array (
  'name' => 'Region',
));

/***********************
 * Page simple OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.simple_page');
$config_group->setData(
	array (
		'uuid' => '79ce0bcf-7a44-4600-a616-cd16b748035f',
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
		'name' => 'Simple page',
		'type' => 'simple_page',
		'description' => '',
		'help' => '',
		'new_revision' => true,
		'preview_mode' => 1,
		'display_submitted' => false,
	)
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.simple_page', array (
  'name' => 'Page simple',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.simple_page', array (
  'name' => 'Simple page',
));

/***********************
 * Solution
 ***********************/

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.solution', array (
  'name' => 'Solution',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.solution', array (
  'name' => 'Solution',
));

/***********************
 * Formulaire OK
 ***********************/

$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('node.type.webform');
$config_group->setData(
  array (
    'uuid' => 'fe1fb5bc-1360-4a55-b3ba-5070cd8a4e31',
    'langcode' => 'en',
    'status' => true,
    'dependencies' =>
      array (
        'enforced' =>
          array (
            'module' =>
              array (
                0 => 'webform',
              ),
          ),
        'module' =>
          array (
            0 => 'workbench_access',
          ),
      ),
    'third_party_settings' =>
      array (
        'workbench_access' =>
          array (
            'workbench_access_status' => false,
          ),
      ),
    '_core' =>
      array (
        'default_config_hash' => 'e0BoXlrxD4xhZMqJm5A1gTUkmntzhvyhDNY-3Y4glyc',
      ),
    'name' => 'Webform',
    'type' => 'webform',
    'description' => 'A basic page with an attached webform',
    'help' => '',
    'new_revision' => false,
    'preview_mode' => 1,
    'display_submitted' => true,
  )
);
$config_group->save(TRUE);

$collection = \Drupal::service('config.storage')->createCollection('language.fr');
$collection->write('node.type.webform', array (
  'name' => 'Formulaire',
));

$collection = \Drupal::service('config.storage')->createCollection('language.ru');
$collection->write('node.type.webform', array (
  'name' => 'Webform',
));


/**********************************
 * Ajout de la config de traduction
 **********************************/
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('language.content_settings.menu_link_content.menu_link_content');
$config_group->setData(
	array (
		'uuid' => 'aff3059d-a120-42f5-a25b-dc231d430de4',
		'langcode' => 'en',
		'status' => true,
		'dependencies' =>
			array (
				'module' =>
					array (
						0 => 'content_translation',
						1 => 'menu_link_content',
					),
			),
		'third_party_settings' =>
			array (
				'content_translation' =>
					array (
						'enabled' => true,
					),
			),
		'id' => 'menu_link_content.menu_link_content',
		'target_entity_type_id' => 'menu_link_content',
		'target_bundle' => 'menu_link_content',
		'default_langcode' => 'site_default',
		'language_alterable' => true,
	)
);
$config_group->save();
//throw new \Drupal\Core\Utility\UpdateException();