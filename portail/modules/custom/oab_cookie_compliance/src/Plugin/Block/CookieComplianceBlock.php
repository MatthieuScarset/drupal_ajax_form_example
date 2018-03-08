<?php

namespace Drupal\oab_cookie_compliance\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\oab_cookie_compliance\Controller\AcceptCookiesController;
use Drupal\oab_cookie_compliance\Form\CookieComplianceSettingsForm;

/**
 *
 * @author PZHM3753
 * @Block(
 *   id = "cookie_compliance_block",
 *   admin_label = @Translation("Cookie compliance Block"),
 *   category = @Translation("Blocks"),
 * )
 *
 */

class CookieComplianceBlock extends BlockBase {

    public function build(){

       $block = [];

        if (!isset($_COOKIE[AcceptCookiesController::COOKIE_NAME])) {
            kint($_COOKIE);
            kint(AcceptCookiesController::COOKIE_NAME);
            $config = \Drupal::config(CookieComplianceSettingsForm::CONFIG_NAME);
            $block = [
                '#theme' => 'block__cookie_compliance_block',
                '#message' => $config->get('cookie_text'),
                '#link_text' => $config->get('cookie_link_text'),
                '#link_url'  => $config->get('cookie_url'),
                '#attached' => [
                    'library'   => [
                        'oab_cookie_compliance/block-library'
                    ]
                ]
            ];
        } else {
            kint($_COOKIE[AcceptCookiesController::COOKIE_NAME]);
        }
        $block['#cache']['max-age'] = 0;
        return $block;
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);
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

    }
}