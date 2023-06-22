import ModuleExempleSlider from "./module-exemple-slider";

class ModuleStorytelling {

  constructor(elem) {
    this.$storyParts = elem.querySelectorAll('.storypart');

    this.$observer =  new IntersectionObserver(function(entries) {
      entries.forEach((entry) => {
        if(entry.isIntersecting) {
          elem.querySelectorAll('.items-list-item').forEach((storyList) => {
            if (storyList.dataset.storyTitleId !== entry.target.dataset.storyId) {
              storyList.classList.remove('active');
              storyList.querySelector('.item-icon').classList.add('d-none');
            } else {
              storyList.classList.add('active');
              storyList.querySelector('.item-icon').classList.remove('d-none');
            }
          });
        }
      });
    }, { threshold: [0.70] });

    this.$storyParts.forEach((el) => this.$observer.observe(el));
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
