(function ($, Drupal, Bootstrap, drupalSettings) {
//      $(document).on("click",".panel-footer", function () {
    countries_form_autocomplete();

    $(".roaming-infos-container").hide();

    $('.get_zone').click(function () {

       $(".get_zone").removeClass("active");
       $(this).addClass("active");

        //get code zone since twig template
        var data = $(this).data();
        var code_zone = data.zone;
        var id_zone = data.zoneId;

        get_countries_with_zone_code(code_zone);
        get_zone_tarif_info(id_zone);

    });


    function get_countries_with_zone_code(code_zone) {

        var arr_hydra_member = drupalSettings.arr_contries;

        $('#select_pays_zone').removeClass('hidden');

        var listePays = arr_hydra_member.filter(function (element) {
            // console.log(element.rootZone.code + " vs " + code_zone + '|' + element.rootZone.code.length + " vs " + code_zone.length);
            return element.rootZone.code === code_zone;
        });
        /*
        - Call method sort by country label _A-Z
         */
        listePays = listePays.sort(SortByLabel);

        $('#select_pays_zone').html("");
        listePays.forEach((function (pays) {
            $('#select_pays_zone').append('<option value="' + pays.id + '">' + pays.label + '</option>');
        }));

        $('.obl-label-name').text(code_zone);

        }

    function countries_form_autocomplete() {
        var arr_hydra_member = drupalSettings.arr_contries;
        var countries = [];

        /*
        - Call method sort by country label _A-Z
         */
        arr_hydra_member.sort(SortByLabel);

        arr_hydra_member.forEach(function (item, key) {
            countries[key] = item.label;
        });

        listen_form_countries(countries);
    }

    function listen_form_countries(countries) {

        var arr_hydra_member = drupalSettings.arr_contries;
        var pays = '';
        var id_zone = '';
        var label_zone = '';

        $('.countries_input_autocomplete').autocomplete({
            source: countries,
            select: function (e, correctValue){

                pays = correctValue.item.value;
                arr_hydra_member.forEach(function(item) {
                    if(item.label == pays) {
                        id_zone = item.rootZone.id;
                        label_zone = item.rootZone.code
                        get_zone_tarif_info(id_zone);
                        get_countries_with_zone_code(label_zone);
                    }
                });
            },
        });
    }

    function get_zone_tarif_info(code_zone) {

        $(".roaming-infos-container").show();
        $(".empty-roaming-infos-container").hide();

        $.ajax({
            url: '/oblGetOneZone/'+code_zone,
            type: 'GET',
            success: function(result) {

                result.roamingChargesToZones.forEach(function(item) {
                   if (item.zoneId == code_zone) {
                       $('#emission-appel').text(item.calling);
                       $('#envoi-sms').text(item.sendingSms);
                       $('#envoi-mms').text(item.sendingMms);
                   }
                });

                $('#reception-appel').text(result.roamingCharges.receivingCall);
                $('#renvoi-appel-france').text(result.roamingCharges.forwardingCallToFrance);
                $('#boite-vocale').text(result.roamingCharges.consultingVoicemail);
                $('#reception-mms').text(result.roamingCharges.receivingMms);
                $('#data-roaming').text(result.roamingCharges.data);
            }
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



    /*
    - obl_template.html.twig return tab of countries accords roaming
     */
    $('#form_countries').submit(function(e) {

        e.preventDefault();


        var arr_hydra_member = drupalSettings.arr_contries;
        var my_country = $('#input_country').val();

        console.log(my_country);



        $.each(arr_hydra_member, function(i, v) {
            if (v.label == my_country) {
                /**
                 * somme request
                 */
            }
        });

       /* $.ajax({
            url: '/oblGetOneZone/'+code_zone,
            type: 'GET',
            success: function(result) {

                result.roamingChargesToZones.forEach(function(item) {
                    if (item.zoneId == code_zone) {
                        $('#emission-appel').text(item.calling);
                        $('#envoi-sms').text(item.sendingSms);
                        $('#envoi-mms').text(item.sendingMms);
                    }
                });

            }
        });*/

    });




})(window.jQuery, window.Drupal, window.Drupal.bootstrap, drupalSettings);
