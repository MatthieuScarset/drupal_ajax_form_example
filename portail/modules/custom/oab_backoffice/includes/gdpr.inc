<?php

/**
 * Regroupement de toutes les fonctions spécifiques à la GDPR pour ne pas surcharger le fichier .module
 */

use Drupal\Core\Datetime;


function gdpr_is_webform_submission_authorized(Drupal\webform\Entity\WebformSubmission $entity, $operation, \Drupal\Core\Session\AccountInterface $account) {

    if ($operation == "delete" && in_array('webform_business_analyst', $account->getRoles())) {

        $webform = $entity->getWebform();
        $business_analaysts_list = $webform->getThirdPartySetting('oab_gdpr', 'gdpr_business_analysts');

        if (array_key_exists($account->id(), $business_analaysts_list)) {

            return Drupal\Core\Access\AccessResult::allowed();
        }
    }
    return Drupal\Core\Access\AccessResult::neutral();
}

/**
 * Je regroupe tout dans une fonction perso, parce que je m'en sers dans plusieurs hook_access
 */
function gdpr_is_webform_authorized(Drupal\webform\Entity\Webform $entity, $operation, \Drupal\Core\Session\AccountInterface $account) {
    /**
     * Si l'utilisateur est un business owner, je lui donne les droits que sur les webforms auxquels il est business owner
     * pour voir les soumissions et faire des modifs
     */

    if (in_array('webform_business_owner', $account->getRoles())) {
        $form_bo = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner'));
        if (($operation == "submission_view_any" || $operation == "update")
            && $form_bo !== null
            && $form_bo->id() == $account->id()) {
            return Drupal\Core\Access\AccessResult::allowed();
        }
    }

    ##Pour l'accès aux données et à leur telechargement
    if ($operation == "submission_view_any" && in_array('webform_business_analyst', $account->getRoles())) {
        ##Je recupère la liste des business analysts du formulaire pour checker que les utilisateurs en font partis
        $business_analaysts_list = $entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_analysts');

        if (array_key_exists($account->id(), $business_analaysts_list)) {

            return Drupal\Core\Access\AccessResult::allowed();
        }

    }

    ## Submission page => page d'affichage du formulaire
    if ($operation == "submission_page" || $operation == "view") {

        $allowed = gdpr_check_authorized_view($entity, $account);
        if ($allowed) {
            return Drupal\Core\Access\AccessResult::allowed();
        } elseif ($allowed == false) {
            return Drupal\Core\Access\AccessResult::forbidden();
        } elseif ($allowed == null) {
            return Drupal\Core\Access\AccessResult::neutral();
        }
    }

    /* A garder pour afficher toutes les permissions des webforms
     * if (in_array('webform_manager', $account->getRoles())) {
        echo $entity->label() . " => " . $operation . " <br /> ";
    }*/


    return Drupal\Core\Access\AccessResult::neutral();
}


function gdpr_check_authorized_view($entity, $account) {
    $ret = false;
    $is_published = $entity->getThirdPartySetting('oab_gdpr', 'gdpr_form_published');

    // Petit hack pour les contenus qui n'ont pas encore leurs réglages GDPR
    if ($is_published === null) {
        return true;
    }

    //echo "is published : $is_published"; die();
    ##Je fais les accès au formulaire en spécifique si le formulaire n'est pas publié
    if ($is_published != 1) {

        ## Si c'est un webform admin ou si c'est l'administrateur
        if (in_array('webform_admin', $account->getRoles())
            || $account->id() == 1) {
            $ret = true;
        }

        ## S'il est business owner, il doit être le BO du form pour le voir
        if (in_array('webform_business_owner', $account->getRoles())
            && $entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner') == $account->id()
        ) {
            $ret = true;
        }


        ## S'il est SPOC Securité, il doit être le SPOC du form pour le voir
        if (in_array('webform_spoc_securite', $account->getRoles())
            && $entity->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security') == $account->id()
        ) {
            $ret = true;
        }


        ## S'il est webform manager, il doit etre le "owner" du form pour le voir
        if (in_array('webform_manager', $account->getRoles())
            && $entity->getOwnerId() == $account->id()
        ) {
            $ret = true;
        }

        # Si aucune condition n'est remplie, on interdit l'accès au webform
        return $ret;
    } else {
        // SI le webform est publié, on return true;

        return true;
    }

}

