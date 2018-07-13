<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginInterface;
use Drupal\ckeditor\CKEditorPluginButtonsInterface;
use Drupal\Component\Plugin\PluginBase;
use Drupal\ckeditor\Annotation\CKEditorPlugin;
use Drupal\Core\Annotation\Translation;
use Drupal\editor\Entity\Editor;
/**
 * Defines the "embed" plugin.
 *
 * @CKEditorPlugin(
 *   id = "embed",
 *   label = @Translation("CKEditor Embed"),
 *   module = "ckeditor"
 * )
 */
class Embed extends PluginBase implements CKEditorPluginInterface, CKEditorPluginButtonsInterface
{
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getDependencies().
   */
  public function getDependencies(Editor $editor)
  {
    return array('embedbase', 'notification', 'notificationaggregator', 'toolbar', 'button');
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
    $plugin = drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/embed/plugin.js';
    return $plugin;
  }
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getConfig(Editor $editor)
  {
    return array();
  }

  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getConfig().
   */
  public function getButtons()
  {
    return array(
      'Embed' => array(
        'label' => t('Embed video'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/embed/icons/embed.png',
      ),
    );
  }
}