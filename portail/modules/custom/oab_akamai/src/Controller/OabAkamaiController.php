<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 09:29
 */

namespace Drupal\oab_akamai\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\oab_akamai\Form\OabAkamaiForm;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabAkamaiController extends ControllerBase
{
    private $schema = "https://";
    private $akamai_authPrefixe;
    private $akamai_baseUrl;
    private $akamai_reqPath;
    private $akamai_accessToken;
    private $akamai_clientSecret;
    private $akamai_clientToken;
    private $id = "mvymsutrt5rjsq2p";
    private $varnish_ip;

    public function __construct() {
        $config = \Drupal::config(OabAkamaiForm::getConfigName());
        $this->akamai_authPrefixe = $config->get('auth_prefixe');
        $this->akamai_baseUrl = $config->get('base_url');
        $this->akamai_reqPath = $config->get('req_path');
        $this->akamai_accessToken = $config->get('access_token');
        $this->akamai_clientToken = $config->get('client_token');
        $this->akamai_clientSecret = $config->get('client_secret');
        $this->varnish_ip = $config->get('varnish_ip');
    }

  /**
   * Méthode appelée quand on va voir le détail d'un import en BO
   */
    public function testPage(Request $request) {
        $page = "https://www.orange-business.com/fr/blogs/collaboration-en-toute-liberte";
        $this->flushAkamai($page);
        $this->flushVarnish($page, "https://www.orange-business.com");
        $this->flushDrupalCache($page);
    }

    public function flushPage(Request $request) {
        $originUrl = $request->headers->get('referer');

        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $originUrl = str_replace("back.", '', $originUrl);
        $originUrl = str_replace("backoffice.", '', $originUrl);

        if ($originUrl === null) {
            throw new \Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException("Vous ne pouvez pas utiliser cette page sans page d'origine");
        }

        $host = "https://".$request->headers->get('host');

        $this->flushAkamai($originUrl);
        $this->flushVarnish($originUrl, $host);
        $this->flushDrupalCache($originUrl);

        ##je fais toujours retourner vers la page d'origine
        return new RedirectResponse($originUrl);
    }


