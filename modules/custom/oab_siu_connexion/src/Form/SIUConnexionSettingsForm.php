<?php

namespace Drupal\oab_siu_connexion\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_develop\Logger\OabLogger;

class SIUConnexionSettingsForm extends ConfigFormBase {

  private function getConfigName(): string {
    return 'oab_siu_connexion.settings';
  }

  protected function getEditableConfigNames(): array {
    return [ $this->getConfigName() ];
  }

  public function getFormId(): string {
    return 'oab_siu_connexion_settings';
  }


  public function buildForm(array $form, FormStateInterface $form_state): array {
    $conf = $this->config($this->getConfigName());
    $list_idps = saml_sp__load_all_idps();
    $array_idps = [];
    /**
     * @var string $key
     * @var \Drupal\saml_sp\Entity\Idp $idp
     */
    foreach ($list_idps as $key => $idp) {
      $array_idps[$key] = $idp->label();
    }

    $form['idp'] = array(
      '#type' => 'select',
      '#title' => "IDP à utiliser",
      '#default_value' => $conf->get('idp'),
      '#options' => $array_idps,
      '#multiple' => FALSE,
    );

    $form['siu_restricted_urls'] = [
      '#type' => 'textarea',
      '#title' => t('List URLs to block with SIU Access'),
      '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. An example path is /user/* for every user page. <front> is the front page."),
      '#default_value' => $conf->get('siu_restricted_urls') ?? ''
    ];

    return parent::buildForm($form, $form_state);
  }

  public function submitForm(array &$form, FormStateInterface $form_state) {

    $config = $this->config($this->getConfigName());
    $config->set('idp', $form_state->getValue('idp'));
    $config->set('siu_restricted_urls', $form_state->getValue('siu_restricted_urls'));
    $config->save();
    parent::submitForm($form, $form_state);
  }

}
