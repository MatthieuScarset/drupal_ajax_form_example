(function($, w, d, c){
    $(d).ready(function() {

      var getLatLngFromText = function(currentCoordonees) {
        var coordonneesTab = currentCoordonees.split(',');
        return L.latLng(coordonneesTab[0], coordonneesTab[1]);
      };

      var selectCSPItem = function(item){
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
        var positions = $(item).find('span.geolocation-data').text();
        var positionsTab = positions.split(';');
        for (var i = 0; i < positionsTab.length; i++) {
          var latlng = getLatLngFromText(positionsTab[i]);
          var mc = new CSPMapControl();
          mc.resetIconOnMarker(latlng);
        }
      }

      var unselectAllCSPItem = function(){
        $('.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress').each(
          function() {
            unselectCSPItem(this);
          }
        )
      }

      $('.view-id-bvpn_gallery .view-content .item-list ul li .row-csp-adress').click(
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
    });

})(jQuery, window, document, window.console)
