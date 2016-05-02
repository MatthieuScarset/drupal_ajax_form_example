(function($, w, d, c){
	$(d).ready(function() {
		
		var offices = drupalSettings.markers;
		var infowindow = null;
		var markers = new Array();

		var infobox = new InfoBox({
	         disableAutoPan: false,
				maxWidth: 0,
				pixelOffset: new google.maps.Size(-107, -60),
				zIndex: null,
				boxStyle: { 
				  opacity: 1,
				  width: "215px"
				 },
				closeBoxMargin: "10px 10px 2px 2px",
				closeBoxURL: "/modules/custom/oab_offices/images/map-close.png",
	        	infoBoxClearance: new google.maps.Size(1, 1),
				isHidden: false,
				pane: "floatPane",
				enableEventPropagation: false,
				alignBottom: true,
	    });
		
		google.maps.event.addListener(infobox,'closeclick',function(){
			for(var idx = 0; idx < markers.length; idx++){
				markers[idx].setIcon("/modules/custom/oab_offices/images/marker-obs.png");
			}
		});
				
		for(var j = 0; j < offices.length; j++){
			createMarker(offices[j]);			  		  	
		}		
		
		function createMarker(office) {
			if(office.field_gps_coordinates.length >0)
			{				
				var marker = new google.maps.Marker({
		            position: new google.maps.LatLng(office.field_gps_coordinates[0].lat, office.field_gps_coordinates[0].lng),
		            map: map,
				    title: office.title,
				    text: office.textInfoBox,
				    icon: "/modules/custom/oab_offices/images/marker-obs.png"
		        });
				markers.push(marker);
				
				google.maps.event.addListener(marker, 'click', function() {
					infobox.setContent(marker.text);
					for(var idx = 0; idx < markers.length; idx++){
						markers[idx].setIcon("/modules/custom/oab_offices/images/marker-obs.png");
					}
					marker.setIcon("/modules/custom/oab_offices/images/marker-obs-hover.png");
			        infobox.open(map, marker);
			    });
				
			}	        
	    }
		
	});
	
})(jQuery, window, document, window.console)