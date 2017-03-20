<?php
//traduction des champs
$connection = \Drupal\Core\Database\Database::getConnection();

//REGION
$champs_region = array('field.field.node.blog_post.field_region',
											 'field.field.node.customer_story.field_region',
											 'field.field.node.document.field_region',
											 'field.field.node.magazine.field_region',
											 'field.field.node.partner.field_region',
											 'field.field.node.press_kit.field_region',
											 'field.field.node.press_release.field_region',
											 'field.field.node.product.field_region',
											 'field.field.node.region.field_region',
											 'field.field.node.simple_page.field_region');
foreach ($champs_region as $champ_region)
{
	$query_delete = $connection->delete('config')
		->condition('collection', 'language.fr')
		->condition('name', $champ_region)
		->execute();

	$query_create = $connection->insert('config')
		->fields(array(
			'collection' => 'language.fr',
			'name' => $champ_region,
			'data' => serialize(array (
					'label' => 'Zone géographique',
				))
		))
		->execute();
}

//JOB PROFILE
$champs_job = array('field.field.node.blog_post.field_job_profile',
	'field.field.node.customer_story.field_job_profile',
	'field.field.node.document.field_job_profile',
	'field.field.node.magazine.field_job_profile',
	'field.field.node.press_kit.field_job_profile',
	'field.field.node.press_release.field_job_profile',
	'field.field.node.product.field_job_profile',
	'field.field.node.simple_page.field_job_profile');
foreach ($champs_job as $champ_job)
{
	$query_delete = $connection->delete('config')
		->condition('collection', 'language.fr')
		->condition('name', $champ_job)
		->execute();

	$query_create = $connection->insert('config')
		->fields(array(
			'collection' => 'language.fr',
			'name' => $champ_job,
			'data' => serialize(array (
				'label' => 'Profil métier',
			))
		))
		->execute();
}


//MARKET SEGMENT
$champs_market_segment = array('field.field.node.blog_post.field_market_segment',
	'field.field.node.customer_story.field_market_segment',
	'field.field.node.document.field_market_segment',
	'field.field.node.magazine.field_market_segment',
	'field.field.node.press_kit.field_market_segment',
	'field.field.node.press_release.field_market_segment',
	'field.field.node.product.field_market_segment',
	'field.field.node.simple_page.field_market_segment');
foreach ($champs_market_segment as $champ_market_segment)
{
	$query_delete = $connection->delete('config')
		->condition('collection', 'language.fr')
		->condition('name', $champ_market_segment)
		->execute();

	$query_create = $connection->insert('config')
		->fields(array(
			'collection' => 'language.fr',
			'name' => $champ_market_segment,
			'data' => serialize(array (
				'label' => 'Segment de marché',
			))
		))
		->execute();
}

//INDUSTRY
$query_delete = $connection->delete('config')
	->condition('collection', 'language.fr')
	->condition('name', 'field.field.node.partner.field_industry')
	->execute();

$query_create = $connection->insert('config')
	->fields(array(
		'collection' => 'language.fr',
		'name' => 'field.field.node.partner.field_industry',
		'data' => serialize(array (
			'label' => 'Industrie',
		))
	))
	->execute();
$query_delete = $connection->delete('config')
	->condition('collection', 'language.fr')
	->condition('name', 'field.field.node.product.field_industry')
	->execute();

$query_create = $connection->insert('config')
	->fields(array(
		'collection' => 'language.fr',
		'name' => 'field.field.node.product.field_industry',
		'data' => serialize(array (
			'label' => 'Industrie',
		))
	))
	->execute();

//PARTNER TYPE
$query_delete = $connection->delete('config')
	->condition('collection', 'language.fr')
	->condition('name', 'field.field.node.partner.field_partner_type')
	->execute();

$query_create = $connection->insert('config')
	->fields(array(
		'collection' => 'language.fr',
		'name' => 'field.field.node.partner.field_partner_type',
		'data' => serialize(array (
			'label' => 'Type de partenaire',
		))
	))
	->execute();


//SOUS FAMILLE
$query_delete = $connection->delete('config')
	->condition('collection', 'language.fr')
	->condition('name', 'field.field.node.product.field_sub_family')
	->execute();

$query_create = $connection->insert('config')
	->fields(array(
		'collection' => 'language.fr',
		'name' => 'field.field.node.product.field_sub_family',
		'data' => serialize(array (
			'label' => 'Sous-famille',
		))
	))
	->execute();


//SUBHOME
$champs_subhome = array('field.field.node.blog_post.field_subhome',
	'field.field.node.customer_story.field_subhome',
	'field.field.node.document.field_subhome',
	'field.field.node.magazine.field_subhome',
	'field.field.node.press_kit.field_subhome',
	'field.field.node.press_release.field_subhome',
	'field.field.node.partner.field_subhome',
	'field.field.node.simple_page.field_subhome');
foreach ($champs_subhome as $champ_subhome)
{
	$query_delete = $connection->delete('config')
		->condition('collection', 'language.fr')
		->condition('name', $champ_subhome)
		->execute();

	$query_create = $connection->insert('config')
		->fields(array(
			'collection' => 'language.fr',
			'name' => $champ_subhome,
			'data' => serialize(array (
				'label' => 'Rubrique',
			))
		))
		->execute();
}