<?php

namespace Drupal\oab_custom_assets;

use Drupal\Core\Condition\ConditionManager;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Path\CurrentPathStack;
use Drupal\oab_custom_assets\Entity\CustomAssetInterface;
use JetBrains\PhpStorm\ArrayShape;

class CustomAssetsService {

  /** @var CustomAssetInterface[] */
  private $customAssets = [];

  public function __construct(
    private ConditionManager $condition_manager,
    private EntityTypeManagerInterface $entity_type_manager,
    private LanguageManagerInterface $language_manager
  ) {

    /** @var CustomAssetInterface $custom_asset */
    foreach ($this->entity_type_manager->getStorage('custom_asset')->loadByProperties([]) as $custom_asset) {
      if ($this->isCustomAssetAllowed($custom_asset)) {
        $this->customAssets[] = $custom_asset;
      }
    }
  }

  /**
   * @return string[]
   */
  #[ArrayShape([
    'css' => "string",
    'js' => "string",
    'bottom_js' => "string",
  ])] public function getCurrentPathAssets(): array {
    return [
      'css' => implode("", $this->getCurrentPathCss()),
      'js' => implode("", $this->getCurrentPathJs()),
      'bottom_js' => implode("", $this->getCurrentPathBottomJs()),
    ];
  }

  /**
   * @return string[]
   */
  public function getCurrentPathCss(): array {
    $ret = [];

    foreach ($this->customAssets as $asset) {
      $ret[] = $asset->getCSS();
    }

    return $ret;
  }

  /**
   * @return string[]
   */
  public function getCurrentPathJs(): array {
    $ret = [];

    foreach ($this->customAssets as $asset) {
      $ret[] = $asset->getJs();
    }

    return $ret;
  }

  /**
   * @return string[]
   */
  public function getCurrentPathBottomJs(): array {
    $ret = [];

    foreach ($this->customAssets as $asset) {
      $ret[] = $asset->getBottomJs();
    }

    return $ret;
  }


  public function getTags(): array {
    $tags = [];

    foreach ($this->customAssets as $customAsset) {
     $tags = array_merge($tags, $customAsset->getCacheTags());
    }

    return $tags;
  }

  private function isCustomAssetAllowed(CustomAssetInterface $custom_asset) {
    $plugin_conf = [
      'pages' => $custom_asset->getPaths() ?? ''
    ];

    /** @var \Drupal\system\Plugin\Condition\RequestPath $path_condition */
    $path_condition = $this->condition_manager->createInstance('request_path', $plugin_conf);

    /** @var \Drupal\language\Plugin\Condition\Language $language_condition */
    $language_condition = $this->condition_manager->createInstance('language', ['langcodes' => $custom_asset->getLanguages()]);
    $language_condition->setContextValue('language', $this->language_manager->getCurrentLanguage()->getId());

    return $path_condition->evaluate() && $language_condition->evaluate();
  }
}
