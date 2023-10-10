<?php

namespace Drupal\oab_styleguide\Plugin\StyleguideElement;

use Drupal\Component\Utility\Html;
use Drupal\oab_styleguide\StyleguideElementPluginBase;
use Drupal\Tests\RandomGeneratorTrait;

/**
 * Plugin implementation of the styleguide_element.
 *
 * @StyleguideElement(
 *   id = "typography",
 *   label = @Translation("Typography"),
 *   description = @Translation("Common textual elements such as paragraph and headings.")
 * )
 */
class Typography extends StyleguideElementPluginBase {

  /**
   * {@inheritDoc}
   */
  public function render() {
    $build = [];

    foreach ($this->configuration['tags'] as $tag => $content) {
      if (empty($content)) {
        switch ($tag) {
          case 'h1':
          case 'h2':
          case 'h3':
          case 'h4':
          case 'h5':
          case 'h6':
            $content = $this->random->word(5) . ' ' . $this->random->word(3) . ' ' . $this->random->word(7);
            break;
          case 'p':
            $content = $this->random->paragraphs(3);
            break;
          default:
            $content = $this->random->sentences(3);
            break;
        }
      }

      $build[Html::getClass($tag)] = [
        '#type' => 'inline_template',
        '#template' => '<div><{{ tag }}>{{ content }}</{{ tag }}></div>',
        '#context' => [
          'tag' => $tag,
          'content' =>  $content,
        ]
      ];
    }

    return $build;
  }
}
