(function ($, Drupal, Bootstrap, drupalSettings) {
//      $(document).on("click",".panel-footer", function () {
    init_listen_form_countries();
    $(".roaming-infos-container").hide();
    $(".reseau-partenaire-tarif-roaming").hide();

    //var pays_id = $('.hidden-countrie-id').text();
    if (drupalSettings.id_country !== undefined) {
      var pays_id = drupalSettings.id_country;
      load_data_from_id_countrie(pays_id);
    }


    $('.get_zone').click(function () {

       $(".get_zone").removeClass("active");
       $(this).addClass("active");

        //get code zone since twig template
        var data = $(this).data();
        var id_zone = data.zoneId;

        update_page_datas_with_selection(id_zone);
        init_reset_autocomplete_field();

    });

    function load_data_from_id_countrie(pays_id) {
        var arr_hydra_member = drupalSettings.arr_contries;
        const country = arr_hydra_member.find(country => country.id == pays_id);

        if (country !== undefined) {
          $('.countries_input_autocomplete').val(country.label);

          update_page_datas_with_selection(country.zoneId);
          load_country_operators(pays_id);
          update_label_countrie_reseaux(country.label);

          $('#select_pays_zone').val(pays_id);
        }
    }

    function update_page_datas_with_selection (id_zone) {
        set_countries_with_zone_code(id_zone);
        set_zone_tarif_info(id_zone);
    }

    function init_reset_autocomplete_field() {
        $('#select_pays_zone').click(function() {
            $('.countries_input_autocomplete').val('');
        });
    }

    function set_countries_with_zone_code(id_zone) {

        var arr_hydra_member = drupalSettings.arr_contries;

        $('.global-obl-container .obl-search-by-country').removeClass('hidden');

        var listePays = arr_hydra_member.filter(function (element) {
            return element.zoneId === id_zone;
        });
        //Call method sort by country label _A-Z
        listePays = listePays.sort(SortByLabel);

        $('#select_pays_zone').html("");
        listePays.forEach((function (pays) {
            $('#select_pays_zone').append('<option value="' + pays.id + '">' + pays.label + '</option>');
        }));


        var zone_label = '';
        if (drupalSettings.obl_zones !== undefined && drupalSettings.obl_zones.length > 0) {
          var actual_zone = drupalSettings.obl_zones.find(zone => zone.id === id_zone);
          if (actual_zone !== undefined) {
            zone_label = actual_zone.label;
          }
        }

        $('.obl-label-name').text(zone_label);
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
            url: '/oblGetOneCountry/'+countrie_id + '?t=' + drupalSettings.ajax_token,
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

                update_page_datas_with_selection(pays.zoneId);
                load_country_operators(pays.id);

                $('#select_pays_zone option[value='+pays.id+']').attr("selected", "selected");

            },
        });
    }

    function set_zone_tarif_info(code_zone) {

        $(".roaming-infos-container").show();
        $(".empty-roaming-infos-container").hide();

        $.ajax({
            url: '/oblGetOneZone/'+code_zone + '?t=' + drupalSettings.ajax_token,
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
    $('#select_technologie_obl').html('<option value="1" selected="selected" disabled>(autre couverture)</option>');

    if (drupalSettings.arr_technologies_obl !== undefined && drupalSettings.arr_technologies_obl.length > 0) {
      var arr_technologies = drupalSettings.arr_technologies_obl;
      var arr_technologies_sort = arr_technologies.sort(SortById);

      if (arr_technologies_sort.length != 0) {
        $.each(arr_technologies_sort, function (index, value) {
          var selected = "";
          if (drupalSettings.techno !== undefined && drupalSettings.techno == value.id) {
            selected = 'selected="selected"';
          }
          $('#select_technologie_obl').append('<option value="' + value.id + '" name="'+ value.name +'" style="color: black"' + selected + '>' + 'couverture  ' + value.name + '</option>');
        });
        $('#select_technologie_obl').on('change', function () {
            var techno_selected = $("option:selected", this).attr('value');
            window.location.href = '?techno=' +techno_selected;
        });
      }
    }

    /*
     print tab obl accords
     */
    $('.btn_print_accords_obl').on('click',function() {
      window.print();
    });


})(window.jQuery, window.Drupal, window.Drupal.bootstrap, drupalSettings);

