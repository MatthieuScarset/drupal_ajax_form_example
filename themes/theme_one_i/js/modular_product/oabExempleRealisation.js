import { elementScrollIntoViewPolyfill } from "seamless-scroll-polyfill";

class oabExempleRealisation {
  constructor(elem) {
    elementScrollIntoViewPolyfill();

    this.$root = elem;
    this.$current = 0;
    this.$examples = this.$root.querySelectorAll('.example');
    this.container = this.$root.querySelector('.example-content');
    this.$delay = this.$root.dataset.delay ? 1000 * this.$root.dataset.delay : 1000;

    if (typeof this.$root.dataset.startAtLaunch !== 'undefined') {
      this._start();
    }
    else {
      window.addEventListener('scroll', () => {this._startIfVisible();});
    }
  }

  /**
   * Start the animation
   * @private
   */
  _start() {
    this.$current = 0;
    this._nextExample();   // Launch 1st step
    this.$intervalId = setInterval(() => {this._nextExample();}, this.$delay);
  }

  /**
   * Start the animation if the steps are visible
   * @private
   */
  _startIfVisible() {
    if (this._checkIfVisible() && !this.$intervalId) {
      this._start();
    }
  }

  /**
   * Check if the steps are visible
   * @private
   */
  _checkIfVisible() {
    const el = this.$examples[0];

    var rect = el.getBoundingClientRect();
    var elemTop = rect.top;
    var elemBottom = rect.bottom;

    // Partially visible elements return true:
    return elemTop < window.innerHeight && elemBottom >= 0;
  }

  /**
   * Change to the next one
   * @private
   */
  _nextExample() {
    this.$current++;
    this.$width = $(this.container).width() ;
    this.$root.querySelectorAll('.example.active').forEach((example) => {
      example.classList.remove('active');
      example.classList.remove('col-6');
      example.classList.add('done');
      example.querySelector('.ob1-progress-bar-determined').classList.add('d-none');
      $(this.container).animate({scrollLeft : "+="+this.$width}, 800);
    });

    // Si $current existe pas... on va dire qu'on est à la fin
    if (this.$examples[this.$current-1]) {

      //Gestion du col mobile qui devient un col-6
      if (window.matchMedia("(max-width: 736px)").matches) {
        this.$examples[this.$current-1].classList.add('col-6');
      }

      this.$examples[this.$current-1].classList.add('active');
      this.$examples[this.$current-1].querySelector('.ob1-progress-bar-determined').classList.remove('d-none');
    }
    else  {
      clearInterval(this.$intervalId);
      $(this.container).animate({scrollLeft : 0}, 0);
    }
  }


}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".example-slider")).forEach((exempleRealisation) => {
    new oabExempleRealisation(exempleRealisation);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.oabExempleRealisation = oabExempleRealisation;

export default oabExempleRealisation;
