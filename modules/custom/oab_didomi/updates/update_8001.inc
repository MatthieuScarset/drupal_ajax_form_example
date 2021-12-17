<?php

use \Drupal\block_content\Entity\BlockContent;

$new_block =
  [
    'uuid' => 'eb454a17-56da-4d21-b3ca-565449d7c452',
    'language' => 'en',
    'name' => 'Didomi Youtube message',
    'type' => 'basic',
    'body' => array(
      'value' => '<p><b>To view this video content, you must accept YouTube cookies.</b></p>
<p>These cookies make it possible to share or react directly on the social networks to which you are connected or to integrate content initially posted on these social networks. They also allow social networks to use your visits to our sites and applications for personalization and targeting advertising.</p>',
      'format' => 'full_html',
    ),
    'body_fr' => array(
      'value' => '<p><strong>Pour regarder cette vidéo, vous devez consentir aux Cookies de notre partenaire Youtube</strong></p>
        <p>Ces cookies permettent de partager ou réagir directement sur les réseaux sociaux auxquels vous êtes connectés ou d\'intégrer du contenu initialement posté sur ces réseaux sociaux. Ils permettent aussi aux réseaux sociaux d\'utiliser vos visites sur nos sites et applications à des fins de personnalisation et de ciblage publicitaire.</p>',
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
  $newBlock->addTranslation('fr', ['body' => $new_block['body_fr']  ]);
  $newBlock->save();
}

