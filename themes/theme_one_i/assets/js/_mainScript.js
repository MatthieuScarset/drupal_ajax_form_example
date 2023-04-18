import {defineCustomElement} from "vue";


/* Import OB1 */
import '@ob1/web';
import ModuleMap from "./corporate/ModuleMap";

export {
  ModuleMap
}


// Hack pour jQuery
window.$ = jQuery.noConflict();
$.animate = $.fn.animate;


/*
  Import TS scripts
 */
// require('./ExampleTs.ts');
require('./StickyContent.ts');
require('./StickyHeader.js');


/*
  Import VueJS Components
 */
// import ExampleVue from "./ExampleVue.ce.vue";

/*
  Register VueJS custom elements
 */
// customElements.define('example-vue', defineCustomElement(ExampleVue));
