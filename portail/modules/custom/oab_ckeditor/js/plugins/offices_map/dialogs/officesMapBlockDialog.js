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
                        id: 'region_chooser',
                        className: 'regionChooser',
                        label: 'Region',
                    },
                    {
                        type: 'select',
                        items: countriesArray,
                        default: 'all',
                        id: 'country_chooser',
                        className: 'countryChooser',
                        label: 'Country',
                    }
                ]
            }
        ],
        onOk: function () {
            var dialog = this;
            var region_id = 'all';
            var country_id = 'all';

            if (dialog.getValueOf('tab-basic', 'region_chooser').length > 0) {
                region_id = dialog.getValueOf('tab-basic', 'region_chooser');
            }
            if (dialog.getValueOf('tab-basic', 'country_chooser').length > 0) {
                country_id = dialog.getValueOf('tab-basic', 'country_chooser');
            }

            editor.insertHtml( '||{"type":"block", "block_id":"offices_map_block", "region_id":"' + region_id + '", "country_id":"'+ country_id + '"}||' );
        }
    };
    return tab;
});