<?php

namespace Drupal\oab_modular_product\Services;

use Drupal\Core\Config\ImmutableConfig;

class OabModularProductService {

  const MODULES_OPTIONNELS = [
    "module_3_4_colonnes",
    "module_text_video_image",
    "paragraph_wysiwyg",
  ];

  public function __construct(
    private ImmutableConfig $config
  ) { }

  public function getShortTitleMaxCharacter(): mixed {
    return $this->get("mp.titles.title_short");
  }

  public function getLongTitleMaxCharacter(): mixed {
    return $this->get("mp.titles.title_long");
  }

  public function getLongDescriptionMaxCharacter(): mixed {
    return $this->get("mp.descriptions.description_long");
  }

  public function getPresentationModuleTitle(): mixed {
    return $this->get("modules_titles.module_presentation");
  }

  public function getOfferDetailTitle(): mixed {
    return $this->get("modules_titles.module_detail_offre");
  }

  public function getDetailGammeModuleTitle(): mixed {
    return $this->get("modules_titles.module_detail_gamme");
  }

  public function getServicesModuleTitle(): mixed {
    return $this->get("modules_titles.module_services");
  }

  public function getCustomerSpaceModuleTitle(): mixed {
    return $this->get("modules_titles.module_customer_space");
  }

  public function getExamplesModuleTitle(): mixed {
    return $this->get("modules_titles.module_exemples");
  }

  public function getTestimonialModuleTitle(): mixed {
    return $this->get("modules_titles.module_testimonial");
  }

  public function getToGoFurtherTitle(): mixed {
    return $this->get("modules_titles.to_go_further");
  }

  public function getModulesOrder(): array {
    $modules = $this->config->get('modules_settings.modules');
    if(empty($modules)) {
      return [];
    }
    else {
      //tri du tableau par la weight
      uasort($modules, function($a, $b) {
        return $a['weight'] <=> $b['weight'];
      });
      //on ne renvoie que les id
      return array_keys($modules);
    }
  }

  public function getModulesRequired(): array {
    $modules = $this->config->get('modules_settings.modules');
    if(empty($modules)) {
      return [];
    }
    else {
      //filtre du tableau sur les required - on ne renvoie que les id
      return array_keys(array_filter($modules, function($v, $k) {
        return $v['required'] === "1";
      }, ARRAY_FILTER_USE_BOTH));
    }
  }

  public function getModulesOptionalSecondaryPosition(): array {
    $modules = $this->config->get('modules_settings.modules');
    if(empty($modules)) {
      return [];
    }
    else {
      //filtre du tableau sur les second_position - on ne renvoie que les id
      return array_keys(array_filter($modules, function($v, $k) {
        return $v['second_position'] === "1";
      }, ARRAY_FILTER_USE_BOTH));
    }
  }

  private function get(string $item): mixed {
    return $this->config->get($item) ?? [];
  }
}

