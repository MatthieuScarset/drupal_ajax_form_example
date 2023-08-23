'use strict';

/* Import OB1 */
import '@ob1/web';
import {defineCustomElement} from "vue";


// Hack pour jQuery
window.$ = jQuery.noConflict();
$.animate = $.fn.animate;


/*
  Import TS scripts
 */
require('./sticky-content.ts');
require('./sticky-header.js');

/*
Custom elements
 */
import YtbEmbed from "./custom_elements/ytb-embed.ce.vue";

customElements.define('ytb-embed', defineCustomElement(YtbEmbed));
