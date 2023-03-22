<?php

namespace Drupal\oab_develop\Helpers;

use Drupal\Component\Transliteration\TransliterationInterface;

class StringUtilities {
  public function __construct(
    private TransliterationInterface $transliteration
  ) {
  }
  public function getSlug(string $string):  string {

    $clean_string = str_replace(' ', '_', $string);
    $clean_string = str_replace('.', '_', $clean_string);
    $clean_string = strtolower($clean_string);
    $clean_string = $this->transliteration->transliterate($clean_string);

    return preg_replace('@[^a-z0-9_.]+@', '_', $clean_string);
  }
}
