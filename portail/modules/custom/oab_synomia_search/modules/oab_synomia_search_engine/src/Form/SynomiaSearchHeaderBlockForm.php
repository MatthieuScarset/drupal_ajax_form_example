<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 22/08/2017
 * Time: 17:00
 */
namespace Drupal\oab_synomia_search_engine\Form;

use Drupal\Component\Utility\UrlHelper;
use Drupal\Core\Database\Database;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;

class SynomiaSearchHeaderBlockForm extends FormBase {
	/**
	 * {@inheritdoc}
	 */
	public function getFormId() {
		return 'oab_synomia_search_header_block_form';
	}

	/**
	 * {@inheritdoc}
	 */
	public function buildForm(array $form, FormStateInterface $form_state) {
		$parameters = UrlHelper::filterQueryParameters(\Drupal::request()->query->all());

		$form['mot'] = array(
			'#type' => 'textfield',
			'#name' => 'mot',
			'#attributes'=> ['class'=>['search-textfield']],
			'#size' => 15,
		);
		$form['submit'] = [
			'#type' => 'submit',
			'#prefix' => '<div class="top-btn-search"><i class="glyphicon glyphicon-search" ></i>',
			'#attributes'=> ['class'=>['search-link']],
			'#suffix' => '</div>',
		];
/*
		$form['submit'] = array(
			'#type' => 'submit',
			'#markup' => '<button id="search-link" class="search-link" type="submit" data-bkg="gray"><span class="glyphicon glyphicon-search" aria-hidden="true" data-target="#search-form" data-toggle="collapse" font-size="2em"></span></button>',
		);*/
/*
	$form['submit'] = array
		(
			'#type' => 'submit',
			'#value' => '',
			'#submit' => array( 'submitForm' ),
			'#prefix' => '<button id="search-link" class="search-link" type="submit" data-bkg="gray"><span class="glyphicon glyphicon-search" aria-hidden="true" data-target="#search-form" data-toggle="collapse" font-size="2em">',
			'#suffix' => '</span></button>',
		);*/

		return $form;
	}

	/**
	 * {@inheritdoc}
	 */
	public function submitForm(array &$form, FormStateInterface $form_state){
		$current_route = \Drupal::routeMatch()->getRouteName();
		$input = &$form_state->getUserInput();
		$option = [
			'query' => array('mot' => $input["mot"]),
		];
		$url = Url::fromRoute($current_route, array(), $option);
		$form_state->setRedirectUrl($url);
	}
}