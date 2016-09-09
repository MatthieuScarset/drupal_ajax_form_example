/*$('.subnav').affix({
 offset: {
 top: $('#navtop').height()
 }
 });*/

(function ($, Drupal, Bootstrap) {
  function init_fixed_navbar(){
    var offset = 5;
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
      } else {
        $top_menu.removeClass('navbar-fixed');
        $('.main-container').css('margin-top', 0);
        $top_menu.css('top', 0);
      }
    });
  }


  $(document).ready(function () {
    init_fixed_navbar();
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
