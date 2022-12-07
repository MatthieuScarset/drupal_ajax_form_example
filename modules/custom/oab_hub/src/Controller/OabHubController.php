<?php
namespace Drupal\oab_hub\Controller;

use Drupal\block\Entity\Block;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Entity\EntityInterface;
use Drupal\system\Entity\Menu;
use Drupal\taxonomy\Entity\Term;
use Symfony\Component\Yaml\Yaml;

class OabHubController extends ControllerBase {

  const HUB_VOCABULARY_ID = "hub";
  const CONFIG_ID = "oab_hub.settings";
  const CONFIG_URL_LIST = "url_list";
  const CONFIG_FORM_REMOVED_SUBHOMES_TIDS = "form_removed_subhome_tids";
  const FIELD_MENUS_ID = 'field_hub_menus';
  const FIELD_BLOCS_ID = 'field_hub_blocs';
  const FIELD_SUBHOMES_ID = 'field_hub_subhomes';
  const FIELD_MN_SUFFIXE_ID = 'field_hub_machine_name_suffixe';
  const FIELD_URL_ID = 'field_hub_url';
  const NODE_FIELD_HUB = 'field_hub';
  const NODE_FIELD_SHARE_ON_PORTAL = 'field_hub_portal';

  private static $elements = [
    'top_navbar' => "Top Navbar",
    'top_right_navbar' => "Top right Navbar",
    'top_right_footer_navbar' => "Top right footer Navbar",
    'main_menu' => "Main menu",
    'direct_access' => "Direct Access",
    'footer' => "Footer"
  ];

  /**
   * Création des menus du nouveau site
   */
  public static function createMenus(\Drupal\taxonomy\Entity\Term &$term) {
    $term_name = $term->label();

    $term_langcode = $term->language()->getId();
    $machine_name = self::getMachineName($term);
    $values = [];

    $default_config = self::getConfig();

    foreach ($default_config['blocks'] as $menu_key => $menu_infos) {
      if ($menu_infos['menu']) {
        $menu_id = self::generateMenuId($menu_key, $machine_name, $term_langcode);
        $menu_name = "$term_name " . $menu_infos['name'] . " $term_langcode";

        $menu_bj = Menu::load($menu_id);
        $i = 0;

        ##Si le nom machine existe déjà pour un menu, déjà, c'est bizarre....
        ## mais du coup, j'ajoute un chiffre que j'incrémente
        while ($menu_bj !== null) {
          $menu_id = self::generateMenuId($menu_key, $machine_name, $term_langcode, $i);
          $menu_bj = Menu::load($menu_id);
          $i++;
          #kint($menuObj);
          #if ($i > 3) die("Je suis à plus de 3");
        }
        $menu_bj = Menu::create([
          'id' => $menu_id,
          'label' => $menu_name,
          'description' => $menu_name,
          'langcode' => $term_langcode,
          'status' => TRUE,
        ]);
        $save_ret = $menu_bj->save();
        if ($save_ret == SAVED_NEW || $save_ret == SAVED_UPDATED) {
          $values[] = $menu_id;
        }
      }

    }

    $term->set(self::FIELD_MENUS_ID, $values);
    return $term;
  }

  /**
   * A la suppression d'une terme, je supprime tous les menus associés
   * @param \Drupal\taxonomy\Entity\Term $term
   */
  public static function deleteMenus(\Drupal\taxonomy\Entity\Term &$term) {
    $menus = $term->get(self::FIELD_MENUS_ID);
    foreach ($menus as $menu) {
      $menu_id = $menu->getString();
      $menu_obj = Menu::load($menu_id);
      if (isset($menu_obj) || !empty($menu_obj)) {
        $menu_obj->delete();
      }
    }
  }

  /**
   * A la suppression d'une terme, je supprime tous les blocks associés
   * @param \Drupal\taxonomy\Entity\Term $term
   */
  public static function deleteBlocks(\Drupal\taxonomy\Entity\Term &$term) {
    $blocks = $term->get(self::FIELD_BLOCS_ID);
    foreach ($blocks as $block) {
      $block_id = $block->getString();
      $block_obj = Block::load($block_id);
      if (isset($block_obj) || !empty($block_obj)) {
        $block_obj->delete();
      }
    }
  }

