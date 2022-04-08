
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
    this.$root.querySelectorAll('.step.active').forEach((step) => {
      step.classList.remove('active');
      step.classList.add('done');
      step.querySelector('.ob1-spinner-determined').classList.add('d-none');
    });
    // Si $current existe pas... on va dire qu'on est à la fin
    if (this.$steps[this.$current-1]) {
      this.$steps[this.$current-1].classList.add('active');
      this.$steps[this.$current-1].querySelector('.ob1-spinner-determined').classList.remove('d-none');
    } else {
      clearInterval(this.$intervalId);
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
