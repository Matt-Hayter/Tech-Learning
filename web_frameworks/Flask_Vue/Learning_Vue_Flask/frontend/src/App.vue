<!--Route component for Vue framework,from which all other cpmponents are rendered-->
<template>
  <!--Classic div id=app, where other JS is inserted-->
  <div id="app">
    <!--Functional component that renders the matched component to it's given path-->
    <router-view />
  </div>
</template>

<style>
#app {
  margin-top : 60px;
}
</style>
