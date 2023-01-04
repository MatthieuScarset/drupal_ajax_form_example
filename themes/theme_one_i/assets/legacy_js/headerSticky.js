class ManageStickyTop {
  constructor() {
    this._defineCssTop();

    $(window).resize(() => {
      this._defineCssTop()
    });


    /**
     * Petit hack pour la partie connectée
     * je le garde en hack car l'autre facon est plus "JS"
     * + evite de faire des actions à chaque scroll du user (donc moins gourmand)
     */
    if ($('body').hasClass('user-logged-in')) {
      $(window).scroll((elem) => {
        if ($(window).scrollTop()) {
          $('header').addClass('is-sticky');
        } else {
          $('header').removeClass('is-sticky');
        }
      });
    }


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
      this._manageStickyHeader,
      {threshold: [1]}
    );

    this.$stickyHeaderObserver.observe(document.querySelector('header'))


    //
    // var observer = new MutationObserver(function (event) {
    //   event.forEach((mutationRecord) => {
    //     if (mutationRecord.target.getAttribute('aria-expanded') === 'true') {
    //       const target = $(mutationRecord.target);
    //       const item = $(target.attr('href'));
    //       if (item.length) {
    //         console.log(item);
    //         alert("coucou");
    //         item.focus();
    //       }
    //     }
    //   });
    // })
    //
    // document.querySelectorAll('#main_nav ul.navbar-nav > li.nav-item > a.nav-link').forEach((e) => {
    //   observer.observe(e, {
    //     attributes: true,
    //     attributeFilter: ['aria-expanded'],
    //     childList: false,
    //     characterData: false
    //   })
    // });

  }

  _manageStickyHeader([e]) {
    const supra_navbar = $('header .navbar.supra');
    const supra_navbar_height = supra_navbar.height();
    const header = $('header');

    e.target.classList.toggle('is-sticky', e.intersectionRatio < 1);
    if (e.intersectionRatio < 1) {
      $('#block-theme-one-i-socialshareblock').css('top', header.height() - supra_navbar_height);
    } else {
      $('#block-theme-one-i-socialshareblock').css('top', header.height());
    }
  }


  _defineCssTop() {
    let init = this._getBodyPaddingTop();
    init = init === 0 ? -1 : init;
    $('.sticky-top').each(function () {
      $(this).css('top', init);
      init += $(this).height();
    });
  }

  _getBodyPaddingTop() {
    return parseInt($('body').css('padding-top').replace("px", ''));
  }

}

new ManageStickyTop();
