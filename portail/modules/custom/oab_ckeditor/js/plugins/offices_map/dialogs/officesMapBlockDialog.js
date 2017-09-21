/*
 *   Plugin developed by CTRL+N.
 *
 *   LICENCE: GPL, LGPL, MPL
 *   NON-COMMERCIAL PLUGIN.
 *
 *   Website: https://www.ctrplusn.net/
 *   Facebook: https://www.facebook.com/ctrlplusn.net/
 *
 */
CKEDITOR.dialog.add('officesMapBlockDialog', function (editor) {
    var regionsArray = $.map(drupalSettings.regionsTab, function(value, index) {
        return [value];
    });
    var countriesArray = $.map(drupalSettings.countriesTab, function(value, index) {
        return [value];
    });

    var tab =  {
        title: editor.lang.offices_map.dialogTitle,
        minWidth: 400,
        minHeight: 80,
        contents: [
            {
                id: 'tab-basic',
                label: 'Basic Settings',
                // var offices = drupalSettings.countriesRegionsTab;
                elements: [
                    {
                        type: 'select',
                        items: regionsArray,
                        default: 'all',
                        id: 'regionChooser',
                        className: 'regionChooser',
                        label: 'Region',
                    },
                    {
                        type: 'select',
                        items: countriesArray,
                        default: 'all',
                        id: 'countryChooser',
                        className: 'countryChooser',
                        label: 'Country',
                    }
                ]
            }
        ],
        onOk: function () {
            /*
            var
                    dialog = this,
                    div_container = new CKEDITOR.dom.element('div'),
                    css = 'videoEmbed';
            // Set custom css class name
            if (dialog.getValueOf('tab-basic', 'css_class').length > 0) {
                css = dialog.getValueOf('tab-basic', 'css_class');
            }
            div_container.setAttribute('class', css);

            // Auto-detect if youtube, vimeo or dailymotion url
            var url = detect(dialog.getValueOf('tab-basic', 'url_video'));
            // Create iframe with specific url
            if (url.length > 1) {
                var iframe = new CKEDITOR.dom.element.createFromHtml('<iframe frameborder="0" width="560" height="349" src="' + url + '" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>');
                div_container.append(iframe);
                editor.insertElement(div_container);
            }*/
            editor.insertHtml( '||{"type":"block", "block_id":"offices_map_block"}||' );
        }
    };
    return tab;
});