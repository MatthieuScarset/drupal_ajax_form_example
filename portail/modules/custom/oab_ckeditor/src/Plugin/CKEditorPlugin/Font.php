<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginBase;
use Drupal\editor\Entity\Editor;
/**
 * Defines the "Font" plugin.
 *
 * @CKEditorPlugin(
 *   id = "font",
 *   label = @Translation("Font"),
 *   module = "ckeditor"
 * )
 */
class Font extends CKEditorPluginBase
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
    $plugin = drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/font/plugin.js';
    return $plugin;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getConfig(Editor $editor)
  {
    $config = array();
    $config['fontSize_sizes'] = '8/.8rem;9/.9rem;10/1rem;11/1.1rem;12/1.2rem;13/1.3rem;14/1.4rem;16/1.6rem;18/1.8rem;20/2rem;24/2.4rem;28/2.8rem;30/3rem;36/3.6rem;40/4rem;46/4.6rem;60/6rem';
    return $config;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getButtons()
  {
    return array(
      'Font' => array(
        'label' => t('Font button'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/font/icons/font.png',
      ),
      'FontSize' => array(
        'label' => t('Font size button'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/font/icons/fontsize.png',
      ),
    );
  }
}