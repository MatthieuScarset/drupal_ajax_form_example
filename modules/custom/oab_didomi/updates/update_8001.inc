<?php

use \Drupal\block_content\Entity\BlockContent;

$new_block =
  [
    'uuid' => 'eb454a17-56da-4d21-b3ca-565449d7c452',
    'language' => 'fr',
    'name' => 'Didomi Youtube message FR',
    'type' => 'basic',
    'body' => array(
      'value' => '<div class="didomi-message">
<p class="titre">Pour regarder cette vidéo, vous devez consentir aux Cookies de notre partenaire Youtube</p>
<p class="message">Ces cookies permettent de partager ou réagir directement sur les réseaux sociaux auxquels vous êtes connectés ou d\'intégrer du contenu initialement posté sur ces réseaux sociaux. Ils permettent aussi aux réseaux sociaux d\'utiliser vos visites sur nos sites et applications à des fins de personnalisation et de ciblage publicitaire.</p>
<a class="btn btn-default btn_accept_cookie_youtube">Accepter</a></div>',
      'format' => 'full_html',
    ),

];


/** @var \Drupal\Core\Entity\EntityTypeManager $entity_type_manager */
$entity_type_manager = \Drupal::entityTypeManager();

$entity = $entity_type_manager->getStorage('block_content')->loadByProperties(
  [
    'uuid' => $new_block['uuid'],
    'langcode' => $new_block['language'],
  ]
);

if (!isset($entity) || empty($entity)) {
  $newBlock = BlockContent::create([
    'uuid' => $new_block['uuid'],
    'langcode' => $new_block['language'],
    'info' => $new_block['name'],
    'body' => $new_block['body'],
    'type' => $new_block['type']
  ]);
  $newBlock->save();
}

