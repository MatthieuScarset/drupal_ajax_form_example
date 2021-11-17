
class MenuPageOverride {
  constructor() {

    this.$is_scrolling = false;
    this.$pageMenu = $('.ob1-menu-page');

    this.$pageMenu.find('ul.nav a.nav-link').click((e) => {this._onItemClick(e)});
    $(window).scroll((e) => this._onScroll());

  }

  _onScroll() {
    if (this.$is_scrolling) {
      return;
    }

    let sticky_bottom_pos = $(window).scrollTop()
      + this._getFixedItemsHeight();  // Init with current page position
    const nav_links = this.$pageMenu.find('.nav-link');
    // On ne commence que quand on a dépassé le 1er element
    if ($(nav_links.first().attr('href')).offset().top <= sticky_bottom_pos) {
      nav_links.each(function(i, elem) {
        const target = $(elem).attr('href');
        $(elem).parent().removeClass('active');

        if (target.length > 1
          && $(target).length) {
          const parent_item_list = $(target).closest('.item-list');

          if (sticky_bottom_pos + this.$pageMenu.height() >= $(target).offset().top
            && sticky_bottom_pos + this.$pageMenu.height() < ($(target).offset().top + parent_item_list.outerHeight(true))) {
            $(elem).parent().addClass('active');
          }
        }
      }.bind(this));
    }
  }

  _onItemClick(event) {
    const target = $(event.currentTarget).attr('href');
    if ($(target).length) {
      event.preventDefault();
      $('html,body').animate({
        scrollTop: $(target).offset().top - this._getFixedItemsHeight()
      }, {
        duration: 1000,
        start: () => {this.$is_scrolling = true},
        complete: () => {this.$is_scrolling = false},
        easing: 'easeInOutQuad'
      });
    }
  }

  _getFixedItemsHeight() {
    let init = parseInt($('body').css('padding-top').replace("px", ''));
    $('.sticky-top').each(function () {
      init += $(this).height();
    });
    return init;
  }
}



if ($('.ob1-menu-page').length) {
  new MenuPageOverride();
}
