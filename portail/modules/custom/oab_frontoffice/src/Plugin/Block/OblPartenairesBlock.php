<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
/**
 * Created by PhpStorm.
 * User: FVMV3117
 * Date: 29/07/2019
 * Time: 11:12
 */
/**
 *
 * @author FVMV3117
 * @Block(
 *   id = "obl_partenaires_block",
 *   admin_label = @Translation("Partenaires OBL"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class OblPartenairesBlock extends BlockBase {

    public function build() {

        $block = array();

        $current_block = \Drupal\block\Entity\Block::load('partenairesobl');

        if ($current_block) {
            $settings = $current_block->get('settings');
            $content = $settings['content'];
            $title = $settings['block_title'];
        }

        $block['#markup'] = $content;
        $block['block_title'] = $title;

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
        $form['content'] = array(
            '#type' => 'text_format',
            '#title' => t('Liste des réseaux partenaires'),
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
        $this->configuration['block_title'] = $form_state->getValue('block_title');
    }
}