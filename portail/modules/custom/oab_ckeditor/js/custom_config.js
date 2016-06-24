
CKEDITOR.editorConfig = function( config )
{
	config.templates_files =
		[
		 drupalSettings.path.baseUrl + 'modules/custom/oab_ckeditor/js/custom_templates.js'
		];
	
	config.templates_replaceContent = false;

  CKEDITOR.dtd.$removeEmpty['span'] = false;
  CKEDITOR.dtd.$removeEmpty.i = false;
};
