<?php
namespace Drupal\oab_hub\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\system\Entity\Menu;
use Drupal\block\Entity\Block;

class OabHubController extends ControllerBase {

    const HUB_VOCABULARY_ID = "hub";
    const FIELD_MENUS_ID = 'field_hub_menus';
    const FIELD_SUBHOMES_ID = 'field_hub_subhomes';

    private static $menus = [
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
        $machine_readable = strtolower($term_name);
        $machine_readable = preg_replace('@[^a-z0-9_]+@','_',$machine_readable);

        $term_langcode = $term->language()->getId();

        $values = [];
        foreach (self::$menus as $menu_key => $menu_name) {
            $menu_id = $menu_key . "_" . $machine_readable;
            $menu_name = "$menu_name $term_name";

            $menuObj = Menu::load($menu_id);
            if(!isset($menuObj) || empty($menuObj)) {
                $menuObj = Menu::create([
                    'id' => $menu_id,
                    'label' => $menu_name,
                    'description' => $menu_name,
                    'langcode' => $term_langcode,
                    'status' => TRUE,
                ]);
                $save_ret = $menuObj->save();
                if( $save_ret == SAVED_NEW || $save_ret == SAVED_UPDATED) {
                    $values[] = $menu_id;
                }
            }
        }
        $term->set(self::FIELD_MENUS_ID,$values );
        $term->save();
    }

    /**
     * A la suppression d'une terme, je supprime tous les menus associés
     * @param \Drupal\taxonomy\Entity\Term $term
     */
    public static function deleteMenus(\Drupal\taxonomy\Entity\Term &$term) {
        $menus = $term->get(self::FIELD_MENUS_ID);
        foreach ($menus as $menu) {
            $value = $menu->getValue();
            $menu_id = $value['value'];
            $menuObj = Menu::load($menu_id);
            if(isset($menuObj) || !empty($menuObj)) {
                $menuObj->delete();
            }
        }
    }
}