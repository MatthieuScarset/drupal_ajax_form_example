(function($, w, d, c){
    $(d).ready(function() {

        var currentMarker;
        var map;
        var infowindow;
        google.maps.InfoWindow = InfoBox;
        var infowindow = new google.maps.InfoWindow();
        Drupal.geolocation.loadGoogle(function () {
            //méthode appelée une fois que la map est chargée
            gestionManipulation()
        });

        function gestionManipulation() {
            if(Drupal.geolocation.maps.length > 0) {

                map = Drupal.geolocation.maps[0];
                map.googleMap.setZoom(12);

                $('.offices-addresses .offices-addresses-list .office-address').mouseover(
                    function(){
                        //on récupère le n° de la ligne via les classes CSS
                        var currentTarget = $(this);
                        var currentTargetClass = currentTarget.attr('class').split(' ');
                        var currentTargetPosition = currentTargetClass[1].split('-');
                        currentTargetPosition = currentTargetPosition[2];
                        //console.log(currentTargetPosition);

                        // On recupere le marker de la map grace au numero de l'element selectionne
                        var markerAssociated = map.mapMarkers[currentTargetPosition-1];
                        var icon = markerAssociated.icon;
                        if(icon.indexOf('-hover.png') == -1) {
                            var iconHover = icon.split('.png');
                            iconHover = iconHover[0] + '-hover.png';
                            markerAssociated.setIcon(iconHover);
                        }
                    }
                );

               $('.offices-addresses .offices-addresses-list .office-address').mouseout(
                    function(){
                        if(currentMarker != undefined){
                            var markerAssociated = map.mapMarkers[currentMarker];
                            for (var i=0; i < map.mapMarkers.length; i++){
                                if(markerAssociated !=  map.mapMarkers[i]) {
                                    var iconNormal = map.mapMarkers[i].icon.replace('-hover.png', '.png');
                                    map.mapMarkers[i].setIcon(iconNormal);
                                }
                            }
                        }else {
                            //on récupère le n° de la ligne via les classes CSS
                            var currentTarget = $(this);
                            var currentTargetClass = currentTarget.attr('class').split(' ');
                            var currentTargetPosition = currentTargetClass[1].split('-');
                            currentTargetPosition = currentTargetPosition[2];
                            //console.log(currentTargetPosition);

                            // On recupere le marker de la map grace au numero de l'element selectionne
                            var markerAssociated = map.mapMarkers[currentTargetPosition - 1];
                            var icon = markerAssociated.icon;
                            if (icon.indexOf('-hover.png')) {
                                var iconNormal = icon.replace('-hover.png', '.png');
                                markerAssociated.setIcon(iconNormal);
                            }
                        }
                    }
                );

               $('.offices-addresses .offices-addresses-list .office-address').click(
                    function(){
                        //on récupère le n° de la ligne via les classes CSS
                        var currentTarget = $(this);
                        var currentTargetClass = currentTarget.attr('class').split(' ');
                        var currentTargetPosition = currentTargetClass[1].split('-');
                        currentTargetPosition = currentTargetPosition[2];
                        //console.log(currentTargetPosition);

                        // On recupere le marker de la map grace au numero de l'element selectionne
                        var markerAssociated = map.mapMarkers[currentTargetPosition-1];
                        currentMarker = currentTargetPosition-1;

                        // On centre la map sur le marqueur
                        var LatLngCenter = new google.maps.LatLng(markerAssociated.position.lat(), markerAssociated.position.lng());
                        map.googleMap.setCenter(LatLngCenter);
                        map.googleMap.setZoom(4);

                        // On affiche la bulle info
                        var boxText = document.createElement("div");
                        boxText.style.cssText = "border: 1px solid rgba(0, 0, 0, 0.5);-moz-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-webkit-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-o-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-moz-border-radius: 5px;-webkit-border-radius: 5px;-o-border-radius: 5px;-ms-border-radius: 5px;-khtml-border-radius: 5px;border-radius: 5px;";
                        boxText.innerHTML = markerAssociated.infoWindowContent;

                        var myOptions = {
                            content: boxText
                            ,disableAutoPan: false
                            ,maxWidth: 0
                            ,pixelOffset: new google.maps.Size(-107, -60)
                            ,zIndex: null
                            ,boxStyle: {
                                opacity: 1
                                ,width: "215px"
                            }
                            ,closeBoxMargin: "10px 9px 2px 2px"
                            ,closeBoxURL: "/modules/custom/oab_offices_map/images/map-close.png"
                            ,infoBoxClearance: new google.maps.Size(1, 1)
                            ,isHidden: false
                            ,pane: "floatPane"
                            ,enableEventPropagation: false
                            ,alignBottom: true
                        };
                        if (infowindow != null){
                            infowindow.close();
                        }
                        infowindow = new InfoBox(myOptions);
                        console.log(infowindow);

                        if (markerAssociated.infoWindowContent) {
                            infowindow.setContent('<div class="gmap-popup">'+markerAssociated.infoWindowContent+'<div class="fleche">&nbsp;</div>\'</div>');
                            infowindow.open(map.googleMap,map.mapMarkers[currentTargetPosition-1]);
                        }

                        // On applique les styles graphiques
                        currentTarget.parent().children('.office-address').removeClass('selected');
                        currentTarget.addClass('selected');

                        // On remet l'icone par defaut sur tous les markers
                        for (var i=0; i < map.mapMarkers.length; i++){
                            var iconNormal = map.mapMarkers[i].icon.replace('-hover.png', '.png');
                            map.mapMarkers[i].setIcon(iconNormal);
                        }

                        // Ajout de la nouvelle icone sur le marqueur selectionne
                        var icon = markerAssociated.icon;
                        if(icon.indexOf('-hover.png') == -1) {
                            var iconHover = icon.split('.png');
                            iconHover = iconHover[0] + '-hover.png';
                            markerAssociated.setIcon(iconHover);
                        }
                    }
                );
/*
                $.each(map.mapMarkers, function(i, marker){
                    google.maps.event.addListener(marker, 'click', function(marker) {
                        console.log(marker.textContent);
                       // console.log(i);
                    });
                });*/

                for (var i=0; i < map.mapMarkers.length; i++){
/*
                    map.mapMarkers[i].addListener('click', function(marker, i) {
                  //  google.maps.event.addListener(map.mapMarkers[i], 'click', function(marker) {
                        console.log(i);
                    });*/
                    marker = map.mapMarkers[i];
                    google.maps.event.addListener(marker, 'click', (function(marker, i) {
                        return function() {
                            var icon = marker.icon;
                            currentMarker = i;
                            var currentTarget = $('.offices-addresses .offices-addresses-list .office-address.views-row-'+(i+1));
                            currentTarget.parent().children('.office-address').removeClass('selected');
                            currentTarget.addClass('selected');

                            for (var j=0; j< map.mapMarkers.length; j++){
                                if (marker !=  map.mapMarkers[j]){
                                    // On remet l'icone par d�faut sur tous les markers
                                    var iconNormal = map.mapMarkers[j].icon.replace('-hover.png', '.png');
                                    map.mapMarkers[j].setIcon(iconNormal);
                                }
                            }

                            // On affiche la bulle info
                            var boxText = document.createElement("div");
                            boxText.style.cssText = "border: 1px solid rgba(0, 0, 0, 0.5);-moz-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-webkit-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-o-box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);box-shadow: 0 0 20px rgba(0, 0, 0, 0.5);-moz-border-radius: 5px;-webkit-border-radius: 5px;-o-border-radius: 5px;-ms-border-radius: 5px;-khtml-border-radius: 5px;border-radius: 5px;";
                            boxText.innerHTML = marker.infoWindowContent;

                            var myOptions = {
                                content: boxText
                                ,disableAutoPan: false
                                ,maxWidth: 0
                                ,pixelOffset: new google.maps.Size(-107, -60)
                                ,zIndex: null
                                ,boxStyle: {
                                    opacity: 1
                                    ,width: "215px"
                                }
                                ,closeBoxMargin: "10px 9px 2px 2px"
                                ,closeBoxURL: "/modules/custom/oab_offices_map/images/map-close.png"
                                ,infoBoxClearance: new google.maps.Size(1, 1)
                                ,isHidden: false
                                ,pane: "floatPane"
                                ,enableEventPropagation: false
                                ,alignBottom: true
                            };
                            if (infowindow != null){
                                infowindow.close();
                            }
                            infowindow = new InfoBox(myOptions);
                            //console.log(infowindow);

                            if (marker.infoWindowContent) {
                                infowindow.setContent('<div class="gmap-popup">'+marker.infoWindowContent+'<div class="fleche">&nbsp;</div>\'</div>');
                                infowindow.open(map.googleMap, marker);
                            }

                            var icon = marker.icon;
                            if(icon.indexOf('-hover.png') == -1) {
                                var iconHover = icon.split('.png');
                                iconHover = iconHover[0] + '-hover.png';
                                marker.setIcon(iconHover);
                            }
                        }
                    })(marker, i));
                }

            }
         }

    });

})(jQuery, window, document, window.console)