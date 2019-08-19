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
 *   id = "top_banner_block",
 *   admin_label = @Translation("Top Banner"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class TopBannerBlock extends BlockBase {

    public function build() {
        $block = array();
        $settings = $this->configuration;
        $file = File::load($settings['block_image']);

        $variables = [
            'style_name' => 'top_zone_big',
            'uri' => $file->getFileUri()
        ];

        $image = \Drupal::service('image.factory')->get($file->getFileUri());
        if ($image->isValid()) {
            $variables['width'] = $image->getWidth();
            $variables['height'] = $image->getHeight();
        } else {
            $variables['width'] = $variables['height'] = NULL;
        }

        $logo_render_array = [
            '#theme' => 'image_style',
            '#width' => $variables['width'],
            '#height' => $variables['height'],
            '#style_name' => $variables['style_name'],
            '#uri' => $variables['uri'],
        ];

        $renderer = \Drupal::service('renderer');
        $renderer->addCacheableDependency($logo_render_array, $file);

            //
            //$settings = $current_block->get('settings');
            $content = $settings['content'];
            $title = $settings['block_title_custom'];

        $block['#markup'] = $content;
        $block['block_image'] = $logo_render_array;

        $block['block_title_custom'] = $title;


        return $block;
    }


    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        $form['block_title_custom'] = [
            '#title' => $this->t('Titre du block'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['block_title_custom']) ? $this->configuration['block_title_custom'] : 'Titre du block',
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
