<?php

oabt_YmlImport('block.block.mediatheque.yml');

$conf = array (
    'settings' =>
        array (
            'mediatheque_text' => 'Are you looking for images or videos to illustrate your communication media?',
            'mediatheque_link' => 'https://mediatheque.orange.com/en/mediacenter',
            'mediatheque_link_text' => 'Click here',
        ),
);

$collection = \Drupal::service('config.storage')->createCollection('language.en');
$collection->write('block.block.mediatheque', $conf);
