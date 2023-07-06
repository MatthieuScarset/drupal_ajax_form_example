class ModuleStorytelling {

  constructor(elem) {
    this.$storyParts = elem.querySelectorAll('.storypart');
    this.windowHeight = window.innerHeight;

    this.$observer =  new IntersectionObserver(function(entries) {
      entries.forEach((entry) => {
        if(entry.isIntersecting) {
          elem.querySelectorAll('.items-list-item').forEach((storyTitle) => {
            if (storyTitle.dataset.storyId !== entry.target.dataset.storyId) {
              storyTitle.classList.remove('active');
              storyTitle.querySelector('.item-icon').classList.add('d-none');
            } else {
              storyTitle.classList.add('active');
              storyTitle.querySelector('.item-icon').classList.remove('d-none');
            }
          });
        }
      });
    }, { threshold: 0, rootMargin: `-${this.windowHeight*0.3}px 0px -${this.windowHeight*0.7}px 0px` });

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
