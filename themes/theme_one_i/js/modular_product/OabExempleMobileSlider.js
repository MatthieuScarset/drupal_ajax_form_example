
class OabExempleMobileSlider {
  constructor(root, parent) {

    this.$root = root;
    this.$parent = parent;

    const params = new Proxy(new URLSearchParams(window.location.search), {
      get: (searchParams, prop) => searchParams.get(prop),
      has: (searchParams, prop) => searchParams.has(prop)
    });

    // Set the exemple as slider
    if ('scroll-mobile' in params) {
      this.$root.classList.add("scroll-mobile");
      this.$root.addEventListener('scroll', (e) => { this._onScroll(e);});
    } else {
      // Block slider and use only Touch events
      this.$root.addEventListener('touchstart', (e) => { this._onTouchStart(e); });
    }

  }

  _onTouchStart(e) {
    if (e.changedTouches.length === 1) {
      this.$touchStart = e.changedTouches[0];

      this.$root.addEventListener('touchend', (touchEndEvent) => {
        if (typeof this.$touchStart !== "undefined" && touchEndEvent.changedTouches.length) {
          const currentTouch = touchEndEvent.changedTouches[0];

          const deltaX = currentTouch.clientX - this.$touchStart.clientX;
          const deltaY = currentTouch.clientY - this.$touchStart.clientY;

          // Je considère que l'utilisateur va à droite si son mouvement est de plus de 45° par rapport à Y,
          // ie. si le déplacement X est supérieur à Y
          if (Math.abs(deltaX) > Math.abs(deltaY)) {
            if (deltaX > 0) {
              this.$parent.previousExample();
            } else {
              this.$parent.nextExample();
            }
          }
          delete this.$touchStart;
        }
      }, {once: true});
    }
  }

  _onScroll(e) {
    if (!this.$parent.isSliderAnimating && this.$parent.currentSliderPositionX !== this.$root.scrollLeft) {
      if (this.$parent.currentSliderPositionX < this.$root.scrollLeft) {
        this.$parent.nextExample();
      } else {
        this.$parent.previousExample();
      }
    }
  }
}


export default OabExempleMobileSlider;
