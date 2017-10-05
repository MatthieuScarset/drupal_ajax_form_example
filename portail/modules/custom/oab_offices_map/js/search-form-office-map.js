(function($, w, d, c){
    $(d).ready(function() {
        hideShowCountries();

        $('#edit-region').change(function(e) {
            hideShowCountries();
        });

        function hideShowCountries() {
            var regionSelect = document.getElementById('edit-region');
            var region_id = regionSelect.options[regionSelect.selectedIndex].value;
            var offices = drupalSettings.countriesRegionsTab;
            var allCountriesArray = drupalSettings.allCountriesArray;

            $("#edit-country").empty();
            $("#edit-country").append($("<option></option>")
                    .attr("value","all")
                    .text("All"));

            $.each(allCountriesArray , function(i, val) {
                if((offices[val.id] == region_id || region_id == 'all') && val.id != 'all' && val.id != '' && val.id != 'undefined'  && val.id != null) {
                    // si le tableau office_id => region ID a la bonne région pour ce pays, on l'ajoute à la liste
                    $("#edit-country").append($("<option></option>")
                        .attr("value", val.id)
                        .text(val.name));
                }
            });
        }

    });

})(jQuery, window, document, window.console)