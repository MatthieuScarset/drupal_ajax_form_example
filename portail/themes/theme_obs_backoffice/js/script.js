(function ($, Drupal) {
  $(window).load(function(){
    $('.horizontal-tabs .horizontal-tabs-list .horizontal-tab-button a strong').each(function(){
      var new_str = $(this).text().replace(/Show /g, '');
      new_str = new_str.replace(/Afficher /g, '');
      $(this).text(new_str);
    });
  });


    $(document).ready(function () {
        $( ".close-env-info" ).click(function(){
            if ($('.env-info').is(":visible")){
                $('.environnement-info').hide();
            }
        });
    });

})(jQuery, Drupal);