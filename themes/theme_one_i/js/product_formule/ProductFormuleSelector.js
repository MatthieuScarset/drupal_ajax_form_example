
import FormuleField from "./FormuleField";
import CustomProgressBar from "./CustomProgressBar";
import ContactFormStep from "./ContactFormStep";
import ResultStep from "./ResultStep";
import ResultStack from "./ResultStack";

class ProductFormuleSelector {

  /**
   * @param root
   * @private
   */
  constructor(root) {
    this.$root = root;
    this.$modal = jQuery(this.$root.querySelector('.modal.modal-product-formule'));
    this.$formuleId = this.$root.dataset.formule || 0;

    this.$content = this.$root.querySelector('.modal-content');

    this.$modalIsOpen = false;
    this.$modal.on('shown.bs.modal', () => {this.$modalIsOpen = true;});
    this.$modal.on('hide.bs.modal', () => {
      this.$modalIsOpen = false;
      this._reset();
    });

    this.$progressBar = new CustomProgressBar(this.$root.querySelector('.progressbar'));
    this.$resultStep = new ResultStep(this.$root.querySelector('[data-step="result"]'));
    this.$resultStack = new ResultStack(this.$root.querySelector('.result-stack'), this);

    this.$fields = Array.from(this.$root.querySelectorAll('.modal-content .right-zone [data-step="process"]'));
    this.$fields.forEach((field) => {
      field.ontransitionend = (e) => {
        if (e.propertyName === 'opacity' && this.$root.style.opacity === 0) {
          this.$root.classList.add('d-none');
        }
      };
    });

    this.$formContact = new ContactFormStep(this.$root.querySelector('[data-step="contact-form"]'), this);


    this.$root.querySelector('.modal-content .left-zone [data-step="reception"] .btn.btn-begin').addEventListener('click', () => {
      this._start();
    });

    this.$steps = [];
    Array.from(this.$root.querySelectorAll('.formule-field')).forEach((formuleField) => {
      this.$steps.push(new FormuleField(formuleField, this));
    });

  }

  /**
   * Renvoie la valeur du field passé en paramètre
   * @param field
   * @return {null}
   */
  getFieldValue(field) {
    const values = this._getFieldValues();
    return values[field] || null;
  }

  setResult(key, value) {
    this.$resultStack.setResult(key, value);
    this.nextField();
  }

  /**
   * Display next field
   */
  nextField() {
    this._packageExists()
      .then(exists => {
        if (exists) {
          // On masque le field actuel
          const i = this.$fields.findIndex((field) => !field.classList.contains('d-none'));
          if (this.$fields[i]) {
            this.$fields[i].addEventListener('transitionend', () => {
              this.$fields[i].classList.add('d-none');
              // Et on affiche le prochain s'il existe
              if (this.$fields[i + 1]) {
                this.showField(this.$fields[i + 1]);
                this.$progressBar.nextStep();
              }
              else {
                // sinon on affiche le panneau de fin
                this._toResult();
              }
            }, {capture: false, once: true});
            this.$fields[i].style.opacity = 0;
          }
        }
        else {
          const i = this.$fields.findIndex((field) => !field.classList.contains('d-none'));
          if (this.$fields[i]) {
            this.$fields[i].addEventListener('transitionend', () => {
              this.$fields[i].classList.add('d-none');
              // Si on a aucun résultat, on redirige vers le formulaire de contact
              this._toContactForm(Object.keys(this._getFieldValues()).pop());
            }, {capture: false, once: true});
            this.$fields[i].style.opacity = 0;
          }
        }
      });
  }


  /**
   * Show the formule field with CSS transition
   */
  showField(field) {
    field.classList.remove("d-none");
    field.style.opacity = 1;
  }


  goToField(formuleFieldId) {
    const field = this.$root.querySelector(`[data-target=${formuleFieldId}]`);
    if (field) {
      const index = this.$fields.findIndex((f) => {
        return f.querySelector(`[data-target="${formuleFieldId}"]`) !== null;
      });
      if (index !== -1) {
        this.$progressBar.goToStep(index + 1);
      }

      const parent = field.closest('[data-step]');

      const currentDisplayedItem = this.$content.dataset.show === 'process' ?
        this.$root.querySelector(`[data-step="process"]:not(.d-none)`) :
        this.$root.querySelector(`[data-step="${this.$content.dataset.show}"]`);
      if (currentDisplayedItem) {
        currentDisplayedItem.addEventListener('transitionend', (e) => {
          if (e.propertyName && e.propertyName === "opacity") {
            currentDisplayedItem.classList.add('d-none');

            this.$content.dataset.show = "process";
            parent.classList.remove('d-none');
            parent.style.opacity = 1;
          }
        }, {capture: false, once: true});
        currentDisplayedItem.style.opacity = 0;
      }
    }
  }

  /**
   * Go to previous field
   */
  previousField() {
    // TODO previous field
  }

  /**
   * Début le process => Cache le panneau reception et affiche la 1ère question
   * @private
   */
  _start() {
    this.$content.dataset.show = "process";
    this.$root.querySelector('.right-zone').ontransitionend = (e) => {
      if (e.propertyName === 'width') {
        if (this.$fields[0]) {
          this.showField(this.$fields[0]);
        }
      }
    };

    this.$progressBar.display();
  }

  /**
   * Reset all datas on close
   * @private
   */
  _reset() {
    // TODO purger les données
  }

  _show(step) {
    this.$content.dataset.show = step;
  }

  /**
   * Return à l'accueil
   * @private
   */
  _backToReception() {
    this.$content.dataset.show = "reception";
  }

  /**
   * Envoie au formulaire de contact
   * @private
   */
  _toContactForm(formuleFieldId) {
    if (this.$formContact.setFormuleField(formuleFieldId)) {
      this._show("contact-form");
      this.$formContact.show();
    }
  }

  /**
   * Affiche le dernier panneau avec les infos.
   * Ne vérifie pas si l'utilisateur à le droit d'y accèder
   * @private
   */
  _toResult() {
    this.$resultStep.setUp(this.$formuleId, this._getFieldValues()).then(() => {
      this._show('result');
      this.$resultStep.show();
    });

  }


  async _packageExists() {
    const searchParams = new URLSearchParams(this._getFieldValues());
    const resp = await fetch(`/api/formule_package/exists/${this.$formuleId}?${searchParams.toString()}`, {
      headers: {
        'Accept': 'application/json'
      }
    });

    return resp.ok;
  }

  /**
   * Renvoie les valeurs de tous les fields déjà validés
   * @return {field: value}
   * @private
   */
  _getFieldValues() {
    const values = {};
    this.$steps.forEach((step) => {
      if (step.getValue()) {
        values[step.getTarget()] = step.getValue();
      }
    });

    return values;
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
