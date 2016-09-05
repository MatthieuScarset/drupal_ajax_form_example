(function ($, Drupal) {
  $(window).load(function(){
    $('.horizontal-tabs .horizontal-tabs-list .horizontal-tab-button a strong').each(function(){
      var new_str = $(this).text().replace(/Show /g, '');
      new_str = new_str.replace(/Afficher /g, '');
      $(this).text(new_str);
      console.log(new_str);
    });
  });
})(jQuery, Drupal);