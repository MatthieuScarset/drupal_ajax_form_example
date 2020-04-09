(function ($, Drupal, Bootstrap) {
  $(document).ready(function () {

    var mkt_to_domain = drupalSettings.marketo.mkt_to_domain;
    var mkt_to_munchkin_id = drupalSettings.marketo.mkt_to_munchkin_id;
    var mkt_to_form_id = drupalSettings.marketo.mkt_to_form_id;
    var mkt_custom_follow_up_url = drupalSettings.marketo.mkt_custom_follow_up_url;
    var mkt_form_follow_up_message = drupalSettings.marketo.mkt_form_follow_up_message;
    var mkt_version = drupalSettings.marketo.mkt_version;
    var mkt_sous_domaine = drupalSettings.marketo.mkt_sous_domaine;
    var mkt_univers_affichage = drupalSettings.marketo.mkt_univers_affichage;
    var mkt_theme = drupalSettings.marketo.mkt_theme;
    var mktoPdfRubrique = drupalSettings.marketo.mkto_pdf_rubrique;
    var mktoPdftype = drupalSettings.marketo.mkto_pdf_type;
    var mktoPdfSolution = drupalSettings.marketo.mkto_pdf_solution;
    var mktoPdfJobroles = drupalSettings.marketo.mkto_pdf_job_roles;
    var mktoPdfSegment = null;
    var mktoPdfCustomerjourney = null;
    var mktoPdfIndustrie = drupalSettings.marketo.mkto_pdf_industrie;
    var mkt_pdf_name = $('.merkato_mkt_pdf_name').data('name');
    var mkt_pdf_link = $('.merkato_mkt_pdf_url').data('url');


    if (typeof mkt_pdf_name == 'undefined' || mkt_pdf_name == null || mkt_pdf_name == ''){
      mkt_pdf_name = null;
    }
    if (typeof mkt_pdf_link == 'undefined' ||  mkt_pdf_link == null ||  mkt_pdf_link == ''){
      mkt_pdf_link = null;
    }
    if (typeof mkt_theme == 'undefined' || mkt_theme == null || mkt_theme == '') {
      mkt_theme = null;
    }
    if (typeof mktoPdfRubrique == 'undefined' || mktoPdfRubrique == null || mktoPdfRubrique == '') {
      mktoPdfRubrique = null;
    }
    if (typeof mktoPdftype == 'undefined' || mktoPdftype == null || mktoPdftype == '') {
      mktoPdftype = null;
    }
    if (typeof mktoPdfSolution == 'undefined' || mktoPdfSolution == null || mktoPdfSolution == '') {
      mktoPdfSolution = null;
    }
    if (typeof mktoPdfJobroles == 'undefined' || mktoPdfJobroles == null || mktoPdfJobroles == '') {
      mktoPdfJobroles = null;
    }
    if (typeof mktoPdfSegment == 'undefined' || mktoPdfSegment == null || mktoPdfSegment == '') {
      mktoPdfSegment = null;
    }
    if (typeof mktoPdfCustomerjourney == 'undefined' || mktoPdfCustomerjourney == null || mktoPdfCustomerjourney == '') {
      mktoPdfCustomerjourney = null;
    }
    if (typeof mktoPdfIndustrie == 'undefined' || mktoPdfIndustrie == null || mktoPdfIndustrie == '') {
      mktoPdfIndustrie = null;
    }

    var formParameters = {
      mktoDomain: mkt_to_domain,
      mktoMunchkinID: mkt_to_munchkin_id,
      mktoFormID: mkt_to_form_id,
      customFollowUpUrl: mkt_custom_follow_up_url,
      followUpMsgDiv: "FormFollowUpMessage_" + mkt_to_form_id,
      formName: "My Test Embed Form",
      mktoPdfName : mkt_pdf_name,
      mktoPdfLink : mkt_pdf_link,
      mktoPdfTheme: mkt_theme,
      mktoPdfRubrique: mktoPdfRubrique,
      mktoPdftype: mktoPdftype,
      mktoPdfSolution: mktoPdfSolution,
      mktoPdfJobroles: mktoPdfJobroles,
      mktoPdfSegment: mktoPdfSegment,
      mktoPdfCustomerjourney: mktoPdfCustomerjourney,
      mktoPdfIndustrie: mktoPdfIndustrie,
      mktoFieldOrder: ["submitButton", "LegalInfos"]
    };

    instantiateMktoForm(formParameters.mktoFormID, formParameters);

  });



})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