  /**
   * Si l'utilisateur n'a pas mis de suffixe pour les machines names, j'en crée un
   * @param \Drupal\taxonomy\Entity\Term $term
   */
  public static function createMachineNameSuffixe(\Drupal\taxonomy\Entity\Term &$term) {
    $machine_name_value = $term->get(self::FIELD_MN_SUFFIXE_ID);

    $term_name = "";
    if ($machine_name_value->count() == 0) {
      $term_name = $term->label();
    } else {
      $term_name = $machine_name_value->first()->getString();
    }

    $machine_readable = strtolower($term_name);
    $machine_readable = preg_replace('@[^a-z0-9_]+@', '-', $machine_readable);
    $machine_readable = str_replace('_', '-', $machine_readable);
    $term->set(self::FIELD_MN_SUFFIXE_ID, $machine_readable);
  }

  /**
   * @param $data \Drupal\taxonomy\Entity\Term or term id
   * @return bool or term machine name
   */
  public static function getMachineName($data) {

    ## Si le paramètre passé est un id, on load le term.
    if (is_int($data)) {
      $term = \Drupal\taxonomy\Entity\Term::load($data);
    } else {
      $term = $data;
    }

    $machine_name = false;

    ##je checke que le term passé en paramètre est bien un term de taxo
    if (is_a($term, '\Drupal\taxonomy\Entity\Term')) {
      $machine_name_value = $term->get(self::FIELD_MN_SUFFIXE_ID);
      if ($machine_name_value->count() > 0) {
        $machine_name = $machine_name_value->first()->getString();
      }
    }

    return $machine_name;
  }

  public static function checkUrl(\Drupal\taxonomy\Entity\Term &$term) {
    $url = $term->get(self::FIELD_URL_ID);
    if ($url->count() > 0) {
      $cleaned_url = \Drupal::service('pathauto.alias_cleaner')->cleanString($url->first()->getString());
      $term->set(self::FIELD_URL_ID, $cleaned_url);

      #Quand je check l'URL, je la sauvegarde en bdd pour pouvoir y réacceder facilement
      # lorsqu'on check les themes
      $url_list = \Drupal::config(self::CONFIG_ID)->get(self::CONFIG_URL_LIST);
      if (is_null($url_list) || empty($url_list) || !isset($url_list)) {
        $url_list = [];
      }
      $url_list[] = $cleaned_url;
      $config_factory = \Drupal::configFactory();
      $config_factory->getEditable(self::CONFIG_ID)
        ->set(self::CONFIG_URL_LIST, $url_list)
        ->save(true);

    }
  }

  /**
   * Suppression de tous les nodes qui sont juste pour ce hub, qui ne sont pas partagés
   * Pour ceux partagés, leurs URLs sont supprimées par la fonction deleteUrl
   */
  public static function deleteNodes(\Drupal\taxonomy\Entity\Term &$term) {
    $query = \Drupal::database()->select('taxonomy_index', 'ti');
    $query->fields('ti', array('nid'));
    $query->condition('ti.tid', $term->id());
    $query->distinct(TRUE);
    $result = $query->execute()->fetchCol();

    $nodes = \Drupal\node\Entity\Node::loadMultiple($result);

    foreach ($nodes as $node) {

      ## Recuperation des hubs du nodes
      $hubs = $node->get(self::NODE_FIELD_HUB);

      ## S'il n'a qu'un seul hub, donc que c'est celui qu'on veut supprimer
      ## on le supprime.
      ## S'il en a plusieurs, on ne le supprime pas
      if ($hubs->count() === 1) {
        $node->delete();
      }
    }
  }

  public static function deleteUrl(\Drupal\taxonomy\Entity\Term &$term) {
    $url = $term->get(self::FIELD_URL_ID);
    if ($url->count() > 0) {

      $url = $url->first()->getString();
      $term_langcode = $term->language()->getId();

      # Suppression de l'URL du tableau des urls en conf
      $urls = \Drupal::config(self::CONFIG_ID)->get(self::CONFIG_URL_LIST);

      unset($urls[array_search($url, $urls)]);
      $config_factory = \Drupal::configFactory();
      $config_factory->getEditable(self::CONFIG_ID)
        ->set(self::CONFIG_URL_LIST, $urls)
        ->save(true);


      # Suppression des URLS créées pour les différents contenus
      $connection = \Drupal::database();
      $results = $connection->select('path_alias', 'u')
        ->fields('u', ['path', 'alias', 'langcode'])
        ->condition('langcode', $term_langcode)
        ->execute()
        ->fetchAll();

      foreach ($results as $result) {
        $aliases = \Drupal::entityTypeManager()->getStorage('path_alias')->loadByProperties(array(
          'alias' => $result->alias,
          "langcode"  => $term_langcode));
        $ret = \Drupal::entityTypeManager()->getStorage('path_alias')->delete($aliases);
      }

    }
  }

