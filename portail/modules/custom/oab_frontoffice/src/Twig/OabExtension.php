<?php
/**
 * Created by PhpStorm.
 * User: PZHM3753
 * Date: 24/07/2017
 * Time: 15:51
 */
namespace Drupal\oab_frontoffice\Twig;

use Drupal\image\Entity\ImageStyle;

class OabExtension extends \Twig_Extension {

  /**
   * Returns the name of the extension.
   *
   * @return string The extension name
   */
  public function getName() {
    return "OAB Twig extension";
  }

  public function getFilters() {
    $filters = [
      new \Twig_SimpleFilter('format_bytes', [$this, 'format_bytes']),
      new \Twig_SimpleFilter('file_format', [$this, 'file_format']),
      new \Twig_SimpleFilter('image_style_uri', [$this, 'image_style_uri']),
    ];

    return $filters;
  }

  /**
   * Affichage de la taille d'un fichier dans le bon format. (o, Ko, Mo, Go, To)
   * @param $bytes
   * @param int $precision
   * @return string
   */
  function format_bytes($bytes, $precision = 2)
  {
    $units = array('B', 'KB', 'MB', 'GB', 'TB');
    $bytes = max($bytes, 0);
    $pow = floor(($bytes ? log($bytes) : 0) / log(1024));
    $pow = min($pow, count($units) - 1);

    // Uncomment one of the following alternatives
    $bytes /= pow(1024, $pow);

    return round($bytes, $precision) . ' ' . t($units[$pow]);
  }

  /**
   * renvoie l'extension d'un fichier
   * @param $filename
   * @return string
   */
  function file_format ($filename) {

    ##Je recupère toutes les parties du fichier, séparées par un "."
    $fileParts = explode(".", $filename);

    $return = "";
    #Je regarde s'il y a au moins 2 éléments dans le tableau
    if (count($fileParts) > 1) {
      ##Je renvoie le dernier element du tableau
      $return = strtoupper($fileParts[count($fileParts)-1]);
    }
    return $return;
  }

  /**
   * Returns the URL of this image derivative for an original image path or URI.
   *
   * @param string $path
   *   The path or URI to the original image.
   * @param string $style
   *   The image style.
   *
   * @return string
   *   The absolute URL where a style image can be downloaded, suitable for use
   *   in an <img> tag. Requesting the URL will cause the image to be created.
   */
  public function image_style_uri($path, $style) {
    /** @var \Drupal\Image\ImageStyleInterface $image_style */
    if ($image_style = ImageStyle::load($style)) {
      return file_url_transform_relative($image_style->buildUrl($path));
    }
  }
}