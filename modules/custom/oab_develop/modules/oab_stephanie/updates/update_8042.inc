<?php


/**************************************************************/
/******** CREATION DES MENUS ET BLOCK DE  DIRECT ACCESS *******/
/**************************************************************/
use  \Drupal\system\Entity\Menu;
use  \Drupal\block\Entity\Block;

$new_menus = array(
	array(
		'menu_id' => 'direct-access-bar-en',
		'menu_label' => 'Direct Access Bar EN',
		'menu_desc' => 'Menu for Direct Access Bar EN',
		'langcode' => 'en',
		'block_id' => 'directaccessbaren',
		'block_label' => 'Direct Access Bar EN'
	),
	array(
		'menu_id' =>
			'direct-access-bar-fr',
		'menu_label' => 'Direct Access Bar FR',
		'menu_desc' => 'Menu for Direct Access Bar FR',
		'langcode' => 'fr',
		'block_id' => 'directaccessbarfr',
		'block_label' => 'Direct Access Bar FR'
	),
	array(
		'menu_id' => 'direct-access-bar-ru',
		'menu_label' => 'Direct Access Bar RU',
		'menu_desc' => 'Menu for Direct Access Bar RU',
		'langcode' => 'ru',
		'block_id' => 'directaccessbarru',
		'block_label' => 'Direct Access Bar RU'
	),
	array(
		'menu_id' => 'direct-access-bar-ru-en',
		'menu_label' => 'Direct Access Bar RU-EN',
		'menu_desc' => 'Menu for Direct Access Bar RU-EN',
		'langcode' => 'ru-en',
		'block_id' => 'directaccessbarruen',
		'block_label' => 'Direct Access Bar RU EN'
	),
);

foreach ($new_menus as $menu_values) {

	$menuObj = Menu::load($menu_values['menu_id']);
	if (!isset($menuObj) || empty($menuObj))
	{
		$menuObj = Menu::create([
			'id' => $menu_values['menu_id'],
			'label' => $menu_values['menu_label'],
			'description' => $menu_values['menu_desc'],
			'langcode' => $menu_values['langcode'],
			'status' => TRUE,
		]);
		$menuObj->save();
		drupal_set_message("-- Menu ".$menu_values['menu_id']." : ".$menu_values['menu_label']." créé ", "status");
	}

	$blockObj = Block::load($menu_values['block_id']);
	if (!isset($blockObj) || empty($blockObj))
	{
		$blockObj = Block::create([
			'langcode' => $menu_values['langcode'],
			'status' => TRUE,
			'dependencies' => array(
				'config' => array('system.menu.'.$menu_values['menu_id']),
				'module' => array('language', 'system'),
				'theme' => array('theme_boosted'),
			),
			'id' => $menu_values['block_id'],
			'theme' => 'theme_boosted',
			'region' => 'prefooter',
			'weight' => 0,
			'provider' => NULL,
			'plugin' => 'system_menu_block:'.$menu_values['menu_id'],
			'settings' => array(
				'id' =>'system_menu_block:'.$menu_values['menu_id'],
				'label' => $menu_values['menu_label'],
				'provider' => 'system',
				'label_display' => '0',
				'level' => 1,
				'depth' => 0,
			),
			'visibility' => array(
				'language' => array(
					'id' => 'language',
					'langcodes' => array( $menu_values['langcode'] => $menu_values['langcode'] ),
					'negate' => FALSE,
					'context_mapping' => array( 'language' => '@language.current_language_context:language_interface')
				)
			),
		]);
		$blockObj->save();
		drupal_set_message("-- Block ".$menu_values['block_id']." créé ", "status");
	}
}

/**********************************************************/
/******** CREATION DES ITEMS DE MENUS DIRECT ACCESS *******/
/**********************************************************/
use Drupal\menu_link_content\Entity\MenuLinkContent;

