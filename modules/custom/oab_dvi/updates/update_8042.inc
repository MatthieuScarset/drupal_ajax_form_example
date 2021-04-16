<?php


/**************************************************************/
/******** CREATION DES MENUS ET BLOCK DE DVI DIRECT ACCESS *******/
/**************************************************************/
use  \Drupal\system\Entity\Menu;
use  \Drupal\block\Entity\Block;

$new_menus = array(
	array(
		'menu_id' => 'direct-access-bar-dvi-fr',
		'menu_label' => 'Direct Access Bar DVI FR',
		'menu_desc' => 'Menu for Direct Access Bar FR only for DVI',
		'langcode' => 'fr',
		'block_id' => 'directaccessbardvifr',
		'block_label' => 'Direct Access Bar DVI FR'
	),
);

foreach ($new_menus as $menu_values)
{
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
				),
				'request_path' =>
					array (
						'id' => 'request_path',
						'pages' => '/ventes-indirectes*',
						'negate' => false,
						'context_mapping' =>
							array (
							),
					),
			)
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
	//FR
	array('title' => 'Réseau mobile', 'uri' => 'internal:/fr/reseau-mobile', 'icon' => 'icon-mirroring', 'menu_name' => 'direct-access-bar-dvi-fr', 'langcode' => 'fr'),
	array('title' => 'Catalogue produits', 'uri' => 'internal:/fr/ventes-indirectes/produits', 'icon' => 'icon-buy', 'menu_name' => 'direct-access-bar-dvi-fr', 'langcode' => 'fr'),
	array('title' => 'Presse', 'uri' => 'internal:/fr/presse', 'icon' => 'icon-Document_compose', 'menu_name' => 'direct-access-bar-dvi-fr', 'langcode' => 'fr'),
	array('title' => 'Blogs', 'uri' => 'internal:/fr/blogs', 'icon' => 'icon-Comments', 'menu_name' => 'direct-access-bar-dvi-fr', 'langcode' => 'fr'),

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
$config_group = $config_factory->getEditable('block.block.directaccessbarfr');
$config_group->set('visibility.request_path', array (
	'id' => 'request_path',
	'pages' => '/ventes-indirectes*',
	'negate' => true,
	'context_mapping' =>
		array (
		),
));
$config_group->save(TRUE);