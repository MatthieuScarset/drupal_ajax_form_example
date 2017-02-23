/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {
  function init_fixed_navbar(){
    var offset = 0;
    var top_menu = $('#main_nav');
    var navtop = $('#navtop');
    var contact_module = $('#contact_module');
    var preview_bar = $('.node-preview-container');
    if(!top_menu.length && !contact_module.length) return;
    var top_menu_offset = top_menu.offset();
    var contact_module_offset = contact_module.offset();
    var menu_offset = 0;
    var contact_offset = 0;
    var preview_bar_offset = 0;
    var init_preview_bar_offset = 0;

    if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
      menu_offset += $('#toolbar-bar').height();
      preview_bar_offset += menu_offset;
      contact_offset += menu_offset;

    }
    if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
      menu_offset += $('#toolbar-item-administration-tray').height();
      contact_offset += $('#toolbar-item-administration-tray').height();
      preview_bar_offset += $('#toolbar-item-administration-tray').height();
    }
    if (top_menu.length) {
      contact_offset += top_menu.outerHeight();
      preview_bar_offset += top_menu.outerHeight();
    }
    if (navtop.length) {
      init_preview_bar_offset += preview_bar_offset;
      init_preview_bar_offset += navtop.outerHeight();
    }
    if (preview_bar.length) {
      contact_offset += preview_bar.outerHeight();
    }

    $( window ).resize(function() {
      menu_offset = 0;
      contact_offset = 0;
      var preview_bar_offset = 0;
      var init_preview_bar_offset = 0;
      if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
        menu_offset += $('#toolbar-bar').height();
        preview_bar_offset += menu_offset;
        contact_offset += menu_offset;
      }
      if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
        menu_offset += $('#toolbar-item-administration-tray').height();
        contact_offset += $('#toolbar-item-administration-tray').height();
        preview_bar_offset += $('#toolbar-item-administration-tray').height();
      }
      if (top_menu.length) {
        contact_offset += top_menu.outerHeight();
        preview_bar_offset += top_menu.outerHeight();
      }
      if (navtop.length) {
        init_preview_bar_offset += preview_bar_offset;
        init_preview_bar_offset += navtop.outerHeight();
      }
      if (preview_bar.length) {
        contact_offset += preview_bar.outerHeight();
      }

      moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset);
    });

    $(window).scroll(function () {
      moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset);
    });

    moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset);
  }

  function moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset){
    var container_margin_top = 0;
    if (top_menu.length) {
      container_margin_top += top_menu.height() + 20;
    }
    if (preview_bar.length) {
      container_margin_top += preview_bar.height() + 20;
    }
    if (contact_module.length) {
      container_margin_top += contact_module.height() + 20;
    }

    if (top_menu.length) {
      if ($(window).scrollTop() > top_menu_offset.top + offset) {
        top_menu.addClass('navbar-fixed');
        $('.main-container').css('margin-top', container_margin_top);
        top_menu.css('top', menu_offset);
        $('.region-pre-content .affix').css('top', top_menu.outerHeight() + menu_offset);
      } else {
        top_menu.removeClass('navbar-fixed');
        $('.main-container').css('margin-top', 0);
        top_menu.css('top', 0);
        $('.region-pre-content .affix').css('top', $('#navbar').height() + menu_offset);
      }
    }

    if (preview_bar.length) {
      if ($(window).scrollTop() > top_menu_offset.top + offset) {
        preview_bar.addClass('navbar-fixed');
        $('.main-container').css('margin-top', container_margin_top);
        preview_bar.css('top', preview_bar_offset);
        $('.region-pre-content .affix').css('top', preview_bar.outerHeight() + preview_bar_offset);
      } else {
        preview_bar.removeClass('navbar-fixed');
        $('.main-container').css('margin-top', 0);
        preview_bar.css('top', init_preview_bar_offset);
        $('.region-pre-content .affix').css('top', $('#navbar').height() + preview_bar_offset);
      }
    }

    // module contact
    if (contact_module.length) {
      if ($(window).scrollTop() > contact_module_offset.top - contact_offset) {
        contact_module.addClass('sticky-module');
        $('.main-container').css('margin-top', container_margin_top);
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


(function () {
  //initialize swiper when document ready
  var mySwiper = new Swiper ('.swiper-container', {
    // Optional parameters
    direction: 'vertical',
    loop: true
  })
});