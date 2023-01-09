
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
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-map-page .form-actions .btn_submit_filter_search_map').addClass('active');
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

    //clique sur l'icone loupe => soumet le formulaire de recherche
    $(document).on('click', '.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block #search-icon-btn',
      function(){
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block input.search-icon').click();
      }
    );
    //clique sur l'icone croix => soumet le formulaire de reset
    $(document).on('click', '.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block #remove-icon-btn',
      function(){
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block input.reset-icon').click();
      }
    );
    // reset de la recherche par noms => on remet vide dans la recherche par titre, on valide la recherche et on déselectionne tout
    $(document).on('click', '#remove-icon-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
          var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
          var selectedRegion = selectOptions.children("option:selected").val();
          view.settings.location = selectedRegion;
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


    // effacer le filtre de la recherche par région
    $(document).on('click', '.btn_clear_filter_search_map', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_map_page") {
          var selector = '.js-view-dom-id-' + view.settings.view_dom_id;
          jQuery(selector).triggerHandler('RefreshView');
          ajax_is_filter = true;
        }
      });
    });


    //marche
    jQuery(document).ajaxSend(function(event, xhr, settings) {
      //temporaire à continuer /modifier
      if (settings.extraData && settings.extraData.view_name == "bvpn_gallery" && settings.extraData.view_display_id == "csp_map_page") {
        if(nameSearched != '') {
          searchByNameToReload = true;
        }
      }
    });

    //au rechargement des vues
    jQuery(document).ajaxComplete(function(event, xhr, settings) {

      selectItemAfterSearch();

      //on désactive la première option du select des Régions => All
      var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
      if(selectOptions.length>0) {
        selectOptions[0][0].disabled = true;
      }

      if(searchByName){
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').addClass('hidden');
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').removeClass('hidden');
      }
      else{
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').addClass('hidden');
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').removeClass('hidden');
      }

      if(nameSearched != '' && searchByNameToReload){
        $('input[name=title]').val(nameSearched);
        searchByNameToReload = false;
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block input.search-icon').click();
      }
    });

    //quand les vues ajax ont fini de se charger
    $(document).ajaxStop(function() {
      var selectOptions = $('.view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-map-page .form-item-location .form-select');
      var selectedOption = selectOptions.children("option:selected").val();
      if(selectedOption != 'all')
      {
        //je zoom sur le point
        var point = drupalSettings.listRegionMarkers[selectedOption];
        if(point){
          goTo(point.lat, point.lng);
        }
      }
    });

  });
})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
