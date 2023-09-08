class ModuleCustomerBenefits {
  constructor(root) {
    this.$root = root;
    this.$cutomerBenefitsItems = Array.from(this.$root.querySelectorAll('.customer-benefits-items'));

    $(window).resize(()=> {
      this._setMinHeight();
    });

    this._setMinHeight();
  }

  _setMinHeight() {
    let minHeight = 0;
    if (window.matchMedia("(min-width: 736px)").matches) {
      this.$cutomerBenefitsItems.forEach((item) => {
        minHeight = Math.max(minHeight, item.querySelector('.field-title').offsetHeight);
      });
      this.$cutomerBenefitsItems.forEach((item) => {
        item.querySelector('.field-title').style.minHeight = `${minHeight}px`;
      });
    }
  }
}



document.addEventListener("DOMContentLoaded", () => {
  const elems = document.querySelectorAll(".paragraph--type--module-customer-benefits");
  [].forEach.call(elems, (elem) => new ModuleCustomerBenefits(elem));
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.ModuleCustomerBenefits = ModuleCustomerBenefits;

export default ModuleCustomerBenefits;
