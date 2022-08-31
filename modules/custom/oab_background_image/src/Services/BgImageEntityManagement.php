<?php
namespace Drupal\oab_background_image\Services;

use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\media\Entity\Media;
use Drupal\oab_background_image\Entity\BackgroundImage;
use Drupal\oab_background_image\Entity\BackgroundImageInterface;

class BgImageEntityManagement implements BgImageManagementInterface {

  /** @var \Drupal\Core\Entity\EntityStorageInterface */
  private $storage;

    public function __construct(
      private EntityTypeManagerInterface $entity_type_manager,
      private MessengerInterface $messenger
    ) {
        $this->storage = $entity_type_manager->getStorage('background_image');
    }

    /**
     * Sauvegarde en cache le background media pour l'url spécifiée
     * @param $url string
     * @param $mid int|Media
     * @throws \Exception
     */
    public function add($url, $mid) {
        $url_machine_name = BackgroundImage::getUrlMachineName($url);

        if ($mid instanceof Media) {
          $mid = $mid->id();
        }

        $background_image = $this->loadByMachineName($url_machine_name);

        if (!is_null($background_image)) {
          if ($mid !== $background_image->mid->target_id) {
//            dd($background_image->mid, $mid);
            $this->messenger->addWarning(t("Replacement of the background for %url. Was media ID %old_mid, is now media ID %new_mid",
              [
                '%url' => $url,
                '%old_mid' => $background_image->mid->target_id,
                '%new_mid' => $mid
              ]
            ));
            $background_image->set('mid', $mid);
            $background_image->save();
          }

        } else {
          $background_image = BackgroundImage::create([
            'mid' => $mid,
            'url' => $url_machine_name
          ]);
          $background_image->save();
          $this->messenger->addStatus(t("Background saved for url %url", ['%url' => $url]));
        }

    }


    /**
     * Renvoie le backgroud image qui a été sauvegardé en cache pour l'url passée en paramètre
     * @param $url string
     * @return \Drupal\Core\Entity\EntityInterface|Media|null
     */
    public function get($url) {
        $ret = null;

        $bg = $this->loadByMachineName(BackgroundImage::getUrlMachineName($url));

        if ($bg) {
          $ret = Media::load($bg->mid->target_id ?? 0);
        }

        return $ret;
    }

    public function remove($url) {
      $bg = $this->loadByMachineName(BackgroundImage::getUrlMachineName($url));
      $bg?->delete();
      \Drupal::messenger()->addStatus(t('The background has been removed for %url', ['%url' => $url]));
    }

    /**
     * Refait tout le cache des background image
     * @throws \Exception
     */
    public function rebuild() {

      // First we delete everything
      foreach ($this->storage->loadByProperties([]) as $bg_image) {
        $bg_image->delete();
      }


      // Then we load every bg image Media to rebuild
      $bg_medias = $this->entity_type_manager->getStorage('media')->loadByProperties(['bundle' => 'background']);

      foreach ($bg_medias as $bg_media) {
        if ($bg_media->hasField('field_visibility') && $bg_media->field_visibility->count() > 0) {
          foreach (_oab_background_image_get_urls($bg_media->field_visibility->first()->getValue()) as $url) {
            if (strlen($url)) {
              $this->add($url, $bg_media->id());
            }
          }
        }

      }

      // Delete all messages
      $this->messenger->addStatus(t('Background images rebuilt'));
    }

    private function loadByMachineName(string $url_machine_name): ?BackgroundImageInterface {
      /** @var BackgroundImageInterface[] $bg_images */
      $bg_images = $this->storage->loadByProperties(['url' => $url_machine_name]);

      if (!empty($bg_images)) {
        return $bg_images[array_key_first($bg_images)];
      }

      return null;
    }

}
