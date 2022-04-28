<?php

namespace Drupal\oab_mp_product_formule_packages\Controller;

use Drupal\Component\Utility\Xss;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Class FormulePackageController.
 *
 *  Returns responses for Formule package routes.
 */
class FormulePackageController extends ControllerBase implements ContainerInjectionInterface {

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
   * Displays a Formule package revision.
   *
   * @param int $formule_package_revision
   *   The Formule package revision ID.
   *
   * @return array
   *   An array suitable for drupal_render().
   */
  public function revisionShow($formule_package_revision) {
    $formule_package = $this->entityTypeManager()->getStorage('formule_package')
      ->loadRevision($formule_package_revision);
    $view_builder = $this->entityTypeManager()->getViewBuilder('formule_package');

    return $view_builder->view($formule_package);
  }

  /**
   * Page title callback for a Formule package revision.
   *
   * @param int $formule_package_revision
   *   The Formule package revision ID.
   *
   * @return string
   *   The page title.
   */
  public function revisionPageTitle($formule_package_revision) {
    $formule_package = $this->entityTypeManager()->getStorage('formule_package')
      ->loadRevision($formule_package_revision);
    return $this->t('Revision of %title from %date', [
      '%title' => $formule_package->label(),
      '%date' => $this->dateFormatter->format($formule_package->getRevisionCreationTime()),
    ]);
  }

  /**
   * Generates an overview table of older revisions of a Formule package.
   *
   * @param \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface $formule_package
   *   A Formule package object.
   *
   * @return array
   *   An array as expected by drupal_render().
   */
  public function revisionOverview(FormulePackageInterface $formule_package) {
    $account = $this->currentUser();
    $formule_package_storage = $this->entityTypeManager()->getStorage('formule_package');

    $build['#title'] = $this->t('Revisions for %title', ['%title' => $formule_package->label()]);

    $header = [$this->t('Revision'), $this->t('Operations')];
    $revert_permission = (($account->hasPermission("revert all formule package revisions") || $account->hasPermission('administer formule package entities')));
    $delete_permission = (($account->hasPermission("delete all formule package revisions") || $account->hasPermission('administer formule package entities')));

    $rows = [];

    $vids = $formule_package_storage->revisionIds($formule_package);

    $latest_revision = TRUE;

    foreach (array_reverse($vids) as $vid) {
      /** @var \Drupal\oab_mp_product_formule_packages\Entity\FormulePackageInterface $revision */
      $revision = $formule_package_storage->loadRevision($vid);
        $username = [
          '#theme' => 'username',
          '#account' => $revision->getRevisionUser(),
        ];

        // Use revision link to link to revisions that are not active.
        $date = $this->dateFormatter->format($revision->getRevisionCreationTime(), 'short');
        if ($vid != $formule_package->getRevisionId()) {
          $link = Link::fromTextAndUrl($date, new Url('entity.formule_package.revision', [
            'formule_package' => $formule_package->id(),
            'formule_package_revision' => $vid,
          ]));
        }
        else {
          $link = $formule_package->toLink($date);
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
              'url' => Url::fromRoute('entity.formule_package.revision_revert', [
                'formule_package' => $formule_package->id(),
                'formule_package_revision' => $vid,
              ]),
            ];
          }

          if ($delete_permission) {
            $links['delete'] = [
              'title' => $this->t('Delete'),
              'url' => Url::fromRoute('entity.formule_package.revision_delete', [
                'formule_package' => $formule_package->id(),
                'formule_package_revision' => $vid,
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

    $build['formule_package_revisions_table'] = [
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
    ];

    return $build;
  }

}
