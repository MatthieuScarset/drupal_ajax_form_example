<?php

namespace Drupal\oab_mp_formules\Controller;

use Drupal\Component\Utility\Xss;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\core\Link;
use Drupal\Core\Url;
use Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Class ProductFormuleEntityController.
 *
 *  Returns responses for Product formule entity routes.
 */
class ProductFormuleEntityController extends ControllerBase implements ContainerInjectionInterface {

  /**
   * The date formatter.
   *
   * @var \Drupal\Core\Datetime\DateFormatter
   */
  protected $dateFormatter;

  /**
   * The renderer.
   *
   * @var \Drupal\Core\Render\Renderer
   */
  protected $renderer;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    $instance = parent::create($container);
    $instance->dateFormatter = $container->get('date.formatter');
    $instance->renderer = $container->get('renderer');
    return $instance;
  }

  /**
   * Displays a Product formule entity revision.
   *
   * @param int $product_formule_entity_revision
   *   The Product formule entity revision ID.
   *
   * @return array
   *   An array suitable for drupal_render().
   */
  public function revisionShow($product_formule_entity_revision) {
    $product_formule_entity = $this->entityTypeManager()->getStorage('product_formule_entity')
      ->loadRevision($product_formule_entity_revision);
    $view_builder = $this->entityTypeManager()->getViewBuilder('product_formule_entity');

    return $view_builder->view($product_formule_entity);
  }

  /**
   * Page title callback for a Product formule entity revision.
   *
   * @param int $product_formule_entity_revision
   *   The Product formule entity revision ID.
   *
   * @return string
   *   The page title.
   */
  public function revisionPageTitle($product_formule_entity_revision) {
    $product_formule_entity = $this->entityTypeManager()->getStorage('product_formule_entity')
      ->loadRevision($product_formule_entity_revision);
    return $this->t('Revision of %title from %date', [
      '%title' => $product_formule_entity->label(),
      '%date' => $this->dateFormatter->format($product_formule_entity->getRevisionCreationTime()),
    ]);
  }

  /**
   * Generates an overview table of older revisions of a Product formule entity.
   *
   * @param \Drupal\oab_mp_formules\Entity\ProductFormuleEntityInterface $product_formule_entity
   *   A Product formule entity object.
   *
   * @return array
   *   An array as expected by drupal_render().
   */
  public function revisionOverview(ProductFormuleEntityInterface $product_formule_entity) {
    $account = $this->currentUser();
    $product_formule_entity_storage = $this->entityTypeManager()->getStorage('product_formule_entity');

    $build['#title'] = $this->t('Revisions for %title', ['%title' => $product_formule_entity->label()]);

    $header = [$this->t('Revision'), $this->t('Operations')];
    $revert_permission = (($account->hasPermission("revert all product formule entity revisions") || $account->hasPermission('administer product formule entity entities')));
    $delete_permission = (($account->hasPermission("delete all product formule entity revisions") || $account->hasPermission('administer product formule entity entities')));

    $rows = [];

    $vids = $product_formule_entity_storage->revisionIds($product_formule_entity);

    $latest_revision = TRUE;

    foreach (array_reverse($vids) as $vid) {
      /** @var \Drupal\oab_mp_formules\ProductFormuleEntityInterface $revision */
      $revision = $product_formule_entity_storage->loadRevision($vid);
        $username = [
          '#theme' => 'username',
          '#account' => $revision->getRevisionUser(),
        ];

        // Use revision link to link to revisions that are not active.
        $date = $this->dateFormatter->format($revision->getRevisionCreationTime(), 'short');
        if ($vid != $product_formule_entity->getRevisionId()) {
          $link = Link::fromTextAndUrl($date, new Url('entity.product_formule_entity.revision', [
            'product_formule_entity' => $product_formule_entity->id(),
            'product_formule_entity_revision' => $vid,
          ]));
        }
        else {
          $link = $product_formule_entity->toLink($date)->toString();
        }

        $row = [];
        $column = [
          'data' => [
            '#type' => 'inline_template',
            '#template' => '{% trans %}{{ date }} by {{ username }}{% endtrans %}{% if message %}<p class="revision-log">{{ message }}</p>{% endif %}',
            '#context' => [
              'date' => $link,
              'username' => $this->renderer->renderPlain($username),
              'message' => [
                '#markup' => $revision->getRevisionLogMessage(),
                '#allowed_tags' => Xss::getHtmlTagList(),
              ],
            ],
          ],
        ];
        $row[] = $column;

        if ($latest_revision) {
          $row[] = [
            'data' => [
              '#prefix' => '<em>',
              '#markup' => $this->t('Current revision'),
              '#suffix' => '</em>',
            ],
          ];
          foreach ($row as &$current) {
            $current['class'] = ['revision-current'];
          }
          $latest_revision = FALSE;
        }
        else {
          $links = [];
          if ($revert_permission) {
            $links['revert'] = [
              'title' => $this->t('Revert'),
              'url' => Url::fromRoute('entity.product_formule_entity.revision_revert', [
                'product_formule_entity' => $product_formule_entity->id(),
                'product_formule_entity_revision' => $vid,
              ]),
            ];
          }

          if ($delete_permission) {
            $links['delete'] = [
              'title' => $this->t('Delete'),
              'url' => Url::fromRoute('entity.product_formule_entity.revision_delete', [
                'product_formule_entity' => $product_formule_entity->id(),
                'product_formule_entity_revision' => $vid,
              ]),
            ];
          }

          $row[] = [
            'data' => [
              '#type' => 'operations',
              '#links' => $links,
            ],
          ];
        }

        $rows[] = $row;
    }

    $build['product_formule_entity_revisions_table'] = [
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
    ];

    return $build;
  }

}
