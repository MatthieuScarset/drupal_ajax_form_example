'use strict';

/**
 * Specific file for ytb-embed custom element, so it can be loaded in Boosted without the OB1 JS library or to any other project
 */
import {defineCustomElement} from "vue";
import YtbEmbed from "./custom_elements/ytb-embed.ce.vue";

customElements.define('ytb-embed', defineCustomElement(YtbEmbed));
