<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginBase;
use Drupal\editor\Entity\Editor;
/**
 * Defines the "LineHeight" plugin.
 *
 * @CKEditorPlugin(
 *   id = "lineheight",
 *   label = @Translation("LineHeight"),
 *   module = "ckeditor"
 * )
 */
class LineHeight extends CKEditorPluginBase
{
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getDependencies().
   */
  public function getDependencies(Editor $editor)
  {
    return array("richcombo");
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
    $plugin = drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/lineheight/plugin.js';
    return $plugin;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getConfig(Editor $editor)
  {
    $config = array();
    $config['line_height'] = '0;1rem;2rem;3rem;4rem;5rem';
    return $config;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getButtons()
  {
    return array(
      'lineheight' => array(
        'label' => t('LineHeight button'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/lineheight/icons/icon.png',
      ),
    );
  }
}