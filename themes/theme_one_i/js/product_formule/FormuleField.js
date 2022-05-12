
class FormuleField {

  /**
   *
   * @param root
   * @param parent
   */
  constructor(root, parent) {
    this.$root = root;

    this.$parent = parent;
    this.$inputName = this.$root.dataset.inputName;

    this.$submit = this.$root.querySelector('button.formule-submit');
    this.$submit.addEventListener('click', (e) => {
      e.preventDefault();
      this.$parent.setResult(this.getTarget(), this.getValue());
    });


    this.$inputs = [];
    Array.from(this.$root.querySelectorAll('li')).forEach((input) => {
      this.$inputs.push(input);
      input.querySelector('input').addEventListener('change', (e) => {
        this.unactiveAll();
        input.classList.add('active');
        this.$submit.disabled = false;
      });
    });

  }

  unactiveAll() {
    this.$inputs.forEach((input) => {
      input.classList.remove('active');
    });
  }

  getTarget() {
    return this.$root.dataset.target;
  }

  getValue() {
    if (this.$root.querySelector(`input[name="${this.$inputName}"]:checked`)) {
      return this.$root.querySelector(`input[name="${this.$inputName}"]:checked`).value;
    }
    return null;
  }

}

export default FormuleField;
