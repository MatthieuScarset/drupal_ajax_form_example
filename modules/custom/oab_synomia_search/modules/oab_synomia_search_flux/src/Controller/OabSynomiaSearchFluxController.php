<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 31/07/2017
 */

namespace Drupal\oab_synomia_search_flux\Controller;


use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Database;
use Drupal\oab_synomia_search_flux\Classes\SynomiaDeletedContent;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabSynomiaSearchFluxController extends ControllerBase
{

  /** Méthode appelée pour l'onglet Global Settings de la partie BO */
  public function viewFlux($type_flux = 'default', Request $request) {

        $response = new Response();
        $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());
        if (empty($parameters)) {
            $response->setContent($this->getSitemapSynomiaSimple($type_flux));
        } elseif (isset($parameters['startDate']) && isset($parameters['endDate'])) {
            if (isValidDate($parameters['startDate'], 'Ymd') && isValidDate($parameters['endDate'], 'Ymd')) {
                $response->setContent($this->getSitemapSynomiaByDates($type_flux, $parameters['startDate'], $parameters['endDate']));
            }
        } else {
            throw new NotFoundHttpException();
        }
        $response->headers->set('Content-Type', 'text/xml');
        return $response;
  }

  private function getSitemapSynomiaSimple($type_flux) {
      //calcul de l'intervalle de temps à prendre en compte :
      // 1. on prend les contenus qui ont été modifiés il y a au moins 12h (pour que le cache Akamai soit rafraichi) :
      $time_fin = strtotime("-12 hours", time());
      //$time_fin =  time(); // pour les tests
      // 2. on prend les contenus modifiés sur 48h (par rapport a la date précédente) :
      $time_debut = strtotime("-48 hours", $time_fin);

      $xml_feed = $this->get_sitemap_synomia_by_dates($type_flux, $time_debut, $time_fin);
      return $xml_feed;
  }

  private function getSitemapSynomiaByDates($type_flux, $debut, $fin) {
      $start_date = \DateTime::createFromFormat('Ymd H:i:s', $debut.'00:00:00');
      $time_debut = $start_date->getTimestamp();

      $end_date = \DateTime::createFromFormat('Ymd H:i:s', $fin.'23:59:59');
      $time_fin = $end_date->getTimestamp();

      $xml_feed = $this->get_sitemap_synomia_by_dates($type_flux, $time_debut, $time_fin);
      return $xml_feed;
  }

  private function get_sitemap_synomia_by_dates($type_flux, $time_debut, $time_fin) {

      $content_types = $this->getContentTypeToIndex($type_flux);
      $start_creation_date_limit = $this->getCreationDateLimit();
      $base_url = \Drupal::request()->getSchemeAndHttpHost();
      $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

      //Récuperation des préfixes (parce que celui de pt-br est br)
      $prefixes = \Drupal::config('language.negotiation')->get('url.prefixes');

      $xml_feed = '';
      // Création du flux XML
      $xml_feed .= '<?xml version=\'1.0\' encoding=\'utf-8\'?><urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">';

      if (!empty($content_types)) {
          //On prend les éléments supprimés
          $query = Database::getConnection()
              ->select('synomia_deleted_content', 's');
          $query->condition('s.content_type', $content_types, 'IN');
          $query->condition('s.language', array($current_language, 'und'), 'IN');
          $query->condition('s.deleted', array($time_debut, $time_fin), 'BETWEEN');
          $query->fields('s');
          $results_deleted = $query->execute()->fetchAll();

          foreach ($results_deleted as $deleted) {
              $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

              $xml_feed .= '<url>
                  <loc><![CDATA[' . $base_url . '/' . $prefixe . $deleted->url . ']]></loc>
                  <lastmod><![CDATA[' . date("Y-m-d H:i", $deleted->deleted) . ']]></lastmod>
                  <changefreq>daily</changefreq>
              <priority>1</priority>
              </url>';
          }

          //Noeuds qui ont été ajoutés ou modifiés
          $query_nodes = Database::getConnection()->select('node_field_data', 'n');
          $query_nodes->condition('n.type', $content_types, 'IN');
          $query_nodes->condition('n.status', 1, '=');
          $query_nodes->condition('n.langcode', array(
              $current_language,
              'und'
          ), 'IN');
          $query_nodes->condition('n.changed', array(
              $time_debut,
              $time_fin
          ), 'BETWEEN');
          $query_nodes->condition('n.created', $start_creation_date_limit, '>=');
          $query_nodes->fields('n', array('nid', 'langcode', 'changed'));
          $results_nodes = $query_nodes->execute()->fetchAll();


          foreach ($results_nodes as $node) {
              $alias = \Drupal::service('path_alias.manager')
                  ->getAliasByPath('/node/' . $node->nid, $node->langcode);

              $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

              $xml_feed .= '<url>
                      <loc><![CDATA[' . $base_url . '/' . $prefixe . $alias . ']]></loc>
                      <lastmod><![CDATA[' . date("Y-m-d H:i", $node->changed) . ']]></lastmod>
                      <changefreq>daily</changefreq>
                      <priority>1</priority>
                  </url>';

          }
        //oabt($xml_feed);die();
      }
      $xml_feed .= '</urlset>';
      return $xml_feed;
  }

  /** Retourne la liste des types de contenus à indexer (dans la config)
   * @return array
   */
  private function getContentTypeToIndex($type_flux) {
    $types = array();
    if($type_flux == 'default') {
      $config_factory = \Drupal::configFactory();
      //on récupère la configuration oab_synomia_search.synomia.contentTypes
      $config = $config_factory->get('oab_synomia_search.synomia.contentTypes');
      //on charge la liste des types de contenus
      $content_types = \Drupal::service('entity.manager')->getStorage('node_type')->loadMultiple();
      foreach ($content_types as $content_type) {
        $value = $config->get($content_type->id());
        if (isset($value) && $value == "1") {
          $types[] = $content_type->id();
        }
      }
    }
    elseif ($type_flux == 'mss'){
      $types[] = 'mss_article';
    }
    return $types;
  }

  /** Retourne la liste des types de contenus à indexer (dans la config)
   * @return array
   */
  private function getCreationDateLimit() {
      $config_factory = \Drupal::configFactory();
      //on récupère la configuration oab_synomia_search.synomia.contentTypes
      $config = $config_factory->get('oab_synomia_search.synomia.contentTypes');
      $date = $config->get('creationDateLimit');
      if (isset($date) && !empty($date)) {
          $timestamp = strtotime($date);
      } else {
          $timestamp = strtotime('2015-01-01');
      }
      return $timestamp;
  }

}
