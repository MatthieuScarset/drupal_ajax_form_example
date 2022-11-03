<?php

namespace Drupal\oab_develop;

use Symfony\Component\DependencyInjection\Exception\ServiceNotFoundException;

class Oab {

  /**
   * @param string $name
   *
   * @return object|void|null
   */
  static function getHelper(string $name) {
    $helper_name = "oab_develop.helper.$name";

    if (\Drupal::hasService($helper_name)) {
      return \Drupal::service($helper_name);
    }

    throw new ServiceNotFoundException($helper_name);
  }

  /**
   * @return \Drupal\oab_develop\Helpers\TranslationsHelper
   */
  static function translationsHelper() {
    return self::getHelper("translations");
  }
}

