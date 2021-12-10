(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {

    if (typeof drupalSettings.marketo_altares_token !== 'undefined') {
      window.obsAltaresMarketo = drupalSettings.marketo_altares_token;
      delete drupalSettings.marketo_altares_token;
    }

    if (typeof drupalSettings.marketo_data !== 'undefined') {
      // Get referrer here instead of PHP beacause of akamai cache
      // Get referrer and remove the host
      let referrer = document.referrer;
      drupalSettings.marketo_data.mktoFrom = referrer.replace(window.location.origin, '');

      instantiateMktoForm(drupalSettings.marketo_data.mktoFormID, drupalSettings.marketo_data);
    }

  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
