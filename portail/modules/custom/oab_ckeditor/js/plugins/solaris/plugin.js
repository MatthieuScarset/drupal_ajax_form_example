

(function() {

    //declaration du plugin
    CKEDITOR.plugins.add('solaris', {
        // Icône présent dans le répertoire "icons" à la racine du plugin
        icons: 'solaris',
        lang: 'en,fr,ru',
        init: function(editor) {

            /*editor.addCommand('solaris', new CKEDITOR.dialogCommand('solaris'));


             editor.ui.addButton('Solaris', {
             label: 'Insert Solaris Icon',
             command: 'solaris',
             toolbar: 'insert'
             });*/

            editor.widgets.add('Solaris', {
                button: 'Insert Solaris Icon',
                template: '<span class="" style=""></span>',
                dialog: 'solaris',
                allowedContent: 'span(!solaris){style}',
                upcast: function(element) {
                    return element.name == 'span' && element.hasClass('solaris')
                },
                init: function() {
                    this.setData('class', this.element.getAttribute('class'));
                    this.setData('color', this.element.getStyle('color'));
                    this.setData('size', this.element.getStyle('font-size'))
                },
                data: function() {
                    var istayl = '';
                    this.element.setAttribute('class', this.data.class);
                    istayl += this.data.color != '' ? 'color:' + this.data.color + ';' : '';
                    istayl += this.data.size != '' ? 'font-size:' + parseInt(this.data.size) + 'rem;' : '';
                    istayl != '' ? this.element.setAttribute('style', istayl) : '';
                    istayl == '' ? this.element.removeAttribute('style') : ''
                }
            });

            CKEDITOR.dialog.add('solaris', CKEDITOR.plugins.getPath('solaris') + 'dialogs/solaris.js');

        }
    });
})();
