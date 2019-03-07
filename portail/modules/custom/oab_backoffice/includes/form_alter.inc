<?php

/**
 * Fonction oab_backoffice_form_alter deplacée ici pour éviter de surcharger le fichier .module
 */


use Drupal\Core\Database\Database;
use \Drupal\oab_dvi\DviHelper;

function _in_hook_form_alter(&$form, $form_state, $form_id) {

    //\Drupal::logger('oab_backoffice')->notice('form id = '.$form_id);
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
    $languages = \Drupal::languageManager()->getLanguages();
    $current_user_language = Drupal::currentUser()->getPreferredLangcode();

    $edit_form = false;
    if (preg_match('@node_(.*)_edit_form@', $form_id)) {
        $current_user_language = $current_language;

        if ($node = \Drupal::routeMatch()->getParameter('node')) {
            $node_language = $node->language();
            $node_langcode = $node_language->getId();

            $current_user_language = $node_langcode;
        }
        $edit_form = true;
    }

    // formulaire replicate
    if (preg_match('@node_(.*)_replicate_form@', $form_id)) {
        $form['#attributes']['class'][] = "replicate-form";
    }

    // on checke les langues auxquelles l utilisateur a droit
    if (preg_match('@node_(.*)_edit_form@', $form_id) || preg_match('@node_(.*)_delete_form@', $form_id)) {
        $user = \Drupal::currentUser();
        $user_id = $user->id();
        if (!in_array('administrator', $user->getRoles())) {
            $node = \Drupal::routeMatch()->getParameter('node');
            $node_language = $node->language();
            $node_langcode = $node_language->getId();
            $connection = Database::getConnection();
            $sth = $connection->select('user__field_access_language', 'f')
                ->fields('f', array('field_access_language_target_id'))
                ->condition('f.entity_id', $user_id, '=');
            $data = $sth->execute();
            $results = $data->fetchAll(\PDO::FETCH_OBJ);
            $can_edit = false;
            if (count($results) != 0) {
                foreach ($results as $r) {
                    if ($r->field_access_language_target_id == $node_langcode) {
                        $can_edit = true;
                        break;
                    }
                }
            }
            if ($can_edit !== true) {
                drupal_set_message(t('You can not edit/delete this node cause you don\'t have access to this language.'), 'error', TRUE);
                $response = new Symfony\Component\HttpFoundation\RedirectResponse('/admin/content');
                $response->send();
                exit();
            }
        }
    }



    // page de liste des taxonomies
    if ($form_id == 'taxonomy_overview_terms') {
        if (isset($form['terms'])) {
            foreach ($form['terms'] AS $key => $value) {
                if (preg_match('@^tid:@', $key)) {
                    if (isset($form['terms'][$key]['term']['#title'])
                        && isset($form['terms'][$key]['#term'])
                        && is_object($form['terms'][$key]['#term'])) {
                        $term_language = $form['terms'][$key]['#term']->language()->getId();
                        $form['terms'][$key]['term']['#title'] .= ' (' . strtoupper($term_language) . ')';
                    }
                }
            }
        }
    }

    // filtres exposés de views
    if ($form_id == 'views_exposed_form') {
        if ($form['#id'] == 'views-exposed-form-medias-entity-browser-entity-browser-media') {
            $form['field_tags_target_id']['#size'] = 30;
        }
    }

    if ($form_id == 'node_profile_form'
        || $form_id == 'node_profile_edit_form') {
        $form['field_social_accounts']['#cardinality_multiple'] = false;

        if (isset($form['field_social_accounts']['widget'])
            && is_array($form['field_social_accounts']['widget'])) {
            $form['field_social_accounts']['widget']['#cardinality_multiple'] = false;

            foreach ($form['field_social_accounts']['widget'] AS $key => &$value) {
                if (isset($value['value']['#title'])) {
                    switch ($key) {
                        case '0':
                            $value['value']['#title'] = t('Twitter account');
                            break;
                        case '1':
                            $value['value']['#title'] = t('LinkedIn account');
                            break;
                        case '2':
                            $value['value']['#title'] = t('Viadeo account');
                            break;
                        case '3':
                            $value['value']['#title'] = t('Google + account');
                            break;
                    }
                    $value['value']['#title_display'] = 'before';
                }
                if (isset($value['_weight'])) {
                    $value['_weight']['#access'] = false;
                }
            }
        }
    }


    if (in_array($form_id, array('node_blog_post_form', 'node_blog_post_edit_form',
        'node_customer_story_form', 'node_customer_story_edit_form',
        'node_document_form', 'node_document_edit_form',
        'node_magazine_form', 'node_magazine_edit_form',
        'node_press_kit_form', 'node_press_kit_edit_form',
        'node_press_release_form', 'node_press_release_edit_form',
        'node_industry_form', 'node_industry_edit_form',
        'node_solution_form', 'node_solution_edit_form',
        'node_product_form', 'node_product_edit_form',
        'node_partner_form', 'node_partner_edit_form',
        'node_region_form', 'node_region_edit_form',
        'node_simple_page_form', 'node_simple_page_edit_form',
        'node_country_form', 'node_country_edit_form',
        'node_full_html_form', 'node_full_html_edit_form',
        'node_distributor_form', 'node_distributor_edit_form'))) {

        $form['#attached']['library'][] = 'oab_backoffice/metadata';

        // positionnement des champs dates
        if (isset($form['field_start_date'])
            && isset($form['field_end_date'])
        ) {
            $form['field_start_date']['#attributes']['style'] = 'float: left; margin-right: 30px;';
            $form['field_end_date']['#attributes']['style'] = 'float: left; margin-right: 30px;';
        }

        // disposition des taxonomies
        if (isset($form['#fieldgroups']['group_classer'])) {
            foreach ($form['#fieldgroups']['group_classer']->children AS $field) {
                if (isset($form[$field])) {
                    $form[$field]['#attributes']['style'] = "float: left; margin-right: 50px;";
                    $form[$field]['widget']['#size'] = 15;
                }
            }
        }

        if (isset($form['#fieldgroups']['group_taxonomie']->children)) {
            $last_taxonomie = end($form['#fieldgroups']['group_taxonomie']->children);
            $form[$last_taxonomie]['#suffix'] = '<div class="clearfix"></div>';
        }

        // Disable browser HTML5 validation
        $form['#attributes']['novalidate'] = 'novalidate';

        //on cache la partie avancée metatags pour les utilisateurs sauf digital admin et admin
        $roles = \Drupal::currentUser()->getRoles();
        if (!in_array("administrator", $roles) && !in_array("digital_admin", $roles)) {
            $form['field_metatags']['#access'] = false;
        }

        // Spécific Document : je cache la langue du document pour les contenus qui sont pas en Anglais
        if (isset($form['field_document_language'])) {
            if ($current_language !== "en") {
                unset($form['field_document_language']);
            }
        }

    }


    // Ajout de champ dans les menus
    if ($form_id == 'menu_link_content_menu_link_content_form') {
        $menu_link_entity = _oab_backoffice_get_menu_link_entity_from_form_state($form_state);
        $link_options = $menu_link_entity->link->first()->options;
        $link_target = !empty($link_options['target']) ? true : false;
        $link_icon = !empty($link_options['icon']) ? $link_options['icon']: array();
        $link_classtag = !empty($link_options['classtag']) ? $link_options['classtag']: array();

        $form['link_target'] = array(
            '#type' => 'checkbox',
            '#title' => t('Open in a new window'),
            '#description' => t('check to open the link in a new window'),
            '#default_value' => $link_target,
            '#weight' => -2
        );

        $form['link_icon'] = array(
            '#type' => 'textfield',
            '#title' => t('Font Awesome Icon'),
            '#description' => t('type your icon class code'),
            '#default_value' => $link_icon,
            '#weight' => -3
        );

        $form['link_classtag'] = array(
            '#type' => 'textfield',
            '#title' => t('Link Tag Class'),
            '#description' => t('type your link tag class'),
            '#default_value' => $link_classtag,
            '#weight' => -4
        );

        $form['actions']['submit']['#submit'][] = 'oab_backoffice_menu_link_submit';
    }

    // langue RU pour les webforms
    if (preg_match('@webform_submission_(.*)_form@', $form_id) && $current_language == 'ru') {
        $form['elements']['actions']['#submit__label'] = 'Отправить';
    }


    //preselection des departements et segments de marché sur les PARTNERS
    if (in_array($form_id, array('node_partner_form'))) {
        if (isset($form['field_departments'])) {
            //par défaut on sélectionne tous les départements
            $form['field_departments']['widget']['#default_value']  = array_keys($form['field_departments']['widget']['#options']);
        }
        if (isset($form['field_market_segment'])) {
            //par défaut on sélectionne +50 et +250 salariés
            $default_label = array();
            $default_values = array();
            if ($current_language == "fr") {
                $default_label = array('+ 50 salariés', '+ 250 salariés');
            }
            elseif ($current_language == "en") {
                $default_label = array('+ 50 employees', '+ 250 employees');
            }
            if (!empty($default_label)) {
                foreach ($default_label as $label) {
                    $query = \Drupal::entityQuery('taxonomy_term');
                    $query->condition('vid', 'market_segments');
                    $query->condition('name', $label);
                    $entity = $query->execute();

                    if (!empty($entity)) {
                        $default_values[] = array_pop($entity);
                    }
                }
                if (!empty($default_values)) {
                    $form['field_market_segment']['widget']['#default_value']  = $default_values;
                }
            }
        }
    }

    ######## Gestion des produits DVI
    if ($form_id === "node_product_form" || $form_id === "node_product_edit_form") {
        ##A la creation d'un produit, je rajoute une fonction de vérification
        ## pour ajouter des verifications spécifiques en fonction du choix de l'user
        $form["#validate"][] = 'oab_backoffice_check_dvi_product_form_validate';
        $langcode = $language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        if ($langcode !== "en"  && $langcode != "fr" &&
            isset($form[DviHelper::FIELD_IS_DVI_PRODUCT_NAME])) {
            $form[DviHelper::FIELD_IS_DVI_PRODUCT_NAME]['widget']['#type'] = "hidden";
        }
    }


    /**
     * Pour les formulaires "contact_commercial", on ajoute le titre du produit de la page
     * sur laquelle on a cliqué sur le bouton pour accèder à ce formulaire
     */
    if (isset($form["#webform_id"]) && $form["#webform_id"] == "contact_commercial"
        && $current_language == "fr") {

        ##On recupère l'URL d'origine
        $url = $_SERVER['HTTP_REFERER'];
        if ($url !== null) {

            ##On recupère l'alias
            $path = preg_replace('/\//', '', parse_url($url, PHP_URL_PATH), 1);
            $path = str_replace($current_language, '', $path);

            ##On recupère le /node/xxx depuis l'alias
            $org_path = \Drupal::service('path.alias_manager')
                ->getPathByAlias("$path");

            ##On recupère le nid qui est dans l'url
            if (preg_match('/node\/(\d+)/', $org_path, $matches)) {

                ##on load le noad
                $node = \Drupal\node\Entity\Node::load($matches[1]);
                if ($node !== null && $node->getType() == "product") {
                    ##On set enfin la value, seulement pour les produits
                    $form['elements']['origin_product_name']['#value'] = $node->getTitle();
                }
            }
        }
    }


    if (in_array($form_id, array('node_blog_post_form', 'node_blog_post_edit_form',
        'node_customer_story_form', 'node_customer_story_edit_form',
        'node_custom_page_form', 'node_custom_page_edit_form',
        'node_document_form', 'node_document_edit_form',
        'node_full_html_form', 'node_full_html_edit_form',
        'node_homepage_form', 'node_homepage_edit_form',
        'node_magazine_form', 'node_magazine_edit_form',
        'node_industry_form', 'node_industry_edit_form',
        'node_product_form', 'node_product_edit_form',
        'node_profile_form', 'node_profile_edit_form',
        'node_simple_page_form', 'node_simple_page_edit_form',
        'node_solution_form', 'node_solution_edit_form'))) {

        $user_roles = \Drupal::currentUser()->getRoles();

        if (count($user_roles)==2 &&
            isset($user_roles[0]) && $user_roles[0] == "authenticated" &&
            isset($user_roles[1]) && $user_roles[1] == "chief_editor_hub") {
            //rend le champ obligatoire
            $form["field_hub"]["widget"]["#required"] = true;
            $form["field_hub_portal"]['#disabled'] = true;

        }
    }

}