  public static function createBlocks(\Drupal\taxonomy\Entity\Term &$term) {
    $menus = $term->get(self::FIELD_MENUS_ID);
    $config = self::getConfig();
    $term_langcode = $term->language()->getId();
    $machine_name = self::getMachineName($term);
    $term_name = $term->label();
    $base_url = $term->get(self::FIELD_URL_ID)->first()->getString();

    $config_factory = \Drupal::configFactory();

    $blocks = array();          #Pour sauvegarder les id des blocks créés

    foreach ($config['blocks'] as $base_id => $block) {

      $conf = $config['blocks-config'];

      $menu_id = self::getMenuId($term, $base_id);
      if ($menu_id === false && $block['menu']) {
        throw new \Exception('Erreur lors de la création des blocks');
      }
      $block_id = self::generateBlockId($base_id, $machine_name, $term_langcode);

      ##test de l'existance d'un block
      $i = 0;
      $test_block = Block::load($block_id);
      while ($test_block !== null) {
        $block_id = self::generateBlockId($base_id, $machine_name, $term_langcode, $i);
        $test_block = Block::load($block_id);
        $i++;
      }


      $conf["langcode"] = $term_langcode;
      $conf["id"] = $block_id;
      $conf["region"] = $block["region"];
      $conf["settings"]["label"] = $block["name"] . " $term_name $term_langcode";
      $conf["visibility"]["language"]["langcodes"] = array($term_langcode => $term_langcode);
      //$conf["visibility"]["request_path"]["pages"] = "/$base_url*";
      $config["visibility"]["hub"]["hub_id"] = $term->id();

      if ($block['menu']) {
        $conf["dependencies"]["config"] = array("system.menu.$menu_id");
        $conf["plugin"] = "system_menu_block:$menu_id";
        $conf["settings"]["id"] = "system_menu_block:$menu_id";
      } else {
        $conf["plugin"] = $base_id;
        $conf["settings"]["id"] = $base_id;
        unset($conf["dependencies"]["config"]);
      }

      $conf_name = "block.block.$block_id";

      $config_group = $config_factory->getEditable($conf_name);
      $config_group->setData($conf);
      $config_group->save(TRUE);

      $blocks[] = $block_id;

    }
    $term->set(self::FIELD_BLOCS_ID, $blocks);
  }

  /**
   * Retourne la config complète des blocks
   */
  private static function getConfig() {
    $config_path = \Drupal::service('extension.path.resolver')->getPath('module', 'oab_hub') . '/config/blocks.yml';
    $data = Yaml::parse(file_get_contents($config_path));
    return $data;
  }

  /**
   * Retourne les id des blocks et menus qui sont dans la config par défaut
   */
  public static function getDefaultBlockName() {
    $conf = self::getConfig();
    $ret = [];
    foreach ($conf['blocks'] as $block_name => $block_config) {
      $ret[] = $block_name;
    }
    return $ret;
  }

  private static function getMenuId(\Drupal\taxonomy\Entity\Term &$term, $block_id) {
    $menus = $term->get(self::FIELD_MENUS_ID);
    $ret = false;
    foreach ($menus as $menu) {
      if (stripos(str_replace('-', '_', $menu->getString()), $block_id) === 0) {
        $ret = $menu->getString();
      }
    }
    return $ret;
  }

  private static function generateMenuId($elem_key, $machine_name, $langcode, $i = null) {
    $ret = "";

    if ($i === null) {
      $machine_name = substr($machine_name, 0, 27 - strlen($elem_key . "-" ."-" . $langcode));
      $ret = $elem_key . "-" . $machine_name . "-" . $langcode;
    } else {
      $machine_name = substr($machine_name, 0, 27 - strlen($elem_key . "-" ."-" . $langcode. "-" . $i));
      $ret = $elem_key . "-" . $machine_name . "-" . $langcode . "-" . $i;
    }

    return str_replace('_', '-', $ret);
  }

  private static function generateBlockId($elem_key, $machine_name, $langcode, $i = null) {
    return str_replace('-', '', self::generateMenuId($elem_key, $machine_name, $langcode, $i));
  }