$menu_links_array = array(
	//EN
	array('title' => 'Blogs', 'uri' => 'internal:/en/', 'icon' => 'icon-wifi', 'menu_name' => 'direct-access-bar-en', 'langcode' => 'en'),
	array('title' => 'Newsroom', 'uri' => 'internal:/en/', 'icon' => 'icon-Collective_class_training', 'menu_name' => 'direct-access-bar-en', 'langcode' => 'en'),
	array('title' => 'Document', 'uri' => 'internal:/en/', 'icon' => 'icon-playmode_random', 'menu_name' => 'direct-access-bar-en', 'langcode' => 'en'),
	array('title' => 'News', 'uri' => 'internal:/en/', 'icon' => 'icon-hotel', 'menu_name' => 'direct-access-bar-en', 'langcode' => 'en'),
	//FR
	array('title' => 'Blogs', 'uri' => 'internal:/fr/', 'icon' => 'icon-wifi', 'menu_name' => 'direct-access-bar-fr', 'langcode' => 'fr'),
	array('title' => 'Newsroom', 'uri' => 'internal:/fr/', 'icon' => 'icon-Collective_class_training', 'menu_name' => 'direct-access-bar-fr', 'langcode' => 'fr'),
	array('title' => 'Document', 'uri' => 'internal:/fr/', 'icon' => 'icon-playmode_random', 'menu_name' => 'direct-access-bar-fr', 'langcode' => 'fr'),
	array('title' => 'News', 'uri' => 'internal:/fr/', 'icon' => 'icon-hotel', 'menu_name' => 'direct-access-bar-fr', 'langcode' => 'fr'),
	//RU
	array('title' => 'Blogs', 'uri' => 'internal:/ru/', 'icon' => 'icon-wifi', 'menu_name' => 'direct-access-bar-ru', 'langcode' => 'ru'),
	array('title' => 'Newsroom', 'uri' => 'internal:/ru/', 'icon' => 'icon-Collective_class_training', 'menu_name' => 'direct-access-bar-ru', 'langcode' => 'ru'),
	array('title' => 'Document', 'uri' => 'internal:/ru/', 'icon' => 'icon-playmode_random', 'menu_name' => 'direct-access-bar-ru', 'langcode' => 'ru'),
	array('title' => 'News', 'uri' => 'internal:/ru/', 'icon' => 'icon-hotel', 'menu_name' => 'direct-access-bar-ru', 'langcode' => 'ru'),
	//RU-EN
	array('title' => 'Blogs', 'uri' => 'internal:/ru-en/', 'icon' => 'icon-wifi', 'menu_name' => 'direct-access-bar-ru-en', 'langcode' => 'ru-en'),
	array('title' => 'Newsroom', 'uri' => 'internal:/ru-en/', 'icon' => 'icon-Collective_class_training', 'menu_name' => 'direct-access-bar-ru-en', 'langcode' => 'ru-en'),
	array('title' => 'Document', 'uri' => 'internal:/ru-en/', 'icon' => 'icon-playmode_random', 'menu_name' => 'direct-access-bar-ru-en', 'langcode' => 'ru-en'),
	array('title' => 'News', 'uri' => 'internal:/ru-en/', 'icon' => 'icon-hotel', 'menu_name' => 'direct-access-bar-ru-en', 'langcode' => 'ru-en'),
);

foreach ($menu_links_array as $menu_link) {
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('menu_link_content');
	$query->condition('menu_name', $menu_link['menu_name']);
	$query->condition('langcode', $menu_link['langcode']);
	$query->condition('title', $menu_link['title']);
	$entity = $query->execute();

	if (!isset($entity) || empty($entity)) {
		$menuLinkObj = MenuLinkContent::create([
			'title' => $menu_link['title'],
			'link' => array(
				'uri' => $menu_link['uri'],
				'options' => array('icon' => $menu_link['icon'])
			),
			'menu_name' => $menu_link['menu_name'],
			'langcode' => $menu_link['langcode']
		]);
		$menuLinkObj->save();
	}
}

//Désactivation du block actuel
$config_factory = \Drupal::configFactory();
$config_group = $config_factory->getEditable('block.block.directaccessblock');
$config_group->set('status', false);
$config_group->save(TRUE);