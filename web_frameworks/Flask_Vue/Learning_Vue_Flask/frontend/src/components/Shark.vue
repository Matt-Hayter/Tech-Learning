<template>
    <div>
        <!--All vue data accessed with {{}}-->
        <button type="button" class = "btn btn-primary">{{ msg }}</button>
    </div>
</template>


<script>
import axios from 'axios';
//Exporting default component, a "Shark" vue component
export default {
    name:'Shark',
    //Format for the data of a Vue component object
    data() {
        return {
            msg : ""
        };
    },
    //Format for the functions of Vue component object
    methods : {
        getReponse(){ //Function for getting response from backend. Could use async function with await, in a try catch
            const path = 'http://localhost:5000/shark'; //Path to flask
            axios.get(path) //Returns promise
            .then ((res) => { 
                console.log(res.data)
                this.msg = res.data;
            }) 
            .catch ((err) => {
                console.error(err);
            });
        },
    }, //end of methods
    created(){ //Lifecycle hook -> can't use an arrow function
        this.getReponse();
    }
}
</script>