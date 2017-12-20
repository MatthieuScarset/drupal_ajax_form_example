<?php
namespace Drupal\oab_dvi;

use Reflection;
use ReflectionClass;


abstract class DviHelper {

    /**
     * Convention de nommage
     *
     * Voca en 2/3/4 lettres
     * Nom Term
     * Langue du term en 2 lettres
     */
    const MS_U50_EMPLOYEES_EN = "- 50 employees";
    const MS_U50_EMPLOYEES_FR = "- 50 salariés";
    const MS_PUBLIC_SECTOR_EN = "Public Sector";
    const MS_PUBLIC_SECTOR_FR = "Secteur Public";


    private static function getConstants() {
        $oClass = new ReflectionClass(__CLASS__);
        return $oClass->getConstants();
    }

    private static function getMS_All() {

        $return = array();
        foreach (self::getConstants() as $constName => $value) {

        }

        return [
            'EN'    => [
                self::U50_EMPLOYEES_EN,
                self::PUBLIC_SECTOR_EN
            ],
            'FR'    => [
                self::U50_EMPLOYEES_FR,
                self::PUBLIC_SECTOR_FR
            ]
        ];
    }

    public static function getMSTerms($params = array()) {
        $return = array();
        ##Si on passe un langcode, on renvoie les éléments de la langue
        if (isset($params['lang'])) {
            $lang = strtoupper($params['lang']);
            $all = self::getAll();
            if (isset($all[$lang]))
                $return = $all[$lang];

         ## Si on passe un sort, on renvoie les elements triés par lang
        } elseif (isset($params['sort']) && $params['sort'] == "lang") {
            $return = self::getAll();

        ##Sinon, je renvoie un tableau de tous les elements
        } else {
            foreach (self::getAll() as $lang => $terms) {
                $return= array_merge($return, $terms);
            }
        }
        return $return;
    }

    public static function getMSTaxoTerms() {
        $terms = self::getMSTerms();
        $terms_ids = array();

        foreach ($terms as $key => $term) {
            //vérification de l'existance du terme pour ce vocabulaire
            $queryTaxo = \Drupal::entityQuery('taxonomy_term');
            $queryTaxo->condition('vid', "market_segments");
            $queryTaxo->condition('name', $term);
            $entity = $queryTaxo->execute();
            if ( $entity !== null) {
                $terms_ids[] = key($entity);
            }
        }
    }

    public static function isDVIProduct($node){
        $dvi_product = FALSE;
        if($node->type->entity->get('type') == "product"){
            //initialisation des tid DVI
            $default_labels = array(
                "fr" => array('- 50 salariés', 'Secteur Public'),
                "en" => array('- 50 employees', 'Public Sector')
            );
            $default_values = array();
            foreach ($default_labels as $lang => $labels)
            {
                $default_values[$lang] = array();
                foreach ($labels as $label) {
                    $query = \Drupal::entityQuery('taxonomy_term');
                    $query->condition('vid', 'market_segments');
                    $query->condition('name', $label);
                    $query->condition('langcode', $lang);
                    $entity = $query->execute();

                    if (!empty($entity)) {
                        $default_values[$lang][] = array_pop($entity);
                    }
                }
            }

            //on regarde le produit
            if (isset($node->field_market_segment)) {
                //récupération des tag market segment du produit
                $field_market_segment = $node->field_market_segment->getValue();
                if (!empty($field_market_segment) && count($field_market_segment)>0) {
                    //pour chaque tag on regarde s'il y en a un dvi
                    foreach ($field_market_segment as $values){
                        if(in_array($values['target_id'], $default_values[$node->language()->getId()])){
                            $dvi_product = TRUE;
                        }
                    }
                }
            }
        }
        return $dvi_product;
    }
}
