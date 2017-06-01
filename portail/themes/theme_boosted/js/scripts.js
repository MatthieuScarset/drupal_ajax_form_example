/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {

  $( window ).resize(function() {
    image_resize_width();
  });

  function image_resize_width(){
    if ($(window).width() < 767){
      $("body > .main-container").addClass("main-container-resized");
      $("body > .main-container").removeClass("main-container");
      $("article .content img").each(function(){
        if ($(this).width() > $(window).width()){
          $(this).width("100%");
          $(this).height("auto");
          $(this).attr("resized", "true");
        }
      });
    }
    else{
      $("body > .main-container-resized").addClass("main-container");
      $("body > .main-container-resized").removeClass("main-container-resized");
      $("article .content img").each(function(){
        if ($(this).attr("resized")){
          $(this).width("");
          $(this).height("");
          $(this).removeAttr("resized");
        }
      });
    }
  }

  $(document).ready(function () {
    image_resize_width();

      $( ".close-env-info" ).click(function(){
          if ($('.env-info').is(":visible")){
              $('.environnement-info').hide();
          }
      });


  });


})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

