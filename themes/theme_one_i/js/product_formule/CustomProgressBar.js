import Utils from "./Utils";

class CustomProgressBar {
  constructor(root) {
    this.$root = root;

    this.$baseLabel = this.$root.dataset.label;

    this.$progressBar = this.$root.querySelector('progress');
    this.$progressLabel = this.$root.querySelector('.progressbar-label');

    this.$currentStep = 1;
  }

  /**
   * Change displayed info with the CurrentStep value
   * @private
   */
  _changeStep() {
    this.$progressBar.value = this.$currentStep;
    this.$progressLabel.innerHTML = Utils.replaceToken(this.$baseLabel, {'num_question': this.$currentStep});
  }

  nextStep() {
    this.$currentStep ++;
    this._changeStep();
  }

  previousStep() {
    this.$currentStep --;
    this._changeStep();
  }

  goToStep(index) {
    this.$currentStep = index;
    this._changeStep();
  }

  getCurrentStep() {
    return this.$currentStep;
  }

  display() {
    this.$root.classList.remove('d-none');
  }

  restart() {
    this.$root.classList.add('d-none');
    this.$currentStep = 1;
  }
}


export default CustomProgressBar;
