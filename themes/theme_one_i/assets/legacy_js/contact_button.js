(function ($, Drupal, Bootstrap) {
  const contactButtonText = $('.contact-button-text');
  const contactDropdown = $('#contactButtonDropdown');
  const contactButtonIcon = $('.contact-button-icon');
  const contactButton =  $('.contact-button');
  const dropdownButton = $('.dropup');


  $(window).on('scroll', function () {
    let intScroll = $(window).scrollTop();

    if (!contactButtonText.hasClass('is-clicked')){
      if(intScroll !== 0) {
        contactButtonText.addClass('d-none d-md-block');
      } else {
        contactButtonText.removeClass('d-none d-md-block');
      }
    }
  });

  contactDropdown.click(function () {
    $(this).find(contactButtonIcon).toggleClass('icon icomoon');
    $(this).find(contactButtonIcon).toggleClass('icon-contact icomoon-ob1-cross');
    $(this).find(contactButtonIcon).toggleClass('text-white  ');
    $(this).find(contactButton).toggleClass('contact-button contact-button-open');
    $(this).find(contactButtonText).toggleClass('is-clicked');
    if ($(this).find(contactButtonText).hasClass('d-md-block')) {
      $(this).find(contactButtonText).removeClass('d-md-block')
    }
  });

  dropdownButton.on('hidden.bs.dropdown', function() {
    contactButtonIcon.removeClass('icomoon icomoon-ob1-cross text-white').addClass('icon icon-contact');
    contactButton.removeClass('contact-button-open').addClass('contact-button');
    contactButtonText.removeClass('is-clicked').addClass('d-md-block');
  });

  var observer = new MutationObserver(function (event) {
    event.forEach((mutationRecord) => {
      const target = mutationRecord.target;
      if (target.style.display !== 'none') {
        $('.contact-button-block').addClass('move-left');
      } else {
        $('.contact-button-block').removeClass('move-left');
      }
    });
  })

  document.querySelectorAll('.o-scroll-up').forEach((e) => {
    observer.observe(e, {
      attributes: true,
      attributeFilter: ['style'],
      childList: false,
      characterData: false
    })
  });

})(window.jQuery, window.Drupal, window.Drupal.bootstrap);
