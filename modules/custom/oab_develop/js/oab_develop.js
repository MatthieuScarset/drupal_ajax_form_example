function flash_message(text, type, delay) {
    activateOverlay();
    var timingFade = 500; // 1s
    // valeurs par defaut

    if (typeof (type) === 'undefined')
        type = "";
    if (typeof (delay) === 'undefined')
        delay = 10000;
    if (type == "success" || type == "error" || type == "danger" || type == "info" || type == "base") {
        var alerttype = " alert-" + type;
    } else {
        alerttype = "";
    }

    // ajout pour désactiver la roue quand le message affiché est une erreur
    if (type == "error") {
        jQuery(".img_wait_overlay").hide();
    }
    // on créé la popin si elle n existe pas
    if (jQuery("#flashmessage").length == 0) {
        jQuery("body").append('<div id="flashmessage" role="alert" aria-live="assertive" class="alert' + alerttype + '"><div class="text"></div></div>');
    }else{
        if (!jQuery("#flashmessage").hasClass( alerttype )){
            jQuery("#flashmessage").addClass(alerttype);
            jQuery("#flashmessage").removeClass("alert-base");
        }
    }

    if (jQuery("#flashmessage").hasClass("alert-error")){
        if (jQuery("#flashmessage").hasClass("alert-success")){
            jQuery("#flashmessage").removeClass("alert-error");
        }
    }

    jQuery("#flashmessage .text").html(text);
    // croix pour fermer
    if (jQuery("#flashmessage .close").length == 0) {
        jQuery("#flashmessage").prepend('<div class="close">X</div>');
    }
    // fadein au démarrage
    jQuery("#flashmessage").fadeIn(timingFade, function() {
        if (delay != false) {
            jQuery(this).delay(delay).fadeOut(timingFade, function() {
                jQuery(this).remove();
                jQuery(".wait_overlay").remove();
            });
        }
    });

    // bouton fermer
    jQuery("#flashmessage .close").click(function() {
        jQuery(this).parent().stop();
        jQuery(this).parent().fadeOut(1000, function() {
            jQuery("#flashmessage").remove();
            jQuery(".wait_overlay").remove();
        });
    });
    // centrer popin
    var marginLeft = -jQuery("#flashmessage").width() / 2 + "px";
    var marginTop = -jQuery("#flashmessage").height() / 2 + "px";
    jQuery("#flashmessage").css("margin-left", marginLeft);
    jQuery("#flashmessage").css("margin-top", marginTop);
    jQuery("#flashmessage .text").focus();
}

function activateOverlay() {
    if (jQuery(".wait_overlay").size() < 1) {
        jQuery("body").append("<div class='wait_overlay'></div>");
        jQuery(".wait_overlay").append("<div class='img_wait_overlay'></div>");
        jQuery("#overlay_message").clone().appendTo('.img_wait_overlay');
        jQuery(".img_wait_overlay #overlay_message").removeClass("hide");
    }
}

function deactivateOverlay() {
    jQuery(".wait_overlay").remove();
}
