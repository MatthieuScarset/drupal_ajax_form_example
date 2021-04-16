<?php

/**
 * Mise à jour des blocks rebond :
 *  - Activation du block Rebond-Product
 *  - Desactivation du linked Content
 *  - Remise en place des fields Rebonds Document & Page du site
 */

##Gestion du block Rebond-product
oabt_YmlImport('block.block.rebondproduct.yml');

##gestion du block "Linked Content"
oabt_YmlImport('block.block.views_block__linked_content_linked_content.yml');

##Config de tous les autres blocks  "auCasOu"
oabt_YmlImport('block.block.views_block__rebond_document_block_document.yml');
oabt_YmlImport('block.block.views_block__rebond_document_block_page_site_1.yml');
oabt_YmlImport('block.block.views_block__rebond_document_block_page_site_2.yml');

##Je remet la config de la view utilsée pour créer les blocks Rebond
oabt_YmlImport('views.view.rebond_document.yml');


##Réactivation des fields dans le form_display des contenus devant afficher ces blocks
oabt_YmlImport('core.entity_form_display.node.blog_post.default.yml');
oabt_YmlImport('core.entity_form_display.node.customer_story.default.yml');
oabt_YmlImport('core.entity_form_display.node.document.default.yml');
oabt_YmlImport('core.entity_form_display.node.magazine.default.yml');
oabt_YmlImport('core.entity_form_display.node.partner.default.yml');
oabt_YmlImport('core.entity_form_display.node.press_release.default.yml');
oabt_YmlImport('core.entity_form_display.node.simple_page.default.yml');
