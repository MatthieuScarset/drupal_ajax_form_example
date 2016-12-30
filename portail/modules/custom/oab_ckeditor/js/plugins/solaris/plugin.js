

(function() {

    //declaration du plugin
    CKEDITOR.plugins.add('solaris', {
        // Icône présent dans le répertoire "icons" à la racine du plugin
        icons: 'solaris',
        init: function(editor) {

            editor.addCommand('solaris', new CKEDITOR.dialogCommand('solaris'));


            editor.ui.addButton('Solaris', {
                label: 'Insert Solaris Icon',
                command: 'solaris',
                toolbar: 'insert'
            });

            CKEDITOR.dialog.add('solaris', CKEDITOR.plugins.getPath('solaris') + 'dialogs/solaris.js');

        }
    });
})();
