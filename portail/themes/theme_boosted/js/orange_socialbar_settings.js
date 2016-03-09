var sharebar_parameters = {
    background_color: 'white', //'black' or 'white'
    layout: 'horizontal', //'horizontal' or 'vertical' or 'grid'
    auto_load: true, //load of the sharebar automatically, if set to false, you must call the showShareBar() function
    show_counter: false, //show counter and requests
    counter_reload_time: 0, //time in seconds between 2 reload of the counter (must be > 0)
    og_url: "http://www.orange.fr", //url of the shared page
    og_title: 'This is my title ! (og_title)', //title of the share
    og_description: 'Cette description est déclarée en paramètres : Lorem ipsum dolor sit amet, consectetur adipisicing elit. Vero nemo quibusdam praesentium est eveniet unde.', //description of the shared page
    og_image: 'http://pocketprod.com/img/960/b_ricard.jpg', //image used in share
    og_locale: "fr_FR", //language (en_US, fr_FR, es_ES, pl_PL, ro_RO, ar_AR)
    use_bitly: true, //use bitly service to reduce size of link in tweet
    bitly_token: 'b65ae4885de2cc131c117f4de075e1f69d26794c', //required if use_bitly is set to true
    twitter_message: "Hello world ! Just wanted to share this with you : ", //tweet
    twitter_site: '@orange', //twitter @username
    email_subject: 'Look this website I found !',
    email_message: 'Lorem ipsum dolor sit amet, consectetur adipisicing elit. Quis qui, nulla ea sunt, repudiandae delectus facere amet laborum. Nostrum architecto sunt explicabo ex tenetur eos velit ipsa illum voluptatem quibusdam!',
    email_popin_title: 'Send an email to a friend !',
    sms_text: 'Come take a look at this website : http://www.orange.fr !'
};
var visible_sharebar_buttons = [
	{button: 'linkedin'},
    {button: 'facebook'},
    {button: 'twitter'},
    {button: 'pinterest'},
    {button: 'googleplus'}
];