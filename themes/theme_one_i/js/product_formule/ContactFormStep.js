import Utils from "./Utils";


class ContactFormStep {

  constructor(root, parent) {
    this.$root = root;
    this.$parent = parent;
    this.$drupalSettings = window.drupalSettings;
    this.$fieldConfigs = window.drupalSettings.formuleField || [];
  }

  show() {
    this.$root.style.opacity = 0;
    this.$root.classList.remove("d-none");
    this.$root.style.opacity = 1;
  }

  /**
   * Return true/false si la config du Form s'est bien faite
   * @param id
   * @return {boolean}
   */
  setFormuleField(id, value) {
    if (!this.$fieldConfigs[id]) {
      return false;
    }



    let emptyConfig = Object.values(this.$fieldConfigs[id].emptyConfigs).find((config) => {
      return config.inputs && Object.values(config.inputs).find((input) => { return input === value});
    });

    if (!emptyConfig) {
      emptyConfig = this.$fieldConfigs[id].emptyConfigs.default;
    }


    // const fieldData = this.$fieldConfigs[id];

    const tokensReplacement = {answer: this.$fieldConfigs[id].options[this.$parent.getFieldValue(id)] || ""};
    const title = (new DOMParser().parseFromString(emptyConfig.no_result_title, "text/html")).documentElement.textContent;
    this.$root.querySelector('[data-field=no-result-title]').innerHTML =
      Utils.replaceToken(title, tokensReplacement);

    this.$root.querySelector('[data-field=no-result-sentence]').innerHTML =
      Utils.replaceToken(emptyConfig.no_result_sentence, tokensReplacement);
    const link = this.$root.querySelector('[data-field=no-result-link]');

    link.setAttribute('href', emptyConfig.button_link);
    link.innerHTML = emptyConfig.button_text;


    return true;
  }

}

export default ContactFormStep;

