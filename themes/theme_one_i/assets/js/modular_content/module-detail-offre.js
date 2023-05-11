class ModuleDetailOffre {

  constructor(elem) {
    this.$root = elem;
    this.$offres = this.$root.querySelectorAll('.detail-offre-item');
    this.$root.querySelectorAll('button.see-more').forEach((btn) => {
      btn.addEventListener('click', this._toggleItems);
    });
  }

  _toggleItems = (event) => {

    if (window.matchMedia("(max-width: 767px)").matches) {
      const is_initially_open = event.currentTarget.closest('.detail-offre-item').classList.contains('item-open');

      this.$offres.forEach((offre) => {
        offre.classList.remove('item-open');
        offre.classList.add('item-close');

        if (offre.querySelector('button.see-more')) {
          offre.querySelector('button.see-more').classList.remove('up');
          offre.querySelector('button.see-more').classList.add('down');

          offre.querySelector('button.see-more .text-voir-detail').classList.remove('d-none');
          offre.querySelector('button.see-more .text-masquer-detail').classList.add('d-none');
        }
      });

      if (!is_initially_open) {
        event.currentTarget.closest('.detail-offre-item').classList.toggle('item-close');
        event.currentTarget.closest('.detail-offre-item').classList.toggle('item-open');
        event.currentTarget.classList.toggle('up');
        event.currentTarget.classList.toggle('down');
      } else {

        let header = document.querySelector('header');
        let pageMenu = document.querySelector('.ob1-menu-page').parentElement;
        let headerHeight = header.offsetHeight + pageMenu.offsetHeight;
        let parentTop = event.currentTarget.closest('.detail-offre-item').getBoundingClientRect().top;

        if(parentTop < headerHeight) {
          window.scrollBy(document.body.clientWidth, -headerHeight+parentTop);
        }
      }

      if (event.currentTarget.classList.contains('up')) {
       event.currentTarget.querySelector('button.see-more .text-voir-detail').classList.add('d-none');
       event.currentTarget.querySelector('button.see-more .text-masquer-detail').classList.remove('d-none');
      }
      else {
        event.currentTarget.querySelector('button.see-more .text-voir-detail').classList.remove('d-none');
        event.currentTarget.querySelector('button.see-more .text-masquer-detail').classList.add('d-none');
      }
    }

    else {
      this.$offres.forEach((offre) => {
        offre.classList.toggle('item-open');
        offre.classList.toggle('item-close');

        if (offre.querySelector('button.see-more')) {
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
        }
      });
    }
  }

}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".items-module-detail-offre")).forEach((detailOffre) => {
    new ModuleDetailOffre(detailOffre);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabDetailOffre = ModuleDetailOffre;

export default ModuleDetailOffre;
