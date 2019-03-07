<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;

/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "mediatheque_block",
 *   admin_label = @Translation("Mediathèque"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class MediathequeBlock extends BlockBase {

  public function build() {

    /*
     * J'ai enlevé les trad car s'affiche seulement sur des contenus FR pour l'instant
     */
    return array(
      'text' => 'Vous êtes à la recherche d\'images ou de vidéos pour illustrer vos supports de communication ?',
      'link'  => 'https://mediatheque.orange.com/fr/mediacenter',
      'link_text' => "En savoir plus"
    );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockValidate($form, FormStateInterface $form_state) {

  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {

  }
}
