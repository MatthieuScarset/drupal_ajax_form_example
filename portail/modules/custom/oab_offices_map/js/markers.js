(function($, w, d, c){
    $(d).ready(function() {
        Drupal.geolocation.loadGoogle(function () {
            //méthode appelée une fois que la map est chargée
            gestionManipulation()
        });

        function gestionManipulation() {
            if(Drupal.geolocation.maps.length > 0) {
                var map = Drupal.geolocation.maps[0];

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
                        var iconHover = icon.split('.png');
                        iconHover = iconHover[0]+'-hover.png';
                        markerAssociated.setIcon(iconHover);
                    }
                );


                $('.offices-addresses .offices-addresses-list .office-address').mouseout(
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
                        console.log(icon);
                        var iconHover = icon.split('.png');
                        iconHover = iconHover[0]+'-hover.png';
                        markerAssociated.setIcon(iconHover);
                    }
                );
            }
         }

    });

})(jQuery, window, document, window.console)