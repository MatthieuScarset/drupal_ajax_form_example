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
 *   id = "obl_couverture_block",
 *   admin_label = @Translation("Couverture OBL"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class OblCouvertureBlock extends BlockBase {

    public function build() {

        $block = array();

        $settings = $this->getConfiguration();

        $block['link'] = isset($settings['link']) ? $settings['link'] : '';
        $block['link_label'] = isset($settings['link_label']) ? $settings['link_label'] : '';
        $block['block_title'] = isset($settings['block_title']) ? $settings['block_title'] : '';

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
        $form['link_label'] = array(
            '#type' => 'textfield',
            '#title' => t('Label du lien'),
            '#default_value' => isset($this->configuration['link_label']) ? $this->configuration['link_label'] : '',
            '#required' => true,
        );

        $form['link'] = array(
          '#type' => 'textfield',
          '#title' => t('Lien'),
          '#default_value' => isset($this->configuration['link']) ? $this->configuration['link'] : '',
          '#required' => true,
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
        $this->configuration['block_title'] = $form_state->getValue('block_title');
        $this->configuration['link_label'] = $form_state->getValue('link_label');
        $this->configuration['link'] = $form_state->getValue('link');
    }
}
