<?php

namespace Drupal\oab_modular_product\Services;

use Drupal\Core\Config\ImmutableConfig;

class OabModularProductService {

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

  public function getPresentationModuleTitle(): string {
    return $this->get("modules_titles.module_presentation");
  }

  public function getOfferDetailTitle(): string {
    return $this->get("modules_titles.module_detail_offre");
  }

  public function getDetailGammeModuleTitle(): string {
    return $this->get("modules_titles.module_detail_gamme");
  }

  public function getServicesModuleTitle(): string {
    return $this->get("modules_titles.module_services");
  }

  public function getCustomerSpaceModuleTitle(): string {
    return $this->get("modules_titles.module_customer_space");
  }

  public function getExamplesModuleTitle(): string {
    return $this->get("modules_titles.module_exemples");
  }

  public function getTestimonialModuleTitle(): string {
    return $this->get("modules_titles.module_testimonial");
  }

  private function get(string $item): mixed {
    return $this->config->get($item) ?? [];
  }
}

