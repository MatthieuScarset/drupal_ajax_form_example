class OabDetailOffre {

  constructor(elem) {
    this.$root = elem;
    this.$offres = this.$root.querySelectorAll('.detail-offre-item');
    this.$root.querySelectorAll('button.see-more').forEach((btn) => {
      btn.addEventListener('click', this._toggleItems);
    });
  }

  _toggleItems = (event) => {

    if (window.matchMedia("(max-width: 736px)").matches) {
      const is_initially_open = event.currentTarget.closest('.detail-offre-item').classList.contains('item-open');

      this.$offres.forEach((offre) => {
        offre.classList.remove('item-open');
        offre.classList.add('item-close');

        offre.querySelector('button.see-more').classList.remove('up');
        offre.querySelector('button.see-more').classList.add('down');

        offre.querySelector('button.see-more .text-voir-tout').classList.remove('d-none');
        offre.querySelector('button.see-more .text-voir-moins').classList.add('d-none');
      });

      if (!is_initially_open) {
        event.currentTarget.closest('.detail-offre-item').classList.toggle('item-close');
        event.currentTarget.closest('.detail-offre-item').classList.toggle('item-open');
        event.currentTarget.classList.toggle('up');
        event.currentTarget.classList.toggle('down');
      }

      if (event.currentTarget.classList.contains('up')) {
       event.currentTarget.querySelector('button.see-more .text-voir-tout').classList.add('d-none');
       event.currentTarget.querySelector('button.see-more .text-voir-moins').classList.remove('d-none');
      }
      else {
        event.currentTarget.querySelector('button.see-more .text-voir-tout').classList.remove('d-none');
        event.currentTarget.querySelector('button.see-more .text-voir-moins').classList.add('d-none');
      }
    }

    else {
      this.$offres.forEach((offre) => {
        offre.classList.toggle('item-open');
        offre.classList.toggle('item-close');

        offre.querySelector('button.see-more').classList.toggle('up');
        offre.querySelector('button.see-more').classList.toggle('down');

        if ($(offre.querySelector('button.see-more')).hasClass('up')) {
          offre.querySelector('button.see-more .text-voir-moins').classList.remove('d-none');
          offre.querySelector('button.see-more .text-voir-tout').classList.add('d-none');
        }
        else {
          offre.querySelector('button.see-more .text-voir-moins').classList.add('d-none');
          offre.querySelector('button.see-more .text-voir-tout').classList.remove('d-none');
        }
      });
    }
  }

}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".items-module-detail-offre")).forEach((detailOffre) => {
    new OabDetailOffre(detailOffre);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabDetailOffre = OabDetailOffre;

export default OabDetailOffre;
