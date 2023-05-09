(function ($, Drupal, Bootstrap) {

  // js essentiel pour le fonctionnement du mega-menu desktop one-i

  $('#megamenu_mobile .mega-menu').megamenu();
  $('#main_nav .mega-menu-desktop.mega-menu').megamenu();

  window.addEventListener("click", function(event) {
    $('#main_nav .mega-menu-desktop.mega-menu .item_mega_menu.mega-menu-panel').each(function(key, elem) {
      if ($(elem).hasClass('show')) {
        $(elem).collapse("toggle");
        $(elem).parent().removeClass('active');
      }
    });
  });

  window.onload = function() {
    document.getElementById('megamenu').onclick = function(e) {
      if ($('#main_nav .mega-menu-desktop.mega-menu .item_mega_menu.mega-menu-panel').hasClass('show') && !$(e.target).hasClass('close')) {
        e.stopPropagation();
      }
    }
  }

  //Changer le burger menu en une croix à l'ouverture
  var observer = new MutationObserver(function (event) {
    event.forEach((mutationRecord) => {

      if (mutationRecord.target.getAttribute('aria-expanded') === 'true') {

        $('#main_nav_mobile .sandwich-button > span').removeClass("navbar-toggler-icon").addClass("icomoon icomoon-ob1-cross");

      } else {

        $('#main_nav_mobile .sandwich-button > span').removeClass("icomoon icomoon-ob1-cross").addClass("navbar-toggler-icon");

      }
    });
  })

  document.querySelectorAll('.sandwich-button').forEach((e) => {
    observer.observe(e, {
      attributes: true,
      attributeFilter: ['aria-expanded'],
      childList: false,
      characterData: false
    })
  });

  // Gestion de l'ouverture du mega-menu

  $('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a').on('click', function () {
    $('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a').removeClass('active');
    $(this).addClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a:first').addClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane:first').addClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane:not(:first)').removeClass('active');
  });

  $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a')
    .on('focus', function (e) {
      // $(this).trigger("focus");
      $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a').removeClass("active");
      $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane').removeClass('active');
      $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane' + $(this).attr('data-target')).addClass('active');
      // $(this).closest('.mega-menu-panel').trigger('focus');
    })
    .on('mouseover', function(e) {
      $(this).trigger('focus');
    });


  // First observer pour afficher et cacher le top nanvbab sur les slider mobile du menu

  var navlink_observer = new MutationObserver(function (event) {
    event.forEach((mutationRecord) => {
      if (mutationRecord.target.tabIndex === -1) {
       $('#megamenu_mobile .top-navbar-mobile').addClass("d-none");
      } else if (mutationRecord.target.tabIndex === 0) {
        $('#megamenu_mobile .top-navbar-mobile').removeClass("d-none");
      }
    });
  })

  document.querySelectorAll('#main_nav_mobile .root-navbar-mobile li[data-menu-level="0"] > a.nav-link').forEach((e) => {
    navlink_observer.observe(e, {
      attributes: true,
      attributeFilter: ['tabindex'],
      childList: false,
      characterData: false
    })
  });

  var socialShareBlockObeserver = new MutationObserver(function (event) {
    event.forEach((mutationRecord) => {
      if (mutationRecord.attributeName === 'class') {
        $('#block-theme-one-i-socialshareblock').css('top', $('header').height());
      }

    });
  })

  document.querySelectorAll('#main_nav #block-theme-one-i-righticonblock .nav-item.share-icon .share-icon').forEach((e) => {
    socialShareBlockObeserver.observe(e, {
      attributes: true
    })
  });

  const smallLogo = $('#main_nav img.small-logo');
  const largeLogo = $('#main_nav img.large-logo');

  $(window).scroll(() => {
    if ($(window).scrollTop() > 0 && $('#main_nav').hasClass('small-header')) {
      smallLogo.addClass('d-lg-block');
      smallLogo.removeClass('d-lg-none');
      largeLogo.removeClass('d-lg-block');
    } else {
      smallLogo.removeClass('d-lg-block');
      smallLogo.addClass('d-lg-none');
      largeLogo.addClass('d-lg-block');
    }
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
