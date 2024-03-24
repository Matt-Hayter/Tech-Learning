//Vue.js section

const app = Vue.createApp({ //Have access to Vue object due to CDN
    //Could have this here: template: "<h1>Hello World</h1>",
    data() { //Data for app component. Function that returns an object
        return {
            firstName: 'John',
            lastName: 'Doe',
            email: 'john@gmail.com',
            gender: 'male', //Different CSS configs for different genders
            picture: 'https://randomuser.me/api/portraits/men/10.jpg' //Using the randomuser API
        }
    },
    methods: { //For functions
        
        async getUser() {
            const res = await fetch('https://randomuser.me/api')
            const {results} = await res.json() //Destructure results after extracting from json
            console.log(results) //See contents of results
            //Updating member data with random fetch results. Items of results seen after printing in browser console
            this.firstName = results[0].name.first,
            this.lastName = results[0].name.last,
            this.email = results[0].email,
            this.gender = results[0].gender,
            this.picture = results[0].picture.large
        }
        /* //Alternative for just one user
        getUser() {
            //Updating member data
            this.firstName = "Sam",
            this.lastName = "Smith",
            this.email = "sam@email.com",
            this.gender = "female",
            this.picture = 'https://randomuser.me/api/portraits/women/10.jpg'
        }
        */
    }
})
//Now mount this app to div created in html
app.mount("#app")