    public function flushAkamai($page) {

        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $page = str_replace("back.", '', $page);
        $page = str_replace("backoffice.", '', $page);

        $akamai_path = $this->schema . $this->akamai_baseUrl . $this->akamai_reqPath;

        $config_factory = \Drupal::configFactory();
        $configProxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
        if (!empty($config) && !empty($configProxy->get('proxy_server')) && !empty($configProxy->get('proxy_port')))	{
            $proxy_server = $configProxy->get('proxy_server').':'.$configProxy->get('proxy_port');
        } else {
            $proxy_server = NULL;
        }

        #$body = '{"objects":["' . $page . '"]}';
        $body = json_encode(array("objects" => [$page]), JSON_UNESCAPED_UNICODE);
        $auth = $this->akamai_getAuthorization($this->akamai_getTimestamp(), $body);
        $headers = array(
            'Authorization: ' . $auth,
            'Content-Type: ' .  "application/json",
            'Content-Length: ' .  strlen($body)
        );

        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $akamai_path);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
        curl_setopt($ch, CURLOPT_TIMEOUT, 5);
        curl_setopt($ch, CURLOPT_PROXY, $proxy_server);
        curl_setopt($ch, CURLOPT_SSLVERSION, 0);
        curl_setopt($ch, CURLOPT_SSLVERSION, false);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $body);
        $retValue = curl_exec($ch);

        # je laisse pour l'exemple si on repasse en returntransfert = true;
        $jsonRet = json_decode(strstr($retValue, '{'), true);

        $ret = false;
        if (isset($jsonRet['httpStatus']) && $jsonRet['httpStatus'] == 201) {
            $ret = true;
            drupal_set_message("Cache Akamaï vidé pour la page $page", 'status', true);
        } else {
            $msg = (isset($jsonRet['detail'])) ? ": " . $jsonRet['detail'] : "";
            drupal_set_message("Erreur lors de l'appel à Akamaï pour la page $page $msg. Voir en log pour plus d'infos", 'error', true);
            \Drupal::logger('oab_akamai')->notice("Erreur lors du flush Akamaï avec le retour : $retValue");
        }

        curl_close($ch);
        return $ret;
  }

    public function flushVarnish($originUrl, $host) {

        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $host = str_replace("back.", '', $host);
        $host = str_replace("backoffice.", '', $host);

        $originPath = str_replace($host, '', $originUrl);

        $url = "https://" . $this->varnish_ip . $originPath;

       // $cmd = "curl -X BAN -LIk '$url' -H 'Host: www.orange-business.com' -H 'via: akamai'";
        $headers = array(
            'Host: : www.orange-business.com',
            'via: akamai',
        );

        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 4);
        curl_setopt($ch, CURLOPT_TIMEOUT, 5);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'BAN');
        curl_setopt($ch, CURLOPT_SSLVERSION, 0);
        curl_setopt($ch, CURLOPT_SSLVERSION, false);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
        //curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        $retValue = curl_exec($ch);


        $ret = false;
        if ($retValue === false && curl_errno($ch) !== 0) {
            $err = curl_error($ch);
            $err .= ' (' . curl_errno($ch) . " : " . curl_strerror(curl_errno($ch)) . ")";
            drupal_set_message("Erreur lors de l'appel à Varnish pour la page $url. Voir en log pour plus d'infos", 'error', true);
            \Drupal::logger('oab_akamai')->notice("Erreur lors du flush Varnish pour la page $url avec le retour : $err");
        } else {
            $ret = true;
            drupal_set_message("Cache Varnish vidé pour la page $url", 'status', true);
        }

        curl_close($ch);

        return $ret;
    }

    public function flushDrupalCache($url) {


        //Si le flush varnish a fonctionné, je fais aussi un flush drupal cache
        \Drupal::cache("page")->delete("$url");
        drupal_set_message("Cache drupal vidé pour la page $url", 'status', true);
    }

    private function akamai_getAuthorization($timestamp, $data) {
        $nonce = $this->akamai_guidv4();

        $signatureData = $this->akamai_generateSignatureData('POST',$this->akamai_baseUrl,$this->akamai_reqPath,$data, $timestamp, $nonce);
        $signingKey = $this->akamai_generateHash($this->akamai_clientSecret,$timestamp);
        $signature = $this->akamai_generateHash($signingKey,$signatureData);

        $authorization = $this->akamai_authPrefixe
            . "client_token=" . $this->akamai_clientToken . ";"
            . "access_token=" . $this->akamai_accessToken . ";"
            . "timestamp=" . $timestamp . ";"
            . "nonce=" . $nonce . ";"
            . "signature=" . $signature;

        return $authorization;
  }

  private function akamai_generateHash($key, $data, $rawoutput = true) {
      $s = hash_hmac('sha256', $data, $key, $rawoutput);
      $b = str_replace('==', '=',base64_encode($s));
      $c = substr($b, 0, strlen($b) / 2);
      $c .= "=";

      //return $c;
      return base64_encode($s);
  }

    private function akamai_guidv4() {
        if (function_exists('com_create_guid') === true)
            return trim(com_create_guid(), '{}');

        $data = openssl_random_pseudo_bytes(16);
        $data[6] = chr(ord($data[6]) & 0x0f | 0x40); // set version to 0100
        $data[8] = chr(ord($data[8]) & 0x3f | 0x80); // set bits 6-7 to 10

        return vsprintf('%s%s-%s-%s-%s-%s%s%s', str_split(bin2hex($data), 4));
    }

    // Generate Akamai signature Data
    private function akamai_generateSignatureData($reqType, $baseURL, $reqPath, $data, $timestamp, $nonce) {
        if (($reqType == "POST") || ($reqType == "PUT")) {
            $signatureData = $reqType . "\t"
                . "https" . "\t"
                . $baseURL . "\t"
                . $reqPath . "\t"
                . "\t" . base64_encode(hash("sha256", $data, true)) . "\t"
                . $this->akamai_authPrefixe
                . "client_token=" . $this->akamai_clientToken . ";"
                . "access_token=" . $this->akamai_accessToken . ";"
                . "timestamp=" . $timestamp . ";"
                . "nonce=" . $nonce . ";";
            return $signatureData;
        } else {
            $signatureData = $reqType . "\t"
                . "https" . "\t"
                . $baseURL . "\t"
                . $reqPath . "\t" . "\t" . "\t"
                . $this->akamai_authPrefixe
                . "client_token=" . $this->akamai_clientToken . ";"
                . "access_token=" . $this->akamai_accessToken . ";"
                . "timestamp=" . $timestamp . ";"
                . "nonce=" . $nonce . ";";

            return $signatureData;
        }
    }

    private function akamai_getTimestamp() {
        return str_replace('-', '', date(DATE_ISO8601));
    }

}