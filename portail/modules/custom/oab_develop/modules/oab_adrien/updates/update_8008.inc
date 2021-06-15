<?php

use \Drupal\block_content\Entity\BlockContent;

$new_blocks = [
  [
    'uuid' => 'ea50b916-a069-4fac-a324-bd82a04a5def',
    'language' => 'en',
    'name' => 'Contact CSP EN',
    'type' => 'basic',
    'body' => array(
      'value' => '<div class="container-fluid">
                  <div class="row" style="background-color: #4cb4e6; padding:1rem;">
                  <div class="col-md-12">
                  <h2><span style="color:#000000;">Contact our sales team</span></h2>

                  <p><font color="#000000"><b>Request a trial of this solution</b></font><br />
                  &nbsp;</p>
                  <a class="btn btn-default " href="/en/any-request">Contact us</a></div>
                  </div>
                  </div>',
      'format' => 'full_html',
    ),
  ],
  [
    'uuid' => 'c55c4f20-7284-46c6-9f27-9a5df2395e26',
    'language' => 'fr',
    'name' => 'Contact CSP FR',
    'type' => 'basic',
    'body' => array(
      'value' => '<div class="container-fluid">
                  <div class="row" style="background-color: #4cb4e6; padding:1rem;">
                  <div class="col-md-12">
                  <h2><span style="color:#000000;">Contacter notre service commercial</span></h2>

                  <p><font color="#000000"><b>Demander un test de cette solution</b></font><br />
                  &nbsp;</p>
                  <a class="btn btn-default " href="/fr/contact">Contactez-nous</a></div>
                  </div>
                  </div>',
      'format' => 'full_html',
),
  ],
];

foreach ($new_blocks as &$block) {

  /** @var \Drupal\Core\Entity\EntityTypeManager $entity_type_manager */
  $entity_type_manager = \Drupal::entityTypeManager();

  $entity = $entity_type_manager->getStorage('block_content')->loadByProperties(
    [
      'uuid' => $block['uuid'],
      'langcode' => $block['language'],
    ]
  );

  if (!isset($entity) || empty($entity)) {
    $newBlock = BlockContent::create([
      'uuid' => $block['uuid'],
      'langcode' => $block['language'],
      'info' => $block['name'],
      'body' => $block['body'],
      'type' => $block['type']
    ]);
    $newBlock->save();
  }
}
