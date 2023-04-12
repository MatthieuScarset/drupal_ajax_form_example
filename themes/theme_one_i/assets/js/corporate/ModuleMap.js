class ModuleMap {
  constructor(elem) {
    this.$root = elem;
    this.$mapImage = Array.from(this.$root.querySelectorAll('.map-image'));
    this.$mapTitle = this.$root.querySelectorAll('.map-image-title a.button-chip');
    this.$mapTitle.forEach((title)=> {
      title.addEventListener('click', (e) => {this._onClick(e);})
    });
  }

  _onClick(event) {
    if (!event.currentTarget.classList.contains("active")) {
      this.$mapTitle.forEach((title)=> {
        title.classList.remove("active");
      });

      this.$mapImage.forEach((mapImage) => {
        mapImage.classList.remove("active");
      });
    }


    const item = this.$mapImage
      .find((item) => item.dataset.paragraph === event.currentTarget.dataset.target);

    if (typeof item !== "undefined") {
      item.classList.add("active");
      event.currentTarget.classList.add("active");
    } else {
      event.currentTarget.classList.add('d-none');
    }
  }
}

document.addEventListener("DOMContentLoaded", () => {
  const moduleMaps = document.querySelectorAll(".paragraph--type--module-map");
  [].forEach.call(moduleMaps, (moduleMap) => new ModuleMap(moduleMap));
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.ModuleMap = ModuleMap;

export default ModuleMap;
