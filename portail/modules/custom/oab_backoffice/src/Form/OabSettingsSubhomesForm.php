<?php

namespace Drupal\oab_backoffice\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Configure example settings for this site.
 */
class OabSettingsSubhomesForm extends ConfigFormBase {

    public static function getConfigName() {
        return 'oab_subhomes.subhomes';
    }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'oab_admin_settings_subhomes';
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

    $form['press_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Press term ID'),
      '#default_value' => $config->get('press_term_tid'),
    );

    $form['partner_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Partner term ID'),
      '#default_value' => $config->get('partner_term_tid'),
    );

    $form['customer_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Customer term ID'),
      '#default_value' => $config->get('customer_term_tid'),
    );

    $form['library_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Library term ID'),
      '#default_value' => $config->get('library_term_tid'),
    );

    $form['blog_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Blog term ID'),
      '#default_value' => $config->get('blog_term_tid'),
    );

    $form['magazine_term_tid'] = array(
      '#type' => 'textfield',
      '#title' => $this->t('Magazine term ID'),
      '#default_value' => $config->get('magazine_term_tid'),
    );

    $form['product_term_tid'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Product term ID'),
          '#default_value' => $config->get('product_term_tid'),
      );

      $form['product_dvi_term_tid'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Product DVI term ID'),
          '#default_value' => $config->get('product_dvi_term_tid'),
      );

      $form['distributor_term_tid'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Distributor term ID'),
          '#default_value' => $config->get('distributor_term_tid'),
      );

      $form['analysts_term_tid'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Analysts term ID'),
          '#default_value' => $config->get('analysts_term_tid'),
      );

      $form['news_term_tid'] = array(
        '#type' => 'textfield',
        '#title' => $this->t('News term ID'),
        '#default_value' => $config->get('news_term_tid'),
      );

      $form['achievement_term_tid'] = array(
        '#type' => 'textfield',
        '#title' => $this->t('IoT Achievements term ID'),
        '#default_value' => $config->get('achievement_term_tid')
      );

      $form['iot_product_term_tid'] = array(
        '#type' => 'textfield',
        '#title' => $this->t('IoT Products term ID'),
        '#default_value' => $config->get('iot_product_term_tid'),
      );

      $form['press_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Press subhome'),
          '#default_value' => $config->get('press_meta'),
      );

      $form['partner_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Partner subhome'),
          '#default_value' => $config->get('partner_meta'),
      );

      $form['customer_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Customer subhome'),
          '#default_value' => $config->get('customer_meta'),
      );

      $form['library_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Library subhome'),
          '#default_value' => $config->get('library_meta'),
      );

      $form['blog_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Blog subhome'),
          '#default_value' => $config->get('blog_meta'),
      );

      $form['magazine_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Magazine subhome'),
          '#default_value' => $config->get('magazine_meta'),
      );

      $form['product_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Product subhome'),
          '#default_value' => $config->get('product_meta'),
      );

      $form['analysts_meta'] = array(
          '#type' => 'textfield',
          '#title' => $this->t('Meta Title for Analysts subhome'),
          '#default_value' => $config->get('analysts_meta'),
      );

      $form['iot_achievement_meta'] = array(
        '#type' => 'textfield',
        '#title' => $this->t('Meta Title for IoT Achievements subhome'),
        '#default_value' => $config->get('iot_achievement_meta'),
      );

      $form['iot_product_meta'] = array(
        '#type' => 'textfield',
        '#title' => $this->t('Meta Title for IoT Products subhome'),
        '#default_value' => $config->get('iot_product_meta'),
      );

      return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    // Retrieve the configuration
    $this->config('oab_subhomes.subhomes')
      ->set('press_term_tid', $form_state->getValue('press_term_tid'))
      ->set('partner_term_tid', $form_state->getValue('partner_term_tid'))
      ->set('customer_term_tid', $form_state->getValue('customer_term_tid'))
      ->set('library_term_tid', $form_state->getValue('library_term_tid'))
      ->set('blog_term_tid', $form_state->getValue('blog_term_tid'))
      ->set('magazine_term_tid', $form_state->getValue('magazine_term_tid'))
      ->set('product_term_tid', $form_state->getValue('product_term_tid'))
      ->set('product_dvi_term_tid', $form_state->getValue('product_dvi_term_tid'))
      ->set('distributor_term_tid', $form_state->getValue('distributor_term_tid'))
      ->set('analysts_term_tid', $form_state->getValue('analysts_term_tid'))
      ->set('news_term_tid', $form_state->getValue('news_term_tid'))
      ->set('achievement_term_tid', $form_state->getValue('achievement_term_tid'))
      ->set('iot_product_term_tid', $form_state->getValue('iot_product_term_tid'))
      ->set('press_meta', $form_state->getValue('press_meta'))
      ->set('partner_meta', $form_state->getValue('partner_meta'))
      ->set('customer_meta', $form_state->getValue('customer_meta'))
      ->set('library_meta', $form_state->getValue('library_meta'))
      ->set('blog_meta', $form_state->getValue('blog_meta'))
      ->set('magazine_meta', $form_state->getValue('magazine_meta'))
      ->set('product_meta', $form_state->getValue('product_meta'))
      ->set('analysts_meta', $form_state->getValue('analysts_meta'))
      ->set('iot_achievement_meta', $form_state->getValue('iot_achievement_meta'))
      ->set('iot_product_meta', $form_state->getValue('iot_product_meta'))
      ->save();

    parent::submitForm($form, $form_state);
  }
}
