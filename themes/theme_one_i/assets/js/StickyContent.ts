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

    if (this.isConnected()) {
      new MutationObserver((mutations) => {
          mutations.forEach((mutationRecord) => {
            if (mutationRecord.oldValue !== (mutationRecord.target as HTMLElement).style.cssText) {
              this.setTop();
            }
          });
      }).observe(document.querySelector('body'), {attributeOldValue: true, attributeFilter: ['style']});
    }

    new MutationObserver((mutations) => {
      mutations.forEach((mutationRecord) => {
        if (mutationRecord.oldValue === (mutationRecord.target as HTMLElement).classList.value) {
          this.setTop();
        }
      });
    }).observe(this.header, {attributeOldValue: true, attributeFilter:['class']});

    this.setTop();
  }

  private setTop() {
    let top = this.getBodyPaddingTop();

    if (!this.header.classList.contains('not-visible')) {
      top += this.header.offsetHeight;
    }

    if (!this.isConnected()) {
      top--;    //Bug sur le header qui est en "top -1px"
    }

    if (this.pageMenu) {
      this.pageMenu.style.top = `${top}px`;
      top += this.pageMenu.offsetHeight;
    }

    this.elems.forEach((elem) => {
      elem.style.top = `${top}px`;
    })
  }

  private getBodyPaddingTop(): number {
    if ((document.querySelector('body') as HTMLElement).style.paddingTop.length) {
      return parseInt(((document.querySelector('body') as HTMLElement).style.paddingTop).replace("px", ''));
    }
    return 0;
  }

  private isConnected(): boolean {
    return document.querySelector('body').classList.contains('user-logged-in');
  }
}

new StickyContent();

