var rtime_oab_develop_theme = new Date(1, 1, 2000, 12,00,00);
var timeout_oab_develop_theme = false;
var delta_oab_develop_theme = 200;
var last_size="";

(function($, w, d) {
    $(d).ready(function() {
        /*gestion du no-js*/
        $("body").removeClass("no-js");
        check_body_size();
        $('html').trigger("htmlCharged");
        $( window ).resize(function() {
            rtime_oab_develop_theme = new Date();
            if (timeout_oab_develop_theme === false) {
                timeout_oab_develop_theme = true;
                setTimeout(resizeend_oab_develop_theme, delta_oab_develop_theme);
            }
        });
    });
})(jQuery, window, document);


function resizeend_oab_develop_theme() {
    if (new Date() - rtime_oab_develop_theme < delta_oab_develop_theme) {
        setTimeout(resizeend_oab_develop_theme, delta_oab_develop_theme);
    }else{
        timeout_oab_develop_theme = false;
        //console.log("resize");
        check_body_size();
    }
}

function check_body_size(){

    var body_width = $("body").width();

    $.each($("html").attr('class').split(/\s+/), function(i, name) {
        if (name.indexOf('col-') > -1) {
            last_size = name;
            return false;
        }
    });

    $("html").removeClass("col-xxs");
    $("html").removeClass("col-xs");
    $("html").removeClass("col-sm");
    $("html").removeClass("col-md");
    $("html").removeClass("col-lg");

    var new_class = '';
    if(body_width<480){
        $("html").addClass("col-xxs");
        new_class = "col-xs";
    }else if(body_width<767){
        $("html").addClass("col-xs");
        new_class = "col-xs";
    }else if(body_width<992){
        $("html").addClass("col-sm");
        new_class = "col-sm";
    }else if(body_width<1200){
        $("html").addClass("col-md");
        new_class = "col-md";
    }else{
        $("html").addClass("col-lg");
        new_class = "col-lg";
    }

    if (last_size !== new_class){
        $("html").trigger('classHtmlChanged');
    }
}
