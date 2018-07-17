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

		// Top zone
		$content = file_get_contents(
			drupal_get_path('theme', 'theme_boosted') . '/templates/nodes/axiome_topzone.html.twig'
		);

		$dom = Html::load($content);

		self::replaceLeftBlock($dom, $bannerData);
		self::replaceCenterBlock($dom, $bannerData);
		self::replaceRightBlock($dom, $bannerData);


		$content = $dom->saveHTML($dom->getElementsByTagName('div')->item(0));
		$node->set('field_top_zone', $content);
		$node->field_top_zone->format = 'full_html';

		//TOP Zone Background
        if (!empty($bannerData['background_image']['url_archive']) && is_string($bannerData['background_image']['url_archive'])){
            $urlBackground = $idOffre.$bannerData['background_image']['url_archive'];
			$urlBackground = 'public://'.AXIOME_FOLDER.'/fiches/'.$urlBackground;
			$image_media_id = self::createTopZoneBackgroundMedia($node, $urlBackground, $bannerData['background_image'], $language);
			$messages .= 'Url Top zone : '.$urlBackground."\nMedia #".$image_media_id."\n";
			$node->set('field_top_zone_background', $image_media_id);
		}

        // Creation image catalog
        if (!empty($bannerData['catalog_image']['url_archive']) && is_string($bannerData['catalog_image']['url_archive'])){
            $urlCatalog = $idOffre.$bannerData['catalog_image']['url_archive'];
            $urlCatalog = 'public://'.AXIOME_FOLDER.'/fiches/'.$urlCatalog;
            $image_media_id = self::createCatalogMedia($node, $urlCatalog, $bannerData['catalog_image'], $language);
            $messages .= 'Url Catalog : '.$urlCatalog."\nMedia #".$image_media_id."\n";
            $node->set('field_visual', $image_media_id);
        }

        // changement du title du noeud par le h1_title present dans la fiche XML
        if(!empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])
        && is_string($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])) {
            $messages .= 'CHANGEMENT DE TITRE pour '.$node->id().' :'.$axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title']."\n";
            $node->setTitle($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title']);
        }

        //$node->save();
	}

    /**
     * @param $dom
     * @param $bannerData
     */
    private static function replaceLeftBlock(&$dom, $bannerData){
        $cssClassLeftBlock =  $bannerData['orange_theme']['boosted_css_name'];
        $fontColor = $bannerData['font_color'];

        //$titleLeftBlock = $bannerData['title']; KO chez Axiome, quick and dirty palliatif ci-dessous

        $ClassLeftBlock = str_replace("-","_",$cssClassLeftBlock);
        $titleLeftBlock = \Drupal::config('oab.axiome')->get($ClassLeftBlock);

        // change class name
		$nodes = self::getNodesByClass($dom, 'icon-frame-connectivity', 'div');
		foreach($nodes as $el) {
			$el->removeAttribute('class');
			$el->setAttribute('class', 'frame-icon-rel inline text_orange '.$cssClassLeftBlock);
		}

		// change title
		$nodesSpan = self::getNodesByClass($dom, 'frame', 'span');
		foreach($nodesSpan as $el) {
			$el->textContent = $titleLeftBlock;
            $el->setAttribute('style', 'color: '.$fontColor);
		}

	}

	private static function replaceCenterBlock(&$dom, $bannerData){
		$titleCenter = $bannerData['insight'];
        $fontColor = $bannerData['font_color'];
		// change title
		$nodesSpan = self::getNodesByClass($dom, 'titre3');
		foreach($nodesSpan as $el) {
			$el->textContent = $titleCenter;
            $el->setAttribute('style', 'color: '.$fontColor);
		}

	}

	private static function replaceRightBlock(&$dom, $bannerData){
		$cssClassRightBlock =  $bannerData['pop_out_color']['boosted_css_name'];
		$titleRightBlock = $bannerData['offre_name'];
		$popoutColor = $bannerData['pop_out_color']['color'];
		// change class name
		$nodes = self::getNodesByClass($dom, 'icon-popout-connectivity');
		foreach($nodes as $el) {
            $el->removeAttribute('class');
            $el->setAttribute('class', 'frame-icon-rel inline text_orange '.$cssClassRightBlock);
            $el->setAttribute('style', 'color: '.$popoutColor.' !important');
		}

		// change title
		$nodesSpan = self::getNodesByClass($dom, 'popout', 'span');
		foreach($nodesSpan as $el) {
			$el->textContent = $titleRightBlock;
			// hack pour mettre en blanc qd le fond est noir
			if($popoutColor == '#000000'){
                $el->setAttribute('style', 'color: #FFF !important');
            }
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

		if(empty($data['balise_alt'])){
            $balise_alt = "";
        }else{
            $balise_alt = $data['balise_alt'];
        }

// Create media entity with saved file.
		$image_media = Media::create([
			'bundle' => 'image',
			'uid' => \Drupal::currentUser()->id(),
			'langcode' => $language,
			'status' => Media::PUBLISHED,
			'field_image' => [
				'target_id' => $image->id(),
				'alt' => $balise_alt,
				'title' => $balise_alt,
			],
		]);
		$image_media->save();

		return $image_media->id();
	}

    private static function createCatalogMedia(&$node, $url, $data, $language){

        $imageId = null;
        $styleTopZone = ImageStyle::load('subhome');
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

        if(empty($data['balise_alt'])){
            $balise_alt = "";
        }else{
            $balise_alt = $data['balise_alt'];
        }

        $image_media = Media::create([
            'bundle' => 'image',
            'uid' => \Drupal::currentUser()->id(),
            'langcode' => $language,
            'status' => Media::PUBLISHED,
            'field_image' => [
                'target_id' => $image->id(),
                'alt' => $balise_alt,
                'title' => $balise_alt,
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
        if(empty($axiomeData['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']['catalog_image']['url_archive'])){
            $message .= "\t WARNING : missing `ruby_zone_banner.catalog_image.url_archive` \n";
            $isValid = false;
        }

		return $isValid;
	}
}