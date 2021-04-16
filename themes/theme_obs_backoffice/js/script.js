(function ($, Drupal) {
  $(window).on('load', (function(){
    $('.horizontal-tabs .horizontal-tabs-list .horizontal-tab-button a strong').each(function(){
      var new_str = $(this).text().replace(/Show /g, '');
      new_str = new_str.replace(/Afficher /g, '');
      $(this).text(new_str);
    });
  }));


    $(document).ready(function () {
        oab_backoffice_subhome_entity_form();
        $( ".close-env-info" ).click(function(){
            if ($('.env-info').is(":visible")){
                $('.environnement-info').hide();
            }
        });
    });

    function oab_backoffice_subhome_entity_form() {
        if ($('#group-team-details').length) {
            $('#group-team-details').attr('hidden',!$("input[name='field_afficher_bloc_notre_equipe[value]']").is(':checked'));
        }
    }

    $("input[name='field_afficher_bloc_notre_equipe[value]']").click(function() {
        oab_backoffice_subhome_entity_form();
    });

})(window.jQuery, window.Drupal);