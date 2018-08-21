<?php

namespace Drupal\oab_axiome\Entity;

class AxiomeBaseEnum {
  private static $constCacheArray = NULL;

  private static function getConstants() {
    if (self::$constCacheArray == NULL) {
      self::$constCacheArray = [];
    }
    $called_class = get_called_class();
    if (!array_key_exists($called_class, self::$constCacheArray)) {
      $reflect = new \ReflectionClass($called_class);
      self::$constCacheArray[$called_class] = $reflect->getConstants();
    }
    return self::$constCacheArray[$called_class];
  }

  public static function getValue($name, $strict = false) {
    $constants = self::getConstants();

    if (array_key_exists($name, $constants)) {
      return $constants[$name];
    }

    return 'Key Axiome Base Enum not found.';
  }
}
