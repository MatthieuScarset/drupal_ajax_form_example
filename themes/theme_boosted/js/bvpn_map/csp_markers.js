
(function ($, Drupal, Bootstrap) {
  $(document).ready(function() {

    var itemSelectedId = null;
    var searchByName = false;
    var nameSearched = '';
    var searchByNameToReload = false;

    //donne un point Latlng à partir de coordonnées "latiture,longitude"
    var getLatLngFromText = function(currentCoordonees) {
      currentCoordonees = currentCoordonees.replace(/\n/g, '');
      var coordonneesTab = currentCoordonees.split(',');
      return L.latLng(coordonneesTab[0], coordonneesTab[1]);
    };

    //on clique sur un item de la liste => sélectionne un point sur la map => changement de l'icône
    var selectCSPItem = function(item){
      itemSelectedId = item.id;
      item.classList.add('selected');
      var positions = $(item).find('span.geolocation-data').text();
      positions = positions.replace(/\n/g, '');
      var positionsTab = positions.split(';');
      for (var i = 0; i < positionsTab.length; i++) {
        var latlng = getLatLngFromText(positionsTab[i]);
        var mc = new CSPMapControl();
        mc.changeIconOnMarker(latlng);
      }
    }

    // on déselectionne un item de la liste ==> déselection des points de la map et on remet l'ancien icône noit
    var unselectCSPItem = function(item){
      item.classList.remove('selected');
      itemSelectedId = null;
      var positions = $(item).find('span.geolocation-data').text();
      positions = positions.replace(/\n/g, '');
      var positionsTab = positions.split(';');
      for (var i = 0; i < positionsTab.length; i++) {
        var latlng = getLatLngFromText(positionsTab[i]);
        var mc = new CSPMapControl();
        mc.resetIconOnMarker(latlng);
      }
    }

    //on déselctionne tous les points de la map => et tous les éléments de la liste des CSP
    var unselectAllCSPItem = function(){
      itemSelectedId = null;
      var mc = new CSPMapControl();
      mc.resetAllIconOnMarker();
      $('.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress').each(
        function() {
          unselectCSPItem(this);
        }
      )
    }

    //après une recherche (par nom ou par région) on regarde si les nouveaux items de la liste contiennent l'item qui avait été sélectionné.
    // Si c'est le cas, on resélectionne sur la map et dans la liste, sinon on déselctionne tout
    var selectItemAfterSearch = function(){
      //on regarde si l'element sélectionné est parmis les résultats, sinon on le déselectionne
      var present = false;
      $('.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress').each(
        function() {
          if(this.id ==itemSelectedId){
            this.classList.add('selected');
            selectCSPItem(this);
            present = true;
          }
        }
      )
      if(!present){
        unselectAllCSPItem();
      }
    }

    //zoom sur un point particulier
    var goTo = function (lat, lng){
      var mc = new CSPMapControl();
      mc.goTo([lat, lng]);
    }

    $(document).on('keypress', '#views-exposed-form-bvpn-gallery-csp-list-block',function(event) {
      var keyPressed = event.keyCode || event.which;
      if (keyPressed === 13) {
        event.preventDefault();
        return false;
      }
    });

    //on sélectionne une région => on change la couleur du bouton en Orange pour montrer qu'il faut appliquer le filtre
    $(document).on('change', '#views-exposed-form-bvpn-gallery-csp-map-page select[name="location"]',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-map-page .form-actions .btn_validate_search_map').addClass('active');
    });

    // au clique sur un item de la liste des CSP => il faut sélectionner ou déselectionner ses points sur la carte
    $(document).on('click', '.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress',
      function(){
        if(this.classList.contains('selected')){
          //on déselectionne l'iten
          unselectCSPItem(this);
        }
        else{
          // on sélectionne cet item et déselectionne les autres
          unselectAllCSPItem();
          selectCSPItem(this);
        }
      }
    );

    $(document).on('click', '[data-click-on]', function(){
        $($(this).data('clickOn')).click();
      }
    );

    // reset de la recherche par noms => on remet vide dans la recherche par titre, on valide la recherche et on déselectionne tout
    $(document).on('click', '#remove-icon-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
          var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
          var selectedRegion = selectOptions.children("option:selected").val();
          view.settings.location = selectedRegion;
          delete view.settings.csp_list_filter_title;
          var selector = '.js-view-dom-id-' + view.settings.view_dom_id;
          jQuery(selector).triggerHandler('RefreshView');
          unselectAllCSPItem();
          ajax_is_filter = true;
          searchByName = false;
          nameSearched = '';
        }
      });
    });

    // recherche par nom, on utilise une variable pour indiquer qu'on a fait la recherche par nom => ça permet de changer l'icône
    $(document).on('click', '#search-icon-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
          searchByName = true;
          nameSearched = $('input[name=title]').val(); //sauvegarde de la recherche
        }
      });
    });

    //BOUTONS DE RECHERCHE DE LA MAP

    //clique sur l'icone Filter de la map => soumet le formulaire de recherche
    $(document).on('click', '.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #validate-search-map-btn',
      function(){
        $.each(Drupal.views.instances, function(i, view) {
          if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
            var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
            var selectedRegion = selectOptions.children("option:selected").val();
            view.settings.location = selectedRegion;
            if(searchByName) {
              view.settings.csp_list_filter_title = $("#views-exposed-form-bvpn-gallery-csp-list-block input[name=title]").val();
            }

            var selector = '.js-view-dom-id-' + view.settings.view_dom_id;
            jQuery(selector).triggerHandler('RefreshView');
          }
        });
       }
    );
    // reset de la recherche par regions => on met All
    $(document).on('click', '.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #clear-search-map-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name === "bvpn_gallery" && view.settings.view_display_id === "csp_map_page") {
          view.settings.location = 'All';
          if(searchByName) {
            view.settings.csp_list_filter_title = $("#views-exposed-form-bvpn-gallery-csp-list-block input[name=title]").val();
          }

          var selector = '.js-view-dom-id-' + view.settings.view_dom_id;
          jQuery(selector).triggerHandler('RefreshView');
        }
      });
    });

    //au rechargement des vues
    $(document).ajaxComplete(function(event, xhr, settings) {
      if (settings.data !== undefined && typeof settings.data.indexOf === "function" && settings.data.indexOf( "view_name=bvpn_gallery") != -1 ) {
        selectItemAfterSearch();
        //on désactive la première option du select des Régions => All
        var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
        if (selectOptions.length > 0) {
          selectOptions[0][0].disabled = true;
        }
        $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-map-page .form-actions .btn_validate_search_map').removeClass('active');
        var selectedOption = selectOptions.children("option:selected").val();
        if(selectedOption != 'All') {
          // recherche sur une région => bouton Clear activé
          $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #clear-search-map-btn').addClass(' is-disabled');
          $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #clear-search-map-btn').attr('disabled', false);
        }
        else {
          // pas de recherche sur une région => bouton Clear déactivé
          $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #clear-search-map-btn').addClass(' is-disabled');
          $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page #clear-search-map-btn').attr('disabled', true);
        }

        if (searchByName) {
          $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').addClass('hidden');
          $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').removeClass('hidden');
          $('#views-exposed-form-bvpn-gallery-csp-list-block input[name=title]').attr('disabled', true);
        } else {
          $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').addClass('hidden');
          $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').removeClass('hidden');
          $('#views-exposed-form-bvpn-gallery-csp-list-block input[name=title]').attr('disabled', false);
        }
      }
    });

    //quand les vues ajax ont fini de se charger
    $(document).ajaxStop(function() {
      var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
      var selectedOption = selectOptions.children("option:selected").val();
      if(selectedOption != 'All') {
        //je zoom sur le point
        var point = drupalSettings.listRegionMarkers[selectedOption];
        if(point){
          goTo(point.lat, point.lng);
        }
      }
    });

  });
})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
