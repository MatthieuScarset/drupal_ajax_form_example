/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {
  function init_fixed_navbar(){
    var offset = 0;
    var top_menu = $('#main_nav');
    var contact_module = $('#contact_module');
    if(!top_menu.length && !contact_module.length) return;
    var top_menu_offset = top_menu.offset();
    var contact_module_offset = contact_module.offset();
    var menu_offset = 0;
    var contact_offset = 0;

    if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
      menu_offset += $('#toolbar-bar').height();
      contact_offset += menu_offset;
    }
    if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
      menu_offset += $('#toolbar-item-administration-tray').height();
      contact_offset += $('#toolbar-item-administration-tray').height();
    }
    if (top_menu.length) {
      contact_offset += top_menu.outerHeight();
    }

    $( window ).resize(function() {
      menu_offset = 0;
      contact_offset = 0;
      if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
        menu_offset += $('#toolbar-bar').height();
        contact_offset += menu_offset;
      }
      if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
        menu_offset += $('#toolbar-item-administration-tray').height();
        contact_offset += $('#toolbar-item-administration-tray').height();
      }
      if (top_menu.length) {
        contact_offset += top_menu.outerHeight();
      }

      moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module);
    });

    $(window).scroll(function () {
      moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module);
    });
  }

  function moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module){
    if (top_menu.length) {
      if ($(window).scrollTop() > top_menu_offset.top + offset) {
        top_menu.addClass('navbar-fixed');
        $('.main-container').css('margin-top', top_menu.height() + 20);
        top_menu.css('top', menu_offset);
        $('.region-pre-content .affix').css('top', top_menu.outerHeight() + menu_offset);
      } else {
        top_menu.removeClass('navbar-fixed');
        $('.main-container').css('margin-top', 0);
        top_menu.css('top', 0);
        $('.region-pre-content .affix').css('top', $('#navbar').height() + menu_offset);
      }
    }

    // module contact
    if (contact_module.length) {
      if ($(window).scrollTop() > contact_module_offset.top - contact_offset) {
        contact_module.addClass('sticky-module');
        $('.main-container').css('margin-top', contact_module.height() + 20);
        contact_module.css('top', contact_offset);
      } else {
        contact_module.removeClass('sticky-module');
        $('.main-container').css('margin-top', 0);
        contact_module.css('top', 0);
      }
    }
  }

  $(document).ready(function () {
    init_fixed_navbar();
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
