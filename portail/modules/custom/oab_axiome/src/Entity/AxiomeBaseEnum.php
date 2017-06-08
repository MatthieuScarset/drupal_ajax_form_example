<?php

namespace Drupal\oab_axiome\Entity;

class AxiomeBaseEnum {
  private static $constCacheArray = NULL;

  private static function getConstants() {
    if (self::$constCacheArray == NULL) {
      self::$constCacheArray = [];
    }
    $calledClass = get_called_class();
    if (!array_key_exists($calledClass, self::$constCacheArray)) {
      $reflect = new \ReflectionClass($calledClass);
      self::$constCacheArray[$calledClass] = $reflect->getConstants();
    }
    return self::$constCacheArray[$calledClass];
  }

  public static function getValue($name, $strict = false) {
    $constants = self::getConstants();

    if (array_key_exists($name, $constants)){
      return $constants[$name];
    }

    return 'Key Axiome Base Enum not found.';
  }
}