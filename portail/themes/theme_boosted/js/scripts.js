/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {

  $( window ).resize(function() {
    image_resize_width();
    obs_template_height();
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

  function obs_template_height(){
    $(".obs_template > div").height('auto');
    $(".obs_template div[class*= obs_background_]").height('auto');
    $(".obs_template").each(function() {
      var max_height = 0;
      $(this).children().each(function(){
        var paddings = parseInt($(this).css('padding-top')) + parseInt($(this).css('padding-bottom'));
        var margins = parseInt($(this).css('margin-top')) + parseInt($(this).css('margin-bottom'));
        if (($(this).height() - paddings - margins) > max_height){
          max_height = $(this).height() - paddings - margins;
        }
      });

      if ($(this).children().find("div[class*= obs_background_]").length > 0) {
        $(this).children().find("div[class*= obs_background_]").each(function () {
          var paddings = parseInt($(this).css('padding-top')) + parseInt($(this).css('padding-bottom'));
          var margins = parseInt($(this).css('margin-top')) + parseInt($(this).css('margin-bottom'));
          $(this).height(max_height - paddings - margins);
        });

        $(this).children().height(max_height);
      }
    });
  }

  $(document).ready(function () {
    image_resize_width();
    obs_template_height();

      $( ".close-env-info" ).click(function(){
          if ($('.env-info').is(":visible")){
              $('.environnement-info').hide();
          }
      });


      //initialize swiper when document ready
      var mySwiperHomepage = new Swiper ('.swiper-container', {
          // Optional parameters
          direction: 'horizontal',
          loop: true,
          pagination : '.swiper-pagination',
          paginationType: 'bullets',
          // Responsive breakpoints
          breakpoints: {
              // when window width is <= 320px
              320: {
                  slidesPerView: 1,
                  spaceBetween: 10
              },
              // when window width is <= 480px
              480: {
                  slidesPerView: 1,
                  spaceBetween: 20
              },
              // when window width is <= 640px
              768: {
                  slidesPerView: 3,
                  spaceBetween: 30
              }
          }

      })

      //initialize swiper when document ready
      var mySwiperThematic = new Swiper ('.swiper-container-columns', {
          // Optional parameters
          direction: 'horizontal',
          loop: true,
          pagination : '.swiper-pagination',
          paginationType: 'bullets',
      })

  });





})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

