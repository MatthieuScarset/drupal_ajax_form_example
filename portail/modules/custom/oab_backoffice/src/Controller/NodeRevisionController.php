<?php

namespace Drupal\oab_backoffice\Controller;

use Drupal\Component\Utility\Xss;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Datetime\DateFormatterInterface;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Render\RendererInterface;
use Drupal\Core\Url;
use Drupal\node\NodeTypeInterface;
use Drupal\node\NodeInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\node\Controller\NodeController;

/**
 * Returns responses for Node routes.
 */
class NodeRevisionController extends NodeController {

  /**
   * Generates an overview table of older revisions of a node.
   *
   * @param \Drupal\node\NodeInterface $node
   *   A node object.
   *
   * @return array
   *   An array as expected by drupal_render().
   */
  public function revisionOverview(NodeInterface $node) {
    $account = $this->currentUser();
    $langcode = $node->language()->getId();
    $langname = $node->language()->getName();
    $languages = $node->getTranslationLanguages();
    $has_translations = (count($languages) > 1);
    $node_storage = $this->entityManager()->getStorage('node');
    $type = $node->getType();

    $build['#title'] = $has_translations ? $this->t('@langname revisions for %title', ['@langname' => $langname, '%title' => $node->label()]) : $this->t('Revisions for %title', ['%title' => $node->label()]);
    $header = array($this->t('Revision'), $this->t('Workflow'), $this->t('Operations'));

    $revert_permission = (($account->hasPermission("revert $type revisions") || $account->hasPermission('revert all revisions') || $account->hasPermission('administer nodes')) && $node->access('update'));
    $delete_permission = (($account->hasPermission("delete $type revisions") || $account->hasPermission('delete all revisions') || $account->hasPermission('administer nodes')) && $node->access('delete'));

    $rows = array();

    $vids = $node_storage->revisionIds($node);

    $latest_revision = TRUE;

    foreach (array_reverse($vids) as $vid) {
      /** @var \Drupal\node\NodeInterface $revision */
      $revision = $node_storage->loadRevision($vid);
      // Only show revisions that are affected by the language that is being
      // displayed.
      if ($revision->hasTranslation($langcode) && $revision->getTranslation($langcode)->isRevisionTranslationAffected()) {
        $username = [
          '#theme' => 'username',
          '#account' => $revision->getRevisionAuthor(),
        ];

        // Use revision link to link to revisions that are not active.
        $date = $this->dateFormatter->format($revision->revision_timestamp->value, 'short');
        if ($vid != $node->getRevisionId()) {
          $link = $this->l($date, new Url('entity.node.revision', ['node' => $node->id(), 'node_revision' => $vid]));
        }
        else {
          $link = $node->link($date);
        }

        $row = [];
        $column = [
          'data' => [
            '#type' => 'inline_template',
            '#template' => '{% trans %}{{ date }} by {{ username }}{% endtrans %}{% if message %}<p class="revision-log">{{ message }}</p>{% endif %}',
            '#context' => [
              'date' => $link,
              'username' => $this->renderer->renderPlain($username),
              'message' => ['#markup' => $revision->revision_log->value, '#allowed_tags' => Xss::getHtmlTagList()],
            ],
          ],
        ];
        // @todo Simplify once https://www.drupal.org/node/2334319 lands.
        $this->renderer->addCacheableDependency($column['data'], $username);
        $row[] = $column;

        // workflow state
        $revision_state_value = $this->t('none');
        if ($revision_state = $revision->get('field_state')->getValue()) {
          if (isset($revision_state[0]['value'])) {
            $revision_state_machine = $revision_state[0]['value'];

            $config_factory = \Drupal::configFactory();
            $config = $config_factory->getEditable('workflow.state.' . $revision_state_machine);
            $revision_state_value = $this->t($config->get('label'));
          }
        }
        $row[] = [
          'data' => [
            '#markup' => $revision_state_value,
          ],
        ];

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
              'url' => $has_translations ?
                Url::fromRoute('node.revision_revert_translation_confirm', ['node' => $node->id(), 'node_revision' => $vid, 'langcode' => $langcode]) :
                Url::fromRoute('node.revision_revert_confirm', ['node' => $node->id(), 'node_revision' => $vid]),
            ];
          }

          if ($delete_permission) {
            $links['delete'] = [
              'title' => $this->t('Delete'),
              'url' => Url::fromRoute('node.revision_delete_confirm', ['node' => $node->id(), 'node_revision' => $vid]),
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
    }

    $build['node_revisions_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
      '#attached' => array(
        'library' => array('node/drupal.node.admin'),
      ),
    );

    return $build;
  }
}
