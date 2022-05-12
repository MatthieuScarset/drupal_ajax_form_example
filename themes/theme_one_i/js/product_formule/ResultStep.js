

class ResultStep {
  constructor(root) {
    this.$root = root;
  }

  async _setUp(formule, results) {
    const searchParams = new URLSearchParams(results);
    fetch(`/api/formule_package/${formule}?${searchParams.toString()}`).then((response) => {
      return response.text();
    }).then((html) => {
      this.$root.innerHTML = html;
    });
  }

}

export default ResultStep;
