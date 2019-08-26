<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;
use Drupal\node\Entity\Node;
use Drupal\Core\Entity;
use Drupal\Core\Url;
use Drupal\Core\Link;
use Drupal\image\Entity\ImageStyle;
use Drupal\media_entity\Entity\Media;
/**
 *
 * @author DMPT2806
 * @Block(
 *   id = "top_zone_custom_block",
 *   admin_label = @Translation("Top Zone Custom"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class TopZoneCustomBlock extends BlockBase {

    public function build() {
        $block = array();

        $settings = $this->configuration;
        $file = File::load($settings['block_image']);


        $url = ImageStyle::load('top_zone_big')->buildUrl($file->getFileUri());
        $url = file_url_transform_relative($url);


        $block['block_title_custom'] = $settings['block_title_custom']['value'];
        $block['block_bgimage_url'] = $url;

        return $block;
    }


    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        $form['block_title_custom'] = [
            '#title' => $this->t('Titre du block'),
            '#type' => 'text_format',
            '#default_value' => isset($this->configuration['block_title_custom']['value']) ? $this->configuration['block_title_custom']['value'] : '',
            '#format' => isset($this->configuration['block_title_custom']['format']) ? $this->configuration['block_title_custom']['format'] : 'full_html',
            '#required' => true,
        ];

        $form['block_image'] = [
            '#title' => $this->t('blooop du block'),
           '#type' => 'managed_file',
            //'#entity_browser' => 'browse_media_modal',
           '#default_value' => isset($this->configuration['block_image']) ? [$this->configuration['block_image']] : '',
            '#required' => true,
            '#upload_location' => 'public://',
        ];
        

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

       //kint( $this->configuration['block_image']); die();

       // $image = $form_state->getValue('block_image');
       // $this->configuration['block_image'] = $image['entities'][0]->id();
        $block_image_values = $form_state->getValue('block_image');
        if (isset($block_image_values[0])) {


            $file = File::load($block_image_values[0]);
            $file->setPermanent();
            $file->save();

            $file_usage = \Drupal::service('file.usage');
            $file_usage->add($file, 'welcome', 'welcome', \Drupal::currentUser()->id());

            $this->configuration['block_image'] = $file->id();
        }

        $this->configuration['block_title_custom'] = $form_state->getValue('block_title_custom');
    }
}
