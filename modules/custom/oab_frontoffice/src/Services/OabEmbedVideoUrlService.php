<?php
namespace Drupal\oab_frontoffice\Services;

class OabEmbedVideoUrlService {


  public function __construct(  ) { }

  public function changeUrlToEmbedUrl($url) {
    $embed_url = '';
    $videoId = '';
    // full youtube url
    if (str_contains($url, 'youtube')) {
      $videoId = $this->getVideoId($url, "?v=", 3);
    }
    // tiny youtube url
    if (str_contains($url, 'youtu.be')) {
      $videoId = $this->getVideoId($url);
    }
    if(!empty($videoId)) {
      $embed_url = 'https://www.youtube.com/embed/' . $videoId ;
      $embed_url = str_replace('&list=', '?list=', $embed_url);
    }
    return $embed_url;
  }

  // Return video ID from URL
  private function getVideoId( $url, $separator = "/", $index = 1) {
    return substr($url, strrpos($url, $separator)+$index, strlen($url));
  }
}
