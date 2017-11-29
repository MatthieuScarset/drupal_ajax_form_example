<?php

namespaceDrupaloab_transliteration_filename;
useDrupalCoreTransliterationPhpTransliteration;
class Transliteration extends PhpTransliteration {

    public function transliterate($string, $langcode = 'en', $unknown_character = '?', $max_length = NULL) {
        return parent::transliterate($string, $langcode, $unknown_character, $max_length);
    }
}