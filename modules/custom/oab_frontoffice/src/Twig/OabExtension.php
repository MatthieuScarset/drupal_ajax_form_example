<?php
/**
 * Created by PhpStorm.
 * User: PZHM3753
 * Date: 24/07/2017
 * Time: 15:51
 */
namespace Drupal\oab_frontoffice\Twig;
use Drupal\Core\Url;
use Drupal\image\Entity\ImageStyle;
use Drupal\views\Views;
use Twig\Environment;
use Twig\Extension\AbstractExtension;
use Twig\TwigFilter;
use Twig\TwigFunction;

class OabExtension extends AbstractExtension {

  /**
   * Returns the name of the extension.
   *
   * @return string The extension name
   */
  public function getName() {
    return "OAB Twig extension";
  }

  public function getFunctions() {
      return [
          new TwigFunction('oab_drupal_view', 'views_embed_view'),
          new TwigFunction('oab_drupal_menu', [$this, 'drupalMenu']),
          new TwigFunction('d_config', [$this, 'd_config']),
          new TwigFunction('nodeAbsoluteUrl', [$this, 'nodeAbsoluteUrl']),
          new TwigFunction('oab_drupal_is_empty_field', [$this, 'is_empty_field']),
          new TwigFunction('oab_drupal_view_count', [$this, 'view_count']),
          new TwigFunction('specialCharacters', [$this, 'specialCharacters']),
          new TwigFunction('isAjaxContext', [$this, 'isAjaxContext']),
          new TwigFunction('is_string', [$this, 'isString']),
          new TwigFunction('kint_t', array($this, 'kint_t'), array(
            'is_safe' => array('html'),
            'needs_environment' => TRUE,
            'needs_context' => TRUE,
            'is_variadic' => TRUE,
          )),
        new TwigFunction('replaceSpacesAndSpecialChars', [$this, 'replaceSpacesAndSpecialChars']),
      ];
}

  public function getFilters() {
    $filters = [
      new TwigFilter('format_bytes', [$this, 'format_bytes']),
      new TwigFilter('file_format', [$this, 'file_format']),
      new TwigFilter('image_style_uri', [$this, 'image_style_uri']),
      new TwigFilter('rawurlencode', [$this, 'rawurlencode']),
      new TwigFilter('url_clean_prefix', [$this, 'url_clean_prefix']),
      new TwigFilter('get_files_folder_pardot', [$this, 'get_files_folder_pardot']),
      new TwigFilter('formatDate', [$this, 'formatDate']),
      new TwigFilter('linkAxiome', [$this, 'linkAxiome']),
    ];

    return $filters;
  }

  public function isString($value) {
    return is_string($value);
  }

  /**
   * Ré-écriture de la fonction Kint pour Twig
   *  => Si besoin d'arrêter le script,
   *
   * @param $data
   * @param bool $stop
   */
  public function kint_t(Environment $env, array $context, array $args = []) {
    $module_handler = \Drupal::service('module_handler');
    if ($module_handler->moduleExists('kint')) {
      if (empty($args)) {
        $kint_variable = array();
        foreach ($context as $key => $value) {
          if (!$value instanceof \Twig_Template) {
            $kint_variable[$key] = $value;
          }
        }
      } else {
        $kint_variable = $args;
      }
      kint($kint_variable);
      die();
    } else {
      oabt($args, true);
    }
  }


  public function d_config($config) {
    return \Drupal::config($config);
  }


