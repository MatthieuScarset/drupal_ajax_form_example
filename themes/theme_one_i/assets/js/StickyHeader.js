class StickyHeader {
  constructor() {
    this._defineCssTop();
    this.$header = $("header");
    this.$localNav = $(".sticky.local-nav");
    this.$adminToolbarHeight = 0;

    $(document).ready(() => {
      let toolbarHeight = $('#toolbar-bar').length ? $('#toolbar-bar').height() : 0;
      let toolbarTrayHorizontalHeight = $('#toolbar-item-administration-tray.toolbar-tray-horizontal').length ?
        $('#toolbar-item-administration-tray.toolbar-tray-horizontal').height() : 0;
      this.$adminToolbarHeight = toolbarHeight + toolbarTrayHorizontalHeight;
    })

    $(window).resize(() => {
      this._defineCssTop()
    });

    this.$bodyCssChanged = new MutationObserver((mutations) => {
      this._defineCssTop();
    });
    this.$bodyCssChanged.observe(document.querySelector('body'), { attributes : true, attributeFilter : ['style'] });


    document.querySelector('header, header .navbar-brand img').ontransitionend = (e) => {
      if (e.propertyName === 'height' || e.propertyName === 'width') {
        $('#block-theme-one-i-socialshareblock').css('top', $(e.target).height());
        this._defineCssTop();
      }
    };

    // get the sticky element
    this.$stickyHeaderObserver = new IntersectionObserver(
      ([e]) => {
        const supra_navbar = $('header .navbar.supra');
        const supra_navbar_height = supra_navbar.height();

        e.target.classList.toggle('is-sticky', e.intersectionRatio < 1);

        if (e.intersectionRatio < 1) {
          this.$header.addClass("not-visible");
          $('#block-theme-one-i-socialshareblock').css('top',
            this.$header.height() - supra_navbar_height);
        }
        else {
          $('#block-theme-one-i-socialshareblock').css('top',
            this.$header.height());
        }
      },
      {threshold: 0}
    );
    this.$stickyHeaderObserver.observe(document.querySelector('header'))

    this.$lastScrollTop = 0;

    $(window).scroll(() => {
      const scrollTop = $(window).scrollTop();
      this.$headerTop = this.$adminToolbarHeight - this.$header.outerHeight();
      this.$localNavTop = this.$adminToolbarHeight + this.$header.outerHeight();
      // Safari iOS + Mac specific hook - pour calculer le scrollDown. Safari fait du scrollDown négatif
      this.$scrollDown = $(document).height() - $(window).height() - $(window).scrollTop();


      if (scrollTop >= this.$lastScrollTop && this.$lastScrollTop >= 0 && this.$scrollDown > 0) {
        // Scroll down
        this.$header.removeClass("is-visible");
        this.$localNav.css("top", this.$adminToolbarHeight);
        this.$header.addClass("no-transition");

      }
      // Je rajoute le > 0 car Safari fait du scrollUp négatif
      else if (this.$lastScrollTop > 0 && this.$scrollDown > 0){
        // Scroll Up
        this.$header.css("top", this.$headerTop);
        this.$header.addClass("is-visible");
        this.$localNav.css("top", this.$localNavTop);
        this.$header.removeClass("not-visible");
        this.$localNav.removeClass("transition");
        this.$header.addClass("transition");
        this.$header.removeClass("no-transition");
      }
      else {
        this.$header.addClass("no-transition");
        this.$header.removeClass("transition");
      }

      this.$lastScrollTop = scrollTop;

      if ( this.$lastScrollTop === 0) {
        this.$header.removeClass("is-visible");
        this.$header.removeClass("transition");
      }

      if (!this.$header.hasClass('is-visible')) {
        this.$localNav.removeClass("transition");
      } else {
        this.$localNav.addClass("transition");
      }

      $('#main_nav .mega-menu-desktop.mega-menu .item_mega_menu.mega-menu-panel').each(function (key,elem) {
        if ($(elem).hasClass('show')) {
          $(elem).collapse("toggle");
          $(elem).parent().removeClass('active');
        }
      });
    });
  }

  _defineCssTop() {
    let init = this._getBodyPaddingTop();
    init = init === 0 ? -1 : init;
    $('header.sticky').each(function () {
      if ($(this).css("visibility") === "visible") {
        $(this).css('top', init);
        init += $(this).height();
      }
    });
  }

  _getBodyPaddingTop() {
    return parseInt($('body').css('padding-top').replace("px", ''));
  }
}

new StickyHeader();
