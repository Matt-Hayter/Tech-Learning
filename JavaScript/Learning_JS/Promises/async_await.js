//Syntactic sugar for asynchronous promises

//Require() reads a JS file, executes it  and returns the export object (effectively includes libraries, alteratice to include keyword)
const axiosRequest = require("axios") //Axios is a promise based JS library fpr making HTTP requests from node or from browser
//Alternative: import axios from axios

//Old syntax:
//There will be some response time for this API call -> call is perfomed asynchronously, and execution of other tasks will continue until promise is returned.
axiosRequest.get("https://www.boredapi.cpm/api/activity")
    .then(response => {
        console.log(`You could ${response.data.activity}`)
    }).catch(error => {
        console.log(`Error! ${error}`)
    })

//Updated syntax (best to use this form):
const getActivity = async function() { //or const getActivity = async() => {}
    try { //Exception block used, as .catch() is no longer a module
        //await is used to pause execution of function until the promise resolves, before executing remaining function. Javascript engine can perform other tasks in the meantime
        let response = await axiosRequest.get("https://www.boredapi.cpm/api/activity") //Just a more elegent way of implementing .then()
        //Now the following code is effectively .then()
        console.log(`You could ${response.data.activity}`)
    } catch(error) { //JS creates an error object when it occurs, and passes it as an argument to catch!
        console.log(`Error! ${error}`)
    }
}

//------Another example (ignore application)------:
const getFruitQuantity = async(name) => { //This function is still performed synchronously, due to it's contents (no wait for external response)
    const fruit_quantities = {
        pineapple: 6,
        apple: 2,
        bananna: 9
    }
    return fruit_quantities[name] //With async func, return is automatically wrapped in a promise
}
getFruitQuantity("apple").then(quantity => console.log(quantity)) //Nicer not to use this syntax

//------Another example where return value of one promise is dependentt on another------:
const total_quantities_ordered = async() => {
    //In this case, want apple to be resolved before bananna
    const a = await getFruitQuantity("apple") //Call promise, then pause function execution whilst waiting for it to be resolved
    const b = await getFruitQuantity("bananna") //Now repreat for new promise

    return [a, b]
}

//------Having all promises run concurrently------:
const total_quantities = async() => {
    try {
        //In this case, want apple to be resolved before bananna
        const a = getFruitQuantity("apple") //Call promise 1, performed asynchronously
        const b = getFruitQuantity("bananna") //Call promise 2, performed asynchronously
        const quantities = await Promise.all([a, b]) //Pause function execution whilst waiting for resolution of all promises

        return quantities
    } catch(err) { //JS creates an error object when it occurs, and passes it as an argument to catch!
        console.log(err) 
    }
}
