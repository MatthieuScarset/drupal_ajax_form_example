CKEDITOR.editorConfig = function(config) {
    CKEDITOR.config.extraPlugins = 'layoutmanager, fontawesome, templating, embed, embedbase, notificationaggregator, notification, toolbar, button, solaris, panel, panelbutton, colorbutton, font, lineheight';

    config.templates_files = [
        drupalSettings.path.baseUrl + 'modules/custom/oab_ckeditor/js/custom_templates.js'
    ];

    config.templates_replaceContent = false;

    CKEDITOR.dtd.$removeEmpty['span'] = false;
    CKEDITOR.dtd.$removeEmpty.i = false;
    CKEDITOR.config.removeFormatTags = "b,big,cite,code,del,dfn,em,font,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,u,var";
    delete CKEDITOR.config.coreStyles_italic;

    CKEDITOR.config.embed_provider = '//iframe.ly/api/oembed?url={url}&callback={callback}&api_key=999d16e5ad074182bbe882';
    /*CKEDITOR.config.removePlugins = 'drupallink';*/

    Object.assign(CKEDITOR.dtd.a, { div: 1, p: 1 });
};
