<?php

/**
 * Mise à jour de la taxo thématique
 */

$bundles = [
    'blog_post',
    'customer_story',
    'custom_page',
    'industry',
    'magazine',
    'press_kit',
    'press_release',
    'product',
    'simple_page',
    'solution'
];

foreach ($bundles as $bundle) {
    $field = FieldConfig::loadByName('node', $bundle, 'field_blog_thematic');
    if (empty($field)) {
        $config_array = array(
            'field_name' =>  'field_blog_thematic',
            'entity_type' => 'node',
            'bundle' => $bundle,
            'required' => false,
        );
        FieldConfig::create($config_array)->save();
    }

    oabt_YmlImport('field.field.node.' . $bundle . '.field_blog_thematic.yml');
    oabt_YmlImport('core.entity_form_display.node.' . $bundle . '.default.yml');
    oabt_YmlImport('core.entity_view_display.node.' . $bundle . '.default.yml');
}


/**
 * RAF :
 *      * Checker pour document => Si on ajouter ce field à document, il faudra peut etre supprimer le field existant et la taxo sur lequel il
 *  pointe (Document Thematic) + MAJ de la view subhome pour remplacer le filtre
 *      * MAJ des termes du voca Blog Thematic, voir pour renommer le voca
 */