  /**
   * Affichage de la taille d'un fichier dans le bon format. (o, Ko, Mo, Go, To)
   * @param $bytes
   * @param int $precision
   * @return string
   */
  public function format_bytes($bytes, $precision = 2) {
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
  public function file_format($filename) {

    ##Je recupère toutes les parties du fichier, séparées par un "."
    $file_parts = explode(".", $filename);

    $return = "";
    #Je regarde s'il y a au moins 2 éléments dans le tableau
    if (count($file_parts) > 1) {
      ##Je renvoie le dernier element du tableau
      $return = strtoupper($file_parts[count($file_parts)-1]);
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
    return "";
  }

    /**
     * Returns the render array for Drupal menu.
     *
     * @param string $menu_name
     *   The name of the menu.
     * @param int $level
     *   (optional) Initial menu level.
     * @param int $depth
     *   (optional) Maximum number of menu levels to display.
     *
     * @return array
     *   A render array for the menu.
     */
    public function drupalMenu($menu_name, $level = 1, $depth = 0) {
        /** @var \Drupal\Core\Menu\MenuLinkTreeInterface $menu_tree */
        $menu_tree = \Drupal::service('menu.link_tree');
        $parameters = $menu_tree->getCurrentRouteMenuTreeParameters($menu_name);

        // Adjust the menu tree parameters based on the block's configuration.
        $parameters->setMinDepth($level);
        // When the depth is configured to zero, there is no depth limit. When depth
        // is non-zero, it indicates the number of levels that must be displayed.
        // Hence this is a relative depth that we must convert to an actual
        // (absolute) depth, that may never exceed the maximum depth.
        if ($depth > 0) {
            $parameters->setMaxDepth(min($level + $depth - 1, $menu_tree->maxDepth()));
        }

        $tree = $menu_tree->load($menu_name, $parameters);
        $manipulators = [
            ['callable' => 'menu.default_tree_manipulators:checkAccess'],
            ['callable' => 'menu.default_tree_manipulators:generateIndexAndSort'],
        ];
        $tree = $menu_tree->transform($tree, $manipulators);
        return $menu_tree->build($tree);
    }

  /**
   * Encode un texte avec rawurlencode ( ...les %20 à la place des espaces)
   * @param $url
   * @return string
   */
  public function rawurlencode($url) {
    return rawurlencode($url);
  }

  /**
   * Renvoie l'url absolue d'un noeud
   * @param $type
   * @param $node
   * @return mixed
   */
  public function nodeAbsoluteUrl($type, $nid, $default_language = false) {

      $options = array('absolute' => TRUE);
      if ($default_language) {
            $node = \Drupal\node\Entity\Node::load($nid);
            $options['language'] = $node->language();
        }
        $url = Url::fromRoute($type, array('node' => $nid), $options);
    return $url->toString();
  }

    /**
     * Returns a url without http(s) to avoir SSL warning and other bad bad things
     *
     * @param $url
     */
    public function url_clean_prefix($url) {
      $url = str_replace('https:', '', $url);
      $url = str_replace('http:', '', $url);
      return $url;
    }

    /**
     * Returns a url without http(s) to avoir SSL warning and other bad bad things
     *
     * @param $url
     */
    public function get_files_folder_pardot($uri) {
        $url = \Drupal::getContainer()->get('file_system')->realpath($uri);
        $cursor = strrpos($url, '/files');
        $url = substr($url, $cursor);
        // on enlève la dernière partie
        //$cursor = strrpos($url, '/') + 1;
       // $url = $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['SERVER_NAME'].substr($url, 0, $cursor);
        $url = $_SERVER['REQUEST_SCHEME'].'://'.$_SERVER['SERVER_NAME'].'/sites/default'.$url;
        return $url;
    }

    /**
     * Returns if the field is empty
     *
     * @param Object $field
     *   The field.
         *
     * @return boolean
     *   A render array for the menu.
     */
    public function is_empty_field($field) {
            $empty = true;
        if (!is_null($field)) {
            foreach ($field as $key => $value) {
                if ($key[0] != "#") {
                            $empty = false;
                        }
                    }
                }
        return $empty;
    }

    /**
     * Returns the total rows count for Drupal view.
     *
     * @param string $view_name
     *   The name of the view.
     * @param int $tid
     *   The id of the argument.
     *
     * @return array
     *   A render array for the view.
     */
    public function view_count($view_name, $tid) {
        // recupere la vue
        $args = [$tid];
        $view = Views::getView($view_name);
        $view->setDisplay('block_1');
        $view->setArguments($args);
        $view->preExecute();
        $view->execute();
        //$content = $view->buildRenderable();
        $total_rows = $view->total_rows;

        return [
            'rows' => $total_rows,
            'render' => $view->render('block_1')
        ];
    }

    public function isAjaxContext() {
        return \Drupal::request()->isXmlHttpRequest();
    }

  /**
   * Render a custom date format with Twig
   * Use the internal helper "format_date" to render the date using the current language for texts
   *
   * Permet surtout d'avoir le "Long month name", que ne permet pas la fonction "format_date",
   * ce qui est utile pour les mois RU qui ont deux formats
   */
  public static function formatDate($date, $format) {
    if ($date_format = \DateTime::createFromFormat('Y-m-d', $date)) {
      $timestmap = strtotime($date);
    }elseif (is_a($date, 'Drupal\Core\Datetime\DrupalDateTime') || is_a($date, 'DateTime')) {
      $timestmap = $date->getTimestamp();
    } else {
      $timestmap = $date;
    }

    return \Drupal::service('date.formatter')->format($timestmap, "Node created date", $format);
  }

  public function linkAxiome($content) {
    $content = str_replace("<link", "<a", $content);
    $content = str_replace("</link>", "</a>", $content);
    return $content;
  }

  public function specialCharacters($string) {
    $clean_string = str_replace('\\', '', $string);
    return htmlentities($clean_string);
  }

  public function replaceSpacesAndSpecialChars($string) {
    $clean_string = str_replace(' ', '_', $string);
    $clean_string = str_replace('.', '_', $clean_string);
    $clean_string = strtolower($clean_string);
    $clean_string = \Drupal::transliteration()->transliterate($clean_string);
    $clean_string = preg_replace('@[^a-z0-9_.]+@', '_', $clean_string);
    return htmlentities($clean_string);
  }

}
