class OabExempleSlider {
  constructor(elem) {
    this.$root = elem;
    this.$current = 0;
    this.$examples = this.$root.querySelectorAll('.example-progress-bar');
    this.$exampleTitle = this.$root.querySelectorAll('.example-title a');
    this.$content_slider = this.$root.querySelector('.example-content');
    this.$delay = this.$root.dataset.delay ? 1000 * this.$root.dataset.delay : 1000;
    this.$exampleTitle.forEach((a) => {
      a.addEventListener('click', this._onClick);
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
  _onClick = (event) => {
    if (!event.currentTarget.classList.contains("active")) {
      this.$exampleTitle.forEach((title)=> {
        title.classList.remove("active");
      });
      event.currentTarget.classList.add("active");
      clearInterval(this.$intervalId);
      this._slide(parseInt(event.target.dataset.index) + 1);
      this.$intervalId = setInterval(() => {this._nextExample();}, this.$delay);
    }
  }

  /**
   * Start the animation
   * @private
   */
  _start() {
    this.$current = 0;
    this._nextExample(); // Launch 1st step
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
    this._slide(this.$current + 1);
  }

  _slide(scrollTo) {
    const width = $(this.$content_slider).width() ;
    this.$root.querySelectorAll('.example-progress-bar.active').forEach((progress_bar) => {
      //Gestion de la progress bar en mobile
      if (window.matchMedia("(max-width: 736px)").matches) {
        progress_bar.classList.remove('col-6');
      }

      const diff = scrollTo - this.$current;

      progress_bar.classList.remove('active');
      progress_bar.querySelector('.ob1-progress-bar-determined').classList.add('d-none');
      $(this.$content_slider).animate({scrollLeft : "+="+(width * diff)}, 800);
    });

    this.$exampleTitle.forEach((title)=>{
      title.classList.remove('active');
    });

    this.$current = scrollTo;

    // Si $current existe pas... on va dire qu'on est à la fin
    if (this.$examples[this.$current-1]) {
      //Gestion de la progress bar en mobile
      if (window.matchMedia("(max-width: 736px)").matches) {
        this.$examples[this.$current-1].classList.add('col-6');
      }
      this.$examples[this.$current-1].classList.add('active');
      this.$examples[this.$current-1].querySelector('.ob1-progress-bar-determined').classList.remove('d-none');
      this.$exampleTitle[this.$current-1].classList.add('active');
    }
    else  {
      clearInterval(this.$intervalId);
      $(this.$content_slider).animate({scrollLeft : 0}, 800);
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
