(function ($, Drupal, debounce) {
  "use strict";

  /**
   *
   */
  $.fn.viewsAjaxUrl = function () {
    alert('plop');
    /*$.ajax({
      type: "POST",
      url: 'http://orange-business.local:8000/en/partners',
      data: {param1 : "myParam1", param2 : "myParam2"},
      success: function(data) {
        alert('plop');
        console.debug('Load was performed.');
      }
    });*/
  };

})(jQuery, Drupal, Drupal.debounce);
