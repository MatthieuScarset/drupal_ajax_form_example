(function($, w, d) {
	var ww = window.innerWidth;
	
    $(d).ready(function() {
    	$(window).resize(function() {
    		ww = window.innerWidth;
    		if (ww < 960){
				if ($("body.desktop-version").length){
					$("body").removeClass("desktop-version");
					$("body").removeClass("desktop-full-version");
					$("body").addClass("mobile-version");

	    		}
    		}
	    	else{
    			if ($("body.mobile-version").length){
        			$("body").removeClass("mobile-version");
            		$("body").addClass("desktop-version");
            		$("body").addClass("desktop-full-version");
        		}
	    	}
    	});
    	
    	$("body").addClass("desktop-version");
        ww = window.innerWidth;
    	if (ww < 960) {
			$("body").removeClass("desktop-version");
			$("body").removeClass("desktop-full-version");
			$("body").addClass("mobile-version");
		}
    });
})(jQuery, window, document);