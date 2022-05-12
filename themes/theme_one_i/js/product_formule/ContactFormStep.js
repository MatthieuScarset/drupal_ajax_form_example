import Utils from "./Utils";


class ContactFormStep {

  constructor(root, parent) {
    this.$root = root;
    this.$parent = parent;
    this.$fieldConfigs = window.drupalSettings.formuleField || [];
  }

  /**
   * Return true/false si la config du Form s'est bien faite
   * @param id
   * @return {boolean}
   */
  setFormuleField(id) {
    if (!this.$fieldConfigs[id]) {
      return false;
    }

    const fieldData = this.$fieldConfigs[id];

    const title = (new DOMParser().parseFromString(fieldData.noResultTitle, "text/html")).documentElement.textContent;
    this.$root.querySelector('[data-field=no-result-title]').innerHTML =
      Utils.replaceToken(title, {answer: fieldData.options[this.$parent.getFieldValue(id)] || ""});

    this.$root.querySelector('[data-field=no-result-sentence]').innerHTML = fieldData.noResultSentence;
    this.$root.querySelector('[data-field=no-result-link]').setAttribute('href', fieldData.buttonLink);
    this.$root.querySelector('[data-field=no-result-link]').innerHTML = fieldData.buttonText;

    return true;
  }

}

export default ContactFormStep;