/**
 * Gestion des accès spécifiques aux webform
 */
function gdpr_hook_node_acces(Drupal\node\Entity\Node $entity, $operation, \Drupal\Core\Session\AccountInterface $account) {
    if ($entity->getType() == 'webform' && $operation == 'view') {
        if ($entity->get('webform')->count() > 0) {
            $webform_value = $entity->get('webform')->first()->getValue();
            $webform_machine_name = $webform_value['target_id'];
            $webform_entity = \Drupal::entityTypeManager()->getStorage('webform')->load($webform_machine_name);
            if ($webform_entity != null && $webform_entity instanceof Drupal\webform\Entity\Webform) {
                return gdpr_is_webform_authorized($webform_entity, $operation, $account);
            }
        }

    }

    return Drupal\Core\Access\AccessResult::neutral();
}

/**
 * Set-up des emails à leur envoie
 */
function gdpr_hook_mail($key, &$message, $params) {
    $token_service = \Drupal::token();
    $config = \Drupal::config('oab.gdpr_settings');

    switch ($key) {
        case 'gdpr_spoc_notice':
            $message['subject'] = $token_service->replace($config->get('mail_spoc_object'), ['webform' => $params['webform']]);
            $message['body'][] = $token_service->replace($config->get('mail_spoc_body'), ['webform' => $params['webform']]);
            break;
        case 'gdpr_creator_notice':
            $message['subject'] = $token_service->replace($config->get('mail_creator_object'), ['webform' => $params['webform']]);
            $message['body'][] = $token_service->replace($config->get('mail_creator_body'), ['webform' => $params['webform']]);
            break;
        case 'gdpr_business_owner_notice':
            $message['subject'] = $token_service->replace($config->get('mail_business_owner_object'), ['webform' => $params['webform']]);
            $message['body'][] = $token_service->replace($config->get('mail_business_owner_body'), ['webform' => $params['webform']]);
            break;
        case 'gdpr_publish_notice':
            $message['subject']  = $token_service->replace($config->get('mail_validation_object'), ['webform' => $params['webform']]);
            $message['body'][]  = $token_service->replace($config->get('mail_validation_body'), ['webform' => $params['webform']]);
            break;
    }
}



/**
 * Création des tokens spécifiques à la GDPR
 */
function gdpr_hook_token_info() {
    $types = array(
        'name' => t('GDPR tokens'),
        'description' => t('Token designed for webform mails')
    );
    $tokens['business-owner-mail'] = array(
        'name' => t('Business owner mail'),
        'description' => t('Business owner mail')
    );
    $tokens['creator-pseudo'] = array(
        'name' => t('Creator pseudo'),
        'description' => t('Creator pseudo')
    );
    $tokens['creator-mail'] = array(
        'name' => t('Creator mail'),
        'description' => t('Creator mail')
    );
    $tokens['form-title'] = array(
        'name' => t('Form title'),
        'description' => t('Form title')
    );
    $tokens['form-expiration-date'] = array(
        'name' => t('Form expiration date'),
        'description' => t('Form expiration date')
    );
    $tokens['form-id'] = array(
        'name' => t('Webform machine name'),
        'description' => t('Machine name of the webform')
    );
    $tokens['spoc-pseudo'] = array(
        'name' => t('Spoc security pseudo'),
        'description' => t('Spoc security pseudo')
    );
    $tokens['spoc-mail'] = array(
        'name' => t('Spoc security mail'),
        'description' => t('Spoc security mail')
    );


    return array(
        'types' => $types,
        'tokens' => $tokens
    );
}

/**
 * Gestion des remplacements des tokens pour la GDPR
 */
