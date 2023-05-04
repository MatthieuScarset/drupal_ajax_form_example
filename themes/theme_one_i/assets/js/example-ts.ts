
class ExampleTs {
  constructor() {
    // alert("coucou - je suis écrit en TS :) " + this.sum(4,5));
  }

  private sum(a: number, b: number): number {
    return a+b;
  }

}

const e = new ExampleTs();

export default ExampleTs;
