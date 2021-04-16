<?php
// Taxonomie RU et RU-EN

//On supprime d'abord les termes de taxonomies Solutions RU et RU-EN saisis manuellement
$languages = array('ru', 'ru-en');

foreach ($languages as $langcode) {
	$tids = \Drupal::entityQuery('taxonomy_term')
		->condition('vid', 'solutions')
		->condition('langcode', $langcode)
		->execute();

	$controller = \Drupal::entityTypeManager()->getStorage('taxonomy_term');
	$entities = $controller->loadMultiple($tids);
	$controller->delete($entities);
}

$terms = array(
	//Solutions RU
	array( 'vid' => 'solutions', 'name' => 'Аудио- и видеоконференции', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Облачные вычисления', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Безопасность', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Голосовые услуги', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Контакт-центр', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Корпоративные сети', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Унифицированные коммуникации', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Мобильность', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Индустрия', 'language' => 'ru'),
	array( 'vid' => 'solutions', 'name' => 'Управление ИТ', 'language' => 'ru'),
	//Solutions RU-EN
	array( 'vid' => 'solutions', 'name' => 'Cloud Computing', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Conferencing', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Contact Centers', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Connectivity', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Security', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Voice and telephony', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Unified Communications', 'language' => 'ru-en'),
	array( 'vid' => 'solutions', 'name' => 'Mobility', 'language' => 'ru-en'),
);

foreach ($terms as $term)
{
	//vérification de l'existance du terme pour ce vocabulaire
	$query = \Drupal::entityQuery('taxonomy_term');
	$query->condition('vid', $term['vid']);
	$query->condition('langcode', $term['language']);
	$query->condition('name', $term['name']);
	$entity = $query->execute();

	if (!isset($entity) || empty($entity))
	{
		//s'il n'existe pas on le crée
		$newTerm = \Drupal\taxonomy\Entity\Term::create([
			'vid' => $term['vid'],
			'name' => $term['name'],
			'langcode' => $term['language'],
		]);
		$newTerm->save();
		drupal_set_message("-- ".$term['name']."(".$term['language'].") créé ", "status");
	}
}