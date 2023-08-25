<script lang="ts">

import {defineComponent} from "vue";
import {Drupal, drupalSettings} from "../drupal";

enum SLOTS {
  Video,
  CookieMessage,
  CoverImage
}

export default defineComponent({

  props: {
    videoSrc: String,
    videoTitle: String,
    noCoverImage: Boolean,
    autoplay: Boolean
  },
  data() {
    return {
      Drupal: Drupal,
      SLOTS: SLOTS,
      // Default slot at loading. If no cover image is provided, we display the CookieMessage
      currentSlot: SLOTS.CoverImage,
      isDidomiDefined: false,
      didomi: {}
    }
  },
  mounted() {

    // if Didomi is not available in window context at loading, we assume that it won't be loaded
    // If it's available later on, the next function will do the job
    if (!window.hasOwnProperty("Didomi")) {
      this.isDidomiDefined = false;
    }

    // Function to be called by Didomi when it's ready
    (<any> window).didomiOnReady = (<any> window).didomiOnReady || [];
    (<any> window).didomiOnReady.push(function (Didomi){
      // this.didomi = Didomi;
      this.isDidomiDefined = true;

      if (Didomi.isConsentRequired()) {
        // Define default slot at loading
        if (this.noCoverImage) {
          this.currentSlot = this.areYtbCookiesAccepted() ? SLOTS.Video : SLOTS.CookieMessage;
        } else {
          this.currentSlot = SLOTS.CoverImage
        }
      }

      // Create event for when param change
      Didomi.getObservableOnUserConsentStatusForVendor(drupalSettings.didomi.vendor_id_youtube)
        .subscribe(function (consentStatus) {
          if (this.currentSlot !== SLOTS.CoverImage) {
            // consentStatus can be false even if the vendor is accepted, because it take the category status into consideration too
            this.currentSlot = (consentStatus || this.areYtbCookiesAccepted()) ? SLOTS.Video : SLOTS.CookieMessage
          }
        }.bind(this));
    }.bind(this));

  },
  methods: {
    showVideo() {
      this.currentSlot = this.areYtbCookiesAccepted() ? SLOTS.Video : SLOTS.CookieMessage;
    },
    areYtbCookiesAccepted(): boolean {
      let youtubeDidomi = (<any> window).Didomi.getUserStatusForVendor(drupalSettings.didomi.vendor_id_youtube);
      return !(youtubeDidomi == false || youtubeDidomi == undefined)
    },
    acceptCookies() {
      const transaction = (<any> window).Didomi.openTransaction();
      transaction.enableVendor(drupalSettings.didomi.vendor_id_youtube);
      transaction.commit();
      this.showVideo();
    }
  }
});

</script>

<template>
<!--  If Didomi is not defined, we show a specific message-->
  <div v-if="!this.isDidomiDefined" class="cookie-message">
    <p>{{ Drupal.t("Cookie management script is not defined. Please add this page to your white list to allow the Youtube video") }}</p>
  </div>
  <div v-else>
    <div class="cover-image" v-on:click="showVideo()" v-if="this.currentSlot === SLOTS.CoverImage">
      <slot name="cover-img"></slot>
    </div>
    <div class="cookie-message" v-else-if="this.currentSlot === SLOTS.CookieMessage">
      <slot name="cookieBlock"></slot>
      <button
        class="btn btn-accept-cookies"
        v-on:click="acceptCookies()"
      >{{ Drupal.t("Accept") }}</button>
    </div>
    <div class="ytb-iframe embed-responsive embed-responsive-16by9" v-else-if="this.currentSlot === SLOTS.Video">
      <iframe allowfullscreen=""
              class="embed-responsive-item"
              :src="this.videoSrc + '?autoplay=' + this.autoplay"
              :title="this.videoTitle"
      ></iframe>
    </div>
  </div>

</template>

<style lang="scss">
.cover-image {
  cursor: pointer;
}

.ytb-iframe {
  height: 100%;
}

.embed-responsive {
  position: relative;
  display: block;
  width: 100%;
  padding: 0;
  overflow: hidden;

  &::before {
    display: block;
    content: "";
  }

  &.embed-responsive-16by9::before {
    padding-top: 56.25%;
  }


  .embed-responsive-item {
    position: absolute;
    top: 0;
    bottom: 0;
    left: 0;
    width: 100%;
    height: 100%;
    border: 0;
  }
}

.cookie-message {
  margin: 2rem;
  padding: 2rem;
  background: #fff;
  border: 1px solid black;
  box-shadow: 2px 3px 0 black;


  .btn.btn-accept-cookies {
    cursor: pointer;
    max-width: 21.875rem;
    white-space: normal;
    outline-offset: 0.25rem;
    transition: outline-offset .15s ease-in-out;
    display: inline-block;
    font-family: "HelvNeueOrange", "Helvetica Neue", Helvetica, Arial, -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, "Noto Sans", sans-serif, "Apple Color Emoji", "Segoe UI Emoji", "Segoe UI Symbol", "Noto Color Emoji";
    font-weight: 700;
    color: #000;
    text-align: center;
    vertical-align: middle;
    -webkit-user-select: none;
    -moz-user-select: none;
    -ms-user-select: none;
    user-select: none;
    background-color: transparent;
    border: 1px solid transparent;
    padding: .8125rem 2.8125rem;
    font-size: 1rem;
    line-height: 1.375rem;
    border-radius: 0;
  }
}

</style>
