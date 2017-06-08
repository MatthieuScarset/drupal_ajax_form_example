<?php

namespace Drupal\oab_axiome\Entity;


abstract class AxiomeParseErrorEnum extends AxiomeBaseEnum {
  const MissingAttribute = 'The attribute %key is missing, the import can not be completed.';
  const MissingKey = 'The key %key is missing, the import can not be completed.';
  const MissingFile = 'The file %key is missing, the import can not be completed.';

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
  public static function getMessage($key, $values = array()){
    return t(AxiomeParseErrorEnum::getValue($key), $values);
  }
}

