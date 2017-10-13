var sharebar_parameters = {
    background_color: 'white', //'black' or 'white'
    layout: 'horizontal', //'horizontal' or 'vertical' or 'grid'
    auto_load: true, //load of the sharebar automatically, if set to false, you must call the showShareBar() function
    show_counter: false, //show counter and requests
    counter_reload_time: 0, //time in seconds between 2 reload of the counter (must be > 0)
    og_url: "http://www.orange.fr", //url of the shared page
    og_title: 'Titre de la page partagée', //title of the share
    og_description: 'Partagez cette page', //description of the shared page
    og_image: 'http://pocketprod.com/img/960/b_ricard.jpg', //image used in share
    og_locale: "fr_FR", //language (en_US, fr_FR, es_ES, pl_PL, ro_RO, ar_AR)
    use_bitly: false, //use bitly service to reduce size of link in tweet
    bitly_token: 'b65ae4885de2cc131c117f4de075e1f69d26794c', //required if use_bitly is set to true
    twitter_message: "", //tweet
    twitter_site: '@orangebusiness', //twitter @username
    email_subject: 'Look this website I found !',
    email_message: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quis qui, nulla ea sunt, repudiandae delectus facere amet laborum. Nostrum architecto sunt explicabo ex tenetur eos velit ipsa illum voluptatem quibusdam!',
    email_popin_title: 'Send an email to a friend !',
    sms_text: 'Come take a look at this website : http://www.orange.fr !'
};
var visible_sharebar_buttons = [
	{button: 'twitter'},
	//{button: 'googleplus'},
    {button: 'facebook'},
    {button: 'linkedin'}
    //{button: 'pinterest'}
];

var followbar_parameters = {
	background_color: 'black',
  	layout: 'horizontal',
  	auto_load: true,
  	locale: 'en_US',
  	page_facebook: 'https://www.facebook.com/orangebusiness',
    page_facebook_ru: 'https://www.facebook.com/OrangeRussia',
  	page_twitter: 'https://twitter.com/orangebusiness',
  	page_googleplus: 'https://plus.google.com/+orange/posts',
  	page_linkedin: 'https://www.linkedin.com/company/orange-business-services',
  	page_pinterest: 'https://pinterest.com/orangebusiness/',
    page_slideshare: 'https://www.slideshare.net/orangebusiness',
  	page_youtube: 'https://www.youtube.com/user/orangebusiness',
  	page_dailymotion: 'https://www.dailymotion.com/orangebusiness'
  		
};
var visible_followbar_buttons = [
    {button: 'twitter'},
    {button: 'linkedin'},
    {button: 'facebook'},
    {button: 'slideshare'},
    {button: 'pinterest'},
    {button: 'youtube'},
    {button: 'dailymotion'}
];
