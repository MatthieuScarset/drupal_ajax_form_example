<?php

$field_name = "field_claim";
$bundle = 'homepage';
$label = "Claim";

createField($field_name, $bundle, $label);

oabt_YmlImport('field.storage.node.field_claim.yml');
oabt_YmlImport('field.field.node.homepage.field_claim.yml');

oabt_YmlImport('core.entity_form_display.node.homepage.default.yml');
oabt_YmlImport('core.entity_view_display.node.homepage.full.yml');
