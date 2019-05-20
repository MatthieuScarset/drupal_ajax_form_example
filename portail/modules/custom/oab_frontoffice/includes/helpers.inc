<?php

/**
 * Regroupement de fonctions utilisées dans le fichier .module
 * afin de ne laisser que les hooks dans le .module
 */


use Drupal\Core\Database\Database;

/**
 * cleane les options du menu déroulant des filtres exposés
 * @param $options du tableau
 */
function clean_exposed_filters_by_language($options = array(), $txt_all) {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    foreach ($options as $key => $value) {
        if ($key != 'All') {
            $term = \Drupal\taxonomy\Entity\Term::load($key);
            if (isset($term) && $term != null) {
                $lang = $term->language();
                if ($lang->getId() != $current_language) {
                    unset($options[ $key ]);
                }
            }
        } else {
            $options['All'] = t($txt_all);
        }
    }
    return $options;
}


function getSocialBarParameters($page_title, $meta_description, $og_image) {
    global $base_root;
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $og_url = $base_root . \Drupal::request()->getRequestUri();

    ##Je fais un tableau de toutes mes données nécessaires pour la création des urls "share"
    ## pour chaque site
    $site_data = [
        'twitter' => [
            'url' => "http://www.twitter.com/intent/tweet",
            'params' => [
                'text' => $page_title,
                'url' => $og_url,
                'hashtags' => '',
                'via' => 'orangebusiness',
                'related' => '',
                'in-reply-to' => ''
            ]
        ],
        'facebook' => [
            'url' => "https://www.facebook.com/sharer/sharer.php",
            "params" => [
                'u' => $og_url
            ]
        ],
        'linkedin' => [
            'url' => "https://www.linkedin.com/shareArticle",
            'params' => [
                'mini' => 'true',
                'url' => $og_url,
                'title' => $page_title,
                'summary' => $meta_description,
                'source' => $og_url
            ]
        ],
        'rss_blogs' => [
            'url' => "/".$current_language."/blogs/rss.xml",
            'params' => []
        ],
        'rss_magazine' => [
            'url' => "/".$current_language."/magazine/rss.xml",
            'params' => []
        ],
        'rss_presse' => [
            'url' => "/".$current_language."/press/feed_rss.xml",
            'params' => []
        ],
    ];

    ## Pour traiter les mails plus tard
    $mail = [
        'subject' => 'Viens voir sur Orange-Business.com',
        'body' => '<html><body><h1>Coucou c\'est un test</body></html>'
    ];

    ##Pour enregistrer les adresses recomposées
    $site_urls = [];

    ##je recompose les URLs share
    foreach ($site_data as $site => $data) {
        $params_string = "";
        foreach ($data['params'] as $paramName => $value) {
            if (is_string($value) && strlen($value)>0) {
                $params_string .= $paramName . "=" . rawurlencode($value) . "&";
            }
        }
        $site_urls[$site] = $data['url'];
        if ($params_string != "") {
            $site_urls[$site] .= "?"
                . rtrim($params_string, "&");
        }
    }

    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    switch ($current_language) {
        case 'fr':
            $og_locale = 'fr_FR';
            break;
        case 'en':
        case 'ru-en':
            $og_locale = 'en_US';
            break;
        case 'ru':
            $og_locale = 'ru_RU';
            break;
        default:
            $og_locale = 'fr_FR';
            break;
    }

    #J'enregistre mes urls et variables OG pour les avoir en JS
    $array_sharbar = array(
        'share_siteUrls' => $site_urls,
        "og_url"    => $og_url,
        "og_locale" => $og_locale,
        "og_image"  => $og_image,
        "og_title"  => $page_title
    );
    return $array_sharbar;
}

/**
 * Pour retrouver tous les Alias d'un node
 * @param $nid
 * @return array
 */
function oab_getAllPathFromNID($nid, $langcode = null) {
    $query = Database::getConnection()->select('url_alias', 'u');

    $query->fields('u', ['alias']);
    $query->condition('source', '/node/' . $nid);

    if ($langcode !== null) {
        $query->condition('langcode', $langcode);
    }

    $result = $query->execute();
    $data = $result->fetchAll();

    $ret = [];
    foreach ($data as $row) {
        $ret[] = ($langcode !== null) ?  "/$langcode" . $row->alias : $row->alias;
    }
    return $ret;
}
