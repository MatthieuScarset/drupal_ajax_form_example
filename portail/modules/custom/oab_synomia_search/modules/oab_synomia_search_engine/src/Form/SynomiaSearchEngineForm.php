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

class SynomiaSearchEngineForm extends FormBase {
    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_synomia_search_engine_form';
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());


        $form['search_label'] = array(
            '#type' => 'label',
            '#title' => t('What are you searching for?')
        );

        $form['mot'] = array(
            '#type' => 'textfield',
            '#name' => 'mot',
            '#required' => TRUE,
            //'#title_display' => 'invisible',
            '#default_value' => (!empty($parameters) && isset($parameters['mot'])) ? $parameters['mot'] : '',
        );

        $form['submit'] = array(
            '#type' => 'submit',
            '#value' => t('Search'),
            '#attributes' => Array(
                'title' => t('search')
            )
        );

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
        $url = Url::fromRoute('oab_synomia_search_engine.engine_url', array(), $option);
        $form_state->setRedirectUrl($url);
    }
}
