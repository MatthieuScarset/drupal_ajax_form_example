<?php

namespace Drupal\oab_axiome;


use DOMDocument;
use DOMXPath;
use Drupal\Core\Database\Database;
use Drupal\Core\Entity\Entity;
use Drupal\Core\File\FileSystem;
use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;
use Exception;
use function PHPSTORM_META\type;
use stdClass;

class AxiomeImporter{

    private $fiches_jointent = array();
    private $arborescence_famille = array();
    private $arborescence_secteur = array();
    private $arborescence_metier = array();
    private $axiome_folder_path = "";
    public $axiome_folder_root_path = "";
    private $axiome_notification = array();
    private $axiome_deleted_fiche = array();
    public $message = '';
    private $id_en_cours = '';

    function __construct(){
        $this->axiome_folder_root_path =  \Drupal::service('file_system')->realpath(file_default_scheme() . '://' . AXIOME_FOLDER);
        $this->axiome_folder_path =  $this->axiome_folder_root_path . '/import';
        $this->message = "== STEP 1 : Contruct ==\nAxiome_folder_path = $this->axiome_folder_path \n";
    }

    /**
     * Main import function
     *
     * @param $folder
     *   The path of the axiome folder
     */
    public function axiome_search_archive($folder){
        $count = 0;

        // Scan du dossier "axiome/import"
        $this->message .= "== STEP 2 : axiome_search_archive ".$folder."==\n";
        $this->axiome_create_dir($folder);
        if (is_dir($folder)){
            $files = scandir($folder);
            if(!empty($files)){
                foreach ($files AS $file){

                    if (is_file($folder.'/'.$file) && substr($file, -4) == '.zip'){
                        $this->message .= "ZipFile found = $file \n";

                        if ($count == 0){
                            $cmd = escapeshellcmd("rm -fR $folder.'/import'");
                            exec($cmd);
                            $this->axiome_create_dir($folder . '/' . AXIOME_SAVE_FOLDER);

                            $this->axiome_notification[] = "file : ".$file;

                            if ($this->axiome_unzip($folder.'/'.$file, $folder.'/import')){
                                $this->message .= 'Move file '.$file.' in '.$folder.'/'.AXIOME_SAVE_FOLDER."\n" ;
                                file_unmanaged_move($folder.'/'.$file, $folder.'/'.AXIOME_SAVE_FOLDER, FILE_EXISTS_REPLACE);

                                // Scan du dossier "import"
                                $folder_import = $folder.'/import';

                                $this->message .= "folder_import = $folder_import \n";
                                $files = scandir($folder_import);


                                foreach ($files AS $file){

                                    if (is_file($folder_import.'/'.$file)
                                        && substr($file, -4) == '.zip'
                                        && substr($file, 0, 11) == 'referentiel'){
                                        $this->message .= "Will handle file $file \n";
                                        $this->axiome_notification[] = "referentiel : ".$file;

                                        if ($this->axiome_unzip($folder_import.'/'.$file, $folder_import)){

                                            $this->message .= "Unzip file $file OK \n";
                                            file_unmanaged_delete($folder_import.'/'.$file);

                                            // Recherche du fichier référentiel XML
                                            preg_match("@[a-z_]*_([A-Za-z]*)_[-0-9]*@", $file, $matches);

                                            if ($matches && isset($matches[1])){
                                                $referentiel_file = "referentiel_" . $matches[1] . ".xml";

                                                if ($dom = $this->axiome_validate_referentiel($folder_import, $referentiel_file)){
                                                    $this->message .= "-- Traitement des référentiels et fiche --\n";
                                                    $this->message .= "RefFile = $referentiel_file \n";
                                                    // Traitement des référentiels et fiches
                                                    $this->axiome_scan_fiche_archives($folder_import);
                                                    $this->axiome_parse_referentiel($dom);
                                                    // Déplacement du référentiel dans "axiome"
                                                    file_unmanaged_move($folder_import.'/'.$referentiel_file, $folder, FILE_EXISTS_REPLACE);
                                                }
                                            }
                                        }
                                    }
                                }
                                // Déplacement des dossiers de fiche dans "axiome"
                                $this->axiome_move_documents($folder_import, $folder);
                                $this->axiome_verif_taxonomy_not_empty();
                                $cmd = escapeshellcmd("rm -fR '$folder_import'");
                                exec($cmd);
                            }
                            $count ++;
                        }
                    }
                }
            }else{
                $this->message .= "Aucun fichier trouvé.\n";
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
            $cmd = escapeshellcmd("/usr/bin/unzip '$file' ");
            exec($cmd);
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
            }else{
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
    private function axiome_parse_referentiel($dom)
    {
        $this->message .=  "Will parse referenciel \n";
        $xpath = new DOMXPath($dom);

        $entryname = $dom->documentElement->getAttribute('environnement_name');
        switch ($entryname) {
            case "International":
                $content_language = "en";
                break;
            case "France":
                $content_language = "fr";
                break;
        }

        $referentiel_date = $dom->documentElement->getAttribute('datecre');

        if ($target_update_date = strtotime($referentiel_date)) {
            $target_update_date -= 60 * 60 * 24;
            $target_update_date = date("Y-m-d", $target_update_date);

            // classement famille/sous-famille
            $liste_classements = $xpath->query("/referentiel/classements/element_classement_group");
            $this->message .=  "- Traitement des classements \n";
            foreach ($liste_classements as $classements) {
                $nom_classement = strtolower(trim($classements->getElementsByTagName('Attributes')->item(0)->getElementsByTagName('identifiant')->item(0)->nodeValue));

                if ($nom_classement == 'portfolio'
                    || $nom_classement == 'porfolio'
                    || $nom_classement == 'secteurs'
                    || $nom_classement == 'metiers'
                ) {
                    $this->axiome_manage_classement($xpath, $classements, $nom_classement, $content_language);
                }
            }

            $this->message .=  "- Traitement des informations des fiches \n";
            // informations sur les fiches
            $liste_fiches = $xpath->query("/referentiel/complements_ficheoffre/ficheoffre");
            foreach ($liste_fiches as $fiche) {
                // On cherche les fiches à mettre à jour en fonction des dates dans le référentiel
                $fiche_update_date = $fiche->getAttribute('datemaj');
                $fiche_id = $fiche->getAttribute('id');

                if ($fiche_update_date == $target_update_date) {
                    $this->axiome_recherche_fiche_existante($fiche_id, $fiche, $content_language);
                } // Ou si on a une archive pour cette fiche
                elseif (isset($this->fiches_jointent[$fiche_id])) {
                    $this->axiome_recherche_fiche_existante($fiche_id, $fiche, $content_language);
                }
            }
        }
    }

    /**
     * Permet de faire le tableau référentiel des 3 filtres (solution, secteurs, métiers)
     * @param $xpath
     * @param $classements
     * @param $nom_classement
     * @param $content_language
     */

    private function axiome_manage_classement($xpath, $classements, $nom_classement, $content_language){
        $this->message .=  "AXIOME MANAGE CLASSEMENT $nom_classement \n";
        $liste_famille = $xpath->query($classements->getNodePath() . '/Children/element_classement');
        if ($nom_classement == "portfolio"
            || $nom_classement == "porfolio"){
            $taxo = $this->arborescence_famille;
        }elseif ($nom_classement == "secteurs"){
            $taxo = $this->arborescence_secteur;
        }elseif ($nom_classement == "metiers"){
            $taxo = $this->arborescence_metier;
        }
        foreach ($liste_famille as $famille) {
            $famille_id = $famille->getAttribute('id');
            $famille_name = $famille->getElementsByTagName('Attributes')->item(0)->getElementsByTagName('nom')->item(0)->nodeValue;

            $taxo[$famille_id] = array(
                'name' => $famille_name,
                'children' => array()
            );

            if ($tid = $this->axiome_recherche_famille_tid($famille_name, $content_language, $nom_classement)) {
                $taxo[$famille_id]['tid'] = $tid;
            }

            // sous familles
            $liste_sousfamille = $xpath->query($famille->getNodePath() . '/Children/element_classement');
            foreach ($liste_sousfamille as $sousfamille) {
                $sousfamille_id = $sousfamille->getAttribute('id');
                array_push($taxo[$famille_id]['children'], $sousfamille_id);
            }
        }
        if ($nom_classement == "portfolio"
            || $nom_classement == "porfolio"){
            $this->arborescence_famille = $taxo;
        }elseif ($nom_classement == "secteurs"){
            $this->arborescence_secteur = $taxo;
        }elseif ($nom_classement == "metiers"){
            $this->arborescence_metier = $taxo;
        }
    }

    /**
     * search for fiche_id in the database if it's a new content or an existing one
     *
     * @param $fiche_id
     *   The axiome product fiche id
     */
    private function axiome_recherche_fiche_existante($fiche_id, $xpath_fiche, $content_language)
    {
        // On recherche le classement portfolio dans la fiche. Sinon, ce n'est pas la peine d'enregistrer le contenu
        $has_portfolio = false;
        $classement = $xpath_fiche->getElementsByTagName('classement');
        $familles = $classement->item(0)->getElementsByTagName('element_classement_group');

        foreach ($familles AS $famille) {
            $classement_nom = strtolower(trim($famille->getAttribute('identifiant')));
            if ($classement_nom == "portfolio"
                || $classement_nom == "porfolio"
            ) {
                $has_portfolio = true;
            }
        }

        if ($has_portfolio) {
            //TODO : QUERY NOK; à rechecker
            //nouveaux champs créés dans le type de contenu Solutions : id_fiche et id_offre
            $query = \Drupal::database()->select('node__field_id_fiche', 'f');
            $query->join("node", "n", "n.nid = f.entity_id");
            $query->fields("n", array("nid"))
                ->condition("f.field_id_fiche_value", $fiche_id, "=")
                ->range(0, 1);

            $results = $query->execute()->fetchObject();
            // Si c'est une nouvelle fiche
            if (!is_object($results) || !isset($results->nid)) {
                $this->message .=  "Fiche nouvelle => insert \n";
                $this->axiome_traitement_fiche($xpath_fiche, $content_language, FALSE);
            } // Si c'est une fiche existante
            else {
                $this->message .=  "Fiche existante => update \n";
                $this->axiome_traitement_fiche($xpath_fiche, $content_language, $results->nid);
            }

            if (isset($this->fiches_jointent[$fiche_id])) {
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
    private function axiome_recherche_famille_tid($name, $language, $nom_classement){
        $connection = Database::getConnection();

        if ($nom_classement == "portfolio"
            || $nom_classement == "porfolio"){
            $vid = AXIOME_TAXO_FAMILLE;
        }elseif ($nom_classement == "secteurs"){
            $vid = AXIOME_TAXO_SECTEURS;
        }elseif ($nom_classement == "metiers"){
            $vid = AXIOME_TAXO_METIERS;
        }

        $query = $connection->select('taxonomy_term_field_data', 't');

        $query->fields('t', array('tid'))
            ->condition('t.name', $name, '=')
            ->condition('t.langcode', $language, '=')
            ->condition('t.vid', $vid, '=')
            ->range(0, 1);

        $result = $query->execute()->fetchObject();

        if (is_object($result)){
            return $result->tid;
        }else{
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
    private function axiome_traitement_fiche($xpath_fiche, $language, $nid)
    {

        //TODO : workflow
        $fiche_dir = $this->axiome_folder_path . '/fiches/' . $xpath_fiche->getAttribute('id');

        $this->id_en_cours = $xpath_fiche->getAttribute('id');
        $this->message .= "axiome traitement fiche id = " . $xpath_fiche->getAttribute('id')." - ".$xpath_fiche->getAttribute('nom_offre_commerciale')."\n";
        if (is_dir($fiche_dir)) {
            $files_fiche = scandir($fiche_dir);
            foreach ($files_fiche AS $file_fiche) {
                if (is_file($fiche_dir . '/' . $file_fiche)
                    && substr($file_fiche, -4) == '.xml'
                ) {
                    if ($this->axiome_validate_fiche($fiche_dir, $file_fiche)) {

                        // Si c'est une fiche existante
                        if ($nid) {
                            $nid = (int)$nid;
                            $this->message .= "Chargement du NODE $nid\n";
                            $node = Node::load($nid);
                            $node->set('moderation_state', array('target_id' => 'draft'));
                            $node->setChangedTime(mktime());
                            $this->message .= "microtime ".mktime()."\n";

                        } else {// Si c'est une nouvelle fiche
                            $this->axiome_notification[] = "nouvelle fiche importée";

                            //creation du node
                            // TODO : A completer
                            $this->message .= "Création du NODE \n";

                            $node = Node::create([
                                'type'        => 'product',
                                'title'       => $xpath_fiche->getAttribute('nom_offre_commerciale'),
                                'isNew'       => true,
                                'langcode'    => $language,
                                'promoted'    => 0,
                                'sticky'      => 0,
                                'moderation_state' => 'draft',
                            ]);
                            $node->save();

                            $node->set('field_id_fiche', $xpath_fiche->getAttribute('id') );
                            $node->set('field_id_offre', $xpath_fiche->getElementsByTagName('offre_commerciale')->item(0)->getAttribute('id') );

                        }

                        if (isset($node)) {

                            $this->message .=  "Parsing content \n";
                            AxiomeContentImporter::parseContent($node, $fiche_dir . '/' . $file_fiche , $language, $this->message);

                            // création des familles
                            $this->axiome_fiche_remplissage_champs($node, $fiche_dir . '/' . $file_fiche);
                            $this->axiome_fiche_recherche_famille($node, $xpath_fiche);

                            $node->save();

                        }
                    }
                }
            }
        }

        else{
            $this->axiome_notification[] = "ERREUR | Pas de dossier pour la fiche : " . $xpath_fiche->getAttribute('id');
        }
    }


    /**
     * Crawl the axiome product XML file for
     * @param $node
     *   The node object reference
     *
     * @param $fiche
     *   The axiome product XML file string
     */
    private function axiome_fiche_remplissage_champs(&$node, $fiche){
        $dom = new DOMDocument("1.0");
        $dom->load($fiche);
        $xpath = new DOMXPath($dom);

        // short description
        $node->field_highlight = $xpath->query("/ficheoffre/Attributes/accroche")->item(0)->nodeValue;

        // metatags
        $axiome_data = unserialize($node->field_axiome_data->value);
        if(isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']['offre_name']))
        {
            $meta_title = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_banner']['Attributes']['offre_name'];
            $node->field_meta_title = mb_substr($meta_title,0, 55);
        }
        if(isset($axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title']))
        {
            $meta_description = $axiome_data['Children']['ruby_theme']['Children']['ruby_zone_header']['Attributes']['h1_title'];
            $node->field_meta_description = mb_substr($meta_description,0, 155);
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
        $familles = $xpath->getElementsByTagName('classement')->item(0)->getElementsByTagName('element_classement_group');
        foreach ($familles AS $famille){
            $classement_nom = strtolower(trim($famille->getAttribute('identifiant')));
            if ($classement_nom == "portfolio"
                || $classement_nom == "porfolio"
                || $classement_nom == "secteurs"
                || $classement_nom == "metiers"
            ) {
                $this->axiome_manage_taxo($node, $famille, $classement_nom);
            }
        }
    }

    private function axiome_manage_taxo($node, $famille, $classement_nom){
        $children_id = $famille->getElementsByTagName('element_classement_list')->item(0)->getElementsByTagName('element_classement_id');

        if ($classement_nom == "portfolio"
            || $classement_nom == "porfolio"){
            $taxo = $this->arborescence_famille;
            $nodeField = 'field_solution';
        }elseif ($classement_nom == "secteurs"){
            $taxo = $this->arborescence_secteur;
            $nodeField = 'field_industry';
        }elseif ($classement_nom == "metiers"){
            $taxo = $this->arborescence_metier;
            $nodeField = 'field_job_profile';
        }

        $this->message .= "AXIOME MANAGE TAXO $classement_nom \n";

        $tidParent = array();
        foreach($children_id as $child){
            foreach($taxo as $key => $value){
                if ($classement_nom == "portfolio"
                    || $classement_nom == "porfolio") {
                    if (in_array($child->nodeValue, $value['children']) && isset($value['tid'])) {
                        array_push($tidParent, $value['tid']);
                    }
                }elseif($classement_nom == "secteurs" || $classement_nom == "metiers"){
                    if ($child->nodeValue == $key && isset($value['tid'])) {
                        array_push($tidParent, $value['tid']);
                        // hack Axiome pour tid =161
                        if($classement_nom == "secteurs" && $value['tid'] == 161){
                            // on tague aussi avec Education (236) / Collectivités locales (164) / Smart cities (162)
                            array_push($tidParent, 236);
                            array_push($tidParent, 164);
                            array_push($tidParent, 162);
                        }
                    }
                }
            }
        }

        $this->message .= "TID pour $classement_nom : ".implode(",", $tidParent)." \n";

        if(count($tidParent) > 0){
            $node->set($nodeField, $tidParent);
            $node->save();
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
                // supprimé car référence pour les images catalog et banniere !
                /*$cmd = escapeshellcmd("rm -fR '$destination/$file'");
                exec($cmd);*/
                $cmd = "cp -R $source/$file/* $destination/$file/";
                exec($cmd);
            }
        }
    }

    /**
     * Verify if any taxonomy term has a node attached
     */
    private function axiome_verif_taxonomy_not_empty(){

        $query = \Drupal::database()->select('taxonomy_term_field_data', 't');
        $query->leftJoin('taxonomy_index', 'i', 'i.tid = t.tid');
        $query->fields('t', array('tid', 'name'));
        $query->groupBy('t.tid');
        $query->groupBy('t.name')
            ->condition('t.vid', AXIOME_TAXO_FAMILLE, '=');

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