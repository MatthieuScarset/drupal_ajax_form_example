<?php

namespace Drupal\oab_synomia_search_flux\Classes;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Database\Database;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\node\Entity\NodeType;
use Drupal\path_alias\AliasManagerInterface;

class SynomiaMSSFluxService {

  public function __construct(
    private EntityTypeManager $entityTypeManager,
    private AliasManagerInterface $alias_manager
  ) { }

  /** Méthode appelée pour obtenir la liste des contenus MSS à indexer par synomia (flux XML)
   * @param $time_debut
   * @param $time_fin
   *
   * @return string
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  public function getMSSSitemapToIndexBySynomia($time_debut, $time_fin) {
    $base_url = \Drupal::request()->getSchemeAndHttpHost();
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    //Récuperation des préfixes (parce que celui de pt-br est br)
    $prefixes = \Drupal::config('language.negotiation')->get('url.prefixes');

    $xml_feed = '';
    // Création du flux XML
    $xml_feed .= '<?xml version=\'1.0\' encoding=\'iso-8859-1\'?><CORPUS>';

    //Noeuds qui ont été ajoutés ou modifiés
    $nids = \Drupal::entityTypeManager()->getStorage('node')->getQuery()
      ->condition('type', 'mss_article', 'IN')
      ->condition('langcode', array( $current_language, 'und' ), 'IN')
      ->condition('changed', array( $time_debut, $time_fin ), 'BETWEEN')
      ->execute();
    if ($nids) {
      $nodes = \Drupal::entityTypeManager()
        ->getStorage('node')
        ->loadMultiple($nids);

      /** @var \Drupal\node\Entity\Node $node */
      foreach ($nodes as $node) {
        $alias = $this->alias_manager
          ->getAliasByPath('/node/' . $node->id(), $node->language()->getId());
        $prefixe = (isset($prefixes[$current_language])) ? $prefixes[$current_language] : $current_language;

        $xml_feed .= '<doc>';
        $xml_feed .= '<meta name="url"><![CDATA[' . $base_url . '/' . $prefixe . $alias . ']]></meta>';
        $xml_feed .= '<meta name="last_modified"><![CDATA[' . date("Y-m-d H:i", $node->changed->value) . ']]></meta>';

        $status = $node->get('status')->getValue()[0]['value'];

        if ($status === "1") {
          //le contenu est publié
          $xml_feed .= '<meta name="title"><![CDATA[' . $node->label() . ']]></meta>';

          // pour MSS les categorisation de Synomia se font par la typologie de l'article
          $field_typology = $node->get('field_typology');
          if (isset($field_typology[0])) {
            $typology = $field_typology[0]->getValue();
            $xml_feed .= '<meta name="rubrique"><![CDATA[' . $typology['value'] . ']]></meta>';
          }
          $xml_feed .= '<meta name="synstatus"><![CDATA[]]></meta>';

          /** @var \Drupal\Core\Field\FieldItemList $field_content */
          $field_content = $node->get('field_content');
          if (isset($field_content)) {
            $xml_feed .= '<words><![CDATA[';
            foreach ($field_content->getValue() as $contentValue) {
              $xml_feed .= str_replace("\r\n", " ", strip_tags($contentValue['value']));
            }
            $xml_feed .= ']]></words>';
          }
        }
        else {
          //contenu NON PUBLIE
          $xml_feed .= '<meta name="synstatus"><![CDATA[deleted]]></meta>';
        }
        $xml_feed .= '</doc>';
      }
    }

    //CONTENUS SUPPRIMES
    $query = \Drupal::database()
      ->select('synomia_deleted_content', 's')
      ->condition('s.content_type', 'mss_article', 'IN')
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

    $xml_feed .= '</CORPUS>';
    return $xml_feed;
  }
}
