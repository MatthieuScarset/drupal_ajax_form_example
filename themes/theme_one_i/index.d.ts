declare module '*.vue' { // NOTE: ts-loader
  import { defineComponent } from 'vue';

  const component: ReturnType<typeof defineComponent>;
  export default component;
}
declare module 'vue/dist/vue.esm-browser';
