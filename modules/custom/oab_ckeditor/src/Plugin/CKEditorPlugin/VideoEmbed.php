<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginBase;
use Drupal\Core\Extension\ExtensionPathResolver;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\editor\Entity\Editor;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Defines the "VideoEmbed" plugin.
 *
 * @CKEditorPlugin(
 *   id = "videoembed",
 *   label = @Translation("VideoEmbed"),
 *   module = "ckeditor"
 * )
 */
class VideoEmbed extends CKEditorPluginBase implements ContainerFactoryPluginInterface
{

  /**
   * @var ExtensionPathResolver
   */
  private $pathResolver;

  public function __construct(array $configuration, $plugin_id, $plugin_definition, ExtensionPathResolver $extension_path_resolver) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->pathResolver = $extension_path_resolver;
  }

  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new self(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('extension.path.resolver')
    );
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getDependencies().
   */
  public function getDependencies(Editor $editor)
  {
    return array();
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getLibraries().
   */
  public function getLibraries(Editor $editor)
  {
    return array();
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::isInternal().
   */
  public function isInternal()
  {
    return false;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getFile().
   */
  public function getFile()
  {
    $plugin = $this->pathResolver->getPath('module', 'oab_ckeditor') . '/js/plugins/videoembed/plugin.js';
    return $plugin;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getConfig(Editor $editor)
  {
    $config = array();
    return $config;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getButtons()
  {
    return array(
      'VideoEmbed' => array(
        'label' => t('VideoEmbed button'),
        'image' => $this->pathResolver->getPath('module', 'oab_ckeditor') . '/js/plugins/videoembed/icons/videoembed.png',
      ),
    );
  }
}
