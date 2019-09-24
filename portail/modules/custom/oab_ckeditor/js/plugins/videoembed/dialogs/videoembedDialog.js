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
CKEDITOR.dialog.add('videoembedDialog', function (editor) {
    return {
        title: editor.lang.videoembed.title,
        minWidth: 400,
        minHeight: 80,
        contents: [
            {
                id: 'tab-basic',
                label: 'Basic Settings',
                elements: [
                    {
                        type: 'html',
                        html: '<p>' + editor.lang.videoembed.onlytxt + '</p>'
                    },
                    {
                        type: 'text',
                        id: 'url_video',
                        label: 'URL (ex: https://www.youtube.com/watch?v=EOIvnRUa3ik)',
                        validate: CKEDITOR.dialog.validate.notEmpty(editor.lang.videoembed.validatetxt)
                    },
                    {
                        type: 'text',
                        id: 'css_class',
                        label: editor.lang.videoembed.input_css
                    },
                    {
                      type: 'checkbox',
                      id: 'is_modal',
                      label: editor.lang.videoembed.is_modal
                    }
                ]
            }
        ],
        onOk: function () {
            var
                    dialog = this,
                    div_container = new CKEDITOR.dom.element('div'),
                    css = 'videoEmbed',
                    is_modal = dialog.getValueOf('tab-basic', 'is_modal');

            // Set custom css class name
            if (dialog.getValueOf('tab-basic', 'css_class').length > 0) {
                css = dialog.getValueOf('tab-basic', 'css_class');
            }
            div_container.setAttribute('class', css);

            // Auto-detect if youtube, vimeo or dailymotion url
            var url = detect(dialog.getValueOf('tab-basic', 'url_video'));
            // Create iframe with specific url
            if (url.length > 1) {
              let html = "";
              if (is_modal) {
                html = htmlWithModal(url);
              } else {
                html = htmlWithoutModal(url);
              }
              div_container.appendHtml(html);
              editor.insertElement(div_container);
            }
        }
    };
});

function htmlWithModal(url) {
  let html = "";
  let random_numb =  Math.random();
  random_numb = Math.floor(random_numb * 10000);
  let randomizedId = "embedVideoModal-" + random_numb;
  console.log(drupalSettings);
  let nom_image = "";
  nom_image = '/'+ drupalSettings.oab_ckeditor.path + '/js/plugins/videoembed/icons/play_icon_banner.png';

  html = "<!-- Button trigger modal -->" +
    "<div class=\"row\">" +
    "     <button type=\"button\" class=\"btn btn-modal-video\" data-toggle=\"modal\" data-target=\"#" + randomizedId + "\">" +
    "         <img src=\""+ nom_image + "\" aria-hidden=\"true\"" +
    "     </button>" +
    "</div>" +

    " <div class=\"modal fade ckeditor-embed-video\" id=\"" + randomizedId + "\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myModalLabel\"\n" +
    "     aria-hidden=\"true\">" +
    "  <div class=\"modal-dialog modal-lg modal-dialog-centered\" role=\"document\">" +
    "      <div class=\"text-right\">" +
    "          <button type=\"button\" class=\"btn btn-primary btn-rounded btn-md ml-4\"" +
    "              data-dismiss=\"modal\">Close</button>" +
    "     </div>" +
    "      <div class=\"modal-body mb-0 p-0\">" +
    "        <div class=\"embed-responsive embed-responsive-16by9 z-depth-1-half\">" +
                 htmlWithoutModal(url)+
    "        </div>" +
    "      </div>" +
    "  </div>" +
    "</div>";

  return html;
}

function htmlWithoutModal(url) {
  return '<iframe frameborder="0" width="560" height="349" src="' + url + '" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>';
}


// Detect platform and return video ID
function detect(url) {
    var embed_url = '';
    // full youtube url
    if (url.indexOf('youtube') > 0) {
        id = getId(url, "?v=", 3);
        if (id.indexOf('&list=') > 0) {
            lastId = getId(id, "&list=", 6);
            return embed_url = 'https://www.youtube.com/embed/' + id + '?list=' + lastId;
        }
        return embed_url = 'https://www.youtube.com/embed/' + id;
    }
    // tiny youtube url
    if (url.indexOf('youtu.be') > 0) {
        id = getId(url);
        // if this is a playlist
        if (id.indexOf('&list=') > 0) {
            lastId = getId(id, "&list=", 6);
            return embed_url = 'https://www.youtube.com/embed/' + id + '?list=' + lastId;
        }
        return embed_url = 'https://www.youtube.com/embed/' + id;
    }
    // full vimeo url
    if (url.indexOf('vimeo') > 0) {
        id = getId(url);
        return embed_url = 'https://player.vimeo.com/video/' + id + '?badge=0';
    }
    // full dailymotion url
    if (url.indexOf('dailymotion') > 0) {
        // if this is a playlist (jukebox)
        if (url.indexOf('/playlist/') > 0) {
           id = url.substring(url.lastIndexOf('/playlist/') + 10, url.indexOf("/1#video="));
           console.log(id);
            return embed_url = 'https://www.dailymotion.com/widget/jukebox?list[]=%2Fplaylist%2F' + id + '%2F1&&autoplay=0&mute=0';
        } else {
            id = getId(url);
        }
        return embed_url = 'https://www.dailymotion.com/embed/video/' + id;
    }
    // tiny dailymotion url
    if (url.indexOf('dai.ly') > 0) {
        id = getId(url);
        return embed_url = 'https://www.dailymotion.com/embed/video/' + id;
    }
    return embed_url;
}

// Return video ID from URL
function getId(url, string = "/", index = 1) {
    return url.substring(url.lastIndexOf(string) + index, url.length);
}
