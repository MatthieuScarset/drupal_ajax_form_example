<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginInterface;
use Drupal\ckeditor\CKEditorPluginButtonsInterface;
use Drupal\Component\Plugin\PluginBase;
use Drupal\ckeditor\Annotation\CKEditorPlugin;
use Drupal\Core\Annotation\Translation;
use Drupal\editor\Entity\Editor;
/**
 * Defines the "Templating" plugin.
 *
 * @CKEditorPlugin(
 *   id = "templating",
 *   label = @Translation("Templating"),
 *   module = "ckeditor"
 * )
 */
class Templating extends PluginBase implements CKEditorPluginInterface, CKEditorPluginButtonsInterface
{
    /**
     * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getDependencies().
     */
    function getDependencies(Editor $editor)
    {
        return array();
    }
    /**
     * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getLibraries().
     */
    function getLibraries(Editor $editor)
    {
        return array();
    }
    /**
     * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::isInternal().
     */
    function isInternal()
    {
        return false;
    }
    /**
     * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getFile().
     */
    function getFile()
    {
        $plugin = drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/templating/plugin.js';
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
            'Templating' => array(
                'label' => t('Templating'),
                'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/templating/icons/templating.png',
            ),
        );
    }
}