import ModuleExempleSlider from "./module-exemple-slider";

class ModuleStorytelling {

  constructor(elem) {
    this.$root = elem;
    this.$storyPanel = elem.querySelector('.right-panel');
    this.$storyParts = this.$root.querySelectorAll('.storypart');
    this.firstStoryPart = this.$root.querySelector('#story1');

    this.firstStoryPart.classList.add('active');
    this.firstStoryPart.querySelector('.item-icon').classList.toggle('d-mb-block');
    this.firstStoryPart.querySelector('.item-icon').classList.toggle('d-none');

    this.$root.querySelector('.right-panel').addEventListener('scroll', () => {
      this._changeActiveIcon();
    });

    this._trapScroll();

  }

  _isActive() {
    let indexElemVisible = 1;

    this.$storyParts.forEach((storyPart, index) => {
      const rect = storyPart.getBoundingClientRect();
      const topPosition = this.$storyPanel.getBoundingClientRect().top;

      let elemStyle =  window.getComputedStyle(storyPart);
      let elemPaddingBottom = parseInt(elemStyle.paddingBottom)

      //verify if the element is visible
      if ((rect.bottom - elemPaddingBottom) > topPosition && (rect.top - elemPaddingBottom)  <= topPosition) {
        indexElemVisible = index+1;
      }
    });

    return indexElemVisible;
  }

  _changeActiveIcon() {
    let idStoryActive = '#story' + this._isActive();
    let storyActive = this.$root.querySelector(idStoryActive);

    this.$root.querySelectorAll('.items-list-item').forEach((storyList) => {
      if (storyList !== idStoryActive) {
        storyList.classList.remove('active');
        storyList.querySelector('.item-icon').classList.remove('d-mb-block');
        storyList.querySelector('.item-icon').classList.add('d-none');
      }
    });

    storyActive.classList.add('active');
    storyActive.querySelector('.item-icon').classList.toggle('d-mb-block');
    storyActive.querySelector('.item-icon').classList.toggle('d-none');
  }

}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".storytelling")).forEach((storytellingElem) => {
    new ModuleStorytelling(storytellingElem);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabStorytelling = ModuleStorytelling;

export default ModuleStorytelling;
