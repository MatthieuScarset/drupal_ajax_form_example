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




  });

  function getHeaderBarHeight() {
    //pour compter le decalage à faire à cause des barres sticky
    var decalSticky = 0;
    if ($("#toolbar-bar")) {  //Si la toolbar-bar existe, je recupère de quoi decaller
      decalSticky += $("#toolbar-bar").height();

      var toolbarAdmin = $("#toolbar-item-administration-tray");
      if (toolbarAdmin && toolbarAdmin.hasClass("is-active toolbar-tray-horizontal")) {
        decalSticky += toolbarAdmin.height();
      }
    }

    //Je recupère la hauteur de la header bar maintenant
    if ($("#main_nav")) {
      decalSticky += $("#main_nav").height();
    }

    return decalSticky;
  }


  function showhideFilters() {
    //je recupère la hauteur de la scrollBar
    var scroll = $(window ).scrollTop();
    var win = scroll + getHeaderBarHeight();  //Je l'ajouter à la hauteur Sticky

    //Je ne le fait que dans les pages ou l'ancre existe
    if ($("#ancre-back-to-filter").length) {
      //je recupère la distance de mon element par rapport au haut de la fenetre
      var elem = $("#ancre-back-to-filter").offset().top;

      //Si scroll+Sticky > distanceElement (cad l'element est caché)
      //alors j'affiche la flèche
      if (win > elem) {
        $("#arrow-back-to-filter").removeClass("hidden");
      } else {
        $("#arrow-back-to-filter").addClass("hidden");
      }
    }
  }

  //Pour afficher la flèche vers l'ancre du filtre lorsque les filtres ne sont plus visibles
  $(window).scroll(function(){
    showhideFilters();
  });

  //Pour savoir si j'affiche la flèche au chargement de la page
  // (Quand on refresh, la page garde sa position.. Donc le scroll ne fonctionne pas)
  $(document).ready(function () {
    showhideFilters();
  });


  //Pour re-afficher les filtres en appuyant sur la flèche...
  $(document).on("click", '#link-back-to-filter', function(event) {

    var ancre = $(this).attr('href');   //Je recupère l'id de l'ancre contenu dans le href

    var decalSticky = getHeaderBarHeight();

    //On recupère la position de la div de l'ancre
    var postitionAncre = $(ancre).offset();

    if (postitionAncre) {   //je vérifie que j'ai bien la position de l'ancre souhaitée
      var top = postitionAncre.top;
      top -= decalSticky + 10;    //J'enlève la taille des elements stickys trouvés; je rajoute 10 de marge

      //On décale l'element avec un petit effet
      $("html, body").animate({ scrollTop: top }, "slow");
    }

    //Je return false pour desactiver le lien vers l'ancre par le navigateur
    return false;
  });

  Drupal.behaviors.myBehaviour = {
    attach: function (context, settings) {
      //On s'occupe de Facebook
      if (settings.myLibrary.share_siteUrls.facebook.length) {
        $("a.share-button-facebook").each(function() {
          $(this).attr("href",settings.myLibrary.share_siteUrls.facebook );
        });
      }

      //Maintenant de linkedin
      if (settings.myLibrary.share_siteUrls.linkedin.length) {
        $("a.share-button-linkedin").each(function() {
          $(this).attr("href",settings.myLibrary.share_siteUrls.linkedin );
        });
      }

      //Et enfin de twitter
      if (settings.myLibrary.share_siteUrls.twitter.length) {
        $("a.share-button-twitter").each(function() {
          $(this).attr("href",settings.myLibrary.share_siteUrls.twitter );
        });
      }

    }
  };

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);



