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
use Drupal\media\Entity\Media;
use Drupal\oab_axiome\Form\OabAxiomeSettingsForm;

class AxiomeContentImporter {

  public static function parseContent(&$node, $fiche, $language, &$messages) {
        $s = file_get_contents($fiche);
        $data = (array) simplexml_load_string($s, 'SimpleXMLElement', LIBXML_NOCDATA);

        $axiome_data = json_decode(json_encode($data), 1);
        $node->set('field_axiome_data', serialize($axiome_data));

        // TESTS IF VALID CONTENT
        self::isValidContent($axiome_data, $messages);

        // Creation du top_zone
        $banner_data = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes'];
        $id_offre = $axiome_data['@attributes']['id'];
        // Top zone
        $content = file_get_contents(
          \Drupal::service('extension.path.resolver')->getPath('theme', 'theme_boosted') . '/templates/nodes/axiome_topzone.html.twig'
        );

        /** @var DOMDocument $dom */
        $dom = Html::load($content);

        self::replaceLeftBlock($dom, $banner_data);
        self::replaceCenterBlock($dom, $banner_data);
        self::replaceRightBlock($dom, $banner_data);


        $content = $dom->saveHTML($dom->getElementsByTagName('div')->item(0));
        $node->set('field_top_zone', $content);
        $node->field_top_zone->format = 'full_html';

        //TOP Zone Background
        if (!empty($banner_data['background_image']['url_archive']) && is_string($banner_data['background_image']['url_archive'])) {
            $url_background = $id_offre.$banner_data['background_image']['url_archive'];
            $url_background = 'public://'.AXIOME_FOLDER.'/fiches/'.$url_background;
            $image_media_id = self::createTopZoneBackgroundMedia($node, $url_background, $banner_data['background_image'], $language);
            $messages .= 'Url Top zone : '.$url_background."\nMedia #".$image_media_id."\n";
            $node->set('field_top_zone_background', $image_media_id);
        }

        // Creation image catalog
        if (!empty($banner_data['catalog_image']['url_archive']) && is_string($banner_data['catalog_image']['url_archive'])) {
            $url_catalog = $id_offre.$banner_data['catalog_image']['url_archive'];
            $url_catalog = 'public://'.AXIOME_FOLDER.'/fiches/'.$url_catalog;
            $image_media_id = self::createCatalogMedia($node, $url_catalog, $banner_data['catalog_image'], $language);
            $messages .= 'Url Catalog : '.$url_catalog."\nMedia #".$image_media_id."\n";
            $node->set('field_visual', $image_media_id);
        }

        // changement du title du noeud par le h1_title present dans la fiche XML
        if (!empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])
            && is_string($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])) {
            $messages .= 'CHANGEMENT DE TITRE pour ' . $node->id() . ' :'
                . $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'] . "\n";
            $node->setTitle($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title']);
        }

        //$node->save();
    }

    /**
     * @param DOMDocument $dom
     * @param $banner_data
     */
    private static function replaceLeftBlock(&$dom, $banner_data) {
        $css_class_left_block =  $banner_data['orange_theme']['boosted_css_name'];
        // Si c'est un string, on check la correspondance et tout le reste pour afficher la popup
        // Si y a rien, c'est un tableau qui est renvoyé, on supprime alors la part de l'HTML qui lui est reservé
        if (is_string($css_class_left_block)) {
            $font_color = $banner_data['font_color'];
            //$title_left_block = $bannerData['title']; KO chez Axiome, quick and dirty palliatif ci-dessous
            $class_left_block = str_replace("-", "_", $css_class_left_block);



            $correspondances = \Drupal::config(OabAxiomeSettingsForm::getConfigName())->get();
            $title_left_block = "";
            if ($class_left_block !== '' && isset($correspondances[$class_left_block])) {
                $title_left_block = $correspondances[$class_left_block];
            }

            // change class name
            $nodes = self::getNodesByClass($dom, 'icon-frame-connectivity', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'frame-icon-rel inline text_orange '.$css_class_left_block);
            }

            // change title
            $nodes_span = self::getNodesByClass($dom, 'frame', 'span');
            foreach ($nodes_span as $el) {
                $el->textContent = $title_left_block;
                $el->setAttribute('style', 'color: '.$font_color);
            }
        } else {

            // On hide la col de gauche
            $nodes = self::getNodesByClass($dom, 'leftcol', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'leftcol hidden');
            }

            // Remove default text of frame
            $nodes_span = self::getNodesByClass($dom, 'frame', 'span');
            foreach ($nodes_span as $el) {
                $el->textContent = "";
            }

            // Remove frame class
            $nodes = self::getNodesByClass($dom, 'icon-frame-connectivity', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
            }


            // Si y a pas de bloc à gauche, on aggrandit le bloc central
            $nodes = self::getNodesByClass($dom, 'centercol', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'col col-lg-9 col-md-9 col-sm-9 col-xs-10 centercol');
            }

            // On modifie aussi le bloc central qui remplace le col-offset
            $nodes = self::getNodesByClass($dom, 'empty-div-instead-of-col-offset', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'col col-lg-1 hidden-md hidden-sm empty-div-instead-of-col-offset');
            }

        }
    }

    private static function replaceCenterBlock(&$dom, $banner_data) {
        if (is_string($banner_data['insight'])) {
            $title_center = $banner_data['insight'];

            $font_color = $banner_data['font_color'];
            // change title
            $nodes_span = self::getNodesByClass($dom, 'titre3');
            foreach ($nodes_span as $el) {
                $el->textContent = $title_center;
                $el->setAttribute('style', 'color: '.$font_color);
            }
        } else {
            // Si y a pas, on vire le texte par défaut, et on cache la div complète
            $nodes_span = self::getNodesByClass($dom, 'titre3');
            foreach ($nodes_span as $el) {
                $el->textContent = "";
            }
        }

    }

    private static function replaceRightBlock(&$dom, $banner_data) {
        $css_class_right_block =  $banner_data['pop_out_color']['boosted_css_name'];

        if (is_string($banner_data['pop_out_color']['boosted_css_name'])) {
            $title_right_block = $banner_data['offre_name'];
            $popout_color = $banner_data['pop_out_color']['color'];
            // change class name
            $nodes = self::getNodesByClass($dom, 'icon-popout-connectivity');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'frame-icon-rel inline text_orange '.$css_class_right_block);
                $el->setAttribute('style', 'color: '.$popout_color.' !important');
            }

            // change title
            $nodes_span = self::getNodesByClass($dom, 'popout', 'span');
            foreach ($nodes_span as $el) {
                $el->textContent = $title_right_block;
                // hack pour mettre en blanc qd le fond est noir
                if ($popout_color == '#000000') {
                    $el->setAttribute('style', 'color: #FFF !important');
                }
            }
        } else {
            // On hide la col de gauche
            $nodes = self::getNodesByClass($dom, 'rightcol', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
                $el->setAttribute('class', 'rightcol hidden');
            }

            // Remove default text of popout
            $nodes_span = self::getNodesByClass($dom, 'popout', 'span');
            foreach ($nodes_span as $el) {
                $el->textContent = "";
            }

            // Remove frame class
            $nodes = self::getNodesByClass($dom, 'icon-popout-connectivity', 'div');
            foreach ($nodes as $el) {
                $el->removeAttribute('class');
            }
        }

    }

    private static function getNodesByClass($dom, $classname, $element = "*") {
        $finder = new DomXPath($dom);
        $nodes = $finder->query("//".$element."[contains(@class, '$classname')]");

        return $nodes;
    }

    private static function createTopZoneBackgroundMedia(&$node, $url, $data, $language) {

        $image_id = null;
        $style_top_zone = ImageStyle::load('top_zone');
        $style_medium = ImageStyle::load('medium');
        $style_thumbnail = ImageStyle::load('thumbnail');

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

        $destination = $style_top_zone->buildUri($url);
        $style_top_zone->createDerivative($original_image, $destination);

        $destination = $style_medium->buildUri($url);
        $style_medium->createDerivative($original_image, $destination);

        $destination = $style_thumbnail->buildUri($url);
        $style_thumbnail->createDerivative($original_image, $destination);

        if (empty($data['balise_alt'])) {
            $balise_alt = "";
        } else {
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

    private static function createCatalogMedia(&$node, $url, $data, $language) {

        $image_id = null;
        $style_top_zone = ImageStyle::load('subhome');
        $style_medium = ImageStyle::load('medium');
        $style_thumbnail = ImageStyle::load('thumbnail');

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

        $destination = $style_top_zone->buildUri($url);
        $style_top_zone->createDerivative($original_image, $destination);

        $destination = $style_medium->buildUri($url);
        $style_medium->createDerivative($original_image, $destination);

        $destination = $style_thumbnail->buildUri($url);
        $style_thumbnail->createDerivative($original_image, $destination);

        if (empty($data['balise_alt'])) {
            $balise_alt = "";
        } else {
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

    public static function isValidContent($axiome_data, &$message) {
        $is_valid = true;
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'])) {
            $message .= "\t WARNING : missing `ruby_zone_header.h1_title`\n";
            $is_valid = true;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['summary'])) {
            $message .= "\t WARNING : missing `ruby_zone_header.summary`\n";
            $is_valid = true;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['image']['url_archive'])) {
            $message .= "\t WARNING : missing `ruby_zone_header.url_archive`\n";
            $is_valid = true;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['image']['balise_alt'])) {
            $message .= "\t WARNING : missing `ruby_zone_header.balise_alt`\n";
            $is_valid = true;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_detailed_contents'])) {
            $message .= "\t WARNING : missing `ruby_zone_detailed_contents` \n";
            $is_valid = false;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']
        ['background_image']['url_archive'])) {
            $message .= "\t WARNING : missing `ruby_zone_banner.background_image.url_archive` \n";
            $is_valid = false;
        }
        if (empty($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']['catalog_image']['url_archive'])) {
            $message .= "\t WARNING : missing `ruby_zone_banner.catalog_image.url_archive` \n";
            $is_valid = false;
        }

        return $is_valid;
    }
}
