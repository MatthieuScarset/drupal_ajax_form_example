<?php
//activation traduction des offices
oabt_YmlImport('language.content_settings.node.office.yml');


//on passe tous les nodes en EN
$nids= \Drupal::entityQuery('node')
	->condition('type', 'office')
	->execute();

foreach ($nids as $nid) {
	print $nid;
	$node = \Drupal\node\Entity\Node::load($nid);
	var_dump($node->language());
	if($node->language()->getId() == 'und') {
		$node->set('langcode', 'en');
		$node->save();
	}
}
