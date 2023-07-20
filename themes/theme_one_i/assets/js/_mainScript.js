import {defineCustomElement} from "vue";


/* Import OB1 */
import '@ob1/web';


// Hack pour jQuery
window.$ = jQuery.noConflict();
$.animate = $.fn.animate;


/*
  Import TS scripts
 */
// require('./example-ts.ts');
require('./sticky-content.ts');
require('./sticky-header.js');


/*
  Import VueJS Components
 */
// import ExampleVue from "./ExampleVue.ce.vue";
import YtbEmbed from "./custom_elements/ytb-embed.ce.vue";

/*
  Register VueJS custom elements
 */
// customElements.define('example-vue', defineCustomElement(ExampleVue));
customElements.define('ytb-embed', defineCustomElement(YtbEmbed));
