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
        $block = array();
        if (!isset($_COOKIE[AcceptCookiesController::COOKIE_NAME])) {
            $config = \Drupal::config(CookieComplianceSettingsForm::CONFIG_NAME);
            $block = array (
                '#theme' => 'block__cookie_compliance_block',
                '#message' => $config->get('cookie_text'),
                '#link_text' => $config->get('cookie_link_text'),
                '#link_url'  => $config->get('cookie_url'),
                '#block_id'  => AcceptCookiesController::BLOCK_ID,
                '#attached' => array(
                    'library' => array(
                        'oab_cookie_compliance/block-library',
                    ),
                )
            );
        }

        $block['#cache'] = array(
            'max-age' => 0,
        );

        \Drupal::service('page_cache_kill_switch')->trigger();


        return $block;
    }

}