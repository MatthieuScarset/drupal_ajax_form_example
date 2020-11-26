(function($, w, d, c){
    $(d).ready(function() {
        initShowCountries();

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

            $("#edit-country").empty();
            $("#edit-country").append($("<option></option>")
                .attr("value","all")
                .text(Drupal.t('Country')));

            $.each(allCountriesArray , function(i, val) {
                if((offices[val.id] == region_id || region_id == 'all') && val.id != 'all' && val.id != '' && val.id != 'undefined'  && val.id != null) {
                    // si le tableau office_id => region ID a la bonne région pour ce pays, on l'ajoute à la liste
                    $("#edit-country").append($("<option></option>")
                        .attr("value", val.id)
                        .text(val.name));
                }
            });
        }

        function initShowCountries() {
            //à l'arrivée sur la page
            var regionSelect = document.getElementById('edit-region');
            var region_id = (regionSelect !== null) ? regionSelect.options[regionSelect.selectedIndex].value : null;
            var offices = drupalSettings.countriesRegionsTab;
            var allCountriesArray = drupalSettings.allCountriesArray;
            var selectedCountryParameter = drupalSettings.selectedCountryParameter;
            $("#edit-country").empty();
            $("#edit-country").append($("<option></option>")
                .attr("value","all")
                .text(Drupal.t('Country')));

            $.each(allCountriesArray , function(i, val) {
                if((offices[val.id] == region_id || region_id == 'all') && val.id != 'all' && val.id != '' && val.id != 'undefined'  && val.id != null) {
                    // si le tableau office_id => region ID a la bonne région pour ce pays, on l'ajoute à la liste
                    $("#edit-country").append($("<option></option>")
                        .attr("value", val.id)
                        .text(val.name));
                }
            });
            $("#edit-country").val(selectedCountryParameter);
        }

    });

})(jQuery, window, document, window.console)
