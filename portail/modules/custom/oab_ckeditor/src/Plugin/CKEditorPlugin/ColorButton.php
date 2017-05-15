<?php
namespace Drupal\oab_ckeditor\Plugin\CKEditorPlugin;
use Drupal\ckeditor\CKEditorPluginBase;
use Drupal\ckeditor\CKEditorPluginConfigurableInterface;
use Drupal\ckeditor\CKEditorPluginInterface;
use Drupal\Component\Plugin\PluginBase;
use Drupal\ckeditor\Annotation\CKEditorPlugin;
use Drupal\Core\Annotation\Translation;
use Drupal\Core\Form\FormStateInterface;
use Drupal\editor\Entity\Editor;
/**
 * Defines the "toolbar" plugin.
 *
 * @CKEditorPlugin(
 *   id = "colorbutton",
 *   label = @Translation("CKEditor ColorButton"),
 *   module = "ckeditor"
 * )
 */
class ColorButton extends CKEditorPluginBase implements CKEditorPluginConfigurableInterface
{
  /**
   * Implements \Drupal\ckeditor\Plugin\CKEditorPluginInterface::getDependencies().
   */
  function getDependencies(Editor $editor)
  {
    return array('panelbutton');
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
    $plugin = drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/colorbutton/plugin.js';
    return $plugin;
  }

  /**
   * {@inheritdoc}
   */
  public function getConfig(Editor $editor) {
    $settings = $editor->getSettings();

    // enableMore can only be supported if the Color Dialog plugin is present.
    $config = [
      'colorButton_enableMore' => false,
      'colorButton_enableAutomatic' => true,
    ];

    if (!empty($settings['plugins']['colorbutton']['colors'])) {
      $config['colorButton_colors'] = $settings['plugins']['colorbutton']['colors'];
    }

    return $config;
  }


  /**
   * {@inheritdoc}
   */
  public function getButtons() {
    return [
      'TextColor' => array(
        'label' => $this->t('Text Color'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/colorbutton/icons/textcolor.png',
      ),
      'BGColor' => array(
        'label' => $this->t('Background Color'),
        'image' => drupal_get_path('module', 'oab_ckeditor') . '/js/plugins/colorbutton/icons/bgcolor.png',
      ),
    ];
  }


  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state, Editor $editor) {
    $settings = $editor->getSettings();

    $form['colors'] = array(
      '#type' => 'textarea',
      '#title' => $this->t('Text Colors'),
      '#description' => $this->t('Enter the hex values of all colors you would like to support (without the # symbol) separated by a comma. Leave blank to use the default colors for Color Button.'),
      '#default_value' => !empty($settings['plugins']['colorbutton']['colors']) ? $settings['plugins']['colorbutton']['colors'] : '',
    );

    $form['colors']['#element_validate'][] = array($this, 'validateInput');
    return $form;
  }

  /**
   * Ensure values entered for color hex values contain no unsafe characters.
   * @param $element
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   */
  public function validateInput(array $element, FormStateInterface $form_state) {
    $input = $form_state->getValue(['editor', 'settings', 'plugins', 'colorbutton', 'colors']);

    if (preg_match('/([^A-Fa-z0-9,])/i', $input)) {
      $form_state->setError($element, 'Only valid hex values are allowed (A-F, 0-9). No other symbols or letters are allowed. Please check your settings and try again.');
    }
  }
}