class OabExempleSlider {
  constructor(elem) {
    this.$root = elem;
    this.$current = 0;
    this.$examples = this.$root.querySelectorAll('.example-progress-bar');
    this.$content = this.$root.querySelector('.example-content');
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
    const el = this.$examples[0];
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
    this.$current++;
    this.$width = $(this.$content).width() ;
    this.$root.querySelectorAll('.example-progress-bar.active').forEach((progress_bar) => {
      if (window.matchMedia("(max-width: 736px)").matches) {
        progress_bar.classList.remove('col-6');
      }
      progress_bar.classList.remove('active');
      progress_bar.querySelector('.ob1-progress-bar-determined').classList.add('d-none');
      $(this.$content).animate({scrollLeft : "+="+this.$width}, 800);
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
      $(this.$content).animate({scrollLeft : 0}, 800);
      clearInterval(this.$intervalId);
      this._start();
    }
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
