<?php

function get_correspondances_press_formats() {
    $press_formats = array(
        'press_kit' => array(
            'fr' => array('label' => 'Dossier de presse', 'tid_D8' => ''),
            'en' => array('label' => 'Press kit', 'tid_D8' => ''),
            'ru' => array('label' => 'Пресс-релиз', 'tid_D8' => ''),
            'ru-en' => array('label' => 'Press release', 'tid_D8' => '')),

        'press_release' => array(
            'fr' => array('label' => 'Communiqué de presse', 'tid_D8' => ''),
            'en' => array('label' => 'Press release', 'tid_D8' => ''),
            'ru' => array('label' => 'Пресс-релиз', 'tid_D8' => ''),
            'ru-en' => array('label' => 'Press release', 'tid_D8' => '')),

    );
    return $press_formats;
}
