<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\Annotation\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\File\FileUrlGenerator;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\file\Entity\File;
use Drupal\image\Entity\ImageStyle;
use Symfony\Component\DependencyInjection\ContainerInterface;

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

class TopZoneCustomBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * @var FileUrlGenerator
   */
  private FileUrlGenerator $fileUrlGenerator;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, FileUrlGenerator $file_url_generator) {
      parent::__construct(
        $configuration,
        $plugin_id,
        $plugin_definition);
      $this->fileUrlGenerator = $file_url_generator;
    }

    public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition): TopZoneCustomBlock {
      return new self(
        $configuration,
        $plugin_id,
        $plugin_definition,
        $container->get('file_url_generator')
      );
    }

    public function build() {
        $block = array();

        $settings = $this->configuration;
        $file = File::load($settings['block_image']);

        $url = '';
        if ($file != null) {
          $url = ImageStyle::load('top_zone')->buildUrl($file->getFileUri());
          $url = $this->fileUrlGenerator->transformRelative($url);
        }

          $block['block_title_custom'] = $settings['block_title_custom']['value'];
          $block['block_bgimage_url'] = $url;

        return $block;

    }


    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state): array {
        $form = parent::blockForm($form, $form_state);

        $form['block_title_custom'] = [
            '#title' => $this->t('Titre du block'),
            '#type' => 'text_format',
            '#default_value' => $this->configuration['block_title_custom']['value'] ?? '',
            '#format' => $this->configuration['block_title_custom']['format'] ?? 'full_html',
            '#required' => true,
        ];

        $form['block_image'] = [
            '#title' => $this->t('Image en background'),
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
