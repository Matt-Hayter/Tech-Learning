//Fetch API (aplication programming interface) is built into javascript and is promise-based - this is an improvement of XMLHttpRequest
//Fetch always succeeds (unless there's some sort of network error) -> requires a .ok check

fetch('https://reqres.in/api/users'), { //Imaginary url
    method: "POST", //Specify that we're posting to server with api
    headers: { //Need to tell fetch that we are passing JSON
        "Content-Type": "application/json"
    },
    body: JSON.stringify({ //Need to convert to JSON string as this is the format on the server
        name: "User 1" //What's being posted.
    })
}.then(res => {
    if(res.ok) {  //Check response from api is ok
        console.log("Success")
    } else {
        console.log("Failure")
    }
    res.json() //Returns data from json format as another promise
}).then(data => console.log(data))