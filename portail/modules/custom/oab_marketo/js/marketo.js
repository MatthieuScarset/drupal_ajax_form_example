(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {

    if (typeof drupalSettings.marketo_data !== 'undefined') {
      instantiateMktoForm(drupalSettings.marketo_data.mktoFormID, drupalSettings.marketo_data);
    }

    if (typeof utag_data !== 'undefined'
        && typeof drupalSettings.marketo_data_for_tealium !== 'undefined') {
      utag_data.version = drupalSettings.marketo_data_for_tealium.version;
      utag_data.sous_domaine = drupalSettings.marketo_data_for_tealium.sous_domaine;
      utag_data.univers_affichage = drupalSettings.marketo_data_for_tealium.univers_affichage;
      utag_data.id_article = drupalSettings.marketo_data.mktPdfName;
    }

  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
