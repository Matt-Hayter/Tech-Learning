//Javascript can be run in browser (eg. google chrome), or in Node.js!
//Syntax based on C

//Naming conventions in JavaScript: 
//- Use Camal case (useCamalCase) for variables and function names
//- Use Pascal case (UsePascalCase) for constructor function names and class names

//------Primitive data types------:
let name = "yoyoy" //Define string var
const name1 = 3 //Define const double var (all numbers are doubles in js)

//------Compound data types------:
const arr1 = [1, 2, 3, "here"] //Define const array (containing multiple variable types)
const personObj = { //Object, similar to dictionaries in other languages (key:value)
    name: "Matt",
    age: 22,
    //pre-ES6 definition of object method (function attached to object, aka member function)
    //This form can't be used in classes
    sayName: function() {
        console.log("My name is", this.name, "v1") //Use "this" to refer to current 
    },
    //post-ES6 definition of method (more concise)
    sayNameAlt() {
        console.log("My name is", this.name, "v2")
    }
}
console.log(arr1)
personObj.sayName() //Access method
personObj.sayNameAlt()

//------Global variable------
//Declaring variable without var or let makes it global
{
    phoneObj = { //No let or const used
        colour: "black",
        version: "10"
    }
}
console.log(phoneObj.colour) //Accessing phone_obj

//------Pre ES6 var keyword------:
//Allows variable access outside of scope (just generally avoid use)
{
    var sum = 1 + 2
}
console.log(sum)