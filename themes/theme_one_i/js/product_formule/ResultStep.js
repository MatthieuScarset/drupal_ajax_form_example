

class ResultStep {
  constructor(root) {
    this.$root = root;
  }

  async setUp(formule, results) {
    const searchParams = new URLSearchParams(results);
    fetch(`/api/formule_package/${formule}?${searchParams.toString()}`).then((response) => {
      return response.text();
    }).then((html) => {
      this.$root.innerHTML = html;
    });
  }

  show() {
    this.$root.style.opacity = 0;
    this.$root.classList.remove("d-none");
    this.$root.style.opacity = 1;
  }

  hide() {
    delete this.$root.style.opacity;
  }

}

export default ResultStep;
