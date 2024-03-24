import Vue from "vue";
import VueRouter from "vue-router";
//Import each component to be accessed via routes
import Shark from '../components/Shark.vue'
//default export in JS within games. This is the Vue object, containing data() and methods
import Games from '../components/Games.vue'


Vue.use(VueRouter);

//Creates the physical routes on web-page, for each page component
const routes = [
 {
   path : '/shark',
   name : 'Shark',
   component : Shark,
 },
 {
   path : '/games',
   name : 'Games',
   component : Games,
 }
];

const router = new VueRouter({
  mode: "history",
  base: process.env.BASE_URL,
  routes,
});

export default router;
