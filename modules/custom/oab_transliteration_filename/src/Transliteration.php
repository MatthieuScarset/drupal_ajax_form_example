<?php

namespace Drupal\oab_transliteration_filename;

use Drupal\Core\Transliteration\PhpTransliteration;

class Transliteration extends PhpTransliteration {

    public function transliterate($string, $langcode = 'en', $unknown_character = '?', $max_length = NULL) {
        return parent::transliterate($string, $langcode, $unknown_character, $max_length);
    }
}
