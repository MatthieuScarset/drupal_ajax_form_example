<?php

function get_correspondances_subhomes () {
  $subhomes = array(
    'blogs' => array(
      'fr' => array('label' => 'Blogs', 'tid_D8' => ''),
      'en' => array('label' => 'Blogs', 'tid_D8' => ''),
      'ru' => array('label' => 'Блоги', 'tid_D8' => ''),
      'ru-en' => array('label' => '', 'tid_D8' => '')),

    'library' => array(
      'fr' => array('label' => 'Médiathèque', 'tid_D8' => ''),
      'en' => array('label' => 'Library', 'tid_D8' => ''),
      'ru' => array('label' => '', 'tid_D8' => ''),
      'ru-en' => array('label' => '', 'tid_D8' => '')),

    'magazine' => array(
      'fr' => array('label' => 'Magazine', 'tid_D8' => ''),
      'en' => array('label' => 'Magazine', 'tid_D8' => ''),
      'ru' => array('label' => '', 'tid_D8' => ''),
      'ru-en' => array('label' => '', 'tid_D8' => '')),

    'press' => array(
      'fr' => array('label' => 'Presse', 'tid_D8' => ''),
      'en' => array('label' => 'Press', 'tid_D8' => ''),
      'ru' => array('label' => 'Новости', 'tid_D8' => ''),
      'ru-en' => array('label' => 'Newsroom', 'tid_D8' => '')),
  );
  return $subhomes;
}
