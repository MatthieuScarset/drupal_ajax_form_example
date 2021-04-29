
(function ($, Drupal, Bootstrap) {
  $(document).ready(function() {

    var itemSelectedId = null;
    var searchByName = false;

    var getLatLngFromText = function(currentCoordonees) {
      var coordonneesTab = currentCoordonees.split(',');
      return L.latLng(coordonneesTab[0], coordonneesTab[1]);
    };

    var selectCSPItem = function(item){
      itemSelectedId = item.id;
      item.classList.add('selected');
      var positions = $(item).find('span.geolocation-data').text();
      var positionsTab = positions.split(';');
      for (var i = 0; i < positionsTab.length; i++) {
        var latlng = getLatLngFromText(positionsTab[i]);
        var mc = new CSPMapControl();
        mc.changeIconOnMarker(latlng);
      }
    }
    var unselectCSPItem = function(item){
      item.classList.remove('selected');
      itemSelectedId = null;
      var positions = $(item).find('span.geolocation-data').text();
      var positionsTab = positions.split(';');
      for (var i = 0; i < positionsTab.length; i++) {
        var latlng = getLatLngFromText(positionsTab[i]);
        var mc = new CSPMapControl();
        mc.resetIconOnMarker(latlng);
      }
    }

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

    $(document).on('change', '.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-map-page #edit-location.form-select',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-map-page .form-actions #edit-submit-bvpn-gallery.button').addClass('active');
    });

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

    $(document).on('click', '.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block #search-icon-btn',
        function(){
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block input.search-icon').click();
        }
      );
    $(document).on('click', '.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block #remove-icon-btn',
        function(){
          $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block input.reset-icon').click();
        }
      );

    $(document).on('click', '#remove-icon-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
          $('#views-exposed-form-bvpn-gallery-csp-list-block #edit-title').attr('value', '');
          var selector = '.js-view-dom-id-' + view.settings.view_dom_id;
          jQuery(selector).triggerHandler('RefreshView');
          unselectAllCSPItem();
          ajax_is_filter = true;
          searchByName = false;
        }
      });
    });
    $(document).on('click', '#search-icon-btn', function() {
      $.each(Drupal.views.instances, function(i, view) {
        if (view.settings.view_name == "bvpn_gallery" && view.settings.view_display_id == "csp_list_block") {
          searchByName = true;
        }
      });
    });


    jQuery(document).ajaxComplete(function(event, xhr, settings) {
      if(searchByName){
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').addClass('hidden');
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').removeClass('hidden');

        //on regarde si l'element sélectionné est parmis les résultats, sinon on le déselectionne
        var present = false;
        $('.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress').each(
          function() {
            if(this.id ==itemSelectedId){
              this.classList.add('selected');
              present = true;
            }
          }
        )
        if(!present){
          unselectAllCSPItem();
        }
      }
      else{
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .remove-icon-btn').addClass('hidden');
        $('.csp-listing .view-bvpn-gallery .view-filters #views-exposed-form-bvpn-gallery-csp-list-block .search-icon-btn').removeClass('hidden');
      }
    });
  });
})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

