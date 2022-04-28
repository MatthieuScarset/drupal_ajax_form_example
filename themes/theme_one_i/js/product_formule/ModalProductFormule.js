
class ModalProductFormule {

  /**
   * @param root
   * @private
   */
  constructor(root) {
    this.$root = root;
    this.$drupalSettings = window.drupalSettings;
    this.$modal = jQuery(this.$root.querySelector('.modal.modal-product-formule'));

    this.$modalIsOpen = false;
    this.$modal.on('shown.bs.modal', () => {this.$modalIsOpen = true;});
    this.$modal.on('hide.bs.modal', () => {this.$modalIsOpen = false;});

  }

}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll("[data-formule]")).forEach((formule) => {
    new ModalProductFormule(formule);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.ModalProductFormule = ModalProductFormule;

export default ModalProductFormule;
