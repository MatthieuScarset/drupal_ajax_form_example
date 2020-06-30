/**
 * Vision business related javascript
 * => Vgrid et dev pour faire fonctionner vgrid
 *
 * Voir
 *  - jquery.vgrid.min.js
 *  - http://blog.xlune.com/2009/09/vgrid/
 *  - https://github.com/xlune/jQuery-vGrid-Plugin
 */

(function ($, Drupal, Bootstrap) {

  let $gridContainer = $(".view-business-insight .view-content .views-infinite-scroll-content-wrapper");

  // création du grid masonry
  let createGrid = function() {
    let grid = $gridContainer.masonry({
      itemSelector: '.views-row',
      columnWidth: '.col-md-4',
      // gutter: 0,
    });

    // on supprime la classe grid-item
    $('.grid-item').removeClass('grid-item');
    return grid;
  };

  // mise à jour du grid (permet de résoudre un problème de positionnement lorsqu'il y a des requêtes ajax)
  let updateGrid = function() {
    setTimeout(function() {
      $gridContainer.masonry();
    }, 0);
  };

  let grid;

  $(window).on('load', function() {
    grid = createGrid();
  });

  //Par défaut, sur le filter parce qu'on y fait des actions, contrairement au load more
  // + compteur pour compter le nb de requetes ajax qui partent (on a parfois 2 requetes qui partent.. Impossible de localiser l'envoie pour l'instant)
  let ajax_is_filter = false;
  let compteur = 0;

  jQuery(document).ajaxSend(function(event, xhr, settings) {
    if (settings.data !== undefined && typeof settings.data.indexOf === "function" && settings.data.indexOf( "view_name=business_insight") != -1) {
      compteur++;
    }
  });

  jQuery(document).ajaxComplete(function(event, xhr, settings) {
    // see if it is from our view
    if (settings.data !== undefined && typeof settings.data.indexOf === "function" && settings.data.indexOf( "view_name=business_insight") != -1) {
      compteur --;
      if (compteur < 1) {
        if (ajax_is_filter && compteur === 0) {
          grid = createGrid();
        } else if (compteur === 0) {
          // on ajoute les nouveaux items au grid
          grid.masonry('appended', $('.grid-item'));
          updateGrid();

          // on supprime la classe grid-item
          $('.grid-item').removeClass('grid-item');
        }

        // Par défaut, parce que pas moyen de le changer au load
        ajax_is_filter = false;
        compteur = 0;
      }
    }
  });

  $(document).on("click", ".fieldset-field-insight-type .btn label", function(evt) {
    utag_link(utag_data.titre_page, 'Filters', 'Content Type', $(evt.target).text());
  });


  $(document).on("click", "div.btn-field-insight-type", function() {

    let input_id = $(this).attr('data-input');

    $('input#' + input_id).prop( "checked", true );
    ajax_is_filter = true;

    $("form#views-exposed-form-business-insight-business-insight-page input[type='submit']").click();
  });


  $(document).on("change", "select[name='vb_thematic']", function() {
    ajax_is_filter = true;
    $("form#views-exposed-form-business-insight-business-insight-page input[type='submit']").click();
  });


  $(document).on('click', '.view-business-insight .field_insight_type a', function() {
    let taxo_id = $(this).attr('data-taxo');
    let selector = "div.btn-field-insight-type[data-taxo='"+taxo_id+"']";

    $(selector).click();
    return false;
  });

  $(document).on('click', '.view-business-insight .field_insight a', function() {
    let taxo_id = $(this).attr('data-taxo');
    let selector = "select[name='vb_thematic']";

    $(selector).val(taxo_id).trigger('change');
    return false;
  });


  $(document).on('click', 'div.new-btn-see-all-business-insight', function() {
    $.each(Drupal.views.instances, function(i, view) {
      if (view.settings.view_name === "business_insight") {
        view.settings.field_insight_type_target_id = 'All';
        view.settings.vb_thematic = 'All';
        view.pager_element= 0;
        $('.view.view-business-insight').triggerHandler('RefreshView');
        delete view.settings.field_insight_type_target_id;
        delete view.settings.vb_thematic ;
        ajax_is_filter = true;
      }
    });
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
