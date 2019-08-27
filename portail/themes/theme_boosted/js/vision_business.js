/**
 * Vision business related javascript
 * => Vgrid et dev pour faire fonctionner vgrid
 *
 * Voir
 *  - jquery.vgrid.min.js
 *  - http://blog.xlune.com/2009/09/vgrid/
 *  - https://github.com/xlune/jQuery-vGrid-Plugin
 */

(function ($, Drupal, Bootstrap) {

    function createVgrid() {

        $(window).off('resize.vgrid');
        return $(".view-business-insight .view-content .views-infinite-scroll-content-wrapper").vgrid({
            easing: "easeOutQuint",
            useLoadImageEvent: true,
            time: 400,
            delay: 20,
            fadeIn: {
                time: 500,
                delay: 50,
                wait: 500
            }
        });
    }

    let vg = createVgrid();

    //Par défaut, sur le filter parce qu'on y fait des actions, contrairement au load more
    // + compteur pour compter le nb de requetes ajax qui partent (on a parfois 2 requetes qui partent.. Impossible de localiser l'envoie pour l'instant)
    let ajax_is_filter = false;
    let compteur = 0;

    jQuery(document).ajaxSend(function(event, xhr, settings) {
        if (settings.data !== undefined && settings.data.indexOf( "view_name=business_insight") != -1) {
            compteur++;
        }
    });

    jQuery(document).ajaxComplete(function(event, xhr, settings) {

        // see if it is from our view
        if (settings.data !== undefined && settings.data.indexOf( "view_name=business_insight") != -1) {
            compteur --;
            if (compteur < 1) {
                if (ajax_is_filter && compteur === 0) {
                    vg = createVgrid();
                } else if (compteur === 0) {
                    vg.vgrefresh();
                }

                // Par défaut, parce que pas moyen de le changer au load
                ajax_is_filter = false;
                compteur = 0;
            }
        }

    });

    $(document).on("click", ".fieldset-field-insight-type .btn label", function(evt) {
        utag_link(utag_data.titre_page, 'Filters', 'Content Type', $(evt.target).text());
    });


    $(document).on("click", "div.btn-field-insight-type", function() {
        let input_id = $(this).attr('data-input');
        $('input#' + input_id).prop( "checked", true );
        ajax_is_filter = true;

        $("form#views-exposed-form-business-insight-business-insight-page input[type='submit']").click();
    });


    $(document).on("change", "select[name='field_insight_target_id']", function() {
        ajax_is_filter = true;
        $("form#views-exposed-form-business-insight-business-insight-page input[type='submit']").click();

    });


    $(document).on('click', '.view-business-insight .field_insight_type a', function() {
        let taxo_id = $(this).attr('data-taxo');
        let selector = "div.btn-field-insight-type[data-taxo='"+taxo_id+"']";

        $(selector).click();
        return false;
    });

    $(document).on('click', '.view-business-insight .field_insight a', function() {
        let taxo_id = $(this).attr('data-taxo');
        let selector = "select[name='field_insight_target_id']";

        $(selector).val(taxo_id).trigger('change');
        return false;
    });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);


