class ManageStickyTop {
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
      this._defineCssTop();
      const scrollTop = $(window).scrollTop();
      this.$headerTop = this.$adminToolbarHeight - this.$header.outerHeight();
      this.$localNavTop =this.$adminToolbarHeight + this.$header.outerHeight();

      if (scrollTop >= this.$lastScrollTop) {
        // Scroll down
        this.$header.removeClass("is-visible");

      } else {
        // Scroll Up
        this.$header.css("top", this.$headerTop);
        this.$header.addClass("is-visible");
        this.$localNav.css("top", this.$localNavTop);
        this.$header.removeClass("not-visible");
        this.$localNav.removeClass("transition");
        this.$header.addClass("transition");
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
    });
  }

  _defineCssTop() {
    let init = this._getBodyPaddingTop();
    init = init === 0 ? -1 : init;
    $('.sticky').each(function () {
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

new ManageStickyTop();
