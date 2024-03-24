//Introduced in 2015, classes are just new syntax for the existing prototype inheritance

//Rather than constructor functions, use the following (more similar to c++):

//- Use Pascal notation (FirstWordIsCapital) for constructor function names
class Name
{
    constructor(fName, sName) {
        this.firstName = fName
        this.surname = sName
    }
    //Class method declaration(method = member function).
    sayMyName() {
        return this.firstName + " " + this.surname
    }
    //The following syntax (using "function" keyword) isn't allowed in classes (which are post ES6)
    /*
    sayMyNameV2: function() {
        return this.firstName + " " + this.surname
    }
    */
}

const classP1 = new person("Bruce", "Wayne") //Call Name constructor
console.log(classP1.sayMyName())