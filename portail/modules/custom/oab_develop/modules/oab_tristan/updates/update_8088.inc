<?php

use Drupal\node\Entity\Node;
use Drupal\field\Entity\FieldConfig;
use Drupal\taxonomy\Entity\Term;
use Drupal\oab_akamai\Form\OabAkamaiForm;

/**
 * @param $sandbox : XXXXX
 * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
 * @throws \Drupal\Component\Plugin\Exception\PluginNotFoundException
 * @throws \Drupal\Core\Entity\EntityStorageException
 *
 * Commentaire de fonction a ajouter par Tristan
 */
function processUpdateWithSandbox_8088(&$sandbox) {

    $nodes_type = ['blog_post', 'full_html', 'page_simple', 'document', 'magazine'];

    // Lors du premier passage du batch, initialisation des variables + création du field et MAJ des termes
    $insight_vid = "thematic";
    if (!isset($sandbox['total'])) {

        // Ajout du champ aux elements
        $bundles = ["custom_page", "press_kit", "press_release", "product"];

        foreach ($bundles as $bundle) {
            $field = FieldConfig::loadByName('node', $bundle, 'field_insight');
            if (empty($field)) {
                $config_array = array('field_name' => 'field_insight', 'entity_type' => 'node', 'bundle' => $bundle, 'required' => false,);
                FieldConfig::create($config_array)->save();
            }

            oabt_YmlImport('field.field.node.' . $bundle . '.field_insight.yml');
            oabt_YmlImport('core.entity_form_display.node.' . $bundle . '.default.yml');
            oabt_YmlImport('core.entity_view_display.node.' . $bundle . '.default.yml');
        }

        // Suppression de tous les anciens termes
        /** @var Drupal\taxonomy\Entity\Term[] $terms */
        $terms = \Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree($insight_vid, 0, NULL, TRUE);

        foreach ($terms as $term) {
            $term->delete();
        }

        // Ajout des nouveaux termes
        $new_terms = [
            'en' => [
                "Big Data",
                "Cloud",
                "Collaboration",
                "Connectivity",
                "Customer Experience",
                "Digital Transformation",
                "IoT",
                "Mobility",
                "News",
                "Security"],
            'fr' => [
                'Cloud',
                'Collaboration',
                'Consulting',
                'E-Santé',
                'Innovation',
                'IoT & Data Analytics',
                'Mobile',
                'Relation client',
                'Réseaux',
                'Sécurité'],
            'ru' => [
                'Безопасность',
                'Голосовые услуги',
                'Индустрия',
                'Корпоративные сети',
                'Мобильность',
                'Облачные вычисления',
                'Унифицированные коммуникации',
                'Управление ИТ']
        ];

        foreach ($new_terms as $lang => $terms) {
            foreach ($terms as $term_label) {
                /** @var Drupal\taxonomy\Entity\Term $term */
                $term = Term::create(['vid' => $insight_vid, 'name' => $term_label, 'langcode' => $lang]);
                $term->save();
            }
        }

        // Rechargement de la vue subhome pour remplacer tous les filtres "Thematic" par un filtre qui pointe
        // sur le nouveau field
        oabt_YmlImport('views.view.subhomes.yml');

        // Pour Blog, Page Full HTML et Page Simple, je transfère les données du field field_blog_thematic au field
        $query = \Drupal::entityQuery('node')
            ->condition('type', $nodes_type, 'IN');
        $query->condition(
            $query->orConditionGroup()
                ->exists('field_blog_thematic')
                ->exists('field_document_thematic')
                ->exists('field_magazine_thematic')
        );
        $nids = $query->execute();

        $sandbox['total'] = count($nids);
        $sandbox['current'] = 0;
        $sandbox['last_nid'] = 0;
        \Drupal::messenger()->addStatus($sandbox['total'] . ' nodes to process.');

    } else {

        $nodes_per_batch = 100;

        // Pour Blog, Page Full HTML et Page Simple, je transfère les données du field field_blog_thematic au field
        $query = \Drupal::entityQuery('node')->condition('type', $nodes_type, 'IN');
        $query->condition(
            $query->orConditionGroup()
                ->exists('field_blog_thematic')
                ->exists('field_document_thematic')
                ->exists('field_magazine_thematic')
        );
        $query->range(0, $nodes_per_batch);
        $query->sort('nid', 'ASC');
        $query->condition('nid', isset($sandbox['last_nid']) ? $sandbox['last_nid'] : 0, '>');

        $ids = $query->execute();
        $nodes = Node::loadMultiple($ids);
        $count = 0;

        $toUpdate = [];

        /** @var Node $node */
        foreach ($nodes as $node) {

            //$node = Node::load($id);

            $terms_to_set = [];


            $field_name = "";
            switch ($node->bundle()) {
                case 'document':
                    $field_name = 'field_document_thematic';
                    break;
                case 'magazine':
                    $field_name = 'field_magazine_thematic';
                    break;
                default:
                    $field_name = 'field_blog_thematic';
                    break;
            }

            $field_value = $node->get($field_name)->getValue();

            foreach ($field_value as $value) {
                $term_thematic = Term::load($value['target_id']);

                $term_name = $term_thematic->getName();

                // Cloud est appelé Cloud Computing dans le voca blog thematic
                if ($term_name == 'Cloud Computing') {
                    $term_name = 'Cloud';
                }

                $terms = \Drupal::entityTypeManager()
                    ->getStorage('taxonomy_term')
                    ->loadByProperties(['name' => $term_name, 'vid' => $insight_vid]);
                $new_term = reset($terms);

                if ($new_term !== null && $new_term !== false) {
                    $terms_to_set[] = $new_term;
                }
            }


            if ($node->hasField('field_insight')) {
                /* Pour garder la date de MAJ initiale ;) */
                $toUpdate[] = ['nid' => $node->id(), 'changed' => $node->getChangedTime()];

                $node->set('field_insight', $terms_to_set);
                $node->save();

                $count++;
            }
            $sandbox['current']++;
            $sandbox['last_nid'] = $node->id();

        }

        // A la fin, j'update les dates de MAJ des contenus pour garder l'initiale (pour eviter que l'ordre dans les subhomes soient modifiés
        // et que ca remonte d'anciens contenus)
        foreach ($toUpdate as $row) {
            $connection = \Drupal::database();
            $connection->update('node_field_data')
                ->fields(['changed' => $row['changed']])
                ->condition('nid', $row['nid'])->execute();
        }

    }
    if ($sandbox['total'] == 0) {
        $sandbox['#finished'] = 1;
    } else {
        $sandbox['#finished'] = ($sandbox['current'] / $sandbox['total']);
    }

    // Fin : retour du message d'info
    if ($sandbox['#finished'] == 1 || $sandbox['#finished'] == true) {
        \Drupal::messenger()->addStatus($sandbox['current'] . ' nodes processed. ' . $count . ' mis à jour. nid actuel : ' . $sandbox['last_nid']);
    }

}