//File for creating app
import Vue from "vue";
import App from "./App.vue";
import router from "./router";
// import bootstrap first, for CSS bootstrap
import 'bootstrap/dist/css/bootstrap.css';
// Importing the bootstrapvue library.
// Component library based entirely on the Bootstrap frontend CSS framework
import BootstrapVue from 'bootstrap-vue';


Vue.config.productionTip = false;
//Added to use bootstrap-vue library
Vue.use(BootstrapVue)

new Vue({
  router,
  render: (h) => h(App),
}).$mount("#app");
