class ManageStickyTop {
  constructor() {
    this._defineCssTop();
    this.$header = $("header");
    this.$adminToolbarHeight = 0;

    $(document).ready(() => {
      this.$adminToolbarHeight += ($('#toolbar-bar').length ? $('#toolbar-bar').height() : 0) +
        ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length ? $('#toolbar-item-administration-tray.toolbar-tray-horizontal').height() : 0);
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
        //const header = $('header');

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
      if (scrollTop > this.$lastScrollTop) {
        // Scroll down
        this.$header.removeClass("is-visible");
      } else {
        // Scroll Up
        this.$header.addClass("is-visible");
        this.$header.css("top", this.$adminToolbarHeight);
        this.$header.removeClass("not-visible");

      }
      this.$lastScrollTop = scrollTop;
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
