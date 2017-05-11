<?php

namespace Drupal\oab_axiome;


use DOMDocument;
use DOMXPath;
use Drupal\Core\Database\Database;
use Drupal\Core\Entity\Entity;
use Drupal\Core\File\FileSystem;
use Drupal\node\Entity\Node;
use Exception;
use stdClass;

class AxiomeImporter{

    private $fiches_jointent = array();
    private $arborescence_famille = array();
    private $axiome_folder_path = "";
    private $axiome_notification = array();
    private $axiome_deleted_fiche = array();

    function __construct(){
        $axiome_folder_path =  \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER);
        $this->axiome_folder_path = $axiome_folder_path . '/import';
        echo nl2br ("Axiome_folder_path = $axiome_folder_path \n");
        $this->axiome_search_archive($axiome_folder_path);
        //kint($this->axiome_notification);

    }

    /**
     * Main import function
     *
     * @param $folder
     *   The path of the axiome folder
     */
    private function axiome_search_archive($folder){
        $count = 0;
        // Scan du dossier "axiome/import"
        $this->axiome_create_dir($folder);
        if (is_dir($folder)){
            $files = scandir($folder);
            foreach ($files AS $file){

                if (is_file($folder.'/'.$file) && substr($file, -4) == '.zip'){

                    if ($count == 0){
                        exec("rm -fR $folder.'/import'");
                        $this->axiome_create_dir($folder . '/' . AXIOME_SAVE_FOLDER);

                        $this->axiome_notification[] = "file : ".$file;

                        if ($this->axiome_unzip($folder.'/'.$file, $folder.'/import')){
                            file_unmanaged_move($folder.'/'.$file, $folder.'/'.AXIOME_SAVE_FOLDER, FILE_EXISTS_REPLACE);

                            // Scan du dossier "import"
                            $folder_import = $folder.'/import';
                            echo nl2br("folder_import = $folder_import \n");
                            $files = scandir($folder_import);
                           // kint ($files);
                            foreach ($files AS $file){

                                if (is_file($folder_import.'/'.$file)
                                    && substr($file, -4) == '.zip'
                                    && substr($file, 0, 11) == 'referentiel'){
                                    echo nl2br("Will handle file $file \n");
                                    $this->axiome_notification[] = "referentiel : ".$file;

                                    if ($this->axiome_unzip($folder_import.'/'.$file, $folder_import)){
                                        echo nl2br("Unzip file $file OK \n");
                                        file_unmanaged_delete($folder_import.'/'.$file);

                                        // Recherche du fichier référentiel XML
                                        preg_match("@[a-z_]*_([A-Za-z]*)_[-0-9]*@", $file, $matches);
                                        if ($matches && isset($matches[1])){
                                            $referentiel_file = "referentiel_" . $matches[1] . ".xml";

                                            if ($dom = $this->axiome_validate_referentiel($folder_import, $referentiel_file)){
                                                echo nl2br ("RefFile = $referentiel_file \n");
                                                // Traitement des référentiels et fiches
                                                $this->axiome_scan_fiche_archives($folder_import);
                                                echo nl2br("Scan fiche archive OK \n");
                                                $this->axiome_parse_referentiel($dom);
                                                echo nl2br("Parse réferentiel  OK \n");

                                                // Déplacement du référentiel dans "axiome"
                                                file_unmanaged_move($folder_import.'/'.$referentiel_file, $folder, FILE_EXISTS_REPLACE);
                                            }
                                        }
                                    }
                                }
                            }
                            // Déplacement des dossiers de fiche dans "axiome"
                            echo nl2br("Will move folder $folder_import to $folder \n");
                            $this->axiome_move_documents($folder_import, $folder);

                            $this->axiome_verif_taxonomy_not_empty();
                            echo nl2br("Will remove folder $folder_import \n");
                            exec("rm -fR '$folder_import'");
                        }
                        $count ++;
                    }
                }
            }
        }
        else{
            $this->axiome_notification[] = "ERREUR | \"".$folder."\" n'est pas un dossier";
        }
        $this->axiome_send_notifications($this->axiome_notification);
    }

    /**
     * Directory creation function
     *
     * @param $folder
     *   The path of the folder to create
     *
     * @return
     *   The folder path
     */
    private function axiome_create_dir($folder){
        if (!file_exists($folder)) {
            if (mkdir($folder, 0777, true)){
                return $folder;
            }
            else{
                $this->axiome_notification[] = "ERREUR | impossible de créer le dossier \"".$folder."\"";
            }
        }
    }

    /**
     * Unzip an axiome archive
     *
     * @param $file
     *   The path of the file to unzip
     *
     * @param $destination
     *   The path of the destination folder
     *
     * @return
     *   boolean
     */
    private function axiome_unzip($file, $destination){
        $this->axiome_create_dir($destination);

        if (is_dir($destination)) {

            $cwd = getcwd();
            chdir($destination);

            echo nl2br(" \n Unzip destination  $destination file =  $file \n");
            exec("/usr/bin/unzip '$file' ");
            chdir($cwd);

            return TRUE;
        }
        else{
            $this->axiome_notification[] = "ERREUR | le dossier \"".$destination."\" n'existe pas";
            return FALSE;
        }
    }

    /**
     * XSD validation of the axiome referentiel
     *
     * @param $folder
     *   The path of the axiome folder
     *
     * @param $file
     *   The path of the XML file to validate
     *
     * @return
     *   dom string
     */
    private function axiome_validate_referentiel($folder, $file){
        if (is_file($folder.'/'.$file)){
            $referentiel_xsd = $folder.'/'.AXIOME_REFERENTIEL_SCHEMA;

            $dom = new DOMDocument("1.0");
            $dom->load($folder.'/'.$file);
            if($dom->schemaValidate($referentiel_xsd)){

                $this->axiome_notification[] = "referentiel XML valide";

                return $dom;
            }
            else{
                $this->axiome_notification[] = "ERREUR | referentiel XML invalide";
                return FALSE;
            }
        }
    }

    /**
     * XSD validation of an axiome product
     *
     * @param $folder
     *   The path of the axiome product folder
     *
     * @param $file
     *   The path of the XML file to validate
     *
     * @return
     *   dom string
     */
    private function axiome_validate_fiche($folder, $file){
        if (is_file($folder.'/'.$file)){
            $fiche_xsd = $folder.'/'.AXIOME_FICHE_SCHEMA;

            $dom = new DOMDocument("1.0");
            $dom->load($folder.'/'.$file);
            if($dom->schemaValidate($fiche_xsd)){

                $this->axiome_notification[] = "Fiche XML valide";

                return $dom;
            }
            else{
                $this->axiome_notification[] = "ERREUR | Fiche XML invalide";
                return FALSE;
            }
        }
    }

    /**
     * Scan the axiome import folder for product ZIP
     *
     * @param $folder
     *   The path of the axiome import folder
     */
    private function axiome_scan_fiche_archives($folder){
        $files = scandir($folder);
        foreach ($files AS $file){
            if (is_file($folder.'/'.$file)
                && substr($file, -4) == '.zip'){
                $file_name = $folder. '/fiches/' . substr($file, 0, -4);
                if ($this->axiome_create_dir($file_name)){
                    if ($this->axiome_unzip($folder.'/'.$file, $file_name)){
                        file_unmanaged_delete($folder.'/'.$file);

                        // renommage du dossier avec l'id de la fiche
                        $files_fiche = scandir($file_name);
                        foreach ($files_fiche AS $file_fiche){
                            if (is_file($file_name.'/'.$file_fiche)
                                && substr($file_fiche, -4) == '.xml'){
                                $dom = new DOMDocument("1.0");
                                $dom->load($file_name.'/'.$file_fiche);

                                $id_fiche = $dom->documentElement->getAttribute('id');

                                $this->fiches_jointent[$id_fiche] = $id_fiche;
                                echo nl2br( "Will rename $file_name by /fiches/$id_fiche \n");
                                rename($file_name, $folder.'/fiches/'.$id_fiche);
                            }
                        }
                    }
                }
            }
        }
    }

    /**
     * crawl the referentiel dom string
     *
     * @param $dom
     *   The dom string
     */
    private function axiome_parse_referentiel($dom){
        $xpath = new DOMXPath($dom);

        $entryname = $dom->documentElement->getAttribute('environnement_name');
        switch($entryname){
            case "International":
                $content_language = "en";
                break;
            case "France":
                $content_language = "fr";
                break;
        }

        $referentiel_date = $dom->documentElement->getAttribute('datecre');

        if ($target_update_date = strtotime($referentiel_date)){
            $target_update_date -= 60*60*24;
            $target_update_date = date("Y-m-d", $target_update_date);

            // classement famille/sous-famille
            $liste_classements = $xpath->query("/referentiel/classements/element_classement_group");
            foreach($liste_classements as $classements){
                $nom_classement = strtolower(trim($classements->getElementsByTagName('Attributes')->item(0)->getElementsByTagName('identifiant')->item(0)->nodeValue));

                if ($nom_classement == 'portfolio'
                    || $nom_classement == 'porfolio'){
                    $liste_famille = $xpath->query($classements->getNodePath().'/Children/element_classement');

                    foreach($liste_famille as $famille){
                        $famille_id = $famille->getAttribute('id');


                        $famille_name = $famille->getElementsByTagName('Attributes')->item(0)->getElementsByTagName('nom')->item(0)->nodeValue;

                        $this->arborescence_famille[$famille_id] = array(
                            'name' => $famille_name,
                            'parent' => 0
                        );
                        kint($famille_name);
                        if ($tid = $this->axiome_recherche_famille_tid($famille_name, $content_language)){
                            $this->arborescence_famille[$famille_id]['tid'] = $tid;
                        }

                        // childrens
                        $liste_childrens = $xpath->query($famille->getNodePath().'/Children/element_classement');
                        foreach($liste_childrens as $children){
                            $children_id = $children->getAttribute('id');
                            $children_name = $children->getElementsByTagName('Attributes')->item(0)->getElementsByTagName('nom')->item(0)->nodeValue;

                            $this->arborescence_famille[$children_id] = array(
                                'name' => $children_name,
                                'parent' => $famille_id
                            );

                            if ($tid = $this->axiome_recherche_famille_tid($children_name, $content_language)){
                                $this->arborescence_famille[$children_id]['tid'] = $tid;
                            }
                        }
                    }
                }
            }

            // informations sur les fiches
            $liste_fiches = $xpath->query("/referentiel/complements_ficheoffre/ficheoffre");
            foreach($liste_fiches as $fiche){
                echo nl2br("Will handle Fiche \n");
                // On cherche les fiches à mettre à jour en fonction des dates dans le référentiel
                $fiche_update_date = $fiche->getAttribute('datemaj');
                $fiche_id = $fiche->getAttribute('id');
                if ($fiche_update_date == $target_update_date){
                    $this->axiome_recherche_fiche_existante($fiche_id, $fiche, $content_language);
                }
                // Ou si on a une archive pour cette fiche
                elseif (isset($this->fiches_jointent[$fiche_id])){
                    $this->axiome_recherche_fiche_existante($fiche_id, $fiche, $content_language);
                }
            }
        }
    }

    /**
     * search for fiche_id in the database if it's a new content or an existing one
     *
     * @param $fiche_id
     *   The axiome product fiche id
     */
    private function axiome_recherche_fiche_existante($fiche_id, $xpath_fiche, $content_language){
        // On recherche le classement portfolio dans la fiche. Sinon, ce n'est pas la peine d'enregistrer le contenu
        $has_portfolio = false;
        $familles = $xpath_fiche->getElementsByTagName('classement')->item(0)->getElementsByTagName('element_classement_group');
        foreach ($familles AS $famille){
            $classement_nom = strtolower(trim($famille->getAttribute('identifiant')));
            if ($classement_nom == "portfolio"
                || $classement_nom == "porfolio"){
                $has_portfolio = true;
            }
        }

        if ($has_portfolio){
            //TODO : equivalent dans D8 de field_data_field_id_fiche et vérifier les champs : nid, field_id_fiche_value
            $query = \Drupal::database()->select('field_data_field_id_fiche', 'f');
            $query->join("node", "n", "n.nid = f.entity_id");
            $query->fields("n", array("nid"))
                ->condition("f.field_id_fiche_value", $fiche_id, "=")
                ->range(0, 1);

            $results = $query->execute()->fetchObject();

            // Si c'est une nouvelle fiche
            if (!is_object($results)){
                $this->axiome_traitement_fiche($xpath_fiche, $content_language, FALSE);
            }
            // Si c'est une fiche existante
            else{
                $this->axiome_traitement_fiche($xpath_fiche, $content_language, $results->nid);
            }

            if (isset($this->fiches_jointent[$fiche_id])){
                unset($this->fiches_jointent[$fiche_id]);
            }
        }
    }

    /**
     * Search a taxonomy term in the DB
     *
     * @param $name
     *   The name of the term
     *
     * @param $language
     *   The language of the term
     *
     * @return
     *   integer tid
     */
    private function axiome_recherche_famille_tid($name, $language){
        $connection = Database::getConnection();

        $query = $connection->select('taxonomy_term_data', 't');
        $query->innerJoin('taxonomy_term_field_data', 'term_data', 'term_data.tid = t.tid');

        $query->fields('t', array('tid'))
            ->condition('term_data.name', $name, '=')
            ->condition('term_data.langcode', $language, '=')
            ->condition('t.vid', AXIOME_TAXO_FAMILLE, '=')
            ->range(0, 1);

        $result = $query->execute()->fetchObject();


        if (is_object($result)){
            return $result->tid;
        }
        else{
            return FALSE;
        }
    }

    /**
     * Fetch the product xml file and generate the node or update it
     *
     * @param $xpath_fiche
     *   The Xpath of the product XML file
     *
     * @param $content_language
     *   The language of the node
     *
     * @param $nid
     *   The nid of the node if existing
     */
    private function axiome_traitement_fiche($xpath_fiche, $language, $nid = FALSE){

        //TODO : migrer le workflow
        $fiche_dir = $this->axiome_folder_path.'/'.$xpath_fiche->getAttribute('id');
        if (is_dir($fiche_dir)){
            $files_fiche = scandir($fiche_dir);
            foreach ($files_fiche AS $file_fiche){
                if (is_file($fiche_dir.'/'.$file_fiche)
                    && substr($file_fiche, -4) == '.xml'){
                    if ($this->axiome_validate_fiche($fiche_dir, $file_fiche)){
                        // Si c'est une fiche existante
                        if ($nid){
                            $nid = (int)$nid;
                            $node = Node::load($nid);

                            $publiee = $xpath_fiche->getElementsByTagName('publiee')->item(0)->nodeValue;
                            if ($publiee == "true"){
                                $node->revision = 1;
                                $node->revision_operation = REVISIONING_NEW_REVISION_WITH_MODERATION;
                                $node->revision_uid = $node->uid;
                                $this->axiome_notification[] = "mise à jour de fiche";
                            }
                            else{
                                $this->axiome_notification[] = "suppression de fiche";

                                $info_notification = array(
                                    'nom commercial' => $node->title,
                                    'langue' => $node->language,
                                    'id fiche' => $node->field_id_fiche['und'][0]['value'],
                                    'id offre' => $node->field_id_offre['und'][0]['value'],
                                    'nid' => $node->nid
                                );

                                $this->axiome_notification[] = "fiche axiome : ".var_export($info_notification, TRUE);

                                //entity_delete($nid);
                                $node->delete();


                                $this->axiome_deleted_fiche[$node->field_id_fiche['und'][0]['value']] = $node->field_id_fiche['und'][0]['value'];
                                if (isset($node)) unset($node);
                            }
                        }
                        // Si c'est une nouvelle fiche
                        else{
                            $this->axiome_notification[] = "nouvelle fiche importée";

                            $node = new stdClass();
                            $node->title = $xpath_fiche->getAttribute('nom_offre_commerciale');
                            $node->type = 'axiome';
                            $node->sticky = 0;
                            $node->promote = 0;
                            $node->language = $language;
                            $node->uid = 0;

                            $node->field_id_fiche['und'][0]['value'] = $xpath_fiche->getAttribute('id');
                            $node->field_id_offre['und'][0]['value'] = $xpath_fiche->getElementsByTagName('offre_commerciale')->item(0)->getAttribute('id');
                        }

                        if (isset($node)){
                            $this->axiome_fiche_recherche_correspondance($node, $fiche_dir.'/'.$file_fiche);
                            $this->axiome_fiche_recherche_famille($node, $xpath_fiche);

                            try{
                                $node->save();
                                //node_save($node);

                                // Si c'est une nouvelle fiche

                                //TODO : AXIOME_WORKFLOW_REQUEST ?
                                if (!$nid){
                                    //workflow_transition($node, AXIOME_WORKFLOW_REQUEST);
                                    $data = array(
                                        'nid' => $node->nid,
                                        'sid' => AXIOME_WORKFLOW_REQUEST,
                                        'uid' => $node->uid,
                                        'stamp' => REQUEST_TIME,
                                    );
                                    workflow_update_workflow_node($data);
                                }

                                $info_notification = array(
                                    'nom commercial' => $node->title,
                                    'langue' => $node->language,
                                    'status' => $node->status,
                                    'id fiche' => $node->field_id_fiche['und'][0]['value'],
                                    'id offre' => $node->field_id_offre['und'][0]['value'],
                                    'nid' => $node->nid
                                );

                                $this->axiome_notification[] = "fiche axiome : ".var_export($info_notification, TRUE);
                            }
                            catch(Exception $e) {
                                $this->axiome_notification[] = "ERREUR | la fiche id \"".$xpath_fiche->getAttribute('id')."\" n'a pas pu être importée";
                                $this->axiome_notification[] = "Exception : ".var_export($e, TRUE);
                            }
                        }
                    }
                }
            }
        }
        else{
            $this->axiome_notification[] = "ERREUR | Pas de dossier pour la fiche : ".$xpath_fiche->getAttribute('id');
        }
    }

    /**
     * Crawl the axiome product XML file for field correspondance
     *
     * @param $node
     *   The node object reference
     *
     * @param $fiche
     *   The axiome product XML file string
     */
    private function axiome_fiche_recherche_correspondance(&$node, $fiche){
        $dom = new DOMDocument("1.0");
        $dom->load($fiche);
        $xpath = new DOMXPath($dom);

        // short description
        $field_txt_catcher = $xpath->query("/ficheoffre/Attributes/accroche")->item(0)->nodeValue;
        $node->field_txt_catcher['und'][0]['value'] = $field_txt_catcher;

        // XML content
        $field_xml_content = file_get_contents($fiche);
        $node->field_xml_content['und'][0]['value'] = $field_xml_content;

        // metatags
        $meta_title = $xpath->query("/ficheoffre/Attributes/a_savoir")->item(0)->nodeValue;
        $meta_keywords = $xpath->query("/ficheoffre/Attributes/kw")->item(0)->nodeValue;
        if ($meta_title != ""){
            $node->metatags[$node->language]['title']['value'] = $meta_title;
        }
        if ($meta_keywords != ""){
            $node->metatags[$node->language]['keywords']['value'] = $meta_keywords;
        }
    }

    /**
     * Crawl the axiome product XML file for taxonomy correspondance
     *
     * @param $node
     *   The node object reference
     *
     * @param $xpath
     *   The xpath of the product file
     */
    private function axiome_fiche_recherche_famille(&$node, $xpath){
        $node->field_taxo_familly_axiome['und'] = array();

        //$familles = $xpath->getElementsByTagName('classement')->item(0)->getElementsByTagName('element_classement_group')->item(0)->getElementsByTagName('element_classement_list');
        $familles = $xpath->getElementsByTagName('classement')->item(0)->getElementsByTagName('element_classement_group');
        foreach ($familles AS $famille){
            $classement_nom = strtolower(trim($famille->getAttribute('identifiant')));
            if ($classement_nom == "portfolio"
                || $classement_nom == "porfolio"){
                $children_id = $famille->getElementsByTagName('element_classement_list')->item(0)->getElementsByTagName('element_classement_id')->item(0)->nodeValue;
                $parent_id = "";

                // il faut créer le parent avant l'enfant
                if (isset($this->arborescence_famille[$children_id])
                    && isset($this->arborescence_famille[$children_id]['name'])){
                    $children_name = $this->arborescence_famille[$children_id]['name'];

                    if (isset($this->arborescence_famille[$children_id]['parent'])
                        && $this->arborescence_famille[$children_id]['parent'] != 0){
                        $parent_id = $this->arborescence_famille[$children_id]['parent'];

                        if (isset($this->arborescence_famille[$parent_id])
                            && isset($this->arborescence_famille[$parent_id]['name'])){
                            $parent_name = $this->arborescence_famille[$parent_id]['name'];

                            if (isset($this->arborescence_famille[$parent_id]['tid'])){
                                $parent_tid = $this->arborescence_famille[$parent_id]['tid'];
                                $node->field_taxo_familly_axiome['und'][] = array('tid' => $parent_tid);
                            }
                            else{
                                // création du term parent
                                $term = new stdClass();
                                $term->name = $parent_name;
                                $term->vid = AXIOME_TAXO_FAMILLE;
                                $term->language = $node->language;
                                $term->parent = 0;

                                try{
                                    taxonomy_term_save($term);

                                    $info_notification = array(
                                        'name' => $term->name,
                                        'tid' => $term->tid,
                                        'language' => $term->language,
                                    );

                                    $this->axiome_notification[] = "Nouveau terme parent de taxonomy créé : ".var_export($info_notification, TRUE);

                                    $this->arborescence_famille[$parent_id]['tid'] = $term->tid;
                                    $node->field_taxo_familly_axiome['und'][] = array('tid' => $term->tid);
                                }
                                catch(Exception $e){
                                    $this->axiome_notification[] = "ERREUR | le terme parent \"".$parent_name."\" n'a pas pu être importé";
                                    $this->axiome_notification[] = "Exception : ".var_export($e, TRUE);
                                }
                            }
                        }
                    }

                    if (isset($this->arborescence_famille[$children_id]['tid'])){
                        $children_tid = $this->arborescence_famille[$children_id]['tid'];
                        $node->field_taxo_familly_axiome['und'][] = array('tid' => $children_tid);
                    }
                    else{
                        if ($parent_id != ""
                            && isset($this->arborescence_famille[$parent_id]['tid'])){
                            // création du term enfant
                            $term = new stdClass();
                            $term->name = $children_name;
                            $term->vid = AXIOME_TAXO_FAMILLE;
                            $term->language = $node->language;
                            $term->parent = $this->arborescence_famille[$parent_id]['tid'];

                            try{
                                taxonomy_term_save($term);

                                $info_notification = array(
                                    'name' => $term->name,
                                    'tid' => $term->tid,
                                    'language' => $term->language,
                                );

                                $this->axiome_notification[] = "Nouveau terme enfant de taxonomy créé : ".var_export($info_notification, TRUE);

                                $this->arborescence_famille[$children_id]['tid'] = $term->tid;
                                $node->field_taxo_familly_axiome['und'][] = array('tid' => $term->tid);
                            }
                            catch(Exception $e){
                                $this->axiome_notification[] = "ERREUR | le terme enfant \"".$children_name."\" n'a pas pu être importé";
                                $this->axiome_notification[] = "Exception : ".var_export($e, TRUE);
                            }
                        }
                    }
                }
            }
        }
    }

    /**
     * Move the axiome document folder after import
     *
     * @param $source
     *   The source directory path
     *
     * @param $destination
     *   The destination directory path
     */
    private function axiome_move_documents($source, $destination){
        $files = scandir($source);
        foreach ($files AS $file){
            if (is_dir($source.'/'.$file)
                && $file != '.'
                && $file != '..'
                && !in_array($file, $this->axiome_deleted_fiche)){
                exec("rm -fR '$destination/$file'");
                exec("mv '$source/$file' '$destination/$file'");
            }
        }
    }

    /**
     * Verify if any taxonomy term has a node attached
     */
    private function axiome_verif_taxonomy_not_empty(){
        $query = \Drupal::database()->select('taxonomy_term_data', 't');
        $query->leftJoin('taxonomy_index', 'i', 'i.tid = t.tid');
        $query->fields('t', array('tid', 'name'));
        $query->groupBy('t.tid')
            ->condition('t.vid', AXIOME_TAXO_FAMILLE, '=')
            ->havingCondition('max_tid', 0, '=');

        $alias = $query->addExpression('COUNT(i.tid)', 'max_tid');

        $results = $query->execute()->fetchAll();

        foreach ($results AS $result){
            if ($result->max_tid == 0){
                //taxonomy_term_delete($result->tid);

                //$this->axiome_notification[] = "Terme de taxonomy supprimé : ".var_export(array('tid' => $result->tid, 'name' => $result->name), TRUE);

            }
        }
    }

    /**
     * Send the axiome notification
     *
     * @param $notifications
     *	The notification array
     */
    private function axiome_send_notifications($notifications = array()){
        if(is_array($notifications)
            && !empty($notifications)){
            //rules_invoke_component('rules_debug_axiome_import',var_export($notifications, TRUE));
        }
    }
}