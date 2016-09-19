var templates_path = '/modules/custom/oab_ckeditor/images/';

var templates = [];
var oab_templates = drupalSettings.oab_templates;
for (var i = 0; i < oab_templates.length; i++) {
    templates.push({
        title: oab_templates[i].title,
        description: oab_templates[i].description,
        image: oab_templates[i].image,
        html: oab_templates[i].html
    });
}


CKEDITOR.addTemplates('default', {
    imagesPath: templates_path,
    templates: templates
});
