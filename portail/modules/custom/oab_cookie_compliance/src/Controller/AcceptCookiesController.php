<?php
namespace Drupal\oab_cookie_compliance\Controller;

define('COOKIE_NAME', 'drupal.obs.cookie-compliance');
define('EXPIRATION_NB_MONTH', 13);


use Drupal\Core\Controller\ControllerBase;
use Symfony\Component\HttpFoundation\JsonResponse;

class AcceptCookiesController extends ControllerBase {
    const COOKIE_NAME = 'drupal_oab_cookie-compliance';
    const BLOCK_ID = 'cookie-compliance-block';

    const EXPIRATION_NB_MONTH = 13;

    public function process() {
        $return = array("response"  => 0);

        $expTime = $this->getExpiration();
            setcookie(self::COOKIE_NAME, '0',$expTime, '/');
            $return['response'] = 1;

        return new JsonResponse($return);
    }


    private function getExpiration() {
        return date("U", strtotime('+' . self::EXPIRATION_NB_MONTH .' months'));
    }
}
