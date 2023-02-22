class StickyHeader {
  constructor() {
    this.$header = document.querySelector('header');
    this.$mainNav = document.getElementById('main_nav');
    this.$socialShareBlock = document.getElementById('block-theme-one-i-socialshareblock');
    this.$mainNavMobile = document.getElementById('main_nav_mobile');
    this.$topNavBar = document.getElementsByClassName('supra');
    this.$megaMenuMobile = document.getElementById('megamenu_mobile');
    let lastScrollTop = 0;
    const threshold = 5; //une marge de sécurité pour qu'un simple mouvement de souris face pas disparaitre le header

    if (document.querySelector('.ob1-menu-page')) {
      this.$pageMenu = document.querySelector('.ob1-menu-page').parentElement;
    }

    $(window).resize(() => {
      this._setHeaderTop();
      this._setSocialShareBlockTop();
      this._setMegaMenuMobileCollapseShow();
    });

    new IntersectionObserver( ([e]) => {
      this._setSocialShareBlockTop();
      this._setMegaMenuMobileCollapseShow();
      this._setHeaderTop();
    },
    {threshold: 0}
    ).observe(document.querySelector('header'));

    if (this._isConnected()) {
      new MutationObserver((mutations) => {
        mutations.forEach((mutationRecord) => {
          if (mutationRecord.oldValue !== mutationRecord.target.style.cssText) {
            this._setHeaderTop();
            this._setSocialShareBlockTop();
          }
        });
      }).observe(document.querySelector('body'), {attributeOldValue: true, attributeFilter: ['style']});
    }

    $(window).scroll(() => {
      let scrollTop = $(window).scrollTop();
      this._setHeaderTop();

      // Safari iOS + Mac specific hook - pour calculer le scrollDown. Safari fait du scrollDown négatif
      let scrollDown = $(document).height() - $(window).height() - scrollTop;

      if(Math.abs(lastScrollTop - scrollTop) >= threshold && this._isHidden(this.$mainNavMobile)) {

        let isScrollDown = scrollTop > lastScrollTop && scrollDown > 0;

        if (scrollTop >= this.$header.offsetHeight) {
          this._changeHeaderOnScroll(isScrollDown);
        }

        lastScrollTop = scrollTop;

        let isOnInitialPos = lastScrollTop < threshold;
        this._resetHeader(isOnInitialPos);

        if (!this.$header.classList.contains('is-visible')) {
          this.$pageMenu.classList.remove("transition");
        } else {
          this.$pageMenu.classList.add("transition");
        }

        // On ferme le megamenu descktop s'il est ouvert au scroll
        $('#main_nav .mega-menu-desktop.mega-menu .item_mega_menu.mega-menu-panel').each(function (key,elem) {
          if ($(elem).hasClass('show')) {
            $(elem).collapse("toggle");
            $(elem).parent().removeClass('active');
          }
        });

        // On ferme la social share block s'il est ouvert au scroll
        $('#social-share').each((key, elem) => {
          if ($(elem).hasClass('show')) {
            $(elem).collapse("toggle");
          }
        });

      }
    });
  }
  _setHeaderTop() {
    let top = this._getBodyPaddingTop() - this.$header.offsetHeight;

    if (!this._isConnected()) {
      top--;    //Bug sur le header qui est en "top -1px"
    }
    else {
      //Connecter en mobile on tiendra pas compte du body padding
      if (window.matchMedia("(max-width: 736px)").matches) {
        top = -this.$header.offsetHeight;
      }
    }

    if (this.$header.classList.contains('is-visible') || !this.$mainNav.classList.contains('small-header')) {
      this.$header.style.top = `${this._getBodyPaddingTop()}px`;
    } else {
      this.$header.style.top = `${top}px`;
    }
  }

  _changeHeaderOnScroll($scrollDown) {
    if ($scrollDown) {
      this.$header.classList.remove("transition");
      this.$header.classList.remove("is-visible");
      this.$header.classList.add("not-visible");
      this.$header.style.position = 'sticky';
      this.$mainNav.classList.add('small-header');
      this.$topNavBar[0].classList.add("d-none");
    } else {
      this.$header.classList.remove("not-visible");
      this.$header.classList.add("transition");
      this.$header.classList.add("is-visible");
    }
  }

  _resetHeader($isOnTop) {
    if ($isOnTop) {
      this.$header.classList.remove("transition");
      this.$header.classList.remove("is-visible");
      this.$header.style.position = 'initial';
      this.$topNavBar[0].classList.remove("d-none");
      this.$mainNav.classList.remove('small-header');
      this._setSocialShareBlockTop();
      this._setHeaderTop();
      this._setMegaMenuMobileCollapseShow();
    }
  }

  _setSocialShareBlockTop() {
    let top = this.$header.offsetHeight + this._getBodyPaddingTop();
    this.$socialShareBlock.style.top = `${top}px`;
  }

  _setMegaMenuMobileCollapseShow() {
    let top = this.$header.classList.contains('is-visible') ? this.$header.offsetHeight
    : this._getBodyPaddingTop() + this.$header.offsetHeight;

    let bottom = this.$header.classList.contains('is-visible') ? - $(window).height() : 0;

    this.$megaMenuMobile.style.top = `${top}px`;
    this.$megaMenuMobile.style.bottom = `${bottom}px`;
  }

  _getBodyPaddingTop() {
    if (document.querySelector('body').style.paddingTop.length) {
      return parseInt((document.querySelector('body').style.paddingTop).replace("px", ''));
    }
    return 0;
  }

  _isConnected() {
    return document.querySelector('body').classList.contains('user-logged-in');
  }

  _isHidden(el) {
    return (typeof el !== 'undefined' && el.offsetParent === null)
  }
}

new StickyHeader();
