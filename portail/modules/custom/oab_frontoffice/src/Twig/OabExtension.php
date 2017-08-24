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

  public function getFunctions() {
    $filters = [
      /*new \Twig_SimpleFunction('kint_t', [$this, 'kint_t'], array(
      'is_safe' => array('html'),
      'needs_environment' => TRUE,
      'needs_context' => TRUE,
      'is_variadic' => TRUE,
    )),*/
      new \Twig_SimpleFunction('kint_t', [$this, 'kint_t']),
    ];

    return $filters;
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
   * Ré-écriture de la fonction Kint pour Twig
   *  => Si besoin d'arrêter le script,
   *
   * @param $data
   * @param bool $stop
   */
  /*function kint_t(\Twig_Environment $env,  array $context, array $args = []) {

  //A Remettre en place, pour utiliser le vrai fonctionnement
  // de Kint, avec un nombre infini de paramètres;
  //Pour l'instant, problème avec $args, et plantage lorsque var_dump($args)
  // et args semble etre vide.......;

    $stop = false;
    ##Si on a un booléen comme dernier paramètre passé, c'est pas savoir si on
    ##stop le script ou non
    if (count($args) > 0 && is_bool($args[count($args)])) {
      $stop = $args[count($args)];
    }

    ##Ensuite, j'appelle la vraie fonction kint
    call_user_func_array('kint',$args);

    ##Ensuite, si on a demandé à s'arreter, on coupe PHP
    if ($stop)
      die();
  }*/
  function kint_t($array, $stop = false) {
    kint($array);

    if ($stop)
      die();
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