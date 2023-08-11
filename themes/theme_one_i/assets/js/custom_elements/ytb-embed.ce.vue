<script lang="ts">

import {defineComponent} from "vue";
import {Didomi, Drupal, drupalSettings} from "../Drupal";

enum SLOTS {
  Video,
  CookieMessage,
  CoverImage
}

export default defineComponent({

  props: {
    videoSrc: String,
    videoTitle: String
  },
  data() {
    return {
      Drupal: Drupal,
      SLOTS: SLOTS,
      currentSlot: SLOTS.CoverImage
    }

  },
  methods: {
    showVideo() {
      if (this.areYtbCookiesAccepted()) {
        this.currentSlot = SLOTS.Video;
      } else {
        this.currentSlot = SLOTS.CookieMessage
      }
    },
    areYtbCookiesAccepted(): boolean {
      let youtubeDidomi = Didomi().getUserStatusForVendor(drupalSettings.didomi.vendor_id_youtube);
      return !(youtubeDidomi == false || youtubeDidomi == undefined)
    },

    acceptCookies() {
      //on récupère le UserConsent
      const userConsent = Didomi().getUserStatus();
      const ytbVendorId = drupalSettings.didomi.vendor_id_youtube;
      //ajout de l'élément dans les vendor enabled
      if (!userConsent.vendors.consent.enabled.includes(ytbVendorId)) {
        userConsent.vendors.consent.enabled.push(ytbVendorId);
      }
      //suppression de l'élément dans les vendor disabled
      for (let i = 0; i < userConsent.vendors.consent.disabled.length; i++) {
        if (userConsent.vendors.consent.disabled[i] === ytbVendorId) {
          userConsent.vendors.consent.disabled.splice(i, 1);
        }
      }
      //on enregistre le nouvel UserConsent
      Didomi().setUserStatus(userConsent);
      this.showVideo();
    }
  }
});

</script>

<template>
  <div class="cover-image" v-on:click="showVideo()" v-if="this.currentSlot === SLOTS.CoverImage">
    <slot name="cover-img"></slot>
  </div>
  <div class="cookie-message" v-if="this.currentSlot === SLOTS.CookieMessage">
    <slot name="cookieBlock"></slot>
    <button
      class="btn btn-accept-cookies"
      v-on:click="acceptCookies()"
    >{{ Drupal.t("Accept") }}</button>
  </div>
  <div class="ytb-iframe embed-responsive embed-responsive-16by9" v-if="this.currentSlot === SLOTS.Video">
    <iframe allowfullscreen=""
            class="embed-responsive-item"
            :src="this.videoSrc"
            :title="this.videoTitle"
    ></iframe>
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
