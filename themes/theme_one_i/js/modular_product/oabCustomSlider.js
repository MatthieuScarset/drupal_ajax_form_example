
class OabCustomSlider {

  constructor(elem) {
    this.root = elem;
    this.container = this.root.querySelector('.slider-container');
    this.root.querySelectorAll('.slider-controller > [data-direction]')
      .forEach((button) => {
        button.addEventListener('click', this.slide);
    });
  }

  slide = (event) => {
    if (typeof event.currentTarget.dataset.direction !== 'undefined' ) {
      const direction = event.currentTarget.dataset.direction;
      let scrollCompleted = 0;
      const slideVar = setInterval(() => {
        if (typeof this.container == 'undefined') {
          return;
        }
        if (direction === 'left') {
          this.container.scrollLeft -= 50;
        }
        else {
          this.container.scrollLeft += 50;
        }
        scrollCompleted += 10;
        if (scrollCompleted >= 100) {
          window.clearInterval(slideVar);
        }
      }, 50);
    }
  }
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".custom-slider")).forEach((slider) => {
    new OabCustomSlider(slider);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabCustomSlider = OabCustomSlider;

export default OabCustomSlider;
