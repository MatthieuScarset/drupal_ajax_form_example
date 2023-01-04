<script lang="ts">

import {defineComponent} from "vue";

export default defineComponent({

  props: {
    name: String
  }
});

</script>

<template>
  <h1>Coucou je suis un custom element <span v-if="name">{{ name }}</span> </h1>
</template>
