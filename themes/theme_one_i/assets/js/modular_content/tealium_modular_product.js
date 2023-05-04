
(function ($, Drupal, Bootstrap) {

  $(document).on("click", ".field--name-field-detail-offre .items-module-detail-offre .media-file-pdf", function(evt) {
    let track_cible =this.dataset.trackCible;
    let detail_offre_item = this.closest('[data-paragraph="module_detail_offre_items"]');
    if(detail_offre_item) {
      let track_nom = detail_offre_item.dataset.trackNom;
      let detail_offre = detail_offre_item.closest('[data-paragraph="module_detail_offre"]');
      if (detail_offre) {
        let track_zone = detail_offre.dataset.trackZone;
        utag_link(utag_data.titre_page, track_zone, track_nom, track_cible);
      }
    }
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);


