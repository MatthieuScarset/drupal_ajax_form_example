<?php

/**
 * Ajout des metatags nécessaires au partage Fb, Twitter, LIn
 */
oabt_YmlImport('metatag.metatag_defaults.node.yml');
oabt_YmlImport('metatag.metatag_defaults.node__homepage.yml');
oabt_YmlImport('metatag.metatag_defaults.node__industry.yml');
oabt_YmlImport('metatag.metatag_defaults.node__product.yml');
oabt_YmlImport('metatag.metatag_defaults.node__solution.yml');

## Ajout d'un field "Visuel pour la subhome" au template full_html
oabt_YmlImport('field.field.node.full_html.field_visual.yml');
oabt_YmlImport('core.entity_form_display.node.full_html.default.yml');
oabt_YmlImport('core.entity_view_display.node.full_html.default.yml');