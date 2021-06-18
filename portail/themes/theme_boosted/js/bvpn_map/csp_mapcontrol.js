/**
 * Gestion de carte intéractive
 * @return {Object}
 * @constructor
 */
var CSPMapControl = function() {
  var map = {};
  var _initialized = false;
  var _settings = {
    //le zoom ne fonctionne pas, il est géré par la views Drupal
    zoom: {
      min: 4,
      max: 10, // 19 par Drupal ?
      detail: 4
    },
  };

  /**
   * Initialisation
   * @private
   */
  var _init = function() {
    if(_initialized === true) {
      return;
    }

    if(typeof Drupal.geolocation === 'undefined') {
      return;
    }

    var drupalMap = Drupal.geolocation.maps[0];

    if(drupalMap.type !== 'leaflet') {
      throw 'Map provider must be "Leaflet"';
    }

    map = drupalMap.leafletMap;
    _initialized = true;
  };

  /**
   * Retourne les coordonnées depuis une chaine de caractères ou depuis les latitude/longitude
   * @param {String|Array} coordsOrLatitude : coordonnées ou latitude (voir commentaires)
   * @param {String|Number} longitude
   * @return {Array}
   * @private
   *
   */
  var _getCoordinates = function(coordsOrLatitude, longitude) {
    if(typeof coordsOrLatitude === 'string') {
      if(longitude !== undefined) {
        // format : _getCoordinates(52.3910186, 4.8332743)
        return [coordsOrLatitude, longitude];
      } else {
        // format : "52.3910186, 4.8332743"
        return coordsOrLatitude.split(', ');
      }
    }

    // format [52.3910186, 4.8332743]
    return coordsOrLatitude;
  };

  /**
   * Récupère tous les marqueurs visibles
   * @return {Array}
   * @private
   */
  var _getMarkers = function() {
    var markers = [];

    map.eachLayer(function(layer) {
      if(layer instanceof L.Marker && map.getBounds().contains(layer.getLatLng())) {
        markers.push(layer);
      }
    });

    return markers;
  };


  /**
   * Retourne un objet L.latLng depuis des coordonnées (utile pour les méthodes de Leaflet)
   * @param {String|Array} coordinates
   * @return {L.latLng}
   * @private
   */
  var _getLatLng = function(coordinates) {
    // var coordinates = arguments;
    coordinates = _getCoordinates(coordinates);
    return new L.latLng(coordinates);
  };

  /**
   * Change l'icone du marker
   * @param {L.latLng} latLng
   *
   */
  var changeIcon = function(latLng, iconPath) {
    var markers = _getMarkers();
    var marker;

    if(markers.length === 1) {
      marker = markers[0];
    } else {
      // si on a + d'un marqueur visible, on recherche celui qui nous intéresse (= celui qui a les mêmes coordonnées)
      marker = markers.find(m => (m._latlng.lat === latLng.lat && m._latlng.lng === latLng.lng));
    }

    if(marker instanceof L.Marker) {
      var icon = marker.options.icon;
      icon.options.iconUrl = iconPath;
      marker.setIcon(icon);
    }
  };
  /**
   * Change l'icone du marker pour l'icone orange
   * @param {String|Array} coordsOrLatitude :
   * @return {MapControl}
   */
  var changeIconOnMarker = function(coordinates) {
    var latLng = _getLatLng(coordinates);
    changeIcon(latLng,'/themes/theme_boosted/images/marker-obs-hover.png');
  };

  /**
   * Remet l'icone noir du du marker
   * @param {String|Array} coordsOrLatitude :
   * @return {MapControl}
   */
  var resetIconOnMarker = function(coordinates) {
    var latLng = _getLatLng(coordinates);
    changeIcon(latLng, '/themes/theme_boosted/images/marker-obs.png');
  };
  /**
   * Remet l'icone noir sur TOUS les markers
   * @param {String|Array} coordsOrLatitude :
   * @return {MapControl}
   */
  var resetAllIconOnMarker = function() {
    var markers = _getMarkers();
    for (var i = 0; i < markers.length; i++) {
      var marker = markers[i];
      if(marker instanceof L.Marker) {
        var icon = marker.options.icon;
        icon.options.iconUrl = '/themes/theme_boosted/images/marker-obs.png';
        marker.setIcon(icon);
      }
    }
  };

  var goTo = function(coordinates) {
    var latLng = _getLatLng(coordinates);
   // map.panTo(latLng);
    console.log(latLng.lat, latLng.lng);
    map.flyTo(latLng, 3.5);
  };

  var getZoom = function() {
    return map.getZoom();
  };

  var setZoom = function(zoom) {
    map.setZoom(zoom);
  };

  _init();

  return {
    changeIconOnMarker: changeIconOnMarker,
    resetIconOnMarker: resetIconOnMarker,
    resetAllIconOnMarker: resetAllIconOnMarker,
    goTo: goTo,
    getZoom: getZoom,
    setZoom: setZoom,
  }
};
