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
    //gestion de la liste des options selon le type de contenu choisi (taxo type)
    $options = array();
    if(isset($_GET['content_type_tid'])) // on vérifie que le paramètre a été passé dans l'url (id du terme permettant de différencier les types)
    {
      $tid = $_GET['content_type_tid'];
      //on charge le terme concerné
      $term = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->load($tid);
      //on vérifie que le machine_name a bien été renseigné
      if(isset($term->field_nom_machine) && !empty($term->field_nom_machine->value))
      {
        //définition des zones selon la taxo "type de contenu"
        switch ($term->field_nom_machine->value)
        {
          case 'magazine' :
            $options = array('Entete', 'Haut 1', 'Haut 2', 'Haut 3', 'Milieu', 'Bas');
            break;
          case 'blog_post' :
            $options = array('Entete', 'Haut gauche', 'Haut droit', 'Milieu', 'Bas 1', 'Bas 2', 'Bas 3');
            break;
        }
      }
    }


    $element['zone'] = array(
      '#type' => 'select',
      '#title' => t('Zone'),
      '#default_value' => $items[$delta]->zone,
      '#options' => $options,
      '#weight' => 10,
    );

    return $element;
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
