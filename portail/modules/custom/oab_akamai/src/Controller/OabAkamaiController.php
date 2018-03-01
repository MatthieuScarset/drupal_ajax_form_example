<?php

/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 17/10/2016
 * Time: 09:29
 */

namespace Drupal\oab_akamai\Controller;


use Drupal\Core\Controller\ControllerBase;
use Drupal\oab_backoffice\Form\OabGeneralSettingsForm;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class OabAkamaiController extends ControllerBase
{
  /** Méthode appelée quand on va voir le détail d'un import en BO
   */
  public function test(Request $request){

		$current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
		$url = "https://akab-lgsc3ap2lfgdhc65-gnbwwdu5i4yvnlfx.purge.akamaiapis.net";
		$access_token = "akab-zcn5oqfkvcbrs52g-mu6txykkxrrhm5im";
		$id = "mvymsutrt5rjsq2p";
		$client_secret = "9nGqXelX88v/1/J0TDo6dOLJst3u8C0qo+pkp4p4WF0=";
		$client_token = "akab-3eq5kc5srq6rtq6n-sfxlqqrosopuhfyp";

		if(!empty($url))
		{
			//$path = $url.;
			$path = $url.'/diagnostic-tools/v1/locations';

			//oabt($path);die();

			$config_factory = \Drupal::configFactory();
			$configProxy = $config_factory->get(OabGeneralSettingsForm::getConfigName());
			if(!empty($config) && !empty($configProxy->get('proxy_server')) && !empty($configProxy->get('proxy_port')))			{
				$proxy_server = $configProxy->get('proxy_server').':'.$configProxy->get('proxy_port');
			}
			else{
				$proxy_server = NULL;
			}

			//var_dump($path);
			$ch = curl_init();
			curl_setopt($ch, CURLOPT_URL, $path);
			curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
			curl_setopt($ch, CURLOPT_TIMEOUT, 5);
			curl_setopt($ch, CURLOPT_PROXY, $proxy_server);
			curl_setopt($ch, CURLOPT_SSLVERSION, 0);
			curl_setopt($ch, CURLOPT_SSLVERSION, false);
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
			$headers = array(
				'Authorization' => 'EG1-HMAC-SHA256',
				'client_token' => $client_token,
				'access_token' => $access_token,
				'timestamp' => time(),
			);

			curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
			$retValue = curl_exec($ch);
			oabt($retValue);
			curl_close($ch);
		}

    return array(    );
  }

}