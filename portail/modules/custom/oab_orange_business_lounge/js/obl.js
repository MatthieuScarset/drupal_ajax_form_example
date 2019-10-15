(function ($, Drupal, Bootstrap, drupalSettings) {
//      $(document).on("click",".panel-footer", function () {
    init_listen_form_countries();
    $(".roaming-infos-container").hide();
    $(".reseau-partenaire-tarif-roaming").hide();

    var pays_id = $('.hidden-countrie-id').text();

    if (pays_id.length) {
        load_data_from_id_countrie(pays_id);
    }

    $('.get_zone').click(function () {

       $(".get_zone").removeClass("active");
       $(this).addClass("active");

        //get code zone since twig template
        var data = $(this).data();
        var code_zone = data.zone;
        var id_zone = data.zoneId;


        update_page_datas_with_selection(code_zone, id_zone);
        init_reset_autocomplete_field();

    });

    function load_data_from_id_countrie(pays_id) {
        var arr_hydra_member = drupalSettings.arr_contries;

        arr_hydra_member.forEach(function(item) {
            if(item.id == pays_id) {

                $('.countries_input_autocomplete').val(item.label);

                update_page_datas_with_selection(item.rootZone.code, item.rootZone.id);
                load_country_operators(pays_id);
                update_label_countrie_reseaux(item.label);

                $('#select_pays_zone').val(pays_id);
            }
        });
    }

    function update_page_datas_with_selection (code_zone, id_zone) {
        set_countries_with_zone_code(code_zone);
        set_zone_tarif_info(id_zone);
    }

    function init_reset_autocomplete_field() {
        $('#select_pays_zone').click(function() {
            $('.countries_input_autocomplete').val('');
        });
    }

    function set_countries_with_zone_code(code_zone) {

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

        $('.obl-label-name').text(code_zone);
        update_label_countrie_reseaux();
        update_label_zone_reseaux();

        }

    function update_label_countrie_reseaux(pays_name = '') {

        if (pays_name.length > 0) {
            $('.roaming-country-selected').text(pays_name);
        }
        $('#select_pays_zone option').click(function() {
            var selected = $('#select_pays_zone option:selected');
            var countrie_id = (selected.val());

            $('.roaming-country-selected').text(selected.text());

            load_country_operators(countrie_id);
        });
    }

    function update_label_zone_reseaux() {
        $('.get_zone').click(function(e) {
            $('.roaming-country-selected').text(e.currentTarget.dataset.zone);
        });
    }

    function load_country_operators(countrie_id) {

        $(".reseau-partenaire-tarif-roaming").show();
        $.ajax({
            url: '/oblGetOneCountry/'+countrie_id,
            type: 'GET',
            success: function(result) {
                $('.roaming-operators-table').html('');
                result.operators.forEach(function(operator) {
                    operator.networkNorms.forEach(function(item) {
                        $('.roaming-operators-table').append('<tr><td>'+operator.name+'</td><td>'+item.name+'</td></tr>');
                    });
                });
            }
        });
    }

    function init_listen_form_countries() {

        var arr_hydra_member = drupalSettings.arr_contries;
        var pays = '';

        $('.countries_input_autocomplete').autocomplete({
            source: arr_hydra_member,
            select: function (e, correctValue){

                pays = correctValue.item;
                $('.roaming-country-selected').text(pays.label);

                if ($('input[name="country_id"]').length) {
                    $('input[name="country_id"]').val(pays.id);
                }

                update_page_datas_with_selection(pays.rootZone.code, pays.rootZone.id);
                load_country_operators(pays.id);

                $('#select_pays_zone option[value='+pays.id+']').attr("selected", "selected");

            },
        });
    }

    function set_zone_tarif_info(code_zone) {

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


    //This function will sort array by Label
    function SortByLabel(a, b) {
        var aName = a.label.toLowerCase();
        var bName = b.label.toLowerCase();
        return ((aName < bName) ? -1 : ((aName > bName) ? 1 : 0));
    }

    //This function will sort array by ID
    function SortById(a, b) {
      var aName = a.id;
      var bName = b.id;
      return ((aName < bName) ? -1 : ((aName > bName) ? 1 : 0));
    }


    /**
     * Page Accords-roaming
     */
    $('#select_technologie_obl').html('<option value="4G" selected="selected" disabled>(autre couverture)</option>');
    var arr_technologies = drupalSettings.arr_technologies_obl;
    var arr_technologies_sort = arr_technologies.sort(SortById);

    if (arr_technologies_sort.length != 0) {
        $.each(arr_technologies_sort, function (index, value) {
          $('#select_technologie_obl').append('<option value="' + value.name + '" style="color: black">' + 'couverture  ' + value.name + '</option>');
        });
        $('#select_technologie_obl').on('change', function () {
        var techno_selected = $("option:selected", this).attr('value');

        /**
         * API countries + op
         */
        var arr_country_with_op = drupalSettings.arr_country_with_op;
        $('#table-accord-romaing tbody').html('');
        $.map(arr_country_with_op, function (country) {
          //console.log('1');
          $.map(country.networks, function (index, network) {
            //console.log('2');
            //console.log(network === techno_selected);
            if (network === techno_selected) {
              //console.log('I\'am here');
              var ma_liste_des_operateurs = "";
              $.map(index, function (i) {
                if (ma_liste_des_operateurs.length != 0) {
                  ma_liste_des_operateurs += '<hr class="reseau-mobile-accords-roaming" />';
                }
                ma_liste_des_operateurs += i;
              });
              $('#table-accord-romaing tbody').append('<tr><td>' + country.label + '</td><td>' + country.zoneId + '</td><td>' + ma_liste_des_operateurs + '</td></tr>');
            }
          });
        });
      });
    }

    $(function() {
      $('#select_technologie_obl').trigger("change");
    });


})(window.jQuery, window.Drupal, window.Drupal.bootstrap, drupalSettings);
