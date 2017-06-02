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

   /* $t1 = microtime();
    $s = file_get_contents($fiche);
    $data = (array) simplexml_load_string($s);

    $a = json_decode(json_encode($data),1);
    $t2 = microtime();


    $t3 = microtime();
    $dom = new DOMDocument("1.0");
    $dom->load($fiche);
    $xpath = new DOMXPath($dom);



    // TODO : Remplir le body avec les élements du XML

    // short description
    $rubriques = $xpath->query("/ficheoffre/Children/theme/Children/rubrique_standard/Attributes");


    $ar = [];
    $i = 0;
    foreach ($rubriques as $rubrique){
//      oabt($rubrique->childNodes);
      foreach($rubrique->childNodes as $childNode){
        $ar[$i][$childNode->tagName] = $childNode->nodeValue;
      }
      $i++;
    }
    $t4 = microtime();

    oabt('T1 : '.(($t2 - $t1) / 1000));
    oabt('T2 : '.(($t4 - $t3) / 1000));

    oabt($ar);
    oabt($a['Children']['theme']['Children'], true);
    die();

    //$node->field_txt_catcher['und'][0]['value'] = $field_txt_catcher;
*/


  }
}