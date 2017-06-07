<?php
/**
 * Created by PhpStorm.
 * User: cpws0281
 * Date: 01/06/2017
 * Time: 15:23
 */

namespace Drupal\oab_axiome;

use DOMDocument;
use DOMXPath;

class AxiomeContentImporter {

  public static function parseContent(&$node, $fiche){
    $s = file_get_contents($fiche);
    $data = (array) simplexml_load_string($s);

    $a = json_decode(json_encode($data),1);
    $node->set('field_axiome_data', serialize($a));
    $node->save();
  }
}