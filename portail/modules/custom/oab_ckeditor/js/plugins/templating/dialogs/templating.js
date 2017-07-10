
var components = drupalSettings.oab_templating_components;
var mEditor = null;
var isCreated = false;
var localNavSubmenuTitle = 'Navigation';


function createTemplateComponent(containerId, component) {

    var item = CKEDITOR.dom.element.createFromHtml('<a href="javascript:void(0)" tabIndex="-1" role="option" >' +
        '<div class="cke_tpl_item"></div>' +
        '</a>');

    // Build the inner HTML of our new item DIV.
    var html = '<table class="cke_tpl_preview" role="presentation"><tr>';

    if (component.image) {
        html += '<td class="cke_tpl_preview_img"><img src="' +
            CKEDITOR.getUrl(component.image) + '"' +
            (CKEDITOR.env.ie6Compat ? ' onload="this.width=this.width"' : '') + ' alt="" title=""></td>';
    }

    html += '<td style="white-space:normal;"><span class="cke_tpl_title">' + component.label + '</span><br/>';
    html += '</td></tr></table>';

    item.getFirst().setHtml(html);
    item.on('click', function() {
        // insertComponentTemplate(template.html);
        insertComponentTemplate(containerId, component.file);
    });
    return item;

}

// Insert the specified template content into editor.
// @param {Number} index
function insertComponentTemplate(containerId, html) {

    var dialog = CKEDITOR.dialog.getCurrent();
    var isReplace = dialog.getValueOf('tab-' + containerId, 'components-chkbox-' + containerId);

    // replace title menu local nav
    html = html.replace("data-title-mobile='submenu'", "data-title-mobile='"+localNavSubmenuTitle+"'");
    if (isReplace) {
        mEditor.fire('saveSnapshot');
        // Everything should happen after the document is loaded (#4073).
        mEditor.setData(html, function() {
            dialog.hide();

            // Place the cursor at the first editable place.
            var range = mEditor.createRange();
            range.moveToElementEditStart(mEditor.editable());
            range.select();
            setTimeout(function() {
                mEditor.fire('saveSnapshot');
            }, 0);
        });
    } else {
        mEditor.insertHtml(html);
        dialog.hide();
    }
}

function buildTabs(components) {
    var result = [];

    for (var i = 0; i < components.length; i++) {
        var component = components[i];
        result.push({
            id: 'tab-' + component.id,
            label: component.label,
            title: component.title,
            elements: [{
                id: 'components-chkbox-' + component.id,
                type: 'checkbox',
                label: 'Replace current content',
                default: false
            }, {
                id: 'components-list-' + component.id,
                type: 'html',
                focus: i == 0,
                html: '<div class="cke_tpl_list" tabIndex="-1" role="listbox"> </div>'
            }]
        })
    }

    return result;
}

function buildElements(container, component) {
    container.setHtml('');
    var items = component.items;
    for (var i = items.length - 1; i >= 0; i--) {
        var el = createTemplateComponent(component.id, items[i]);
        container.append(el);
    }
}

(function() {

    CKEDITOR.dialog.add('templating', function(editor) {
        // Load skin at first.
        mEditor = editor;
        var plugin = CKEDITOR.plugins.get('templating');
        CKEDITOR.document.appendStyleSheet(CKEDITOR.getUrl(plugin.path + 'dialogs/templating.css'));
        var lang = editor.lang.templating;
        localNavSubmenuTitle = lang.localNavSubmenu;

        return {
            title: 'Templating Modules' ,/*editor.lang.templating.title,*/
            minWidth: CKEDITOR.env.ie ? 440 : 800,
            minHeight: 400,
            //Construire les onglets dynamiquement en fonction du fichier components.json
            contents: buildTabs(components),
            buttons: [CKEDITOR.dialog.cancelButton],
            onShow: function() {
                if (!isCreated) {
                    isCreated = true;
                    for (var i = 0; i < components.length; i++) {
                        var component = components[i];
                        var componentsList = this.getContentElement('tab-' + component.id, 'components-list-' + component.id);
                        var container = componentsList.getElement();
                        buildElements(container, component);
                    }
                }
            },
            onHide: function() {
                isCreated = false;
            }
        };
    });
})();
