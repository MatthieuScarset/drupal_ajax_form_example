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


      // Wait 3s to be sur the marketo form is instantiated
      setTimeout(() => {

        const urlParams = new URLSearchParams(window.location.search);
        let data = urlParams.get('data');
        if (!data) {
          return;
        }

        data = JSON.parse(atob(data));

        const mktoForm = document.querySelector(".mktoForm");
        if (data && mktoForm) {
          console.log(data);
          for (const [key, value] of Object.entries(data)) {
            const input = mktoForm.querySelector(`input[name=${key}]`);
            if (input) {
              input.value = value;
            }
          }
        }

      }, 3000);
      instantiateMktoForm(drupalSettings.marketo_data.mktoFormID, drupalSettings.marketo_data);

    }

  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
