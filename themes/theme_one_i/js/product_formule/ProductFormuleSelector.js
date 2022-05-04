
import FormuleSelectorStep from "./FormuleSelectorStep";

class ProductFormuleSelector {

  /**
   * @param root
   * @private
   */
  constructor(root) {
    this.$root = root;
    this.$drupalSettings = window.drupalSettings;
    this.$modal = jQuery(this.$root.querySelector('.modal.modal-product-formule'));
    this.$content = this.$root.querySelector('.modal-content');

    this.$modalIsOpen = false;
    this.$modal.on('shown.bs.modal', () => {this.$modalIsOpen = true;});
    this.$modal.on('hide.bs.modal', () => {this.$modalIsOpen = false;});


    this.$root.querySelector('.modal-content [data-step="reception"] .btn.btn-begin').addEventListener('click', () => {
      this._start();
    });

    this.$steps = [];
    Array.from(this.$root.querySelectorAll('.formule-field')).forEach((step) => {
      this.$steps.push(new FormuleField(step, this));
    });

  }

  /**
   * Début le process => Cache le panneau reception et affiche la 1ère question
   * @private
   */
  _start() {
    this.$content.dataset.show = "process";
  }


  backToReception() {
    this.$content.dataset.show = "reception";
  }

  nextField() {
    // TODO next field
  }

  previousField() {
    // TODO next field
  }


}

document.addEventListener("DOMContentLoaded", () => {

  Array.from(document.querySelectorAll("[data-formule]")).forEach((formule) => {
    new ProductFormuleSelector(formule);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.ProductFormuleSelector = ProductFormuleSelector;

export default ProductFormuleSelector;
