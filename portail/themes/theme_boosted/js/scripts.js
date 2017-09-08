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


      $('#tab-expertise-banner a').click(function (e) {
          e.preventDefault();
          $(this).tab('show');
      });

      $('.slick-mode').slick({
          infinite: true,
          dots: false,
          arrows: false,
          responsive: [
              {
                  breakpoint: 768,
                  settings: {
                      dots: true
                  }
              },
          ],
      });

      // Homepage carousel solution & industries
      $('#home-slick-carousel-left-prev_arrow').on('click', function(){
          console.log('click on prevArrow ok');
          $('#slick-left-zone').slick("slickPrev");
      });
      $('#home-slick-carousel-left-next_arrow').on('click', function(){
          console.log('click on nextArrow ok');
          $('#slick-left-zone').slick("slickNext");
      });
      $('#home-slick-carousel-right-prev_arrow').on('click', function(){
          console.log('click on prevArrow ok');
          $('#slick-right-zone').slick("slickPrev");
      });
      $('#home-slick-carousel-right-next_arrow').on('click', function(){
          console.log('click on nextArrow ok');
          $('#slick-right-zone').slick("slickNext");
      });

      //Tabs Homepage Expertise Banner
      $('.nav-tabs-dropdown').each(function(i, elm) {
          $(elm).text($(elm).next('ul').find('li.active a').text());
          $(elm).append('<span class="caret"></span>');
      });

      $('.nav-tabs-dropdown').on('click', function(e) {
          e.preventDefault();
          $(e.target).toggleClass('open').next('ul').slideToggle();
      });

      $('#tab-expertise-banner a[data-toggle="tab"]').on('click', function(e) {
          e.preventDefault();
          $(e.target).closest('ul').hide().prev('button').removeClass('open').text($(this).text());
          $(e.target).closest('ul').prev('button').append('<span class="caret"></span>');
      });

  });


})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

