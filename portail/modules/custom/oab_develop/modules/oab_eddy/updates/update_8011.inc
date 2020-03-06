<?php

use \Drupal\paragraphs\Entity\ParagraphsType;

/* field.storage.paragraph.field_home_accroche.yml
paragraphs.paragraphs_type.home_caroussel.yml
field.storage.node.field_caroussel_header.yml */

/***************************************
 * *************************************
 *
 *  ETAPE 1 : Création de mon paragraph
 *
 * *************************************
 * *************************************
 */

/**** 1.A - Création de l'entité ******/

$paragraph_data = [
    'langcode' => 'en',
    'id' => 'home_caroussel',
    'label' => 'Home Caroussel'
];

$paragraph = ParagraphsType::load($paragraph_data['id']);

if (null == $paragraph) {
    $paragraph = ParagraphsType::create($paragraph_data);
}
oabt_YmlImport('paragraphs.paragraphs_type.home_caroussel.yml');


/**** 1.B - Création des fields ******/

// Field Accroche
createField("field_home_accroche", 'home_caroussel','Accroche', 'text_long', 'false', 'paragraph');


oabt_YmlImport('field.storage.paragraph.field_home_accroche.yml');
oabt_YmlImport('field.field.paragraph.home_caroussel.field_home_accroche.yml');


// Fiemld Bouton
oabt_YmlImport('field.field.paragraph.home_caroussel.field_button.yml');



/**** 1.C - Affichage des fields : view et form ******/

oabt_YmlImport('core.entity_form_display.paragraph.home_caroussel.default.yml');
oabt_YmlImport('core.entity_view_display.paragraph.home_caroussel.default.yml');


/***************************************
 * *************************************
 *
 *  ETAPE 2 : Modification de type de contenu Homepage
 *
 * *************************************
 * *************************************
 */


//Création du field de la home

/**** 2.A - Affichage des fields : view et form ******/
createField("field_caroussel_header", 'homepage','Caroussel Header', 'entity_reference_revisions');
oabt_YmlImport('field.storage.node.field_caroussel_header.yml');
oabt_YmlImport('field.field.node.homepage.field_caroussel_header.yml');


/**** 2.B - Affichage des fields : view et form ******/
oabt_YmlImport('core.entity_form_display.node.homepage.default.yml');
oabt_YmlImport('core.entity_view_display.node.homepage.full.yml');


