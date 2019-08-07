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

        $current_block = \Drupal\block\Entity\Block::load('topbanner');

        if ($current_block) {

            $settings = $current_block->get('settings');
            $content = $settings['content'];
            $media = $settings['block_image'];
        }
        $block['#markup'] = $content;
        $block['block_image'] = $media;

        return $block;
    }


    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        $form['block_title'] = [
            '#title' => $this->t('Titre du block'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['block_title']) ? $this->configuration['block_title'] : 'Titre du block',
            '#required' => true,
        ];
        $form['block_image'] = [
            '#title' => $this->t('blooop du block'),
           '#type' => 'entity_browser',
            '#entity_browser' => 'browse_media_modal',
           '#default_value' => isset($this->configuration['block_image']) ? $this->configuration['block_image'] : '',
            '#required' => true,
        ];

       /* $form['block_image'] = array(
            '#type' => 'container',
            '#title' => t('Image en background'),
            '#attributes' => [
                'class' => [
                    'field--type-entity-reference',
                    'field--name-field-visual',
                    'field--widget-entity-browser-entity-reference'
                ]
            ],
            'widget' => [
                '#title' => "Blop",
                '#id' => 'edit-field-visual',
                '#type' => "details",
                '#open' => true,
                'target_id' => [
                      '#type' => 'hidden',
                      '#id' => 'edit-field-visual-target-id',
                      '#default_value' => "",
                      '#attribute' => [
                          'id' => 'edit-field-visual-target-id'
                      ],
                      '#ajax' => [
                          'callback' => [
                              'Drupal\entity_browser\Plugin\Field\FieldWidget\EntityReferenceBrowserWidget',
                              'updateWidgetCallback'
                          ],
                          'wrapper' => 'edit-field-visual',
                          'event' => 'entity_browser_value_updated'
                      ]
                ],
                'entity_browser' => [
                    '#type' => 'entity_browser',
                    '#entity_browser' => 'browse_media_modal',
                    '#cardinality' => 1,
                    '#selection_mode' => 'selection_append',
                    '#default_value' => [],
                    '#entity_browser_validators' => [
                        'entity_type' => [
                            'type' => 'media'
                        ]
                    ],
                    '#widget_context' => [],
                    '#custom_hidden_id' => 'edit-field-visual-target-id',
                    '#process' => [
                        ['\Drupal\entity_browser\Element\EntityBrowserElement', 'processEntityBrowser'],
                        ['Drupal\entity_browser\Plugin\Field\FieldWidget\EntityReferenceBrowserWidget', 'processEntityBrowser']
                    ]
                ],
                '#attached' => [
                    'library' => [
                        'entity_browser/entity_reference'
                    ]
                ],
                'current' => [
                    '#theme_wrappers' => [
                        'container'
                    ],
                    '#attributes' => [
                        'class' => [
                            'entities_list'
                        ]
                    ],
                    'items' => []
                ],
                '#parents' => [
                    'block_image'
                ],
                '#field_name' => 'block_image'
            ],
            '#default_value' => isset($this->configuration['block_image']) ? $this->configuration['block_image'] : '',
            '#required' => true,

        );*/


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
        kint($form_state); die();
        $image = $form_state->getValue('block_image');
        $this->configuration['block_image'] = $image['entities'][0]->id();
        $this->configuration['block_title'] = $form_state->getValue('block_title');
    }
}
