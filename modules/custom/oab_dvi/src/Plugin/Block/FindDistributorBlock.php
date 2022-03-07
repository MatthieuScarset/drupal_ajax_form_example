<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 05/12/2017
 * Time: 10:28
 */

namespace Drupal\oab_dvi\Plugin\Block;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Database\Database;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Drupal\node\Entity\Node;

/**
 *
 * @author QWWT2837
 * @Block(
 *   id = "find_distributor_block",
 *   admin_label = @Translation("Find Distributor Block"),
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

class FindDistributorBlock  extends BlockBase {

    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        $form['title'] = [
            '#title' => $this->t('Block Title'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['title']) ? $this->configuration['title'] : 'Find a distributor near you',
            '#required' => true,
        ];
        $form['description'] = [
            '#title' => $this->t('Description block'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['description']) ? $this->configuration['description'] : '',
            '#required' => true,
        ];
        $form['button_label'] = [
            '#title' => $this->t('Button label'),
            '#type' => 'textfield',
            '#default_value' => isset($this->configuration['button_label']) ? $this->configuration['button_label'] : 'Find',
            '#required' => true,
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
        $this->setConfigurationValue('title', $form_state->getValue('title'));
        $this->setConfigurationValue('description', $form_state->getValue('description'));
        $this->setConfigurationValue('button_label', $form_state->getValue('button_label'));
    }

    public function build() {
        $show_block = FALSE;
        $config = $this->getConfiguration();
        $block = array();
        $block_empty = true;
        // récupération du contexte
        $node_context = $this->getContextValue('node');
        $nid_field = $node_context->nid->getValue();
        $nid = $nid_field[0]['value'];
        // chargement du noeud et de la valeur axiome_data
        $node = Node::load($nid);
        $type = $node->getType();

        if ($type == 'product') {


            $query = Database::getConnection()->select('node__field_products', 'np');
            $query->leftjoin('node_field_data', 'n', 'n.nid = np.entity_id');
            $query->condition('np.bundle', 'distributor', '=');
            $query->condition('np.field_products_target_id', $nid, '=');
            $query->condition('n.status', 1, '=');
            $count = $query->countQuery()->execute()->fetchField();

            if ($count > 0) {
                $block = array(
                    'title' => isset($config['title']) ? t($config['title']) : '',
                    'text' => isset($config['description']) ? t($config['description']) : '',
                    'link'  => Url::fromRoute('view.subhomes.page_distributor', array('product' => $nid)) ,
                    'link_text' => isset($config['button_label']) ? t($config['button_label']) : '',
                );
                $show_block = TRUE;
            }


        }

        if ($show_block) {
            return $block;
        } else {
            return NULL;
        }
    }
}
