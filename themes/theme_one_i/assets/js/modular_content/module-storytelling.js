import ModuleExempleSlider from "./module-exemple-slider";

class ModuleStorytelling {

  constructor(elem) {
    this.$root = elem;
    this.$current = 1;
    this.$storyPanel = elem.querySelector('.right-panel');
    this.$storyParts = this.$root.querySelectorAll('.storypart');
    this.firstStoryPart = this.$root.querySelector('#story1');

    this.firstStoryPart.classList.add('active');
    this.firstStoryPart.querySelector('.item-icon').classList.toggle('d-mb-block');
    this.firstStoryPart.querySelector('.item-icon').classList.toggle('d-none');

    this.$root.querySelector('.right-panel').addEventListener('scroll', () => {
      this._changeActiveIcon();
    })
  }

  _isActive() {
    let isVisible

    this.$storyParts.forEach((storyPart, index) => {
      const rect = storyPart.getBoundingClientRect();
      const position = (rect.top + rect.bottom) / 2;

      const topPosition = this.$storyPanel.getBoundingClientRect().top;
      const bottomPosition = this.$storyPanel.getBoundingClientRect().bottom;

      //verify if the element is visible
      if ((rect.top > (topPosition - 10) || position > topPosition) && (position < bottomPosition || Math.trunc(rect.bottom) < bottomPosition)) {
        isVisible = index+1;
      }
    })

    return isVisible;
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
