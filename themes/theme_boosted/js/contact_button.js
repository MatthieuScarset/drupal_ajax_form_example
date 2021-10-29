(function ($, Drupal, Bootstrap) {
  const contactButtonText = $('.contact-button-text');
  const contactDropdown = $('#contactButtonDropdown');
  const contactButtonIcon = $('.contact-button-icon');
  const contactButton =  $('.contact-button');
  const dropdownButton = $('.dropup');

  $(window).on('scroll', function () {
    let intScroll = $(window).scrollTop();

    if(intScroll !== 0) {
      contactButtonText.addClass('hidden-xs');
    } else {
      contactButtonText.removeClass('hidden-xs');
    }
  });

  contactDropdown.click(function () {
    $(this).find(contactButtonIcon).toggleClass('icomoon-ob1-contact icomoon-ob1-cross');
    $(this).find(contactButton).toggleClass('contact-button contact-button-open');
  });

  dropdownButton.on('show.bs.dropdown', function() {
      contactButtonText.addClass('hidden');
  });

  dropdownButton.on('hidden.bs.dropdown', function() {
    contactButtonIcon.removeClass('icomoon-ob1-cross');
    contactButtonIcon.addClass('icomoon-ob1-contact');
    contactButton.removeClass('contact-button-open');
    contactButton.addClass('contact-button');
      contactButtonText.removeClass('hidden');
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
