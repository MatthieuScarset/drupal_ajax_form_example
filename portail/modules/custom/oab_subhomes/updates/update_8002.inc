<?php

use Drupal\field\Entity\FieldStorageConfig;
use Drupal\field\Entity\FieldConfig;
use Drupal\paragraphs\Entity\ParagraphsType;


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
// Création du paragraph pour le bouton et pour le carrousel
$paragraphs = [
    [
        'id'  => 'default_button',
        'label'   => 'Default button',
        'fields'  => [
            [
                'field_name' => 'field_button_color',
                'type'  => 'list_string',
            ],
            [
                'field_name' => 'field_button_text',
                'type'  => 'string',
            ],
            [
                'field_name' => 'field_link_button',
                'type'  => 'link',
            ]
        ]
    ],
    [
        'id'    => 'subhome_presse_carrousel',
        'label' => 'Subhome Presse Carrousel',
        'fields'    => [
            [
                'field_name'    => 'field_accroche',
                'type'          => 'string_long'
            ],
            [
                'field_name'    => 'field_button',
                'type'          => 'entity_reference_revisions'
            ],
            [
                'field_name'    => 'field_title',
                'type'          => 'string'
            ],
            [
                'field_name'    => 'field_visual',
                'type'          => 'entity_reference'
            ]
        ]
    ]
];

foreach ($paragraphs as $paragraph) {

// Création du paragraph puis rechargement de la conf
    $paragraph_type = ParagraphsType::load($paragraph['id']);
    if (empty($paragraph_type)) {
        $paragraph_type = ParagraphsType::create([
            'id' => $paragraph['id'],
            'label' => $paragraph['label'],
            'revision' => false
        ]);
        $paragraph_type->save();
    }
    oabt_YmlImport("paragraphs.paragraphs_type." . $paragraph['id'] . ".yml");

    foreach ($paragraph['fields'] as $field) {
        $field_storage = FieldStorageConfig::loadByName('paragraph', $field['field_name']);
        if (empty($field_storage)) {
            FieldStorageConfig::create(array(
                'field_name' => $field['field_name'],
                'entity_type' => 'paragraph',
                'type' => $field['type'],
            ))->save();
        }

        $storage_yml = "field.storage.paragraph." . $field['field_name'] . ".yml";
        oabt_YmlImport($storage_yml);

        $field_yml = "field.field.paragraph." . $paragraph['id'] . "." . $field['field_name'] . ".yml";
        oabt_YmlImport($field_yml);
    }


// Rechargement des confs view et form display du pargraph
    oabt_YmlImport('core.entity_form_display.paragraph.' . $paragraph['id'] . '.default.yml');
    oabt_YmlImport('core.entity_view_display.paragraph.' . $paragraph['id'] . '.default.yml');

}


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////
/// Création des fields pour l'entité press

$press_entity_id = "presse";
$entity_type = "subhome_entity";

$fields = [
    [
        'field_name'    => 'field_carrousel',
        'type'  => 'entity_reference_revisions'
    ],
    [
        'field_name' => 'field_corporate_aplat',
        'type' => 'list_string'
    ],
    [
        'field_name' => 'field_corporate_title',
        'type'  => 'string'
    ],
    [
        'field_name'    => 'field_corporate_url',
        'type'  => 'link'
    ],
    [
        'field_name'    => 'field_corporate_visual',
        'type'  => 'entity_reference'
    ],
    [
        'field_name'    => 'field_team_title',
        'type'  => 'string'
    ],
    [
        'field_name'    => 'field_team_visual',
        'type'  => 'entity_reference'
    ],
    [
        'field_name'    => 'field_team_button',
        'type'  => 'entity_reference_revisions'
    ],
    [
        'field_name' => 'field_afficher_bloc_notre_equipe',
        'type'  => 'boolean'
    ]
];


foreach ($fields as $field) {
    $field_storage = FieldStorageConfig::loadByName('subhome_entity', $field['field_name']);
    if (empty($field_storage)) {
        FieldStorageConfig::create(array(
            'field_name' => $field['field_name'],
            'entity_type' => 'subhome_entity',
            'type' => $field['type'],
        ))->save();
    }

    $storage_yml = "field.storage.subhome_entity." . $field['field_name'] . ".yml";
    oabt_YmlImport($storage_yml);

    $field_yml = "field.field.subhome_entity.presse." . $field['field_name'] . ".yml";
    oabt_YmlImport($field_yml);
}

// Raffraichissement des displays view et form
oabt_YmlImport('core.entity_view_display.subhome_entity.presse.default.yml');
oabt_YmlImport('core.entity_form_display.subhome_entity.presse.default.yml');

