class StepSlider {
  constructor(elem) {

    this.$root = elem;
    this.$current = 0;
    this.$steps = this.$root.querySelectorAll('.step');

    this.$delay = this.$root.dataset.delay ? 1000 * this.$root.dataset.delay : 1000;

    if (typeof this.$root.dataset.startAtLaunch !== 'undefined') {
      this._start();
    } else {
      window.addEventListener('scroll', () => {this._startIfVisible();});
    }
  }

  /**
   * Start the animation
   * @private
   */
  _start() {
    this.$current = 0;
    this._nextStep();   // Launch 1st step
    this.$intervalId = setInterval(() => {this._nextStep();}, this.$delay);
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
    const el = this.$steps[0];

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
  _nextStep() {
    this.$current++;
    this.$width = ($(this.$root).width() + $(this.$root.children).width())/2;
    this.$root.querySelectorAll('.step.active').forEach((step) => {
      step.classList.remove('active');
      step.classList.add('done');

      //Gestion du scroll des éléments en version mobile
      if (window.matchMedia("(max-width: 736px)").matches) {
        $(this.$root).animate({scrollLeft : "+="+this.$width}, 800);
      }
    });

    // Si $current existe pas... on va dire qu'on est à la fin
    if (this.$steps[this.$current-1]) {
      this.$steps[this.$current-1].classList.add('active');
    }
    else {
      clearInterval(this.$intervalId);

      //On revient au début des éléments en mobile
      if (window.matchMedia("(max-width: 736px)").matches) {
        $(this.$root).animate({scrollLeft : 0}, 800);
      }
    }
  }
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".step-slider")).forEach((slider) => {
    new StepSlider(slider);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.StepSlider = StepSlider;

export default StepSlider;
