class CustomAlignment {
  constructor(root) {
    this.$root = root;
    this.$moduleItems = Array.from(this.$root.querySelectorAll('.horizontal-align-item'));

    $(window).resize(()=> {
      this._setMinHeight();
    });

    this._setMinHeight();
  }

  _setMinHeight() {
    let minHeight = 0;
    if (window.matchMedia("(min-width: 736px)").matches) {
      this.$moduleItems.forEach((item) => {
        minHeight = Math.max(minHeight, item.querySelector('.horizontal-align-item-field').offsetHeight);
      });
      this.$moduleItems.forEach((item) => {
        item.querySelector('.horizontal-align-item-field').style.minHeight = `${minHeight}px`;
      });
    }
  }
}



document.addEventListener("DOMContentLoaded", () => {
  const elems = document.querySelectorAll('.custom-alignment');
  [].forEach.call(elems, (elem) => new CustomAlignment(elem));
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.CustomAlignHeight = CustomAlignment;

export default CustomAlignment;
