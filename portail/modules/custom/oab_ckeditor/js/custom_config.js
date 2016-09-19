(function() {
    CKEDITOR.plugins.addExternal('basewidget', '/modules/custom/oab_ckeditor/js/plugins/basewidget/', 'plugin.js');
})();

CKEDITOR.editorConfig = function(config) {
    CKEDITOR.config.extraPlugins = 'layoutmanager,fontawesome,basewidget, templating';

    config.templates_files = [
        drupalSettings.path.baseUrl + 'modules/custom/oab_ckeditor/js/custom_templates.js'
    ];

    config.templates_replaceContent = false;

    CKEDITOR.dtd.$removeEmpty['span'] = false;
    CKEDITOR.dtd.$removeEmpty.i = false;
    CKEDITOR.config.removeFormatTags = "b,big,cite,code,del,dfn,em,font,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,u,var";
    delete CKEDITOR.config.coreStyles_italic;
};
