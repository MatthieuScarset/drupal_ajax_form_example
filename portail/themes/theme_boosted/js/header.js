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
        var local_nav = $('#local_nav');
        var contact_module = $('#contact_module');
        var preview_bar = $('.node-preview-container');
        var top_zone = $('#block-topzone');
        if(!top_menu.length && !contact_module.length) return;
        var top_menu_offset = top_menu.offset();
        var contact_module_offset = contact_module.offset();
        var menu_offset = 0;
        var contact_offset = 0;
        var preview_bar_offset = 0;
        var init_preview_bar_offset = 0;
        var localnav_offset = 0;
        var topShare = $('#block-socialshareblock').offset().top;

        if(local_nav.length) {
            createSubNavMobile(top_menu, local_nav);
        }

        if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
            menu_offset += $('#toolbar-bar').height();
            preview_bar_offset += menu_offset;
            contact_offset += menu_offset;
            localnav_offset += menu_offset;
        }
        if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
            menu_offset += $('#toolbar-item-administration-tray').height();
            contact_offset += $('#toolbar-item-administration-tray').height();
            preview_bar_offset += $('#toolbar-item-administration-tray').height();
            localnav_offset += $('#toolbar-item-administration-tray').height();
        }

        if (top_menu.length) {
            contact_offset += top_menu.outerHeight();
            preview_bar_offset += top_menu.outerHeight();
            localnav_offset +=  top_menu.outerHeight();
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
            localnav_offset = 0;
            if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) {
                menu_offset += $('#toolbar-bar').height();
                preview_bar_offset += menu_offset;
                contact_offset += menu_offset;
                localnav_offset += menu_offset;
            }
            if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) {
                menu_offset += $('#toolbar-item-administration-tray').height();
                contact_offset += $('#toolbar-item-administration-tray').height();
                preview_bar_offset += $('#toolbar-item-administration-tray').height();
                localnav_offset += $('#toolbar-item-administration-tray').height();
            }

            if (top_menu.length) {
                contact_offset += top_menu.outerHeight();
                preview_bar_offset += top_menu.outerHeight();
                localnav_offset +=  top_menu.outerHeight();
            }
            if (navtop.length) {
                init_preview_bar_offset += preview_bar_offset;
                init_preview_bar_offset += navtop.outerHeight();
            }

            if (preview_bar.length) {
                contact_offset += preview_bar.outerHeight();
            }

            moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset, local_nav, localnav_offset, top_zone);
        });

        $(window).scroll(function () {
            moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset, local_nav, localnav_offset, top_zone);
        });

        moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset, local_nav, localnav_offset, top_zone);

        //init scrolling animation
        $(".sub_local_menu ul li a").click(function() {
            event.preventDefault();

            var divToScroll  = $(this).attr('href');
            var offsetTop = 0;

            if (top_menu.length) { offsetTop += top_menu.outerHeight(); }
            if (preview_bar.length) { offsetTop += preview_bar.outerHeight(); }
            if (navtop.length) { offsetTop += navtop.outerHeight(); }
            if ($('#toolbar-item-administration-tray.toolbar-tray-horizontal').length) { offsetTop += $('#toolbar-item-administration-tray').outerHeight(); }
            // if (local_nav.length && local_nav.is(':visible')) { offsetTop += $(this).parents(".sub_local_menu").height(); }
            if ($('body.toolbar-fixed .toolbar-oriented #toolbar-bar').length) { offsetTop += $('#toolbar-bar').outerHeight(); }

            var mTop = 0;
            if (top_menu.hasClass('navbar-fixed')){
                mTop = parseInt($('.main-container-resized').css('margin-top'));
                if (isNaN(mTop)){
                    mTop = 0;
                }
            }
            /*$('html, body').animate({ //- 25
                scrollTop: $(divToScroll).offset().top + mTop - offsetTop - 25
            }, 1000);*/
        });
    }

    function moveFixedElements(top_menu_offset, offset, top_menu, menu_offset, contact_module_offset, contact_offset, contact_module, preview_bar, preview_bar_offset, init_preview_bar_offset, local_nav, localnav_offset, top_zone){
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
                //$('.main-container').css('margin-top', container_margin_top);
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
                //$('.main-container').css('margin-top', container_margin_top);
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
                //$('.main-container').css('margin-top', container_margin_top);
                contact_module.css('top', contact_offset);
            } else {
                contact_module.removeClass('sticky-module');
                $('.main-container').css('margin-top', 0);
                contact_module.css('top', 0);
            }
        }

        var top_zone_offset = 0;
        if(top_zone.length && top_zone.outerHeight() > 0){
            top_zone_offset = $('#block-topzone').outerHeight();
        }

        // module local_nav
        if (local_nav.length && local_nav.is(':visible')) {
            if ($(window).scrollTop() > (top_zone_offset - localnav_offset)) {
                local_nav.addClass('sticky-module');
                if(top_zone.length && top_zone.outerHeight() > 0) {
                    $('.main-container').css('margin-top', 0);
                }else{
                    $('.main-container').css('margin-top', container_margin_top);
                }
                local_nav.css('top',  localnav_offset );
                $('#block-socialshareblock').css('top', localnav_offset + $('#local_nav').outerHeight());
            } else {
                local_nav.removeClass('sticky-module');
                if(top_zone.length && top_zone.outerHeight() > 0) {
                    $('.main-container').css('margin-top', 0);
                }else{
                    $('.main-container').css('margin-top', container_margin_top);
                }
                local_nav.css('top', 0);
                // $('#block-socialshareblock').css('top', topShare);
            }
            if($(window).scrollTop() == 0){
                local_nav.css('top', (localnav_offset + $('#top_navbar').outerHeight()));
            }
        }

    }

    function createSubNavMobile(top_menu, local_nav){
        var mobile_local_nav = local_nav.clone();
        mobile_local_nav.attr('id', 'mobile_local_nav');
        mobile_local_nav.removeClass('local_nav');
        mobile_local_nav.addClass('dropdown-menu');
        mobile_local_nav.attr('aria-labelledby', 'dropdownMenu1');
        var titleMenu = local_nav.attr('data-title-mobile');
        if (titleMenu == undefined){
            titleMenu = 'Navigation';
        }

        var divDropdown = $('<div id="mobile_dropdown_subnav" class="dropdown visible-xs"></div>');
        var button = $('<button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu1" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">'+titleMenu+'<span class="caret"></span></button>');

        button.appendTo(divDropdown);
        mobile_local_nav.appendTo(divDropdown);
        divDropdown.appendTo(top_menu);

        local_nav.addClass('hidden-xs');
    }
    $( document ).ajaxComplete(function() {
       console.log( "Triggered ajaxComplete handler." );
        //TODO Uncomment me + find a better way to handle the first call, if necessary
       // $('#page_thematique_filter').collapse("toggle");



    });

    $(document).ready(function () {

        init_fixed_navbar();
        // slider pour barre accès bleu

        if ($('#slider_direct_access').length) {
            jQuery('#slider_direct_access').slick({
                dots: false,
                arrows: false,
                infinite: true,
                speed: 300,
                slidesToShow: 4,
                slidesToScroll: 1,
                responsive: [
                    {
                        breakpoint: 1024,
                        settings: {
                            slidesToShow: 4,
                            slidesToScroll: 1,
                        }
                    },
                    {
                        breakpoint: 980,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1,
                        }
                    },
                    {
                        breakpoint: 768,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1
                        }
                    },
                    {
                        breakpoint: 480,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1
                        }
                    }
                ]
            });
        }

        if ($('.related-content-items').length) {

            //initialize swiper when document ready
            jQuery('.related-content-items').slick({
                dots: true,
                arrows: false,
                infinite: true,
                speed: 300,
                slidesToShow: 3,
                slidesToScroll: 1,
                responsive: [
                    {
                        breakpoint: 1024,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1,
                        }
                    },
                    {
                        breakpoint: 980,
                        settings: {
                            slidesToShow: 3,
                            slidesToScroll: 1,
                        }
                    },
                    {
                        breakpoint: 768,
                        settings: {
                            slidesToShow: 1,
                            slidesToScroll: 1,
                        }
                    },
                    {
                        breakpoint: 480,
                        settings: {
                            slidesToShow: 1,
                            slidesToScroll: 1
                        }
                    }
                ]
            });
          jQuery('.related-content-items .slick-track').addClass('row');
        }



        var clickOnDiscover = function() {
            if($('#home_playlist_end').hasClass('hidden'))
            {
                $('#home_playlist_end').removeClass('hidden');
            }
            else
            {
                $('#home_playlist_end').addClass('hidden');
            }
            $('.home-playlist-items').slick('setPosition');
        };
        $('div.btn-decouvrir-plus').click(clickOnDiscover);

        if ($('.home-playlist-items').length) {

            $('.home-playlist-items').each(function(key, item) {
                //initialize swiper when document ready

                $('#'+item.id).slick({
                    lazyLoad: 'ondemand',
                    slidesToShow: 4,
                    slidesToScroll: 1,
                    dots: false,
                    arrows: false,
                  //  appendArrows: $('#'+item.id + '-slider-nav'),
                  //  prevArrow: '<div class="navigation_arrow prev_arrow"> < </div>',
                  //  nextArrow: '<div class="navigation_arrow next_arrow "> > </div>',
                    responsive: [
                        {
                            breakpoint: 1024,
                            settings: {
                                slidesToShow: 4,
                                slidesToScroll: 1,
                            }
                        },
                        {
                            breakpoint: 980,
                            settings: {
                                slidesToShow: 3,
                                slidesToScroll: 1,
                                dots: true,
                            }
                        },
                        {
                            breakpoint: 768,
                            settings: {
                                slidesToShow: 1,
                                slidesToScroll: 1,
                                dots: true,
                            }
                        },
                        {
                            breakpoint: 480,
                            settings: {
                                slidesToShow: 1,
                                slidesToScroll: 1,
                                dots: true,
                            }
                        }
                    ]
                });

                $('#'+item.id+'-prev_arrow').on('click', function(){
                $('#'+item.id).slick("slickPrev");
                 });
                 $('#'+item.id+'-next_arrow').on('click', function(){
                 $('#'+item.id).slick("slickNext");
                 });

            });
           // clickOnDiscover();

        }

        if ($('.home-banner-items').length) {

            //initialize swiper when document ready
            jQuery('.home-banner-items').slick({
                dots: true,
                arrows: false,
                infinite: true,
                speed: 300,
                slidesToShow: 1,
                slidesToScroll: 1,

            });
        }

        $('#myAffix').affix({
            offset: {
                top: 100,
                bottom: function () {
                    return (this.bottom = $('.footer').outerHeight(true))
                }
            }
        })

    });


})(window.jQuery, window.Drupal, window.Drupal.bootstrap);

