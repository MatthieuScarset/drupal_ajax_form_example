<?php

namespace Drupal\oab_orange_business_lounge\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;



/**
 * Configure example settings for this site.
 */
class OabOblForm extends ConfigFormBase {

    const ZONE_IMAGES = "zones_image";
    const IMAGE_LOCATION = "public://obl_zone_images";

    public static function getConfigName() {
        return 'oab.orange_business_lounge_settings';
    }

    /**
     * {@inheritdoc}
     */
    public function getFormId() {
        return 'oab_admin_settings_orange_business_lounge';
    }

    /**
     * {@inheritdoc}
     */
    protected function getEditableConfigNames() {
        return [
            self::getConfigName(),
        ];
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state) {
        $config = $this->config(self::getConfigName());
        $settings = $this->configuration;

        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');
        $zones = $obl_service->getZones();
        $images = $config->get('zones_image');


        $form['global'] = array(
            '#type' => 'fieldset',
            '#title' => t('Global Settings'),
        );

        $form['global']['url_api'] = array(
            '#type' => 'url',
            '#title' => $this->t('Url de l\'API'),
            '#default_value' => $config->get('url_api'),
            '#description' => 'API domain : ' . $config->get('url_api'),
            '#size'=> 80,
        );

        $form['global']['test_submit'] = array(
            '#type' => 'submit',
            '#value' => t('Test'),
            '#submit' => array('::isValid')
        );

        $form['global']['title_label'] = array(
            '#type' => 'textfield',
            '#title' => $this->t('Titre de la page'),
            '#default_value' => $config->get('title_label'),
            '#size'=> 350,
        );

        $form['images'] = array(
            '#type' => 'fieldset',
            '#title' => t('Images Settings'),
        );


        $images = $config->get(self::ZONE_IMAGES);

        if (isset($zones['items'])) {
            foreach ($zones['items'] as $key => $zone) {
                $zone_id = $zone['id'];

                $form['images']['image_block_' . $zone_id] = array(
                    '#type' => 'managed_file',
                    '#title' => $this->t($zone['label']),
                    '#upload_location' => self::IMAGE_LOCATION,
                    '#default_value' => isset($images[$zone['id']]) ? [$images[$zone['id']]] : '',
                    //isset($this->configuration['block_image_'.$key]) ? [$this->configuration['block_image_'.$key]] : '',
                );
            }
        }

        return parent::buildForm($form, $form_state);
    }


    /**
     * @param $form
     * @param FormStateInterface $form_state
     */
    function isValid($form, FormStateInterface $form_state) {

        $url = $form_state->getValue('url_api');

        /** @var \Drupal\oab_orange_business_lounge\Services\OabOblSwagger $obl_service */
        $obl_service = \Drupal::service('oab_orange_business_lounge.oab_obl_swagger');

        if ($obl_service->isValid($url)) {
          drupal_set_message(t('Api connected Successfully'), 'status', TRUE);
        } else {
          drupal_set_message(t('Unexpected HTTP code'), 'error', TRUE);
        }

    }


    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state) {
        // Retrieve the configuration
        $values = $form_state->getValues();
        $conf = $this->config($this->getConfigName());

        $conf->set('url_api', $values['url_api']);
        $conf->set('title_label', $values['title_label']);

        $images_id = [];

        foreach ($values as $key => $value) {
            if (strstr($key, 'image_block_') && isset($value[0])) {

                $key_parts = explode('_', $key);

                $file = File::load($value[0]);

                if ($file !== null) {
                    $file->setPermanent();
                    $file->save();

                    $file_usage = \Drupal::service('file.usage');
                    $file_usage->add($file, 'oab_orange_business_lounge', 'oab_orange_business_lounge', \Drupal::currentUser()->id());
                    $images_id[$key_parts[2]] = $file->id();
                }
            }
        }
        $conf->set(self::ZONE_IMAGES, $images_id);

        $conf->save();

        parent::submitForm($form, $form_state);
    }

}
