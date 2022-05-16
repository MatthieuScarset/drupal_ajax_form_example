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

    let config = Object.values(this.$fieldConfigs[id].emptyConfigs).find((config) => {
      return config.inputs && Object.values(config.inputs).find((input) => input === id);
    });
    
    if (!config) {
      config = this.$fieldConfigs[id].emptyConfigs.default;
    }


    // const fieldData = this.$fieldConfigs[id];

    const title = (new DOMParser().parseFromString(config.no_result_title, "text/html")).documentElement.textContent;
    this.$root.querySelector('[data-field=no-result-title]').innerHTML =
      Utils.replaceToken(title, {answer: this.$fieldConfigs[id].options[this.$parent.getFieldValue(id)] || ""});

    this.$root.querySelector('[data-field=no-result-sentence]').innerHTML = config.no_result_sentence;
    this.$root.querySelector('[data-field=no-result-link]').setAttribute('href', config.button_link);
    this.$root.querySelector('[data-field=no-result-link]').innerHTML = config.button_text;

    return true;
  }

}

export default ContactFormStep;