  public static function createSubhomesUrl(\Drupal\taxonomy\Entity\Term &$term) {

    $url_object = $term->get(self::FIELD_URL_ID);
    $langcode = \Drupal::languageManager()->getCurrentLanguage()->getId();

    if ($url_object->count() > 0) {
      $base_url = $url_object->first()->getString();

      $subhomes = $term->get(self::FIELD_SUBHOMES_ID);

      $subhomes_tid = [];
      $i = 0;
      while ($i < $subhomes->count()) {

        $subhome = $subhomes->get($i);
        $elem_value = $subhome->getValue();

        $subhomes_tid[] = $elem_value['target_id'];

        $i++;
      }

      $terms = \Drupal\taxonomy\Entity\Term::loadMultiple($subhomes_tid);

      foreach ($terms as $term) {
        $term_name = $term->getName();
        $display = $term->get('field_related_display_view');
        if ($display->count() > 0) {
          $display_name = $display->first()->getString();
          $url = \Drupal\Core\Url::fromRoute("view.subhomes.$display_name");


          $view = \Drupal\views\Views::getView('subhomes');
          $view->setDisplay($display_name);
          $origin_url = $view->getPath();

          $alias = \Drupal::entityTypeManager()->getStorage('path_alias')->loadByProperties(['path' => $url->toString()]);

          $alias_parts = isset($alias[0]) ? explode('/', $alias[0]->getPath()): [];

          if (isset($alias_parts[0]) && $alias_parts[0] === "") {
            array_shift($alias_parts);
          }
          if (count($alias_parts)>1) {
            $subhome_url = $alias_parts[count($alias_parts)-1];
            \Drupal::entityTypeManager()->getStorage('path_alias')
              ->create([
                'path' => "/". $origin_url,
                'alias' => "/$base_url/$subhome_url",
                'langcode' =>$langcode])
              ->save();
          } else {
            \Drupal::messenger()->addError(t("L'URL pour la subhome @term n'a pas pu être créée pour ce hub.", ['@term', $term]), true);
          }
        } else {
          \Drupal::messenger()->addError(t("L'URL pour la subhome @term n'a pas pu être créée pour ce hub.", ['@term', $term]), true);
        }
      }
    }
  }

  /**
   * @return EntityInterface|Term|null
   */
  public static function getActifHub() {
    $term = null;

    if (($url = self::getHubPartOfUrl()) !== false) {
      $term = self::getTermFromUrl($url);
    }

    return $term;
  }


  /**
   * Return prefixes of hub that are stored in Config
   * @return array
   */
  public static function getAllHubPrefixes(): array {
    return \Drupal::config(self::CONFIG_ID)->get(self::CONFIG_URL_LIST) ?? [];
  }


  //TODO faire une fonction pour recuperer le hub en fonction de l'URL
    public static function getHubPartOfUrl() {
        $url_list = self::getAllHubPrefixes();
        if (is_null($url_list) || empty($url_list) || !isset($url_list)) {
            $url_list = [];
        }

        $actif_hub = false;

        /*
         * Sometimes, the Request is not yet instantiate
         */
        if ($request = \Drupal::request()) {
          $url = $request->getPathInfo();
        } else {
          $url = str_replace("?" . $_SERVER["QUERY_STRING"], "", $_SERVER['REQUEST_URI']);
        }

        ##Je recupère toutes les parties de la route
        $route_parts = explode('/', $url);

        #Je supprime le 1er element qui est vide
        if (isset($route_parts[0]) && strlen($route_parts[0]) == 0) {
          array_shift($route_parts);
        }



        if (isset($route_parts[1])) {
          $hub_part = $route_parts[1];

          foreach ($url_list as $hub => $url) {
            if ($url == $hub_part) {
              $actif_hub = $url;
            }
          }
        }



        return $actif_hub;
    }

  /**
   * @return Term[]
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
    public static function getAllHubTerms() {
      return \Drupal::entityTypeManager()
        ->getStorage('taxonomy_term')
        ->loadTree('hub', 0, NULL, TRUE);
    }

  public static function getTermFromUrl($url) {
      $res = \Drupal::entityQuery('taxonomy_term')
        ->condition(self::FIELD_URL_ID, $url)
        ->execute();

      $ret = null;

      if (count($res) > 0) {
        $tid = reset($res);
        $ret = Term::load($tid);
      }

      return $ret;
  }

  /**
   * @deprecated Do not use it anymore
   */
    public static function getNodeUrl($nid) {
        $url = \Drupal::request()->getRequestUri();


        ##Je recupère toutes les parties de la route
        $route_parts = explode('/', $url);

        #Je supprime le 1er element qui est vide
        if (isset($route_parts[0]) && strlen($route_parts[0]) == 0) {
            array_shift($route_parts);
        }
        $actual_url = $route_parts[1];

        $langcode = \Drupal::languageManager()->getCurrentLanguage()->getId();
        $connection = \Drupal::database();
        $results = $connection->select('path_alias', 'u')
            ->fields('u', ['path', 'alias', 'langcode'])
            ->condition('langcode', $langcode)
            ->execute()
            ->fetchAll();

        $ret = "";
        if (count($results)>0) {
            $ret = "/" . $results[0]->langcode . $results[0]->alias;
        } else {
            $alias = \Drupal::service('path_alias.manager')->getAliasByPath("/node/$nid", $langcode);
            $ret = "/" . $langcode . $alias ;
        }

        return $ret;
    }

