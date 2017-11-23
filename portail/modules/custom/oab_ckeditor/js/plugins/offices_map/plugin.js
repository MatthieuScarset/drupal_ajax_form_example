

(function() {

    //declaration du plugin
    CKEDITOR.plugins.add('offices_map', {
        icons: 'picto-carte',
        lang: 'fr,en,ru',
        version: 1.1,
        init: function(editor) {
            /*
            editor.addCommand( 'offices_map_command', {
                exec : function( editor ) {
                    //here is where we tell CKEditor what to do.
                    editor.insertHtml( '<p>test</p>' );
                }
            });
            */
            // Command
            editor.addCommand('offices_map_command', new CKEDITOR.dialogCommand('officesMapBlockDialog'));
            editor.ui.addButton( 'OfficesMap', {
                label: editor.lang.offices_map.buttonTitle,
                command: 'offices_map_command',
                icon: this.path + 'icons/picto-carte.png'
            });

            // Dialog window
            CKEDITOR.dialog.add('officesMapBlockDialog', this.path + 'dialogs/officesMapBlockDialog.js');
        }
    });
})();
