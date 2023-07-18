<?php

namespace Drupal\oab_marketo\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Entity\EntityStorageException;
use Drupal\Core\Entity\EntityTypeManager;
use Drupal\oab_marketo\AltaresTokenService;
use Drupal\oab_marketo\DnbHttpClient\DnbClient;
use Drupal\oab_marketo\DnbHttpClient\DnbService;
use Drupal\oab_marketo\Entity\PhotoCommercialeItem;
use Drupal\oab_marketo\PhotoCommercialeService;
use http\Params;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpKernel\Exception\HttpException;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class AltaresApiController extends ControllerBase implements ContainerInjectionInterface {

    /**
     * @var AltaresTokenService
     */
    private $altaresTokenService;
    private $altaresService;
    private $photoCommercialeService;

    public function __construct(AltaresTokenService $altares_token_service,
                                DnbService $altares_service,
                                PhotoCommercialeService $photo_commerciale_service
    ) {
        $this->altaresTokenService = $altares_token_service;
        $this->altaresService = $altares_service;
        $this->photoCommercialeService = $photo_commerciale_service;
    }

    public static function create(ContainerInterface $container) {
        return new self(
            $container->get('oab_marketo.altares_token.service'),
            $container->get('oab_marketo.dnb_service'),
            $container->get('oab_marketo.photo_commerciale.service')
        );
    }

    /**
     * Create Token Action
     *
     * @param Request $request
     * @return JsonResponse
     */
    public function tokenAction(Request $request) {

  //    /** @var EntityTypeManager $entity_type_manager */
  //    $entity_type_manager = \Drupal::service("entity_type_manager");
  //    $entity_type_manager->getStorage('photo_commerciale_item')->create();
  //
  //    while ($f->readNextCsvL) {
  //      $line = PhotoCommercialeItem::create([
  //        'siret' => $csv_lin[AltaresApiController::NumColSiret]
  //      ]);
  //      $line->save();
  //    }

        try {
            $token = $this->altaresTokenService->createToken();

            $ret = [
              'token' => $token->getToken(),
              'expires' => $token->getExpires()
            ];

            return new JsonResponse($ret);
        } catch (EntityStorageException $e) {
            throw new HttpException(400);
        }
    }


    /**
     * Get Company Typehead Action.
     * Récupère les lettres tapées par l'utilisateur et appelle la fonction typehead puis affiche les candidats conformes
     *
     * @param Request $request
     * @return JsonResponse
     */
    public function getCompanyAutocompleteAction(Request $request) { //String $string

        if (!$request->query->has('name')) {
          throw new NotFoundHttpException('There is no given company name');
        }

        $all_params = $request->query->all();
        $params_name = $all_params['name'];
        unset($all_params['name']);


        $res = $this->altaresService->typeahead($params_name, $all_params);

        if (!empty($res)) {
            return new JsonResponse($res);
        } else {
            return new JsonResponse([]);
        }
    }

    /**
     * Get Company Information Action
     * Récupère les infos de l'entreprise selectionné par l'utilisateur
     *
     * @param Request $request
     * @return array|mixed
     */
    public function getCompanyInfoAction(Request $request) { //String $countryAlphaCode, String $siret, String $duns

        if (!$request->query->has('duns')) {
            throw new NotFoundHttpException('There is no given DUNS');
        }
        $duns = $request->query->get('duns');
        //recup info par duns
        $res = $this->altaresService->getInfo($duns);

        if (!empty($res)) {
          $reg_numb_type = $res[0]["organization"]["registrationNumbers"][0]["typeDescription"];
          $reg_numb = $res[0]["organization"]["registrationNumbers"][0]["registrationNumber"];
          $raison_sociale = $res[0]["organization"]["primaryName"];

          $photo_commerciale = $this->photoCommercialeService->getPhotoCommercialeItem($reg_numb_type, $reg_numb, $raison_sociale);

          if (!empty($photo_commerciale)) {
            $res_photo = $photo_commerciale->getFieldsAsArray();
          } else {
            $res_photo = [];
          }
        } else {
          $res = [];
          $res_photo = [];
        }

        $return  = [
          'altares' => $res,
          'photo_commerciale' => $res_photo,
        ];

        return new JsonResponse($return);
    }
}

