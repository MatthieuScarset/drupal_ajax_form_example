class ModuleMap {
  constructor() {

    document.querySelector('a.button-chip:first-child').classList.add("active");
    document.querySelector('.map-image:first-child').classList.add("active");
    document.querySelector('.map-image:first-child').style.opacity = 1;
    this.$mapImage = document.querySelectorAll('.map-image');
    this.$mapTitle = document.querySelectorAll('.map-image-title a.button-chip');
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
        mapImage.style.opacity = 0;
        mapImage.classList.remove("active");
      });
    }

    event.currentTarget.classList.add("active");
    this.$mapImage.forEach((item) => {
      if (item.dataset.paragraph === event.currentTarget.dataset.target) {
        item.classList.add("active");
        item.style.opacity = 1;
        item.style.transition = "opacity 1s linear";
      }
    });
  }
}

const moduleMap = new ModuleMap();
