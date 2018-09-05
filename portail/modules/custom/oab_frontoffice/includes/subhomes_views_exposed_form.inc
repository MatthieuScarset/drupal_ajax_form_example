<?php

// Gestion de l'affichage des forms spécifiques aux subhomes via une fonction pour ne pas surcharger le .module


function subhomes_views_exposed_form(&$form) {
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();


    if (strpos($form['#id'], 'views-exposed-form-subhomes') !== false) {
        foreach ($form AS $key => $value) {
            if (isset($value['#type'])
                && $value['#type'] == "textfield") {
                $vocabulary = \Drupal\taxonomy\Entity\Vocabulary::load($key);
                if (is_object($vocabulary)) {
                    $terms = \Drupal::entityManager()->getStorage('taxonomy_term')->loadByProperties([
                        'vid' => $key,
                        'langcode' => $current_language
                    ]);
                    if (is_array($terms)
                        && !empty($terms)) {
                        $options = array('All' => t($vocabulary->get('name')));
                        foreach ($terms AS $term) {
                            $term_name = $term->getName();
                            $options[$term_name] = $term_name;
                        }
                        $form[$key]['#type'] = "select";
                        $form[$key]['#options'] = $options;
                        $form[$key]['#default_value'] = 'All';
                        $form[$key]['#validated'] = TRUE;
                        $form[$key]['#size'] = null;
                    }
                    else{
                        unset($form[$key]);
                    }
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

        // HACK POUR LA SORTIE
        if ($current_language == 'fr') {
            // on supprime "eBook"
            unset($form['field_document_type_target_id']['#options']['E-book']);
        }
        if ($current_language == 'en') {
            // on supprime "position paper"
            unset($form['field_document_type_target_id']['#options']['Position paper']);
        }
    }

    // subhome presse
    if ($form['#id'] == 'views-exposed-form-subhomes-page-press') {
        if (isset($form['solutions'])) {
            $form['solutions']['#options']['All'] = t('Solution');
        }
        if (isset($form['press_formats'])) {
            $form['press_formats']['#options']['All'] = t('Type');
        }

        //Suppression de filtres pour le russe
        if ($current_language == 'ru') {
            unset($form['press_formats']);
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
        $solutions = clean_exposed_filters_by_language(
            $form['field_solution_target_id']['#options'],
            'Solution'
        );
        $form['field_solution_target_id']['#options'] = $solutions;

        $departements = clean_exposed_filters_by_language(
            $form['field_departments_target_id']['#options'],
            'Departements'
        );
        $form['field_departments_target_id']['#options'] = $departements;

    }

    // Subhome Analysts
    if ($form['#id'] == 'views-exposed-form-subhomes-page-analysts') {
        // Nothing to do for the moment
        $form['solutions']['#options'] = clean_exposed_filters_by_language(
            $form['solutions']['#options'],
            t('Solution')->render()
        );

        //Je supprime les filtres regions et année en francais
        if ($current_language == 'fr') {
            unset($form['region']);
            unset($form['year']);
        } else {
            // Regions
            $form['region']['#options'] = clean_exposed_filters_by_language(
                $form['region']['#options'],
                t('Region')->render()
            );

            // Années
            $form['year']['#options'] = clean_exposed_filters_by_language(
                $form['year']['#options'],
                t('Year')->render()
            );
        }
    }
}