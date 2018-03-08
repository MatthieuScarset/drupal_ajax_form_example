<?php
namespace Drupal\oab_cookie_compliance\Controller;

define('COOKIE_NAME', 'drupal.obs.cookie-compliance');
define('EXPIRATION_NB_MONTH', 13);


use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\StackMiddleware\Session;
use Drupal\Core\TypedData\Plugin\DataType\Uri;
use Drupal\Core\Url;
use Drupal\system\FileDownloadController;
use Symfony\Component\HttpFoundation\BinaryFileResponse;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;
use Drupal\user\PrivateTempStoreFactory;

class AcceptCookiesController extends ControllerBase {
    const COOKIE_NAME = 'drupal_oab_cookie-compliance';
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
