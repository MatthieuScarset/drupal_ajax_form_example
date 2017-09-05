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
            $(document.getElementById('edit-country').options).each(function (index, option) {
                option.hidden = false;
                option.style.display = 'block';
            });
            if(region_id != 'all') {
                $(document.getElementById('edit-country').options).each(function (index, option) {
                    if (option.value != 'all' && offices[option.value] != region_id) {
                        option.style.display = 'none';
                        option.hidden = true;
                        option.selected = false;
                    }
                });
            }
        }

    });

})(jQuery, window, document, window.console)