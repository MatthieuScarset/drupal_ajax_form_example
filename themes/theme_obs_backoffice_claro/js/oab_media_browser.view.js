/**
 * @file oab_media_browser.view.js
 */
(function ($, Drupal) {

  "use strict";

  /**
   * Registers behaviours related to view widget.
   */
  Drupal.behaviors.OabMediaBrowserView = {

    attach: function (context) {
      $('.views-col').once('bind-click-event').click(function () {
        var input = $(this).find('.views-field-entity-browser-select input');
        input.prop('checked', !input.prop('checked'));
        if (input.prop('checked')) {
          $(this).addClass('checked');
        }
        else {
          $(this).removeClass('checked');
        }
      });
    }
  }

}(jQuery, Drupal));
