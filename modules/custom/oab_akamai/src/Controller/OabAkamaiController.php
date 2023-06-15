<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 09:29
 */

namespace Drupal\oab_akamai\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\File\FileSystemInterface;
use Drupal\Core\Routing\RouteBuilderInterface;
use Drupal\oab_akamai\Form\OabAkamaiForm;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabAkamaiController extends ControllerBase
{
    private $schema = "https://";
    private $authPrefixe;
    private $baseUrl;
    private $reqPath;
    private $accessToken;
    private $clientSecret;
    private $clientToken;
    private $id = "mvymsutrt5rjsq2p";
    private $varnishIp;


    public function __construct() {
        $config = \Drupal::config(OabAkamaiForm::getConfigName());
        $this->authPrefixe = $config->get('auth_prefixe');
        $this->baseUrl = $config->get('base_url');
        $this->reqPath = $config->get('req_path');
        $this->accessToken = $config->get('access_token');
        $this->clientToken = $config->get('client_token');
        $this->clientSecret = $config->get('client_secret');
        $this->varnishIp = $config->get('varnish_ip');
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
        $origin_url = $request->headers->get('referer');

        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $origin_url = str_replace("back.", '', $origin_url);
        $origin_url = str_replace("backoffice.", '', $origin_url);

        if ($origin_url === null) {
            throw new \Symfony\Component\HttpKernel\Exception\AccessDeniedHttpException(
                "Vous ne pouvez pas utiliser cette page sans page d'origine"
            );
        }

        $host = "https://".$request->headers->get('host');

        $this->flushAkamai($origin_url);
        $this->flushVarnish($origin_url, $host);
        $this->flushDrupalCache($origin_url);

        ##je fais toujours retourner vers la page d'origine
        return new RedirectResponse($origin_url);
    }


    public function flushAkamai($page) {

        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $page = str_replace("back.", '', $page);
        $page = str_replace("backoffice.", '', $page);

        $akamai_path = $this->schema . $this->baseUrl . $this->reqPath;

        $config_factory = \Drupal::configFactory();
        $config_proxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
        if (!empty($config) && !empty($config_proxy->get('proxy_server')) && !empty($config_proxy->get('proxy_port'))) {
            $proxy_server = $config_proxy->get('proxy_server').':'.$config_proxy->get('proxy_port');
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
        $ret_value = curl_exec($ch);

        # je laisse pour l'exemple si on repasse en returntransfert = true;
        $json_ret = json_decode(strstr($ret_value, '{'), true);

        $ret = false;
        $msg = "";
        if (isset($json_ret['httpStatus']) && $json_ret['httpStatus'] == 201) {
            $ret = true;
            $this->messenger()->addMessage(t("Cache Akamaï vidé pour la page $page"), 'status', true);
        } else {
            $msg = (isset($json_ret['detail'])) ? ": " . $json_ret['detail'] : "";
            $this->messenger()->addError(t("Erreur lors de l'appel à Akamaï pour la page $page $msg. Voir en log pour plus d'infos"),true);
            \Drupal::logger('oab_akamai')->notice("Erreur lors du flush Akamaï avec le retour : $ret_value");
        }

        curl_close($ch);
        return $ret;
  }

    public function flushVarnish($origin_url, $host) {

      if(!isset($this->varnishIp) || empty($this->varnishIp)) {
        return true;
      }
      else {
        #Je supprime le prefixe "back." et "backoffice" pour vider le cache en prod
        $host = str_replace("back.", '', $host);
        $host = str_replace("backoffice.", '', $host);

        $origin_path = str_replace($host, '', $origin_url);

        $url = "https://" . $this->varnishIp . $origin_path;

        // $cmd = "curl -X BAN -LIk '$url' -H 'Host: www.orange-business.com' -H 'via: akamai'";
        $headers = [
          'Host: www.orange-business.com',
          'via: akamai',
        ];

        $ch = curl_init();

        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 4);
        curl_setopt($ch, CURLOPT_TIMEOUT, 5);
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'BAN');
        curl_setopt($ch, CURLOPT_SSLVERSION, 0);
        curl_setopt($ch, CURLOPT_SSLVERSION, FALSE);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
        //curl_setopt($ch, CURLOPT_POST, true);
        curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch, CURLOPT_HEADER, 1);
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
        $ret_value = curl_exec($ch);


        $ret = FALSE;
        if ($ret_value === FALSE && curl_errno($ch) !== 0) {
          $err = curl_error($ch);
          $err .= ' (' . curl_errno($ch) . " : " . curl_strerror(curl_errno($ch)) . ")";
          $this->messenger()
            ->addError(t("Erreur lors de l'appel à Varnish pour la page $url. Voir en log pour plus d'infos"), TRUE);
          \Drupal::logger('oab_akamai')
            ->notice("Erreur lors du flush Varnish pour la page $url avec le retour : $err");
        }
        else {
          $ret = TRUE;
          $this->messenger()
            ->addMessage(t('Cache Varnish vidé pour la page $url'), 'status', TRUE);

        }

        curl_close($ch);

        return $ret;
      }
    }

    public function flushDrupalCache($url) {


        //Si le flush varnish a fonctionné, je fais aussi un flush drupal cache
        \Drupal::cache("page")->delete("$url");
        \Drupal::service("router.builder")->rebuild();
        $this->messenger()->addMessage(t("Cache drupal vidé pour la page $url"), 'status', true);

    }

    private function akamai_getAuthorization($timestamp, $data) {
        $nonce = $this->akamai_guidv4();

        $signature_data = $this->akamai_generateSignatureData('POST', $this->baseUrl, $this->reqPath, $data, $timestamp, $nonce);
        $signing_key = $this->akamai_generateHash($this->clientSecret, $timestamp);
        $signature = $this->akamai_generateHash($signing_key, $signature_data);

        $authorization = $this->authPrefixe
            . "client_token=" . $this->clientToken . ";"
            . "access_token=" . $this->accessToken . ";"
            . "timestamp=" . $timestamp . ";"
            . "nonce=" . $nonce . ";"
            . "signature=" . $signature;

        return $authorization;
  }

  private function akamai_generateHash($key, $data, $rawoutput = true) {
      $s = hash_hmac('sha256', $data, $key, $rawoutput);
      $b = str_replace('==', '=', base64_encode($s));
      $c = substr($b, 0, strlen($b) / 2);
      $c .= "=";

      //return $c;
      return base64_encode($s);
  }

    private function akamai_guidv4() {
        if (function_exists('com_create_guid') === true) {
            return trim(com_create_guid(), '{}');
        }

        $data = openssl_random_pseudo_bytes(16);
        $data[6] = chr(ord($data[6]) & 0x0f | 0x40); // set version to 0100
        $data[8] = chr(ord($data[8]) & 0x3f | 0x80); // set bits 6-7 to 10

        return vsprintf('%s%s-%s-%s-%s-%s%s%s', str_split(bin2hex($data), 4));
    }

    // Generate Akamai signature Data
    private function akamai_generateSignatureData($req_type, $base_url, $req_path, $data, $timestamp, $nonce) {
        if (($req_type == "POST") || ($req_type == "PUT")) {
            $signature_data = $req_type . "\t"
                . "https" . "\t"
                . $base_url . "\t"
                . $req_path . "\t"
                . "\t" . base64_encode(hash("sha256", $data, true)) . "\t"
                . $this->authPrefixe
                . "client_token=" . $this->clientToken . ";"
                . "access_token=" . $this->accessToken . ";"
                . "timestamp=" . $timestamp . ";"
                . "nonce=" . $nonce . ";";
            return $signature_data;
        } else {
            $signature_data = $req_type . "\t"
                . "https" . "\t"
                . $base_url . "\t"
                . $req_path . "\t" . "\t" . "\t"
                . $this->authPrefixe
                . "client_token=" . $this->clientToken . ";"
                . "access_token=" . $this->accessToken . ";"
                . "timestamp=" . $timestamp . ";"
                . "nonce=" . $nonce . ";";

            return $signature_data;
        }
    }

    private function akamai_getTimestamp() {
      // Akamai a besoin du timestamp dans ce format, malgré la déprécation
      return str_replace('-', '', date(DATE_ISO8601));
    }

}
