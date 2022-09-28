<?php

namespace Drupal\oab_synomia_search_flux\Classes;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Database\Database;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\node\Entity\NodeType;
use Drupal\path_alias\AliasManagerInterface;

class SynomiaFluxService {

  public function __construct(
    private ImmutableConfig $config,
    private EntityTypeManager $entityTypeManager,
    private AliasManagerInterface $alias_manager
  ) { }

  private function getConfig(string $item): mixed {
    return $this->config->get($item) ?? [];
  }

  /** Retourne la liste des types de contenus à indexer (dans la config)
   * @return array
   */
  private function getContentTypeToIndex() {
    $types = array();
    foreach (NodeType::loadMultiple() as $content_type) {
      $value = $this->getConfig($content_type->id());
      if (isset($value) && $value === 1) {
        $types[] = $content_type->id();
      }
    }
    return $types;
  }

  /** Retourne la date minimale de création des contenus à indexer (dans la config)
   * @return array
   */
  private function getCreationDateLimit() {
    $date = $this->getConfig('creationDateLimit');
    if (isset($date) && !empty($date)) {
      $timestamp = strtotime($date);
    } else {
      $timestamp = strtotime('2015-01-01');
    }
    return $timestamp;
  }

  /** Méthode appelée pour obtenir la liste des contenus à indexer par synomia (flux XML)
   * @param $time_debut
   * @param $time_fin
   *
   * @return string
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public function getSitemapToIndexBySynomia($time_debut, $time_fin) {
    $content_types = $this->getContentTypeToIndex();
    $base_url = \Drupal::request()->getSchemeAndHttpHost();
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    //Récuperation des préfixes (parce que celui de pt-br est br)
    $prefixes = \Drupal::config('language.negotiation')->get('url.prefixes');

    $xml_feed = '';
    // Création du flux XML
    $xml_feed .= '<?xml version=\'1.0\' encoding=\'utf-8\'?><urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">';

    if (!empty($content_types)) {
      //Noeuds qui ont été ajoutés ou modifiés
      $nids = \Drupal::entityTypeManager()->getStorage('node')->getQuery()
        ->condition('type', $content_types, 'IN')
        ->condition('status', 1, '=')
        ->condition('langcode', array( $current_language, 'und' ), 'IN')
        ->condition('changed', array( $time_debut, $time_fin ), 'BETWEEN')
        ->condition('created', $this->getCreationDateLimit(), '>=')
        ->execute();

      if ($nids) {
        $nodes = \Drupal::entityTypeManager()
          ->getStorage('node')
          ->loadMultiple($nids);

        /** @var Drupal\node\Entity\Node $node */
        foreach ($nodes as $node) {
         // dd($node->language()->getId());
          $alias = $this->alias_manager
            ->getAliasByPath('/node/' . $node->id(), $node->language()->getId());
          $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

          $xml_feed .= '<url>
                        <loc><![CDATA[' . $base_url . '/' . $prefixe . $alias . ']]></loc>
                        <lastmod><![CDATA[' . date("Y-m-d H:i", $node->changed->value) . ']]></lastmod>
                        <changefreq>daily</changefreq>
                        <priority>1</priority>
                    </url>';
        }
      }
    }
    $xml_feed .= '</urlset>';
    return $xml_feed;
  }

  /** Méthode appelée pour obtenir le flux XML des contenus supprimés ou dépublié à désindexer par Synomia
   * @param $time_debut
   * @param $time_fin
   *
   * @return string
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public function getSitemapToDeleteBySynomia($time_debut, $time_fin) {
    $content_types = $this->getContentTypeToIndex();
    $base_url = \Drupal::request()->getSchemeAndHttpHost();
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    //Récuperation des préfixes (parce que celui de pt-br est br)
    $prefixes = \Drupal::config('language.negotiation')->get('url.prefixes');

    $xml_feed = '';
    // Création du flux XML
    $xml_feed .= '<?xml version=\'1.0\' encoding=\'utf-8\'?><CORPUS>';

    if (!empty($content_types)) {

      //CONTENUS DEPUBLIES
      $nids = \Drupal::entityTypeManager()->getStorage('node')->getQuery()
        ->condition('type', $content_types, 'IN')
        ->condition('status', 0, '=')
        ->condition('langcode', array( $current_language, 'und' ), 'IN')
        ->condition('changed', array( $time_debut, $time_fin ), 'BETWEEN')
        ->condition('created', $this->getCreationDateLimit(), '>=')
        ->execute();

      if ($nids) {
        $nodes = \Drupal::entityTypeManager()
          ->getStorage('node')
          ->loadMultiple($nids);

        /** @var Drupal\node\Entity\Node $node */
        foreach ($nodes as $node) {
          // dd($node->language()->getId());
          $alias = $this->alias_manager
            ->getAliasByPath('/node/' . $node->id(), $node->language()->getId());
          $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

          $xml_feed .= '<doc>
                        <meta name="url"><![CDATA[' . $base_url . '/' . $prefixe . $alias . ']]></meta>
                        <meta name="synstatus"><![CDATA[deleted]]></meta>
                        <meta name="last_modified"><![CDATA[' . date("Y-m-d H:i", $node->changed->value) . ']]></meta>
                    </doc>';
        }
      }

      //CONTENUS SUPPRIMES
      $query = \Drupal::database()
        ->select('synomia_deleted_content', 's')
        ->condition('s.content_type', $content_types, 'IN')
        ->condition('s.language', array($current_language, 'und'), 'IN')
        ->condition('s.deleted', array($time_debut, $time_fin), 'BETWEEN')
        ->fields('s');
      $results_deleted = $query->execute()->fetchAll();

      foreach ($results_deleted as $deleted) {
        $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

        $xml_feed .= '<doc>
                        <meta name="url"><![CDATA[' . $base_url . '/' . $prefixe . $deleted->url . ']]></meta>
                        <meta name="synstatus"><![CDATA[deleted]]></meta>
                        <meta name="last_modified"><![CDATA[' . date("Y-m-d H:i", $deleted->deleted) . ']]></meta>
                    </doc>';
      }
    }
    $xml_feed .= '</CORPUS>';
    return $xml_feed;
  }

}
