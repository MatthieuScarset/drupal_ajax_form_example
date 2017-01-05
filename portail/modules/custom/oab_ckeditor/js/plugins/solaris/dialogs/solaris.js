


var solaris = '';
var icons = Array();
icons.push(['icon-3g', '3G']);
icons.push(['icon-4g', '4G']);
icons.push(['icon-4g_cam', '4G Cam']);
icons.push(['icon-4G_Cam__Live_80', '4G Cam Live']);
icons.push(['icon-4G_Cam_Camera_80', '4G Cam Camera']);
icons.push(['icon-4G_Cam_Inbox80', '4G Cam Inbox']);
icons.push(['icon-4G_Cam_Outbox_80', '4G Cam outbox']);
icons.push(['icon-4G_Cam_Rec_80', '4G Cam Rec']);
icons.push(['icon-4g_plus', '4G+']);
icons.push(['icon-4G-Cam-Compact', '4G Cam Compact']);
icons.push(['icon-1013_Reseau', 'Réseau']);
icons.push(['icon-about_event', 'About event']);
icons.push(['icon-Accessability', 'Accessability']);
icons.push(['icon-accessibility_cognition', 'Accessability cognition']);
icons.push(['icon-accessibility_dexterity', 'Accessability Dexterity']);
icons.push(['icon-accessibility_hearing', 'Accessability Hearing']);
icons.push(['icon-accessibility_mobility', 'Accessability Mobility']);
icons.push(['icon-accessibility_speech', 'Accessability Speech']);
icons.push(['icon-accessibility_vision', 'Accessability Vision']);
icons.push(['icon-accessory_headphones', 'Accessory Headphones']);
icons.push(['icon-accessory_shop', 'Accessory Shop']);
icons.push(['icon-Add', 'Add']);
icons.push(['icon-add_more', 'Add more']);
icons.push(['icon-Add_person', 'Add person']);
icons.push(['icon-address_book', 'Address book']);
icons.push(['icon-administrator', 'Administrator']);
icons.push(['icon-Adultcode', 'Adult code']);
icons.push(['icon-Adult', 'Adult']);
icons.push(['icon-advertising', 'Advertising']);
icons.push(['icon-aeroplane', 'Aeroplane']);

var solarisIcons = '';
for (var i = 0; i < icons.length; i++) {
    var newTitle = '';
    var ctr = 0;
    var title = icons[i][1];
    title = title.split(' ');
    for (var x = 0; x < title.length; x++) {
        ctr++;
        newTitle += ctr == 2 ? '<br />' : '';
        newTitle += title[x] + ' ';
        ctr = ctr == 2 ? 0 : ctr
    }
    solarisIcons += '<a href="#" onclick="klik(this);return false;" title="solaris ' + icons[i][0] + '"><span class="solaris ' + icons[i][0] + '"></span><div>' + newTitle + '</div></a>'
};
var currentIcon = '';
function klik(el) {
    document.getElementsByClassName('solarisClass')[0].getElementsByTagName('input')[0].value = el.getAttribute('title');
    a = document.getElementById('solaris');
    a = a.getElementsByTagName('a');
    for (i = 0; i < a.length; i++) {
        a[i].className = ''
    }
    el.className += 'active';
    currentIcon = el.firstChild;
};

function searchIcon(val) {
    var aydi = document.getElementById('solaris');
    var klases = aydi.getElementsByTagName('a');
    for (var i = 0, len = klases.length, klas, klasNeym; i < len; i++) {
        klas = klases[i];
        klasNeym = klas.getAttribute('title');
        if (klasNeym && klasNeym.indexOf(val) >= 0) {
            klas.style.display = 'block'
        } else {
            klas.style.display = 'none'
        }
    }
};

function setSpanColor(color) {
    el = document.getElementById('solaris');
    el = el.getElementsByTagName('span');
    for (i = 0; i < el.length; i++) {
        el[i].setAttribute('style', 'color:' + color)
    }
};

