<?php

// Gestion de l'affichage des forms spécifiques aux subhomes via une fonction pour ne pas surcharger le .module


use Drupal\Core\Form\FormStateInterface;
use Drupal\taxonomy\Entity\Term;
use Drupal\views\ViewExecutable;


function subhomes_views_exposed_form(&$form) {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $num_select = 0;

    if (strpos($form['#id'], 'views-exposed-form-subhomes') !== false) {
      foreach ($form AS $key => $value) {
        if (isset($value['#type'])
          && $value['#type'] == "textfield") {
          $form[$key] = change_textfield_to_select($key, $key !== 'analyst');
        }
        elseif (isset($value['#type']) && $value['#type'] == "select") {

          if ($num_select >= 1) {
            $form['#info']["filter-field_subhome_target_id_".$num_select]["label"] = '';
          } else {
            $form['#info']["filter-field_subhome_target_id"]["label"] = '';
          }

          $form[$key]['#type'] = 'subhome_select_button';
          $properties = [
            "vid" => $key,
            "langcode" =>\Drupal::languageManager()->getCurrentLanguage()->getId()
          ];
          $form[$key]['#options'] = [];
          $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties($properties);
          if (is_array($terms)
            && !empty($terms)) {
            foreach ($terms AS $term) {
              $term_name = $term->getName();
              $form[$key]['#options'][$term->id()] = $term_name;
            }
          }
          $num_select++;
        }
      }

      if (isset($form['thematic'])) {
//        kint($form['thematic']); die();
//        kint($form['thematic']); die();
        $form['thematic']['#type'] = 'subhome_select_button';
        $properties = [
          "vid" => "thematic",
          "langcode" =>\Drupal::languageManager()->getCurrentLanguage()->getId()
        ];
        $form['thematic']['#options'] = [];
        $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadByProperties($properties);

        if (is_array($terms)
          && !empty($terms)) {
          foreach ($terms AS $term) {
            $term_name = $term->getName();
            $form['thematic']['#options'][$term->id()] = $term_name;
          }
        }
      }

      /**
       * je cache le bouton "Apply" s'il n'y a plus de filtre
       */
      $has_filters = false;
      foreach ($form["#info"] as $filter_name => $filter_infos) {
        if (isset($form[$filter_infos['value']])) {
          $has_filters = true;
        }
      }

      if (!$has_filters) {
        $form['actions']['submit']['#attributes']['class'][] = 'hidden';
      }
    }



  // Pour tous les contenus avec le filtre thématic/ field_insight
    if (isset($form['field_insight'])) {
        $form['field_insight']['#options'] = clean_exposed_filters_by_language(
            $form['field_insight']['#options'],
            'Thematic'
        );;
    }

    // subhome blogs
    if ($form['#id'] == 'views-exposed-form-subhomes-page-blog') {
        if (isset($form['blog_thematics'])) {
            $form['blog_thematics']['#options']['All'] = t('Thematic');
        }
        if (isset($form['blog_formats'])) {
            $form['blog_formats']['#options']['All'] = t('Type');
        }

        // HACK POUR LA SORTIE
        if ($current_language == 'en'
            || $current_language == 'ru') {
            unset($form['blog_formats']);
        }
    }

    // subhome magazine
    if ($form['#id'] == 'views-exposed-form-subhomes-page-magazine') {
        if (isset($form['magazine_thematics'])) {
            $form['magazine_thematics']['#options']['All'] = t('Thematic');
        }
        if (isset($form['magazine_types'])) {
            $form['magazine_types']['#options']['All'] = t('Type');
        }

        //Suppression ees filtres format, metier et industry pour la subhome RU
        if ($current_language == 'en'
            || $current_language == 'ru') {
            unset($form['magazine_types']);
        }
    }

    // subhome mediatheque
    if ($form['#id'] == 'views-exposed-form-subhomes-page-document') {
        if (isset($form['document_thematics'])) {
            $form['document_thematics']['#options']['All'] = t('Thematic');
        }
        if (isset($form['document_types'])) {
            $form['document_types']['#options']['All'] = t('Type');
        }

        if (isset($form['document_language'])) {
            $form['document_language']['#options']['All'] = t('Document language');
        }

        // HACK POUR LA SORTIE
        if ($current_language == 'fr') {
            // on supprime "eBook"
            unset($form['field_document_type_target_id']['#options']['E-book']);
        }
        if ($current_language == 'en') {
            // on supprime "position paper"
            unset($form['field_document_type_target_id']['#options']['Position paper']);
        } else {
            unset($form['document_language']);
        }

    }

    // subhome presse
    if ($form['#id'] == 'views-exposed-form-subhomes-page-press') {
        if (isset($form['field_solution_target_id'])) {
            $solutions = clean_exposed_filters_by_language(
                $form['field_solution_target_id']['#options'],
                'Solution'
            );
            $form['field_solution_target_id']['#options'] = $solutions;
        }

        //Suppression de filtres pour le russe
        if ($current_language == 'ru') {
            unset($form['press_formats']);
        }

        if (isset($form['created-max'])) {
          $form['created-max']['#type'] = "date";
          $form['created-max']['#size'] = "10";
        }

        if (isset($form['created-min'])) {
            $form['created-min']['#type'] = "date";
            $form['created-min']['#size'] = "10";
        }
    }

    // subhome produits
    if ($form['#id'] == 'views-exposed-form-subhomes-page-catalogue') {
        if (isset($form['solutions'])) {
            $form['solutions']['#options']['All'] = t('Solution');
        }
        if (isset($form['industries'])) {
            $form['industries']['#options']['All'] = t('Industry');
        }
        if (isset($form['jobs_profiles'])) {
            $form['jobs_profiles']['#options']['All'] = t('Profession');
        }

        //Suppression de filtres pour le russe
        if ($current_language == 'ru'
            || $current_language == 'en') {
            unset($form['industries']);
            unset($form['jobs_profiles']);
        }
        // HACK POUR LA SORTIE
        if ($current_language == 'fr') {
            // on supprime "ressources et énergie" et "transport"
            unset($form['industries']['#options']["ressources et énergie"]);
            unset($form['industries']['#options']["transport"]);
        }
    }

    // subhome temoignages
    if ($form['#id'] == 'views-exposed-form-subhomes-page-customer') {
        if (isset($form['solutions'])) {
            $form['solutions']['#options']['All'] = t('Solution');
        }
        if (isset($form['industries'])) {
            $form['industries']['#options']['All'] = t('Industry');
        }
        if (isset($form['jobs_profiles'])) {
            $form['jobs_profiles']['#options']['All'] = t('Profession');
        }

        // HACK POUR LA SORTIE
        if ($current_language == 'fr') {
            // on supprime "ressources et énergie" et "transport"
            unset($form['industries']['#options']["ressources et énergie"]);
            unset($form['industries']['#options']["transport"]);
        }
        if ($current_language == 'ru') {
            unset($form['industries']);
        }
    }

    // subhome partenaires
    if ($form['#id'] == 'views-exposed-form-subhomes-page-partners') {
        if (isset($form['solutions'])) {
            $form['solutions']['#options']['All'] = t('Solution');
        }
        if (isset($form['partners_types'])) {
            $form['partners_types']['#options']['All'] = t('Category');
        }
    }

    //Subhome Distributors
    if ($form['#id'] == 'views-exposed-form-subhomes-page-distributor') {
        // I don't know where the change is... I delete because it's the real field name
    }

    // Subhome Analysts
    if ($form['#id'] == 'views-exposed-form-subhomes-page-analysts') {
        // Nothing to do for the moment
        $form['solutions']['#options'] = clean_exposed_filters_by_language(
            $form['solutions']['#options'],
            t('Solution')->render()
        );

        //Je supprime les filtres regions et année en francais
        /*if ($current_language == 'fr') {
            unset($form['region']);
            unset($form['year']);
        } else { */
            // Regions
            if (!isset($form['region']) || !isset($form['region']['#options'])) {
                $form['region']['#options'] = array();
            }
            $form['region']['#options'] = clean_exposed_filters_by_language(
                $form['region']['#options'],
                t('Region')->render()
            );

            // Années
            $form['year']['#options'] = clean_exposed_filters_by_language(
                $form['year']['#options'],
                t('Year')->render()
            );
            // Analyst
            $form['analyst']['#options']['All'] = t('Analyst');

        //}
    }

    if ($form['#id'] == 'views-exposed-form-subhomes-archive-archive-press'
      || $form['#id'] == 'views-exposed-form-subhomes-archive-archive-news') {
        //$form['field_solution_target_id']['#options']['All'] = 'Solutions';

        if (isset($form['field_solution_target_id'])) {
          $form['field_solution_target_id']['#options'] = clean_exposed_filters_by_language(
            $form['field_solution_target_id']['#options'],
            'Solutions');
        }

        $form['node_year']['#options']['All'] = t('Year');
        $form['node_month']['#options']['All'] = t('Month');
    }

}
