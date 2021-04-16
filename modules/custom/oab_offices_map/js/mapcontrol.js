/**
 * Gestion de carte intéractive
 * @return {Object}
 * @constructor
 */
var MapControl = function() {
  var map = {};
  var _initialized = false;
  var _settings = {
    zoom: {
      min: 2,
      max: 16, // 19 par Drupal ?
      detail: 13
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
   * TODO : changer de nom : coordinates(), formatCoordinates(), ...
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
   * Ouvre les clusters visibles
   * TODO
   * @private
   */
  // var _openClusters = function() {
  //   // TODO
  //   // TODO : détecter à quel niveau de zoom les clusters s'ouvrent
  //   // TODO
  //   var markers = L.markerClusterGroup();
  //   // TODO
  //   // TODO
  // };

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
   * Affiche une popup sur un marqueur (elle doit déjà exister)
   * @param {L.latLng} latLng
   *
   * TODO : remplacer latLng par coordinates ?
   */
  var openPopupOnMarker = function(latLng) {
    var markers = _getMarkers();
    var marker;

    if(markers.length === 1) {
      marker = markers[0];
    } else {
      // si on a + d'un marqueur visible, on recherche celui qui nous intéresse (= celui qui a les mêmes coordonnées)
      marker = markers.find(m => (m._latlng.lat === latLng.lat && m._latlng.lng === latLng.lng));
    }

    if(marker instanceof L.Marker) {
      marker.openPopup();
    }
  };

  /**
   * Positionne la carte sur les coordonnées
   * @param {String|Array} coordsOrLatitude :
   * @return {MapControl}
   */
  var gotoMarker = function(coordinates) {
    // déplacement de la vue sur le marqueur
    var latLng = _getLatLng(coordinates);
    map.setView(latLng, _settings.zoom.detail);

    // affichage de la popup sur le marqueur
    openPopupOnMarker(latLng);
  };
  var flyToMarker = function(coordinates) {
    var latLng = _getLatLng(coordinates);

    map.flyTo(latLng, _settings.zoom.detail);
    // affichage de la popup sur le marqueur
    openPopupOnMarker(latLng);
    // TODO : détecter si il y a un marqueur et le créer si besoin ?
  };

  /**
   * Ajoute un marqueur sur la carte
   * @param {Number} latitude
   * @param {Number} longitude
   * @return {L.Marker}
   *
   * TODO : remplacer latitude/longitude par latLng ou coordinates ?
   */
  var addMarker = function(latitude, longitude) {
    var latLng = _getLatLng([latitude, longitude]);
    var marker = new L.marker(latLng).addTo(map);

    return marker;
  }

  _init();

  return {
    gotoMarker: gotoMarker,
    flyToMarker: flyToMarker,
    addMarker: addMarker,
    openPopupOnMarker: openPopupOnMarker
  }
};