function setCheckboxes() {
    klases = '';
    klases += document.getElementsByClassName('spinning')[0].getElementsByTagName('input')[0].checked ? ' fa-spin' : klases;
    klases += document.getElementsByClassName('fixedWidth')[0].getElementsByTagName('input')[0].checked ? ' fa-fw' : klases;
    klases += document.getElementsByClassName('bordered')[0].getElementsByTagName('input')[0].checked ? ' fa-border' : klases;
    klases += ' ' + document.getElementsByClassName('flippedRotation')[0].getElementsByTagName('select')[0].value;
    el = document.getElementById('solaris');
    el = el.getElementsByTagName('span');
    for (i = 0; i < el.length; i++) {
        el[i].className = el[i].parentNode.getAttribute('title') + klases
    }
};

function in_array(needle, haystack) {
    for (var i in haystack) {
        if (haystack[i] == needle) return true
    }
    return false
};


    CKEDITOR.dialog.add('solaris', function(editor) {

        CKEDITOR.document.appendStyleSheet(CKEDITOR.plugins.getPath('solaris') + 'solaris/css/solaris.css');

        return {
            title: 'Solaris Icons Module' ,
            minWidth: CKEDITOR.env.ie ? 440 : 600,
            minHeight: 400,
            contents: [{
                id: 'insertSolaris',
                label: 'insertSolaris',
                elements: [{
                    type: 'hbox',
                    widths: ['50%', '50%'],
                    children: [{
                        type: 'hbox',
                        widths: ['75%', '25%'],
                        children: [{
                            type: 'text',
                            id: 'colorChooser',
                            className: 'colorChooser',
                            label: 'Color',
                            onKeyUp: function(e) {
                                setSpanColor(e.sender.$.value)
                            },
                            setup: function(widget) {
                                color = widget.data.color != '' ? widget.data.color : '#000000';
                                this.setValue(color);
                                setSpanColor(color)
                            },
                            commit: function(widget) {
                                widget.setData('color', this.getValue())
                            }
                        }, {
                            type: 'button',
                            label: 'Select',
                            style: 'margin-top:1.35em',
                            onClick: function() {
                                editor.getColorFromDialog(function(color) {
                                    document.getElementsByClassName('colorChooser')[0].getElementsByTagName('input')[0].value = color;
                                    setSpanColor(color)
                                }, this)
                            }
                        }]
                    }, {
                        type: 'text',
                        id: 'size',
                        className: 'size',
                        label: 'Size',
                        setup: function(widget) {
                            this.setValue(widget.data.size)
                        },
                        commit: function(widget) {
                            widget.setData('size', this.getValue())
                        }
                    }]
                }, /*{
                    type: 'hbox',
                    widths: ['25%', '25%', '25%', '25%'],
                    children: [{
                        type: 'checkbox',
                        id: 'spinning',
                        className: 'spinning cke_dialog_ui_checkbox_input',
                        label: 'Spinning',
                        value: 'true',
                        setup: function(widget) {
                            var klases = widget.data.class;
                            klases = klases.split(' ');
                            document.getElementsByClassName('spinning')[0].getElementsByTagName('input')[0].checked = in_array('fa-spin', klases) ? true : false;
                            setCheckboxes()
                        },
                        onClick: function() {
                            setCheckboxes()
                        }
                    }, {
                        type: 'checkbox',
                        id: 'fixedWidth',
                        className: 'fixedWidth cke_dialog_ui_checkbox_input',
                        label: 'Fixed Width',
                        value: 'true',
                        setup: function(widget) {
                            var klases = widget.data.class;
                            klases = klases.split(' ');
                            document.getElementsByClassName('fixedWidth')[0].getElementsByTagName('input')[0].checked = in_array('fa-fw', klases) ? true : false;
                            setCheckboxes()
                        },
                        onClick: function() {
                            setCheckboxes()
                        }
                    }, {
                        type: 'checkbox',
                        id: 'bordered',
                        className: 'bordered cke_dialog_ui_checkbox_input',
                        label: 'Bordered',
                        value: 'true',
                        setup: function(widget) {
                            var klases = widget.data.class;
                            klases = klases.split(' ');
                            document.getElementsByClassName('bordered')[0].getElementsByTagName('input')[0].checked = in_array('fa-border', klases) ? true : false;
                            setCheckboxes()
                        },
                        onClick: function() {
                            setCheckboxes()
                        }
                    }, {
                        type: 'select',
                        id: 'flippedRotation',
                        className: 'flippedRotation cke_dialog_ui_checkbox_input',
                        label: 'Flipping and Rotating',
                        items: [
                            ['Normal', ''],
                            ['Rotate 90', 'fa-rotate-90'],
                            ['Rotate 180', 'fa-rotate-180'],
                            ['Rotate 270', 'fa-rotate-270'],
                            ['Flip Horizontal', 'fa-flip-horizontal'],
                            ['Flip Vertical', 'fa-flip-vertical']
                        ],
                        setup: function(widget) {
                            this.setValue(widget.data.flippedRotation ? widget.data.flippedRotation : '')
                        },
                        commit: function(widget) {
                            widget.setData('flippedRotation', this.getValue())
                        },
                        onClick: function() {
                            setCheckboxes()
                        }
                    }]
                },*/ {
                    type: 'text',
                    id: 'solarisSearch',
                    className: 'solarisSearch cke_dialog_ui_input_text',
                    label: 'Search',
                    onKeyUp: function(e) {
                        searchIcon(e.sender.$.value)
                    }
                }, {
                    type: 'text',
                    id: 'solarisClass',
                    className: 'solarisClass',
                    style: 'display:none',
                    setup: function(widget) {
                        var klases = '';
                        if (widget.data.class != '') {
                            klases = widget.data.class;
                            klases = klases.split(' ');
                            // in_array('fa-border', klases) ? klases.splice(klases.indexOf('fa-border'), 1) : '';
                            // in_array('fa-fw', klases) ? klases.splice(klases.indexOf('fa-fw'), 1) : '';
                            // in_array('fa-spin', klases) ? klases.splice(klases.indexOf('fa-spin'), 1) : '';
                            // in_array('fa-rotate-90', klases) ? klases.splice(klases.indexOf('fa-rotate-90'), 1) : '';
                            // in_array('fa-rotate-180', klases) ? klases.splice(klases.indexOf('fa-rotate-180'), 1) : '';
                            // in_array('fa-rotate-270', klases) ? klases.splice(klases.indexOf('fa-rotate-270'), 1) : '';
                            // in_array('fa-flip-horizontal', klases) ? klases.splice(klases.indexOf('fa-flip-horizontal'), 1) : '';
                            // in_array('fa-flip-vertical', klases) ? klases.splice(klases.indexOf('fa-flip-vertical'), 1) : '';
                            klases = klases.join(' ')
                        }
                        this.setValue(klases)
                    },
                    commit: function(widget) {
                        var klases = '';
                        // klases += document.getElementsByClassName('spinning')[0].getElementsByTagName('input')[0].checked ? ' fa-spin' : klases;
                        // klases += document.getElementsByClassName('fixedWidth')[0].getElementsByTagName('input')[0].checked ? ' fa-fw' : klases;
                        // klases += document.getElementsByClassName('bordered')[0].getElementsByTagName('input')[0].checked ? ' fa-border' : klases;
                        // klases += ' ' + document.getElementsByClassName('flippedRotation')[0].getElementsByTagName('select')[0].value;
                        widget.setData('class', this.getValue() + klases)
                    }
                },
                    {
                    type: 'html',
                    html: '<link rel="stylesheet" type="text/css" href="' + CKEDITOR.plugins.getPath('solaris') + 'solaris/css/boosted2015.min.css" />'
                },
                    {
                    type: 'html',
                    html: '<div id="solaris">' + solarisIcons + '</div>'
                }]
            }],
            onOk: function() {

                el = document.getElementById('solaris');
                var iconSize = document.getElementsByClassName('size')[0].getElementsByTagName('input')[0].value;

                //editor.insertHtml('<span class=\"' + currentIcon.className + '\" style=\"color:' + el.getElementsByTagName('span')[0].style.color + '; font-size:' + iconSize + 'rem;\" ></span>');
                var glyphs = document.getElementById('solaris');
                glyphs = glyphs.getElementsByTagName('a');

                for (i = 0; i < glyphs.length; i++) {
                    glyphs[i].firstChild.className = glyphs[i].getAttribute('title');
                    glyphs[i].className = '';
                    glyphs[i].style.display = '';
                }


            }
        };
    });