function gdpr_hook_tokens(array &$replacements, $type, $tokens, array $data) {
    if (isset($data['webform']) && $type == 'gdpr') {
        $webform = $data['webform'];
        foreach ($tokens as $name => $original) {
            switch ($name) {
                case 'business-owner-mail':
                    $business_owner = \Drupal\user\Entity\User::load($webform->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner'));
                    if ($business_owner !== null) {
                        $replacements[$original] = $business_owner->getEmail();
                    } else {
                        drupal_set_message(t("Le Business Owner n'a pas pu etre trouvé"), 'error', true);
                    }
                    break;
                case 'creator-pseudo':
                    $replacements[$original] = $webform->getOwner()->getDisplayName();
                    break;
                case 'creator-mail':
                    $replacements[$original] = $webform->getOwner()->getEmail();
                    break;
                case 'form-title':
                    $replacements[$original] = $webform->get('title');
                    break;
                case 'form-expiration-date':
                    $date = new \DateTime($webform->getThirdPartySetting('oab_gdpr', 'gdpr_expiration_date'));
                    $replacements[$original] = $date->format('d/m/Y');
                    break;
                case 'data-delete-date':
                    $date = new \DateTime($webform->getThirdPartySetting('oab_gdpr', 'gdpr_data_delete_date'));
                    $replacements[$original] = $date->format('d/m/Y');
                    break;
                case 'form-id':
                    $replacements[$original] = $webform->id();
                    break;
                case 'spoc-pseudo':
                    $spoc = \Drupal\user\Entity\User::load($webform->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security'));
                    if ($spoc !== null) {
                        $replacements[$original] = $spoc->label();
                    } else {
                        drupal_set_message(t("Le SPOC Securité n'a pas pu etre trouvé"), 'error', true);
                    }
                    break;
                case 'spoc-mail':
                    $spoc = \Drupal\user\Entity\User::load($webform->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security'));
                    if ($spoc !== null) {
                        $replacements[$original] = $spoc->getEmail();
                    } else {
                        drupal_set_message(t("Le SPOC Securité n'a pas pu etre trouvé"), 'error', true);
                    }
                    break;
                case 'delete-data-date':
                    $date = new \DateTime($webform->getThirdPartySetting('oab_gdpr', 'gdpr_delete_data_date'));
                    $replacements[$original] = $date->format('d/m/Y');
                    break;
            }
        }
    }

}

/**
 * A la creation d'un webform, on envoie des emails
 */
function gdpr_hook_webform_insert(Drupal\webform\Entity\Webform $entity) {
    $current_user = Drupal::currentUser();
    $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

    #mail to SPOC Security
    $spoc_security = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security'));
    if ($spoc_security !== null) {
        \Drupal::service('plugin.manager.mail')
            ->mail('oab_backoffice', 'gdpr_spoc_notice', $spoc_security->getEmail(), $current_language, array('webform'=> $entity));
    } else {
        drupal_set_message(t("L'email au SPOC Securité n'a pas pu être envoyé"), 'error', true);
    }

    # mail au createur du webform
    $mail_creator = $current_user->getEmail();
    \Drupal::service('plugin.manager.mail')
        ->mail('oab_backoffice', 'gdpr_creator_notice', $mail_creator, $current_language, array('webform'=> $entity));

    # mail au business owner
    $business_owner = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner'));
    if ($business_owner !== null) {
        $mail_business_owner = $business_owner->getEmail();
        \Drupal::service('plugin.manager.mail')
            ->mail('oab_backoffice', 'gdpr_business_owner_notice', $mail_business_owner, $current_language, array('webform'=> $entity));
    } else {
        drupal_set_message(t("L'email au Business Owner n'a pas pu être envoyé"), 'error', true);
    }

}

/**
 * Liste des utilisateurs ayant le role Business Analyst
 */
function gdpr_business_analysts_list() {
    $query = \Drupal::database()->select('users', 'u');
    $query->fields('u', array('uid'));
    $query->innerJoin('user__roles', 'r', 'r.entity_id = u.uid');
    $query->join('users_field_data', 'd', 'u.uid = d.uid');
    $query->condition('r.roles_target_id', 'webform_business_analyst');
    $query->fields('d', array('name'));
    $query->orderBy('d.name');

    $result = $query->execute();

    $users = array();
    foreach ($result as $user) {
        $users[$user->uid] = $user->name;
    }
    return $users;
}

/**
 * Fonction appellée à la validation de l'edition d'un webform pour sauvegarder nos paramètres spécifiques à la GDPR
 */
function gdpr_webform_submit(&$form, \Drupal\Core\Form\FormStateInterface $form_state) {

    if ($entity = $form_state->getFormObject()->getEntity()) {
        $entity->setThirdPartySetting('oab_gdpr', 'gdpr_business_owner', $form_state->getValue('gdpr_business_owner'));
        $entity->setThirdPartySetting('oab_gdpr', 'gdpr_spoc_security', $form_state->getValue('gdpr_spoc_security'));
        $entity->setThirdPartySetting('oab_gdpr', 'gdpr_expiration_date', $form_state->getValue('gdpr_expiration_date'));
        $entity->setThirdPartySetting('oab_gdpr', 'gdpr_business_analysts', $form_state->getValue('gdpr_business_analysts'));
        $entity->setThirdPartySetting('oab_gdpr', 'gdpr_form_published', $form_state->getValue('gdpr_form_published'));
    }
}


function gdpr_hook_form_alter(&$form, $form_state, $form_id) {

    /**
     * Pour les nodes de type "Webform", je filtre les webform accessibles en fonction de ce que l'utilisateur
     * peut voir
     */
    if ($form_id == "node_webform_form") {
        $options = $form['webform']['widget'][0]['target_id']["#options"];

        $ret = [];
        $current_user = Drupal::currentUser();
        foreach ($options as $machine_name => $name) {
            if (is_array($name)) {
                $ret[$machine_name] = [];

                foreach ($name as $key => $value) {
                    $webform = \Drupal::entityTypeManager()->getStorage('webform')->load($key);
                    if (gdpr_check_authorized_view($webform, $current_user)) {
                        $ret[$machine_name][$key] = $value;
                    }
                }

                if (count($ret[$machine_name]) == 0) {
                    unset($ret[$machine_name]);
                }
            } else {
                $webform = \Drupal::entityTypeManager()->getStorage('webform')->load($machine_name);
                if (gdpr_check_authorized_view($webform, $current_user)) {
                    $ret[$machine_name] = $name;
                }
            }
        }

        $form['webform']['widget'][0]['target_id']["#options"] = $ret;
    }

    /**
     * Pour la GDPR, hook des webform pour ajouter des éléments
     */
    if ($form_id == "webform_add_form" || $form_id == 'webform_settings_form') {
        $entity = $form_state->getFormObject()->getEntity();

        $form['gdpr_informations'] = [
            '#type' => 'details',
            '#title'    => t('GDPR Information'),
            '#open' => true,
        ];

        $form['gdpr_informations']['gdpr_form_published'] = [
            '#type' => 'checkbox',
            '#title'    => t('Form published'),
            '#default_value' => ($entity->getThirdPartySetting('oab_gdpr', 'gdpr_form_published') !== null)
                    ? $entity->getThirdPartySetting('oab_gdpr', 'gdpr_form_published')
                    : false,
            '#access' => false,
            "#disabled" => "disabled"
        ];

        $business_owner = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner'));
        $current_user = Drupal::currentUser();
        // j'affiche la checkbox si on est dans les settings du webform
        // et l'utilisateur connecté est le "business owner" du formulaire en question
        if ($form_id == 'webform_settings_form') {

            ##Je n'affiche la publication que si on édite le formulaire, pas à la création
            $form['gdpr_informations']['gdpr_form_published']['#access'] = true;

            ## Je le rend cliquable que si l'utilisateur courant est le business_owner
            if ($current_user->id() == 1
                || ($business_owner !== null && (
                        in_array('webform_admin', $current_user->getRoles())
                        ||  (
                            in_array('webform_business_owner', $current_user->getRoles())
                            && $current_user->id() === $business_owner->id()
                        )
                    )
                )
            ) {
                $form['gdpr_informations']['gdpr_form_published']['#disabled'] = false;
            }
        }


        $form['gdpr_informations']['gdpr_business_owner'] = [
            '#type' => 'entity_autocomplete',
            '#title'    => t('Business Owner'),
            '#default_value' => \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner')),
            '#target_type' => "user",
            '#settings' => [
                'match_operator'    => "CONTAINS"
            ],
            "#selection_settings"   => [
                'include_anonymous' => false,
                'filter' => [
                    'role' => ['webform_business_owner'],
                ],
            ],
            '#required' => true,
        ];


        $form['gdpr_informations']['gdpr_business_analysts'] = [
            '#type' => 'select',
            '#multiple' => true,
            '#title'    => t('Business Analysts'),
            '#options' => gdpr_business_analysts_list(),
            '#description' => "Utilisez ctrl+click pour selectionner plusieurs utilisateurs",
            "#default_value"  => $entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_analysts')
        ];

        # Je donne les droits à l'admin de se selectionner
        if ($current_user->id() == 1) {
            $form['gdpr_informations']['gdpr_business_owner']["#selection_settings"]['filter']['role'][] = "administrator";
        }


        $form['gdpr_informations']['gdpr_spoc_security'] = [
            '#type' => 'entity_autocomplete',
            '#title'    => t('SPOC Security'),
            "#default_value"    => \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security')),
            '#required' => true,
            '#target_type' => "user",
            '#settings' => [
                'match_operator'    => "CONTAINS"
            ],
            "#selection_settings"   => [
                'include_anonymous' => false,
                'filter' => [
                    'role' => ['webform_spoc_securite'],
                ],
            ],
        ];
        # Je donne les droits à l'admin de se selectionner
        if ($current_user->id() == 1) {
            $form['gdpr_informations']['gdpr_spoc_security']["#selection_settings"]['filter']['role'][] = "administrator";
        }


        $form['gdpr_informations']['gdpr_expiration_date'] = [
            '#type' => 'date',
            '#title'    => t('Form expiration date'),
            '#default_value'    => $entity->getThirdPartySetting('oab_gdpr', 'gdpr_expiration_date')
        ];

        if (in_array('webform_manager', $current_user->getRoles())) {
            $form['gdpr_informations']['gdpr_expiration_date']['#required'] = true;
        }


        //array_unshift($form['actions']['submit']['#submit'],'_oab_webform_gdpr_submit' );

        ## Je place mon submit, pour éviter qu'il soit en dernière place, sinon ca crée des erreurs
        $old_submit = $form['actions']['submit']['#submit'];
        $submit = array_slice($old_submit, 0, count($old_submit) - 1, true) +
            ["ne_pas_supprimer" => "gdpr_webform_submit"] +
            array_slice($old_submit, count($old_submit) - 1, count($old_submit) - 1, true);

        $form['actions']['submit']['#submit'] = array_values($submit);
        $form['#validate'][] = '_oab_webform_gdpr_validate';
    }
}

/**
 * Envoi des mails aux users specifiés lors de la publication d'un webform
 */
function gdpr_hook_entity_update($entity) {
    if ($entity instanceof Drupal\webform\Entity\Webform) {
        $current_user = Drupal::currentUser();
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();

        $old_webform = $entity->original;

        $is_published = $entity->getThirdPartySetting('oab_gdpr', 'gdpr_form_published');
        $old_is_published = $old_webform->getThirdPartySetting('oab_gdpr', 'gdpr_form_published');

        ## Si le webform vient d'etre publié et que ce n'est pas un admin qui vient de le publier
        if ($is_published
            && $is_published !== $old_is_published
            && $current_user->id() != 1     #Je ne le fait pas pour l'admin)
        ) {

            $spoc = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_spoc_security'));
            if ($spoc !== null) {
                $mail_spoc = $spoc->getEmail();
                \Drupal::service('plugin.manager.mail')
                    ->mail('oab_backoffice', 'gdpr_publish_notice', $mail_spoc, $current_language, array('webform' => $entity));
            }

            $mail_creator = $entity->getOwner()->getEmail();
            \Drupal::service('plugin.manager.mail')
                ->mail('oab_backoffice', 'gdpr_publish_notice', $mail_creator, $current_language, array('webform' => $entity));

            $business_owner = \Drupal\user\Entity\User::load($entity->getThirdPartySetting('oab_gdpr', 'gdpr_business_owner'));
            if ($business_owner !== null) {
                $mail_business_owner = $business_owner->getEmail();
                \Drupal::service('plugin.manager.mail')
                    ->mail('oab_backoffice', 'gdpr_publish_notice', $mail_business_owner, $current_language, array('webform' => $entity));
            }

        }

        if ($is_published) {

            /////////////////////////////////////////////////////
            //Vidage des caches des contenus possedant ce webform
            $webform_id = $entity->id();

            //Recuperation de tous les contents type "Webform" ayant le formulaire
            $query = \Drupal::entityQuery('node');
            $query->condition('type', 'webform');
            $query->condition('webform', $webform_id);
            $result = $query->execute();

            $akamai_ctrl = new \Drupal\oab_akamai\Controller\OabAkamaiController();
            $host = "https://".\Drupal::request()->getHost();

            foreach ($result as $value) {
                $node_url =  Drupal\Core\Url::fromRoute('entity.node.canonical', ['node' => $value])->setAbsolute()->toString();

                $node_url = str_replace("back.", '', $node_url);
                $node_url = str_replace("backoffice.", '', $node_url);

                $akamai_ctrl->flushAkamai($node_url);
                $akamai_ctrl->flushVarnish($node_url, $host);
                $akamai_ctrl->flushDrupalCache($node_url);
            }

        }
    }
}

/**
 * Fonction pour le cron, pour nettoyer les résultats du formulaire
 */
function gdpr_hook_cron() {
    ##Je fais la vérif' qu'une fois par jour, à 1h du mat'
    #(2h, mais du coup, y a 1h de decalage par rapport à l'heure D8)


        ## Je recupère tous les webforms existants et je boucle sur chacun d'entre eux,
        ## les règles de suppression dépendant des éléments du webform
        # => Si une date d'expiration a été définie, toutes les données sont supprimées 6 mois après la date d'expiration du formulaire
        # => Si non définie, les données sont supprimées 6 mois après leur soumission

        $webform_query =  \Drupal::entityQuery('webform');
        $webforms = $webform_query->execute();

        foreach ($webforms as $webform_id => $webform_data) {

            $webform_entity = \Drupal::entityTypeManager()->getStorage('webform')->load($webform_id);

            if ($webform_entity !== null) {

                $expire_date = $webform_entity->getThirdPartySetting('oab_gdpr', 'gdpr_expiration_date');

                if ($expire_date == null || $expire_date == "") {
                    ## SI le formulaire n'a pas de date d'expiration, je supprime toutes les soumissions qui ont plus de 6 mois
                    ## (soit gdpr_expiration_date n'existe pas, soit il est setté avec un string vide (résultat du form sans donnée)

                    ##je recupère la date d'il y a 6 mois
                    $date = new Datetime\DrupalDateTime('6 month ago', new \DateTimezone(DATETIME_STORAGE_TIMEZONE));
                    $formatted = $date->format('U');    ## Format milliseconde

                    ##Query pour retrouver toutes les submissions antérieures à un an
                    $query = \Drupal::entityQuery('webform_submission')
                        ->condition('created', $formatted, '<')
                        ->condition('webform_id', $webform_id, '=');
                    $results = $query->execute();

                    ##je load toutes les submissions trouvées
                    $storage = \Drupal::entityTypeManager()->getStorage('webform_submission');
                    $webform_submissions = $storage->loadMultiple($results);

                    ##Suppression de toutes les entités trouvées
                    $storage->delete($webform_submissions);

                } else {

                    ## S'il a une date d'expiration, je regarde si on est 6 mois après la date d'expiration
                    ## si c'est le cas, je supprime TOUTES les données

                    ## Je recrée l'objet date de la date de suppression que je set 6 mois
                    $expire_date = new \DateTime($webform_entity->getThirdPartySetting('oab_gdpr', 'gdpr_expiration_date'));
                    $expire_date->add(new \DateInterval('P6M'));

                    ## Today
                    $today = new \DateTime('now');

                    ## Je compare les 2 dates. Si today est avant la date de suppression,
                    $diff = $today->diff($expire_date);


                    ## Si invert est à un, c'est qu'on est en négatif, et il faut supprimer les données
                    if ($diff->invert == 1) {

                        ## Dans ce cas là, je supprime toutes les données du formulaire en question
                        $query = \Drupal::entityQuery('webform_submission')
                            ->condition('webform_id', $webform_id, '=');
                        $results = $query->execute();

                        ##je load toutes les submissions trouvées
                      //  $storage = \Drupal::entityTypeManager()->getStorage('webform_submission')->loadMultiple($results);
                        $webform_submissions = $storage->loadMultiple($results);

                        ##Suppression de toutes les entités trouvées
                        $storage->delete($webform_submissions);
                    }

                }
            }

        }

        #####################################
        #####################################
        # Suppression des elements du dossier d'export des listes de documents du site
        \Drupal\oab_backoffice\Controller\OabExportFileListController::clearStorageDir();


}
