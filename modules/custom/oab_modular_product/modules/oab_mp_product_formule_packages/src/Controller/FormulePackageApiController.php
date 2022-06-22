<?php

namespace Drupal\oab_mp_product_formule_packages\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Render\Renderer;
use Drupal\oab_mp_formules\Entity\ProductFormuleEntity;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackage;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackageType;
use Drupal\oab_mp_product_formule_packages\FormulePackageStorage;
use Laminas\Diactoros\Response\JsonResponse;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\Exception\BadRequestHttpException;
use Symfony\Component\HttpKernel\Exception\NotFoundHttpException;

class FormulePackageApiController extends ControllerBase {

  /**
   * @var \Drupal\Core\Render\Renderer
   */
  private Renderer $renderer;

  public function __construct(Renderer $renderer) {
    $this->renderer = $renderer;
  }


  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('renderer')
    );
  }


  public function packageExistsAction(Request $request, ProductFormuleEntity $product_formule) {

    // On recupère depuis les query params les Formules Fields du product Entity
    $values = array_intersect_key($request->query->all(), $product_formule->getFormuleFields());

    if (empty($values)) {
      throw new BadRequestHttpException($this->t("Given datas are not valid")->__toString());
    }

    if ($this->getUniquePackage($product_formule, $values) !== null) {
      return new JsonResponse([], 204);
    }

    // Si on arrive là, c'est qu'on a rien trouvé => 404 Not Found
    throw new NotFoundHttpException($this->t("No package found for given data"));
  }


  public function getPackageAction(Request $request, ProductFormuleEntity $product_formule) {
    // On recupère depuis les query params les Formules Fields du product Entity
    $values = array_intersect_key($request->query->all(), $product_formule->getFormuleFields());

    if (empty($values)) {
      throw new BadRequestHttpException($this->t("Given datas are not valid")->__toString());
    }


    if ($package = $this->getUniquePackage($product_formule, $values)) {
      $view_builder = $this->entityTypeManager()->getViewBuilder('formule_package');
      $elements = $view_builder->view($package);

      try {
        $render = $this->renderer->render($elements);
      } catch (\Exception) {
        throw new BadRequestHttpException("Cannot render entity");
      }
      return new Response($render);
    }

    // Si on est là, c'est qu'on a pas trouvé l'entité. Return 404
    throw new NotFoundHttpException("Cannot find entity");
  }

  /**
   * Return first found package
   *
   * @param \Drupal\oab_mp_formules\Entity\ProductFormuleEntity $product_formule
   * @param array $fields
   *
   * @return \Drupal\oab_mp_product_formule_packages\Entity\FormulePackage|int|null
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
   */
  private function getUniquePackage(ProductFormuleEntity $product_formule, array $fields): FormulePackage|int|null {
    // On load le PackageType le PackageType qui a notre Formule passée en param'
    $formule_package_type_storage = $this->entityTypeManager()->getStorage('formule_package_type');
    $formule_package_types = $formule_package_type_storage->loadByProperties(['formule' => $product_formule->id()]);


    $result = [];
    if (count($formule_package_types)) {
      /** @var FormulePackageType $formule_package_type */
      $formule_package_type = array_shift($formule_package_types);

      // On cherche tous les packages pour les valeurs envoyées
      /** @var FormulePackageStorage $storage */
      $storage = $this->entityTypeManager()->getStorage('formule_package');
      $result = $storage->getFromFieldValue($fields, $formule_package_type->id());

    }

    return FormulePackage::load(array_key_first($result) ?? 0);
  }

}

