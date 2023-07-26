<?php

namespace Drupal\oab_frontoffice\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;


/**
 *
 * @author FFLB8539
 * @Block(
 *   id = "phone_number_block",
 *   admin_label = @Translation("Phone Number"),
 *   category = @Translation("Blocks"),
 *   context_definitions = {
 *     "node" = @ContextDefinition(
 *       "entity:node",
 *       label = @Translation("Current Node")
 *     )
 *   }
 * )
 *
 */

class PhoneNumberBlock extends BlockBase {

    public function build() {
        $block = array();
                $config = $this->getConfiguration();
        // récupération du contexte
        $node_ctxt = $this->getContextValue('node');
        $nid_fld = $node_ctxt->nid->getValue();
        $nid = $nid_fld[0]['value'];
        // chargement du noeud et de la valeur top zone
        $node = Node::load($nid);
        if ($node->hasField('field_phone_number')) {
            $phone_number = $node->get('field_phone_number')->getValue();
        }

        $block['block_num_tel'] = '';
        if (isset($phone_number[0]['value'])) {
            //$content = check_markup($phone_number[0]['value'], 'full_html', '', []);
          $block['block_num_tel'] = $phone_number[0]['value'];
        }

        $block['block_title'] = isset($config['block_title']) ? t($config['block_title']) : '';//oabt($config, true);

        return $block;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

                $form['block_title'] = [
                    '#title' => $this->t('Block Title'),
                    '#type' => 'textfield',
                    '#default_value' => isset($this->configuration['block_title'])
                      ? $this->configuration['block_title'] : 'To contact him by phone',
                    '#required' => true,
                ];
        $form['content'] = array(
            '#type' => 'text_format',
            '#title' => t('Phone number content'),
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
