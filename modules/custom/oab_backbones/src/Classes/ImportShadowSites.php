<?php
/**
 * Created by PhpStorm.
 * User: QWWT2837
 * Date: 18/10/2016
 * Time: 10:34
 */

namespace Drupal\oab_backbones\Classes;


use Drupal\Core\Messenger\MessengerInterface;
use Drupal\Core\Messenger\MessengerTrait;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Classe qui va faire l'import des Shadow Sites
 */
class ImportShadowSites {
    const IMPORT_DIRECTORY = 'public://backbones/sites/';

    /**
     * @var MessengerInterface
     */
    private $messenger;

    /**
     * ImportPerformanceData constructor.
     * @param MessengerInterface $messenger
     */
    public function __construct(MessengerInterface $messenger) {
      $this->messenger = $messenger;
    }


    public function executeImport($filename) {
        $file_name_complete = $this::IMPORT_DIRECTORY . $filename;
        if (file_exists($file_name_complete) && filesize($file_name_complete) > 0) {
            $lines = gzfile($file_name_complete);
            if (count($lines) > 100) {
                // Suppression de la ligne header
                unset($lines[0]);

                //constitution du tableau de sites présents dans le fichier
                $ss_in_file = array();
                foreach ($lines as $line) {
                    $parts = explode("\t", $line);
                    // 0:RowMd5Digest 1:IPShadowSiteCode 2:IPShadowSiteLabel
                    $ss_in_file[trim($parts[1])] = trim($parts[2]);
                }

                //récupération des sites en BDD
                $shadows_sites = new ShadowSites();
                $ss_in_db = $shadows_sites->getShadowSitesArrayFromDB();

                //Comparaison entre le fichier et la BDD : retourne les shadow sites à ajouter par le fichier
                $ss_to_update = array_diff($ss_in_file, $ss_in_db);

                if (count($ss_to_update) > 0) {
                    $shadows_sites->saveShadowSitesInDB($ss_to_update);
                }
                //Comparaison entre la BDD et le fichier pour les sites à supprimer
                $ss_to_delete = array_keys(array_diff_key($ss_in_db, $ss_in_file));

                if (count($ss_to_delete) > 0) {
                    $shadows_sites->deleteShadowSitesInDB($ss_to_delete);
                }
                //mise à jour de la variable de date du dernier import shadows_sites
                $timestamp = time();
                \Drupal::state()->set('bbp_last_import_ss', $timestamp);

                $this->messenger->addMessage("The file " . $filename . "has been imported successfully", 'status', TRUE);

            } else {
                $this->messenger->addError(t("File has to few lines"), FALSE);
            }
        } else {
            $this->messenger->addError(t("File doesn't exist"), FALSE);
        }
    }
}
