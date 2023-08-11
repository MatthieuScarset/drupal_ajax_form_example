<?php
namespace Drupal\oab_frontoffice\Services;

class OabEmbedVideoUrlService {


  public function __construct() { }

  public function changeUrlToEmbedUrl($url) {
    $embed_url = '';
    $video_id = '';
    // full youtube url
    if (str_contains($url, 'youtube')) {
      $video_id = $this->getVideoId($url, "?v=", 3);
    }
    // tiny youtube url
    if (str_contains($url, 'youtu.be')) {
      $video_id = $this->getVideoId($url);
    }
    if (!empty($video_id)) {
      $embed_url = 'https://www.youtube.com/embed/' . $video_id ;
      $embed_url = str_replace('&list=', '?list=', $embed_url);
    }
    return $embed_url;
  }

  // Return video ID from URL
  private function getVideoId($url, $separator = "/", $index = 1) {
    return substr($url, strrpos($url, $separator)+$index, strlen($url));
  }
}
