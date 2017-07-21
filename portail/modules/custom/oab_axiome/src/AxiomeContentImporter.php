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
use Drupal\file\Entity\File;
use Drupal\image\Entity\ImageStyle;
use Drupal\media_entity\Entity\Media;

class AxiomeContentImporter {

	public static function parseContent(&$node, $fiche, $language, &$messages){
		$s = file_get_contents($fiche);
		$data = (array) simplexml_load_string($s, 'SimpleXMLElement', LIBXML_NOCDATA);

		$axiomeData = json_decode(json_encode($data),1);
		$node->set('field_axiome_data', serialize($axiomeData));

		// TESTS IF VALID CONTENT
		self::isValidContent($axiomeData, $messages);

		// Creation du top_zone
		$bannerData = $axiomeData['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes'];
		$idOffre = $axiomeData['@attributes']['id'];
		$urlBackground = $idOffre.'/'.$bannerData['background_image']['url_archive'];



		// Top zone
		$content = file_get_contents(
			drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/templating/files/banner/top-zone.html.twig'
		);

		$dom = Html::load($content);

		self::replaceLeftBlock($dom, $bannerData);
		self::replaceCenterBlock($dom, $bannerData);
		self::replaceRightBlock($dom, $bannerData);

		$content = $dom->saveHTML($dom->getElementsByTagName('div')->item(0));
		$node->set('field_top_zone', $content);
		$node->field_top_zone->format = 'full_html';


		//TOP Zone Background
		if (!empty($bannerData['background_image']['url_archive'])){

			$urlBackground = 'public://axiome/fiches/'.$urlBackground;
			$image_media_id = self::createTopZoneBackgroundMedia($node, $urlBackground, $bannerData['background_image'], $language);
			$messages .= 'Url Top zone : '.$urlBackground."\nMedia #".$image_media_id."\n";
			$node->set('field_top_zone_background', $image_media_id);
		}
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

	private static function createTopZoneBackgroundMedia(&$node, $url, $data, $language){

		$imageId = null;
		$styleTopZone = ImageStyle::load('top_zone');
		$styleMedium = ImageStyle::load('medium');
		$styleThumbnail = ImageStyle::load('thumbnail');

		$filesystem = \Drupal::service('file_system');
		// Create file entity.
		$image = File::create();
		$image->setFileUri($url);
		$image->setOwnerId(\Drupal::currentUser()->id());
		$image->setMimeType('image/' . pathinfo($url, PATHINFO_EXTENSION));
		$image->setFileName($filesystem->basename($url));
		$image->setPermanent();
		$image->save();

		$original_image = $url;

		$destination = $styleTopZone->buildUri($url);
		$styleTopZone->createDerivative($original_image, $destination);

		$destination = $styleMedium->buildUri($url);
		$styleMedium->createDerivative($original_image, $destination);

		$destination = $styleThumbnail->buildUri($url);
		$styleThumbnail->createDerivative($original_image, $destination);


// Create media entity with saved file.
		$image_media = Media::create([
			'bundle' => 'image',
			'uid' => \Drupal::currentUser()->id(),
			'langcode' => $language,
			'status' => Media::PUBLISHED,
			'field_image' => [
				'target_id' => $image->id(),
				'alt' => $data['balise_alt'],
				'title' => $data['balise_alt'],
			],
		]);
		$image_media->save();

		return $image_media->id();
	}

	public static function isValidContent($axiomeData, &$message){
		$isValid = true;
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])){
			$message .= "\t WARNING : missing `ruby_zone_header.h1_title`\n";
			$isValid = true;
		}
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['summary'])){
			$message .= "\t WARNING : missing `ruby_zone_header.summary`\n";
			$isValid = true;
		}
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['image']['url_archive'])){
			$message .= "\t WARNING : missing `ruby_zone_header.url_archive`\n";
			$isValid = true;
		}
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['image']['balise_alt'])){
			$message .= "\t WARNING : missing `ruby_zone_header.balise_alt`\n";
			$isValid = true;
		}
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_detailed_contents'])){
			$message .= "\t WARNING : missing `ruby_zone_detailed_contents` \n";
			$isValid = false;
		}
		if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']['background_image']['url_archive'])){
			$message .= "\t WARNING : missing `ruby_zone_banner.background_image.url_archive` \n";
			$isValid = false;
		}

		return $isValid;
	}
}