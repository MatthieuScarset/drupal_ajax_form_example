<?php
namespace Drupal\oab_dvi;

use Reflection;
use ReflectionClass;
use \Drupal\taxonomy\Entity\Term;

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
    /*const MS_U50_EMPLOYEES_EN = "- 50 employees";
    const MS_U50_EMPLOYEES_FR = "moins-50-salaries";
    const MS_PUBLIC_SECTOR_EN = "Public Sector";
    const MS_PUBLIC_SECTOR_FR = "secteur-public";*/
    const SUBHOME_PRODUIT_DVI_TERM_EN = 'Products DVI';
    const SUBHOME_PRODUIT_DVI_TERM_FR = 'Produits DVI';
    const MS_PUBLIC_SECTOR_FR = "secteur-public";
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
    private static $subhome_field_name = 'field_subhome';
    private static $default_field_market_segment = 'field_market_segment_dvi';
    private static $dvi_market_segment_vocabulary = 'market_segments_dvi';


################################
################################
################################
## PRIVATE FUNCTIONS

    public static function getProductDviSubhomeTid ($langcode = null) {
      if (is_null($langcode)) $langcode = \Drupal::languageManager()->getCurrentLanguage()->getId();
      if ($langcode == \Drupal::languageManager()->getDefaultLanguage()->getId()) {
        $config = \Drupal::config('oab.subhomes');
        return $config->get('product_dvi_term_tid');
      }
      else{
        $config = \Drupal::service('config.storage')->createCollection('language.'.$langcode);
        $subhomes = $config->read('oab.subhomes');
        if (isset($subhomes['product_dvi_term_tid'])) {
          return $subhomes['product_dvi_term_tid'];
        }
        else{
          return false;
        }
      }
    }


################################
################################
################################
## PUBLICS FUNCTIONS

    /**
     * Renvoie les termes de taxo sous forme de tableau. Possibilité de filtrer par langue
     *   lang : Renvoie les termes de la langue correspondante, default => en, pour tous =>all
     * @param array $lang
     * @return array|mixed
     */
    public static function getMSTerms($lang = 'en') {
        $terms = \Drupal\taxonomy\Entity\Term::loadMultiple(self::getMSTaxoTermsIds($lang));
        return $terms;
    }

    /**
     * Renvoie les ID des termes de taxo de Market Segment
     * Si une langue est passée en paramètre, renvoie seulement les taxos de la langue
     *
     * @param null $lang
     * @return array
     */
    public static function getMSTaxoTermsIds($lang = 'en', $taxo_term = null) {

        $query = \Drupal::entityQuery('taxonomy_term');
        $query->condition('vid', self::$dvi_market_segment_vocabulary);
        if ($lang !== 'all') {
            $query->condition('langcode', $lang);
        }
        if ($taxo_term !== null) {
            $query->condition('name', $taxo_term);
        }
        $entities = $query->execute();

        return $entities;
    }

    /**
     * Renvoie l'id du term passé en paramètre
     * @param $taxoTerm
     * @param null $lang
     * @return bool|int|null|string
     */
    public static function getMSTaxoTermId($taxoTerm, $lang) {
        return self::getMSTaxoTermsIds($lang, $taxoTerm);
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
        $is_dvi_product = FALSE;
        ## First, on check si le node est bien un produit
        if($node->type->entity->get('type') == "product"){

            ##Ensuite, on demande si on a un des terme de taxo de DVI
            $hasMsTaxoTerm = self::hasMSTaxoTerm($node);

            #je vérifie qu'il est tagué "produit DVI" pour la subhome
            $isTaggedDvi = false;
            $lang = $node->language()->getId();

            $subhome_taxoTerm = "";
            if ($lang == 'fr') {
                $subhome_taxoTerm = self::SUBHOME_PRODUIT_DVI_TERM_FR;
            } else {
                $subhome_taxoTerm = self::SUBHOME_PRODUIT_DVI_TERM_EN;
            }

            $fieldName = self::$subhome_field_name;
            if ( isset($node->$fieldName)) {
                //récupération des tag market segment du produit
                $fieldValue = $node->$fieldName->getValue();
                if (!empty($fieldValue)) {
                    //pour chaque tag on regarde s'il y en a un dvi
                    foreach ($fieldValue as $values){
                        if(isset($values['target_id']) && ($values['target_id'] == self::getProductDviSubhomeTid())){
                            $isTaggedDvi = TRUE;
                        }
                    }
                }
            }

            $is_dvi_product = ($hasMsTaxoTerm && $isTaggedDvi) ? true : false;
        }
        return $is_dvi_product;
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
