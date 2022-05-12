import Utils from "./Utils";

class ResultStack {
  constructor(root, parent) {
    this.$root = root;
    this.$parent = parent;
    this.$fieldConfigs = window.drupalSettings.formuleField || [];
    this.$drupal = window.Drupal;

    this.$defaultTemplate = `<div class="stack-item" data-item="" >` +
        `<div class="stack-item-result"></div>` +
        `<button class="btn btn-link" >${this.$drupal.t('edit')}</button>` +
      `</div>`;

    this.results = {};
  }

  display() {
    this.$root.classList.remove('d-none');
  }

  setResult(formuleFieldId, value) {
    this.display();
    this.results[formuleFieldId] = value;
    if (this.$root.querySelector(`[data-item=${formuleFieldId}]`)) {
      this.$root.querySelector(`[data-item=${formuleFieldId}] .stack-item-result`).innerHTML =
        Utils.replaceToken(
          this.$fieldConfigs[formuleFieldId].resultSentence,
          {answer: this.$fieldConfigs[formuleFieldId].options[value] || ""}
        );
    } else {
      this.$root.append(this._createItem(formuleFieldId, value));
    }

  }

  _createItem(formuleFieldId, value) {
    const template = document.createElement('template');
    template.innerHTML = this.$defaultTemplate.trim(); // Never return a text node of whitespace as the result

    template.content.querySelector('.stack-item').dataset.item = formuleFieldId;
    template.content.querySelector('button').addEventListener('click', () => {
      this.$parent.goToField(formuleFieldId);
    });

    template.content.querySelector('.stack-item-result').innerHTML =
      Utils.replaceToken(
        this.$fieldConfigs[formuleFieldId].resultSentence,
        {answer: this.$fieldConfigs[formuleFieldId].options[value] || "" }
      );

    return template.content.firstChild;
  }
}

export default ResultStack;
