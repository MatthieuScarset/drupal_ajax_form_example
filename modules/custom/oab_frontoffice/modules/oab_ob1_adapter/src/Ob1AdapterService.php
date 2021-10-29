<?php

namespace Drupal\oab_ob1_adapter;

use Drupal\Core\Config\ImmutableConfig;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\oab_ob1_adapter\Form\Ob1ThemeSettingsForm;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RequestStack;

class Ob1AdapterService {

  /**
   * @var ImmutableConfig
   */
  private $ob1ThemeConfig;

  /**
   * @var LanguageManagerInterface
   */
  private $languageManager;

  private $conf;

  public function __construct(ImmutableConfig $ob1_theme_config, LanguageManagerInterface $language_manager) {
    $this->ob1ThemeConfig = $ob1_theme_config;
    $this->languageManager = $language_manager;
    $this->conf = $ob1_theme_config->get($language_manager->getCurrentLanguage()->getId());
  }

  /**
   * @param $key
   * @return mixed|null
   */
  public function get($key) {
    $current_lang = $this->languageManager->getCurrentLanguage()->getId();
    $key = $current_lang.'.'.$key;
    return $this->ob1ThemeConfig->get($key);
  }

  public function getUrl() : array {
    $urls = $this->get('url');

    if (is_array($urls)) {
      return $urls;
    }

    return [];
  }

  public function hasUrl($url) : bool {
    $has_url = false;

    //récupération de la liste des urls à One-ifiées
    $urls_allowed = $this->getUrl();

      // je vérifie que l'url est bien dans la liste
      if (in_array($url, $urls_allowed, true)) {
        $has_url = true;
      }


    return $has_url;
  }

  public function hasView($view_id, $display_id) : bool {
    $has_view = false;

    $views_allowed = $this->get('views');

    if (isset($views_allowed[$view_id]) && count($views_allowed[$view_id]) != 0) {
      if (in_array($display_id, $views_allowed[$view_id])) {
        $has_view = true;
      }
    }

    return $has_view;
  }

  public function hasContent($content_type) : bool {
    $has_content = false;

    $contents_type_allowed = $this->get('contents');

    if ($content_type !== null) {
      if (isset($contents_type_allowed) && count($contents_type_allowed) != 0) {
        if (in_array($content_type, $contents_type_allowed)) {
          $has_content = true;
        }
      }
    }

    return $has_content;
  }
}
