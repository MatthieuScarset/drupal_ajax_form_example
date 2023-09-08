<?php

namespace Drupal\oab_twitter\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Cache\Cache;
use Drupal\Core\Form\FormBuilderInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;

/**
 *
 * @Block(
 *   id = "twitter_block",
 *   admin_label = @Translation("Twitter Block"),
 *   category = @Translation("Blocks")
 * )
 *
 */

class TwitterBlock extends BlockBase {

  public function build() {

    $twitter_service = \Drupal::service('oab_twitter.twitter_service');
    try {
      $tweet = $twitter_service->getTweet($this->configuration['position']);
    } catch (\Exception $e) {
      $tweet = [];
    }
    return (count($tweet) > 0) ? array("tweets" => $tweet) : array();
  }

}
