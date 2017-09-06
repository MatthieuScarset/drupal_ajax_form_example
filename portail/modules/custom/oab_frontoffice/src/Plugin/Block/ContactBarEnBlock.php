<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "contact_bar_en_block",
 *   admin_label = @Translation("Contact Bar EN Standard"),
 *   category = @Translation("Blocks"),
 *   context = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */

class ContactBarEnBlock extends BlockBase {

    public function build(){
        $block = array();

        $block['#markup'] = $this->configuration['content'];
        $block['#format'] = $this->configuration['content_format'];

        $form['link_assistance'] = [
            '#title' => $this->t('Lien vers l\'espace assistance'),
            '#type' => 'link',
            '#url' => '',
        ];
        $form['key_1'] = [
            '#title' => $this->t('Key 1 label'),
            '#type' => 'textfield',
            '#default_value' => '',
            '#required' => false,
        ];
        return $block;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        $form['content'] = array(
            '#type' => 'text_format',
            '#title' => t('Contact Bar content'),
            '#default_value' => isset($this->configuration['content']) ? $this->configuration['content'] : '',
            '#format' => isset($this->configuration['content_format']) ? $this->configuration['content_format'] : 'full_html',
        );

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
        $content = $form_state->getValue('content');
        $this->configuration['content'] = $content['value'];
        $this->configuration['content_format'] = $content['format'];
    }
}