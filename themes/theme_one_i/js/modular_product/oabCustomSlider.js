import { elementScrollIntoViewPolyfill } from "seamless-scroll-polyfill";

class OabCustomSlider {

  constructor(elem) {
    elementScrollIntoViewPolyfill();

    this.$root = elem;
    this.$container = this.$root.querySelector('.slider-container');
    this.$containerChildrens = this.$container.children;

    this.$root.querySelectorAll('.slider-controller > [data-direction]')
      .forEach((button) => {
        button.addEventListener('click', () => {this._slide(button.dataset.direction);});
      });
  }

  /**
   * slide to the next element
   * @private
   */
  _slide(direction) {
    const elem = this._getFirstHidden(direction);

    if (typeof elem !== 'undefined') {
      elem.scrollIntoView({
        behavior: 'smooth',
        block: 'nearest',
        inline: 'nearest'
      });
    }
  }

  _getFirstHidden(sens) {
    const elems = sens === 'left'
      ? Array.from(this.$containerChildrens).slice()
      : Array.from(this.$containerChildrens).slice().reverse();

    let firstHidden;

    elems.forEach((el) => {
      const rect = el.getBoundingClientRect();
      const position = (rect.left + rect.right) / 2;

      const basePosition = sens === 'left' ? this.$container.getBoundingClientRect().left : this.$container.getBoundingClientRect().right;

      if ((sens === 'left' && position < basePosition) || (sens === 'right' && position > basePosition)) {
        firstHidden = el;
      }
    });
    return firstHidden;
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
