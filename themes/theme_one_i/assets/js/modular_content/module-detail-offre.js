class ModuleDetailOffre {

  constructor(elem) {
    this.$root = elem;
    this.$offres = this.$root.querySelectorAll('.detail-offre-item');


    this.$offresClose = this.$root.querySelectorAll('.detail-offre-item.item-close');
    if (this.$offresClose.length > 1) {
      updateOffresHeight(this.$offresClose);
    }

    this.$root.querySelectorAll('button.see-more').forEach((btn) => {
      btn.addEventListener('click', this._toggleItems);
    });

    this.$offres.forEach((offre) => {
      new ResizeObserver(function(elem) {
        let offre_height = elem[0].contentRect.height;
        let seeMoreBtn = offre.querySelector('button.see-more');

        console.log(offre.classList, offre.classList.contains('item-close'))

        if (offre.classList.contains('item-close')) {
          if (window.matchMedia("(max-width: 767px)").matches
            || window.matchMedia("(min-width: 767px)").matches && offre_height > offre.offsetHeight) {
            seeMoreBtn.classList.remove('btn-hidden');
          } else {
            seeMoreBtn.classList.add('btn-hidden');
          }
        } else {
          if (window.matchMedia("(min-width: 767px)").matches && offre_height < 608) {
            seeMoreBtn.classList.add('btn-hidden');
          }
        }
      }).observe(offre.querySelector('.detail-offre-content'));
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

// modifie la taille de la carte offre pour la version mobile
function updateOffresHeight(elems) {
  let oneHaveCta = false;
  let oneHavePrice = false;
  let haveGlobalCta = false;
  let maxCtaNb = 0;

  let offreGlobalCta = document.querySelector('#detail-offre .product-cta-button.btn-primary');

  if (offreGlobalCta != null) {
    haveGlobalCta = true;
  }

  // boucle pour savoir les éléments présents dans l'ensemble des offres
  elems.forEach(function(elem) {
    let offreCta = elem.querySelectorAll('.call-to-action .field--item')
    let offrePrice = elem.querySelectorAll('.offre-price');

    let haveSeeMore = false;

    if (elem.querySelector('.see-more') === null) {
       elem.classList.add('see-full');
    }

    if (!haveGlobalCta) {
      if (oneHaveCta === false && offreCta.length > 0) {
        oneHaveCta = true;

        if (offreCta.length > maxCtaNb) {
          maxCtaNb = offreCta.length;
        }
      }
    }
    if (oneHavePrice === false && offrePrice.length > 0) {
      oneHavePrice = true
    }

    //pour la version mobile, on applique les modification de height pour chaque élément
    if (window.matchMedia('(max-width: 736px)').matches) {
      if (haveGlobalCta) {
        if (offrePrice.length > 0 ) {
          if (offreCta.length > 0) {
            elem.classList.add('oneCtaAndPrice');
          } else {
            elem.classList.add('onlyPrice');
          }
        } else if (offreCta.length > 0) {
          elem.classList.add('onlyOneCta');
        } else {
          elem.classList.add('onlyText');
        }
      } else {
        if (offrePrice.length > 0 && offreCta.length === 0) {
          elem.classList.add('onlyPrice');
        } else if (offrePrice.length === 0 && offreCta.length > 0 ) {
          if (offreCta.length === 1) {
            elem.classList.add('onlyOneCta');
          } else {
            elem.classList.add('onlyCtas');
          }
        } else if (offrePrice.length > 0 && offreCta.length > 0) {
          if (offreCta.length === 1) {
            elem.classList.add('oneCtaAndPrice');
          } else {
            elem.classList.add('allElem');
          }
        } else {
          elem.classList.add('onlyText');
        }
      }
    }

  });
}

document.addEventListener("DOMContentLoaded", () => {
  Array.from(document.querySelectorAll(".items-module-detail-offre")).forEach((detailOffre) => {
    new ModuleDetailOffre(detailOffre);
  });
});

// rattachement au contexte window pour pouvoir l'utiliser en dehors du JS
window.OabDetailOffre = ModuleDetailOffre;

export default ModuleDetailOffre;
