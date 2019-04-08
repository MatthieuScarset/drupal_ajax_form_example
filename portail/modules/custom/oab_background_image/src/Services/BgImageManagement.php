<?php
namespace Drupal\oab_background_image\Services;

use Drupal\media_entity\Entity\Media;

class BgImageManagement
{

    /** @var \Drupal\Core\Cache\CacheBackendInterface  */
    private $cache;

    const CACHE_BIN = 'oab_background_image';

    public function __construct() {
        $this->cache = \Drupal::cache(self::CACHE_BIN);
    }

    /**
     * Sauvegarde en cache le background media pour l'url spécifiée
     * @param $url string
     * @param $mid int|\Drupal\media_entity\Entity\Media
     * @throws \Exception
     */
    public function add($url, $mid) {
        if ($this->cache->get($url, true) !== false) {
            $this->cache->delete($url);
        }

        $data = null;
        if (is_a($mid, 'Drupal\media_entity\Entity\Media')) {
            $data = $mid->id();
        } elseif (ctype_digit ($mid) !== false) {
            $data = $mid;
        } else {
            throw new \Exception("Mauvais paramètre");
        }

        $this->cache->set($url, $data);
    }


    /**
     * Renvoie le backgroud image qui a été sauvegardé en cache pour l'url passée en paramètre
     * @param $url string
     * @return \Drupal\Core\Entity\EntityInterface|\Drupal\media_entity\Entity\Media|null
     */
    public function get($url) {
        $ret = null;

        $cache = $this->cache->get($url);
        if ($cache !== false && isset($cache->data)) {
            $ret = Media::load($cache->data);
        }

        return $ret;
    }

    public function remove($url) {
        $this->cache->delete($url);
    }

    /**
     * Refait tout le cache des background image
     * @throws \Exception
     */
    public function rebuild() {
        $this->cache->deleteAll();

        $query = \Drupal::entityQuery('media')
            ->condition('bundle', 'background');

        $results = $query->execute();

        foreach ($results as $key => $value) {
            /** @var \Drupal\media_entity\Entity\Media $media */
            $media = Media::load($value);
            if ($media !== null) {
                $value = \Drupal::service('oab_background_image.entity_get_field')->getFirst($media, 'field_visibility');
                if (isset($value['value'])) {

                    $urls = explode("\r\n", $value['value']);
                    foreach ($urls as $url) {
                        $this->add($url, (int) $media->id());
                    }
                }
            }
        }
    }

}
