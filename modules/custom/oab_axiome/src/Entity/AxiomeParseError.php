<?php

namespace Drupal\oab_axiome\Entity;


abstract class AxiomeParseErrorEnum extends AxiomeBaseEnum {
  const MISSING_ATTRIBUTE = 'The attribute %key is missing, the import can not be completed.';
  const MISSING_KEY = 'The key %key is missing, the import can not be completed.';
  const MISSING_FILE = 'The file %key is missing, the import can not be completed.';

}

/*
 * EXEMPLE
  namespace Drupal\oab_axiome\Entity;

  $text = AxiomeParseError::getMessage('MissingKey', array('%key' => 'attributes'));
  echo $text;
*/

class AxiomeParseError {

  /**
   * @param $key
   * @param array $values
   * @return \Drupal\Core\StringTranslation\TranslatableMarkup
   *
   */
  public static function getMessage($key, $values = array()) {
    return t(AxiomeParseErrorEnum::getValue($key), $values);
  }
}

