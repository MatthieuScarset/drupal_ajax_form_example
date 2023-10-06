<?php

namespace Drupal\oab_styleguide\Controller;

use Drupal\Component\Serialization\Json;
use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Link;
use Drupal\Core\Url;
use Drupal\migrate_drupal\Plugin\migrate\source\ContentEntity;
use Drupal\user\Plugin\views\argument\Uid;
use Symfony\Component\DependencyInjection\ContainerInterface;

class OabStyleguideController extends ControllerBase {

  /**
   * The module extension list.
   *
   * @var \Drupal\Core\Extension\ModuleExtensionList
   */
  protected $moduleExtensionList;

  /**
   * The module handler service.
   *
   * @var \Drupal\Core\Extension\ModuleHandlerInterface
   */
  protected $moduleHandler;

  /**
   * The theme manager.
   *
   * @var \Drupal\Core\Theme\ThemeManagerInterface
   */
  protected $themeManager;

  /**
   * The theme registry used to render an output.
   *
   * @var \Drupal\Core\Theme\Registry
   */
  protected $themeRegistry;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    $instance = new static();
    $instance->moduleExtensionList = $container->get('extension.list.module');
    $instance->moduleHandler = $container->get('module_handler');
    $instance->themeManager = $container->get('theme.manager');
    $instance->themeRegistry = $container->get('theme.registry');
    return $instance;
  }

  /**
   * Get hook suggestions and preprocess functions for a given template hook.
   *
   * @return array
   *   The list of hooks.
   */
  protected function getTemplateInfo(string $hook, $variables): array {
    $theme_registry = $this->themeRegistry->getRuntime();
    $info = $theme_registry->get($hook);
    $base_theme_hook = $info['base hook'] ?? $hook;

    $suggestions = $this->moduleHandler->invokeAll('theme_suggestions_' . $base_theme_hook, [[
      'elements' => $variables
    ]]);

    return [
      'preprocess' => $info['preprocess functions'] ?? [],
      'templates' => $suggestions,
    ];
  }

  /**
   * Render modules from JSON data.
   *
   * @return array
   *   The content as render array.
   */
  public function renderModules(): array {
    $module_path = $this->moduleExtensionList->getPath('oab_styleguide');
    $filepath = "$module_path/artifacts/modules.json";
    if (!file_exists($filepath)) {
      return ['#markup' => $this->t('Error with data source.')];
    }

    try {
      $data = Json::decode(file_get_contents($filepath));
      if (empty($data)) {
        throw new \Exception("Empty data source");
      }
    } catch (\Exception $e) {
      return ['#markup' => $e->getMessage()];
    }

    $build = [];
    foreach ($data as $i => $object) {
      $entity_type_id = $object['type'] ?? NULL;
      $bundle = $object['bundle'] ?? $entity_type_id;
      $fields = $object['fields'] ?? [];
      $view_mode = $object['view_mode'] ?? 'full';
      $langcode = $object['langcode'] ?? 'fr';

      // Missing entity type. Stop now.
      if (!$entity_type_id) {
        continue;
      }

      // Generate entity.
      $storage = $this->entityTypeManager()->getStorage($entity_type_id);
      $entity_type = $storage->getEntityType();
      $values = [];
      if ($entity_type->hasKey('bundle')) {
        $values[$entity_type->getKey('bundle')] = $bundle;
      }

      /** @var \Drupal\Core\Entity\ContentEntityInterface $entity */
      $entity = $storage->create($values);
      if (!$entity instanceof ContentEntityInterface) {
        continue;
      }

      foreach ($fields as $field_name => $field_values) {
        if ($entity->hasField($field_name)) {
          $entity->set($field_name, $field_values);
        }
      }

      // Render entity.
      $label = $object['label'] ?? $entity_type->getSingularLabel() . ' - ' . $bundle;
      $build[$i] = [
        '#type' => 'details',
        '#title' => $label,
        '#open' => TRUE,
      ];

      $variables = $this->entityTypeManager()->getViewBuilder($entity_type_id)
        ->view($entity, $view_mode, $langcode);

      $build[$i]['content'] = $variables;

      // Developer info.
      $info = $this->getTemplateInfo($entity_type_id, $variables);
      $info_preprocess_items = [];
      foreach ($info['preprocess'] ?? [] as $name) {
        $info_preprocess_items[] = [
          '#prefix' => '<code>',
          '#markup' => $name . '()',
          '#suffix' => '</code>',
        ];
      }
      $info_suggestion_items = [];
      foreach ($info['templates'] ?? [] as $name) {
        $info_suggestion_items[] = [
          '#prefix' => '<code>',
          '#markup' => $name . '()',
          '#suffix' => '</code>',
        ];
      }

      $build[$i][] = [
        '#type' => 'details',
        '#title' => $this->t('Info for developers'),
        '#open' => TRUE,
        'preprocess' => [
          '#theme' => 'item_list',
          '#title' => $this->t('Preprocess functions'),
          '#items' => $info_preprocess_items,
        ],
        'suggestions' => [
          '#theme' => 'item_list',
          '#title' => $this->t('Template suggestions'),
          '#items' => $info_suggestion_items,
        ],
        '#attributes' => [
          'class' => ['oab-styleguide__info'],
        ]
      ];
    }

    // @todo Print Theme suggestion
    // @todo Print Twig
    // @todo Print Preprocess

    return $build;
  }

  /**
   * Present the styleguide page.
   *
   * @return array
   *   The content as render array.
   */
  public function styleguide(): array {
    $build = [];

    $build['intro'] = [
      '#type' => 'item',
      '#description' => $this->t('Read @link for a full list of components.', [
        '@link' => Link::fromTextAndUrl($this->t('read the documentation'), Url::fromUri(
          'https://boosted.orange.com/docs/4.3/getting-started/introduction/',
          ['attributes' => ['target' => '_blank']]
        ))->toString(),
      ]),
      '#description_display' => 'after',
    ];

    $build['modules'] = [
      '#type' => 'details',
      '#title' => $this->t('Modules'),
      '#open' => TRUE,
      '#attributes' => [
        'class' => ['oab-styleguide']
      ]
    ];

    $build['modules']['content'] = $this->renderModules();

    $build['#attached']['library'][] = 'oab_styleguide/styleguide';

    return $build;
  }
}
