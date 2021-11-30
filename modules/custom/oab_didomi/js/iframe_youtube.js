/*
 * Custom element data-attributes :
 * - data-url : url de la micro app,
 * - data-url-vie : url de vie de la micro app,
 * - data-with-params : s'il y a besoin d'appeler l'iframe avec les query de l'URL courante,
 * - data-config : specific config, au format Json
 */
export default class DivIframeYoutube extends HTMLDivElement {

  constructor() {
    super();

    this.$iFrameChild = this.querySelector('iframe');
    this.$divMessageBlockChild = this.querySelector('.divParentBlockMessageCookie');

    //ajout de l'évènement Didomi pour vérifier les cookies
    window.didomiOnReady = window.didomiOnReady || [];
    window.didomiOnReady.push(() => this._manageCookieStatus());

    this.querySelector('.btn_accept_cookie_youtube').addEventListener('click', function(event) {this._acceptYoutubeCookies(event)}.bind(this));
  }


 _manageCookieStatus(){
    if (typeof Didomi === 'undefined') {
      return;
    }
    if (this.$iFrameChild.length === 0) {
      return;
    }

    var youtubeDidomi = Didomi.getUserStatusForVendor(drupalSettings.didomi.vendor_id_youtube);
    if (youtubeDidomi == false || youtubeDidomi == undefined) {
      this._switchDisplay(false);
    } else if (youtubeDidomi == true) {
      this._switchDisplay(true);
    }
  }

  _switchDisplay(cookieOk){
    if(cookieOk) {
      this.$iFrameChild.src = this.$iFrameChild.getAttribute('data-src');
      this.$iFrameChild.style.display = 'block';
      this.$divMessageBlockChild.style.display = 'none';
    }
    else {
      this.$iFrameChild.src = '';
      this.$iFrameChild.style.display = 'none';
      this.$divMessageBlockChild.style.display = 'block';
    }
  }


  _acceptYoutubeCookies(){
    //on récupère le UserConsent
    var userConsent = Didomi.getUserStatus();
    var vendor = drupalSettings.didomi.vendor_id_youtube;
    //ajout de l'élément dans les vendor enabled
    if(!userConsent.vendors.consent.enabled.includes(vendor)) {
      userConsent.vendors.consent.enabled.push(vendor);
    }
    //suppression de l'élément dans les vendor disabled
    for (var i = 0; i < userConsent.vendors.consent.disabled.length; i++) {
      if (userConsent.vendors.consent.disabled[i] === vendor) {
        userConsent.vendors.consent.disabled.splice(i, 1);
      }
    }
    //on enregistre le nouvel UserConsent
    Didomi.setUserStatus(userConsent);
    this._switchDisplay(true);
  }
}
customElements.define('div-iframe-youtube', DivIframeYoutube, {extends: 'div'})
