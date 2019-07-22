(function ($, Drupal, Bootstrap, drupalSettings) {
//      $(document).on("click",".panel-footer", function () {
    countries_form_autocomplete();
    $('.get_zone').click(function () {

       $(".get_zone").removeClass("active");
       $(this).addClass("active");

        //get code zone since twig template
        var data = $(this).data();
        var code_zone = data.zone;

        get_countries_with_zone_code(code_zone);

    });


    function get_countries_with_zone_code(code_zone) {

        var arr_hydra_member = drupalSettings.arr_contries;

        $('#select_pays_zone').removeClass('hidden');

        var listePays = arr_hydra_member.filter(function (element) {
            // console.log(element.rootZone.code + " vs " + code_zone + '|' + element.rootZone.code.length + " vs " + code_zone.length);
            return element.rootZone.code === code_zone;
        });

        //Call method sort by country label _A-Z
        listePays = listePays.sort(SortByLabel);

        $('#select_pays_zone').html("");
        listePays.forEach((function (pays) {
            $('#select_pays_zone').append('<option value="' + pays.id + '">' + pays.label + '</option>');
        }));

        }

    function countries_form_autocomplete() {
        var arr_hydra_member = drupalSettings.arr_contries;
        var countries = [];

        arr_hydra_member.forEach(function (item, key) {
            countries[key] = item.label;
        });

        listen_form_countries(countries);
    }

    function listen_form_countries(countries) {

        $('.countries_input_autocomplete').on('keyup', function() {

            $('.countries_input_autocomplete').autocomplete({
                source: countries
            });
        });
    }
        /*
        $('#select_pays_zone')
            .fadeOut(1500, function () {
                $('#select_pays_zone').html("");
                listePays.forEach(function(pays) {
                    $('#select_pays_zone').append('<option value="' + pays.id + '">' + pays.label + '</option>');

                });
            })
            .fadeIn(1500);
      */



    //This function will sort array
    function SortByLabel(a, b) {
        var aName = a.label.toLowerCase();
        var bName = b.label.toLowerCase();
        return ((aName < bName) ? -1 : ((aName > bName) ? 1 : 0));
    }

})(window.jQuery, window.Drupal, window.Drupal.bootstrap, drupalSettings);
