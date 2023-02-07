class StickyHeader {
  constructor() {
    this.$header = document.querySelector('header');
    this.$socialShareBlock = document.getElementById('block-socialshareblock');
    this.$megaMenuMobile = document.querySelector('#navbar-collapse-mega.navbar-collapse');
    let lastScrollTop = 0;
    const threshold = 5; //une marge de sécurité pour qu'un simple mouvement de souris face pas disparaitre le header

    if (document.getElementById('local_nav')) {
      this.$pageMenu = document.getElementById('local_nav');
    }

    $(window).resize(() => {
      this._setHeaderTop();
      this._setSocialShareBlockTop();
    });

    if (this._isConnected()) {
      new MutationObserver((mutations) => {
        mutations.forEach((mutationRecord) => {
          if (mutationRecord.oldValue !== mutationRecord.target.style.cssText) {
            this._setHeaderTop();
            this._setPageMenuTop();
            this._setSocialShareBlockTop();
          }
        });
      }).observe(document.querySelector('body'), {attributeOldValue: true, attributeFilter: ['style']});
    }

    new IntersectionObserver( ([e]) => {
        this._setSocialShareBlockTop();
        this._setMegaMenuMobileCollapseIn();
        if (e.intersectionRatio < 1) {
          this.$header.classList.add("not-visible");
        }
      },
      {threshold: 0}
    ).observe(document.querySelector('header'));

    $(window).scroll(() => {
      let scrollTop = $(window).scrollTop();
      this._setHeaderTop();
      this._setPageMenuTop();

      // Safari iOS + Mac specific hook - pour calculer le scrollDown. Safari fait du scrollDown négatif
      let scrollDown = $(document).height() - $(window).height() - scrollTop;

      if(Math.abs(lastScrollTop - scrollTop) >= threshold) {
        if (!(scrollTop > lastScrollTop && scrollDown > 0)) {
          //Scroll Up
          this.$header.classList.add("transition");
          this.$header.classList.add("is-visible");
          this.$header.classList.remove("not-visible");
        }
        else {
          //Scroll Down
          this.$header.classList.remove("is-visible");
          this.$header.classList.remove("transition");
        }

        lastScrollTop = scrollTop;

        if (lastScrollTop < threshold) {
          this.$header.classList.remove("is-visible");
          this.$header.classList.remove("transition");
          this._setSocialShareBlockTop();
          this._setHeaderTop();
          this._setPageMenuTop();
          this._setMegaMenuMobileCollapseIn();
        }

        if (document.getElementById('local_nav')) {
          if (!this.$header.classList.contains('is-visible')) {
            this.$pageMenu.classList.add("no-transition");
            this.$pageMenu.classList.remove("transition");
          } else {
            this.$pageMenu.classList.add("transition");
            this.$pageMenu.classList.remove("no-transition");
          }
        }


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

        // On ferme le megamenu mobile s'il est ouvert au scroll
        $('#navbar-collapse-mega.navbar-collapse').each((key, elem)=> {
          if ($(elem).hasClass('in')) {
            $(elem).collapse("toggle");
          }
        });
      }
    });
  }

  _setHeaderTop() {
    let top = this._getBodyPaddingTop() - this.$header.offsetHeight;

    if (this._isConnected()) {
      if (window.matchMedia("(max-width: 736px)").matches) {
        top = -this.$header.offsetHeight;
      }
    }

    if (this.$header.classList.contains('is-visible')) {
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

  _setMegaMenuMobileCollapseIn() {
    let top = this.$header.classList.contains('is-visible') ? this.$header.offsetHeight
      : this._getBodyPaddingTop() + this.$header.offsetHeight;

    top-= 5; //Bug sur le header qui est en "top -5px"

    let bottom = this.$header.classList.contains('is-visible') ? - $(window).height() : 0;

    this.$megaMenuMobile.style.top = `${top}px`;
    this.$megaMenuMobile.style.bottom = `${bottom}px`;
  }

  _isConnected() {
    return document.querySelector('body').classList.contains('user-logged-in');
  }
}

new StickyHeader();
