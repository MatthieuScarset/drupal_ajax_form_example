import { elementScrollIntoViewPolyfill } from "seamless-scroll-polyfill";

class CustomSlider {

  constructor(elem) {
    elementScrollIntoViewPolyfill();

    this.$root = elem;
    this.$container = this.$root.querySelector('.slider-container');
    this.$currentStepSlider = this.$root.querySelector('.current-step-slider');
    if (this.$container) {
      this.$containerChildrens = this.$container.children;
    } else {
      return;
    }

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

      this._changeStepSlider(elem.dataset.target);

      if (elem.classList.contains('item-detail-offre')) {
        this.$width = elem.getBoundingClientRect().width;
        if (direction === 'left') {
          $(this.$container).animate({scrollLeft : "-="+this.$width}, 800);
        }
        else {
          $(this.$container).animate({scrollLeft : "+="+this.$width}, 800);
        }
      }
      else {
        elem.scrollIntoView({
          behavior: 'smooth',
          block: 'nearest',
          inline: 'nearest'
        });
      }
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
      //verify if the element is hidden or partially hidden
      if ((sens === 'left' && (rect.left < (basePosition-10) || position < basePosition)) || (sens === 'right' && (position > basePosition || Math.trunc(rect.right) > basePosition))) {
        firstHidden = el;
      }
    });
    return firstHidden;
  }

  _changeStepSlider(number) {
    this.$currentStepSlider.innerText = number;
  }
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".custom-slider")).forEach((slider) => {
    new CustomSlider(slider);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabCustomSlider = CustomSlider;

export default CustomSlider;
