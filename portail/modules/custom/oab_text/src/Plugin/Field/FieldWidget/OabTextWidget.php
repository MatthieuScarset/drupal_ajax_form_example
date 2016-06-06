<?php

namespace Drupal\oab_text\Plugin\Field\FieldWidget;

use Drupal\Core\Form\FormStateInterface;
use Drupal\text\Plugin\Field\FieldWidget\TextareaWidget;
use Symfony\Component\Validator\ConstraintViolationInterface;
use Drupal\Core\Field\FieldItemListInterface;

/**
 * Plugin implementation of the 'text_textfield' widget.
 *
 * @FieldWidget(
 *   id = "oab_text_textfield",
 *   label = @Translation("Oab Text field"),
 *   field_types = {
 *     "oab_text"
 *   },
 * )
 */
class OabTextWidget extends TextareaWidget {

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return array(
      'rows' => '9',
      'placeholder' => '',
    ) + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $element = parent::settingsForm($form, $form_state);

    return $element;
  }

  /**
   * {@inheritdoc}
   */
  function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    $element = parent::formElement($items, $delta, $element, $form, $form_state);

    //RUBYPORTAILOBS-2431
    //gestion de la liste des options selon le type de contenu choisi
    $options = array();
    if(isset($_GET['rendering_model_tid'])) // on vérifie que le paramètre a été passé dans l'url (id du terme permettant de différencier les types)
    {
      $tid = $_GET['rendering_model_tid'];
    }
    else
    {
      if ($node = \Drupal::routeMatch()->getParameter('node')) {
        $nid = $node->nid->value;
        $type = $node->field_rendering_model->getValue();
        if(isset($type[0]['target_id']) && !empty($type[0]['target_id']))
        {
          $tid = $type[0]['target_id'];
        }
      }
    }
    if(isset($tid) && !empty($tid)) {
      //on charge le terme concerné
      $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($tid);
      //on vérifie que le machine_name a bien été renseigné
      if (isset($term->field_machine_name) && !empty($term->field_machine_name->value)) {
        $options = $this->getOptionsForContentTypeTerm($term->field_machine_name->value);
      }
      else{
        $options = array('default' => 'Default');
      }
    }

    $element['zone'] = array(
      '#type' => 'select',
      '#title' => t('display area for content above'),
      '#default_value' => $items[$delta]->zone,
      '#options' => $options,
      '#weight' => 10,
    );

    return $element;
  }

  private function getOptionsForContentTypeTerm($machine_name)
  {
    //définition des zones selon la taxo "type de contenu"
    $options = array();
    switch ($machine_name)
    {
      case 'magazine' :
        $options = array('default' => 'Default', 'entete' => 'Entete', "haut1"=> 'Haut 1', "haut2"=> 'Haut 2', "haut3"=> 'Haut 3', "milieu"=> 'Milieu', "bas"=> 'Bas');
        break;
      case 'blog_post' :
        $options = array('default' => 'Default', 'entete' => 'Entete', "hautgauche"=>'Haut gauche', "hautdroit"=>'Haut droit', 'milieu' => 'Milieu', 'bas1' => 'Bas 1', 'bas2' => 'Bas 2', 'bas3' => 'Bas 3');
        break;
      default:
        $options = array('default' => 'Default');
    }
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function errorElement(array $element, ConstraintViolationInterface $violation, array $form, FormStateInterface $form_state) {
    $element = parent::errorElement($element, $violation, $form, $form_state);
    if ($element === FALSE) {
      return FALSE;
    }
    elseif (isset($violation->arrayPropertyPath[0])) {
      return $element[$violation->arrayPropertyPath[0]];
    }
    else {
      return $element;
    }
  }

}
