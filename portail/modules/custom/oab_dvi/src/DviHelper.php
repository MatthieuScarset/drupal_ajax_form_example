<?php
namespace Drupal\oab_dvi;

use Reflection;
use ReflectionClass;


abstract class DviHelper {

################################
################################
#################################
## CONSTANTES
    /**
     * Convention de nommage
     *
     * Voca en 2/3/4 lettres
     * Nom Term
     * Langue du term en 2 lettres
     */
    const MS_U50_EMPLOYEES_EN = "- 50 employees";
    const MS_U50_EMPLOYEES_FR = "moins-50-salaries";
    const MS_PUBLIC_SECTOR_EN = "Public Sector";
    const MS_PUBLIC_SECTOR_FR = "secteur-public";
    const SUBHOME_PRODUIT_DVI_TERM_EN = 'Products DVI';
    const SUBHOME_PRODUIT_DVI_TERM_FR = 'Produits DVI';
    const FIELD_SUBHOME_NAME = 'field_subhome';
    const FIELD_DVI_MARKET_SEGMENT_NAME = 'field_market_segment_dvi';
    const FIELD_IS_DVI_PRODUCT_NAME = 'field_is_dvi_product';
    const DVI_PRODUCT_URL = 'ventes-indirectes';

################################
################################
################################
## VARIABLES
    /**
     * VARIABLES UTILES DANS DviHelper
     */
    #private static $default_field_market_segment = 'field_market_segment';
    private static $subhome_field_name = 'field_subhome';
    private static $default_field_market_segment = 'field_market_segment_dvi';


################################
################################
################################
## PRIVATE FUNCTIONS
    /**
     * Renvoie la liste des constantes définies
     * @return array liste des contraintes
     */
    private static function getConstants() {
        $oClass = new ReflectionClass(__CLASS__);
        return $oClass->getConstants();
    }

    /**
     * Retourne sous forme de tableau construit selon la langue, tous les termes de taxo de Market Segment
     * @return array [ LANG => [values], LANG => [$values] ]
     */
    private static function getMS_all() {

        $return = array();
        foreach (self::getConstants() as $constName => $value) {
            ##Je check si c'est des MarketSegment
            if (substr($constName, 0,2) == "MS") {
                $return[substr($constName, strlen($constName)-2,strlen($constName))][] = $value;
            }
        }

        return $return;
    }


    public static function getProductDviSubhomeTid () {
        $config = \Drupal::config('oab.subhomes');
        return $config->get('product_dvi_term_tid');
    }


################################
################################
################################
## PUBLICS FUNCTIONS


    /**
     * Renvoie les termes de taxo sous forme de tableau. Possibilité de trier/filtrer par langue
     * params :
     *      - lang : Renvoie les termes de la langue correspondante
     *      - sort : Renvoie les termes triés par langue
     * @param array $params
     * @return array|mixed
     */
    public static function getMSTerms($params = array()) {
        $terms = self::getMS_all();

        $return = array();
        ##Si on passe un langcode, on renvoie les éléments de la langue
        if (isset($params['lang'])) {
            $lang = strtoupper($params['lang']);
            if (isset($terms[$lang]))
                $return = $terms[$lang];

         ## Si on passe un sort, on renvoie les elements triés par lang
        } elseif (isset($params['sort']) && $params['sort'] == "lang") {
            $return = $terms;

        ##Sinon, je renvoie un tableau de tous les elements
        } else {
            foreach ($terms as $lang => $langTerms) {
                $return = array_merge($return, $langTerms);
            }
        }

        return $return;
    }

    /**
     * Renvoie les ID des termes de taxo de Market Segment
     * Si une langue est passée en paramètre, renvoie seulement les taxos de la langue
     *
     * @param null $lang
     * @return array
     */
    public static function getMSTaxoTermsIds($lang = null) {
        $return = array();
        $params = array();
        if ($lang !== null) {
            $params["lang"] = $lang;
        }
        $default_labels = self::getMSTerms($params);


        foreach ($default_labels as $label) {

            if (false !== $tid = self::getMSTaxoTermId($label, $lang)) {
                $return[] = $tid;
            }
/*
            $query = \Drupal::entityQuery('taxonomy_term');
            $query->condition('vid', 'market_segments');
            $query->condition('name', $label);
            if ($lang !== null) {
                $query->condition('langcode', $lang);
            }
            $entity = $query->execute();

            if (!empty($entity)) {
                $return[] = key($entity);
            }*/
        }

        if (count($return) == 0 ) {
            \Drupal::logger('DviHelper')->notice("Erreur avec les termes taxo Market Segment pour DVI : il semble qu'ils ne soient pas corrects - Aucune entité trouvée pour les termes fournis");
        }

        return $return;
    }

    /**
     * Renvoie l'id du term passé en paramètre
     * @param $taxoTerm
     * @param null $lang
     * @return bool|int|null|string
     */
    public static function getMSTaxoTermId($taxoTerm, $lang = null) {
        $return = false;
        $query = \Drupal::entityQuery('taxonomy_term');
        $query->condition('vid', 'market_segments');
        $query->condition('name', $taxoTerm);
        if ($lang !== null) {
            $query->condition('langcode', $lang);
        }
        $entity = $query->execute();

        if (!empty($entity)) {
            $return = key($entity);
        }

        return $return;
    }

    /**
     * Dit si le node passé en paramètre possède un terme de MS spécifique à DVI
     * @param \Drupal\node\Entity\Node $node
     * @param null $fieldName
     * @return bool
     */
    public static function hasMSTaxoTerm(\Drupal\node\Entity\Node $node, $fieldName = null) {
        $return = false;

        ##Je peux pas attribuer une valeur par défaut issue d'une variable
        ##Du coup, j'init par défaut à false, et si c'est false, je set avec la valeur par défaut
        if ($fieldName == null) {
            $fieldName = self::$default_field_market_segment;
        }

        $lang = $node->language()->getId();
        $ms_termsIds = self::getMSTaxoTermsIds($lang);

        //on regarde le produit
        if ( isset($node->$fieldName)) {
            //récupération des tag market segment du produit
            $fieldValue = $node->$fieldName->getValue();
            if (!empty($fieldValue)) {
                //pour chaque tag on regarde s'il y en a un dvi
                foreach ($fieldValue as $values){
                    if(isset($values['target_id']) && in_array($values['target_id'], $ms_termsIds)){
                        $return = TRUE;
                    }
                }
            }
        }

        return $return;
    }

    /**
     * Dit si la Node passé en paramètre est un produit DVI ou non (ie. s'il possède un des
     * termes de la taxo MS qui sont en constantes)
     *
     * @param \Drupal\node\Entity\Node $node
     * @param string $fieldName
     * @return bool
     */
    public static function isDVIProduct(\Drupal\node\Entity\Node $node){
        $dvi_product = FALSE;
        ## First, on check si le node est bien un produit
        if($node->type->entity->get('type') == "product"){

            ##Ensuite, on demande si on a un des terme de taxo de DVI
            $dvi_product = self::hasMSTaxoTerm($node);
        }
        return $dvi_product;
    }

    /**
     * Dit si le term passé en paramètre est un market segment
     * @param $term
     * @return bool
     */
    public static function isMSTerm($term) {
        $ms_terms = self::getMSTerms();
        return in_array($term, $ms_terms);
    }
}
