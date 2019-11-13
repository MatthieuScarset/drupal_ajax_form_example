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

    $twitterService = \Drupal::service('oab_twitter.twitter_settings_form_service');
    $tweet = $twitterService->getTweet($this->configuration['position']);
    return (count($tweet) > 0) ? array("tweets" => $tweet) : array();
  }

}
