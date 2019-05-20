(function ($, Drupal, window, document, undefined) {
	$(document).ready(function() {		
		$('.page-synomia-search-results .filters_title').click(function() {
			if ($("body.col-xs").length || $("body.col-md").length){
				var clicked = $(this);				
				var filtersDiv = $('.page-synomia-search-results .block-facetapi .item-list');
				if(!filtersDiv.is(":visible")){
					clicked.addClass('selected');
					clicked.removeClass('not-selected');
					filtersDiv.slideDown();
				}					
				else{
					clicked.removeClass('selected');
					clicked.addClass('not-selected');
					filtersDiv.slideUp();
				}
			}
			
		});
		
		var hideShowFilters = function (){
			var elementH2 = $('.page-synomia-search-results .filters_title');
			var filtersDiv = $('.page-synomia-search-results .block-facetapi .item-list');
			if ($("body.desktop-version").length){	
				//mode desktop				
				if(!filtersDiv.is(":visible")){
					elementH2.addClass('selected');
					elementH2.removeClass('not-selected');
					filtersDiv.slideDown();
				}
			}
			else{
				if(!filtersDiv.is(":visible")){
					elementH2.addClass('not-selected');
					elementH2.removeClass('selected');
				}					
				else{
					elementH2.addClass('selected');
					elementH2.removeClass('not-selected');
				}
			}
		}
		
		hideShowFilters();
		$('.page-synomia-search-results .filters_title').click();
		
		//lors du redimensionnement on verifie les elements
		$(window).resize(function() {
    		hideShowFilters();
        });
		
	});
	
})(jQuery, Drupal, this.document);