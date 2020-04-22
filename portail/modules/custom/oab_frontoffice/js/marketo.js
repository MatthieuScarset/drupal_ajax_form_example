(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {

    var formParameters = drupalSettings.data_for_construction_webform_marketo;

    if (formParameters != null) {
      formParameters.mktoPdfName = $('.merkato_mkt_pdf_name').data('name');
      formParameters.mktoPdfLink = $('.merkato_mkt_pdf_url').data('url');
      formParameters.mktoFieldOrder = ["submitButton", "LegalInfos"]; //info Api Marketo
      instantiateMktoForm(formParameters.mktoFormID, formParameters);
    }

  });



})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