    public static function getHubBaseUrl($absolute = false) {
        #Path du noeud (sous la forme /node/id
        $url = \Drupal::request()->getRequestUri();


        ##Je recupère toutes les parties de la route
        $route_parts = explode('/', $url);

        #Je supprime le 1er element qui est vide
        if (isset($route_parts[0]) && strlen($route_parts[0]) == 0) {
            array_shift($route_parts);
        }

        $hub_url = $route_parts[1];
        # Je recupère les URLS des hubs
        $urls = \Drupal::config(OabHubController::CONFIG_ID)->get(OabHubController::CONFIG_URL_LIST);

        $is_hub = false;
        ##Je teste si on a bien recu un tableau, au cas ou...
        if (is_array($urls)) {
            #l'URL du hub est le 1er element du tableau
            $is_hub = in_array($hub_url, $urls);
        }

        if (!$is_hub) {
            return false;
        }

        $host = "";
        if ($absolute) {
            $host = \Drupal::request()->getHost();
        }

        $langcode = \Drupal::languageManager()->getCurrentLanguage()->getId();
        return "$host/$langcode/$hub_url";

    }

  /**
   * @deprecated Do not use it anymore. Change have been done in AliasRepository
   */
    public static function getHubSubhomeUrl($url_cible, $add_internal = true) {

        $url_to_test = $url_cible;
        if (is_object($url_to_test) && method_exists($url_to_test, 'toString')) {
            $url_to_test = $url_cible->toString();
        }

        if (\Drupal\Component\Utility\UrlHelper::isExternal($url_to_test)) {
            return $url_cible;
        }

        # Je recupère les URLS des hubs
        $urls_hub = \Drupal::config(OabHubController::CONFIG_ID)->get(OabHubController::CONFIG_URL_LIST);


        $cur_url = \Drupal::request()->getRequestUri();
        ##Je recupère toutes les parties de la route
        $route_parts = explode('/', $cur_url);
        #Je supprime le 1er element qui est vide
        if (isset($route_parts[0]) && strlen($route_parts[0]) == 0) {
            array_shift($route_parts);
        }
        if (count($route_parts)>2) {
            $part_url = $route_parts[1];
        } else {
            $part_url = "";
        }

        $is_hub_curr = false;
        ##Je teste si on a bien recu un tableau, au cas ou...
        if (is_array($urls_hub)) {
            #l'URL du hub est le 1er element du tableau
            $is_hub_curr = in_array($part_url, $urls_hub);
        }

        if (is_object($url_cible)) {
            $route_parts_cible = explode('/', $url_cible->toString());
        } else {
            $route_parts_cible = explode('/', $url_cible);
        }
        if (isset($route_parts_cible[0]) && strlen($route_parts_cible[0]) == 0) {
            array_shift($route_parts_cible);
        }

        // Si je cherche la home, je renvoie avant.
        if (!isset($route_parts_cible[1])) {
            return $url_cible;
        }


        $part_url_cible = $route_parts_cible[1];
        $is_hub_cible = false;
        ##Je teste si on a bien recu un tableau, au cas ou...
        if (is_array($urls_hub)) {
            #l'URL du hub est le 1er element du tableau
            $is_hub_cible = in_array($part_url_cible, $urls_hub);
        }

        if (!$is_hub_curr) {
            //pas de contexte hub on envois une adresse normale
            if (!$is_hub_cible) {
                //hos context hub , cible hors context hub => ok
                $new_url = $url_cible;
            } else {
                //hos context hub , cible context hub => on retravail la cible
                unset($route_parts_cible[1]);
                $new_url = "/" . implode("/", $route_parts_cible);
            }
        } else {
            //context hub
            if ($route_parts[1]<>$route_parts_cible[1]) {
                $route_parts_cible[1] = $route_parts[1];
                $new_url = "/" . implode("/", $route_parts_cible);
            } else {
                $new_url = $url_cible;
            }
        }

        if (!is_object($new_url) && $add_internal) {
            if (strpos($new_url, '/') == 0) {
                $new_url = substr($new_url, 1);
            }

           $new_url = 'internal:/' . $new_url;
           $new_url =  str_replace("/index.php", '', $new_url);
        }

        return $new_url;
    }

}
