<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 22/08/2017
 * Time: 17:00
 */
namespace Drupal\oab_synomia_search_engine\Form;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Database\Database;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

class SynomiaMSSAssistanceSearchBlockForm extends FormBase {
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_synomia_mss_assistance_search_block_form';
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $form['mot'] = array(
            '#type' => 'textfield',
            '#name' => 'mot',
            '#attributes'=> ['class'=>['search-textfield']],
            '#size' => 15,
        );
        $form['submit'] = [
            '#type' => 'submit',
            '#prefix' => '<div class="top-btn-search"><i class="glyphicon glyphicon-search" ></i>',
            '#attributes'=> ['class'=>['search-link'], 'onmousedown' => 'utag_link(utag_data.titre_page, \'Menu\', \'Rechercher\', \'\');return true;'],
            '#suffix' => '</div>',
        ];
        return $form;
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        $input = &$form_state->getUserInput();
        $option = [
            'query' => array('mot' => $input["mot"]),
        ];
        $url = Url::fromRoute('oab_synomia_search_engine.mss_assistance_engine_url', array(), $option);
        $form_state->setRedirectUrl($url);
    }
}
