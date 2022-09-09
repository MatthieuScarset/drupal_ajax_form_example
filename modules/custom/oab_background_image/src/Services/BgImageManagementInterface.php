<?php

namespace Drupal\oab_background_image\Services;

interface BgImageManagementInterface {

  public function add($url, $mid);
  public function get($url);
  public function remove($url);
  public function rebuild();

}
