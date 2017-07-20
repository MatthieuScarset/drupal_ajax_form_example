(function() {


    //declaration du plugin
    CKEDITOR.plugins.add('templating', {
        // Icône présent dans le répertoire "icons" à la racine du plugin
        icons: 'templating',
        lang: 'en,fr,ru',
        init: function(editor) {

            //create a command for our plugin called
            //when the command is executed it will open a dialog window.
            //we gave this new window the identifier of "templating"
            //"templating" can be use to identify the window
            editor.addCommand('templating', new CKEDITOR.dialogCommand('templating'));

            //add a button to the toolbar.
            //when the button is clicked it will execute the "templating" command
            //which will open the dialog window
            editor.ui.addButton('Templating', {
                label: 'Insert Templating Code',
                command: 'templating',
                toolbar: 'insert'
            });

            //the specific code to run when the dialog opens can be defined in
            //another file. "templating" is the dialog we registered above.
            //we also pass the path to the file to run.
            //CKEDITOR.dialog.add( 'templating', this.path + 'dialogs/templating.js' );
            //most examples I've found uses "this.path" to get the plugin directory
            //but i was getting an error with this approach
            //therefore i used CKEDITOR.plugins.getPath() to get the path to the plugin dir
            CKEDITOR.dialog.add('templating', CKEDITOR.plugins.getPath('templating') + 'dialogs/templating.js');

        }
    });    
})();
