class StickyContent {
  private elems = [];
  private readonly header: HTMLElement;
  private readonly pageMenu: HTMLElement;

  constructor() {
    this.elems = Array.from(document.querySelectorAll('.sticky-top')).filter((elem) => {
      return !elem.closest('header') && !elem.querySelector('.ob1-menu-page');
    });

    this.header = document.querySelector('header');
    if (document.querySelector('.ob1-menu-page')) {
     this.pageMenu = document.querySelector('.ob1-menu-page').parentElement;
    }

    new ResizeObserver(() => {
      this.setTop();
    }).observe(this.header);

    const body = document.querySelector('body');

    if (body.classList.contains('user-logged-in')) {
      new MutationObserver((mutations) => {
          this.setTop();
      }).observe(body, {attributes: true, attributeFilter: ['style']});
    }

    this.setTop();
  }

  private setTop() {
    let top = this.header.offsetHeight + this.getBodyPaddingTop();

    if (this.pageMenu) {
      this.pageMenu.style.top = `${top}px`;
      top += this.pageMenu.offsetHeight;
    }

    this.elems.forEach((elem) => {
      elem.style.top = `${top}px`;
    })
  }

  private getBodyPaddingTop(): number {
    return parseInt(((document.querySelector('body') as HTMLElement).style.paddingTop).replace("px", ''));
  }
}

new StickyContent();

