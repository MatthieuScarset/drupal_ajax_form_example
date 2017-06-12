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
use Drupal\Component\Utility\Html;

class AxiomeContentImporter {

  public static function parseContent(&$node, $fiche){
    $s = file_get_contents($fiche);
    $data = (array) simplexml_load_string($s, 'SimpleXMLElement', LIBXML_NOCDATA);

    $axiomeData = json_decode(json_encode($data),1);
    $node->set('field_axiome_data', serialize($axiomeData));


    // Creation du top_zone
    $bannerData = $axiomeData['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes'];
    $urlBackground = $bannerData['background_image']['url_archive'];


    $content = file_get_contents(
      drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/templating/files/banner/top-zone.html.twig'
    );

    $dom = Html::load($content);

    self::replaceLeftBlock($dom, $bannerData);
    self::replaceCenterBlock($dom, $bannerData);
    self::replaceRightBlock($dom, $bannerData);

    $content = $dom->saveHTML($dom->getElementsByTagName('div')->item(0));
//    oabt($content);
    $node->set('field_top_zone', $content);
    $node->field_top_zone->format = 'full_html';

    $node->save();
//    oabt('==========');
//    oabt($node->field_top_zone->value);
  }

  private static function replaceLeftBlock(&$dom, $bannerData){
    $cssClassLeftBlock =  $bannerData['orange_theme']['boosted_css_name'];
    $titleLeftBlock = $bannerData['title'];

    // change class name
    $nodes = self::getNodesByClass($dom, 'icon-frame-connectivity', 'div');
    foreach($nodes as $el) {
      $el->removeAttribute('class');
      $el->setAttribute('class', 'frame-icon-rel inline text_orange '.$cssClassLeftBlock);
    }

    // change title
    $nodesSpan = self::getNodesByClass($dom, 'black', 'span');
    foreach($nodesSpan as $el) {
      $el->textContent = $titleLeftBlock;
    }
  }

  private static function replaceCenterBlock(&$dom, $bannerData){
    $titleCenter = $bannerData['insight'];

    // change title
    $nodesSpan = self::getNodesByClass($dom, 'titre3');
    foreach($nodesSpan as $el) {
      $el->textContent = $titleCenter;
    }
  }

  private static function replaceRightBlock(&$dom, $bannerData){
    $cssClassRightBlock =  $bannerData['pop_out_color']['boosted_css_name'];
    $titleRightBlock = $bannerData['offre_name'];

    // change class name
    $nodes = self::getNodesByClass($dom, 'icon-frame-connectivity');
    $firstItem = true;
    foreach($nodes as $el) {
      if (!$firstItem){
        $el->removeAttribute('class');
        $el->setAttribute('class', 'frame-icon-rel inline text_orange '.$cssClassRightBlock);
      }
      $firstItem = false;
    }

    // change title
    $nodesSpan = self::getNodesByClass($dom, 'white', 'span');
    foreach($nodesSpan as $el) {
      $el->textContent = $titleRightBlock;
    }
  }


  private static function getNodesByClass($dom, $classname, $element = "*"){
    $finder = new DomXPath($dom);
    $nodes = $finder->query("//".$element."[contains(@class, '$classname')]");

    return $nodes;
  }
}