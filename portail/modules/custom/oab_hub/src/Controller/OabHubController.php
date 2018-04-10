<?php
namespace Drupal\oab_hub\Controller;

use Masterminds\HTML5\Exception;
use Symfony\Component\Yaml\Yaml;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Path\PathValidator;
use Drupal\system\Entity\Menu;
use Drupal\block\Entity\Block;

class OabHubController extends ControllerBase {

    const HUB_VOCABULARY_ID = "hub";
    const FIELD_MENUS_ID = 'field_hub_menus';
    const FIELD_BLOCS_ID = 'field_hub_blocs';
    const FIELD_SUBHOMES_ID = 'field_hub_subhomes';
    const FIELD_MN_SUFFIXE_ID = 'field_hub_machine_name_suffixe';
    const FIELD_URL_ID = 'field_hub_url';

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
        $machineName = self::getMachineName($term);
        $values = [];
        foreach (self::$elements as $menu_key => $menu_name) {
            $menu_id = self::generateMenuId($menu_key, $machineName, $term_langcode);
            $menu_name = "$menu_name $term_name $term_langcode";

            $menuObj = Menu::load($menu_id);
            $i = 0;

            ##Si le nom machine existe déjà pour un menu, déjà, c'est bizarre....
            ## mais du coup, j'ajoute un chiffre que j'incrémente
            while($menuObj !== null) {
                $menu_id = self::generateMenuId($menu_key, $machineName, $term_langcode, $i);
                $menuObj = Menu::load($menu_id);
                $i++;
                #kint($menuObj);
                #if($i > 3) die("Je suis à plus de 3");
            }
            $menuObj = Menu::create([
                'id' => $menu_id,
                'label' => $menu_name,
                'description' => $menu_name,
                'langcode' => $term_langcode,
                'status' => TRUE,
            ]);
            $save_ret = $menuObj->save();
            if ($save_ret == SAVED_NEW || $save_ret == SAVED_UPDATED) {
                $values[] = $menu_id;
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
            $menuObj = Menu::load($menu_id);
            if(isset($menuObj) || !empty($menuObj)) {
                $menuObj->delete();
            }
        }
    }

    /**
     * Si l'utilisateur n'a pas mis de suffixe pour les machines names, j'en crée un
     * @param \Drupal\taxonomy\Entity\Term $term
     */
    public static function createMachineNameSuffixe(\Drupal\taxonomy\Entity\Term &$term) {
        $machineName_value = $term->get(self::FIELD_MN_SUFFIXE_ID);
        if ($machineName_value->count() == 0) {
            $term_name = $term->label();
            $machine_readable = strtolower($term_name);
            $machine_readable = preg_replace('@[^a-z0-9_]+@','_',$machine_readable);
            $term->set(self::FIELD_MN_SUFFIXE_ID, $machine_readable);
        }
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

        $machineName = false;

        ##je checke que le term passé en paramètre est bien un term de taxo
        if (is_a($term,'\Drupal\taxonomy\Entity\Term' )) {
            $machineName_value = $term->get(self::FIELD_MN_SUFFIXE_ID);
            if($machineName_value->count() > 0) {
                $machineName = $machineName_value->first()->getString();
            }
        }

        return $machineName;
    }

    public static function checkUrl(\Drupal\taxonomy\Entity\Term &$term) {
        $url = $term->get(self::FIELD_URL_ID);
        if ($url->count() > 0 ) {
            $cleanedUrl = \Drupal::service('pathauto.alias_cleaner')->cleanString($url->first()->getString());
            $term->set(self::FIELD_URL_ID, $cleanedUrl);
        }
    }

    public static function createBlocks(\Drupal\taxonomy\Entity\Term &$term) {
        $menus = $term->get(self::FIELD_MENUS_ID);
        $config = self::getConfig();
        $term_langcode = $term->language()->getId();
        $machineName = self::getMachineName($term);
        $term_name = $term->label();
        $base_url = $term->get(self::FIELD_URL_ID)->first()->getString();

        $config_factory = \Drupal::configFactory();

        $blocks = array();          #Pour sauvegarder les id des blocks créés

        foreach ($config['blocks'] as $base_id => $block) {

            $conf = $config['blocks-config'];

            $menu_id = self::getMenuId($term, $base_id);
            if ($menu_id === false) {
                throw new \Exception('Erreur lors de la création des blocks');
            }
            $block_id = self::generateBlockId($base_id, $machineName, $term_langcode);

            ##test de l'existance d'un block
            $i = 0;
            $test_block = \Drupal\block_content\Entity\BlockContent::load($block_id);
            while($test_block !== null) {
                $block_id = self::generateMenuId($base_id, $machineName, $term_langcode, $i);
                $test_block = \Drupal\block_content\Entity\BlockContent::load($block_id);
                $i++;
            }

            $conf["langcode"] = $term_langcode;
            $conf["dependencies"]["config"] = array("system.menu.$menu_id");
            $conf["id"] = $block_id;
            $conf["region"] = $block["region"];
            $conf["plugin"] = "system_menu_block:$menu_id";
            $conf["settings"]["id"] = "system_menu_block:$menu_id";
            $conf["settings"]["label"] = $block["name"] . " $term_name $term_langcode";
            $conf["visibility"]["language"]["langcodes"] = array($term_langcode => $term_langcode);
            $conf["visibility"]["request_path"]["pages"] = "/$base_url/*";

            $conf_name = "block.block.$block_id";

            $config_group = $config_factory->getEditable($conf_name);
            $config_group->setData($conf);
            $config_group->save(TRUE);

            $blocks[] = $block_id;

        }

        $term->set(self::FIELD_BLOCS_ID, $blocks);
    }

    private static function getConfig() {
        $config_path = drupal_get_path('module', 'oab_hub') . '/config/blocks.yml';
        $data = Yaml::parse(file_get_contents($config_path));
        return $data;
    }

    private static function getMenuId(\Drupal\taxonomy\Entity\Term &$term, $block_id) {
        $menus = $term->get(self::FIELD_MENUS_ID);
        $ret = false;
        foreach ($menus as $menu) {
            if (stripos($menu->getString(), $block_id) == 0) {
                $ret = $menu->getString();
            }
        }

        return $ret;
    }

    private static function generateMenuId($elem_key, $machineName, $langcode, $i = null) {
        $ret = "";

        if ($i === null) {
            $ret = $elem_key . "_" . $machineName . "_" . $langcode;
        } else {
            $ret = $elem_key . "_" . $machineName . "_" . $langcode . "_" . $i;
        }

        return $ret;
    }

    private static function generateBlockId($elem_key, $machineName, $langcode, $i = null) {
        return str_replace('_', '', self::generateMenuId($elem_key, $machineName, $langcode, $i));
    }

}