
class MenuPageOverride {
  constructor() {
    this.$is_scrolling = false;
    this.$pageMenu = $('.ob1-menu-page');
    this.$fixedItemsHeight = this._getFixedItemsHeight();
    this._defineCssTop();

    $(window).resize(() => {
      this._defineCssTop()
    });

    this.$pageMenu.find('ul.nav a.nav-link').click((e) => {this._onItemClick(e)});
    $(window).scroll((e) => this._onScroll());

    this.$bodyCssChanged = new MutationObserver((mutations) => {
      this._defineCssTop();
    });
    this.$bodyCssChanged.observe(document.querySelector('body'), { attributes : true, attributeFilter : ['style'] });



    // get the sticky element
    this.$stickyHeaderObserver = new IntersectionObserver(
      ([e]) => {
        const supra_navbar = $('header .navbar.supra');
        const supra_navbar_height = supra_navbar.height();
        const pagemenu_parent = this.$pageMenu.parent();

        document.querySelector('header, header .navbar-brand img').ontransitionend = (e) => {
          if (e.propertyName === 'height' || e.propertyName === 'width') {
            this.$fixedItemsHeight = this._getFixedItemsHeight();
            pagemenu_parent.css('top', $('header').height());
            $('#block-theme-one-i-socialshareblock').css('top', $('header').height());
          }
        };

        e.target.classList.toggle('is-sticky', e.intersectionRatio < 1);
        if (e.intersectionRatio < 1) {
          pagemenu_parent.css('top', $('header').height() - supra_navbar_height);
          $('#block-theme-one-i-socialshareblock').css('top', $('header').height() - supra_navbar_height);
        } else {
          pagemenu_parent.css('top', $('header').height());
          $('#block-theme-one-i-socialshareblock').css('top', $('header').height());
        }
      },
      {threshold: [1]}
    );

    this.$stickyHeaderObserver.observe(document.querySelector('header'))
  }

  _defineCssTop() {
    let init = parseInt($('body').css('padding-top').replace("px", ''));
    init = init === 0 ? -1 : init;
    $('.sticky-top').each(function () {
      $(this).css('top', init);
      init += $(this).height();
    });
  }
  _getFixedItemsHeight() {
    let init = parseInt($('body').css('padding-top').replace("px", ''));
    $('.sticky-top').each(function () {
      init += $(this).height();
    });
    return init;
  }

  _onScroll() {
    if (this.$is_scrolling) {
      return;
    }

    let sticky_bottom_pos = $(window).scrollTop()
      + this.$fixedItemsHeight;  // Init with current page position

    const nav_links = this.$pageMenu.find('.nav-link');
    // On ne commence que quand on a dépassé le 1er element
    if ($(nav_links.first().attr('href')).offset().top <= sticky_bottom_pos) {
      nav_links.each(function() {
        const target = $(this).attr('href');
        $(this).parent().removeClass('active');
        if (target.length > 1
          && $(target).length
          && sticky_bottom_pos >= $(target).offset().top
          && sticky_bottom_pos < ($(target).offset().top + $(target).closest('.item-list').height())) {
          $(this).parent().addClass('active');
        }
      });
    }
  }

  _onItemClick(event) {
    const target = $(event.currentTarget).attr('href');
    if ($(target).length) {
      event.preventDefault();
      $('html,body').animate({
        scrollTop: $(target).offset().top - this.$fixedItemsHeight
      }, {
        duration:1000,
        start: () => {this.$is_scrolling = true},
        complete: () => {this.$is_scrolling = false}
      });
    }
  }
}


(function ($, Drupal, Bootstrap) {

  // Js essentiel pour le fonctionnement du mega-menu desktop one-i

  $('#megamenu_mobile .mega-menu').megamenu();
  $('.mega-menu').megamenu();



  //Gestion fermeture du méga-menu

/*  $(document).on('click', function (e){
    $('.mega-menu-desktop .navbar-nav .item_mega_menu.mega-menu-panel').removeClass('show');
    if (!$(e.target).is('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a')) {
      $('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a').removeClass('active');
    }
  });*/

  // Gestion de l'ouverture du mega-menu

  $('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a').on('click', function () {
    $('.mega-menu-desktop .navbar-nav .nav-item.nav_item_dropdown > a').removeClass('active');
    $(this).addClass('active');
    if ($('.mega-menu-desktop .mega-menu-panel.item_mega_menu').hasClass('show')){}
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a:first').addClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane:first').addClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane:not(:first)').removeClass('active');
  });

  $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a').on('mouseover', function (e) {
    $(this).trigger("focus");
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .nav-pills a:first').removeClass("active");
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane').removeClass('active');
    $('.mega-menu-desktop .mega-menu-panel.item_mega_menu .tab-content .tab-pane' + $(this).attr('data-target')).addClass('active');
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

  new MenuPageOverride();
})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

