class StickyHeader {
  constructor() {
    this.$header = document.querySelector('header');
    this.$mainNav = document.getElementById('main_nav');
    this.$socialShareBlock = document.getElementById('block-socialshareblock');
    this.$topNavBar = document.getElementById('navtop').parentElement;
    this.$megaMenuMobile = document.querySelector('#navbar-collapse-mega.navbar-collapse');
    let lastScrollTop = 0;
    let isOnInitialPos = true;
    let isFirstScroll = true;
    const threshold = 5; //une marge de sécurité pour qu'un simple mouvement de souris face pas disparaitre le header

    if (document.getElementById('local_nav')) {
      this.$pageMenu = document.getElementById('local_nav');
    }

    $(window).resize(() => {
      this._setHeaderTop(isOnInitialPos);
      this._setPageMenuTop();
      this._setSocialShareBlockTop();
      this._setMegaMenuMobileCollapseIn(isOnInitialPos);
    });

    if (this._isConnected()) {
      new MutationObserver((mutations) => {
        mutations.forEach((mutationRecord) => {
          if (mutationRecord.oldValue !== mutationRecord.target.style.cssText) {
            this._setHeaderTop(isOnInitialPos);
            this._setPageMenuTop();
            this._setSocialShareBlockTop();
            this._setMegaMenuMobileCollapseIn(isOnInitialPos);
          }
        });
      }).observe(document.querySelector('body'), {attributeOldValue: true, attributeFilter: ['style']});
    }

    new IntersectionObserver( ([e]) => {
        this._setSocialShareBlockTop();
        this._setHeaderTop(isOnInitialPos);
        this._setPageMenuTop();

        if (window.matchMedia("(max-width: 980px)").matches) {
          this.$header.style.position = 'sticky';
          this._setMegaMenuMobileCollapseIn(isOnInitialPos);
        }
      },
      {threshold: 0}
    ).observe(document.querySelector('header'));

    $(window).scroll(() => {
      this._setPageMenuTop();
      let scrollableSpace = $(document).height() - $(window).height();
      let isScrollDown = false;
      let scrollTop = $(window).scrollTop();
      isOnInitialPos = scrollTop < threshold;
      this._setMegaMenuMobileCollapseIn(isOnInitialPos);

      // Safari iOS + Mac specific hook - pour calculer le scrollDown. Safari fait du scrollDown négatif
      let scrollDown = scrollableSpace - scrollTop;

      if(Math.abs(lastScrollTop - scrollTop) >= threshold && !window.matchMedia("(max-width: 980px)").matches) {

        if (scrollTop > lastScrollTop && scrollDown > 0 || scrollTop === scrollableSpace) {
          isScrollDown = true;
        } else if (scrollTop >= this.$header.offsetHeight && isFirstScroll){
          isFirstScroll = false;
        } else if (isOnInitialPos) {
          isFirstScroll = true;
        }

        if (scrollTop >= (this.$header.offsetHeight)) {
          this._changeHeaderOnScroll(isScrollDown, isFirstScroll);
        }

        lastScrollTop = scrollTop;
        isOnInitialPos = lastScrollTop < threshold;

        this._resetHeader(isOnInitialPos);

        // On ferme le megamenu descktop s'il est ouvert au scroll
        $('#navbar-collapse-mega .nav-menu .nav-item').each(function (key,elem) {
          if ($(elem).hasClass('open')) {
            $(elem).removeClass('open');
          }
        });

        // On ferme la social share block s'il est ouvert au scroll
        $('#social-share').each((key, elem) => {
          if ($(elem).hasClass('in')) {
            $(elem).collapse("toggle");
          }
        });
      }
      this._setHeaderTop(isOnInitialPos);
    });
  }

  _setHeaderTop($isOnTop) {
    let top = this._getBodyPaddingTop() - this.$header.offsetHeight;

    if (!this._isConnected()) {
      if (window.matchMedia("(max-width: 980px)").matches) {
        top = this._getBodyPaddingTop();
      } else {
        top--;
      }
    }
    else {
      //Connecter en mobile on tiendra pas compte du body padding
      if (window.matchMedia("(max-width: 980px)").matches) {
        top = $isOnTop ? -this.$header.offsetHeight : 0;
      }
    }

    if (this.$header.classList.contains('is-visible')
      || (!window.matchMedia("(max-width: 980px)").matches && !this.$mainNav.classList.contains('small-header'))) {
      this.$header.style.top = `${this._getBodyPaddingTop()}px`;
    } else {
      this.$header.style.top = `${top}px`;
    }
  }

  _setPageMenuTop() {
    let top = this.$header.classList.contains('is-visible') ? this._getBodyPaddingTop() + this.$header.offsetHeight
      : this._getBodyPaddingTop();

    if (this.$pageMenu) {
      this.$pageMenu.style.top = `${top}px`;
    }
  }

  _changeHeaderOnScroll($scrollDown, $firstScroll) {
    // ajout transition opacité pour éviter l'apparition du header lors de la première disparition
    if ($firstScroll) {
      this.$header.style.opacity = '0';
      this.$header.style.transition = 'opacity 0s linear';
    } else {
      this.$header.style.opacity = '1';
      this.$header.style.transition = 'opacity 0s linear, top 0.8s ease';
    }

    if ($scrollDown) {
      //Scroll Down
      this.$header.classList.remove("is-visible");
      this.$header.classList.add("not-visible");
      this.$header.style.position = 'sticky';
      this.$mainNav.classList.add('small-header');
      this.$topNavBar.style.display = 'none';
    }
    else {
      //Scroll Up
      this.$header.classList.remove("not-visible");
      this.$header.classList.add("is-visible");
    }
  }

  _resetHeader($isOnTop) {
    if ($isOnTop) {
      this.$header.classList.remove("is-visible");
      this.$header.style.position = 'initial';
      this.$topNavBar.style.display = 'block';
      this.$mainNav.classList.remove('small-header');
      this._setSocialShareBlockTop();
    }
  }

  _getBodyPaddingTop() {
    if (document.querySelector('body').style.paddingTop.length) {
      return parseInt((document.querySelector('body').style.paddingTop).replace("px", ''));
    }
    return 0;
  }

  _setSocialShareBlockTop() {
    let top = this.$header.offsetHeight + this._getBodyPaddingTop();
    this.$socialShareBlock.style.top = `${top}px`;
  }

  _setMegaMenuMobileCollapseIn($isOnTop) {
    let top = this._getBodyPaddingTop() + this.$header.offsetHeight;

    if (!window.matchMedia("(max-width: 980px)").matches || (this._isConnected() && !$isOnTop)) {
      top = this.$header.offsetHeight;
    }

    let bottom = this.$header.classList.contains('is-visible') ? - $(window).height() : 0;

    this.$megaMenuMobile.style.top = `${top}px`;
    this.$megaMenuMobile.style.bottom = `${bottom}px`;
  }

  _isConnected() {
    return document.querySelector('body').classList.contains('user-logged-in');
  }
}

new StickyHeader();
