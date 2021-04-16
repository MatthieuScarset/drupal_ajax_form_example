<?php



#Reload des configs des subhome et du content type distributor
# Subhome > Suppression d'un filtre, ajout d'un tri
# Distributor > Ajout d'un wysiwyg

##Reload view subhomes
oabt_YmlImport('views.view.subhomes.yml');


##Reload Distributor
oabt_YmlImport("field.field.node.distributor.field_content.yml");
oabt_YmlImport("core.entity_form_display.node.distributor.default.yml");
oabt_YmlImport("core.entity_view_display.node.distributor.default.yml");
oabt_YmlImport("language.content_settings.node.distributor.yml");