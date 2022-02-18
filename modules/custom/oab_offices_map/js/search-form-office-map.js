(function($, w, d, Drupal, drupalSettings){
    $(d).ready(function() {

        // initialisation du contrôle de la carte (nécessite mapcontrol.js)
        var mc = new MapControl();

        // EVENEMENT : clic sur "Afficher la carte" > Voir l'agence sur la carte
        $('.show_on_map').click(function() {
          mc.gotoMarker($(this).data('location'));
          // mc.flyToMarker($(this).data('location'));
        });

        $('#edit-region').change(function(e) {
            onChangeHideShowCountries();
        });

        function onChangeHideShowCountries() {
            //sur le changeement de région
            var regionSelect = document.getElementById('edit-region');
            var region_id = regionSelect.options[regionSelect.selectedIndex].value;
            var offices = drupalSettings.countriesRegionsTab;
            var allCountriesArray = drupalSettings.allCountriesArray;

            $("#edit-country").addClass('form-control-empty');
            $("#edit-country").empty();
            $("#edit-country").append($("<option></option>")
                .attr("value","")
                .attr("selected", "")
                .attr("disabled", "")
                .addClass('label-option-hidden'));

            $.each(allCountriesArray , function(i, val) {
                if((offices[val.id] == region_id) && val.id != 'all' && val.id != '' && val.id != 'undefined'  && val.id != null) {
                    // si le tableau office_id => region ID a la bonne région pour ce pays, on l'ajoute à la liste
                    $("#edit-country").append($("<option></option>")
                        .attr("value", val.id)
                        .text(val.name));
                }
            });
        }

    });

})(jQuery, window, document, window.Drupal, window.drupalSettings);
