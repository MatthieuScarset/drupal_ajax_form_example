<?php

namespace Drupal\oab_cookie_compliance\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
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

    const COOKIE_NAME = 'drupal_oab_cookie-compliance';
    const COOKIE_NAME_FIRST_VISIT = 'drupal_oab_cookie-compliance_first-visit';
    const BLOCK_ID = 'cookie-compliance-block';
    const EXPIRATION_NB_MONTH = 13;

    public function build(){

        $block = array();
        if (!isset($_COOKIE[self::COOKIE_NAME]) && !isset($_COOKIE[self::COOKIE_NAME_FIRST_VISIT]) ) {


            setcookie(self::COOKIE_NAME_FIRST_VISIT, '0', $this->getExpiration(), '/');

            $config = \Drupal::config(CookieComplianceSettingsForm::CONFIG_NAME);
            $block = array (
                '#theme' => 'block__cookie_compliance_block',
                '#message' => $config->get('cookie_text'),
                '#link_text' => $config->get('cookie_link_text'),
                '#link_url'  => $config->get('cookie_url'),
                '#block_id'  => self::BLOCK_ID,
                '#attached' => array(
                    'library' => array(
                        'oab_cookie_compliance/block-library',
                    ),
                )
            );


        } elseif (isset($_COOKIE[self::COOKIE_NAME_FIRST_VISIT])) {
            setcookie(self::COOKIE_NAME_FIRST_VISIT, '0', -1, '/');

            $this->setCookie();
        }

        $block['#cache'] = array(
            'max-age' => 0,
            'contexts' => array("cookie"),
            'tags'  => array("cookie")
        );

        \Drupal::service('page_cache_kill_switch')->trigger();


        return $block;
    }


    private function setCookie( $expTime =  null) {
        if ($expTime === null)
            $expTime = self::getExpiration();

        setcookie(self::COOKIE_NAME, '0', $expTime, '/');
    }

    private function getExpiration() {
        return date("U", strtotime('+' . self::EXPIRATION_NB_MONTH .' months'));
    }

}