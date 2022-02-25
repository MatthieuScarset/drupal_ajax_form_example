
(function ($, Drupal, Bootstrap) {
  $(document).ready(function() {

    //on sélectionne un type_of_cloud_service => on change la couleur du bouton en Orange pour montrer qu'il faut appliquer le filtre
    $(document).on('change', '#views-exposed-form-bvpn-gallery-csp-list-page select[name="type_of_cloud_service"]',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-list-page .form-actions .btn_submit_filter_search_list_csp').addClass('active');
    });

    //on sélectionne un service_providers => on change la couleur du bouton en Orange pour montrer qu'il faut appliquer le filtre
    $(document).on('change', '#views-exposed-form-bvpn-gallery-csp-list-page select[name="service_providers"]',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-list-page .form-actions .btn_submit_filter_search_list_csp').addClass('active');
    });

    //on sélectionne une location => on change la couleur du bouton en Orange pour montrer qu'il faut appliquer le filtre
    $(document).on('change', '#views-exposed-form-bvpn-gallery-csp-list-page select[name="location"]',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-list-page .form-actions .btn_submit_filter_search_list_csp').addClass('active');
    });

    //on écrit une recherche => on change la couleur du bouton en Orange pour montrer qu'il faut appliquer le filtre
    $(document).on('input', '#views-exposed-form-bvpn-gallery-csp-list-page input[name="title"]',function() {
      $('.view-bvpn-gallery #views-exposed-form-bvpn-gallery-csp-list-page .form-actions .btn_submit_filter_search_list_csp').addClass('active');
    });

  });
})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
