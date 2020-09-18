<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Annotation\Translation;
use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;

/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "rebond_subhome_block",
 *   admin_label = @Translation("Rebond Subhome"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class RebondSubhomeBlock extends BlockBase {

    const TEXT = 'block_text';
    const LINK = 'block_link';
    const LINK_TEXT = 'block_link_text';
    const IMAGE = 'block_image_src';

    private $default_img_src = '/modules/custom/oab_frontoffice/images/visuel-mediatheque.png';

    public function build() {

        // Retrieve existing configuration for this block.
        $config = $this->getConfiguration();

        $img_src = $this->default_img_src;
        if (isset($config[self::IMAGE])) {
          $file = File::load($config[self::IMAGE]);
          $img_src = $file->getFileUri();
        }

        /*
         * J'ai enlevé les trad car s'affiche seulement sur des contenus FR pour l'instant
         */
        return array(
          'text' => isset($config[self::TEXT]) ? $config[self::TEXT] : '',
          'link'  => isset($config[self::LINK]) ? $config[self::LINK] : '',
          'link_text' => isset($config[self::LINK_TEXT]) ? $config[self::LINK_TEXT] : '',
          'image_src' => $img_src
        );
  }

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);

      // Retrieve existing configuration for this block.
      $config = $this->getConfiguration();

      // Add a form field to the existing block configuration form.
      $form[self::TEXT] = array(
          '#type' => 'textfield',
          '#title' => t('Text'),
          '#default_value' => isset($config[self::TEXT]) ? $config[self::TEXT] : ''
      );

      $form[self::LINK] = array(
          '#type' => 'textfield',
          '#title' => t('Link'),
          '#default_value' => isset($config[self::LINK]) ? $config[self::LINK] : ''
      );

      $form[self::LINK_TEXT] = array(
          '#type' => 'textfield',
          '#title' => t('Link text'),
          '#default_value' => isset($config[self::LINK_TEXT]) ? $config[self::LINK_TEXT] : ''
      );

      $form[self::IMAGE] = array(
          '#title' => "Image",
          '#type' => 'managed_file',
          '#upload_location' => "public://rebond-subhome-block",
          '#default_value' => isset($config[self::IMAGE]) ? $config[self::IMAGE] : ''
      );

    return $form;
  }


  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
      $this->setConfigurationValue(self::TEXT, $form_state->getValue(self::TEXT));
      $this->setConfigurationValue(self::LINK, $form_state->getValue(self::LINK));
      $this->setConfigurationValue(self::LINK_TEXT, $form_state->getValue(self::LINK_TEXT));

      $img_value = $form_state->getValue(self::IMAGE);
      $file = File::load($img_value[0]);

      if ($file !== null) {
        $file->setPermanent();
        $file->save();

        $file_usage = \Drupal::service('file.usage');
        $file_usage->add($file, 'oab_frontoffice', 'block', rand());
        $this->setConfigurationValue(self::IMAGE, $file->id());
      }

  }
}
