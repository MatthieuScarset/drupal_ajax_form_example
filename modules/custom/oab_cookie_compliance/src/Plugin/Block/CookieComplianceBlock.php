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

    const COOKIE_NAME               = 'drupal_oab_cookie-compliance_hide-message';
    const BLOCK_ID                  = 'cookie-compliance-block';
    const EXPIRATION_NB_MONTH       = 13;

    public function build() {

        /*if (!isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME])
            && !isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT]) ) {
            CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT);

        } elseif (isset($_COOKIE[CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT])) {
            CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME_FIRST_VISIT, -1);
            CookieComplianceBlock::setCookie(CookieComplianceBlock::COOKIE_NAME);
        }*/

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

        $block['#cache'] = array(
            'max-age' => 0
        );

        \Drupal::service('page_cache_kill_switch')->trigger();


        return $block;
    }

    public function getCacheMaxAge() {
        return 0;
    }

    public function getCacheTags() {
        return ["cookie_compliance"];
    }


    /*public static function setCookie($cookieName, $expTime =  null) {
        if ($expTime === null)
            $expTime = self::getExpiration();

        setcookie($cookieName, '0', $expTime, '/');
    }

    private static function getExpiration() {
        return date("U", strtotime('+' . self::EXPIRATION_NB_MONTH .' months'));
    }*/

}
