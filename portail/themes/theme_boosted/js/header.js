/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {
  function init_fixed_navbar(){
    var offset = 0;
    var $top_menu = $('#main_nav');
    if(!$top_menu.length) return;
    var top_menu_offset = $top_menu.offset();
    var menu_offset = 0;

    if ($('#toolbar-bar').length){
      menu_offset += $('#toolbar-bar').height();
    }
    if ($('#toolbar-item-administration-tray').length){
      menu_offset += $('#toolbar-item-administration-tray').height();
    }

    $(window).scroll(function () {

      if ($(window).scrollTop() > top_menu_offset.top + offset) {
        $top_menu.addClass('navbar-fixed');
        $('.main-container').css('margin-top', $top_menu.height() + 20);
        $top_menu.css('top', menu_offset);
        $('.region-pre-content .affix').css('top', $top_menu.height() + menu_offset);
      } else {
        $top_menu.removeClass('navbar-fixed');
        $('.main-container').css('margin-top', 0);
        $top_menu.css('top', 0);
        $('.region-pre-content .affix').css('top', $('#navbar').height() + menu_offset);
      }
    });
  }

  function init_fixed_contactmodule(){
    var offset = 0;
    var $contact_module = $('#contact_module');
    if(!$contact_module.length) return;
    var contact_module_offset = $contact_module.offset();
    var menu_offset = 0;

    if ($('#toolbar-bar').length){
      menu_offset += $('#toolbar-bar').height();
    }
    if ($('#toolbar-item-administration-tray').length){
      menu_offset += $('#toolbar-item-administration-tray').height();
    }
    if ($('#main_nav').length){
      menu_offset += $('#main_nav').height();
    }

    $(window).scroll(function () {

      if ($(window).scrollTop() > contact_module_offset.top - menu_offset) {
        $contact_module.addClass('sticky-module');
        $('.main-container').css('margin-top', $contact_module.height() + 20);
        $contact_module.css('top', menu_offset + 10);
        $('.region-pre-content .affix').css('top', $contact_module.height() + menu_offset);
      } else {
        $contact_module.removeClass('sticky-module');
        $('.main-container').css('margin-top', 0);
        $contact_module.css('top', 0);
        $('.region-pre-content .affix').css('top', $('#navbar').height() + menu_offset);
      }
    });
  }

  $(document).ready(function () {
    init_fixed_navbar();
    init_fixed_contactmodule();
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
