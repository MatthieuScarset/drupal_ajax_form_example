
class FormuleSelectorStep {

  constructor(root, parent, isReception = false) {
    this.$root = root;
    this.$parent = parent;
    this.$isReception = isReception;
  }

  isDisplayed() {
    return !this.$root.classList.contains('d-none');
  }

  show() {
    this.$root.classList.remove('d-none');
  }

  hide() {
    this.$root.classList.add('d-none');
  }

}

export default FormuleSelectorStep;
