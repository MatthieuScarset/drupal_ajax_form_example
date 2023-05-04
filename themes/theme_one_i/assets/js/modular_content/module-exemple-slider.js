import ModuleExempleMobileSlider from "./module-exemple-mobile-slider";

class ModuleExempleSlider {

  constructor(elem) {
    this.$root = elem;
    this.$current = 1;
    this.$exampleTitles = this.$root.querySelectorAll('.example-titles a');
    this.$contentSlider = this.$root.querySelector('.example-content');
    this.$delay = this.$root.dataset.delay ? 1000 * this.$root.dataset.delay : 1000;
    this.$exampleTitles.forEach((a) => {
      a.addEventListener('click', (e) => {this._onClick(e);});
    });

    this.$isSliderAnimating = false;

    // Lorsqu'il y a un resize, on garde la slide alignée
    window.addEventListener('resize', () => {
      this._scrollToSlide(this.$current);
      if (window.matchMedia("(min-width: 736px)").matches) {
        this.$exampleTitles[this.$current].classList.remove('col-6');
      } else {
        this.$exampleTitles[this.$current].classList.add('col-6');
      }
    });

    if (typeof this.$root.dataset.startAtLaunch !== 'undefined') {
      this._start();
    }
    else {
      window.addEventListener('scroll', this.$startIfVisibleReference = this._startIfVisible.bind(this));
    }

    this.$mobileSlider = new ModuleExempleMobileSlider(this.$contentSlider, this);

  }

  get isSliderAnimating() {
    return this.$isSliderAnimating;
  }

  get currentSliderPositionX() {
    return this.$currentSliderPositionX ?? 0;
  }

  /**
   * Return current slide
   * @return {number}
   * @private
   */
  get current() {
    return this.$current;
  }

  /**
   * Manage class and do the scroll
   * @param slide
   * @private
   */
  set current(slide) {
    if (!this.$isSliderAnimating) {
      // Number.mod()
      this.$current = this._mod(slide, this.$exampleTitles.length ?? 1);
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
      this.$intervalId = setInterval(() => {this.nextExample();}, this.$delay);
    }

  }

  /**
   * Change to the next one
   */
  nextExample() {
    this.current++;
  }

  /**
   * Change to the previous one
   */
  previousExample() {
    this.current--;
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
      this.current = parseInt(event.currentTarget.dataset.index);
    }
  }

  /**
   * Start the animation
   * @private
   */
  _start() {
    this.current = 0; // Launch 1st step
  }

  /**
   * Start the animation if the examples are visible
   * @private
   */
  _startIfVisible() {
    if (this._checkIfVisible() && !this.$intervalId) {
      this._start();

      // Remove listener onScroll when it has started
      if (typeof this.$startIfVisibleReference !== 'undefined') {
        window.removeEventListener('scroll', this.$startIfVisibleReference);
        delete this.$startIfVisibleReference;
      }
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
   * Do and animate the slide
   * @param slide
   * @private
   */
  _scrollToSlide(slide) {
    const width = $(this.$contentSlider).width();
    if (!this.$isSliderAnimating) {
      this.$isSliderAnimating = true;
      $(this.$contentSlider).animate({scrollLeft: (width * slide)}, {
        duration: 800,
        done: () => {
          this.$currentSliderPositionX = width * slide;
          this.$isSliderAnimating = false;
        }
      });
    }

  }


  /**
   * Modulo
   * @param n
   * @param m
   * @return {number}
   * @private
   */
  _mod(n, m) {
    return ((n % m) + m) % m;
  }
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".example-items")).forEach((exempleSlider) => {
    new ModuleExempleSlider(exempleSlider);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabExempleSlider = ModuleExempleSlider;

export default ModuleExempleSlider;
