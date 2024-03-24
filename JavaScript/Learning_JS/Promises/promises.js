//The return result for an asynchronous block of code
//Allows other code to execute whilst asynchronous task (that requires waiting, such as API call) waits for a response)
//JS is a single threaded language (with 1 stack and heap) (external libs needed for multiple threads) -> only single threaded asynchrony allowed

//*NOTE: Standard functions that return promises are usually asynchronous (eg. fetch()), no action required. Using .then() just allows us to handle the response of the asynchrnous task*

//------Basics of promises------

let p = new Promise((resolve, reject) => { //This code is still executed synchronously
    let a = 1 + 2
    if(a === 3) { //After task/comparison is made, evaluate task success
        resolve("Success") //Resolve message (if task is successful)
    } else {
        reject("Failure") //Reject message
    }
})

//Code performed after task is completed. argument of resolve() fed as arg here. 
//If promise returns a promise, another .then() should be added
p.then((message) => {
    console.log("This is in the then: " + message)
}).catch((message) => { //Argument of reject fed here
    console.log("This is in the catch: " + message)
})

//------Asynchronous promise handling example------
const path = 'http://localhost:5000/games';
axios.post(path, payload) //Asychronous communicating between frontend and backend, returns a promise
    .then(() => {
        this.getGames();
    })

//Program may continue executing, until promise is fulfilled or fails, at which point .then or .catch is called

//------Mulitple promises-----

const record_video_1 = new Promise((resolve, reject) => { //This is still synchronous code here
    resolve("video 1 recorded")
})
const record_video_2 = new Promise((resolve, reject) => {
    resolve("video 2 recorded")
})
const record_video_3 = new Promise((resolve, reject) => {
    resolve("video 3 recorded")
})

Promise.all([ //Wait for all promises to be completed, then return all resolves
    record_video_1, //In this case promises are synchronous, so they'll just be completed one after the other
    record_video_2,
    record_video_3
]).then((messages) => { //Once all promises are fullfilled, calls .then (array of resolve()). Tends to be where data is recieved and processed after lengthy operation
    console.log(messages)
})

Promise.race([ //Calls .then() when the first promise is fullfilled (1 resolve()).
    record_video_1, //As promises are all synchronous here, that will just be the first promise
    record_video_2,
    record_video_3
]).then((message) => {
    console.log(message)
})

