<?php
//activation traduction des contenus offices==> fait en BO directement, on n'importe pas la config finalement
/*
oabt_YmlImport('language.content_settings.node.office.yml');
oabt_YmlImport('core.base_field_override.node.office.title.yml');
oabt_YmlImport('field.field.node.office.field_additionnal.yml');
oabt_YmlImport('field.field.node.office.field_city.yml');
oabt_YmlImport('field.field.node.office.field_email_address.yml');
oabt_YmlImport('field.field.node.office.field_office_country.yml');
oabt_YmlImport('field.field.node.office.field_office_location.yml');
oabt_YmlImport('field.field.node.office.field_phone_number.yml');
oabt_YmlImport('field.field.node.office.field_postal_code.yml');
oabt_YmlImport('field.field.node.office.field_region.yml');
oabt_YmlImport('field.field.node.office.field_street.yml');
*/

//mise a jour de la vue
oabt_YmlImport('views.view.offices_map_view.yml');

//on passe tous les nodes Office en EN
$nids= \Drupal::entityQuery('node')
	->condition('type', 'office')
	->execute();

$nodesOffices = \Drupal\node\Entity\Node::loadMultiple($nids);
foreach ($nodesOffices as $office) {
	if ($office->language()->getId() == 'und') {
		$office->set('langcode', 'en');
		$office->save();
	}
}


//on rend la taxo office countries traductible ==> fait en BO directement, on n'importe pas la config finalement
/*
oabt_YmlImport('language.content_settings.taxonomy_term.office_countries.yml');
oabt_YmlImport('core.base_field_override.taxonomy_term.office_countries.name.yml');
*/

//il faut rendre traductible les termes Offices countries!
$countriesTrad = array(
	"Argentina" => "Аргентина",
	"Australia" => "Австралия",
	"Austria" => "Австрия",
	"Belarus" => "Белоруссия",
	"Belgium" => "Бельгия",
	"Brazil" => "Бразилия",
	"Bulgaria" => "Болгария",
	"Canada" => "Канада",
	"Chile" => "Чили",
	"China" => "Китай",
	"Colombia" => "Колумбия",
	"Croatia" => "Хорватия",
	"Czech Republic" => "Чешская республика",
	"Denmark" => "Дания",
	"Egypt" => "Египет",
	"Estonia" => "Эстония",
	"Finland" => "Финляндия",
	"France" => "Франция",
	"Germany" => "Германия",
	"Greece" => "Греция",
	"Hungary" => "Венгрия",
	"Iceland" => "Исландия",
	"India" => "Индия",
	"Indonesia" => "Индонезия",
	"Ireland" => "Ирландия",
	"Italy" => "Италия",
	"Ivory Coast" => "Кот-д'Ивуар",
	"Japan" => "Япония",
	"Kazakhstan" => "Казахстан",
	"Latvia" => "Латвия",
	"Lebanon" => "Ливан",
	"Lithuania" => "Литва",
	"Luxembourg" => "Люксембург",
	"Malaysia" => "Малайзия",
	"Malta" => "Мальта",
	"Mauritius" => "Маврикий",
	"Mexico" => "Мексика",
	"Netherlands" => "Нидерланды",
	"New Zealand" => "Новая Зеландия",
	"Norway" => "Норвегия",
	"Poland" => "Польша",
	"Portugal" => "Португалия",
	"Romania" => "Румыния",
	"Russia" => "Россия",
	"Saudi Arabia" => "Саудовская Аравия",
	"Senegal" => "Сенегал",
	"Singapore" => "Сингапур",
	"Slovakia" => "Словакия",
	"South Africa" => "Южная Африка",
	"South Korea" => "Южная Корея",
	"Spain" => "Испания",
	"Sweden" => "Швеция",
	"Switzerland" => "Швейцария",
	"Taiwan" => "Тайвань",
	"Turkey" => "Турция",
	"United Arab Emirates" => "Объединенные Арабские Эмираты",
	"United Kingdom" => "Великобритания",
	"United States" => "Соединенные Штаты",
	"Vietnam" => "Вьетнам"
);

//traduction de la taxo office country
$tidCountries = \Drupal::entityQuery('taxonomy_term')
	->condition('vid', 'office_countries')
	->execute();
$controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
$termsCountries = $controller->loadMultiple($tidCountries);
foreach ($termsCountries as $termObj) {
	if (!empty($termObj)) {
		//on passe le terme en version EN
		if ($termObj->language()->getId() == 'und') {
			$termObj->set('langcode', 'en');
			$termObj->save();
		}
		if (!$termObj->hasTranslation('ru')) {
			$termArray = $termObj->toArray();
			if (isset($countriesTrad[$termObj->label()]))
			{
				$termArray['name'] = $countriesTrad[$termObj->label()];
			}
			$termObj->addTranslation('ru', $termArray)->save();
		}
	}
}


$role = \Drupal\user\Entity\Role::load('digital_admin');
if (!empty($role)) {
	//affectation de la permission
	$permissions = $role->getPermissions();
	if (!in_array('translate office node', $permissions)) {
		$role->grantPermission('translate office node');
		$role->save();
		drupal_set_message("Permission affectée (translate office node) au role digital_admin", 'status');
	}
}