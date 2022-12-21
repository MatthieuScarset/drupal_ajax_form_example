class OabExempleSlider {
  constructor(elem) {
    this.$root = elem;
    this.$current = 1;
    this.$exampleTitles = this.$root.querySelectorAll('.example-titles a');
    this.$contentSlider = this.$root.querySelector('.example-content');
    this.$delay = this.$root.dataset.delay ? 1000 * this.$root.dataset.delay : 1000;
    this.$exampleTitles.forEach((a) => {
      a.addEventListener('click', (e) => {this._onClick(e);});
    });

    // Lorsqu'il y a un resize, on garde la slide alignée
    window.addEventListener('resize', () => {
      this._scrollToSlide(this.$current);
      if (window.matchMedia("(min-width: 736px)").matches) {
        this.$exampleTitles[this.$current].classList.remove('col-6');
      } else {
        this.$exampleTitles[this.$current].classList.add('col-6');
      }
    });

    this.$contentSlider.addEventListener('touchstart', (e) => {
      console.log(e);
      if (e.changedTouches.length === 1) {
        this.$touchStart = e.changedTouches[0];
      }
    });

    this.$contentSlider.addEventListener('touchend', (e) => {

      if (typeof this.$touchStart !== "undefined" && e.changedTouches.length) {
        const currentTouch = e.changedTouches[0];

        const deltaX = currentTouch.clientX - this.$touchStart.clientX;
        const deltaY = currentTouch.clientY - this.$touchStart.clientY;

        // Je considère que l'utilisateur va à droite si son mouvement est de plus de 45° par rapport à Y,
        // ie. si le déplacement X est supérieur à Y
        if (Math.abs(deltaX) > Math.abs(deltaY)) {
          if (deltaX > 0) {
            this._slide(this.$current - 1);
          } else {
            this._slide(this.$current + 1);
          }
        }
        delete this.$touchStart;
      }
    });

    if (typeof this.$root.dataset.startAtLaunch !== 'undefined') {
      this._start();
    }
    else {
      window.addEventListener('scroll', () => {this._startIfVisible();});
    }
  }

  /** Restart animation on click on example title
   * @private
   */
  _onClick(event) {
    if (!event.currentTarget.classList.contains("active")) {
      this.$exampleTitles.forEach((title)=> {
        title.classList.remove("active");
      });
      event.currentTarget.classList.add("active");
      this._slide(parseInt(event.currentTarget.dataset.index));
    }
  }

  /**
   * Start the animation
   * @private
   */
  _start() {
    this.$current = 0;
    this._slide(0); // Launch 1st step
  }

  /**
   * Start the animation if the examples are visible
   * @private
   */
  _startIfVisible() {
    if (this._checkIfVisible() && !this.$intervalId) {
      this._start();
    }
  }

  /**
   * Check if the examples are visible
   * @private
   */
  _checkIfVisible() {
    const el = this.$exampleTitles[0];
    if(el) {
      var rect = el.getBoundingClientRect();
      var elemTop = rect.top;
      var elemBottom = rect.bottom;

      // Partially visible elements return true:
      return elemTop < window.innerHeight && elemBottom >= 0;
    }
  }

  /**
   * Change to the next one
   * @private
   */
  _nextExample() {
    this._slide(this.$current + 1);
  }

  _slide(slide) {
    // Number.mod()
    this.$current = this._mod(slide, this.$exampleTitles.length ?? 1);
    console.log({slide : slide, current: this.$current});
    this._scrollToSlide(this.$current);

    //Gestion de la progress bar en mobile
    if (window.matchMedia("(max-width: 736px)").matches) {
      this.$exampleTitles[this.$current].classList.add('col-6');
    }
    this.$exampleTitles[this.$current].querySelector('.ob1-progress-bar-determined').classList.remove('d-none');
    this.$exampleTitles[this.$current].classList.add('active');

    this.$exampleTitles.forEach((title, key) => {
      if (key !== this.$current) {
        title.classList.remove('active');
        title.classList.remove('col-6');
        title.querySelector('.ob1-progress-bar-determined').classList.add('d-none');
      }
    });

    clearInterval(this.$intervalId);
    this.$intervalId = setInterval(() => {this._nextExample();}, this.$delay);

  }


  _scrollToSlide(slide) {
    const width = $(this.$contentSlider).width();
    $(this.$contentSlider).animate({scrollLeft: (width * slide)}, 800);
  }


  _mod(n, m) {
    return ((n % m) + m) % m;
  }
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".example-items")).forEach((exempleSlider) => {
    new OabExempleSlider(exempleSlider);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabExempleSlider = OabExempleSlider;

export default OabExempleSlider;
